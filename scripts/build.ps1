[CmdletBinding()]
param(
    [ValidatePattern('^\d{3}-[A-Za-z0-9._-]+$')]
    [string]$Iteration = '001-car-viewer',

    [ValidateSet('debug', 'release')]
    [string]$Config = 'release',

    [ValidateSet('all', 'native', 'web')]
    [string]$Target = 'all',

    [string]$GameDir = 'local/game'
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$Root = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$IterationRoot = Join-Path $Root (Join-Path 'iterations' $Iteration)
$OutputRoot = Join-Path $Root (Join-Path 'local/builds' $Iteration)
$NativeOutput = Join-Path $OutputRoot 'windows'
$WebOutput = Join-Path $OutputRoot 'web'
$CargoTarget = Join-Path $OutputRoot '.cargo-target'
$Manifest = Join-Path $IterationRoot 'crates/porsche-viewer/Cargo.toml'
$GamePath = if ([IO.Path]::IsPathRooted($GameDir)) { $GameDir } else { Join-Path $Root $GameDir }
$ToolEnv = Join-Path $Root 'scripts/tool-env.ps1'

function Assert-InWorkspace([string]$Path, [string]$Label) {
    $full = [IO.Path]::GetFullPath($Path)
    $prefix = $Root.TrimEnd([IO.Path]::DirectorySeparatorChar, [IO.Path]::AltDirectorySeparatorChar) + [IO.Path]::DirectorySeparatorChar
    if (($full -ne $Root) -and (-not $full.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase))) {
        throw "$Label resolves outside the project workspace: $full"
    }
    return $full
}

if (-not (Test-Path -LiteralPath $IterationRoot -PathType Container)) { throw "Iteration not found: $IterationRoot" }
if (-not (Test-Path -LiteralPath $Manifest -PathType Leaf)) { throw "Viewer manifest not found: $Manifest" }
$null = Assert-InWorkspace $IterationRoot 'Iteration'
$null = Assert-InWorkspace $OutputRoot 'Output'
$null = Assert-InWorkspace $GamePath 'Game directory'

# Keep all generated artifacts in local/builds and never remove an existing output.
New-Item -ItemType Directory -Force -Path $NativeOutput, $WebOutput, $CargoTarget | Out-Null
if (Test-Path -LiteralPath $ToolEnv -PathType Leaf) { . $ToolEnv }

$profileArgs = if ($Config -eq 'release') { @('--release') } else { @() }
$profileDir = if ($Config -eq 'release') { 'release' } else { 'debug' }
$lockPath = Join-Path $IterationRoot 'Cargo.lock'
if (-not (Test-Path -LiteralPath $lockPath -PathType Leaf)) {
    throw "Cargo.lock is missing at the iteration workspace root: $lockPath. Generate it with 'cargo generate-lockfile --manifest-path `"$IterationRoot/Cargo.toml`"', review it, then rerun this build."
}

function Invoke-Cargo([string[]]$Arguments) {
    $args = @('build', '--manifest-path', $Manifest, '--target-dir', $CargoTarget) + $Arguments
    $args += '--locked'
    & cargo @args
    if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit code $LASTEXITCODE)" }
}

if ($Target -in @('all', 'native')) {
    Invoke-Cargo (@('--bin', 'porsche-viewer') + $profileArgs)
    $nativeBinary = Join-Path $CargoTarget (Join-Path $profileDir 'porsche-viewer.exe')
    if (-not (Test-Path -LiteralPath $nativeBinary -PathType Leaf)) { throw "Native executable was not produced: $nativeBinary" }
    Copy-Item -LiteralPath $nativeBinary -Destination (Join-Path $NativeOutput 'porsche-viewer.exe') -Force
}

if ($Target -in @('all', 'web')) {
    Invoke-Cargo (@('--target', 'wasm32-unknown-unknown', '--lib') + $profileArgs)
    $wasm = Join-Path $CargoTarget (Join-Path 'wasm32-unknown-unknown' (Join-Path $profileDir 'porsche_viewer.wasm'))
    if (-not (Test-Path -LiteralPath $wasm -PathType Leaf)) { throw "Wasm artifact was not produced: $wasm" }

    $staticWeb = Join-Path $IterationRoot 'web'
    if (Test-Path -LiteralPath $staticWeb -PathType Container) {
        Get-ChildItem -LiteralPath $staticWeb -Force | Copy-Item -Destination $WebOutput -Recurse -Force
    }
    $PackageOutput = Join-Path $WebOutput 'package'
    New-Item -ItemType Directory -Force -Path $PackageOutput | Out-Null
    $wasmBindgen = Get-Command wasm-bindgen -ErrorAction SilentlyContinue
    if (-not $wasmBindgen) { throw 'wasm-bindgen-cli 0.2.128 is required on PATH (install it with cargo install wasm-bindgen-cli --version 0.2.128 --locked)' }
    $version = (& $wasmBindgen.Source '--version').Trim()
    if ($LASTEXITCODE -ne 0 -or $version -notmatch 'wasm-bindgen ([0-9]+\.[0-9]+\.[0-9]+)' -or $Matches[1] -ne '0.2.128') { throw "Expected wasm-bindgen-cli 0.2.128, found: $version" }
    & $wasmBindgen.Source $wasm '--target' 'web' '--out-dir' $PackageOutput '--out-name' 'viewer_impl'
    if ($LASTEXITCODE -ne 0) { throw "wasm-bindgen failed (exit code $LASTEXITCODE)" }
}

Write-Host "Build complete: $OutputRoot (config=$Config, target=$Target, game-dir=$GameDir)"
