#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="${1:-build}"
CONFIG="${2:-Release}"

cmake --build "$BUILD_DIR" --config "$CONFIG"
(cd "$BUILD_DIR" && cpack -C "$CONFIG")