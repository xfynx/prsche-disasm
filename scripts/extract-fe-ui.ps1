param(
    [string]$GameDirectory,
    [string]$OutputDirectory
)

$ErrorActionPreference = 'Stop'
$WorkspaceRoot = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
if (-not $GameDirectory) { $GameDirectory = Join-Path $WorkspaceRoot 'local/game' }
if (-not $OutputDirectory) { $OutputDirectory = Join-Path $WorkspaceRoot 'local/derived/fe-ui' }

. (Join-Path $WorkspaceRoot 'scripts/tool-env.ps1')
Push-Location $WorkspaceRoot
try {
    $Manifest = 'iterations/012-campaign-fidelity/crates/nfs-assets/Cargo.toml'
    $TargetDirectory = 'local/builds/012-campaign-fidelity/.cargo-target'
    & cargo run --locked --manifest-path $Manifest --target-dir $TargetDirectory --example extract_fe_art -- $GameDirectory $OutputDirectory
    if ($LASTEXITCODE -ne 0) {
        throw "FE UI extraction failed with cargo exit code $LASTEXITCODE"
    }
}
finally {
    Pop-Location
}
