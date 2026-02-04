#!/bin/bash
# ============================================================
#  build_iso.sh — Build a patched Daytona USA disc image
#
#  Compiles all verified C functions, patches them into the
#  original APROG.BIN, and produces a Saturn disc image.
#
#  Usage (from project root):
#    MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash tools/build_iso.sh
#
#  Output:
#    build/aprog_patched.bin    — Patched program binary
#    build/disc/daytona_patched.iso — Ready-to-play disc image
# ============================================================
set -e

# Auto-detect project directory from script location
PROJDIR="$(cd "$(dirname "$0")/.." && pwd)"

echo "============================================================"
echo "  Daytona USA — Build Patched Disc Image"
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
echo "  OK"
echo ""

# Step 2: Compile, compare, and patch
echo "[2/3] Compiling and patching functions..."
python3 "$PROJDIR/tools/patch_binary.py" --patch 2>&1
echo ""

# Step 3: Verify output
echo "[3/3] Verifying output..."
if [ -f "$PROJDIR/build/disc/daytona_patched.iso" ]; then
    ORIG_SIZE=$(stat -c%s "$PROJDIR/build/disc/daytona_data.iso")
    NEW_SIZE=$(stat -c%s "$PROJDIR/build/disc/daytona_patched.iso")
    if [ "$ORIG_SIZE" -eq "$NEW_SIZE" ]; then
        echo "  ISO size OK ($NEW_SIZE bytes)"
    else
        echo "  WARNING: ISO size mismatch (orig=$ORIG_SIZE new=$NEW_SIZE)"
    fi

    if cmp -s "$PROJDIR/build/disc/daytona_data.iso" "$PROJDIR/build/disc/daytona_patched.iso"; then
        echo "  Binary identical to original (safe — all patches are verified matches)"
    else
        DIFF_BYTES=$(cmp -l "$PROJDIR/build/disc/daytona_data.iso" "$PROJDIR/build/disc/daytona_patched.iso" | wc -l)
        echo "  $DIFF_BYTES bytes differ from original"
    fi
else
    echo "  ERROR: ISO not created"
    exit 1
fi

echo ""
echo "============================================================"
echo "  Done! Load in a Saturn emulator:"
echo "    build/disc/daytona_patched.iso"
echo ""
echo "  Recommended emulators:"
echo "    - Mednafen (most accurate)"
echo "    - Kronos / Yabause (good compatibility)"
echo "    - RetroArch + Beetle Saturn core"
echo "============================================================"
