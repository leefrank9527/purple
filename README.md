# PurpleNavigator

PurpleNavigator is a cross-platform Qt Widgets desktop app written in C++.
It uses a left-side navigation bar and a `QStackedWidget` to switch between views.

## Features

- Qt Widgets-based desktop GUI
- Left navigation menu with view switching
- CMake build system
- Install step and package generation via CPack
- Works on Windows, Ubuntu Linux, and macOS with the same source tree

## Dependencies

Install the following tools before building:

- CMake 3.21 or newer
- A C++17 compiler
- Qt 6 Widgets development files
- Ninja or another supported CMake generator

### Windows

Install Qt 6 using the Qt Online Installer or your preferred package manager.
Make sure `cmake`, the compiler toolchain, and Qt are available in your environment.

Recommended Windows toolchain setup:

1. Install Visual Studio 2022 Build Tools with the `Desktop development with C++` workload.
2. Install CMake and add it to `PATH`.
3. Optional: install Ninja and add it to `PATH` for faster builds.
4. Install Qt 6 (MSVC x64 kit, for example `win64_msvc2022_64`).

Quick install commands (PowerShell with winget):

```powershell
winget install Kitware.CMake
winget install Microsoft.VisualStudio.2022.BuildTools
winget install Ninja-build.Ninja
```

If Qt is not found by CMake, pass `CMAKE_PREFIX_PATH`:

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DCMAKE_PREFIX_PATH="C:/Qt/6.8.3/msvc2022_64"
```

```bash
pip install aqtinstall
```

```bash
aqt list-qt windows desktop
```

```bash
aqt install-qt windows desktop 6.8.3 win64_msvc2022_64
```

```bash
aqt install-tool windows desktop tools_cmake
```

### Ubuntu Linux

```bash
sudo apt update
sudo apt install build-essential cmake ninja-build qt6-base-dev qt6-base-dev-tools
```

### macOS

```bash
brew install cmake ninja qt
```

If Qt is not automatically found on macOS, add it to `CMAKE_PREFIX_PATH`.

## Build

### Windows PowerShell

```powershell
.\scripts\build.ps1
```

By default on Windows, `build.ps1` now uses Ninja when available and falls back to `Visual Studio 17 2022` when Ninja is missing.

### Linux / macOS

```bash
chmod +x scripts/*.sh
./scripts/build.sh
```

You can also pass custom arguments:

```powershell
.\scripts\build.ps1 -BuildDir out/build -Config Release -Generator Ninja
```

```bash
./scripts/build.sh out/build Release Ninja
```

## Install

### Windows PowerShell

```powershell
.\scripts\install.ps1 -BuildDir build -Config Release -InstallDir install
```

### Linux / macOS

```bash
./scripts/install.sh build Release install
```

This copies the built app into the chosen install prefix using `cmake --install`.

## Create an installation package

The project uses CPack through `CMakeLists.txt`.

### Windows PowerShell

```powershell
.\scripts\package.ps1 -BuildDir build -Config Release
```

### Linux / macOS

```bash
./scripts/package.sh build Release
```

The package format depends on the platform:

- Windows: `ZIP`
- Ubuntu Linux: `TGZ` and `ZIP`
- macOS: `DragNDrop` and `ZIP`

## Project Structure

- `src/main.cpp` starts the Qt application.
- `src/MainWindow.*` creates the shell with the left navigation and stacked pages.
- `src/pages/*` contains the individual views.
- `scripts/*` contains build, install, and package helpers.

## Notes

- The project targets Qt 6 Widgets and C++17.
- If your Qt installation is not discovered automatically, pass `-DCMAKE_PREFIX_PATH=<path-to-qt>` to CMake.
