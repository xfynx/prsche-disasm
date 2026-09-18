# Dot-source this file: . ./scripts/tool-env.ps1
$PorscheProjectRoot = Split-Path $PSScriptRoot -Parent
$PorscheTools = Join-Path $PorscheProjectRoot 'local/tools'
$PorscheToolPaths = @((Join-Path $env:USERPROFILE '.cargo/bin'))
foreach ($pattern in @('cmake-*/bin', 'ninja', 'jdk-*/bin', 'wasm-bindgen-*-x86_64-pc-windows-msvc')) {
    $PorscheToolPaths += Get-Item (Join-Path $PorscheTools $pattern) -ErrorAction SilentlyContinue | ForEach-Object FullName
}
$env:PATH = ($PorscheToolPaths -join ';') + ';' + $env:PATH
$PorscheJdk = Get-ChildItem $PorscheTools -Directory -Filter 'jdk-*' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($PorscheJdk) { $env:JAVA_HOME = $PorscheJdk.FullName }
$PorscheGhidra = Get-ChildItem $PorscheTools -Directory -Filter 'ghidra_*_PUBLIC' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($PorscheGhidra) { $env:GHIDRA_INSTALL_DIR = $PorscheGhidra.FullName }
$PorscheVswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio/Installer/vswhere.exe'
if (Test-Path $PorscheVswhere) {
    $PorscheVsPath = & $PorscheVswhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    if ($PorscheVsPath) {
        Import-Module (Join-Path $PorscheVsPath 'Common7/Tools/Microsoft.VisualStudio.DevShell.dll') -ErrorAction Stop
        Enter-VsDevShell -VsInstallPath $PorscheVsPath -SkipAutomaticLocation -DevCmdArguments '-arch=x64 -host_arch=x64' | Out-Null
    }
}
