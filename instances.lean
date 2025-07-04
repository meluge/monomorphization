import Mathlib.Data.Real.Basic
import Mathlib.Data.ZMod.Basic
import Canonical
import Monomorphization.Basic

example (x : ℝ) : x + 2 = 2 + x := by
  monomorphize [add_comm]

example (R : Type*) [CommRing R] (x : R) : x + 2 = 2 + x := by
  monomorphize [add_comm]

example (a b : Nat) : a + b = b + a := by
  monomorphize [add_comm]

-- fails
example (R : Type*) [CommRing R] (x : R) (m n : Nat) : x^(m + n) = x^m * x^n := by
  monomorphize [pow_add]

-- fails
example (n : Nat) (x : ZMod n) : x + 2 = 2 + x := by
  monomorphize [add_comm]

-- fails
example (R : Type*) [CommRing R] (x y z : R) : x + y + z = x + z + y := by
  monomorphize [add_right_comm]
