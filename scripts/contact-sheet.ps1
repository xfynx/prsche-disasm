[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$InputDir,
    [Parameter(Mandatory)][string]$OutputDir
)

# A labelled overview for reviewing GPU captures; the original PNGs stay intact.
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Drawing
$captureFiles = @(Get-ChildItem -LiteralPath $InputDir -Filter '*.png' -File | Sort-Object Name)
if (-not $captureFiles.Count) { throw 'No PNG captures found.' }
New-Item -ItemType Directory -Path $OutputDir -Force | Out-Null
$font = New-Object System.Drawing.Font('Consolas', 13)
try {
    for ($start = 0; $start -lt $captureFiles.Count; $start += 9) {
        $sheet = New-Object System.Drawing.Bitmap(1440, 972)
        $graphics = [System.Drawing.Graphics]::FromImage($sheet)
        try {
            $graphics.Clear([System.Drawing.Color]::FromArgb(40, 47, 57))
            $graphics.InterpolationMode = [System.Drawing.Drawing2D.InterpolationMode]::HighQualityBicubic
            for ($slot = 0; $slot -lt 9 -and ($start + $slot) -lt $captureFiles.Count; $slot++) {
                $file = $captureFiles[$start + $slot]
                $x = ($slot % 3) * 480
                $y = [Math]::Floor($slot / 3) * 324
                $frame = [System.Drawing.Image]::FromFile($file.FullName)
                try {
                    $scale = [Math]::Min(480.0 / $frame.Width, 300.0 / $frame.Height)
                    $w = [int]($frame.Width * $scale)
                    $h = [int]($frame.Height * $scale)
                    $graphics.DrawImage($frame, [int]($x + (480 - $w) / 2), [int]($y + 24), $w, $h)
                } finally { $frame.Dispose() }
                $graphics.DrawString($file.BaseName, $font, [System.Drawing.Brushes]::White, [single]($x + 10), [single]$y)
            }
            $path = Join-Path $OutputDir ('sheet-{0:D2}.png' -f ([int]($start / 9) + 1))
            $sheet.Save($path, [System.Drawing.Imaging.ImageFormat]::Png)
            Write-Output $path
        } finally { $graphics.Dispose(); $sheet.Dispose() }
    }
} finally { $font.Dispose() }
