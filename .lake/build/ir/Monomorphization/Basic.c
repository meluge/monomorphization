// Lean compiler output
// Module: Monomorphization.Basic
// Imports: Init Lean Mathlib.Tactic.Ring Mathlib.Data.Real.Basic Mathlib.Data.ZMod.Basic Mathlib.Data.List.Basic
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
static lean_object* l_monomorphize___closed__9;
lean_object* l_Lean_Expr_const___override(lean_object*, lean_object*);
static lean_object* l_getInstanceTypes___closed__2;
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_getInstanceTypes___spec__4(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_monomorphizeCore___spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_getConstInfo___at_Lean_Meta_mkConstWithFreshMVarLevels___spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_mkAppN(lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__8;
static lean_object* l_monomorphize___closed__7;
static lean_object* l_List_foldlM___at_monomorphizeCore___spec__7___closed__2;
LEAN_EXPORT lean_object* l_monomorphizeCore(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_ConstantInfo_type(lean_object*);
LEAN_EXPORT lean_object* l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__6(lean_object*, lean_object*, size_t, size_t, lean_object*);
lean_object* l_Lean_ConstantInfo_levelParams(lean_object*);
LEAN_EXPORT lean_object* l_monomorphizeCore___lambda__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_Exception_isInterrupt(lean_object*);
static lean_object* l_monomorphize___closed__17;
LEAN_EXPORT lean_object* l_List_foldlM___at_monomorphizeCore___spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
size_t lean_uint64_to_usize(uint64_t);
lean_object* l_Lean_Name_toString(lean_object*, uint8_t, lean_object*);
lean_object* l_Lean_Elab_throwUnsupportedSyntax___at_LeanSearchClient_leanSearchTacticImpl___spec__1___rarg(lean_object*);
uint8_t l_Std_DHashMap_Internal_AssocList_contains___at_Lean_CollectFVars_visit___spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_evalMonomorphize(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_List_foldlM___at_monomorphizeCore___spec__7___closed__1;
lean_object* lean_array_push(lean_object*, lean_object*);
static lean_object* l_monomorphizeSingle___closed__4;
uint8_t lean_usize_dec_eq(size_t, size_t);
lean_object* l_Lean_Syntax_getArgs(lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__5;
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_unify___spec__2___rarg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__10;
lean_object* l_Lean_Elab_Tactic_getMainGoal(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Syntax_TSepArray_getElems___rarg(lean_object*);
lean_object* l_Lean_Environment_find_x3f(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_List_flatMapTR_go___at_unify___spec__3(lean_object*);
uint8_t l_Lean_Syntax_isOfKind(lean_object*, lean_object*);
lean_object* l_Nat_nextPowerOfTwo_go(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_getInstanceTypes(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_monomorphizeSingle___closed__1;
lean_object* l_Std_DHashMap_Internal_Raw_u2080_expand___at_Lean_CollectFVars_visit___spec__2(lean_object*);
LEAN_EXPORT lean_object* l_evalMonomorphizeSingle(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_Expr_hasMVar(lean_object*);
LEAN_EXPORT lean_object* l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_flatMapTR_go___at_unify___spec__3___rarg(lean_object*, lean_object*);
size_t lean_usize_of_nat(lean_object*);
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_monomorphizeCore___spec__2(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l_monomorphizeCore___lambda__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_getInstanceTypes___spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_st_ref_take(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_monomorphizeCore___lambda__2___boxed__const__1;
static lean_object* l_monomorphize___closed__14;
static lean_object* l_getInstanceTypes___closed__1;
lean_object* l_Array_zip___rarg(lean_object*, lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
LEAN_EXPORT lean_object* l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_getInstanceTypes___spec__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__15;
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* l_Lean_MVarId_getType(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l___private_Lean_Meta_Basic_0__Lean_Meta_forallMetaTelescopeReducingAux(lean_object*, uint8_t, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Array_idxOf_x3f___at___private_Lean_Meta_Constructions_BRecOn_0__Lean_buildBRecOnMinorPremise_go___spec__1(lean_object*, lean_object*);
lean_object* l_Lean_MVarId_withContext___at___private_Lean_Meta_SynthInstance_0__Lean_Meta_synthPendingImp___spec__2___rarg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_mapM_loop___at_Lean_Meta_tryUnificationHints_tryCandidate___spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_monomorphizeSingle;
LEAN_EXPORT lean_object* l_evalMonomorphize___lambda__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Elab_Tactic_withMainContext___rarg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_monomorphizeMultiple___spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
extern uint8_t l_Lean_instInhabitedBinderInfo;
LEAN_EXPORT lean_object* l_evalMonomorphizeSingle___lambda__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__11;
static lean_object* l_monomorphizeSingle___closed__2;
lean_object* lean_st_ref_get(lean_object*, lean_object*);
uint8_t l_List_isEmpty___rarg(lean_object*);
static lean_object* l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___closed__1;
LEAN_EXPORT lean_object* l_List_foldrIdx___at_getInstanceTypes___spec__1___boxed(lean_object*, lean_object*, lean_object*);
lean_object* lean_array_to_list(lean_object*);
LEAN_EXPORT lean_object* l_Array_filterMapM___at_monomorphizeCore___spec__1(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_abstractMVars(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_MVarId_note(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_Expr_hasLooseBVars(lean_object*);
lean_object* l_Lean_Meta_synthInstance(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_unify___rarg___lambda__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_monomorphizeCore___lambda__1(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
extern lean_object* l_Lean_instInhabitedExpr;
static lean_object* l_monomorphize___closed__20;
uint64_t l_Lean_Expr_hash(lean_object*);
uint8_t l_Lean_BinderInfo_isInstImplicit(uint8_t);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at_monomorphizeCore___spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldlM___at_monomorphizeCore___spec__7___lambda__1___boxed(lean_object*);
lean_object* l_Lean_extractMacroScopes(lean_object*);
lean_object* l_Lean_Name_str___override(lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__12;
lean_object* l_Lean_Syntax_getArg(lean_object*, lean_object*);
static lean_object* l_monomorphizeSingle___closed__3;
lean_object* l_Array_foldlMUnsafe_fold___at_Lean_Elab_Tactic_Omega_asLinearComboImpl___spec__2(lean_object*, size_t, size_t, lean_object*);
lean_object* l_Lean_Expr_instantiateLevelParams(lean_object*, lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__6;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at_getInstanceTypes___spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__13;
lean_object* l_Lean_MacroScopesView_review(lean_object*);
LEAN_EXPORT lean_object* l_Array_filterMapM___at_monomorphizeCore___spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_updateLambdaBinderInfos(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at_getInstanceTypes___spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_getBinders(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__1;
static lean_object* l_monomorphize___closed__4;
LEAN_EXPORT lean_object* l_monomorphizeMultiple___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_monomorphize;
uint8_t l_Lean_Name_hasMacroScopes(lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at_monomorphizeCore___spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__16;
lean_object* l_Lean_instantiateMVars___at___private_Lean_Meta_Basic_0__Lean_Meta_isClassApp_x3f___spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_MVarId_assign___at_Lean_Tactic_FunInd_abstractIndependentMVars___spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_unify___rarg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_isExprDefEqGuarded(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_resolveGlobalConstNoOverload___at___private_Lean_Meta_Tactic_Grind_PropagatorAttr_0__Lean_Meta_Grind_addBuiltin___spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_getBinders___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint64_t lean_uint64_xor(uint64_t, uint64_t);
static lean_object* l_getInstanceTypes___closed__3;
lean_object* l_Lean_Meta_resetCache___rarg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_unify___rarg___lambda__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* l_List_foldl___at_Array_appendList___spec__1___rarg(lean_object*, lean_object*);
lean_object* l_List_reverse___rarg(lean_object*);
static lean_object* l_unify___rarg___closed__1;
size_t lean_usize_sub(size_t, size_t);
lean_object* lean_array_mk(lean_object*);
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_unify___spec__2___rarg___lambda__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Array_foldrMUnsafe_fold___at_Lean_Elab_Tactic_BVDecide_Frontend_uninterpretedExplainer___spec__2(lean_object*, size_t, size_t, lean_object*);
size_t lean_usize_add(size_t, size_t);
static lean_object* l_monomorphize___closed__3;
LEAN_EXPORT lean_object* l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5(lean_object*, lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_unify(lean_object*);
static lean_object* l_monomorphize___closed__2;
lean_object* lean_array_uget(lean_object*, size_t);
size_t lean_array_size(lean_object*);
static lean_object* l_monomorphize___closed__21;
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_unify___spec__2(lean_object*);
LEAN_EXPORT lean_object* l_evalMonomorphizeSingle___lambda__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_getInstanceTypes___spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldlM___at_monomorphizeCore___spec__7(lean_object*, lean_object*, lean_object*, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_getAppFnArgs(lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldrIdx___at_getInstanceTypes___spec__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_withoutModifyingMCtx___at_unify___spec__1___rarg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
static lean_object* l_monomorphize___closed__19;
LEAN_EXPORT lean_object* l_monomorphizeMultiple(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_array_get(lean_object*, lean_object*, lean_object*);
lean_object* lean_infer_type(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_nat_add(lean_object*, lean_object*);
uint8_t l_Lean_Exception_isRuntime(lean_object*);
lean_object* l_Lean_Expr_lam___override(lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__3(size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_evalMonomorphize___lambda__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_monomorphize___closed__18;
lean_object* l_Lean_Expr_mvarId_x21(lean_object*);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
lean_object* l_Lean_Elab_Tactic_replaceMainGoal(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_beqBinderInfo____x40_Lean_Expr___hyg_413_(uint8_t, uint8_t);
LEAN_EXPORT uint8_t l_List_foldlM___at_monomorphizeCore___spec__7___lambda__1(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_withoutModifyingMCtx___at_unify___spec__1(lean_object*);
size_t lean_usize_land(size_t, size_t);
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_monomorphizeMultiple___spec__1(lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_getBinders(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
switch (lean_obj_tag(x_1)) {
case 5:
{
lean_object* x_7; 
x_7 = lean_ctor_get(x_1, 1);
x_1 = x_7;
goto _start;
}
case 6:
{
lean_object* x_9; 
x_9 = lean_ctor_get(x_1, 2);
x_1 = x_9;
goto _start;
}
case 7:
{
lean_object* x_11; uint8_t x_12; lean_object* x_13; uint8_t x_14; 
x_11 = lean_ctor_get(x_1, 2);
x_12 = lean_ctor_get_uint8(x_1, sizeof(void*)*3 + 8);
x_13 = l_getBinders(x_11, x_2, x_3, x_4, x_5, x_6);
x_14 = !lean_is_exclusive(x_13);
if (x_14 == 0)
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_15 = lean_ctor_get(x_13, 0);
x_16 = lean_box(x_12);
x_17 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_17, 0, x_16);
lean_ctor_set(x_17, 1, x_15);
lean_ctor_set(x_13, 0, x_17);
return x_13;
}
else
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; 
x_18 = lean_ctor_get(x_13, 0);
x_19 = lean_ctor_get(x_13, 1);
lean_inc(x_19);
lean_inc(x_18);
lean_dec(x_13);
x_20 = lean_box(x_12);
x_21 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_21, 0, x_20);
lean_ctor_set(x_21, 1, x_18);
x_22 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_22, 0, x_21);
lean_ctor_set(x_22, 1, x_19);
return x_22;
}
}
case 8:
{
lean_object* x_23; 
x_23 = lean_ctor_get(x_1, 3);
x_1 = x_23;
goto _start;
}
case 10:
{
lean_object* x_25; 
x_25 = lean_ctor_get(x_1, 1);
x_1 = x_25;
goto _start;
}
default: 
{
lean_object* x_27; lean_object* x_28; 
x_27 = lean_box(0);
x_28 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_28, 0, x_27);
lean_ctor_set(x_28, 1, x_6);
return x_28;
}
}
}
}
LEAN_EXPORT lean_object* l_getBinders___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; 
x_7 = l_getBinders(x_1, x_2, x_3, x_4, x_5, x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
return x_7;
}
}
LEAN_EXPORT lean_object* l_List_foldrIdx___at_getInstanceTypes___spec__1(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
if (lean_obj_tag(x_2) == 0)
{
lean_dec(x_3);
lean_inc(x_1);
return x_1;
}
else
{
uint8_t x_4; 
x_4 = !lean_is_exclusive(x_2);
if (x_4 == 0)
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; uint8_t x_10; uint8_t x_11; uint8_t x_12; 
x_5 = lean_ctor_get(x_2, 0);
x_6 = lean_ctor_get(x_2, 1);
x_7 = lean_unsigned_to_nat(1u);
x_8 = lean_nat_add(x_3, x_7);
x_9 = l_List_foldrIdx___at_getInstanceTypes___spec__1(x_1, x_6, x_8);
x_10 = 3;
x_11 = lean_unbox(x_5);
lean_dec(x_5);
x_12 = l_Lean_beqBinderInfo____x40_Lean_Expr___hyg_413_(x_11, x_10);
if (x_12 == 0)
{
lean_free_object(x_2);
lean_dec(x_3);
return x_9;
}
else
{
lean_ctor_set(x_2, 1, x_9);
lean_ctor_set(x_2, 0, x_3);
return x_2;
}
}
else
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; uint8_t x_18; uint8_t x_19; uint8_t x_20; 
x_13 = lean_ctor_get(x_2, 0);
x_14 = lean_ctor_get(x_2, 1);
lean_inc(x_14);
lean_inc(x_13);
lean_dec(x_2);
x_15 = lean_unsigned_to_nat(1u);
x_16 = lean_nat_add(x_3, x_15);
x_17 = l_List_foldrIdx___at_getInstanceTypes___spec__1(x_1, x_14, x_16);
x_18 = 3;
x_19 = lean_unbox(x_13);
lean_dec(x_13);
x_20 = l_Lean_beqBinderInfo____x40_Lean_Expr___hyg_413_(x_19, x_18);
if (x_20 == 0)
{
lean_dec(x_3);
return x_17;
}
else
{
lean_object* x_21; 
x_21 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_21, 0, x_3);
lean_ctor_set(x_21, 1, x_17);
return x_21;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_getInstanceTypes___spec__2(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8) {
_start:
{
if (lean_obj_tag(x_2) == 0)
{
lean_object* x_9; lean_object* x_10; 
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
x_9 = l_List_reverse___rarg(x_3);
x_10 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_10, 0, x_9);
lean_ctor_set(x_10, 1, x_8);
return x_10;
}
else
{
uint8_t x_11; 
x_11 = !lean_is_exclusive(x_2);
if (x_11 == 0)
{
lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; uint8_t x_16; 
x_12 = lean_ctor_get(x_2, 0);
x_13 = lean_ctor_get(x_2, 1);
x_14 = l_Lean_instInhabitedExpr;
x_15 = lean_array_get(x_14, x_1, x_12);
lean_dec(x_12);
x_16 = l_Lean_Expr_hasLooseBVars(x_15);
if (x_16 == 0)
{
lean_object* x_17; 
lean_inc(x_7);
lean_inc(x_6);
lean_inc(x_5);
lean_inc(x_4);
x_17 = lean_infer_type(x_15, x_4, x_5, x_6, x_7, x_8);
if (lean_obj_tag(x_17) == 0)
{
lean_object* x_18; lean_object* x_19; 
x_18 = lean_ctor_get(x_17, 0);
lean_inc(x_18);
x_19 = lean_ctor_get(x_17, 1);
lean_inc(x_19);
lean_dec(x_17);
lean_ctor_set(x_2, 1, x_3);
lean_ctor_set(x_2, 0, x_18);
{
lean_object* _tmp_1 = x_13;
lean_object* _tmp_2 = x_2;
lean_object* _tmp_7 = x_19;
x_2 = _tmp_1;
x_3 = _tmp_2;
x_8 = _tmp_7;
}
goto _start;
}
else
{
uint8_t x_21; 
lean_free_object(x_2);
lean_dec(x_13);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
x_21 = !lean_is_exclusive(x_17);
if (x_21 == 0)
{
return x_17;
}
else
{
lean_object* x_22; lean_object* x_23; lean_object* x_24; 
x_22 = lean_ctor_get(x_17, 0);
x_23 = lean_ctor_get(x_17, 1);
lean_inc(x_23);
lean_inc(x_22);
lean_dec(x_17);
x_24 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_24, 0, x_22);
lean_ctor_set(x_24, 1, x_23);
return x_24;
}
}
}
else
{
lean_dec(x_15);
lean_free_object(x_2);
x_2 = x_13;
goto _start;
}
}
else
{
lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; uint8_t x_30; 
x_26 = lean_ctor_get(x_2, 0);
x_27 = lean_ctor_get(x_2, 1);
lean_inc(x_27);
lean_inc(x_26);
lean_dec(x_2);
x_28 = l_Lean_instInhabitedExpr;
x_29 = lean_array_get(x_28, x_1, x_26);
lean_dec(x_26);
x_30 = l_Lean_Expr_hasLooseBVars(x_29);
if (x_30 == 0)
{
lean_object* x_31; 
lean_inc(x_7);
lean_inc(x_6);
lean_inc(x_5);
lean_inc(x_4);
x_31 = lean_infer_type(x_29, x_4, x_5, x_6, x_7, x_8);
if (lean_obj_tag(x_31) == 0)
{
lean_object* x_32; lean_object* x_33; lean_object* x_34; 
x_32 = lean_ctor_get(x_31, 0);
lean_inc(x_32);
x_33 = lean_ctor_get(x_31, 1);
lean_inc(x_33);
lean_dec(x_31);
x_34 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_34, 0, x_32);
lean_ctor_set(x_34, 1, x_3);
x_2 = x_27;
x_3 = x_34;
x_8 = x_33;
goto _start;
}
else
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; 
lean_dec(x_27);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
x_36 = lean_ctor_get(x_31, 0);
lean_inc(x_36);
x_37 = lean_ctor_get(x_31, 1);
lean_inc(x_37);
if (lean_is_exclusive(x_31)) {
 lean_ctor_release(x_31, 0);
 lean_ctor_release(x_31, 1);
 x_38 = x_31;
} else {
 lean_dec_ref(x_31);
 x_38 = lean_box(0);
}
if (lean_is_scalar(x_38)) {
 x_39 = lean_alloc_ctor(1, 2, 0);
} else {
 x_39 = x_38;
}
lean_ctor_set(x_39, 0, x_36);
lean_ctor_set(x_39, 1, x_37);
return x_39;
}
}
else
{
lean_dec(x_29);
x_2 = x_27;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at_getInstanceTypes___spec__3(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
if (lean_obj_tag(x_5) == 0)
{
return x_6;
}
else
{
uint8_t x_8; 
x_8 = !lean_is_exclusive(x_6);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; uint64_t x_14; uint64_t x_15; uint64_t x_16; uint64_t x_17; uint64_t x_18; uint64_t x_19; uint64_t x_20; size_t x_21; size_t x_22; size_t x_23; size_t x_24; size_t x_25; lean_object* x_26; uint8_t x_27; 
x_9 = lean_ctor_get(x_5, 0);
x_10 = lean_ctor_get(x_5, 1);
x_11 = lean_ctor_get(x_6, 0);
x_12 = lean_ctor_get(x_6, 1);
x_13 = lean_array_get_size(x_12);
x_14 = l_Lean_Expr_hash(x_9);
x_15 = 32;
x_16 = lean_uint64_shift_right(x_14, x_15);
x_17 = lean_uint64_xor(x_14, x_16);
x_18 = 16;
x_19 = lean_uint64_shift_right(x_17, x_18);
x_20 = lean_uint64_xor(x_17, x_19);
x_21 = lean_uint64_to_usize(x_20);
x_22 = lean_usize_of_nat(x_13);
lean_dec(x_13);
x_23 = 1;
x_24 = lean_usize_sub(x_22, x_23);
x_25 = lean_usize_land(x_21, x_24);
x_26 = lean_array_uget(x_12, x_25);
x_27 = l_Std_DHashMap_Internal_AssocList_contains___at_Lean_CollectFVars_visit___spec__1(x_9, x_26);
if (x_27 == 0)
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; uint8_t x_38; 
x_28 = lean_unsigned_to_nat(1u);
x_29 = lean_nat_add(x_11, x_28);
lean_dec(x_11);
x_30 = lean_box(0);
lean_inc(x_9);
x_31 = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(x_31, 0, x_9);
lean_ctor_set(x_31, 1, x_30);
lean_ctor_set(x_31, 2, x_26);
x_32 = lean_array_uset(x_12, x_25, x_31);
x_33 = lean_unsigned_to_nat(4u);
x_34 = lean_nat_mul(x_29, x_33);
x_35 = lean_unsigned_to_nat(3u);
x_36 = lean_nat_div(x_34, x_35);
lean_dec(x_34);
x_37 = lean_array_get_size(x_32);
x_38 = lean_nat_dec_le(x_36, x_37);
lean_dec(x_37);
lean_dec(x_36);
if (x_38 == 0)
{
lean_object* x_39; 
x_39 = l_Std_DHashMap_Internal_Raw_u2080_expand___at_Lean_CollectFVars_visit___spec__2(x_32);
lean_ctor_set(x_6, 1, x_39);
lean_ctor_set(x_6, 0, x_29);
x_5 = x_10;
x_7 = lean_box(0);
goto _start;
}
else
{
lean_ctor_set(x_6, 1, x_32);
lean_ctor_set(x_6, 0, x_29);
x_5 = x_10;
x_7 = lean_box(0);
goto _start;
}
}
else
{
lean_dec(x_26);
x_5 = x_10;
x_7 = lean_box(0);
goto _start;
}
}
else
{
lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; uint64_t x_48; uint64_t x_49; uint64_t x_50; uint64_t x_51; uint64_t x_52; uint64_t x_53; uint64_t x_54; size_t x_55; size_t x_56; size_t x_57; size_t x_58; size_t x_59; lean_object* x_60; uint8_t x_61; 
x_43 = lean_ctor_get(x_5, 0);
x_44 = lean_ctor_get(x_5, 1);
x_45 = lean_ctor_get(x_6, 0);
x_46 = lean_ctor_get(x_6, 1);
lean_inc(x_46);
lean_inc(x_45);
lean_dec(x_6);
x_47 = lean_array_get_size(x_46);
x_48 = l_Lean_Expr_hash(x_43);
x_49 = 32;
x_50 = lean_uint64_shift_right(x_48, x_49);
x_51 = lean_uint64_xor(x_48, x_50);
x_52 = 16;
x_53 = lean_uint64_shift_right(x_51, x_52);
x_54 = lean_uint64_xor(x_51, x_53);
x_55 = lean_uint64_to_usize(x_54);
x_56 = lean_usize_of_nat(x_47);
lean_dec(x_47);
x_57 = 1;
x_58 = lean_usize_sub(x_56, x_57);
x_59 = lean_usize_land(x_55, x_58);
x_60 = lean_array_uget(x_46, x_59);
x_61 = l_Std_DHashMap_Internal_AssocList_contains___at_Lean_CollectFVars_visit___spec__1(x_43, x_60);
if (x_61 == 0)
{
lean_object* x_62; lean_object* x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; lean_object* x_67; lean_object* x_68; lean_object* x_69; lean_object* x_70; lean_object* x_71; uint8_t x_72; 
x_62 = lean_unsigned_to_nat(1u);
x_63 = lean_nat_add(x_45, x_62);
lean_dec(x_45);
x_64 = lean_box(0);
lean_inc(x_43);
x_65 = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(x_65, 0, x_43);
lean_ctor_set(x_65, 1, x_64);
lean_ctor_set(x_65, 2, x_60);
x_66 = lean_array_uset(x_46, x_59, x_65);
x_67 = lean_unsigned_to_nat(4u);
x_68 = lean_nat_mul(x_63, x_67);
x_69 = lean_unsigned_to_nat(3u);
x_70 = lean_nat_div(x_68, x_69);
lean_dec(x_68);
x_71 = lean_array_get_size(x_66);
x_72 = lean_nat_dec_le(x_70, x_71);
lean_dec(x_71);
lean_dec(x_70);
if (x_72 == 0)
{
lean_object* x_73; lean_object* x_74; 
x_73 = l_Std_DHashMap_Internal_Raw_u2080_expand___at_Lean_CollectFVars_visit___spec__2(x_66);
x_74 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_74, 0, x_63);
lean_ctor_set(x_74, 1, x_73);
x_5 = x_44;
x_6 = x_74;
x_7 = lean_box(0);
goto _start;
}
else
{
lean_object* x_76; 
x_76 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_76, 0, x_63);
lean_ctor_set(x_76, 1, x_66);
x_5 = x_44;
x_6 = x_76;
x_7 = lean_box(0);
goto _start;
}
}
else
{
lean_object* x_78; 
lean_dec(x_60);
x_78 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_78, 0, x_45);
lean_ctor_set(x_78, 1, x_46);
x_5 = x_44;
x_6 = x_78;
x_7 = lean_box(0);
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_getInstanceTypes___spec__4(lean_object* x_1, size_t x_2, size_t x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9) {
_start:
{
uint8_t x_10; 
x_10 = lean_usize_dec_eq(x_2, x_3);
if (x_10 == 0)
{
lean_object* x_11; lean_object* x_12; 
x_11 = lean_array_uget(x_1, x_2);
lean_inc(x_8);
lean_inc(x_7);
lean_inc(x_6);
lean_inc(x_5);
x_12 = l_getInstanceTypes(x_11, x_5, x_6, x_7, x_8, x_9);
if (lean_obj_tag(x_12) == 0)
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; uint8_t x_18; 
x_13 = lean_ctor_get(x_12, 0);
lean_inc(x_13);
x_14 = lean_ctor_get(x_12, 1);
lean_inc(x_14);
lean_dec(x_12);
x_15 = lean_ctor_get(x_13, 1);
lean_inc(x_15);
lean_dec(x_13);
x_16 = lean_array_get_size(x_15);
x_17 = lean_unsigned_to_nat(0u);
x_18 = lean_nat_dec_lt(x_17, x_16);
if (x_18 == 0)
{
size_t x_19; size_t x_20; 
lean_dec(x_16);
lean_dec(x_15);
x_19 = 1;
x_20 = lean_usize_add(x_2, x_19);
x_2 = x_20;
x_9 = x_14;
goto _start;
}
else
{
uint8_t x_22; 
x_22 = lean_nat_dec_le(x_16, x_16);
if (x_22 == 0)
{
size_t x_23; size_t x_24; 
lean_dec(x_16);
lean_dec(x_15);
x_23 = 1;
x_24 = lean_usize_add(x_2, x_23);
x_2 = x_24;
x_9 = x_14;
goto _start;
}
else
{
size_t x_26; size_t x_27; lean_object* x_28; size_t x_29; size_t x_30; 
x_26 = 0;
x_27 = lean_usize_of_nat(x_16);
lean_dec(x_16);
x_28 = l_Array_foldlMUnsafe_fold___at_Lean_Elab_Tactic_Omega_asLinearComboImpl___spec__2(x_15, x_26, x_27, x_4);
lean_dec(x_15);
x_29 = 1;
x_30 = lean_usize_add(x_2, x_29);
x_2 = x_30;
x_4 = x_28;
x_9 = x_14;
goto _start;
}
}
}
else
{
uint8_t x_32; 
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
x_32 = !lean_is_exclusive(x_12);
if (x_32 == 0)
{
return x_12;
}
else
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; 
x_33 = lean_ctor_get(x_12, 0);
x_34 = lean_ctor_get(x_12, 1);
lean_inc(x_34);
lean_inc(x_33);
lean_dec(x_12);
x_35 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_35, 0, x_33);
lean_ctor_set(x_35, 1, x_34);
return x_35;
}
}
}
else
{
lean_object* x_36; 
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_36 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_36, 0, x_4);
lean_ctor_set(x_36, 1, x_9);
return x_36;
}
}
}
static lean_object* _init_l_getInstanceTypes___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(10u);
x_2 = lean_unsigned_to_nat(1u);
x_3 = l_Nat_nextPowerOfTwo_go(x_1, x_2, lean_box(0));
return x_3;
}
}
static lean_object* _init_l_getInstanceTypes___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_getInstanceTypes___closed__1;
x_3 = lean_mk_array(x_2, x_1);
return x_3;
}
}
static lean_object* _init_l_getInstanceTypes___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = l_getInstanceTypes___closed__2;
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set(x_3, 1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_getInstanceTypes(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
switch (lean_obj_tag(x_1)) {
case 5:
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; 
x_7 = l_Lean_Expr_getAppFnArgs(x_1);
x_8 = lean_ctor_get(x_7, 0);
lean_inc(x_8);
x_9 = lean_ctor_get(x_7, 1);
lean_inc(x_9);
lean_dec(x_7);
x_10 = lean_st_ref_get(x_5, x_6);
x_11 = !lean_is_exclusive(x_10);
if (x_11 == 0)
{
lean_object* x_12; lean_object* x_13; lean_object* x_14; uint8_t x_15; lean_object* x_16; 
x_12 = lean_ctor_get(x_10, 0);
x_13 = lean_ctor_get(x_10, 1);
x_14 = lean_ctor_get(x_12, 0);
lean_inc(x_14);
lean_dec(x_12);
x_15 = 0;
x_16 = l_Lean_Environment_find_x3f(x_14, x_8, x_15);
if (lean_obj_tag(x_16) == 0)
{
lean_object* x_17; 
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_17 = l_getInstanceTypes___closed__3;
lean_ctor_set(x_10, 0, x_17);
return x_10;
}
else
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; 
lean_free_object(x_10);
x_18 = lean_ctor_get(x_16, 0);
lean_inc(x_18);
lean_dec(x_16);
x_19 = l_Lean_ConstantInfo_type(x_18);
lean_dec(x_18);
x_20 = l_getBinders(x_19, x_2, x_3, x_4, x_5, x_13);
lean_dec(x_19);
x_21 = lean_ctor_get(x_20, 0);
lean_inc(x_21);
x_22 = lean_ctor_get(x_20, 1);
lean_inc(x_22);
lean_dec(x_20);
x_23 = lean_box(0);
x_24 = lean_unsigned_to_nat(0u);
x_25 = l_List_foldrIdx___at_getInstanceTypes___spec__1(x_23, x_21, x_24);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_3);
lean_inc(x_2);
x_26 = l_List_filterMapM_loop___at_getInstanceTypes___spec__2(x_9, x_25, x_23, x_2, x_3, x_4, x_5, x_22);
if (lean_obj_tag(x_26) == 0)
{
uint8_t x_27; 
x_27 = !lean_is_exclusive(x_26);
if (x_27 == 0)
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; uint8_t x_34; 
x_28 = lean_ctor_get(x_26, 0);
x_29 = lean_ctor_get(x_26, 1);
x_30 = lean_box(0);
x_31 = l_getInstanceTypes___closed__3;
x_32 = l_List_forIn_x27_loop___at_getInstanceTypes___spec__3(x_28, x_30, x_31, x_28, x_28, x_31, lean_box(0));
lean_dec(x_28);
x_33 = lean_array_get_size(x_9);
x_34 = lean_nat_dec_lt(x_24, x_33);
if (x_34 == 0)
{
lean_dec(x_33);
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_ctor_set(x_26, 0, x_32);
return x_26;
}
else
{
uint8_t x_35; 
x_35 = lean_nat_dec_le(x_33, x_33);
if (x_35 == 0)
{
lean_dec(x_33);
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_ctor_set(x_26, 0, x_32);
return x_26;
}
else
{
size_t x_36; size_t x_37; lean_object* x_38; 
lean_free_object(x_26);
x_36 = 0;
x_37 = lean_usize_of_nat(x_33);
lean_dec(x_33);
x_38 = l_Array_foldlMUnsafe_fold___at_getInstanceTypes___spec__4(x_9, x_36, x_37, x_32, x_2, x_3, x_4, x_5, x_29);
lean_dec(x_9);
return x_38;
}
}
}
else
{
lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; uint8_t x_45; 
x_39 = lean_ctor_get(x_26, 0);
x_40 = lean_ctor_get(x_26, 1);
lean_inc(x_40);
lean_inc(x_39);
lean_dec(x_26);
x_41 = lean_box(0);
x_42 = l_getInstanceTypes___closed__3;
x_43 = l_List_forIn_x27_loop___at_getInstanceTypes___spec__3(x_39, x_41, x_42, x_39, x_39, x_42, lean_box(0));
lean_dec(x_39);
x_44 = lean_array_get_size(x_9);
x_45 = lean_nat_dec_lt(x_24, x_44);
if (x_45 == 0)
{
lean_object* x_46; 
lean_dec(x_44);
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_46 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_46, 0, x_43);
lean_ctor_set(x_46, 1, x_40);
return x_46;
}
else
{
uint8_t x_47; 
x_47 = lean_nat_dec_le(x_44, x_44);
if (x_47 == 0)
{
lean_object* x_48; 
lean_dec(x_44);
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_48 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_48, 0, x_43);
lean_ctor_set(x_48, 1, x_40);
return x_48;
}
else
{
size_t x_49; size_t x_50; lean_object* x_51; 
x_49 = 0;
x_50 = lean_usize_of_nat(x_44);
lean_dec(x_44);
x_51 = l_Array_foldlMUnsafe_fold___at_getInstanceTypes___spec__4(x_9, x_49, x_50, x_43, x_2, x_3, x_4, x_5, x_40);
lean_dec(x_9);
return x_51;
}
}
}
}
else
{
uint8_t x_52; 
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_52 = !lean_is_exclusive(x_26);
if (x_52 == 0)
{
return x_26;
}
else
{
lean_object* x_53; lean_object* x_54; lean_object* x_55; 
x_53 = lean_ctor_get(x_26, 0);
x_54 = lean_ctor_get(x_26, 1);
lean_inc(x_54);
lean_inc(x_53);
lean_dec(x_26);
x_55 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_55, 0, x_53);
lean_ctor_set(x_55, 1, x_54);
return x_55;
}
}
}
}
else
{
lean_object* x_56; lean_object* x_57; lean_object* x_58; uint8_t x_59; lean_object* x_60; 
x_56 = lean_ctor_get(x_10, 0);
x_57 = lean_ctor_get(x_10, 1);
lean_inc(x_57);
lean_inc(x_56);
lean_dec(x_10);
x_58 = lean_ctor_get(x_56, 0);
lean_inc(x_58);
lean_dec(x_56);
x_59 = 0;
x_60 = l_Lean_Environment_find_x3f(x_58, x_8, x_59);
if (lean_obj_tag(x_60) == 0)
{
lean_object* x_61; lean_object* x_62; 
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_61 = l_getInstanceTypes___closed__3;
x_62 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_62, 0, x_61);
lean_ctor_set(x_62, 1, x_57);
return x_62;
}
else
{
lean_object* x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; lean_object* x_67; lean_object* x_68; lean_object* x_69; lean_object* x_70; lean_object* x_71; 
x_63 = lean_ctor_get(x_60, 0);
lean_inc(x_63);
lean_dec(x_60);
x_64 = l_Lean_ConstantInfo_type(x_63);
lean_dec(x_63);
x_65 = l_getBinders(x_64, x_2, x_3, x_4, x_5, x_57);
lean_dec(x_64);
x_66 = lean_ctor_get(x_65, 0);
lean_inc(x_66);
x_67 = lean_ctor_get(x_65, 1);
lean_inc(x_67);
lean_dec(x_65);
x_68 = lean_box(0);
x_69 = lean_unsigned_to_nat(0u);
x_70 = l_List_foldrIdx___at_getInstanceTypes___spec__1(x_68, x_66, x_69);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_3);
lean_inc(x_2);
x_71 = l_List_filterMapM_loop___at_getInstanceTypes___spec__2(x_9, x_70, x_68, x_2, x_3, x_4, x_5, x_67);
if (lean_obj_tag(x_71) == 0)
{
lean_object* x_72; lean_object* x_73; lean_object* x_74; lean_object* x_75; lean_object* x_76; lean_object* x_77; lean_object* x_78; uint8_t x_79; 
x_72 = lean_ctor_get(x_71, 0);
lean_inc(x_72);
x_73 = lean_ctor_get(x_71, 1);
lean_inc(x_73);
if (lean_is_exclusive(x_71)) {
 lean_ctor_release(x_71, 0);
 lean_ctor_release(x_71, 1);
 x_74 = x_71;
} else {
 lean_dec_ref(x_71);
 x_74 = lean_box(0);
}
x_75 = lean_box(0);
x_76 = l_getInstanceTypes___closed__3;
x_77 = l_List_forIn_x27_loop___at_getInstanceTypes___spec__3(x_72, x_75, x_76, x_72, x_72, x_76, lean_box(0));
lean_dec(x_72);
x_78 = lean_array_get_size(x_9);
x_79 = lean_nat_dec_lt(x_69, x_78);
if (x_79 == 0)
{
lean_object* x_80; 
lean_dec(x_78);
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
if (lean_is_scalar(x_74)) {
 x_80 = lean_alloc_ctor(0, 2, 0);
} else {
 x_80 = x_74;
}
lean_ctor_set(x_80, 0, x_77);
lean_ctor_set(x_80, 1, x_73);
return x_80;
}
else
{
uint8_t x_81; 
x_81 = lean_nat_dec_le(x_78, x_78);
if (x_81 == 0)
{
lean_object* x_82; 
lean_dec(x_78);
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
if (lean_is_scalar(x_74)) {
 x_82 = lean_alloc_ctor(0, 2, 0);
} else {
 x_82 = x_74;
}
lean_ctor_set(x_82, 0, x_77);
lean_ctor_set(x_82, 1, x_73);
return x_82;
}
else
{
size_t x_83; size_t x_84; lean_object* x_85; 
lean_dec(x_74);
x_83 = 0;
x_84 = lean_usize_of_nat(x_78);
lean_dec(x_78);
x_85 = l_Array_foldlMUnsafe_fold___at_getInstanceTypes___spec__4(x_9, x_83, x_84, x_77, x_2, x_3, x_4, x_5, x_73);
lean_dec(x_9);
return x_85;
}
}
}
else
{
lean_object* x_86; lean_object* x_87; lean_object* x_88; lean_object* x_89; 
lean_dec(x_9);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_86 = lean_ctor_get(x_71, 0);
lean_inc(x_86);
x_87 = lean_ctor_get(x_71, 1);
lean_inc(x_87);
if (lean_is_exclusive(x_71)) {
 lean_ctor_release(x_71, 0);
 lean_ctor_release(x_71, 1);
 x_88 = x_71;
} else {
 lean_dec_ref(x_71);
 x_88 = lean_box(0);
}
if (lean_is_scalar(x_88)) {
 x_89 = lean_alloc_ctor(1, 2, 0);
} else {
 x_89 = x_88;
}
lean_ctor_set(x_89, 0, x_86);
lean_ctor_set(x_89, 1, x_87);
return x_89;
}
}
}
}
case 6:
{
lean_object* x_90; 
x_90 = lean_ctor_get(x_1, 2);
lean_inc(x_90);
lean_dec(x_1);
x_1 = x_90;
goto _start;
}
case 8:
{
lean_object* x_92; 
x_92 = lean_ctor_get(x_1, 3);
lean_inc(x_92);
lean_dec(x_1);
x_1 = x_92;
goto _start;
}
case 10:
{
lean_object* x_94; 
x_94 = lean_ctor_get(x_1, 1);
lean_inc(x_94);
lean_dec(x_1);
x_1 = x_94;
goto _start;
}
default: 
{
lean_object* x_96; lean_object* x_97; 
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_96 = l_getInstanceTypes___closed__3;
x_97 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_97, 0, x_96);
lean_ctor_set(x_97, 1, x_6);
return x_97;
}
}
}
}
LEAN_EXPORT lean_object* l_List_foldrIdx___at_getInstanceTypes___spec__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l_List_foldrIdx___at_getInstanceTypes___spec__1(x_1, x_2, x_3);
lean_dec(x_1);
return x_4;
}
}
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_getInstanceTypes___spec__2___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8) {
_start:
{
lean_object* x_9; 
x_9 = l_List_filterMapM_loop___at_getInstanceTypes___spec__2(x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8);
lean_dec(x_1);
return x_9;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at_getInstanceTypes___spec__3___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
lean_object* x_8; 
x_8 = l_List_forIn_x27_loop___at_getInstanceTypes___spec__3(x_1, x_2, x_3, x_4, x_5, x_6, x_7);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
return x_8;
}
}
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_getInstanceTypes___spec__4___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9) {
_start:
{
size_t x_10; size_t x_11; lean_object* x_12; 
x_10 = lean_unbox_usize(x_2);
lean_dec(x_2);
x_11 = lean_unbox_usize(x_3);
lean_dec(x_3);
x_12 = l_Array_foldlMUnsafe_fold___at_getInstanceTypes___spec__4(x_1, x_10, x_11, x_4, x_5, x_6, x_7, x_8, x_9);
lean_dec(x_1);
return x_12;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_withoutModifyingMCtx___at_unify___spec__1___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_7 = lean_st_ref_get(x_3, x_6);
x_8 = lean_ctor_get(x_7, 0);
lean_inc(x_8);
x_9 = lean_ctor_get(x_7, 1);
lean_inc(x_9);
lean_dec(x_7);
x_10 = lean_ctor_get(x_8, 0);
lean_inc(x_10);
lean_dec(x_8);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_3);
x_11 = lean_apply_5(x_1, x_2, x_3, x_4, x_5, x_9);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; uint8_t x_19; 
x_12 = lean_ctor_get(x_11, 0);
lean_inc(x_12);
x_13 = lean_ctor_get(x_11, 1);
lean_inc(x_13);
lean_dec(x_11);
x_14 = l_Lean_Meta_resetCache___rarg(x_3, x_4, x_5, x_13);
lean_dec(x_5);
lean_dec(x_4);
x_15 = lean_ctor_get(x_14, 1);
lean_inc(x_15);
lean_dec(x_14);
x_16 = lean_st_ref_take(x_3, x_15);
x_17 = lean_ctor_get(x_16, 0);
lean_inc(x_17);
x_18 = lean_ctor_get(x_16, 1);
lean_inc(x_18);
lean_dec(x_16);
x_19 = !lean_is_exclusive(x_17);
if (x_19 == 0)
{
lean_object* x_20; lean_object* x_21; uint8_t x_22; 
x_20 = lean_ctor_get(x_17, 0);
lean_dec(x_20);
lean_ctor_set(x_17, 0, x_10);
x_21 = lean_st_ref_set(x_3, x_17, x_18);
lean_dec(x_3);
x_22 = !lean_is_exclusive(x_21);
if (x_22 == 0)
{
lean_object* x_23; 
x_23 = lean_ctor_get(x_21, 0);
lean_dec(x_23);
lean_ctor_set(x_21, 0, x_12);
return x_21;
}
else
{
lean_object* x_24; lean_object* x_25; 
x_24 = lean_ctor_get(x_21, 1);
lean_inc(x_24);
lean_dec(x_21);
x_25 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_25, 0, x_12);
lean_ctor_set(x_25, 1, x_24);
return x_25;
}
}
else
{
lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; 
x_26 = lean_ctor_get(x_17, 1);
x_27 = lean_ctor_get(x_17, 2);
x_28 = lean_ctor_get(x_17, 3);
x_29 = lean_ctor_get(x_17, 4);
lean_inc(x_29);
lean_inc(x_28);
lean_inc(x_27);
lean_inc(x_26);
lean_dec(x_17);
x_30 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_30, 0, x_10);
lean_ctor_set(x_30, 1, x_26);
lean_ctor_set(x_30, 2, x_27);
lean_ctor_set(x_30, 3, x_28);
lean_ctor_set(x_30, 4, x_29);
x_31 = lean_st_ref_set(x_3, x_30, x_18);
lean_dec(x_3);
x_32 = lean_ctor_get(x_31, 1);
lean_inc(x_32);
if (lean_is_exclusive(x_31)) {
 lean_ctor_release(x_31, 0);
 lean_ctor_release(x_31, 1);
 x_33 = x_31;
} else {
 lean_dec_ref(x_31);
 x_33 = lean_box(0);
}
if (lean_is_scalar(x_33)) {
 x_34 = lean_alloc_ctor(0, 2, 0);
} else {
 x_34 = x_33;
}
lean_ctor_set(x_34, 0, x_12);
lean_ctor_set(x_34, 1, x_32);
return x_34;
}
}
else
{
lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; uint8_t x_42; 
x_35 = lean_ctor_get(x_11, 0);
lean_inc(x_35);
x_36 = lean_ctor_get(x_11, 1);
lean_inc(x_36);
lean_dec(x_11);
x_37 = l_Lean_Meta_resetCache___rarg(x_3, x_4, x_5, x_36);
lean_dec(x_5);
lean_dec(x_4);
x_38 = lean_ctor_get(x_37, 1);
lean_inc(x_38);
lean_dec(x_37);
x_39 = lean_st_ref_take(x_3, x_38);
x_40 = lean_ctor_get(x_39, 0);
lean_inc(x_40);
x_41 = lean_ctor_get(x_39, 1);
lean_inc(x_41);
lean_dec(x_39);
x_42 = !lean_is_exclusive(x_40);
if (x_42 == 0)
{
lean_object* x_43; lean_object* x_44; uint8_t x_45; 
x_43 = lean_ctor_get(x_40, 0);
lean_dec(x_43);
lean_ctor_set(x_40, 0, x_10);
x_44 = lean_st_ref_set(x_3, x_40, x_41);
lean_dec(x_3);
x_45 = !lean_is_exclusive(x_44);
if (x_45 == 0)
{
lean_object* x_46; 
x_46 = lean_ctor_get(x_44, 0);
lean_dec(x_46);
lean_ctor_set_tag(x_44, 1);
lean_ctor_set(x_44, 0, x_35);
return x_44;
}
else
{
lean_object* x_47; lean_object* x_48; 
x_47 = lean_ctor_get(x_44, 1);
lean_inc(x_47);
lean_dec(x_44);
x_48 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_48, 0, x_35);
lean_ctor_set(x_48, 1, x_47);
return x_48;
}
}
else
{
lean_object* x_49; lean_object* x_50; lean_object* x_51; lean_object* x_52; lean_object* x_53; lean_object* x_54; lean_object* x_55; lean_object* x_56; lean_object* x_57; 
x_49 = lean_ctor_get(x_40, 1);
x_50 = lean_ctor_get(x_40, 2);
x_51 = lean_ctor_get(x_40, 3);
x_52 = lean_ctor_get(x_40, 4);
lean_inc(x_52);
lean_inc(x_51);
lean_inc(x_50);
lean_inc(x_49);
lean_dec(x_40);
x_53 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_53, 0, x_10);
lean_ctor_set(x_53, 1, x_49);
lean_ctor_set(x_53, 2, x_50);
lean_ctor_set(x_53, 3, x_51);
lean_ctor_set(x_53, 4, x_52);
x_54 = lean_st_ref_set(x_3, x_53, x_41);
lean_dec(x_3);
x_55 = lean_ctor_get(x_54, 1);
lean_inc(x_55);
if (lean_is_exclusive(x_54)) {
 lean_ctor_release(x_54, 0);
 lean_ctor_release(x_54, 1);
 x_56 = x_54;
} else {
 lean_dec_ref(x_54);
 x_56 = lean_box(0);
}
if (lean_is_scalar(x_56)) {
 x_57 = lean_alloc_ctor(1, 2, 0);
} else {
 x_57 = x_56;
 lean_ctor_set_tag(x_57, 1);
}
lean_ctor_set(x_57, 0, x_35);
lean_ctor_set(x_57, 1, x_55);
return x_57;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_withoutModifyingMCtx___at_unify___spec__1(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_Lean_Meta_withoutModifyingMCtx___at_unify___spec__1___rarg), 6, 0);
return x_2;
}
}
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_unify___spec__2___rarg___lambda__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10) {
_start:
{
lean_object* x_11; 
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_7);
lean_inc(x_6);
x_11 = l_Lean_Meta_isExprDefEqGuarded(x_1, x_2, x_6, x_7, x_8, x_9, x_10);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; uint8_t x_13; 
x_12 = lean_ctor_get(x_11, 0);
lean_inc(x_12);
x_13 = lean_unbox(x_12);
lean_dec(x_12);
if (x_13 == 0)
{
uint8_t x_14; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
x_14 = !lean_is_exclusive(x_11);
if (x_14 == 0)
{
lean_object* x_15; lean_object* x_16; 
x_15 = lean_ctor_get(x_11, 0);
lean_dec(x_15);
x_16 = lean_box(0);
lean_ctor_set(x_11, 0, x_16);
return x_11;
}
else
{
lean_object* x_17; lean_object* x_18; lean_object* x_19; 
x_17 = lean_ctor_get(x_11, 1);
lean_inc(x_17);
lean_dec(x_11);
x_18 = lean_box(0);
x_19 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_19, 0, x_18);
lean_ctor_set(x_19, 1, x_17);
return x_19;
}
}
else
{
lean_object* x_20; lean_object* x_21; 
x_20 = lean_ctor_get(x_11, 1);
lean_inc(x_20);
lean_dec(x_11);
x_21 = l_unify___rarg(x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_20);
if (lean_obj_tag(x_21) == 0)
{
uint8_t x_22; 
x_22 = !lean_is_exclusive(x_21);
if (x_22 == 0)
{
lean_object* x_23; lean_object* x_24; 
x_23 = lean_ctor_get(x_21, 0);
x_24 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_24, 0, x_23);
lean_ctor_set(x_21, 0, x_24);
return x_21;
}
else
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; 
x_25 = lean_ctor_get(x_21, 0);
x_26 = lean_ctor_get(x_21, 1);
lean_inc(x_26);
lean_inc(x_25);
lean_dec(x_21);
x_27 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_27, 0, x_25);
x_28 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_28, 0, x_27);
lean_ctor_set(x_28, 1, x_26);
return x_28;
}
}
else
{
uint8_t x_29; 
x_29 = !lean_is_exclusive(x_21);
if (x_29 == 0)
{
return x_21;
}
else
{
lean_object* x_30; lean_object* x_31; lean_object* x_32; 
x_30 = lean_ctor_get(x_21, 0);
x_31 = lean_ctor_get(x_21, 1);
lean_inc(x_31);
lean_inc(x_30);
lean_dec(x_21);
x_32 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_32, 0, x_30);
lean_ctor_set(x_32, 1, x_31);
return x_32;
}
}
}
}
else
{
uint8_t x_33; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
x_33 = !lean_is_exclusive(x_11);
if (x_33 == 0)
{
return x_11;
}
else
{
lean_object* x_34; lean_object* x_35; lean_object* x_36; 
x_34 = lean_ctor_get(x_11, 0);
x_35 = lean_ctor_get(x_11, 1);
lean_inc(x_35);
lean_inc(x_34);
lean_dec(x_11);
x_36 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_36, 0, x_34);
lean_ctor_set(x_36, 1, x_35);
return x_36;
}
}
}
}
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_unify___spec__2___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11) {
_start:
{
if (lean_obj_tag(x_5) == 0)
{
lean_object* x_12; lean_object* x_13; 
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_12 = l_List_reverse___rarg(x_6);
x_13 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_13, 0, x_12);
lean_ctor_set(x_13, 1, x_11);
return x_13;
}
else
{
uint8_t x_14; 
x_14 = !lean_is_exclusive(x_5);
if (x_14 == 0)
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_15 = lean_ctor_get(x_5, 0);
x_16 = lean_ctor_get(x_5, 1);
lean_inc(x_2);
lean_inc(x_1);
lean_inc(x_3);
lean_inc(x_4);
x_17 = lean_alloc_closure((void*)(l_List_filterMapM_loop___at_unify___spec__2___rarg___lambda__1), 10, 5);
lean_closure_set(x_17, 0, x_4);
lean_closure_set(x_17, 1, x_15);
lean_closure_set(x_17, 2, x_3);
lean_closure_set(x_17, 3, x_1);
lean_closure_set(x_17, 4, x_2);
lean_inc(x_10);
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_7);
x_18 = l_Lean_Meta_withoutModifyingMCtx___at_unify___spec__1___rarg(x_17, x_7, x_8, x_9, x_10, x_11);
if (lean_obj_tag(x_18) == 0)
{
lean_object* x_19; 
x_19 = lean_ctor_get(x_18, 0);
lean_inc(x_19);
if (lean_obj_tag(x_19) == 0)
{
lean_object* x_20; 
lean_free_object(x_5);
x_20 = lean_ctor_get(x_18, 1);
lean_inc(x_20);
lean_dec(x_18);
x_5 = x_16;
x_11 = x_20;
goto _start;
}
else
{
lean_object* x_22; lean_object* x_23; 
x_22 = lean_ctor_get(x_18, 1);
lean_inc(x_22);
lean_dec(x_18);
x_23 = lean_ctor_get(x_19, 0);
lean_inc(x_23);
lean_dec(x_19);
lean_ctor_set(x_5, 1, x_6);
lean_ctor_set(x_5, 0, x_23);
{
lean_object* _tmp_4 = x_16;
lean_object* _tmp_5 = x_5;
lean_object* _tmp_10 = x_22;
x_5 = _tmp_4;
x_6 = _tmp_5;
x_11 = _tmp_10;
}
goto _start;
}
}
else
{
uint8_t x_25; 
lean_free_object(x_5);
lean_dec(x_16);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_25 = !lean_is_exclusive(x_18);
if (x_25 == 0)
{
return x_18;
}
else
{
lean_object* x_26; lean_object* x_27; lean_object* x_28; 
x_26 = lean_ctor_get(x_18, 0);
x_27 = lean_ctor_get(x_18, 1);
lean_inc(x_27);
lean_inc(x_26);
lean_dec(x_18);
x_28 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_28, 0, x_26);
lean_ctor_set(x_28, 1, x_27);
return x_28;
}
}
}
else
{
lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; 
x_29 = lean_ctor_get(x_5, 0);
x_30 = lean_ctor_get(x_5, 1);
lean_inc(x_30);
lean_inc(x_29);
lean_dec(x_5);
lean_inc(x_2);
lean_inc(x_1);
lean_inc(x_3);
lean_inc(x_4);
x_31 = lean_alloc_closure((void*)(l_List_filterMapM_loop___at_unify___spec__2___rarg___lambda__1), 10, 5);
lean_closure_set(x_31, 0, x_4);
lean_closure_set(x_31, 1, x_29);
lean_closure_set(x_31, 2, x_3);
lean_closure_set(x_31, 3, x_1);
lean_closure_set(x_31, 4, x_2);
lean_inc(x_10);
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_7);
x_32 = l_Lean_Meta_withoutModifyingMCtx___at_unify___spec__1___rarg(x_31, x_7, x_8, x_9, x_10, x_11);
if (lean_obj_tag(x_32) == 0)
{
lean_object* x_33; 
x_33 = lean_ctor_get(x_32, 0);
lean_inc(x_33);
if (lean_obj_tag(x_33) == 0)
{
lean_object* x_34; 
x_34 = lean_ctor_get(x_32, 1);
lean_inc(x_34);
lean_dec(x_32);
x_5 = x_30;
x_11 = x_34;
goto _start;
}
else
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_36 = lean_ctor_get(x_32, 1);
lean_inc(x_36);
lean_dec(x_32);
x_37 = lean_ctor_get(x_33, 0);
lean_inc(x_37);
lean_dec(x_33);
x_38 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_38, 0, x_37);
lean_ctor_set(x_38, 1, x_6);
x_5 = x_30;
x_6 = x_38;
x_11 = x_36;
goto _start;
}
}
else
{
lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; 
lean_dec(x_30);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_40 = lean_ctor_get(x_32, 0);
lean_inc(x_40);
x_41 = lean_ctor_get(x_32, 1);
lean_inc(x_41);
if (lean_is_exclusive(x_32)) {
 lean_ctor_release(x_32, 0);
 lean_ctor_release(x_32, 1);
 x_42 = x_32;
} else {
 lean_dec_ref(x_32);
 x_42 = lean_box(0);
}
if (lean_is_scalar(x_42)) {
 x_43 = lean_alloc_ctor(1, 2, 0);
} else {
 x_43 = x_42;
}
lean_ctor_set(x_43, 0, x_40);
lean_ctor_set(x_43, 1, x_41);
return x_43;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_filterMapM_loop___at_unify___spec__2(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_List_filterMapM_loop___at_unify___spec__2___rarg), 11, 0);
return x_2;
}
}
LEAN_EXPORT lean_object* l_List_flatMapTR_go___at_unify___spec__3___rarg(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
lean_object* x_3; 
x_3 = lean_array_to_list(x_2);
return x_3;
}
else
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; 
x_4 = lean_ctor_get(x_1, 0);
lean_inc(x_4);
x_5 = lean_ctor_get(x_1, 1);
lean_inc(x_5);
lean_dec(x_1);
x_6 = l_List_foldl___at_Array_appendList___spec__1___rarg(x_2, x_4);
x_1 = x_5;
x_2 = x_6;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_flatMapTR_go___at_unify___spec__3(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_List_flatMapTR_go___at_unify___spec__3___rarg), 2, 0);
return x_2;
}
}
LEAN_EXPORT lean_object* l_unify___rarg___lambda__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9) {
_start:
{
lean_object* x_10; 
x_10 = l_unify___rarg(x_1, x_2, x_3, x_5, x_6, x_7, x_8, x_9);
return x_10;
}
}
static lean_object* _init_l_unify___rarg___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_box(0);
x_2 = lean_array_mk(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_unify___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
lean_object* x_9; 
lean_dec(x_2);
x_9 = lean_apply_5(x_3, x_4, x_5, x_6, x_7, x_8);
if (lean_obj_tag(x_9) == 0)
{
uint8_t x_10; 
x_10 = !lean_is_exclusive(x_9);
if (x_10 == 0)
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_11 = lean_ctor_get(x_9, 0);
x_12 = lean_box(0);
x_13 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_13, 0, x_11);
lean_ctor_set(x_13, 1, x_12);
lean_ctor_set(x_9, 0, x_13);
return x_9;
}
else
{
lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_14 = lean_ctor_get(x_9, 0);
x_15 = lean_ctor_get(x_9, 1);
lean_inc(x_15);
lean_inc(x_14);
lean_dec(x_9);
x_16 = lean_box(0);
x_17 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_17, 0, x_14);
lean_ctor_set(x_17, 1, x_16);
x_18 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_18, 0, x_17);
lean_ctor_set(x_18, 1, x_15);
return x_18;
}
}
else
{
uint8_t x_19; 
x_19 = !lean_is_exclusive(x_9);
if (x_19 == 0)
{
return x_9;
}
else
{
lean_object* x_20; lean_object* x_21; lean_object* x_22; 
x_20 = lean_ctor_get(x_9, 0);
x_21 = lean_ctor_get(x_9, 1);
lean_inc(x_21);
lean_inc(x_20);
lean_dec(x_9);
x_22 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_22, 0, x_20);
lean_ctor_set(x_22, 1, x_21);
return x_22;
}
}
}
else
{
lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; uint8_t x_28; 
x_23 = lean_ctor_get(x_1, 0);
lean_inc(x_23);
x_24 = lean_ctor_get(x_1, 1);
lean_inc(x_24);
lean_dec(x_1);
x_25 = l_Lean_instantiateMVars___at___private_Lean_Meta_Basic_0__Lean_Meta_isClassApp_x3f___spec__1(x_23, x_4, x_5, x_6, x_7, x_8);
x_26 = lean_ctor_get(x_25, 0);
lean_inc(x_26);
x_27 = lean_ctor_get(x_25, 1);
lean_inc(x_27);
lean_dec(x_25);
x_28 = l_Lean_Expr_hasMVar(x_26);
if (x_28 == 0)
{
lean_dec(x_26);
x_1 = x_24;
x_8 = x_27;
goto _start;
}
else
{
lean_object* x_30; lean_object* x_31; 
x_30 = lean_box(0);
lean_inc(x_7);
lean_inc(x_6);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_24);
lean_inc(x_3);
lean_inc_n(x_2, 2);
x_31 = l_List_filterMapM_loop___at_unify___spec__2___rarg(x_2, x_3, x_24, x_26, x_2, x_30, x_4, x_5, x_6, x_7, x_27);
if (lean_obj_tag(x_31) == 0)
{
uint8_t x_32; 
x_32 = !lean_is_exclusive(x_31);
if (x_32 == 0)
{
lean_object* x_33; lean_object* x_34; uint8_t x_35; 
x_33 = lean_ctor_get(x_31, 0);
x_34 = lean_ctor_get(x_31, 1);
x_35 = l_List_isEmpty___rarg(x_33);
if (x_35 == 0)
{
lean_object* x_36; lean_object* x_37; 
lean_dec(x_24);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_36 = l_unify___rarg___closed__1;
x_37 = l_List_flatMapTR_go___at_unify___spec__3___rarg(x_33, x_36);
lean_ctor_set(x_31, 0, x_37);
return x_31;
}
else
{
lean_free_object(x_31);
lean_dec(x_33);
x_1 = x_24;
x_8 = x_34;
goto _start;
}
}
else
{
lean_object* x_39; lean_object* x_40; uint8_t x_41; 
x_39 = lean_ctor_get(x_31, 0);
x_40 = lean_ctor_get(x_31, 1);
lean_inc(x_40);
lean_inc(x_39);
lean_dec(x_31);
x_41 = l_List_isEmpty___rarg(x_39);
if (x_41 == 0)
{
lean_object* x_42; lean_object* x_43; lean_object* x_44; 
lean_dec(x_24);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_42 = l_unify___rarg___closed__1;
x_43 = l_List_flatMapTR_go___at_unify___spec__3___rarg(x_39, x_42);
x_44 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_44, 0, x_43);
lean_ctor_set(x_44, 1, x_40);
return x_44;
}
else
{
lean_dec(x_39);
x_1 = x_24;
x_8 = x_40;
goto _start;
}
}
}
else
{
uint8_t x_46; 
lean_dec(x_24);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_46 = !lean_is_exclusive(x_31);
if (x_46 == 0)
{
return x_31;
}
else
{
lean_object* x_47; lean_object* x_48; lean_object* x_49; 
x_47 = lean_ctor_get(x_31, 0);
x_48 = lean_ctor_get(x_31, 1);
lean_inc(x_48);
lean_inc(x_47);
lean_dec(x_31);
x_49 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_49, 0, x_47);
lean_ctor_set(x_49, 1, x_48);
return x_49;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_unify(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_unify___rarg), 8, 0);
return x_2;
}
}
LEAN_EXPORT lean_object* l_unify___rarg___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9) {
_start:
{
lean_object* x_10; 
x_10 = l_unify___rarg___lambda__1(x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9);
lean_dec(x_4);
return x_10;
}
}
LEAN_EXPORT lean_object* l_updateLambdaBinderInfos(lean_object* x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_1) == 6)
{
if (lean_obj_tag(x_2) == 0)
{
return x_1;
}
else
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; uint8_t x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_3 = lean_ctor_get(x_1, 0);
lean_inc(x_3);
x_4 = lean_ctor_get(x_1, 1);
lean_inc(x_4);
x_5 = lean_ctor_get(x_1, 2);
lean_inc(x_5);
x_6 = lean_ctor_get_uint8(x_1, sizeof(void*)*3 + 8);
lean_dec(x_1);
x_7 = lean_ctor_get(x_2, 0);
lean_inc(x_7);
x_8 = lean_ctor_get(x_2, 1);
lean_inc(x_8);
lean_dec(x_2);
x_9 = l_updateLambdaBinderInfos(x_5, x_8);
if (lean_obj_tag(x_7) == 0)
{
lean_object* x_10; 
x_10 = l_Lean_Expr_lam___override(x_3, x_4, x_9, x_6);
return x_10;
}
else
{
lean_object* x_11; uint8_t x_12; lean_object* x_13; 
x_11 = lean_ctor_get(x_7, 0);
lean_inc(x_11);
lean_dec(x_7);
x_12 = lean_unbox(x_11);
lean_dec(x_11);
x_13 = l_Lean_Expr_lam___override(x_3, x_4, x_9, x_12);
return x_13;
}
}
}
else
{
lean_dec(x_2);
return x_1;
}
}
}
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_monomorphizeCore___spec__2(lean_object* x_1, size_t x_2, size_t x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; 
x_5 = lean_usize_dec_eq(x_2, x_3);
if (x_5 == 0)
{
lean_object* x_6; size_t x_7; size_t x_8; lean_object* x_9; lean_object* x_10; uint8_t x_11; uint8_t x_12; 
x_6 = lean_array_uget(x_1, x_2);
x_7 = 1;
x_8 = lean_usize_add(x_2, x_7);
x_9 = lean_ctor_get(x_6, 0);
lean_inc(x_9);
x_10 = lean_ctor_get(x_6, 1);
lean_inc(x_10);
lean_dec(x_6);
x_11 = lean_unbox(x_10);
lean_dec(x_10);
x_12 = l_Lean_BinderInfo_isInstImplicit(x_11);
if (x_12 == 0)
{
lean_dec(x_9);
x_2 = x_8;
goto _start;
}
else
{
lean_object* x_14; 
x_14 = lean_array_push(x_4, x_9);
x_2 = x_8;
x_4 = x_14;
goto _start;
}
}
else
{
return x_4;
}
}
}
LEAN_EXPORT lean_object* l_Array_filterMapM___at_monomorphizeCore___spec__1(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; 
x_4 = lean_nat_dec_lt(x_2, x_3);
if (x_4 == 0)
{
lean_object* x_5; 
x_5 = l_unify___rarg___closed__1;
return x_5;
}
else
{
lean_object* x_6; uint8_t x_7; 
x_6 = lean_array_get_size(x_1);
x_7 = lean_nat_dec_le(x_3, x_6);
lean_dec(x_6);
if (x_7 == 0)
{
lean_object* x_8; 
x_8 = l_unify___rarg___closed__1;
return x_8;
}
else
{
size_t x_9; size_t x_10; lean_object* x_11; lean_object* x_12; 
x_9 = lean_usize_of_nat(x_2);
x_10 = lean_usize_of_nat(x_3);
x_11 = l_unify___rarg___closed__1;
x_12 = l_Array_foldlMUnsafe_fold___at_monomorphizeCore___spec__2(x_1, x_9, x_10, x_11);
return x_12;
}
}
}
}
LEAN_EXPORT lean_object* l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__3(size_t x_1, size_t x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8) {
_start:
{
uint8_t x_9; 
x_9 = lean_usize_dec_lt(x_2, x_1);
if (x_9 == 0)
{
lean_object* x_10; 
x_10 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_10, 0, x_3);
lean_ctor_set(x_10, 1, x_8);
return x_10;
}
else
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; 
x_11 = lean_array_uget(x_3, x_2);
x_12 = lean_unsigned_to_nat(0u);
x_13 = lean_array_uset(x_3, x_2, x_12);
x_14 = l_Lean_Expr_mvarId_x21(x_11);
lean_dec(x_11);
x_15 = l_Lean_MVarId_getType(x_14, x_4, x_5, x_6, x_7, x_8);
if (lean_obj_tag(x_15) == 0)
{
lean_object* x_16; lean_object* x_17; size_t x_18; size_t x_19; lean_object* x_20; 
x_16 = lean_ctor_get(x_15, 0);
lean_inc(x_16);
x_17 = lean_ctor_get(x_15, 1);
lean_inc(x_17);
lean_dec(x_15);
x_18 = 1;
x_19 = lean_usize_add(x_2, x_18);
x_20 = lean_array_uset(x_13, x_2, x_16);
x_2 = x_19;
x_3 = x_20;
x_8 = x_17;
goto _start;
}
else
{
uint8_t x_22; 
lean_dec(x_13);
x_22 = !lean_is_exclusive(x_15);
if (x_22 == 0)
{
return x_15;
}
else
{
lean_object* x_23; lean_object* x_24; lean_object* x_25; 
x_23 = lean_ctor_get(x_15, 0);
x_24 = lean_ctor_get(x_15, 1);
lean_inc(x_24);
lean_inc(x_23);
lean_dec(x_15);
x_25 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_25, 0, x_23);
lean_ctor_set(x_25, 1, x_24);
return x_25;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at_monomorphizeCore___spec__4(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
if (lean_obj_tag(x_5) == 0)
{
return x_6;
}
else
{
uint8_t x_8; 
x_8 = !lean_is_exclusive(x_6);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; uint64_t x_14; uint64_t x_15; uint64_t x_16; uint64_t x_17; uint64_t x_18; uint64_t x_19; uint64_t x_20; size_t x_21; size_t x_22; size_t x_23; size_t x_24; size_t x_25; lean_object* x_26; uint8_t x_27; 
x_9 = lean_ctor_get(x_5, 0);
x_10 = lean_ctor_get(x_5, 1);
x_11 = lean_ctor_get(x_6, 0);
x_12 = lean_ctor_get(x_6, 1);
x_13 = lean_array_get_size(x_12);
x_14 = l_Lean_Expr_hash(x_9);
x_15 = 32;
x_16 = lean_uint64_shift_right(x_14, x_15);
x_17 = lean_uint64_xor(x_14, x_16);
x_18 = 16;
x_19 = lean_uint64_shift_right(x_17, x_18);
x_20 = lean_uint64_xor(x_17, x_19);
x_21 = lean_uint64_to_usize(x_20);
x_22 = lean_usize_of_nat(x_13);
lean_dec(x_13);
x_23 = 1;
x_24 = lean_usize_sub(x_22, x_23);
x_25 = lean_usize_land(x_21, x_24);
x_26 = lean_array_uget(x_12, x_25);
x_27 = l_Std_DHashMap_Internal_AssocList_contains___at_Lean_CollectFVars_visit___spec__1(x_9, x_26);
if (x_27 == 0)
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; lean_object* x_37; uint8_t x_38; 
x_28 = lean_unsigned_to_nat(1u);
x_29 = lean_nat_add(x_11, x_28);
lean_dec(x_11);
x_30 = lean_box(0);
lean_inc(x_9);
x_31 = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(x_31, 0, x_9);
lean_ctor_set(x_31, 1, x_30);
lean_ctor_set(x_31, 2, x_26);
x_32 = lean_array_uset(x_12, x_25, x_31);
x_33 = lean_unsigned_to_nat(4u);
x_34 = lean_nat_mul(x_29, x_33);
x_35 = lean_unsigned_to_nat(3u);
x_36 = lean_nat_div(x_34, x_35);
lean_dec(x_34);
x_37 = lean_array_get_size(x_32);
x_38 = lean_nat_dec_le(x_36, x_37);
lean_dec(x_37);
lean_dec(x_36);
if (x_38 == 0)
{
lean_object* x_39; 
x_39 = l_Std_DHashMap_Internal_Raw_u2080_expand___at_Lean_CollectFVars_visit___spec__2(x_32);
lean_ctor_set(x_6, 1, x_39);
lean_ctor_set(x_6, 0, x_29);
x_5 = x_10;
x_7 = lean_box(0);
goto _start;
}
else
{
lean_ctor_set(x_6, 1, x_32);
lean_ctor_set(x_6, 0, x_29);
x_5 = x_10;
x_7 = lean_box(0);
goto _start;
}
}
else
{
lean_dec(x_26);
x_5 = x_10;
x_7 = lean_box(0);
goto _start;
}
}
else
{
lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; uint64_t x_48; uint64_t x_49; uint64_t x_50; uint64_t x_51; uint64_t x_52; uint64_t x_53; uint64_t x_54; size_t x_55; size_t x_56; size_t x_57; size_t x_58; size_t x_59; lean_object* x_60; uint8_t x_61; 
x_43 = lean_ctor_get(x_5, 0);
x_44 = lean_ctor_get(x_5, 1);
x_45 = lean_ctor_get(x_6, 0);
x_46 = lean_ctor_get(x_6, 1);
lean_inc(x_46);
lean_inc(x_45);
lean_dec(x_6);
x_47 = lean_array_get_size(x_46);
x_48 = l_Lean_Expr_hash(x_43);
x_49 = 32;
x_50 = lean_uint64_shift_right(x_48, x_49);
x_51 = lean_uint64_xor(x_48, x_50);
x_52 = 16;
x_53 = lean_uint64_shift_right(x_51, x_52);
x_54 = lean_uint64_xor(x_51, x_53);
x_55 = lean_uint64_to_usize(x_54);
x_56 = lean_usize_of_nat(x_47);
lean_dec(x_47);
x_57 = 1;
x_58 = lean_usize_sub(x_56, x_57);
x_59 = lean_usize_land(x_55, x_58);
x_60 = lean_array_uget(x_46, x_59);
x_61 = l_Std_DHashMap_Internal_AssocList_contains___at_Lean_CollectFVars_visit___spec__1(x_43, x_60);
if (x_61 == 0)
{
lean_object* x_62; lean_object* x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; lean_object* x_67; lean_object* x_68; lean_object* x_69; lean_object* x_70; lean_object* x_71; uint8_t x_72; 
x_62 = lean_unsigned_to_nat(1u);
x_63 = lean_nat_add(x_45, x_62);
lean_dec(x_45);
x_64 = lean_box(0);
lean_inc(x_43);
x_65 = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(x_65, 0, x_43);
lean_ctor_set(x_65, 1, x_64);
lean_ctor_set(x_65, 2, x_60);
x_66 = lean_array_uset(x_46, x_59, x_65);
x_67 = lean_unsigned_to_nat(4u);
x_68 = lean_nat_mul(x_63, x_67);
x_69 = lean_unsigned_to_nat(3u);
x_70 = lean_nat_div(x_68, x_69);
lean_dec(x_68);
x_71 = lean_array_get_size(x_66);
x_72 = lean_nat_dec_le(x_70, x_71);
lean_dec(x_71);
lean_dec(x_70);
if (x_72 == 0)
{
lean_object* x_73; lean_object* x_74; 
x_73 = l_Std_DHashMap_Internal_Raw_u2080_expand___at_Lean_CollectFVars_visit___spec__2(x_66);
x_74 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_74, 0, x_63);
lean_ctor_set(x_74, 1, x_73);
x_5 = x_44;
x_6 = x_74;
x_7 = lean_box(0);
goto _start;
}
else
{
lean_object* x_76; 
x_76 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_76, 0, x_63);
lean_ctor_set(x_76, 1, x_66);
x_5 = x_44;
x_6 = x_76;
x_7 = lean_box(0);
goto _start;
}
}
else
{
lean_object* x_78; 
lean_dec(x_60);
x_78 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_78, 0, x_45);
lean_ctor_set(x_78, 1, x_46);
x_5 = x_44;
x_6 = x_78;
x_7 = lean_box(0);
goto _start;
}
}
}
}
}
static lean_object* _init_l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_box(0);
x_2 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, size_t x_5, size_t x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11, lean_object* x_12) {
_start:
{
uint8_t x_13; 
x_13 = lean_usize_dec_lt(x_6, x_5);
if (x_13 == 0)
{
lean_object* x_14; 
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_1);
x_14 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_14, 0, x_7);
lean_ctor_set(x_14, 1, x_12);
return x_14;
}
else
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_23; lean_object* x_24; 
lean_dec(x_7);
x_15 = lean_array_uget(x_4, x_6);
x_23 = l_Lean_Expr_mvarId_x21(x_15);
lean_dec(x_15);
lean_inc(x_23);
x_24 = l_Lean_MVarId_getType(x_23, x_8, x_9, x_10, x_11, x_12);
if (lean_obj_tag(x_24) == 0)
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_25 = lean_ctor_get(x_24, 0);
lean_inc(x_25);
x_26 = lean_ctor_get(x_24, 1);
lean_inc(x_26);
lean_dec(x_24);
x_27 = l_Lean_instantiateMVars___at___private_Lean_Meta_Basic_0__Lean_Meta_isClassApp_x3f___spec__1(x_25, x_8, x_9, x_10, x_11, x_26);
x_28 = lean_ctor_get(x_27, 0);
lean_inc(x_28);
x_29 = lean_ctor_get(x_27, 1);
lean_inc(x_29);
lean_dec(x_27);
lean_inc(x_11);
lean_inc(x_10);
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_1);
x_30 = l_Lean_Meta_synthInstance(x_28, x_1, x_8, x_9, x_10, x_11, x_29);
if (lean_obj_tag(x_30) == 0)
{
lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; 
x_31 = lean_ctor_get(x_30, 0);
lean_inc(x_31);
x_32 = lean_ctor_get(x_30, 1);
lean_inc(x_32);
lean_dec(x_30);
x_33 = l_Lean_MVarId_assign___at_Lean_Tactic_FunInd_abstractIndependentMVars___spec__3(x_23, x_31, x_8, x_9, x_10, x_11, x_32);
x_34 = lean_ctor_get(x_33, 1);
lean_inc(x_34);
lean_dec(x_33);
x_35 = l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___closed__1;
x_16 = x_35;
x_17 = x_34;
goto block_22;
}
else
{
uint8_t x_36; 
lean_dec(x_23);
x_36 = !lean_is_exclusive(x_30);
if (x_36 == 0)
{
lean_object* x_37; lean_object* x_38; uint8_t x_39; 
x_37 = lean_ctor_get(x_30, 0);
x_38 = lean_ctor_get(x_30, 1);
x_39 = l_Lean_Exception_isInterrupt(x_37);
if (x_39 == 0)
{
uint8_t x_40; 
x_40 = l_Lean_Exception_isRuntime(x_37);
if (x_40 == 0)
{
lean_object* x_41; 
lean_free_object(x_30);
lean_dec(x_37);
x_41 = l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___closed__1;
x_16 = x_41;
x_17 = x_38;
goto block_22;
}
else
{
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_1);
return x_30;
}
}
else
{
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_1);
return x_30;
}
}
else
{
lean_object* x_42; lean_object* x_43; uint8_t x_44; 
x_42 = lean_ctor_get(x_30, 0);
x_43 = lean_ctor_get(x_30, 1);
lean_inc(x_43);
lean_inc(x_42);
lean_dec(x_30);
x_44 = l_Lean_Exception_isInterrupt(x_42);
if (x_44 == 0)
{
uint8_t x_45; 
x_45 = l_Lean_Exception_isRuntime(x_42);
if (x_45 == 0)
{
lean_object* x_46; 
lean_dec(x_42);
x_46 = l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___closed__1;
x_16 = x_46;
x_17 = x_43;
goto block_22;
}
else
{
lean_object* x_47; 
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_1);
x_47 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_47, 0, x_42);
lean_ctor_set(x_47, 1, x_43);
return x_47;
}
}
else
{
lean_object* x_48; 
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_1);
x_48 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_48, 0, x_42);
lean_ctor_set(x_48, 1, x_43);
return x_48;
}
}
}
}
else
{
uint8_t x_49; 
lean_dec(x_23);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_1);
x_49 = !lean_is_exclusive(x_24);
if (x_49 == 0)
{
return x_24;
}
else
{
lean_object* x_50; lean_object* x_51; lean_object* x_52; 
x_50 = lean_ctor_get(x_24, 0);
x_51 = lean_ctor_get(x_24, 1);
lean_inc(x_51);
lean_inc(x_50);
lean_dec(x_24);
x_52 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_52, 0, x_50);
lean_ctor_set(x_52, 1, x_51);
return x_52;
}
}
block_22:
{
lean_object* x_18; size_t x_19; size_t x_20; 
x_18 = lean_ctor_get(x_16, 0);
lean_inc(x_18);
lean_dec(x_16);
x_19 = 1;
x_20 = lean_usize_add(x_6, x_19);
x_6 = x_20;
x_7 = x_18;
x_12 = x_17;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__6(lean_object* x_1, lean_object* x_2, size_t x_3, size_t x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; 
x_6 = lean_usize_dec_lt(x_4, x_3);
if (x_6 == 0)
{
return x_5;
}
else
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; size_t x_11; size_t x_12; 
x_7 = lean_array_uget(x_5, x_4);
x_8 = lean_unsigned_to_nat(0u);
x_9 = lean_array_uset(x_5, x_4, x_8);
x_10 = l_Array_idxOf_x3f___at___private_Lean_Meta_Constructions_BRecOn_0__Lean_buildBRecOnMinorPremise_go___spec__1(x_1, x_7);
lean_dec(x_7);
x_11 = 1;
x_12 = lean_usize_add(x_4, x_11);
if (lean_obj_tag(x_10) == 0)
{
lean_object* x_13; lean_object* x_14; 
x_13 = lean_box(0);
x_14 = lean_array_uset(x_9, x_4, x_13);
x_4 = x_12;
x_5 = x_14;
goto _start;
}
else
{
uint8_t x_16; 
x_16 = !lean_is_exclusive(x_10);
if (x_16 == 0)
{
lean_object* x_17; uint8_t x_18; lean_object* x_19; lean_object* x_20; uint8_t x_21; lean_object* x_22; lean_object* x_23; 
x_17 = lean_ctor_get(x_10, 0);
x_18 = l_Lean_instInhabitedBinderInfo;
x_19 = lean_box(x_18);
x_20 = lean_array_get(x_19, x_2, x_17);
lean_dec(x_17);
x_21 = lean_unbox(x_20);
lean_dec(x_20);
x_22 = lean_box(x_21);
lean_ctor_set(x_10, 0, x_22);
x_23 = lean_array_uset(x_9, x_4, x_10);
x_4 = x_12;
x_5 = x_23;
goto _start;
}
else
{
lean_object* x_25; uint8_t x_26; lean_object* x_27; lean_object* x_28; uint8_t x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; 
x_25 = lean_ctor_get(x_10, 0);
lean_inc(x_25);
lean_dec(x_10);
x_26 = l_Lean_instInhabitedBinderInfo;
x_27 = lean_box(x_26);
x_28 = lean_array_get(x_27, x_2, x_25);
lean_dec(x_25);
x_29 = lean_unbox(x_28);
lean_dec(x_28);
x_30 = lean_box(x_29);
x_31 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_31, 0, x_30);
x_32 = lean_array_uset(x_9, x_4, x_31);
x_4 = x_12;
x_5 = x_32;
goto _start;
}
}
}
}
}
LEAN_EXPORT uint8_t l_List_foldlM___at_monomorphizeCore___spec__7___lambda__1(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = 0;
return x_2;
}
}
static lean_object* _init_l_List_foldlM___at_monomorphizeCore___spec__7___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_List_foldlM___at_monomorphizeCore___spec__7___lambda__1___boxed), 1, 0);
return x_1;
}
}
static lean_object* _init_l_List_foldlM___at_monomorphizeCore___spec__7___closed__2() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("'", 1, 1);
return x_1;
}
}
LEAN_EXPORT lean_object* l_List_foldlM___at_monomorphizeCore___spec__7(lean_object* x_1, lean_object* x_2, lean_object* x_3, size_t x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11) {
_start:
{
if (lean_obj_tag(x_6) == 0)
{
lean_object* x_12; 
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_1);
x_12 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_12, 0, x_5);
lean_ctor_set(x_12, 1, x_11);
return x_12;
}
else
{
lean_object* x_13; lean_object* x_14; lean_object* x_15; size_t x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; uint8_t x_21; lean_object* x_22; 
x_13 = lean_ctor_get(x_6, 0);
lean_inc(x_13);
x_14 = lean_ctor_get(x_6, 1);
lean_inc(x_14);
lean_dec(x_6);
x_15 = lean_ctor_get(x_13, 1);
lean_inc(x_15);
x_16 = lean_array_size(x_15);
x_17 = l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__6(x_2, x_3, x_16, x_4, x_15);
x_18 = lean_ctor_get(x_13, 2);
lean_inc(x_18);
lean_dec(x_13);
x_19 = lean_array_to_list(x_17);
x_20 = l_updateLambdaBinderInfos(x_18, x_19);
x_21 = l_Lean_Name_hasMacroScopes(x_1);
x_22 = lean_box(0);
if (x_21 == 0)
{
uint8_t x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; 
x_23 = 1;
x_24 = l_List_foldlM___at_monomorphizeCore___spec__7___closed__1;
lean_inc(x_1);
x_25 = l_Lean_Name_toString(x_1, x_23, x_24);
x_26 = l_List_foldlM___at_monomorphizeCore___spec__7___closed__2;
x_27 = lean_string_append(x_25, x_26);
x_28 = lean_box(0);
x_29 = l_Lean_Name_str___override(x_28, x_27);
lean_inc(x_10);
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_7);
x_30 = l_Lean_MVarId_note(x_5, x_29, x_20, x_22, x_7, x_8, x_9, x_10, x_11);
if (lean_obj_tag(x_30) == 0)
{
lean_object* x_31; lean_object* x_32; lean_object* x_33; 
x_31 = lean_ctor_get(x_30, 0);
lean_inc(x_31);
x_32 = lean_ctor_get(x_30, 1);
lean_inc(x_32);
lean_dec(x_30);
x_33 = lean_ctor_get(x_31, 1);
lean_inc(x_33);
lean_dec(x_31);
x_5 = x_33;
x_6 = x_14;
x_11 = x_32;
goto _start;
}
else
{
uint8_t x_35; 
lean_dec(x_14);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_1);
x_35 = !lean_is_exclusive(x_30);
if (x_35 == 0)
{
return x_30;
}
else
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_36 = lean_ctor_get(x_30, 0);
x_37 = lean_ctor_get(x_30, 1);
lean_inc(x_37);
lean_inc(x_36);
lean_dec(x_30);
x_38 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_38, 0, x_36);
lean_ctor_set(x_38, 1, x_37);
return x_38;
}
}
}
else
{
lean_object* x_39; uint8_t x_40; 
lean_inc(x_1);
x_39 = l_Lean_extractMacroScopes(x_1);
x_40 = !lean_is_exclusive(x_39);
if (x_40 == 0)
{
lean_object* x_41; uint8_t x_42; lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; lean_object* x_50; 
x_41 = lean_ctor_get(x_39, 0);
x_42 = 1;
x_43 = l_List_foldlM___at_monomorphizeCore___spec__7___closed__1;
x_44 = l_Lean_Name_toString(x_41, x_42, x_43);
x_45 = l_List_foldlM___at_monomorphizeCore___spec__7___closed__2;
x_46 = lean_string_append(x_44, x_45);
x_47 = lean_box(0);
x_48 = l_Lean_Name_str___override(x_47, x_46);
lean_ctor_set(x_39, 0, x_48);
x_49 = l_Lean_MacroScopesView_review(x_39);
lean_inc(x_10);
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_7);
x_50 = l_Lean_MVarId_note(x_5, x_49, x_20, x_22, x_7, x_8, x_9, x_10, x_11);
if (lean_obj_tag(x_50) == 0)
{
lean_object* x_51; lean_object* x_52; lean_object* x_53; 
x_51 = lean_ctor_get(x_50, 0);
lean_inc(x_51);
x_52 = lean_ctor_get(x_50, 1);
lean_inc(x_52);
lean_dec(x_50);
x_53 = lean_ctor_get(x_51, 1);
lean_inc(x_53);
lean_dec(x_51);
x_5 = x_53;
x_6 = x_14;
x_11 = x_52;
goto _start;
}
else
{
uint8_t x_55; 
lean_dec(x_14);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_1);
x_55 = !lean_is_exclusive(x_50);
if (x_55 == 0)
{
return x_50;
}
else
{
lean_object* x_56; lean_object* x_57; lean_object* x_58; 
x_56 = lean_ctor_get(x_50, 0);
x_57 = lean_ctor_get(x_50, 1);
lean_inc(x_57);
lean_inc(x_56);
lean_dec(x_50);
x_58 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_58, 0, x_56);
lean_ctor_set(x_58, 1, x_57);
return x_58;
}
}
}
else
{
lean_object* x_59; lean_object* x_60; lean_object* x_61; lean_object* x_62; uint8_t x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; lean_object* x_67; lean_object* x_68; lean_object* x_69; lean_object* x_70; lean_object* x_71; lean_object* x_72; 
x_59 = lean_ctor_get(x_39, 0);
x_60 = lean_ctor_get(x_39, 1);
x_61 = lean_ctor_get(x_39, 2);
x_62 = lean_ctor_get(x_39, 3);
lean_inc(x_62);
lean_inc(x_61);
lean_inc(x_60);
lean_inc(x_59);
lean_dec(x_39);
x_63 = 1;
x_64 = l_List_foldlM___at_monomorphizeCore___spec__7___closed__1;
x_65 = l_Lean_Name_toString(x_59, x_63, x_64);
x_66 = l_List_foldlM___at_monomorphizeCore___spec__7___closed__2;
x_67 = lean_string_append(x_65, x_66);
x_68 = lean_box(0);
x_69 = l_Lean_Name_str___override(x_68, x_67);
x_70 = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(x_70, 0, x_69);
lean_ctor_set(x_70, 1, x_60);
lean_ctor_set(x_70, 2, x_61);
lean_ctor_set(x_70, 3, x_62);
x_71 = l_Lean_MacroScopesView_review(x_70);
lean_inc(x_10);
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_7);
x_72 = l_Lean_MVarId_note(x_5, x_71, x_20, x_22, x_7, x_8, x_9, x_10, x_11);
if (lean_obj_tag(x_72) == 0)
{
lean_object* x_73; lean_object* x_74; lean_object* x_75; 
x_73 = lean_ctor_get(x_72, 0);
lean_inc(x_73);
x_74 = lean_ctor_get(x_72, 1);
lean_inc(x_74);
lean_dec(x_72);
x_75 = lean_ctor_get(x_73, 1);
lean_inc(x_75);
lean_dec(x_73);
x_5 = x_75;
x_6 = x_14;
x_11 = x_74;
goto _start;
}
else
{
lean_object* x_77; lean_object* x_78; lean_object* x_79; lean_object* x_80; 
lean_dec(x_14);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_1);
x_77 = lean_ctor_get(x_72, 0);
lean_inc(x_77);
x_78 = lean_ctor_get(x_72, 1);
lean_inc(x_78);
if (lean_is_exclusive(x_72)) {
 lean_ctor_release(x_72, 0);
 lean_ctor_release(x_72, 1);
 x_79 = x_72;
} else {
 lean_dec_ref(x_72);
 x_79 = lean_box(0);
}
if (lean_is_scalar(x_79)) {
 x_80 = lean_alloc_ctor(1, 2, 0);
} else {
 x_80 = x_79;
}
lean_ctor_set(x_80, 0, x_77);
lean_ctor_set(x_80, 1, x_78);
return x_80;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_monomorphizeCore___lambda__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, size_t x_4, size_t x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11, lean_object* x_12, lean_object* x_13) {
_start:
{
lean_object* x_14; lean_object* x_15; 
x_14 = lean_box(0);
lean_inc(x_12);
lean_inc(x_11);
lean_inc(x_10);
lean_inc(x_9);
x_15 = l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5(x_1, x_2, x_3, x_2, x_4, x_5, x_14, x_9, x_10, x_11, x_12, x_13);
if (lean_obj_tag(x_15) == 0)
{
lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; uint8_t x_22; lean_object* x_23; 
x_16 = lean_ctor_get(x_15, 1);
lean_inc(x_16);
lean_dec(x_15);
x_17 = l_Lean_Expr_const___override(x_6, x_7);
x_18 = l_Lean_mkAppN(x_17, x_8);
x_19 = l_Lean_instantiateMVars___at___private_Lean_Meta_Basic_0__Lean_Meta_isClassApp_x3f___spec__1(x_18, x_9, x_10, x_11, x_12, x_16);
x_20 = lean_ctor_get(x_19, 0);
lean_inc(x_20);
x_21 = lean_ctor_get(x_19, 1);
lean_inc(x_21);
lean_dec(x_19);
x_22 = 1;
x_23 = l_Lean_Meta_abstractMVars(x_20, x_22, x_9, x_10, x_11, x_12, x_21);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
return x_23;
}
else
{
uint8_t x_24; 
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_7);
lean_dec(x_6);
x_24 = !lean_is_exclusive(x_15);
if (x_24 == 0)
{
return x_15;
}
else
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; 
x_25 = lean_ctor_get(x_15, 0);
x_26 = lean_ctor_get(x_15, 1);
lean_inc(x_26);
lean_inc(x_25);
lean_dec(x_15);
x_27 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_27, 0, x_25);
lean_ctor_set(x_27, 1, x_26);
return x_27;
}
}
}
}
static lean_object* _init_l_monomorphizeCore___lambda__2___boxed__const__1() {
_start:
{
size_t x_1; lean_object* x_2; 
x_1 = 0;
x_2 = lean_box_usize(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_monomorphizeCore___lambda__2(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
lean_object* x_8; 
lean_inc(x_6);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_3);
x_8 = l_Lean_resolveGlobalConstNoOverload___at___private_Lean_Meta_Tactic_Grind_PropagatorAttr_0__Lean_Meta_Grind_addBuiltin___spec__1(x_1, x_3, x_4, x_5, x_6, x_7);
if (lean_obj_tag(x_8) == 0)
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_9 = lean_ctor_get(x_8, 0);
lean_inc(x_9);
x_10 = lean_ctor_get(x_8, 1);
lean_inc(x_10);
lean_dec(x_8);
lean_inc(x_9);
x_11 = l_Lean_getConstInfo___at_Lean_Meta_mkConstWithFreshMVarLevels___spec__1(x_9, x_3, x_4, x_5, x_6, x_10);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; lean_object* x_13; lean_object* x_14; 
x_12 = lean_ctor_get(x_11, 0);
lean_inc(x_12);
x_13 = lean_ctor_get(x_11, 1);
lean_inc(x_13);
lean_dec(x_11);
lean_inc(x_2);
x_14 = l_Lean_MVarId_getType(x_2, x_3, x_4, x_5, x_6, x_13);
if (lean_obj_tag(x_14) == 0)
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; 
x_15 = lean_ctor_get(x_14, 0);
lean_inc(x_15);
x_16 = lean_ctor_get(x_14, 1);
lean_inc(x_16);
lean_dec(x_14);
x_17 = l_Lean_ConstantInfo_levelParams(x_12);
x_18 = lean_box(0);
lean_inc(x_17);
x_19 = l_List_mapM_loop___at_Lean_Meta_tryUnificationHints_tryCandidate___spec__1(x_17, x_18, x_3, x_4, x_5, x_6, x_16);
x_20 = lean_ctor_get(x_19, 0);
lean_inc(x_20);
x_21 = lean_ctor_get(x_19, 1);
lean_inc(x_21);
lean_dec(x_19);
x_22 = l_Lean_ConstantInfo_type(x_12);
lean_dec(x_12);
lean_inc(x_20);
x_23 = l_Lean_Expr_instantiateLevelParams(x_22, x_17, x_20);
lean_dec(x_22);
lean_inc(x_6);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_3);
x_24 = l_getInstanceTypes(x_15, x_3, x_4, x_5, x_6, x_21);
if (lean_obj_tag(x_24) == 0)
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; uint8_t x_30; uint8_t x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_94; uint8_t x_95; 
x_25 = lean_ctor_get(x_24, 0);
lean_inc(x_25);
x_26 = lean_ctor_get(x_24, 1);
lean_inc(x_26);
lean_dec(x_24);
x_27 = lean_ctor_get(x_25, 1);
lean_inc(x_27);
lean_dec(x_25);
x_28 = lean_array_get_size(x_27);
x_29 = lean_box(0);
x_30 = 1;
x_31 = 0;
lean_inc(x_6);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_3);
x_32 = l___private_Lean_Meta_Basic_0__Lean_Meta_forallMetaTelescopeReducingAux(x_23, x_30, x_29, x_31, x_3, x_4, x_5, x_6, x_26);
x_94 = lean_unsigned_to_nat(0u);
x_95 = lean_nat_dec_lt(x_94, x_28);
if (x_95 == 0)
{
lean_dec(x_28);
lean_dec(x_27);
if (lean_obj_tag(x_32) == 0)
{
lean_object* x_96; lean_object* x_97; 
x_96 = lean_ctor_get(x_32, 0);
lean_inc(x_96);
x_97 = lean_ctor_get(x_32, 1);
lean_inc(x_97);
lean_dec(x_32);
x_33 = x_18;
x_34 = x_96;
x_35 = x_97;
goto block_93;
}
else
{
uint8_t x_98; 
lean_dec(x_20);
lean_dec(x_9);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_98 = !lean_is_exclusive(x_32);
if (x_98 == 0)
{
return x_32;
}
else
{
lean_object* x_99; lean_object* x_100; lean_object* x_101; 
x_99 = lean_ctor_get(x_32, 0);
x_100 = lean_ctor_get(x_32, 1);
lean_inc(x_100);
lean_inc(x_99);
lean_dec(x_32);
x_101 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_101, 0, x_99);
lean_ctor_set(x_101, 1, x_100);
return x_101;
}
}
}
else
{
if (lean_obj_tag(x_32) == 0)
{
lean_object* x_102; lean_object* x_103; size_t x_104; size_t x_105; lean_object* x_106; 
x_102 = lean_ctor_get(x_32, 0);
lean_inc(x_102);
x_103 = lean_ctor_get(x_32, 1);
lean_inc(x_103);
lean_dec(x_32);
x_104 = lean_usize_of_nat(x_28);
lean_dec(x_28);
x_105 = 0;
x_106 = l_Array_foldrMUnsafe_fold___at_Lean_Elab_Tactic_BVDecide_Frontend_uninterpretedExplainer___spec__2(x_27, x_104, x_105, x_18);
lean_dec(x_27);
x_33 = x_106;
x_34 = x_102;
x_35 = x_103;
goto block_93;
}
else
{
uint8_t x_107; 
lean_dec(x_28);
lean_dec(x_27);
lean_dec(x_20);
lean_dec(x_9);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_107 = !lean_is_exclusive(x_32);
if (x_107 == 0)
{
return x_32;
}
else
{
lean_object* x_108; lean_object* x_109; lean_object* x_110; 
x_108 = lean_ctor_get(x_32, 0);
x_109 = lean_ctor_get(x_32, 1);
lean_inc(x_109);
lean_inc(x_108);
lean_dec(x_32);
x_110 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_110, 0, x_108);
lean_ctor_set(x_110, 1, x_109);
return x_110;
}
}
}
block_93:
{
lean_object* x_36; lean_object* x_37; lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; size_t x_45; size_t x_46; lean_object* x_47; 
x_36 = lean_ctor_get(x_34, 1);
lean_inc(x_36);
x_37 = lean_ctor_get(x_34, 0);
lean_inc(x_37);
lean_dec(x_34);
x_38 = lean_ctor_get(x_36, 0);
lean_inc(x_38);
x_39 = lean_ctor_get(x_36, 1);
lean_inc(x_39);
if (lean_is_exclusive(x_36)) {
 lean_ctor_release(x_36, 0);
 lean_ctor_release(x_36, 1);
 x_40 = x_36;
} else {
 lean_dec_ref(x_36);
 x_40 = lean_box(0);
}
x_41 = l_Array_zip___rarg(x_37, x_38);
x_42 = lean_array_get_size(x_41);
x_43 = lean_unsigned_to_nat(0u);
x_44 = l_Array_filterMapM___at_monomorphizeCore___spec__1(x_41, x_43, x_42);
lean_dec(x_42);
lean_dec(x_41);
x_45 = lean_array_size(x_44);
x_46 = 0;
lean_inc(x_44);
x_47 = l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__3(x_45, x_46, x_44, x_3, x_4, x_5, x_6, x_35);
if (lean_obj_tag(x_47) == 0)
{
lean_object* x_48; lean_object* x_49; lean_object* x_50; 
x_48 = lean_ctor_get(x_47, 0);
lean_inc(x_48);
x_49 = lean_ctor_get(x_47, 1);
lean_inc(x_49);
lean_dec(x_47);
lean_inc(x_6);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_3);
x_50 = l_getInstanceTypes(x_39, x_3, x_4, x_5, x_6, x_49);
if (lean_obj_tag(x_50) == 0)
{
lean_object* x_51; lean_object* x_52; lean_object* x_53; lean_object* x_54; lean_object* x_55; lean_object* x_56; lean_object* x_57; lean_object* x_58; lean_object* x_59; lean_object* x_60; lean_object* x_61; uint8_t x_82; 
x_51 = lean_ctor_get(x_50, 0);
lean_inc(x_51);
x_52 = lean_ctor_get(x_50, 1);
lean_inc(x_52);
lean_dec(x_50);
x_53 = lean_box(0);
x_54 = lean_array_to_list(x_48);
lean_inc(x_51);
x_55 = l_List_forIn_x27_loop___at_monomorphizeCore___spec__4(x_53, x_54, x_51, x_54, x_54, x_51, lean_box(0));
lean_dec(x_51);
lean_dec(x_54);
x_56 = lean_ctor_get(x_55, 1);
lean_inc(x_56);
lean_dec(x_55);
x_57 = lean_array_get_size(x_56);
x_58 = lean_box_usize(x_45);
x_59 = l_monomorphizeCore___lambda__2___boxed__const__1;
lean_inc(x_37);
lean_inc(x_9);
x_60 = lean_alloc_closure((void*)(l_monomorphizeCore___lambda__1___boxed), 13, 8);
lean_closure_set(x_60, 0, x_29);
lean_closure_set(x_60, 1, x_44);
lean_closure_set(x_60, 2, x_53);
lean_closure_set(x_60, 3, x_58);
lean_closure_set(x_60, 4, x_59);
lean_closure_set(x_60, 5, x_9);
lean_closure_set(x_60, 6, x_20);
lean_closure_set(x_60, 7, x_37);
x_82 = lean_nat_dec_lt(x_43, x_57);
if (x_82 == 0)
{
lean_dec(x_57);
lean_dec(x_56);
x_61 = x_18;
goto block_81;
}
else
{
size_t x_83; lean_object* x_84; 
x_83 = lean_usize_of_nat(x_57);
lean_dec(x_57);
x_84 = l_Array_foldrMUnsafe_fold___at_Lean_Elab_Tactic_BVDecide_Frontend_uninterpretedExplainer___spec__2(x_56, x_83, x_46, x_18);
lean_dec(x_56);
x_61 = x_84;
goto block_81;
}
block_81:
{
lean_object* x_62; 
lean_inc(x_6);
lean_inc(x_5);
lean_inc(x_4);
lean_inc(x_3);
x_62 = l_unify___rarg(x_61, x_33, x_60, x_3, x_4, x_5, x_6, x_52);
if (lean_obj_tag(x_62) == 0)
{
lean_object* x_63; lean_object* x_64; lean_object* x_65; 
x_63 = lean_ctor_get(x_62, 0);
lean_inc(x_63);
x_64 = lean_ctor_get(x_62, 1);
lean_inc(x_64);
lean_dec(x_62);
x_65 = l_List_foldlM___at_monomorphizeCore___spec__7(x_9, x_37, x_38, x_46, x_2, x_63, x_3, x_4, x_5, x_6, x_64);
lean_dec(x_38);
lean_dec(x_37);
if (lean_obj_tag(x_65) == 0)
{
uint8_t x_66; 
x_66 = !lean_is_exclusive(x_65);
if (x_66 == 0)
{
lean_object* x_67; lean_object* x_68; 
x_67 = lean_ctor_get(x_65, 0);
if (lean_is_scalar(x_40)) {
 x_68 = lean_alloc_ctor(1, 2, 0);
} else {
 x_68 = x_40;
 lean_ctor_set_tag(x_68, 1);
}
lean_ctor_set(x_68, 0, x_67);
lean_ctor_set(x_68, 1, x_18);
lean_ctor_set(x_65, 0, x_68);
return x_65;
}
else
{
lean_object* x_69; lean_object* x_70; lean_object* x_71; lean_object* x_72; 
x_69 = lean_ctor_get(x_65, 0);
x_70 = lean_ctor_get(x_65, 1);
lean_inc(x_70);
lean_inc(x_69);
lean_dec(x_65);
if (lean_is_scalar(x_40)) {
 x_71 = lean_alloc_ctor(1, 2, 0);
} else {
 x_71 = x_40;
 lean_ctor_set_tag(x_71, 1);
}
lean_ctor_set(x_71, 0, x_69);
lean_ctor_set(x_71, 1, x_18);
x_72 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_72, 0, x_71);
lean_ctor_set(x_72, 1, x_70);
return x_72;
}
}
else
{
uint8_t x_73; 
lean_dec(x_40);
x_73 = !lean_is_exclusive(x_65);
if (x_73 == 0)
{
return x_65;
}
else
{
lean_object* x_74; lean_object* x_75; lean_object* x_76; 
x_74 = lean_ctor_get(x_65, 0);
x_75 = lean_ctor_get(x_65, 1);
lean_inc(x_75);
lean_inc(x_74);
lean_dec(x_65);
x_76 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_76, 0, x_74);
lean_ctor_set(x_76, 1, x_75);
return x_76;
}
}
}
else
{
uint8_t x_77; 
lean_dec(x_40);
lean_dec(x_38);
lean_dec(x_37);
lean_dec(x_9);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_77 = !lean_is_exclusive(x_62);
if (x_77 == 0)
{
return x_62;
}
else
{
lean_object* x_78; lean_object* x_79; lean_object* x_80; 
x_78 = lean_ctor_get(x_62, 0);
x_79 = lean_ctor_get(x_62, 1);
lean_inc(x_79);
lean_inc(x_78);
lean_dec(x_62);
x_80 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_80, 0, x_78);
lean_ctor_set(x_80, 1, x_79);
return x_80;
}
}
}
}
else
{
uint8_t x_85; 
lean_dec(x_48);
lean_dec(x_44);
lean_dec(x_40);
lean_dec(x_38);
lean_dec(x_37);
lean_dec(x_33);
lean_dec(x_20);
lean_dec(x_9);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_85 = !lean_is_exclusive(x_50);
if (x_85 == 0)
{
return x_50;
}
else
{
lean_object* x_86; lean_object* x_87; lean_object* x_88; 
x_86 = lean_ctor_get(x_50, 0);
x_87 = lean_ctor_get(x_50, 1);
lean_inc(x_87);
lean_inc(x_86);
lean_dec(x_50);
x_88 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_88, 0, x_86);
lean_ctor_set(x_88, 1, x_87);
return x_88;
}
}
}
else
{
uint8_t x_89; 
lean_dec(x_44);
lean_dec(x_40);
lean_dec(x_39);
lean_dec(x_38);
lean_dec(x_37);
lean_dec(x_33);
lean_dec(x_20);
lean_dec(x_9);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_89 = !lean_is_exclusive(x_47);
if (x_89 == 0)
{
return x_47;
}
else
{
lean_object* x_90; lean_object* x_91; lean_object* x_92; 
x_90 = lean_ctor_get(x_47, 0);
x_91 = lean_ctor_get(x_47, 1);
lean_inc(x_91);
lean_inc(x_90);
lean_dec(x_47);
x_92 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_92, 0, x_90);
lean_ctor_set(x_92, 1, x_91);
return x_92;
}
}
}
}
else
{
uint8_t x_111; 
lean_dec(x_23);
lean_dec(x_20);
lean_dec(x_9);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_111 = !lean_is_exclusive(x_24);
if (x_111 == 0)
{
return x_24;
}
else
{
lean_object* x_112; lean_object* x_113; lean_object* x_114; 
x_112 = lean_ctor_get(x_24, 0);
x_113 = lean_ctor_get(x_24, 1);
lean_inc(x_113);
lean_inc(x_112);
lean_dec(x_24);
x_114 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_114, 0, x_112);
lean_ctor_set(x_114, 1, x_113);
return x_114;
}
}
}
else
{
uint8_t x_115; 
lean_dec(x_12);
lean_dec(x_9);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_115 = !lean_is_exclusive(x_14);
if (x_115 == 0)
{
return x_14;
}
else
{
lean_object* x_116; lean_object* x_117; lean_object* x_118; 
x_116 = lean_ctor_get(x_14, 0);
x_117 = lean_ctor_get(x_14, 1);
lean_inc(x_117);
lean_inc(x_116);
lean_dec(x_14);
x_118 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_118, 0, x_116);
lean_ctor_set(x_118, 1, x_117);
return x_118;
}
}
}
else
{
uint8_t x_119; 
lean_dec(x_9);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_119 = !lean_is_exclusive(x_11);
if (x_119 == 0)
{
return x_11;
}
else
{
lean_object* x_120; lean_object* x_121; lean_object* x_122; 
x_120 = lean_ctor_get(x_11, 0);
x_121 = lean_ctor_get(x_11, 1);
lean_inc(x_121);
lean_inc(x_120);
lean_dec(x_11);
x_122 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_122, 0, x_120);
lean_ctor_set(x_122, 1, x_121);
return x_122;
}
}
}
else
{
uint8_t x_123; 
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_123 = !lean_is_exclusive(x_8);
if (x_123 == 0)
{
return x_8;
}
else
{
lean_object* x_124; lean_object* x_125; lean_object* x_126; 
x_124 = lean_ctor_get(x_8, 0);
x_125 = lean_ctor_get(x_8, 1);
lean_inc(x_125);
lean_inc(x_124);
lean_dec(x_8);
x_126 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_126, 0, x_124);
lean_ctor_set(x_126, 1, x_125);
return x_126;
}
}
}
}
LEAN_EXPORT lean_object* l_monomorphizeCore(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
lean_object* x_8; lean_object* x_9; 
lean_inc(x_1);
x_8 = lean_alloc_closure((void*)(l_monomorphizeCore___lambda__2), 7, 2);
lean_closure_set(x_8, 0, x_2);
lean_closure_set(x_8, 1, x_1);
x_9 = l_Lean_MVarId_withContext___at___private_Lean_Meta_SynthInstance_0__Lean_Meta_synthPendingImp___spec__2___rarg(x_1, x_8, x_3, x_4, x_5, x_6, x_7);
return x_9;
}
}
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_monomorphizeCore___spec__2___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
size_t x_5; size_t x_6; lean_object* x_7; 
x_5 = lean_unbox_usize(x_2);
lean_dec(x_2);
x_6 = lean_unbox_usize(x_3);
lean_dec(x_3);
x_7 = l_Array_foldlMUnsafe_fold___at_monomorphizeCore___spec__2(x_1, x_5, x_6, x_4);
lean_dec(x_1);
return x_7;
}
}
LEAN_EXPORT lean_object* l_Array_filterMapM___at_monomorphizeCore___spec__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l_Array_filterMapM___at_monomorphizeCore___spec__1(x_1, x_2, x_3);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
return x_4;
}
}
LEAN_EXPORT lean_object* l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__3___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8) {
_start:
{
size_t x_9; size_t x_10; lean_object* x_11; 
x_9 = lean_unbox_usize(x_1);
lean_dec(x_1);
x_10 = lean_unbox_usize(x_2);
lean_dec(x_2);
x_11 = l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__3(x_9, x_10, x_3, x_4, x_5, x_6, x_7, x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
return x_11;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at_monomorphizeCore___spec__4___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
lean_object* x_8; 
x_8 = l_List_forIn_x27_loop___at_monomorphizeCore___spec__4(x_1, x_2, x_3, x_4, x_5, x_6, x_7);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
return x_8;
}
}
LEAN_EXPORT lean_object* l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11, lean_object* x_12) {
_start:
{
size_t x_13; size_t x_14; lean_object* x_15; 
x_13 = lean_unbox_usize(x_5);
lean_dec(x_5);
x_14 = lean_unbox_usize(x_6);
lean_dec(x_6);
x_15 = l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5(x_1, x_2, x_3, x_4, x_13, x_14, x_7, x_8, x_9, x_10, x_11, x_12);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
return x_15;
}
}
LEAN_EXPORT lean_object* l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__6___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
size_t x_6; size_t x_7; lean_object* x_8; 
x_6 = lean_unbox_usize(x_3);
lean_dec(x_3);
x_7 = lean_unbox_usize(x_4);
lean_dec(x_4);
x_8 = l_Array_mapMUnsafe_map___at_monomorphizeCore___spec__6(x_1, x_2, x_6, x_7, x_5);
lean_dec(x_2);
lean_dec(x_1);
return x_8;
}
}
LEAN_EXPORT lean_object* l_List_foldlM___at_monomorphizeCore___spec__7___lambda__1___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; lean_object* x_3; 
x_2 = l_List_foldlM___at_monomorphizeCore___spec__7___lambda__1(x_1);
lean_dec(x_1);
x_3 = lean_box(x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_List_foldlM___at_monomorphizeCore___spec__7___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11) {
_start:
{
size_t x_12; lean_object* x_13; 
x_12 = lean_unbox_usize(x_4);
lean_dec(x_4);
x_13 = l_List_foldlM___at_monomorphizeCore___spec__7(x_1, x_2, x_3, x_12, x_5, x_6, x_7, x_8, x_9, x_10, x_11);
lean_dec(x_3);
lean_dec(x_2);
return x_13;
}
}
LEAN_EXPORT lean_object* l_monomorphizeCore___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11, lean_object* x_12, lean_object* x_13) {
_start:
{
size_t x_14; size_t x_15; lean_object* x_16; 
x_14 = lean_unbox_usize(x_4);
lean_dec(x_4);
x_15 = lean_unbox_usize(x_5);
lean_dec(x_5);
x_16 = l_monomorphizeCore___lambda__1(x_1, x_2, x_3, x_14, x_15, x_6, x_7, x_8, x_9, x_10, x_11, x_12, x_13);
lean_dec(x_8);
lean_dec(x_3);
lean_dec(x_2);
return x_16;
}
}
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_monomorphizeMultiple___spec__1(lean_object* x_1, size_t x_2, size_t x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9) {
_start:
{
uint8_t x_10; 
x_10 = lean_usize_dec_eq(x_2, x_3);
if (x_10 == 0)
{
if (lean_obj_tag(x_4) == 0)
{
lean_object* x_11; size_t x_12; size_t x_13; 
x_11 = lean_box(0);
x_12 = 1;
x_13 = lean_usize_add(x_2, x_12);
x_2 = x_13;
x_4 = x_11;
goto _start;
}
else
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_15 = lean_ctor_get(x_4, 0);
lean_inc(x_15);
lean_dec(x_4);
x_16 = lean_array_uget(x_1, x_2);
lean_inc(x_8);
lean_inc(x_7);
lean_inc(x_6);
lean_inc(x_5);
x_17 = l_monomorphizeCore(x_15, x_16, x_5, x_6, x_7, x_8, x_9);
if (lean_obj_tag(x_17) == 0)
{
lean_object* x_18; lean_object* x_19; size_t x_20; size_t x_21; 
x_18 = lean_ctor_get(x_17, 0);
lean_inc(x_18);
x_19 = lean_ctor_get(x_17, 1);
lean_inc(x_19);
lean_dec(x_17);
x_20 = 1;
x_21 = lean_usize_add(x_2, x_20);
x_2 = x_21;
x_4 = x_18;
x_9 = x_19;
goto _start;
}
else
{
uint8_t x_23; 
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_23 = !lean_is_exclusive(x_17);
if (x_23 == 0)
{
return x_17;
}
else
{
lean_object* x_24; lean_object* x_25; lean_object* x_26; 
x_24 = lean_ctor_get(x_17, 0);
x_25 = lean_ctor_get(x_17, 1);
lean_inc(x_25);
lean_inc(x_24);
lean_dec(x_17);
x_26 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_26, 0, x_24);
lean_ctor_set(x_26, 1, x_25);
return x_26;
}
}
}
}
else
{
lean_object* x_27; 
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_27 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_27, 0, x_4);
lean_ctor_set(x_27, 1, x_9);
return x_27;
}
}
}
LEAN_EXPORT lean_object* l_monomorphizeMultiple(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; uint8_t x_12; 
x_8 = lean_box(0);
x_9 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_9, 0, x_1);
lean_ctor_set(x_9, 1, x_8);
x_10 = lean_array_get_size(x_2);
x_11 = lean_unsigned_to_nat(0u);
x_12 = lean_nat_dec_lt(x_11, x_10);
if (x_12 == 0)
{
lean_object* x_13; 
lean_dec(x_10);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
x_13 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_13, 0, x_9);
lean_ctor_set(x_13, 1, x_7);
return x_13;
}
else
{
uint8_t x_14; 
x_14 = lean_nat_dec_le(x_10, x_10);
if (x_14 == 0)
{
lean_object* x_15; 
lean_dec(x_10);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
x_15 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_15, 0, x_9);
lean_ctor_set(x_15, 1, x_7);
return x_15;
}
else
{
size_t x_16; size_t x_17; lean_object* x_18; 
x_16 = 0;
x_17 = lean_usize_of_nat(x_10);
lean_dec(x_10);
x_18 = l_Array_foldlMUnsafe_fold___at_monomorphizeMultiple___spec__1(x_2, x_16, x_17, x_9, x_3, x_4, x_5, x_6, x_7);
return x_18;
}
}
}
}
LEAN_EXPORT lean_object* l_Array_foldlMUnsafe_fold___at_monomorphizeMultiple___spec__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9) {
_start:
{
size_t x_10; size_t x_11; lean_object* x_12; 
x_10 = lean_unbox_usize(x_2);
lean_dec(x_2);
x_11 = lean_unbox_usize(x_3);
lean_dec(x_3);
x_12 = l_Array_foldlMUnsafe_fold___at_monomorphizeMultiple___spec__1(x_1, x_10, x_11, x_4, x_5, x_6, x_7, x_8, x_9);
lean_dec(x_1);
return x_12;
}
}
LEAN_EXPORT lean_object* l_monomorphizeMultiple___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7) {
_start:
{
lean_object* x_8; 
x_8 = l_monomorphizeMultiple(x_1, x_2, x_3, x_4, x_5, x_6, x_7);
lean_dec(x_2);
return x_8;
}
}
static lean_object* _init_l_monomorphize___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("monomorphize", 12, 12);
return x_1;
}
}
static lean_object* _init_l_monomorphize___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_monomorphize___closed__1;
x_3 = l_Lean_Name_str___override(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_monomorphize___closed__3() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("andthen", 7, 7);
return x_1;
}
}
static lean_object* _init_l_monomorphize___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_monomorphize___closed__3;
x_3 = l_Lean_Name_str___override(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_monomorphize___closed__5() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("monomorphize ", 13, 13);
return x_1;
}
}
static lean_object* _init_l_monomorphize___closed__6() {
_start:
{
lean_object* x_1; uint8_t x_2; lean_object* x_3; 
x_1 = l_monomorphize___closed__5;
x_2 = 0;
x_3 = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(x_3, 0, x_1);
lean_ctor_set_uint8(x_3, sizeof(void*)*1, x_2);
return x_3;
}
}
static lean_object* _init_l_monomorphize___closed__7() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("[", 1, 1);
return x_1;
}
}
static lean_object* _init_l_monomorphize___closed__8() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_monomorphize___closed__7;
x_2 = lean_alloc_ctor(5, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l_monomorphize___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = l_monomorphize___closed__4;
x_2 = l_monomorphize___closed__6;
x_3 = l_monomorphize___closed__8;
x_4 = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(x_4, 0, x_1);
lean_ctor_set(x_4, 1, x_2);
lean_ctor_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_monomorphize___closed__10() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("ident", 5, 5);
return x_1;
}
}
static lean_object* _init_l_monomorphize___closed__11() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_monomorphize___closed__10;
x_3 = l_Lean_Name_str___override(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_monomorphize___closed__12() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_monomorphize___closed__11;
x_2 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l_monomorphize___closed__13() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked(", ", 2, 2);
return x_1;
}
}
static lean_object* _init_l_monomorphize___closed__14() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_monomorphize___closed__13;
x_2 = lean_alloc_ctor(5, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l_monomorphize___closed__15() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked(",", 1, 1);
return x_1;
}
}
static lean_object* _init_l_monomorphize___closed__16() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; uint8_t x_4; lean_object* x_5; 
x_1 = l_monomorphize___closed__12;
x_2 = l_monomorphize___closed__15;
x_3 = l_monomorphize___closed__14;
x_4 = 0;
x_5 = lean_alloc_ctor(10, 3, 1);
lean_ctor_set(x_5, 0, x_1);
lean_ctor_set(x_5, 1, x_2);
lean_ctor_set(x_5, 2, x_3);
lean_ctor_set_uint8(x_5, sizeof(void*)*3, x_4);
return x_5;
}
}
static lean_object* _init_l_monomorphize___closed__17() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = l_monomorphize___closed__4;
x_2 = l_monomorphize___closed__9;
x_3 = l_monomorphize___closed__16;
x_4 = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(x_4, 0, x_1);
lean_ctor_set(x_4, 1, x_2);
lean_ctor_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_monomorphize___closed__18() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("]", 1, 1);
return x_1;
}
}
static lean_object* _init_l_monomorphize___closed__19() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_monomorphize___closed__18;
x_2 = lean_alloc_ctor(5, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l_monomorphize___closed__20() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = l_monomorphize___closed__4;
x_2 = l_monomorphize___closed__17;
x_3 = l_monomorphize___closed__19;
x_4 = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(x_4, 0, x_1);
lean_ctor_set(x_4, 1, x_2);
lean_ctor_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_monomorphize___closed__21() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = l_monomorphize___closed__2;
x_2 = lean_unsigned_to_nat(1024u);
x_3 = l_monomorphize___closed__20;
x_4 = lean_alloc_ctor(3, 3, 0);
lean_ctor_set(x_4, 0, x_1);
lean_ctor_set(x_4, 1, x_2);
lean_ctor_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_monomorphize() {
_start:
{
lean_object* x_1; 
x_1 = l_monomorphize___closed__21;
return x_1;
}
}
static lean_object* _init_l_monomorphizeSingle___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("monomorphizeSingle", 18, 18);
return x_1;
}
}
static lean_object* _init_l_monomorphizeSingle___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_monomorphizeSingle___closed__1;
x_3 = l_Lean_Name_str___override(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_monomorphizeSingle___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = l_monomorphize___closed__4;
x_2 = l_monomorphize___closed__6;
x_3 = l_monomorphize___closed__12;
x_4 = lean_alloc_ctor(2, 3, 0);
lean_ctor_set(x_4, 0, x_1);
lean_ctor_set(x_4, 1, x_2);
lean_ctor_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_monomorphizeSingle___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_1 = l_monomorphizeSingle___closed__2;
x_2 = lean_unsigned_to_nat(1022u);
x_3 = l_monomorphizeSingle___closed__3;
x_4 = lean_alloc_ctor(3, 3, 0);
lean_ctor_set(x_4, 0, x_1);
lean_ctor_set(x_4, 1, x_2);
lean_ctor_set(x_4, 2, x_3);
return x_4;
}
}
static lean_object* _init_l_monomorphizeSingle() {
_start:
{
lean_object* x_1; 
x_1 = l_monomorphizeSingle___closed__4;
return x_1;
}
}
LEAN_EXPORT lean_object* l_evalMonomorphize___lambda__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10) {
_start:
{
lean_object* x_11; 
x_11 = l_Lean_Elab_Tactic_getMainGoal(x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; lean_object* x_13; lean_object* x_14; 
x_12 = lean_ctor_get(x_11, 0);
lean_inc(x_12);
x_13 = lean_ctor_get(x_11, 1);
lean_inc(x_13);
lean_dec(x_11);
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_7);
lean_inc(x_6);
x_14 = l_monomorphizeMultiple(x_12, x_1, x_6, x_7, x_8, x_9, x_13);
if (lean_obj_tag(x_14) == 0)
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_15 = lean_ctor_get(x_14, 0);
lean_inc(x_15);
x_16 = lean_ctor_get(x_14, 1);
lean_inc(x_16);
lean_dec(x_14);
x_17 = l_Lean_Elab_Tactic_replaceMainGoal(x_15, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_16);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
if (lean_obj_tag(x_17) == 0)
{
uint8_t x_18; 
x_18 = !lean_is_exclusive(x_17);
if (x_18 == 0)
{
lean_object* x_19; lean_object* x_20; 
x_19 = lean_ctor_get(x_17, 0);
lean_dec(x_19);
x_20 = lean_box(0);
lean_ctor_set(x_17, 0, x_20);
return x_17;
}
else
{
lean_object* x_21; lean_object* x_22; lean_object* x_23; 
x_21 = lean_ctor_get(x_17, 1);
lean_inc(x_21);
lean_dec(x_17);
x_22 = lean_box(0);
x_23 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_23, 0, x_22);
lean_ctor_set(x_23, 1, x_21);
return x_23;
}
}
else
{
uint8_t x_24; 
x_24 = !lean_is_exclusive(x_17);
if (x_24 == 0)
{
return x_17;
}
else
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; 
x_25 = lean_ctor_get(x_17, 0);
x_26 = lean_ctor_get(x_17, 1);
lean_inc(x_26);
lean_inc(x_25);
lean_dec(x_17);
x_27 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_27, 0, x_25);
lean_ctor_set(x_27, 1, x_26);
return x_27;
}
}
}
else
{
uint8_t x_28; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
x_28 = !lean_is_exclusive(x_14);
if (x_28 == 0)
{
return x_14;
}
else
{
lean_object* x_29; lean_object* x_30; lean_object* x_31; 
x_29 = lean_ctor_get(x_14, 0);
x_30 = lean_ctor_get(x_14, 1);
lean_inc(x_30);
lean_inc(x_29);
lean_dec(x_14);
x_31 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_31, 0, x_29);
lean_ctor_set(x_31, 1, x_30);
return x_31;
}
}
}
else
{
uint8_t x_32; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
x_32 = !lean_is_exclusive(x_11);
if (x_32 == 0)
{
return x_11;
}
else
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; 
x_33 = lean_ctor_get(x_11, 0);
x_34 = lean_ctor_get(x_11, 1);
lean_inc(x_34);
lean_inc(x_33);
lean_dec(x_11);
x_35 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_35, 0, x_33);
lean_ctor_set(x_35, 1, x_34);
return x_35;
}
}
}
}
LEAN_EXPORT lean_object* l_evalMonomorphize(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10) {
_start:
{
lean_object* x_11; uint8_t x_12; 
x_11 = l_monomorphize___closed__2;
lean_inc(x_1);
x_12 = l_Lean_Syntax_isOfKind(x_1, x_11);
if (x_12 == 0)
{
lean_object* x_13; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_13 = l_Lean_Elab_throwUnsupportedSyntax___at_LeanSearchClient_leanSearchTacticImpl___spec__1___rarg(x_10);
return x_13;
}
else
{
lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; 
x_14 = lean_unsigned_to_nat(2u);
x_15 = l_Lean_Syntax_getArg(x_1, x_14);
lean_dec(x_1);
x_16 = l_Lean_Syntax_getArgs(x_15);
lean_dec(x_15);
x_17 = l_Lean_Syntax_TSepArray_getElems___rarg(x_16);
lean_dec(x_16);
x_18 = lean_alloc_closure((void*)(l_evalMonomorphize___lambda__1___boxed), 10, 1);
lean_closure_set(x_18, 0, x_17);
x_19 = l_Lean_Elab_Tactic_withMainContext___rarg(x_18, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10);
return x_19;
}
}
}
LEAN_EXPORT lean_object* l_evalMonomorphize___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10) {
_start:
{
lean_object* x_11; 
x_11 = l_evalMonomorphize___lambda__1(x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
return x_11;
}
}
LEAN_EXPORT lean_object* l_evalMonomorphizeSingle___lambda__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10) {
_start:
{
lean_object* x_11; 
x_11 = l_Lean_Elab_Tactic_getMainGoal(x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; lean_object* x_13; lean_object* x_14; 
x_12 = lean_ctor_get(x_11, 0);
lean_inc(x_12);
x_13 = lean_ctor_get(x_11, 1);
lean_inc(x_13);
lean_dec(x_11);
lean_inc(x_9);
lean_inc(x_8);
lean_inc(x_7);
lean_inc(x_6);
x_14 = l_monomorphizeCore(x_12, x_1, x_6, x_7, x_8, x_9, x_13);
if (lean_obj_tag(x_14) == 0)
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_15 = lean_ctor_get(x_14, 0);
lean_inc(x_15);
x_16 = lean_ctor_get(x_14, 1);
lean_inc(x_16);
lean_dec(x_14);
x_17 = l_Lean_Elab_Tactic_replaceMainGoal(x_15, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_16);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
if (lean_obj_tag(x_17) == 0)
{
uint8_t x_18; 
x_18 = !lean_is_exclusive(x_17);
if (x_18 == 0)
{
lean_object* x_19; lean_object* x_20; 
x_19 = lean_ctor_get(x_17, 0);
lean_dec(x_19);
x_20 = lean_box(0);
lean_ctor_set(x_17, 0, x_20);
return x_17;
}
else
{
lean_object* x_21; lean_object* x_22; lean_object* x_23; 
x_21 = lean_ctor_get(x_17, 1);
lean_inc(x_21);
lean_dec(x_17);
x_22 = lean_box(0);
x_23 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_23, 0, x_22);
lean_ctor_set(x_23, 1, x_21);
return x_23;
}
}
else
{
uint8_t x_24; 
x_24 = !lean_is_exclusive(x_17);
if (x_24 == 0)
{
return x_17;
}
else
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; 
x_25 = lean_ctor_get(x_17, 0);
x_26 = lean_ctor_get(x_17, 1);
lean_inc(x_26);
lean_inc(x_25);
lean_dec(x_17);
x_27 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_27, 0, x_25);
lean_ctor_set(x_27, 1, x_26);
return x_27;
}
}
}
else
{
uint8_t x_28; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
x_28 = !lean_is_exclusive(x_14);
if (x_28 == 0)
{
return x_14;
}
else
{
lean_object* x_29; lean_object* x_30; lean_object* x_31; 
x_29 = lean_ctor_get(x_14, 0);
x_30 = lean_ctor_get(x_14, 1);
lean_inc(x_30);
lean_inc(x_29);
lean_dec(x_14);
x_31 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_31, 0, x_29);
lean_ctor_set(x_31, 1, x_30);
return x_31;
}
}
}
else
{
uint8_t x_32; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_1);
x_32 = !lean_is_exclusive(x_11);
if (x_32 == 0)
{
return x_11;
}
else
{
lean_object* x_33; lean_object* x_34; lean_object* x_35; 
x_33 = lean_ctor_get(x_11, 0);
x_34 = lean_ctor_get(x_11, 1);
lean_inc(x_34);
lean_inc(x_33);
lean_dec(x_11);
x_35 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_35, 0, x_33);
lean_ctor_set(x_35, 1, x_34);
return x_35;
}
}
}
}
LEAN_EXPORT lean_object* l_evalMonomorphizeSingle(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10) {
_start:
{
lean_object* x_11; uint8_t x_12; 
x_11 = l_monomorphizeSingle___closed__2;
lean_inc(x_1);
x_12 = l_Lean_Syntax_isOfKind(x_1, x_11);
if (x_12 == 0)
{
lean_object* x_13; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_13 = l_Lean_Elab_throwUnsupportedSyntax___at_LeanSearchClient_leanSearchTacticImpl___spec__1___rarg(x_10);
return x_13;
}
else
{
lean_object* x_14; lean_object* x_15; lean_object* x_16; uint8_t x_17; 
x_14 = lean_unsigned_to_nat(1u);
x_15 = l_Lean_Syntax_getArg(x_1, x_14);
lean_dec(x_1);
x_16 = l_monomorphize___closed__11;
lean_inc(x_15);
x_17 = l_Lean_Syntax_isOfKind(x_15, x_16);
if (x_17 == 0)
{
lean_object* x_18; 
lean_dec(x_15);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
x_18 = l_Lean_Elab_throwUnsupportedSyntax___at_LeanSearchClient_leanSearchTacticImpl___spec__1___rarg(x_10);
return x_18;
}
else
{
lean_object* x_19; lean_object* x_20; 
x_19 = lean_alloc_closure((void*)(l_evalMonomorphizeSingle___lambda__1___boxed), 10, 1);
lean_closure_set(x_19, 0, x_15);
x_20 = l_Lean_Elab_Tactic_withMainContext___rarg(x_19, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10);
return x_20;
}
}
}
}
LEAN_EXPORT lean_object* l_evalMonomorphizeSingle___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10) {
_start:
{
lean_object* x_11; 
x_11 = l_evalMonomorphizeSingle___lambda__1(x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10);
lean_dec(x_5);
lean_dec(x_4);
lean_dec(x_3);
lean_dec(x_2);
return x_11;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_Lean(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Tactic_Ring(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_Real_Basic(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_ZMod_Basic(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_List_Basic(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_Monomorphization_Basic(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Tactic_Ring(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_Real_Basic(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_ZMod_Basic(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_List_Basic(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_getInstanceTypes___closed__1 = _init_l_getInstanceTypes___closed__1();
lean_mark_persistent(l_getInstanceTypes___closed__1);
l_getInstanceTypes___closed__2 = _init_l_getInstanceTypes___closed__2();
lean_mark_persistent(l_getInstanceTypes___closed__2);
l_getInstanceTypes___closed__3 = _init_l_getInstanceTypes___closed__3();
lean_mark_persistent(l_getInstanceTypes___closed__3);
l_unify___rarg___closed__1 = _init_l_unify___rarg___closed__1();
lean_mark_persistent(l_unify___rarg___closed__1);
l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___closed__1 = _init_l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___closed__1();
lean_mark_persistent(l_Array_forIn_x27Unsafe_loop___at_monomorphizeCore___spec__5___closed__1);
l_List_foldlM___at_monomorphizeCore___spec__7___closed__1 = _init_l_List_foldlM___at_monomorphizeCore___spec__7___closed__1();
lean_mark_persistent(l_List_foldlM___at_monomorphizeCore___spec__7___closed__1);
l_List_foldlM___at_monomorphizeCore___spec__7___closed__2 = _init_l_List_foldlM___at_monomorphizeCore___spec__7___closed__2();
lean_mark_persistent(l_List_foldlM___at_monomorphizeCore___spec__7___closed__2);
l_monomorphizeCore___lambda__2___boxed__const__1 = _init_l_monomorphizeCore___lambda__2___boxed__const__1();
lean_mark_persistent(l_monomorphizeCore___lambda__2___boxed__const__1);
l_monomorphize___closed__1 = _init_l_monomorphize___closed__1();
lean_mark_persistent(l_monomorphize___closed__1);
l_monomorphize___closed__2 = _init_l_monomorphize___closed__2();
lean_mark_persistent(l_monomorphize___closed__2);
l_monomorphize___closed__3 = _init_l_monomorphize___closed__3();
lean_mark_persistent(l_monomorphize___closed__3);
l_monomorphize___closed__4 = _init_l_monomorphize___closed__4();
lean_mark_persistent(l_monomorphize___closed__4);
l_monomorphize___closed__5 = _init_l_monomorphize___closed__5();
lean_mark_persistent(l_monomorphize___closed__5);
l_monomorphize___closed__6 = _init_l_monomorphize___closed__6();
lean_mark_persistent(l_monomorphize___closed__6);
l_monomorphize___closed__7 = _init_l_monomorphize___closed__7();
lean_mark_persistent(l_monomorphize___closed__7);
l_monomorphize___closed__8 = _init_l_monomorphize___closed__8();
lean_mark_persistent(l_monomorphize___closed__8);
l_monomorphize___closed__9 = _init_l_monomorphize___closed__9();
lean_mark_persistent(l_monomorphize___closed__9);
l_monomorphize___closed__10 = _init_l_monomorphize___closed__10();
lean_mark_persistent(l_monomorphize___closed__10);
l_monomorphize___closed__11 = _init_l_monomorphize___closed__11();
lean_mark_persistent(l_monomorphize___closed__11);
l_monomorphize___closed__12 = _init_l_monomorphize___closed__12();
lean_mark_persistent(l_monomorphize___closed__12);
l_monomorphize___closed__13 = _init_l_monomorphize___closed__13();
lean_mark_persistent(l_monomorphize___closed__13);
l_monomorphize___closed__14 = _init_l_monomorphize___closed__14();
lean_mark_persistent(l_monomorphize___closed__14);
l_monomorphize___closed__15 = _init_l_monomorphize___closed__15();
lean_mark_persistent(l_monomorphize___closed__15);
l_monomorphize___closed__16 = _init_l_monomorphize___closed__16();
lean_mark_persistent(l_monomorphize___closed__16);
l_monomorphize___closed__17 = _init_l_monomorphize___closed__17();
lean_mark_persistent(l_monomorphize___closed__17);
l_monomorphize___closed__18 = _init_l_monomorphize___closed__18();
lean_mark_persistent(l_monomorphize___closed__18);
l_monomorphize___closed__19 = _init_l_monomorphize___closed__19();
lean_mark_persistent(l_monomorphize___closed__19);
l_monomorphize___closed__20 = _init_l_monomorphize___closed__20();
lean_mark_persistent(l_monomorphize___closed__20);
l_monomorphize___closed__21 = _init_l_monomorphize___closed__21();
lean_mark_persistent(l_monomorphize___closed__21);
l_monomorphize = _init_l_monomorphize();
lean_mark_persistent(l_monomorphize);
l_monomorphizeSingle___closed__1 = _init_l_monomorphizeSingle___closed__1();
lean_mark_persistent(l_monomorphizeSingle___closed__1);
l_monomorphizeSingle___closed__2 = _init_l_monomorphizeSingle___closed__2();
lean_mark_persistent(l_monomorphizeSingle___closed__2);
l_monomorphizeSingle___closed__3 = _init_l_monomorphizeSingle___closed__3();
lean_mark_persistent(l_monomorphizeSingle___closed__3);
l_monomorphizeSingle___closed__4 = _init_l_monomorphizeSingle___closed__4();
lean_mark_persistent(l_monomorphizeSingle___closed__4);
l_monomorphizeSingle = _init_l_monomorphizeSingle();
lean_mark_persistent(l_monomorphizeSingle);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
