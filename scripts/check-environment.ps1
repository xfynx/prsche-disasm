param([switch]$Smoke)
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot 'tool-env.ps1')
foreach ($command in @('git', 'py', 'rustc', 'cargo', 'rustfmt', 'cmake', 'ninja', 'java', 'cl', 'wasm-bindgen')) {
    $found = Get-Command $command -ErrorAction SilentlyContinue
    if (!$found) { throw "Required tool missing: $command" }
    Write-Output "$command => $($found.Source)"
}
git --version
py -3.12 --version
rustc --version
cargo --version
rustfmt --version
cargo clippy --version
rustup target list --installed
cmake --version
ninja --version
java -version
wasm-bindgen --version
if (!(Test-Path "$env:GHIDRA_INSTALL_DIR/support/analyzeHeadless.bat")) { throw 'Ghidra not found' }
foreach ($arch in @('x32', 'x64')) {
    if (!(Test-Path "$PorscheTools/x64dbg/release/$arch/${arch}dbg.exe")) { throw "$arch debugger not found" }
}
if ($Smoke) {
    $smokeDir = Join-Path $PorscheProjectRoot 'local/smoke'
    New-Item -ItemType Directory -Force $smokeDir | Out-Null
    $source = Join-Path $smokeDir 'hello.rs'
    'fn main() { println!("porsche rust smoke ok"); }' | Set-Content $source -Encoding ASCII
    & rustc $source -o (Join-Path $smokeDir 'hello.exe')
    if ($LASTEXITCODE -ne 0) { throw 'Rust MSVC compile failed' }
    & (Join-Path $smokeDir 'hello.exe')
    if ($LASTEXITCODE -ne 0) { throw 'Rust smoke execution failed' }
}
