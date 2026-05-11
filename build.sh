#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"

if [[ "${1:-}" == "clean" ]]; then
    rm -rf "$BUILD_DIR"
    shift
fi

cmake -S "$SCRIPT_DIR" -B "$BUILD_DIR"
cmake --build "$BUILD_DIR" -j"$(nproc)"

"$BUILD_DIR/main" "$@"
