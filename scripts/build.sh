#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="${1:-build}"
CONFIG="${2:-Release}"
GENERATOR="${3:-Ninja}"

cmake -S "$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)" -B "$BUILD_DIR" -G "$GENERATOR" -DCMAKE_BUILD_TYPE="$CONFIG"
cmake --build "$BUILD_DIR" --config "$CONFIG"