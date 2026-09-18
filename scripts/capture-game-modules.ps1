param([int]$ObservationSeconds = 12)
$ErrorActionPreference = 'Stop'
$ProjectRoot = Split-Path $PSScriptRoot -Parent
$Baseline = Join-Path $ProjectRoot 'local/game'
$WorkingCopy = Join-Path $ProjectRoot 'local/experiments/runtime'
if (-not (Test-Path -LiteralPath $WorkingCopy)) {
    New-Item -ItemType Directory -Path (Split-Path $WorkingCopy -Parent) -Force | Out-Null
    Copy-Item -LiteralPath $Baseline -Destination $WorkingCopy -Recurse
}
$Executable = Join-Path $WorkingCopy 'nfs5.exe'
$GameProcess = Start-Process -FilePath $Executable -WorkingDirectory $WorkingCopy -PassThru -WindowStyle Hidden
Start-Sleep -Seconds $ObservationSeconds
$GameProcess.Refresh()
$Report = [ordered]@{
    executable = $Executable
    pid = $GameProcess.Id
    observed_at = (Get-Date).ToUniversalTime().ToString('o')
    observation_seconds = $ObservationSeconds
    exited = $GameProcess.HasExited
}
if ($GameProcess.HasExited) {
    $Report.exit_code = $GameProcess.ExitCode
    $Report.modules = @()
} else {
    $Report.modules = @($GameProcess.Modules | ForEach-Object {
        [ordered]@{ name=$_.ModuleName; path=$_.FileName; base_address=('0x{0:X}' -f $_.BaseAddress.ToInt64()); size=$_.ModuleMemorySize }
    })
}
$OutputFile = Join-Path $ProjectRoot 'docs/runtime-modules.json'
$Report | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath $OutputFile -Encoding UTF8
Write-Output "Recorded $($Report.modules.Count) modules; process $($GameProcess.Id); exited=$($GameProcess.HasExited)"
Write-Output 'If still running, close this experimental game normally after visual verification.'
