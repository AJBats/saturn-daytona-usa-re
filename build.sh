#!/bin/bash
# build.sh - Run the build pipeline
# Usage (WSL):    wsl -d Ubuntu -- ./build.sh [target]
# Usage (native): ./build.sh [target]
#   Targets: build (default), verify, clean, split

PROJ_ROOT="$(cd "$(dirname "$0")" && pwd)"

# Add project-local toolchain to PATH (built by setup.sh)
export PATH="$PROJ_ROOT/tools/sh-elf/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

cd "$PROJ_ROOT" || exit 1

TARGET="${1:-build}"
make "$TARGET"
