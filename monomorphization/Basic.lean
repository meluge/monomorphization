import Lean
open Lean Elab Tactic Expr Std
open Meta hiding transform

structure Mono where
  id : MVarId
  levels : List Name
  assignment : Expr

structure MonoState where
  mono : HashMap Name (List Mono) := .emptyWithCapacity 8
  given : HashSet Expr := .emptyWithCapacity 8
  globalFVars : HashSet FVarId := .emptyWithCapacity 0

instance : ToString MonoState where
  toString s := s!"{s.mono.toList.map (fun x => x.1)}\n{s.given.toList}"

abbrev MonoM := StateT MonoState MetaM

partial def getBinders (e : Expr) : MetaM (List BinderInfo) := do
  match e with
  | forallE _ _ b i        => return i :: (← getBinders b)
  | mdata _ b | lam _ _ b _ | app _ b | letE _ _ _ b _ => getBinders b
  | _                      => return []

partial def preprocessMono (e : Expr) : MonoM Expr := do
  let (fn, args) := Expr.getAppFnArgs e
  let env ← getEnv
  if let some info := env.find? fn then
    let bs := (← getBinders info.type).toArray
    let instImplicit := (bs.zip args).filterMap fun ⟨binfo, a⟩ =>
      if binfo.isInstImplicit then some a else none
    if !instImplicit.isEmpty then
      let mut found := false
      let globalFVars := (← get).globalFVars
      let p := fun x => !globalFVars.contains x
      for arg in instImplicit do
        if arg.hasAnyFVar p then
          found := true
        else
          let type ← inferType arg
          modify (fun s => { s with given := s.given.insert type })
      if args.size == bs.size && !found then
        let set := (← get).mono.getD fn []
        for ⟨id, levels, value⟩ in set do
          let mvarlevels ← mkFreshLevelMVars levels.length
          let instantiated := value.instantiateLevelParams levels mvarlevels
          let ⟨metas, _, body⟩ ← lambdaMetaTelescope instantiated
          if ← isDefEqGuarded e body then
            return mkAppN (.mvar id) (← metas.mapM instantiateMVars)
        -- create new const!
        let mvarlevels ← mkFreshLevelMVars info.levelParams.length
        let typeInstantiated := info.type.instantiateLevelParams info.levelParams mvarlevels
        let ⟨metas, _, _⟩ ← forallMetaTelescope typeInstantiated
        let instImplicit' := (bs.zip metas).filterMap fun ⟨binfo, a⟩ =>
          if binfo.isInstImplicit then some a else none
        for ⟨arg, meta⟩ in instImplicit.zip instImplicit' do
          if !(← isDefEq arg meta) then
            panic! s!"Invalid application of {fn}"
        let value := mkAppN (mkConst fn mvarlevels) metas
        let abstractResult ← abstractMVars (← instantiateMVars value)
        let name := fn.num set.length

        let mvar := (← mkFreshExprMVar (← inferType abstractResult.expr) .syntheticOpaque name).mvarId!

        modify (fun s => { s with mono := s.mono.insert fn (
            ⟨mvar, abstractResult.paramNames.toList, abstractResult.expr⟩ :: set)
          })
        let _ ← isDefEq value e
        return mkAppN (.mvar mvar) (← abstractResult.mvars.mapM instantiateMVars)
  pure e

def exit : MonoM Unit := do
  (← get).mono.values.flatten.forM (fun mono =>
    do mono.id.assign mono.assignment
  )

def preprocess (e : Expr) : MonoM Expr := do
  preprocessMono (← whnf e)

partial def transform [Monad n] [MonadControlT MetaM n] (e : Expr) (f : Expr → n Expr) : n Expr := do
  match ← f e with
  | app fn arg =>
    pure (.app (← transform fn f) (← transform arg f))
  | lam name type body info =>
    withLocalDecl name info type fun fvar => do
      pure (.lam name (← transform type f)
        ((← transform (body.instantiate1 fvar) f).abstract #[fvar]) info)
  | forallE name type body info =>
    withLocalDecl name info type fun fvar => do
      pure (.forallE name (← transform type f)
        ((← transform (body.instantiate1 fvar) f).abstract #[fvar]) info)
  | letE name type value body nonDep =>
    withLetDecl name type value fun fvar => do
      pure (.letE name (← transform type f) (← transform value f)
        ((← transform (body.instantiate1 fvar) f).abstract #[fvar]) nonDep)
  | mdata m b => pure (.mdata m (← transform b f))
  | _ => pure e


-- def test (a b : Nat) := 0 + 1 + 2

-- #eval (do
--   let e := ((← getEnv).find? `test).get!.value!
--   let e' ← (transform e preprocessMono).run {}
--   dbg_trace (← ppExpr e)
--   dbg_trace (← ppExpr e'.1)
--   -- dbg_trace e'.2
-- )

partial def getInstanceTypes (e : Expr) : MetaM (HashSet Expr) := do
  match e with
  | app _ _ =>
      let (fn, args) := Expr.getAppFnArgs e
      if let some info := (← getEnv).find? fn then
        let bs ← getBinders info.type
        let insts ← (bs.toArray.zip args).filterMapM fun ⟨binfo, arg⟩ => do
          if !binfo.isInstImplicit || arg.hasLooseBVars then
            pure none
          else some <$> inferType arg
        args.foldlM (fun acc a => return acc ∪ (← getInstanceTypes a)) (HashSet.ofArray insts)
      else
        return ∅
  | mdata _ b | lam _ _ b _ | letE _ _ _ b _ => getInstanceTypes b
  | _ => return ∅

partial def unify (todo : List Expr) (given : List Expr) (cb : MetaM (Option Expr)) : MetaM (List Expr) := do
  match todo with
  | [] => match ← cb with
    | some e => return [e]
    | none => return []
  | type :: todo =>
    let type ← instantiateMVars type
    if type.hasMVar then
      let branches ← given.filterMapM fun inst => do
        withoutModifyingMCtx do
          if ← isDefEqGuarded type inst then
            pure (some (← unify todo given cb))
          else pure none
      if !branches.isEmpty then
        return branches.flatten
    unify todo given cb

def updateLambdaBinderInfos (e : Expr) (binderInfos? : List (Option BinderInfo)) : Expr :=
  match e, binderInfos? with
  | Expr.lam n d b bi, newBi? :: binderInfos? =>
    let b  := updateLambdaBinderInfos b binderInfos?
    let bi := newBi?.getD bi
    Expr.lam n d b bi
  | e, _ => e

def monomorphizeImpl (name : Name) : MonoM (List Expr) := do
  let constInfo ← getConstInfo name

  let levels ← constInfo.levelParams.mapM (fun _ => mkFreshLevelMVar)

  let typeInstantiated := constInfo.type.instantiateLevelParams constInfo.levelParams levels
  let (mvars, binders, body) ← forallMetaTelescopeReducing typeInstantiated

  let instImplicit := (mvars.zip binders).filterMap fun ⟨m, binfo⟩ =>
    if binfo.isInstImplicit then some m else none

  let instImplicitTypes ← instImplicit.mapM (fun mvar => do mvar.mvarId!.getType)
  let todo := (← getInstanceTypes body).insertMany instImplicitTypes.toList

  unify todo.toList (← get).given.toList do
    for mvar in instImplicit do
      let mty ← instantiateMVars (← mvar.mvarId!.getType)
      match ← trySynthInstance mty with
      | .some inst => do
        mvar.mvarId!.assign inst
      | .none => return none
      | .undef => pure ()

    let appliedExpr := mkAppN (Expr.const name levels) mvars
    let instantiated ← instantiateMVars appliedExpr
    let abstrResult ← abstractMVars instantiated
    let binfos := abstrResult.mvars.map (fun mvar =>
      (mvars.idxOf? mvar).map (fun idx => binders[idx]!)
    )
    pure (updateLambdaBinderInfos (abstrResult.expr) binfos.toList)

def monomorphizeTactic (goal : MVarId) (ids : Array Syntax) : MetaM MVarId := do
  let instTypes ← getInstanceTypes (← goal.getType)
  let consts ← ids.mapM resolveGlobalConstNoOverload
  let exprs : List (Name × Expr) ← (consts.toList.flatMapM (fun (const : Name) => do
    let test ← (monomorphizeImpl const).run' { given := instTypes}
    pure (test.mapIdx (fun idx expr =>
      let name := Name.mkSimple ((const.num idx).toStringWithSep "_" true)
      ⟨name, expr⟩
    ))
  ))
  exprs.foldlM (fun goal ⟨name, result⟩ => do
    pure (← goal.note name result).2) goal

def monomorphizeTactic1 (goal : MVarId) (ids : Array Syntax) : MetaM MVarId := do
  let instTypes ← goal.withContext <| getInstanceTypes (← goal.getType)
  let consts ← ids.mapM resolveGlobalConstNoOverload
  let exprs : List (Name × Expr) ← (consts.toList.flatMapM (fun (const : Name) => do
    let test ← (monomorphizeImpl const).run' { given := instTypes}
    pure (test.mapIdx (fun idx expr =>
      let name := Name.mkSimple ((const.num idx).toStringWithSep "_" true)
      ⟨name, expr⟩
    ))
  ))

  let mut currentGoal := goal
  let mut fvarMap : HashMap Name FVarId := {}

  for pair in consts.zip (Array.mk exprs) do
    let const := pair.1
    let monoName := pair.2.1
    let monoExpr := pair.2.2

    let (fvarId, newGoal) ← currentGoal.note monoName monoExpr
    currentGoal := newGoal
    fvarMap := fvarMap.insert const fvarId

  currentGoal.withContext do
    let preprocessMonoForGoal (e : Expr) : MonoM Expr := do
      let fn := e.getAppFn
      let args := e.getAppArgs
      match fn with
      | Expr.const name _ =>
        match fvarMap.get? name with
        | some fvarId =>
          let env ← getEnv
          if let some info := env.find? name then
            let bs := (← getBinders info.type).toArray
            let nonInstArgs := (bs.zip args).filterMap fun ⟨binfo, arg⟩ =>
              if binfo.isExplicit then some arg else none
            return mkAppN (Expr.fvar fvarId) nonInstArgs
          else
            preprocessMono e
        | none => preprocessMono e
      | _ => preprocessMono e

    let goalType ← currentGoal.getType
    let (newGoalType, _) ← (transform goalType preprocessMonoForGoal).run {}

    let newGoalType ← instantiateMVars newGoalType
    currentGoal.replaceTargetDefEq newGoalType

syntax (name := monomorphize) "monomorphize " "[" ident,* "]" : tactic
syntax (name := monomorphizeSingle) "monomorphize " ident : tactic

@[tactic monomorphize] def evalMonomorphize : Tactic
| `(tactic| monomorphize [$ids:ident,*]) =>
  liftMetaTactic1 fun goal =>
    goal.withContext do
      monomorphizeTactic1 goal ids.getElems
| _ => throwUnsupportedSyntax

@[tactic monomorphizeSingle] def evalMonomorphizeSingle : Tactic
| `(tactic| monomorphize $id:ident) =>
  liftMetaTactic1 fun goal =>
    goal.withContext do
      monomorphizeTactic1 goal #[id]
| _ => throwUnsupportedSyntax


example (a b : Nat) : a + b = b + a := by
  monomorphize [HAdd.hAdd]
  sorry
