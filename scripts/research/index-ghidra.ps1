param([int]$TimeoutPerFile = 120, [switch]$ExportOnly, [string]$OnlyBinary = '')
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot '../tool-env.ps1')
$indexOutput = Join-Path $PorscheProjectRoot 'research/binary-index/ghidra'
$indexProject = Join-Path $PorscheProjectRoot 'local/experiments/binary-index-ghidra'
$indexScripts = Join-Path $PSScriptRoot 'ghidra'
New-Item -ItemType Directory -Force -Path $indexOutput,$indexProject | Out-Null
# A separate disposable analysis cache; the existing research project and locks stay intact.
$indexInputs = @(Get-ChildItem (Join-Path $PorscheProjectRoot 'local/game') -Recurse -File -Force |
    Where-Object { $_.Extension -in '.exe','.dll','.asi','.ocx' } |
    Where-Object { -not $OnlyBinary -or $_.Name -eq $OnlyBinary } |
    Where-Object {
        $bytes = [IO.File]::ReadAllBytes($_.FullName)
        if ($bytes.Length -lt 64) { return $false }
        $peOffset = [BitConverter]::ToInt32($bytes, 60)
        $peOffset -ge 0 -and $peOffset + 4 -le $bytes.Length -and
            [BitConverter]::ToUInt32($bytes, $peOffset) -eq 0x4550
    } | Sort-Object @{Expression={if ($_.Name -eq 'Porsche.exe') {0} elseif ($_.Name -eq 'gimme.dll') {1} else {2}}},FullName |
    Select-Object -ExpandProperty FullName)
if ($indexInputs.Count -eq 0) { throw 'No PE inputs found' }
$indexArgs = if ($ExportOnly) { @($indexProject,'binary-index','-process','*','-noanalysis') }
    else { @($indexProject,'binary-index','-import') + $indexInputs + @('-overwrite') }
$indexArgs += @('-analysisTimeoutPerFile',"$TimeoutPerFile",'-max-cpu','2',
    '-scriptPath',$indexScripts,'-postScript','ExportBinaryIndex.java',$indexOutput,
    '-log',(Join-Path $indexProject 'analysis.log'))
& (Join-Path $env:GHIDRA_INSTALL_DIR 'support/analyzeHeadless.bat') @indexArgs
if ($LASTEXITCODE -ne 0) { throw "Ghidra index failed (exit $LASTEXITCODE); inspect $indexOutput" }
$indexMetadata = @(Get-ChildItem $indexOutput -Recurse -Filter metadata.json | ForEach-Object {
    Get-Content -LiteralPath $_.FullName -Raw | ConvertFrom-Json
})
$indexHashes = @($indexInputs | ForEach-Object { (Get-FileHash -LiteralPath $_ -Algorithm SHA256).Hash.ToLowerInvariant() } | Select-Object -Unique)
$indexMissing = @($indexHashes | Where-Object { $_ -notin $indexMetadata.sha256 })
$indexMetadata | ConvertTo-Json -Depth 8 | Set-Content (Join-Path $indexOutput 'summary.json') -Encoding utf8
if ($indexMissing.Count) { throw "Incomplete exports: missing $($indexMissing.Count) unique binaries; inspect analysis.log" }
Write-Output "Indexed $($indexMetadata.Count) PE files; per-file timeout and unresolved calls remain explicit in metadata."
