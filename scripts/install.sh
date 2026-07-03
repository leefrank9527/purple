#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="${1:-build}"
CONFIG="${2:-Release}"
INSTALL_DIR="${3:-install}"

cmake --install "$BUILD_DIR" --config "$CONFIG" --prefix "$INSTALL_DIR"