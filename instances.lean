import Mathlib.Data.Real.Basic
import Mathlib.Data.ZMod.Basic
import Canonical
import Monomorphization.Basic

-- fails and hangs
-- example (x : ℝ) : x + 2 = 2 + x := by
--   monomorphize add_comm
--   canonical 1 +debug

-- succeeds only because it finds the axiom
-- example (R : Type*) [CommRing R] (x : R) : x + 2 = 2 + x := by
--   monomorphize add_comm
--   exact AddCommMonoid.add_comm x ↑Nat.zero.succ.succ

example (a b : Nat) : a + b = b + a := by
  monomorphize add_comm
  -- exact add_comm a b

-- fails
example (R : Type*) [CommRing R] (x : R) (m n : Nat) : x^(m + n) = x^m * x^n := by
  monomorphize pow_add
  have x := fun inst => @HAdd.hAdd Nat Nat Nat inst -- hAdd3
  -- hadd1, hadd2, hadd3
  -- canonical

#check Lean.FVarId

-- fails
example (n : Nat) (x : ZMod n) : x + 2 = 2 + x := by
  monomorphize add_comm
  -- canonical

-- fails
example (R : Type*) [CommRing R] (x y z : R) : x + y + z = x + z + y := by
  monomorphize add_right_comm
  -- canonical


-- With type class inference

-- fails
example (n : Nat) (x : ZMod n) : x + 2 = 2 + x := by
  monomorphize add_comm
  -- canonical

-- fails and hangs
example (n : Nat) (x : ZMod n) : x + 2 = 2 + x := by
  have := add_comm x 2
  -- canonical
  rw [this]
  sorry

-- succeeds
example (x y : ℝ) : x + y = y + x := by
  monomorphize add_comm
  -- canonical


-- succeeds
example (x y : ℝ) : x + y = y + x := by
  have := add_comm x y
  -- canonical
  sorry

-- succeeds
example (R : Type*) [CommRing R] (x : R) (m n : Nat) : x^(m + n) = x^m * x^n := by
  have := pow_add (M := R)
  -- canonical
  sorry

-- succeeds
example (R : Type*) [CommRing R] (x y z : R) : x + y + z = x + z + y := by
  have := add_right_comm (G := R)
  -- canonical
  sorry


example (a b : Nat) (c d : ℤ) : ↑(a + b) = c + d := by
  monomorphize HAdd.hAdd
  sorry


axiom contrived [Finite α] [HAdd α α α] : Unit

example (a b : Nat) : a + b = b + a := by
  monomorphize [contrived]
  sorry
