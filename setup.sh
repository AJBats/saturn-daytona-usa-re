#!/bin/bash
# setup.sh — Daytona USA (Saturn) Project Setup
#
# Single entrypoint for bootstrapping this project from a fresh clone.
# You need: a legally obtained Daytona USA (USA) disc dump in BIN/CUE format.
#
# Usage:
#   ./setup.sh                  Full setup (extract disc, build toolchain)
#   ./setup.sh clean            Wipe all derived artifacts back to ground zero
#   ./setup.sh status           Show what's present and what's missing
#
# What this does:
#   1. Checks prerequisites (Python 3, gcc, make, wget, SDL2)
#   2. Extracts APROG.BIN from your disc image
#   3. Generates the disassembly bible (build/aprog.s)
#   4. Builds sh-elf cross-toolchain (binutils 2.42 + GCC 13.3.0)
#   5. Builds debug Mednafen emulator (from mednafen/ submodule)
#
# After setup, build the reimplementation:
#   cd reimpl && make            Build reimpl binary
#   cd reimpl && make disc       Inject into disc image for emulator testing
#
# Disc image location (place yours here before running):
#   external_resources/Daytona USA (USA)/
#     Daytona USA (USA).cue
#     Daytona USA (USA) (Track 01).bin    <- Data track
#     Daytona USA (USA) (Track 02).bin    <- Audio (CDDA)
#     ... (up to Track 22)

set -e

# Handle CRLF when run from Windows (e.g. wsl -- bash setup.sh)
(set -o igncr) 2>/dev/null && set -o igncr

PROJ_ROOT="$(cd "$(dirname "$0")" && pwd)"
SH_ELF_PREFIX="$PROJ_ROOT/tools/sh-elf"
BINUTILS_VER="2.42"
BINUTILS_URL="https://sourceware.org/pub/binutils/releases/binutils-${BINUTILS_VER}.tar.xz"
BUILD_TMP="$PROJ_ROOT/.setup-tmp"

# ── helpers ────────────────────────────────────────────────────────

RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'; CYAN='\033[0;36m'; NC='\033[0m'
ok()   { echo -e "  ${GREEN}✓${NC} $1"; }
miss() { echo -e "  ${RED}✗${NC} $1"; }
warn() { echo -e "  ${YELLOW}!${NC} $1"; }
step() { echo -e "\n${CYAN}── $1 ──${NC}\n"; }

find_python() {
    if command -v python3 &>/dev/null; then echo "python3"
    elif command -v python &>/dev/null && python --version 2>&1 | grep -q "Python 3"; then echo "python"
    else echo ""; fi
}

# ── status ─────────────────────────────────────────────────────────

do_status() {
    echo ""
    echo -e "${CYAN}Daytona USA (Saturn) — Project Status${NC}"
    echo ""

    # Disc image
    DISC_DIR="$PROJ_ROOT/external_resources/Daytona USA (USA)"
    if [ -d "$DISC_DIR" ]; then
        ok "Disc image: external_resources/Daytona USA (USA)/"
    else
        miss "Disc image not found (place at external_resources/Daytona USA (USA)/)"
    fi

    # APROG.BIN
    APROG="$PROJ_ROOT/build/disc/files/APROG.BIN"
    if [ -f "$APROG" ]; then
        SIZE=$(stat -c%s "$APROG" 2>/dev/null || stat -f%z "$APROG" 2>/dev/null)
        ok "APROG.BIN extracted ($SIZE bytes)"
    else
        miss "APROG.BIN not extracted"
    fi

    # aprog.s (the bible)
    if [ -f "$PROJ_ROOT/build/aprog.s" ]; then
        LINES=$(wc -l < "$PROJ_ROOT/build/aprog.s" | tr -d ' ')
        ok "build/aprog.s ($LINES lines)"
    else
        miss "build/aprog.s not generated"
    fi

    # Toolchain
    if [ -x "$SH_ELF_PREFIX/bin/sh-elf-as" ]; then
        ok "sh-elf-binutils (as, ld, objcopy)"
    else
        miss "sh-elf-binutils not built"
    fi

    if [ -x "$SH_ELF_PREFIX/bin/sh-elf-gcc" ]; then
        VER=$("$SH_ELF_PREFIX/bin/sh-elf-gcc" --version 2>/dev/null | head -1 | grep -oP '\d+\.\d+\.\d+' || echo "?")
        ok "sh-elf-gcc $VER"
    else
        miss "sh-elf-gcc not built"
    fi

    # Mednafen
    if [ -f "$PROJ_ROOT/mednafen/src/mednafen" ]; then
        ok "Mednafen debug emulator"
    else
        miss "Mednafen not built"
    fi

    # Reimpl
    if [ -f "$PROJ_ROOT/reimpl/build/APROG.BIN" ]; then
        SIZE=$(stat -c%s "$PROJ_ROOT/reimpl/build/APROG.BIN" 2>/dev/null || stat -f%z "$PROJ_ROOT/reimpl/build/APROG.BIN" 2>/dev/null)
        ok "reimpl build ($SIZE bytes)"
    else
        miss "reimpl not built (cd reimpl && make)"
    fi

    echo ""
}

# ── clean ──────────────────────────────────────────────────────────

do_clean() {
    echo ""
    echo -e "${CYAN}Cleaning all derived artifacts...${NC}"
    echo ""

    for dir in build reimpl/build tools/sh-elf tools/gcc26-build tools/old-gcc .setup-tmp; do
        if [ -d "$PROJ_ROOT/$dir" ]; then
            echo "  rm -rf $dir/"
            rm -rf "$PROJ_ROOT/$dir"
        fi
    done

    for f in reimpl/daytona_sizing.elf reimpl/saturn_fixed.ld reimpl/src/trampolines.s; do
        if [ -f "$PROJ_ROOT/$f" ]; then
            echo "  rm $f"
            rm -f "$PROJ_ROOT/$f"
        fi
    done

    find "$PROJ_ROOT" -type d -name __pycache__ -exec rm -rf {} + 2>/dev/null || true

    echo ""
    echo -e "${GREEN}Ground zero.${NC} Run ./setup.sh to rebuild everything."
    echo ""
}

# ── full setup ─────────────────────────────────────────────────────

do_setup() {
    echo ""
    echo -e "${CYAN}Daytona USA (Saturn) — Project Setup${NC}"
    echo ""

    READY=true

    # ── Prerequisites ──────────────────────────────────────────────

    step "1. Prerequisites"

    PYTHON=$(find_python)
    if [ -n "$PYTHON" ]; then
        ok "Python 3: $($PYTHON --version 2>&1)"
    else
        miss "Python 3 not found (install python3)"
        READY=false
    fi

    if command -v gcc &>/dev/null && command -v make &>/dev/null; then
        ok "Build tools (gcc, make)"
    else
        miss "gcc/make not found (sudo apt install build-essential)"
        READY=false
    fi

    if command -v wget &>/dev/null; then
        ok "wget"
    else
        miss "wget not found (sudo apt install wget)"
        READY=false
    fi

    if pkg-config --exists sdl2 2>/dev/null; then
        ok "SDL2 ($(pkg-config --modversion sdl2))"
    else
        miss "SDL2 not found (sudo apt install libsdl2-dev)"
        READY=false
    fi

    if [ "$READY" = false ]; then
        echo ""
        echo -e "${RED}Missing prerequisites. Install them and re-run.${NC}"
        exit 1
    fi

    # ── Extract disc ───────────────────────────────────────────────

    step "2. Disc extraction"

    APROG="$PROJ_ROOT/build/disc/files/APROG.BIN"

    if [ -f "$APROG" ]; then
        ok "APROG.BIN already extracted"
    else
        DISC_DIR="$PROJ_ROOT/external_resources/Daytona USA (USA)"
        if [ ! -d "$DISC_DIR" ]; then
            miss "Disc image not found"
            echo ""
            echo "  Place your Daytona USA (USA) BIN/CUE dump at:"
            echo "    external_resources/Daytona USA (USA)/"
            echo ""
            echo "  Then re-run ./setup.sh"
            exit 1
        fi

        echo "  Extracting disc image..."
        $PYTHON "$PROJ_ROOT/tools/extract_disc.py"

        if [ -f "$APROG" ]; then
            SIZE=$(stat -c%s "$APROG" 2>/dev/null || stat -f%z "$APROG" 2>/dev/null)
            ok "APROG.BIN extracted ($SIZE bytes)"
        else
            miss "Extraction failed"
            exit 1
        fi
    fi

    # ── Generate aprog.s ───────────────────────────────────────────

    step "3. Disassembly (aprog.s)"

    if [ -f "$PROJ_ROOT/build/aprog.s" ]; then
        ok "build/aprog.s already exists"
    else
        echo "  Splitting binary into annotated assembly..."
        $PYTHON "$PROJ_ROOT/scripts/split_binary.py"

        if [ -f "$PROJ_ROOT/build/aprog.s" ]; then
            LINES=$(wc -l < "$PROJ_ROOT/build/aprog.s" | tr -d ' ')
            ok "build/aprog.s generated ($LINES lines)"
        else
            miss "split_binary.py failed"
            exit 1
        fi
    fi

    # ── sh-elf-binutils ────────────────────────────────────────────

    step "4. Cross-assembler (sh-elf-binutils ${BINUTILS_VER})"

    if [ -x "$SH_ELF_PREFIX/bin/sh-elf-as" ] && \
       [ -x "$SH_ELF_PREFIX/bin/sh-elf-ld" ] && \
       [ -x "$SH_ELF_PREFIX/bin/sh-elf-objcopy" ]; then
        ok "Already installed at tools/sh-elf/"
    else
        echo "  Downloading binutils ${BINUTILS_VER}..."
        mkdir -p "$BUILD_TMP"

        if [ ! -f "$BUILD_TMP/binutils-${BINUTILS_VER}.tar.xz" ]; then
            wget -q --show-progress "$BINUTILS_URL" \
                -O "$BUILD_TMP/binutils-${BINUTILS_VER}.tar.xz"
        fi

        if [ ! -d "$BUILD_TMP/binutils-${BINUTILS_VER}" ]; then
            echo "  Extracting..."
            tar xf "$BUILD_TMP/binutils-${BINUTILS_VER}.tar.xz" -C "$BUILD_TMP"
        fi

        echo "  Configuring..."
        mkdir -p "$BUILD_TMP/binutils-build"
        cd "$BUILD_TMP/binutils-build"

        "$BUILD_TMP/binutils-${BINUTILS_VER}/configure" \
            --target=sh-elf \
            --prefix="$SH_ELF_PREFIX" \
            --disable-nls \
            --disable-werror \
            --disable-gdb \
            --disable-sim \
            --quiet

        echo "  Building (this takes a couple minutes)..."
        make -j"$(nproc)" --quiet
        make install --quiet

        cd "$PROJ_ROOT"
        rm -rf "$BUILD_TMP/binutils-build" "$BUILD_TMP/binutils-${BINUTILS_VER}"

        if [ -x "$SH_ELF_PREFIX/bin/sh-elf-as" ]; then
            ok "sh-elf-binutils installed"
        else
            miss "Build failed"
            exit 1
        fi
    fi

    # ── sh-elf-gcc ─────────────────────────────────────────────────

    step "5. Cross-compiler (sh-elf-gcc 13.3.0)"

    if [ -x "$SH_ELF_PREFIX/bin/sh-elf-gcc" ]; then
        VER=$("$SH_ELF_PREFIX/bin/sh-elf-gcc" --version 2>/dev/null | head -1 | grep -oP '\d+\.\d+\.\d+' || echo "?")
        ok "Already installed (GCC $VER)"
    else
        # Check GCC build prerequisites
        for lib in gmp mpfr mpc; do
            if ! dpkg -l "lib${lib}-dev" 2>/dev/null | grep -q '^ii'; then
                miss "lib${lib}-dev not installed"
                echo "  Run: sudo apt install libgmp-dev libmpfr-dev libmpc-dev"
                exit 1
            fi
        done

        echo "  Building GCC 13.3.0 for sh-elf (this takes 10-20 minutes)..."
        bash "$PROJ_ROOT/tools/build_sh_elf_gcc.sh"

        if [ -x "$SH_ELF_PREFIX/bin/sh-elf-gcc" ]; then
            ok "sh-elf-gcc installed"
        else
            miss "GCC build failed"
            exit 1
        fi
    fi

    # ── Mednafen (debug emulator) ─────────────────────────────────

    step "6. Debug emulator (Mednafen)"

    MEDNAFEN_BIN="$PROJ_ROOT/mednafen/src/mednafen"

    if [ -f "$MEDNAFEN_BIN" ]; then
        ok "Already built at mednafen/src/mednafen"
    else
        if [ ! -d "$PROJ_ROOT/mednafen/src" ]; then
            miss "mednafen submodule not checked out"
            echo "  Run: git submodule update --init --recursive"
            exit 1
        fi

        # Mednafen's #include <mednafen/...> needs include/mednafen -> ../src
        if [ ! -e "$PROJ_ROOT/mednafen/include/mednafen" ]; then
            ln -sf ../src "$PROJ_ROOT/mednafen/include/mednafen"
        fi

        echo "  Configuring Mednafen..."
        cd "$PROJ_ROOT/mednafen"
        ./configure --disable-jack --quiet

        echo "  Building Mednafen (this takes a few minutes)..."
        make -j"$(nproc)" --quiet

        cd "$PROJ_ROOT"

        if [ -f "$MEDNAFEN_BIN" ]; then
            ok "Mednafen built"
        else
            miss "Mednafen build failed"
            exit 1
        fi
    fi

    # ── Done ───────────────────────────────────────────────────────

    echo ""
    echo -e "${GREEN}Setup complete!${NC}"
    echo ""
    echo "  Build the reimplementation:"
    echo "    cd reimpl && make"
    echo ""
    echo "  Inject into disc image for emulator testing:"
    echo "    cd reimpl && make disc"
    echo ""
}

# ── dispatch ───────────────────────────────────────────────────────

CMD="$(echo "${1:-}" | tr -d '\r')"

case "$CMD" in
    "")      do_setup ;;
    clean)   do_clean ;;
    status)  do_status ;;
    -h|--help|help)
        echo "Usage: ./setup.sh [command]"
        echo ""
        echo "Commands:"
        echo "  (none)    Full setup — extract disc, build toolchain"
        echo "  clean     Remove all derived artifacts (ground zero)"
        echo "  status    Show what's present and what's missing"
        echo "  help      This message"
        echo ""
        ;;
    *)
        echo "Unknown command: $CMD (try ./setup.sh help)"
        exit 1
        ;;
esac
