param(
    [string]$BuildDir = "build",
    [string]$Config = "Release",
    [string]$InstallDir = "install"
)

$ErrorActionPreference = "Stop"

cmake --install $BuildDir --config $Config --prefix $InstallDir