$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot 'tool-env.ps1')
$ProjectDir = Join-Path $PorscheProjectRoot 'local/ghidra'
$ReportsDir = Join-Path $PorscheProjectRoot 'local/reports'
New-Item -ItemType Directory -Force -Path $ProjectDir,$ReportsDir | Out-Null
$Analyzer = Join-Path $env:GHIDRA_INSTALL_DIR 'support/analyzeHeadless.bat'
foreach ($Module in @('Porsche.exe','nfs5.exe','gimme.dll')) {
    & $Analyzer $ProjectDir 'porsche' -import (Join-Path $PorscheProjectRoot "local/game/$Module") -overwrite -analysisTimeoutPerFile 180 -max-cpu 2 -log (Join-Path $ReportsDir "ghidra-$Module.log")
    if ($LASTEXITCODE -ne 0) { throw "Ghidra import failed: $Module (exit $LASTEXITCODE)" }
}
