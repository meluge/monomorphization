import Mathlib.Data.Real.Basic
import Mathlib.Data.ZMod.Basic
import Canonical
import Typeclass.Basic

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
  canonical

-- fails
example (R : Type*) [CommRing R] (x : R) (m n : Nat) : x^(m + n) = x^m * x^n := by
  monomorphize pow_add
  -- canonical

-- fails
example (n : Nat) (x : ZMod n) : x + 2 = 2 + x := by
  -- canonical [add_comm]
  rw [add_comm]

-- fails
example (R : Type*) [CommRing R] (x y z : R) : x + y + z = x + z + y := by
  -- canonical [add_right_comm]
  rw [add_right_comm]


-- With type class inference

-- fails
example (n : Nat) (x : ZMod n) : x + 2 = 2 + x := by
  have := add_comm (G := ZMod n)
  -- canonical
  rw [this]
  sorry

-- fails and hangs
example (n : Nat) (x : ZMod n) : x + 2 = 2 + x := by
  have := add_comm x 2
  -- canonical
  rw [this]
  sorry

-- succeeds
example (x y : ℝ) : x + y = y + x := by
  have := add_comm (G := ℝ)
  -- canonical
  sorry

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
