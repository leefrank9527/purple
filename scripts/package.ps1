param(
    [string]$BuildDir = "build",
    [string]$Config = "Release"
)

$ErrorActionPreference = "Stop"

cmake --build $BuildDir --config $Config
Push-Location $BuildDir
cpack -C $Config
Pop-Location