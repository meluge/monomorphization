import Lake
open Lake DSL

package Monomorphization

require mathlib from git "https://github.com/leanprover-community/mathlib4" @ "308445d7985027f538e281e18df29ca16ede2ba3"

require "chasenorman" / "Canonical"


require REPL from git
  "https://github.com/leanprover-community/repl" @ "v4.21.0"


lean_lib Monomorphization
