param(
    [ValidateSet('listing','decompile')][string]$Mode='listing',
    [int]$FunctionTimeout=30,
    [string]$OnlyBinary='',
    [switch]$ImportNE,
    [switch]$NE
)
$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot '../tool-env.ps1')
$v2Output=Join-Path $PorscheProjectRoot 'research/v2/binaries'
$v2Scripts=Join-Path $PSScriptRoot 'ghidra'
$v2Cache=Join-Path $PorscheProjectRoot 'local/experiments/binary-index-ghidra'
$v2Project='binary-index'
if($ImportNE -or $NE) {
    $v2Cache=Join-Path $PorscheProjectRoot 'local/experiments/v2-ne-ghidra'
    $v2Project='v2-ne'
    New-Item -ItemType Directory -Force -Path $v2Cache | Out-Null
    if($ImportNE) {
        $v2Args=@($v2Cache,$v2Project,'-import',(Join-Path $PorscheProjectRoot 'local/game/clcd16.dll'))
    } else {
        $v2Args=@($v2Cache,$v2Project,'-process','clcd16.dll','-noanalysis','-readOnly')
    }
} else {
    if(-not (Test-Path -LiteralPath (Join-Path $v2Cache "$v2Project.gpr"))) { throw 'Existing index project missing; run index-ghidra.ps1 first' }
    $v2Args=@($v2Cache,$v2Project,'-process',$(if($OnlyBinary){$OnlyBinary}else{'*'}),'-noanalysis','-readOnly')
}
New-Item -ItemType Directory -Force -Path $v2Output | Out-Null
$v2Args+=@('-max-cpu','2','-scriptPath',$v2Scripts,'-postScript','ExportRecoveryCorpus.java',$v2Output,$Mode,"$FunctionTimeout",'-log',(Join-Path $PorscheProjectRoot "local/reports/v2-$Mode-ghidra.log"))
& (Join-Path $env:GHIDRA_INSTALL_DIR 'support/analyzeHeadless.bat') @v2Args
if($LASTEXITCODE -ne 0) { throw "V2 $Mode export failed; inspect local/reports/v2-$Mode-ghidra.log" }
# Ghidra can return zero after a failed post-script; the coverage command is
# deliberately separate and required to check all expected hashes/results.
Write-Output "Headless command finished. Verify corpus with inventory-v2.py; zero exit alone does not prove complete export."
