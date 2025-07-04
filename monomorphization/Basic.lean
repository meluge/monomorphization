import Lean
open Lean Elab Tactic Expr Std
open Meta hiding transform

structure Abstracted where
  expr : Expr
  levels : List Name

instance : BEq Abstracted where
  beq := fun x y =>
    if x.levels.length != y.levels.length then false else
    let levels := y.levels.map Level.param
    y.expr == (instantiateLevelParams x.expr x.levels levels)

instance : Hashable Abstracted where
  hash := fun x => (instantiateLevelParams x.expr x.levels (x.levels.map (fun _ => Level.zero))).hash

structure Mono where
  id : MVarId
  levels : List Name
  assignment : Expr

structure MonoState where
  mono : HashMap Expr (List Mono) := .emptyWithCapacity 8
  given : HashSet Abstracted := .emptyWithCapacity 8
  globalFVars : HashSet FVarId := .emptyWithCapacity 0

instance : ToString MonoState where
  toString s := s!"{s.mono.toList.map (fun x => x.1)}\n{s.given.toList.map (fun x => x.expr)}"

abbrev MonoM := StateT MonoState MetaM

partial def getBinders (e : Expr) : MetaM (List BinderInfo) := do
  match e with
  | forallE _ _ b i        => return i :: (← getBinders b)
  | mdata _ b | lam _ _ b _ | app _ b | letE _ _ _ b _ => getBinders b
  | _                      => return []

def updateLambdaBinderInfos (e : Expr) (binderInfos? : List (Option BinderInfo)) : Expr :=
  match e, binderInfos? with
  | Expr.lam n d b bi, newBi? :: binderInfos? =>
    let b  := updateLambdaBinderInfos b binderInfos?
    let bi := newBi?.getD bi
    Expr.lam n d b bi
  | e, _ => e

def asHead : Expr → MetaM (Option (Expr × Expr × List Name))
| e@(fvar id) | e@(mvar id) => return some (e, ← id.getType, [])
| const name us => do
  let info := ((← getEnv).find? name).get!
  return some (.const name (us.map (fun _ => Level.zero)), info.type, info.levelParams)
| _ => return none

def toName : Expr → MetaM Name
| .fvar id => do pure (id.name.updatePrefix (← id.getUserName).getRoot)
| .mvar id => do pure (id.name.updatePrefix ((← getMCtx).getDecl id).userName)
| .const name _ => pure name
| e => panic! s!"toName applied to non-head symbol: {e}"

def onlyGlobalFVars (e : Expr) : MonoM Bool := do
  let globalFVars := (← get).globalFVars
  let p := fun x => !globalFVars.contains x
  return !e.hasAnyFVar p

partial def registerInstance (s : Expr) : MonoM Unit := do
  if ← onlyGlobalFVars s then
    let ⟨levels, _, type⟩ ← abstractMVars (← inferType s)
    modify (fun s => { s with given := s.given.insert ⟨type, levels.toList⟩ })

partial def skeleton (e : Expr) : MonoM (Option Expr) := do
  withApp e fun fn args => do
    if let some (_, type, levels) ← asHead fn then
      let (metas, binders, _) ← forallMetaTelescopeReducing
        (type.instantiateLevelParams levels (← mkFreshLevelMVars levels.length))
      if metas.size != args.size then return none -- eta check.
      for i in [0:binders.size] do
        if binders[i]!.isInstImplicit then
          if let some skeleton ← skeleton args[i]! then
            -- globalInstances if const check.
            let _ ← registerInstance skeleton
            let success ← isDefEq metas[i]! skeleton
            assert! success
          else return none
      return ← instantiateMVars (mkAppN fn metas)
    return none

partial def preprocessMono (e : Expr) : MonoM Expr := do
  withApp e fun fn _ => do
    if let some (fn, type, _) ← asHead fn then
      let hasInstImplicit ← forallTelescopeReducing type (fun xs _ =>
        do xs.anyM (fun x => do pure (← x.fvarId!.getBinderInfo).isInstImplicit))
      if hasInstImplicit then
        let set := (← get).mono.getD fn []
        for ⟨id, levels, value⟩ in set do
          let mvarlevels ← mkFreshLevelMVars levels.length
          let instantiated := value.instantiateLevelParams levels mvarlevels
          let ⟨metas, _, body⟩ ← lambdaMetaTelescope instantiated
          if ← isDefEqGuarded e body then
            return mkAppN (.mvar id) (← metas.mapM instantiateMVars)

        if let some skeleton ← skeleton e then
          if  ← onlyGlobalFVars skeleton then
            let skeleton ← instantiateMVars skeleton
            let ⟨paramNames, mvars, abstracted⟩ ← abstractMVars skeleton
            let name := Name.mkSimple (((← toName fn).num set.length).toStringWithSep "_" true)
            let mvar := (← mkFreshExprMVar (← inferType
              (abstracted.instantiateLevelParams paramNames.toList (← mkFreshLevelMVars paramNames.size))) .syntheticOpaque name).mvarId!
            modify (fun s => { s with mono := s.mono.insert fn (⟨mvar, paramNames.toList, abstracted⟩ :: set) })
            let success ← isDefEq skeleton e
            assert! success
            return ← instantiateMVars (mkAppN (.mvar mvar) mvars)
    return e

def exit : MonoM Unit := do
  (← get).mono.values.flatten.forM (fun mono =>
    do if !(← mono.id.isAssigned) then
        mono.id.assign mono.assignment
  )

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

partial def unify (todo : List Expr) (given : List Abstracted) (cb : MetaM (Option Expr)) : MetaM (List Expr) := do
  match todo with
  | [] => pure (← cb).toList
  | type :: todo =>
    let type ← instantiateMVars type
    if type.hasMVar then
      let branches ← given.filterMapM fun (inst : Abstracted) => do
        withoutModifyingMCtx do
          let (_, _, inst) ← lambdaMetaTelescope
            (inst.expr.instantiateLevelParams inst.levels (← mkFreshLevelMVars inst.levels.length))
          if ← isDefEqGuarded type inst then
            pure (some (← unify todo given cb))
          else pure none
      if !branches.isEmpty then
        return branches.flatten
    unify todo given cb

def monomorphizeImpl (name : Name) : MonoM (List Expr) := do
  let constInfo ← getConstInfo name

  let levels ← constInfo.levelParams.mapM (fun _ => mkFreshLevelMVar)

  let typeInstantiated := constInfo.type.instantiateLevelParams constInfo.levelParams levels
  let (mvars, binders, body) ← forallMetaTelescopeReducing typeInstantiated

  let instImplicit := (mvars.zip binders).filterMap fun ⟨m, binfo⟩ =>
    if binfo.isInstImplicit then some m else none

  let instImplicitTypes ← instImplicit.mapM (fun mvar => do mvar.mvarId!.getType)
  let todo := (← getInstanceTypes body).insertMany instImplicitTypes.toList -- what are the universe levels of todo?

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
    pure (updateLambdaBinderInfos abstrResult.expr binfos.toList)

def transformMVar [Monad n] [MonadLiftT MetaM n] [MonadMCtx n] (goal : MVarId) (transform : Expr → n Expr) : n (Expr × LocalContext) := do
  let decl := ((← getMCtx).findDecl? goal).get!
  let type ← transform decl.type

  let lctx := { decl.lctx with decls := ← decl.lctx.decls.mapM fun decl => do decl.mapM fun decl => do
    let decl := decl.setType (← transform decl.type)
    if let some value := decl.value? then
      pure (decl.setValue (← transform value))
    else pure decl
  }

  pure (type, lctx)

structure MonoConfig where
  canonicalize : Bool := true

declare_config_elab monoConfig MonoConfig

def monomorphizeTactic (goal : MVarId) (ids : Array Syntax) (config : MonoConfig) : MonoM MVarId := do
  let _ ← transformMVar goal (fun e => transform e preprocessMono) -- all instances are in the MonoM

  let consts ← ids.mapM resolveGlobalConstNoOverload
  -- we don't foldlM immediately because we need the index.
  let exprs : List (Name × Expr) ← consts.toList.flatMapM (fun const => do
    let results ← monomorphizeImpl const
    pure (results.mapIdx (fun idx expr =>
      let name := Name.mkSimple ((const.num idx).toStringWithSep "_" true)
      (name, expr)))
  )

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

    let (type, lctx) ← transformMVar goal (fun e => transform e preprocessMono)
    let _ ← exit
    let _ ← goal.modifyLCtx (fun _ => lctx)
    goal.replaceTargetDefEq type
  else pure goal

syntax (name := monomorphize) "monomorphize " Parser.Tactic.optConfig "[" ident,* "]" : tactic
syntax (name := monomorphizeSingle) "monomorphize " Parser.Tactic.optConfig ident : tactic

@[tactic monomorphize] def evalMonomorphize : Tactic
| `(tactic| monomorphize $config [$ids:ident,*]) => do
  let config ← monoConfig config
  liftMetaTactic1 fun goal =>
    goal.withContext do
      (monomorphizeTactic goal ids.getElems config).run' { globalFVars := HashSet.ofArray (← getLCtx).getFVarIds }
| _ => throwUnsupportedSyntax

@[tactic monomorphizeSingle] def evalMonomorphizeSingle : Tactic
| `(tactic| monomorphize $config $id:ident) => do
  let config ← monoConfig config
  liftMetaTactic1 fun goal =>
    goal.withContext do
      (monomorphizeTactic goal #[id] config).run' { globalFVars := HashSet.ofArray (← getLCtx).getFVarIds }
| _ => throwUnsupportedSyntax
