[CmdletBinding()]
param(
    [ValidateSet('desktop', 'web', 'native')]
    [string]$Mode = 'desktop',

    [ValidatePattern('^\d{3}-[A-Za-z0-9._-]+$')]
    [string]$Iteration = '009-game-shell',

    [string]$GameDir = 'local/game'
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$Root = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$BuildRoot = Join-Path $Root (Join-Path 'local/builds' $Iteration)
$NativeBinary = Join-Path $BuildRoot 'windows/porsche-viewer.exe'
$WebRoot = Join-Path $BuildRoot 'web'
$ServeScript = Join-Path $Root 'scripts/serve-web.py'
$GamePath = if ([IO.Path]::IsPathRooted($GameDir)) { $GameDir } else { Join-Path $Root $GameDir }
$LaunchId = (Get-Date -Format 'yyyyMMdd-HHmmss') + '-' + ([guid]::NewGuid().ToString('N').Substring(0, 8))
$LogRoot = Join-Path (Join-Path $BuildRoot 'launcher') $LaunchId
$ReadyFile = Join-Path $LogRoot 'ready.json'
$Server = $null
$Browser = $null

function Assert-InWorkspace([string]$Path, [string]$Label) {
    $full = [IO.Path]::GetFullPath($Path)
    $prefix = $Root.TrimEnd([IO.Path]::DirectorySeparatorChar, [IO.Path]::AltDirectorySeparatorChar) + [IO.Path]::DirectorySeparatorChar
    if (($full -ne $Root) -and (-not $full.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase))) {
        throw "$Label resolves outside the project workspace: $full"
    }
    return $full
}

function Quote-WindowsArg([string]$Value) {
    # CommandLineToArgvW / CRT: double backslashes before a quote or final quote.
    $quoted = [regex]::Replace($Value, '(\\*)"', '$1$1\"')
    $quoted = [regex]::Replace($quoted, '(\\+)$', '$1$1')
    return '"' + $quoted + '"'
}

function Find-Browser {
    $candidates = @(
        (Join-Path $env:ProgramFiles 'Microsoft\Edge\Application\msedge.exe'),
        (Join-Path ${env:ProgramFiles(x86)} 'Microsoft\Edge\Application\msedge.exe'),
        (Join-Path $env:LOCALAPPDATA 'Microsoft\Edge\Application\msedge.exe'),
        (Join-Path $env:ProgramFiles 'Google\Chrome\Application\chrome.exe'),
        (Join-Path ${env:ProgramFiles(x86)} 'Google\Chrome\Application\chrome.exe'),
        (Join-Path $env:LOCALAPPDATA 'Google\Chrome\Application\chrome.exe'),
        (Join-Path $env:ProgramFiles 'Chromium\Application\chrome.exe'),
        (Join-Path ${env:ProgramFiles(x86)} 'Chromium\Application\chrome.exe')
    )
    foreach ($candidate in $candidates) {
        if ($candidate -and (Test-Path -LiteralPath $candidate -PathType Leaf)) { return $candidate }
    }
    $pathBrowser = Get-Command msedge, chrome, chromium -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($pathBrowser) { return $pathBrowser.Source }
    return $null
}

try {
    $null = Assert-InWorkspace $BuildRoot 'Build output'
    $null = Assert-InWorkspace $GamePath 'Game directory'
    if ($Mode -eq 'native') {
        if (-not (Test-Path -LiteralPath $NativeBinary -PathType Leaf)) {
            throw "Native executable not found: $NativeBinary (build the selected iteration first)"
        }
        Write-Host "Starting native viewer: $NativeBinary"
        $nativeArgs = 'catalog --game-dir ' + (Quote-WindowsArg $GamePath)
        $Browser = Start-Process -FilePath $NativeBinary -ArgumentList $nativeArgs -WorkingDirectory $Root -PassThru
        Wait-Process -Id $Browser.Id
        $Browser.Refresh()
        exit $Browser.ExitCode
    }

    if (-not (Test-Path -LiteralPath $ServeScript -PathType Leaf)) { throw "Server script not found: $ServeScript" }
    if (-not (Test-Path -LiteralPath (Join-Path $WebRoot 'index.html') -PathType Leaf)) {
        throw "Built web site not found: $WebRoot (build the selected iteration first)"
    }
    New-Item -ItemType Directory -Force -Path $LogRoot | Out-Null
    $serverOut = Join-Path $LogRoot 'server.stdout.log'
    $serverErr = Join-Path $LogRoot 'server.stderr.log'
    $pythonPath = $null
    $pyLauncher = Get-Command py -ErrorAction SilentlyContinue
    if ($pyLauncher) {
        $pythonPath = (& $pyLauncher.Source -3 -c 'import sys; print(sys.executable)').Trim()
        if ($LASTEXITCODE -ne 0 -or -not (Test-Path -LiteralPath $pythonPath -PathType Leaf)) { $pythonPath = $null }
    }
    if (-not $pythonPath) {
        $pythonCommand = Get-Command python -ErrorAction SilentlyContinue
        if (-not $pythonCommand) { throw 'Python (py or python) was not found on PATH' }
        $pythonPath = $pythonCommand.Source
    }
    $serverArgs = @($ServeScript, '--iteration', $Iteration, '--game-dir', $GameDir, '--port', '0', '--ready-file', $ReadyFile)
    $quotedArgs = ($serverArgs | ForEach-Object { Quote-WindowsArg $_ }) -join ' '
    $Server = Start-Process -FilePath $pythonPath -ArgumentList $quotedArgs -WorkingDirectory $Root -WindowStyle Hidden -RedirectStandardOutput $serverOut -RedirectStandardError $serverErr -PassThru

    $deadline = (Get-Date).AddSeconds(15)
    do {
        Start-Sleep -Milliseconds 100
        if ($Server.HasExited) { throw "Web server exited early with code $($Server.ExitCode); see $serverErr" }
        if (Test-Path -LiteralPath $ReadyFile -PathType Leaf) { break }
    } while ((Get-Date) -lt $deadline)
    if (-not (Test-Path -LiteralPath $ReadyFile -PathType Leaf)) { throw "Timed out waiting for server readiness; see $serverErr" }
    $ready = Get-Content -LiteralPath $ReadyFile -Raw | ConvertFrom-Json
    if ([int]$ready.pid -ne $Server.Id) { throw "Server PID mismatch (launcher=$($Server.Id), readiness=$($ready.pid)); see $serverErr" }
    $url = "http://127.0.0.1:$([int]$ready.port)/"
    $browserName = if ($Mode -eq 'desktop') { 'browser app' } else { 'browser' }
    $browserPath = Find-Browser
    if (-not $browserPath) { throw 'Edge/Chrome/Chromium was not found in standard install paths or PATH' }
    $browserArgs = if ($Mode -eq 'desktop') { @('--app=' + $url) } else { @($url) }
    $browserArgLine = ($browserArgs | ForEach-Object { Quote-WindowsArg $_ }) -join ' '
    $Browser = Start-Process -FilePath $browserPath -ArgumentList $browserArgLine -PassThru
    Write-Host "Started $browserName at $url. Press Ctrl+C here to stop the owned server."
    while (-not $Server.HasExited) { Start-Sleep -Seconds 1 }
    if ($Server.ExitCode -ne 0) { throw "Web server exited with code $($Server.ExitCode); see $serverErr" }
} finally {
    if ($Server -and -not $Server.HasExited) {
        Stop-Process -Id $Server.Id -Force -ErrorAction SilentlyContinue
        $Server.WaitForExit()
    }
    if (Test-Path -LiteralPath $ReadyFile -PathType Leaf) { Remove-Item -LiteralPath $ReadyFile -Force -ErrorAction SilentlyContinue }
}
