#!/bin/bash
# ============================================================
#  build_disc.sh — Build a patched Daytona USA disc (CUE+BIN)
#
#  Compiles all verified C functions, patches them into the
#  original APROG.BIN, and produces a Mednafen-ready CUE+BIN.
#
#  Usage (from project root):
#    MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash tools/build_disc.sh
#
#  Output:
#    build/aprog_patched.bin                      — Patched program binary
#    build/disc/patched_disc/Track 01.bin         — Patched data track
#    build/disc/patched_disc/daytona_patched.cue  — CUE sheet for Mednafen
# ============================================================
set -e

# Auto-detect project directory from script location
PROJDIR="$(cd "$(dirname "$0")/.." && pwd)"

echo "============================================================"
echo "  Daytona USA — Build Patched Disc (CUE+BIN)"
echo "============================================================"
echo ""

# Step 1: Verify toolchain
echo "[1/3] Checking toolchain..."
for tool in "$PROJDIR/tools/gcc26-build/cc1" \
            "$PROJDIR/tools/sh-elf/bin/sh-elf-as" \
            "$PROJDIR/tools/sh-elf/bin/sh-elf-ld" \
            "$PROJDIR/tools/sh-elf/bin/sh-elf-objcopy"; do
    if [ ! -f "$tool" ]; then
        echo "  ERROR: Missing $tool"
        exit 1
    fi
done

ORIG_TRACK01="$PROJDIR/external_resources/Daytona USA (USA)/Daytona USA (USA) (Track 01).bin"
if [ ! -f "$ORIG_TRACK01" ]; then
    echo "  ERROR: Original Track 01 not found: $ORIG_TRACK01"
    exit 1
fi
echo "  OK"
echo ""

# Step 2: Compile, compare, and patch
echo "[2/3] Compiling and patching functions..."
INCLUDE_FILE="$PROJDIR/build/test_include.txt"
if [ -f "$INCLUDE_FILE" ]; then
    python3 "$PROJDIR/tools/patch_binary.py" --patch --level 2 --include-funcs "$INCLUDE_FILE" 2>&1
else
    python3 "$PROJDIR/tools/patch_binary.py" --patch 2>&1
fi
echo ""

# Step 3: Verify output
echo "[3/3] Verifying output..."
PATCHED_TRACK01="$PROJDIR/build/disc/patched_disc/Track 01.bin"
PATCHED_CUE="$PROJDIR/build/disc/patched_disc/daytona_patched.cue"

if [ -f "$PATCHED_TRACK01" ] && [ -f "$PATCHED_CUE" ]; then
    ORIG_SIZE=$(stat -c%s "$ORIG_TRACK01")
    NEW_SIZE=$(stat -c%s "$PATCHED_TRACK01")
    if [ "$ORIG_SIZE" -eq "$NEW_SIZE" ]; then
        echo "  Track 01 size OK ($NEW_SIZE bytes)"
    else
        echo "  WARNING: Track 01 size mismatch (orig=$ORIG_SIZE new=$NEW_SIZE)"
    fi

    if cmp -s "$ORIG_TRACK01" "$PATCHED_TRACK01"; then
        echo "  Binary identical to original (safe — all patches are verified matches)"
    else
        DIFF_BYTES=$(cmp -l "$ORIG_TRACK01" "$PATCHED_TRACK01" | wc -l)
        echo "  $DIFF_BYTES bytes differ from original"
    fi
else
    echo "  ERROR: Disc not created"
    exit 1
fi

echo ""
echo "============================================================"
echo "  Done! Launch with:"
echo "    run_patched.bat"
echo ""
echo "  Output:"
echo "    $PATCHED_CUE"
echo "============================================================"
