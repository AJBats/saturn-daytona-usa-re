#!/bin/bash
# setup-toolchain.sh - Bootstrap the Daytona USA decomp toolchain
#
# Run this once after cloning to set up everything needed for `make verify`.
# Works in: WSL Ubuntu, native Linux, MSYS2. Not tested on macOS.
#
# What it does:
#   1. Checks prerequisites (Python 3, build tools)
#   2. Builds sh-elf-binutils from source into tools/sh-elf/
#   3. Checks for the Cygnus 96Q3 compiler
#   4. Checks for the original game binary (APROG.BIN)
#   5. Runs the splitter to generate build/aprog.s
#
# After setup completes, run:  make verify

set -e

PROJ_ROOT="$(cd "$(dirname "$0")" && pwd)"
TOOLS_DIR="$PROJ_ROOT/tools"
SH_ELF_PREFIX="$TOOLS_DIR/sh-elf"
BINUTILS_VER="2.42"
BINUTILS_URL="https://sourceware.org/pub/binutils/releases/binutils-${BINUTILS_VER}.tar.xz"

# Cygnus compiler expected location (committed to repo)
CYGNUS_DIR="$TOOLS_DIR/cygnus-2.7-96Q3"

# Original binary (user must provide)
ORIGINAL_BIN="$PROJ_ROOT/build/disc/files/APROG.BIN"

# Colors (if terminal supports them)
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

pass()  { echo -e "  ${GREEN}[OK]${NC}   $1"; }
fail()  { echo -e "  ${RED}[MISS]${NC} $1"; }
warn()  { echo -e "  ${YELLOW}[WARN]${NC} $1"; }
info()  { echo -e "  ...    $1"; }

echo ""
echo "=== Daytona USA (Saturn) Decomp - Toolchain Setup ==="
echo ""

READY=true

# ── 1. Prerequisites ────────────────────────────────────────────────

echo "Checking prerequisites..."

if command -v python3 &>/dev/null; then
    pass "Python 3: $(python3 --version 2>&1)"
elif command -v python &>/dev/null && python --version 2>&1 | grep -q "Python 3"; then
    pass "Python 3: $(python --version 2>&1)"
else
    fail "Python 3 not found. Install it and re-run."
    READY=false
fi

if command -v gcc &>/dev/null && command -v make &>/dev/null; then
    pass "Build tools (gcc, make)"
else
    fail "gcc/make not found. Install build-essential: sudo apt install build-essential"
    READY=false
fi

# ── 2. sh-elf-binutils ─────────────────────────────────────────────

echo ""
echo "Checking sh-elf-binutils..."

if [ -x "$SH_ELF_PREFIX/bin/sh-elf-as" ] && \
   [ -x "$SH_ELF_PREFIX/bin/sh-elf-ld" ] && \
   [ -x "$SH_ELF_PREFIX/bin/sh-elf-objcopy" ]; then
    pass "sh-elf-binutils already installed at tools/sh-elf/"
else
    info "sh-elf-binutils not found. Building from source..."
    info "Downloading binutils-${BINUTILS_VER}..."

    BUILD_TMP="$PROJ_ROOT/.setup-tmp"
    mkdir -p "$BUILD_TMP"

    if [ ! -f "$BUILD_TMP/binutils-${BINUTILS_VER}.tar.xz" ]; then
        curl -sL --max-time 120 "$BINUTILS_URL" \
            -o "$BUILD_TMP/binutils-${BINUTILS_VER}.tar.xz"
    fi

    if [ ! -d "$BUILD_TMP/binutils-${BINUTILS_VER}" ]; then
        info "Extracting..."
        tar xf "$BUILD_TMP/binutils-${BINUTILS_VER}.tar.xz" -C "$BUILD_TMP"
    fi

    mkdir -p "$BUILD_TMP/binutils-build"
    cd "$BUILD_TMP/binutils-build"

    info "Configuring for sh-elf target..."
    "$BUILD_TMP/binutils-${BINUTILS_VER}/configure" \
        --target=sh-elf \
        --prefix="$SH_ELF_PREFIX" \
        --disable-nls \
        --disable-werror \
        --disable-gdb \
        --disable-sim \
        --quiet

    info "Building (this takes a minute or two)..."
    make -j"$(nproc)" --quiet

    info "Installing to tools/sh-elf/..."
    make install --quiet

    cd "$PROJ_ROOT"

    # Clean up build artifacts (keep the tarball for re-runs)
    rm -rf "$BUILD_TMP/binutils-build" "$BUILD_TMP/binutils-${BINUTILS_VER}"

    if [ -x "$SH_ELF_PREFIX/bin/sh-elf-as" ]; then
        pass "sh-elf-binutils built and installed"
    else
        fail "sh-elf-binutils build failed"
        READY=false
    fi
fi

# ── 3. Cygnus 96Q3 compiler ────────────────────────────────────────

echo ""
echo "Checking Cygnus 96Q3 compiler..."

if [ -f "$CYGNUS_DIR/BIN/CC1.EXE" ] || [ -f "$CYGNUS_DIR/BIN/cc1.exe" ]; then
    pass "Cygnus compiler at tools/cygnus-2.7-96Q3/"
else
    warn "Cygnus compiler not found."
    warn "Not needed for asm round-trip builds, but required for C compilation later."
    warn "Expected at: tools/cygnus-2.7-96Q3/BIN/CC1.EXE"
fi

# ── 4. Original game binary ────────────────────────────────────────

echo ""
echo "Checking original APROG.BIN..."

if [ -f "$ORIGINAL_BIN" ]; then
    SIZE=$(stat -c%s "$ORIGINAL_BIN" 2>/dev/null || stat -f%z "$ORIGINAL_BIN" 2>/dev/null)
    if [ "$SIZE" = "394896" ]; then
        pass "APROG.BIN present (394,896 bytes)"
    else
        warn "APROG.BIN present but unexpected size: $SIZE (expected 394896)"
    fi
else
    fail "APROG.BIN not found at build/disc/files/APROG.BIN"
    info "Extract it from your Daytona USA (USA) disc image."
    info "  mkdir -p build/disc/files"
    info "  cp <your-disc>/APROG.BIN build/disc/files/"
    READY=false
fi

# ── 5. Generate build artifacts ────────────────────────────────────

echo ""
if [ -f "$ORIGINAL_BIN" ] && [ -f "$PROJ_ROOT/scripts/split_binary.py" ]; then
    if [ -f "$PROJ_ROOT/build/aprog.s" ]; then
        pass "build/aprog.s already exists (re-run 'make split' to regenerate)"
    else
        echo "Running splitter to generate build/aprog.s..."
        PYTHON_CMD="python3"
        command -v python3 &>/dev/null || PYTHON_CMD="python"
        $PYTHON_CMD "$PROJ_ROOT/scripts/split_binary.py"
        if [ -f "$PROJ_ROOT/build/aprog.s" ]; then
            pass "build/aprog.s generated"
        else
            fail "Splitter failed to produce build/aprog.s"
            READY=false
        fi
    fi
else
    warn "Skipping splitter (need APROG.BIN and scripts/split_binary.py)"
fi

# ── Summary ─────────────────────────────────────────────────────────

echo ""
echo "==========================================="
if [ "$READY" = true ]; then
    echo -e "${GREEN}Setup complete.${NC} Run:  make verify"
else
    echo -e "${YELLOW}Setup incomplete.${NC} Fix the issues above and re-run ./setup-toolchain.sh"
fi
echo "==========================================="
echo ""
