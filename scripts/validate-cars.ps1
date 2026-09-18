[CmdletBinding()]
param(
    [string]$GameDir = 'local/game',
    [string]$Viewer,
    [string]$Report = 'local/builds/001-car-viewer/validation/cars.tsv',
    [string]$CaptureDir = 'local/builds/001-car-viewer/validation/captures',
    [switch]$Capture,
    [ValidateSet('debug', 'release')]
    [string]$Config = 'release',
    [ValidateRange(1, 8192)]
    [int]$Width = 1280,
    [ValidateRange(1, 8192)]
    [int]$Height = 720,
    [double]$Yaw,
    [double]$Pitch,
    [switch]$Force
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$Root = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$GamePath = if ([IO.Path]::IsPathRooted($GameDir)) { $GameDir } else { Join-Path $Root $GameDir }
$ReportPath = if ([IO.Path]::IsPathRooted($Report)) { $Report } else { Join-Path $Root $Report }
$CapturePath = if ([IO.Path]::IsPathRooted($CaptureDir)) { $CaptureDir } else { Join-Path $Root $CaptureDir }
$CarModelPath = Join-Path $GamePath 'GameData/CarModel'
$CargoTarget = Join-Path $Root 'local/builds/001-car-viewer/.cargo-target'

function Resolve-WorkspacePath([string]$Path, [string]$Label) {
    $full = [IO.Path]::GetFullPath($Path)
    $prefix = $Root.TrimEnd([IO.Path]::DirectorySeparatorChar, [IO.Path]::AltDirectorySeparatorChar) + [IO.Path]::DirectorySeparatorChar
    if (($full -ne $Root) -and (-not $full.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase))) {
        throw "$Label resolves outside the project workspace: $full"
    }
    return $full
}

$GamePath = Resolve-WorkspacePath $GamePath 'Game directory'
$ReportPath = Resolve-WorkspacePath $ReportPath 'Report'
$CapturePath = Resolve-WorkspacePath $CapturePath 'Capture directory'

if (-not (Test-Path -LiteralPath $CarModelPath -PathType Container)) { throw "CarModel directory not found: $CarModelPath" }
if (Test-Path -LiteralPath $ReportPath -PathType Leaf) {
    if (-not $Force) { throw "Report already exists: $ReportPath. Use -Force to replace it." }
}

if (-not $Viewer) {
    $profile = Join-Path $CargoTarget $Config
    $candidates = @(
        (Join-Path $profile 'porsche-viewer.exe'),
        (Join-Path $Root 'local/builds/001-car-viewer/windows/porsche-viewer.exe')
    )
    $Viewer = $candidates | Where-Object { Test-Path -LiteralPath $_ -PathType Leaf } | Select-Object -First 1
}
if (-not $Viewer) { throw "Viewer executable not found. Build with scripts/build.ps1 or pass -Viewer." }
$Viewer = (Resolve-Path -LiteralPath $Viewer).Path

$pairs = Get-ChildItem -LiteralPath $CarModelPath -File |
    Where-Object { $_.Extension -ieq '.crp' } |
    ForEach-Object {
        $tpg = Join-Path $_.DirectoryName ($_.BaseName + '.tpg')
        if (Test-Path -LiteralPath $tpg -PathType Leaf) {
            [PSCustomObject]@{ Car = $_.BaseName; Crp = $_.FullName; Tpg = $tpg }
        }
    } | Sort-Object Car

if (-not $pairs) { throw "No .crp/.tpg pairs found in $CarModelPath" }

$reportParent = Split-Path $ReportPath -Parent
New-Item -ItemType Directory -Force -Path $reportParent | Out-Null
if ($Capture) { New-Item -ItemType Directory -Force -Path $CapturePath | Out-Null }

function Invoke-Viewer([string[]]$Arguments) {
    $previousErrorAction = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try {
        $output = (& $Viewer @Arguments 2>&1 |
            ForEach-Object {
                if ($_ -is [System.Management.Automation.ErrorRecord]) { $_.ToString() }
                else { [string]$_ }
            } | Out-String)
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousErrorAction
    }
    [PSCustomObject]@{ Output = $output; ExitCode = $exitCode }
}

$rows = [System.Collections.Generic.List[object]]::new()
foreach ($pair in $pairs) {
    $summary = ''
    $errorText = ''
    $status = 'ok'
    $screenshot = ''
    $inspect = Invoke-Viewer @('inspect', '--game-dir', $GamePath, '--car', $pair.Car)
    $inspectOutput = $inspect.Output
    $inspectExit = $inspect.ExitCode
    $summary = (($inspectOutput -split '\r?\n' | Select-Object -First 1) -replace '\s+', ' ').Trim()
    if ($inspectExit -ne 0) {
        $status = 'inspect-failed'
        $errorText = ($inspectOutput -replace '\s+', ' ').Trim()
    } elseif ($Capture) {
        $screenshot = Join-Path $CapturePath ($pair.Car + '.png')
        if ((Test-Path -LiteralPath $screenshot -PathType Leaf) -and (-not $Force)) {
            $status = 'capture-exists'
            $errorText = 'screenshot exists; use -Force to overwrite'
            $view = $null
        } else {
            $viewArguments = [System.Collections.Generic.List[string]]::new()
            $viewArguments.AddRange([string[]]@('view', '--game-dir', $GamePath, '--car', $pair.Car, '--screenshot', $screenshot, '--width', $Width, '--height', $Height))
            if ($PSBoundParameters.ContainsKey('Yaw')) { $viewArguments.AddRange([string[]]@('--yaw', $Yaw.ToString([Globalization.CultureInfo]::InvariantCulture))) }
            if ($PSBoundParameters.ContainsKey('Pitch')) { $viewArguments.AddRange([string[]]@('--pitch', $Pitch.ToString([Globalization.CultureInfo]::InvariantCulture))) }
            $view = Invoke-Viewer $viewArguments.ToArray()
        }
        if ($null -ne $view) {
            $viewOutput = $view.Output
            $viewExit = $view.ExitCode
            if ($viewExit -ne 0) {
                $status = 'capture-failed'
                $errorText = (($viewOutput -replace '\s+', ' ').Trim())
            } elseif (-not (Test-Path -LiteralPath $screenshot -PathType Leaf)) {
                $status = 'capture-failed'
                $errorText = 'viewer exited successfully but did not create the screenshot'
            }
        }
    }
    $rows.Add([PSCustomObject]@{
        car = $pair.Car
        status = $status
        inspect_exit = $inspectExit
        screenshot = if ($screenshot) { $screenshot } else { '' }
        summary = $summary
        error = $errorText
    })
    Write-Host ("{0,-20} {1}" -f $pair.Car, $status)
}

$rows | ConvertTo-Csv -Delimiter "`t" -NoTypeInformation | Set-Content -LiteralPath $ReportPath -Encoding utf8
$failed = @($rows | Where-Object status -ne 'ok').Count
Write-Host "Validated $($rows.Count) car pairs; failed $failed; report: $ReportPath"
if ($Capture) { Write-Host "Screenshots: $CapturePath" }
if ($failed -ne 0) { exit 1 }
