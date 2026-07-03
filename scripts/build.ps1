param(
    [string]$BuildDir = "build",
    [string]$Config = "Release",
    [string]$Generator = ""
)

$ErrorActionPreference = "Stop"

if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    throw "CMake is not installed or not on PATH. Install CMake first, then reopen PowerShell."
}

if (-not $Generator) {
    if (Get-Command ninja -ErrorAction SilentlyContinue) {
        $Generator = "Ninja"
    } elseif ($IsWindows -or $env:OS -eq "Windows_NT") {
        $Generator = "Visual Studio 17 2022"
    }
}

$sourceDir = Join-Path $PSScriptRoot ".."
$cmakeArgs = @("-S", $sourceDir, "-B", $BuildDir)

if ($Generator) {
    $cmakeArgs += @("-G", $Generator)
}

if ($Generator -like "Visual Studio*") {
    $cmakeArgs += @("-A", "x64")
} else {
    $cmakeArgs += "-DCMAKE_BUILD_TYPE=$Config"
}

cmake @cmakeArgs
cmake --build $BuildDir --config $Config