import Lean
open Lean Elab Tactic Expr Std
open Meta

namespace Monomorphize

/-Type of Instance with universe level abstracted-/
structure UnivAbstracted where
  expr : Expr
  levels : List Name

/-Boolean equality for UnivAbstracted-/
instance : BEq UnivAbstracted where
  beq := fun x y =>
    if x.levels.length != y.levels.length then false else
    let levels := y.levels.map Level.param
    y.expr == (instantiateLevelParams x.expr x.levels levels)

instance : Hashable UnivAbstracted where
  hash := fun x => (instantiateLevelParams x.expr x.levels (x.levels.map (fun _ => Level.zero))).hash

/-The metavariable of a function and monomorphized version we later substitute into it.-/
structure MonoExpr where
  id: MVarId
  levels: List Name
  /-Monomorphized version-/
  assignment: Expr

/-State monad for monomorphization-/
structure MonoState where
  /-Original expression to all created monomorphized versions-/
  mono: HashMap Expr (List MonoExpr) := .emptyWithCapacity 8
  /-Types of potential candidate instances-/
  candidateInsts: HashSet UnivAbstracted := .emptyWithCapacity 8
  /-Ids of global free variable, which are variables safe to use-/
  globalFVars: HashSet FVarId := .emptyWithCapacity 0
  /-Names of all constants we encounter.-/
  constNames: NameSet := .empty
  /-Indication that a new constant has been discovered in current process-/
  hasNewConst: Bool := true

instance : ToString MonoState where
  toString s := s!"{s.mono.toList.map fun x => x.1}\n{s.candidateInsts.toList.map fun x => x.expr}"

abbrev MonoM := StateT MonoState MetaM

def addConstant (name : Name) : MonoM Unit := do
  modify fun s => { s with
    constNames := s.constNames.insert name,
    hasNewConst:= s.hasNewConst || !s.constNames.contains name
  }

def addConstants (names : NameSet) : MonoM Unit := do
  modify fun s => { s with
    constNames := s.constNames.union names,
    hasNewConst := s.hasNewConst || !names.subset s.constNames
  }

def getConstants : MonoM NameSet := do
  return (← get).constNames


def consumeNewConstFlag : MonoM Bool := do
  let s ← get
  modify fun s => { s with hasNewConst := false }
  return s.hasNewConst

/-Recursively gets all the binder info from forall expressions inside e.-/
partial def getAllBinderInfos (e : Expr) : MetaM (List BinderInfo) := do
  match e with
  | forallE _ _ b i         => return i :: (← getAllBinderInfos b)
  | mdata _ b | lam _ _ b _ | app _ b | letE _ _ _ b _ => getAllBinderInfos b
  /-No other cases can potentially contain foralls.-/
  | _                       => return []

/-Takes a list of new BinderInfo Option and substitute them to a given lambda term.-/
def updateLambdaBinderInfos (e : Expr) (binderInfos? : List (Option BinderInfo)) : Expr :=
  match e, binderInfos? with
  | Expr.lam binderName binderType body binderInfo, newBi? :: binderInfos? =>
    /-recursively also update the body. -/
    let body  := updateLambdaBinderInfos body binderInfos?
    let binderInfo := newBi?.getD binderInfo
    Expr.lam binderName binderType body binderInfo
  | e, _ => e

/-Takes an expression and outputs the head symbol, type, and level parameters.-/
def getHeadInfo : Expr → MetaM (Option (Expr × Expr × List Name))
/-for variables, return the variable, its type, and an empty universe level param.-/
| e@(fvar id) | e@(mvar id) => return some (e, ← id.getType, [])
| const name us => do
  let info := ((← getEnv).find? name).get!
  /-Level set to zero for all constants to create the canonical version for comparison.-/
  /-We still store the actual level parameters for later.-/
  return some (.const name (us.map fun _ => Level.zero), info.type, info.levelParams)
| _ => return none

/-Outputs the name of a head symbol.-/
def toName : Expr → MetaM Name
| .fvar id => return id.name.updatePrefix (← id.getUserName).getRoot
| .mvar id => return id.name.updatePrefix ((← getMCtx).getDecl id).userName
| .const name _ => return name
| e => panic! s!"toName applied to non-head symbol: {e}"

/-Checks if e only has global free variables as opposed to local ones.-/
def onlyHasGlobalFVars (e : Expr) : MonoM Bool := do
  let globalFVars := (← get).globalFVars
  let p := fun x => !globalFVars.contains x
  return !e.hasAnyFVar p

/-Add a typeclass instance as a candidate.-/
partial def addAsCandidate (inst : Expr) : MonoM Unit := do
  if ← onlyHasGlobalFVars inst then
    let ⟨levels, _, type⟩ ← abstractMVars (← inferType inst)
    modify fun inst => { inst with candidateInsts := inst.candidateInsts.insert ⟨type, levels.toList⟩ }

/-Potentially unfold underlying definition in an instance using whnf-/
partial def unfoldInstDefn (e : Expr) : MetaM Expr := do
  let (name, args) := getAppFnArgs e
  let env ← getEnv
  if let some info := env.find? name then
    if !isGlobalInstance env name then
      if let some value := info.value? then
        return ← unfoldInstDefn (← whnfR (mkAppN value args))
  return e

/-Transform a metavariable's type and its context. -/
def transformMVar [Monad n] [MonadLiftT MetaM n] [MonadMCtx n] (goal : MVarId) (transform : Expr → n Expr) : n (Expr × LocalContext) := do
  let decl := ((← getMCtx).findDecl? goal).get!
  let type ← transform decl.type

  let lctx := { decl.lctx with decls := ← decl.lctx.decls.mapM fun decl => do decl.mapM fun decl => do
    let decl := decl.setType (← transform decl.type)
    if let some value := decl.value? then
      pure (decl.setValue (← transform value))
    else pure decl
  }

  return (type, lctx)

/-Fixes the type class inst and abstract everything else into metavariables-/
/-It is used as a key to the actual specialized definition.-/
partial def monoKeyTemplate (e : Expr) : MonoM (Option Expr) := do
  withApp e fun fn args => do
    if let some (_, type, levels) ← getHeadInfo fn then
    /-Assign new metavariable levels so outputs are independent of levels.-/
      let mvarlevels ← mkFreshLevelMVars levels.length
      let fn := fn.instantiateLevelParams levels mvarlevels
      let (metas, binders, _) ← forallMetaTelescopeReducing
        (type.instantiateLevelParams levels mvarlevels)
        /-Eta expansion check.-/
      if metas.size != args.size then return none
      for i in [0:binders.size] do
        if binders[i]!.isInstImplicit then
          if let some subTermTemplate ← monoKeyTemplate (← unfoldInstDefn args[i]!) then
            let _ ← addAsCandidate subTermTemplate
            /-Unify the metavariable with the corresponding template.-/
            let success ← isDefEq metas[i]! subTermTemplate
            assert! success
          else return none
      return ← instantiateMVars (mkAppN fn metas)
    return none

/-Turns type class arguments to metavariables that is either specialized or left alone.-/
partial def preprocessMono (e : Expr) : MonoM Expr := do
  let ctx ← getLCtx

  dbg_trace s!"preprocessMono called on: {e}, lctx size: {ctx.size}"

  withApp e fun fn _ => do
    if let some (fn, type, _) ← getHeadInfo fn then
      let hasInstImplicit ← forallTelescopeReducing type fun xs _ =>
        do xs.anyM fun x => return (← x.fvarId!.getBinderInfo).isInstImplicit
      if hasInstImplicit then
      /-Check if we can use a preexisting specialization in the mono state.-/
        let cachedSpec := (← get).mono.getD fn []
        for ⟨specmVar, specLevels, specBody⟩ in cachedSpec do
          let mvarlevels ← mkFreshLevelMVars specLevels.length
          let instantiated := specBody.instantiateLevelParams specLevels mvarlevels
          let ⟨metas, _, body⟩ ← lambdaMetaTelescope instantiated
          if ← isDefEqGuarded e body then
            return mkAppN (.mvar specmVar) (← metas.mapM instantiateMVars)

      /-Else, create new specialization.-/
        if let some monoKeyTemplate ← monoKeyTemplate e then
          if ← onlyHasGlobalFVars monoKeyTemplate then
            let monoKeyTemplate ← instantiateMVars monoKeyTemplate
            let ⟨paramNames, mvars, abstracted⟩ ← abstractMVars monoKeyTemplate
            /-Make new name for the specialized version.-/
            let specName := Name.mkSimple (((← toName fn).num cachedSpec.length).toStringWithSep "_" true)
            let specMvarId := (← mkFreshExprMVar (← inferType
              (abstracted.instantiateLevelParams paramNames.toList (← mkFreshLevelMVars paramNames.size))) .syntheticOpaque specName).mvarId!
              /-Add this to mono state.-/
            modify fun s => { s with
              mono := s.mono.insert fn (⟨specMvarId, paramNames.toList, abstracted⟩ :: cachedSpec)
            }
            let _ ← addConstants monoKeyTemplate.getUsedConstantsAsSet
            let success ← isDefEq monoKeyTemplate e
            assert! success
            return ← instantiateMVars (mkAppN (.mvar specMvarId) mvars)
    return e


/-Assign metavars to their monomorphized versions.-/
def finalizeMonos : MonoM Unit := do
  (← get).mono.values.flatten.forM fun mono =>
    do if !(← mono.id.isAssigned) then
        mono.id.assign mono.assignment

/-Gets all potential types of instance implicit argument.-/
partial def getInstanceTypes (e : Expr) : MetaM (HashSet Expr) := do
  match e with
  | app _ _ =>
      let (fn, args) := Expr.getAppFnArgs e
      if let some info := (← getEnv).find? fn then
        let bs ← getAllBinderInfos info.type
        let insts ← (bs.toArray.zip args).filterMapM fun ⟨binfo, arg⟩ => do
          if !binfo.isInstImplicit || arg.hasLooseBVars then
            return none
          else some <$> inferType arg
          /-recursively check all arguments too-/
        args.foldlM (fun acc a => return acc ∪ (← getInstanceTypes a)) (HashSet.ofArray insts)
      else
        return ∅
  | mdata _ b | lam _ _ b _ | letE _ _ _ b _ => getInstanceTypes b
  | _ => return ∅

partial def unifyWithCand (todo : List Expr) (candidates : List UnivAbstracted) (cb : MonoM (Option Expr)) : MonoM (List Expr) := do
  match todo with
  /-Base case means everything is solved, so call the callback.-/
  | [] => return (← cb).toList
  | type :: todo =>
    let type ← instantiateMVars type
    if type.hasMVar then
    /-Loop through the candidates and try to unify.-/
    /-We backtrack if it fails in a branch and try the next candidate.-/
      let branches ← candidates.filterMapM fun (inst : UnivAbstracted) => do
        withoutModifyingMCtx do
        /-Prepare for unification by getting rid of universe and opening lambda binders-/
          let (_, _, inst) ← lambdaMetaTelescope
            (inst.expr.instantiateLevelParams inst.levels (← mkFreshLevelMVars inst.levels.length))
          if ← isDefEqGuarded type inst then
            return some (← unifyWithCand todo candidates cb)
          else return none
      if !branches.isEmpty then
        return branches.flatten
    unifyWithCand todo candidates cb

def monomorphizeConst (name : Name) : MonoM (List Expr) := do
/-First, get the instance implicit arguments of the constant.-/
  let constInfo ← getConstInfo name

  let levels ← constInfo.levelParams.mapM fun _ => mkFreshLevelMVar

  let typeInstantiated := constInfo.type.instantiateLevelParams constInfo.levelParams levels

  /-Turn foralls to metavariables to solve.-/
  let (mvars, binders, body) ← forallMetaTelescopeReducing typeInstantiated

  let instImplicit := (mvars.zip binders).filterMap fun ⟨m, binfo⟩ =>
    if binfo.isInstImplicit then some m else none

  let instImplicitTypes ← instImplicit.mapM fun mvar => do mvar.mvarId!.getType
  let todo := (← getInstanceTypes body).insertMany instImplicitTypes.toList

  unifyWithCand todo.toList (← get).candidateInsts.toList do
    for mvar in instImplicit do
      let mty ← instantiateMVars (← mvar.mvarId!.getType)
      match ← trySynthInstance mty with
      | .some inst => do
        let success ← isDefEq mvar inst
        assert! success
      | .none => return none
      | .undef => pure ()

    let appliedExpr := mkAppN (Expr.const name levels) mvars
    let instantiated ← instantiateMVars appliedExpr
    let abstrResult ← abstractMVars instantiated
    let binfos := abstrResult.mvars.map fun mvar =>
      (mvars.idxOf? mvar).map fun idx => binders[idx]!

    let result := updateLambdaBinderInfos abstrResult.expr binfos.toList

    let set := (← get).mono.getD (Expr.const name (levels.map fun _ => Level.zero)) []
    for mono in set do
      let sameLevels := mono.assignment.instantiateLevelParams mono.levels (abstrResult.paramNames.toList.map Level.param)
      if sameLevels == result then
        return none

    let result := result.instantiateLevelParams abstrResult.paramNames.toList (abstrResult.paramNames.toList.map (fun _ => Level.zero))

    let _ ← addConstants result.getUsedConstantsAsSet

    return result


def monoPreTransform (e : Expr) : MonoM TransformStep := do
  let e' ← preprocessMono e
  if e' == e then
    return .continue
  else
    return .visit e'

structure MonoConfig where
  canonicalize : Bool := true

declare_config_elab monoConfig MonoConfig

def monomorphizeTactic (goal : MVarId) (ids : Array Syntax) (config : MonoConfig) : MonoM MVarId := do
  let _ ← transformMVar goal fun e => Meta.transform e (pre := monoPreTransform)

  if !config.canonicalize then
    modify fun s => { s with mono := .emptyWithCapacity 0 }

  let consts ← ids.mapM resolveGlobalConstNoOverload
  -- we don't foldlM immediately because we need the index.
  let exprs : List (Name × Expr) ← consts.toList.flatMapM fun const => do
    let results ← monomorphizeConst const
    return results.mapIdx fun idx expr =>
      let name := Name.mkSimple ((const.num idx).toStringWithSep "_" true)
      (name, expr)

  let goal ← exprs.foldlM (fun goal (name, result) => do
    pure (← MVarId.note goal name result).2
  ) goal

  if config.canonicalize then
    let goal ← (← get).mono.toList.foldlM (fun goal pair => do
      let (_, monos) := pair
      monos.foldlM (fun goal mono => do
        let name := ((← getMCtx).getDecl mono.id).userName
        let noteResult ← MVarId.note goal name mono.assignment
        mono.id.assign (.fvar noteResult.1)
        pure noteResult.2
      ) goal
    ) goal

    let (type, lctx) ← transformMVar goal fun e => Meta.transform e (pre := monoPreTransform)
    let _ ← finalizeMonos
    let _ ← goal.modifyLCtx fun _ => lctx
    goal.replaceTargetDefEq type
  else return goal

syntax (name := monomorphize) "monomorphize " Parser.Tactic.optConfig ("[" ident,* "]")? : tactic

@[tactic monomorphize] def evalMonomorphize : Tactic
| `(tactic| monomorphize $config [$ids:ident,*]) => do
  let config ← monoConfig config
  liftMetaTactic1 fun goal =>
    goal.withContext do
      (monomorphizeTactic goal ids.getElems config).run' { globalFVars := HashSet.ofArray (← getLCtx).getFVarIds }
| `(tactic| monomorphize $config) => do
  let config ← monoConfig config
  liftMetaTactic1 fun goal =>
    goal.withContext do
      (monomorphizeTactic goal #[] config).run' { globalFVars := HashSet.ofArray (← getLCtx).getFVarIds }
| _ => throwUnsupportedSyntax





example (m : Nat) : m + 2 = 2 + m := by
  monomorphize [HAdd.hAdd]
  sorry
