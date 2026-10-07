[CmdletBinding()]
param(
    [ValidateSet('Debug', 'Release')]
    [string]$Configuration = 'Release',
    [switch]$Clean
)

$ErrorActionPreference = 'Stop'
$ProjectRoot = Split-Path $PSScriptRoot -Parent
$IterationRoot = Join-Path $ProjectRoot 'iterations/v2/001-original-recovery'
$BuildRoot = Join-Path $ProjectRoot 'local/builds/v2/001-original-recovery'
$SourceProbe = Join-Path $IterationRoot 'source/recovered/recovery_probe.cpp'

if (-not (Test-Path -LiteralPath $IterationRoot -PathType Container)) {
    throw "Iteration CMake directory does not exist: $IterationRoot"
}
if (-not (Test-Path -LiteralPath $SourceProbe -PathType Leaf)) {
    throw "No recovered source exists: expected $SourceProbe"
}

$ToolEnv = Join-Path $ProjectRoot 'scripts/tool-env.ps1'
if (-not (Test-Path -LiteralPath $ToolEnv -PathType Leaf)) {
    throw "Required tool environment is missing: $ToolEnv"
}
. $ToolEnv

$CMake = Get-Command cmake -ErrorAction SilentlyContinue
if (-not $CMake) { throw 'cmake was not found after loading scripts/tool-env.ps1' }

$VsGenerator = $null
$VsWhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio/Installer/vswhere.exe'
if (Test-Path -LiteralPath $VsWhere) {
    $VsInstall = (& $VsWhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath | Select-Object -First 1)
    if ($LASTEXITCODE -eq 0 -and $VsInstall) {
        $VsGenerator = 'Visual Studio 17 2022'
    }
}
if (-not $VsGenerator) {
    throw 'Visual Studio Build Tools with the x86/x64 C++ workload were not found; refusing a non-MSVC or non-x86 build'
}

if ($Clean -and (Test-Path -LiteralPath $BuildRoot)) {
    $BuildRootFull = [IO.Path]::GetFullPath($BuildRoot)
    $BuildParentFull = [IO.Path]::GetFullPath((Join-Path $ProjectRoot 'local/builds/v2'))
    $BuildParentPrefix = $BuildParentFull.TrimEnd('\') + '\'
    if (-not $BuildRootFull.StartsWith($BuildParentPrefix, [StringComparison]::OrdinalIgnoreCase)) {
        throw "Refusing clean outside local/builds/v2: $BuildRootFull"
    }
    Remove-Item -LiteralPath $BuildRoot -Recurse -Force
}
New-Item -ItemType Directory -Force -Path $BuildRoot | Out-Null

$ConfigureArgs = @('-S', $IterationRoot, '-B', $BuildRoot, '-G', $VsGenerator, '-A', 'Win32', '-DCMAKE_CXX_STANDARD=17', '-DCMAKE_CXX_STANDARD_REQUIRED=ON')
& $CMake.Source @ConfigureArgs
if ($LASTEXITCODE -ne 0) { throw "CMake configure failed with exit code $LASTEXITCODE" }

& $CMake.Source '--build' $BuildRoot '--config' $Configuration '--target' 'recovery_probe' 'fe_stream_probe' 'heap_probe' 'files_probe' '--parallel'
if ($LASTEXITCODE -ne 0) { throw "CMake build failed with exit code $LASTEXITCODE" }

$Probe = Join-Path $BuildRoot "bin/$Configuration/recovery_probe.exe"
if (-not (Test-Path -LiteralPath $Probe -PathType Leaf)) {
    throw "Build reported success but probe executable is missing: $Probe"
}

$ToolchainMetadata = Join-Path $BuildRoot 'build-toolchain.json'
if (-not (Test-Path -LiteralPath $ToolchainMetadata -PathType Leaf)) {
    throw "CMake configure reported success but toolchain metadata is missing: $ToolchainMetadata"
}
$Toolchain = Get-Content -LiteralPath $ToolchainMetadata -Raw | ConvertFrom-Json
if ($Toolchain.compiler_id -ne 'MSVC' -or [int]$Toolchain.pointer_size -ne 4 -or $Toolchain.generator_platform -ne 'Win32') {
    throw "CMake toolchain is not proven x86 MSVC: compiler='$($Toolchain.compiler_id)', pointer_size='$($Toolchain.pointer_size)', platform='$($Toolchain.generator_platform)'"
}
$CompilerPath = [string]$Toolchain.compiler
$CompilerVersion = [string]$Toolchain.compiler_version
$GeneratorPlatform = [string]$Toolchain.generator_platform
if (-not $CompilerPath -or -not $CompilerVersion) {
    throw 'CMake toolchain metadata has empty compiler path or version'
}
$Metadata = [ordered]@{
    schema = 1
    target = 'recovery_probe'
    purpose = 'v2 recovered-source verification tool; not the game'
    architecture = 'x86/Win32'
    compiler = 'MSVC'
    compiler_path = [string]$CompilerPath
    compiler_version = [string]$CompilerVersion
    generator_platform = [string]$GeneratorPlatform
    generator = $VsGenerator
    configuration = $Configuration
    flags = @('/W4', '/EHsc', '/permissive-', 'C++17', '/machine:X86')
    source = 'iterations/v2/001-original-recovery/source/recovered/recovery_probe.cpp'
    output = $Probe.Substring($ProjectRoot.Length + 1)
}
$Metadata | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $BuildRoot 'build-metadata.json') -Encoding UTF8
Write-Output "Built x86 recovery probe: $Probe"
