#!/bin/bash
# setup.sh - Bootstrap or clean the Daytona USA Saturn project
#
# Usage:
#   ./setup.sh          # Full setup from scratch
#   ./setup.sh clean    # Remove all derived artifacts (back to ground zero)
#   ./setup.sh extract  # Just extract disc + generate aprog.s
#   ./setup.sh status   # Show what's present / missing
#
# Ground zero = git-tracked source only. No build/, no tools/sh-elf/,
# no tools/gcc26-build/. User must provide their own disc image at:
#   external_resources/Daytona USA (USA)/

set -e

PROJ_ROOT="$(cd "$(dirname "$0")" && pwd)"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

ok()   { echo -e "  ${GREEN}[OK]${NC}   $1"; }
miss() { echo -e "  ${RED}[MISS]${NC} $1"; }
warn() { echo -e "  ${YELLOW}[WARN]${NC} $1"; }
info() { echo -e "  ...    $1"; }

# ── clean ──────────────────────────────────────────────────────────
do_clean() {
    echo ""
    echo "=== Cleaning derived artifacts ==="
    echo ""

    # Build outputs
    if [ -d "$PROJ_ROOT/build" ]; then
        info "Removing build/"
        rm -rf "$PROJ_ROOT/build"
    fi
    if [ -d "$PROJ_ROOT/reimpl/build" ]; then
        info "Removing reimpl/build/"
        rm -rf "$PROJ_ROOT/reimpl/build"
    fi

    # Reimpl generated files
    for f in reimpl/daytona_sizing.elf reimpl/saturn_fixed.ld reimpl/src/trampolines.s; do
        if [ -f "$PROJ_ROOT/$f" ]; then
            info "Removing $f"
            rm -f "$PROJ_ROOT/$f"
        fi
    done

    # Toolchains (built locally)
    if [ -d "$PROJ_ROOT/tools/sh-elf" ]; then
        info "Removing tools/sh-elf/"
        rm -rf "$PROJ_ROOT/tools/sh-elf"
    fi
    if [ -d "$PROJ_ROOT/tools/gcc26-build" ]; then
        info "Removing tools/gcc26-build/"
        rm -rf "$PROJ_ROOT/tools/gcc26-build"
    fi
    if [ -d "$PROJ_ROOT/tools/old-gcc" ]; then
        info "Removing tools/old-gcc/"
        rm -rf "$PROJ_ROOT/tools/old-gcc"
    fi

    # Setup temp
    if [ -d "$PROJ_ROOT/.setup-tmp" ]; then
        info "Removing .setup-tmp/"
        rm -rf "$PROJ_ROOT/.setup-tmp"
    fi

    # Python caches
    find "$PROJ_ROOT" -type d -name __pycache__ -exec rm -rf {} + 2>/dev/null || true

    echo ""
    echo -e "${GREEN}Clean complete.${NC} Project is at ground zero."
    echo "Run './setup.sh' to rebuild everything from disc image."
    echo ""
}

# ── status ─────────────────────────────────────────────────────────
do_status() {
    echo ""
    echo "=== Project Status ==="
    echo ""

    echo "Disc image:"
    DISC_DIR="$PROJ_ROOT/external_resources/Daytona USA (USA)"
    if [ -d "$DISC_DIR" ]; then
        ok "Disc image directory found"
    else
        miss "Disc image not found at: external_resources/Daytona USA (USA)/"
    fi

    echo ""
    echo "Extracted files:"
    if [ -f "$PROJ_ROOT/build/disc/files/APROG.BIN" ]; then
        SIZE=$(stat -c%s "$PROJ_ROOT/build/disc/files/APROG.BIN" 2>/dev/null || stat -f%z "$PROJ_ROOT/build/disc/files/APROG.BIN" 2>/dev/null)
        ok "APROG.BIN ($SIZE bytes)"
    else
        miss "APROG.BIN (run './setup.sh extract')"
    fi

    if [ -f "$PROJ_ROOT/build/aprog.s" ]; then
        LINES=$(wc -l < "$PROJ_ROOT/build/aprog.s")
        ok "aprog.s ($LINES lines)"
    else
        miss "aprog.s (run './setup.sh extract')"
    fi

    echo ""
    echo "Toolchains:"
    if [ -x "$PROJ_ROOT/tools/sh-elf/bin/sh-elf-gcc" ]; then
        ok "sh-elf-gcc (modern, for reimpl)"
    else
        miss "sh-elf-gcc (run './setup.sh')"
    fi

    if [ -x "$PROJ_ROOT/tools/sh-elf/bin/sh-elf-as" ]; then
        ok "sh-elf-binutils"
    else
        miss "sh-elf-binutils (run './setup.sh')"
    fi

    if [ -x "$PROJ_ROOT/tools/gcc26-build/cc1" ]; then
        ok "GCC 2.6.3 cc1 (matching compiler)"
    else
        miss "GCC 2.6.3 cc1 (run './setup.sh')"
    fi

    if [ -f "$PROJ_ROOT/tools/cygnus-2.7-96Q3/BIN/CC1.EXE" ] || \
       [ -f "$PROJ_ROOT/tools/cygnus-2.7-96Q3/BIN/cc1.exe" ]; then
        ok "Cygnus 96Q3 (period-correct toolchain)"
    else
        warn "Cygnus 96Q3 (optional, committed to repo)"
    fi

    echo ""
    echo "Reimpl build:"
    if [ -f "$PROJ_ROOT/reimpl/build/APROG.BIN" ]; then
        SIZE=$(stat -c%s "$PROJ_ROOT/reimpl/build/APROG.BIN" 2>/dev/null || stat -f%z "$PROJ_ROOT/reimpl/build/APROG.BIN" 2>/dev/null)
        ok "reimpl APROG.BIN ($SIZE bytes)"
    else
        miss "reimpl APROG.BIN (run 'cd reimpl && make')"
    fi

    echo ""
}

# ── extract ────────────────────────────────────────────────────────
do_extract() {
    echo ""
    echo "=== Extracting disc image ==="
    echo ""

    PYTHON_CMD="python3"
    command -v python3 &>/dev/null || PYTHON_CMD="python"

    # Step 1: Extract disc
    if [ -f "$PROJ_ROOT/tools/extract_disc.py" ]; then
        info "Running extract_disc.py..."
        $PYTHON_CMD "$PROJ_ROOT/tools/extract_disc.py"
    else
        echo -e "${RED}ERROR: tools/extract_disc.py not found${NC}"
        exit 1
    fi

    # Step 2: Split binary
    if [ -f "$PROJ_ROOT/build/disc/files/APROG.BIN" ] && [ -f "$PROJ_ROOT/scripts/split_binary.py" ]; then
        info "Running split_binary.py..."
        $PYTHON_CMD "$PROJ_ROOT/scripts/split_binary.py"
        if [ -f "$PROJ_ROOT/build/aprog.s" ]; then
            ok "aprog.s generated"
        else
            echo -e "${RED}ERROR: split_binary.py failed${NC}"
            exit 1
        fi
    else
        echo -e "${RED}ERROR: Missing APROG.BIN or scripts/split_binary.py${NC}"
        exit 1
    fi

    echo ""
}

# ── full setup ─────────────────────────────────────────────────────
do_setup() {
    echo ""
    echo "=== Daytona USA (Saturn) - Full Setup ==="
    echo ""

    # Extract disc if needed
    if [ ! -f "$PROJ_ROOT/build/disc/files/APROG.BIN" ]; then
        do_extract
    else
        ok "Disc already extracted"
    fi

    # Run the existing toolchain setup
    if [ -f "$PROJ_ROOT/setup-toolchain.sh" ]; then
        bash "$PROJ_ROOT/setup-toolchain.sh"
    else
        warn "setup-toolchain.sh not found, skipping toolchain build"
    fi

    do_status
}

# ── dispatch ───────────────────────────────────────────────────────
case "${1:-}" in
    clean)   do_clean ;;
    status)  do_status ;;
    extract) do_extract ;;
    *)       do_setup ;;
esac
