import json
import subprocess
import os
import sys
from typing import List, Any

# Try to find the lake executable
lake_path = subprocess.run(["which", "lake"], capture_output=True, text=True).stdout.strip()
if not lake_path:
    # Alternative paths where lake might be installed
    potential_paths = [
        os.path.expanduser("~/.elan/bin/lake"),
        "/usr/local/bin/lake",
        "/opt/homebrew/bin/lake"
    ]
    for path in potential_paths:
        if os.path.exists(path):
            lake_path = path
            break
    
    if not lake_path:
        raise FileNotFoundError("Lake executable not found. Please install Lean/Lake or add it to PATH.")

process = subprocess.Popen(
    [lake_path, "exe", "repl", "--load-dynlib=.lake/packages/Canonical/.lake/build/lib/libcanonical_lean.dylib"],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True,
    bufsize=1,
    env=os.environ,
)

def send_command(command):
    json_command = json.dumps(command, ensure_ascii=False) + "\n\n"
    process.stdin.write(json_command)
    process.stdin.flush()
    response_lines = []
    while True:
        stdout_line = process.stdout.readline()
        if stdout_line.strip() == "":
            break
        response_lines.append(stdout_line)
    return json.loads("".join(response_lines))

lol = send_command({ "cmd" : "import Mathlib\nimport Canonical\ntheorem womp : (2:Nat) + 2 = 4 := by canonical" })

print(lol)
env_import = lol["env"]
print(env_import)