import subprocess
import os

tool_env = os.path.abspath('scripts/tool-env.ps1')

def run_cmd(powershell_code):
    cmd = ['powershell', '-ExecutionPolicy', 'Bypass', '-Command', f'. "{tool_env}"; {powershell_code}']
    res = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    out = res.stdout.decode('cp866', errors='replace') + res.stderr.decode('cp866', errors='replace')
    return res.returncode, out

run_dir = 'iterations/006-game-systems/runs/001-game-systems'
os.makedirs(run_dir, exist_ok=True)

print("Running fmt...")
code_fmt, out_fmt = run_cmd('cargo fmt --manifest-path iterations/006-game-systems/Cargo.toml --all -- --check')
with open(os.path.join(run_dir, 'fmt.log'), 'w', encoding='utf-8') as f:
    f.write(out_fmt)

print("Running clippy...")
code_clippy, out_clippy = run_cmd('cargo clippy --locked --manifest-path iterations/006-game-systems/Cargo.toml --target-dir local/builds/006-game-systems/.cargo-target --workspace --all-targets -- -D warnings')
with open(os.path.join(run_dir, 'clippy.log'), 'w', encoding='utf-8') as f:
    f.write(out_clippy)

print("Running test...")
code_test, out_test = run_cmd('cargo test --locked --manifest-path iterations/006-game-systems/Cargo.toml --target-dir local/builds/006-game-systems/.cargo-target --workspace')
with open(os.path.join(run_dir, 'test.log'), 'w', encoding='utf-8') as f:
    f.write(out_test)

print("Running build...")
code_build, out_build = run_cmd('.\\scripts\\build.ps1 -Iteration 006-game-systems -Config release -Target all')
with open(os.path.join(run_dir, 'build.log'), 'w', encoding='utf-8') as f:
    f.write(out_build)

print(f"fmt: {code_fmt}")
print(f"clippy: {code_clippy}")
print(f"test: {code_test}")
print(f"build: {code_build}")
