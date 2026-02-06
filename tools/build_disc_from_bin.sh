#!/bin/bash
# ============================================================
#  build_disc_from_bin.sh — Build disc from a rebuilt APROG.BIN
#
#  Takes a binary file and injects it into the original disc
#  image at the APROG.BIN location.
#
#  Usage:
#    bash tools/build_disc_from_bin.sh [binary_file]
#
#  If no binary_file specified, uses build/compiler_rebuilt/aprog_rebuilt.bin
# ============================================================
set -e

PROJDIR="$(cd "$(dirname "$0")/.." && pwd)"

# Input binary
if [ -n "$1" ]; then
    INPUT_BIN="$1"
else
    INPUT_BIN="$PROJDIR/build/compiler_rebuilt/aprog_rebuilt.bin"
fi

if [ ! -f "$INPUT_BIN" ]; then
    echo "ERROR: Binary not found: $INPUT_BIN"
    exit 1
fi

echo "============================================================"
echo "  Build Disc from Binary"
echo "============================================================"
echo ""
echo "Input binary: $INPUT_BIN"
echo ""

# Verify original disc
ORIG_TRACK01="$PROJDIR/external_resources/Daytona USA (USA)/Daytona USA (USA) (Track 01).bin"
if [ ! -f "$ORIG_TRACK01" ]; then
    echo "ERROR: Original Track 01 not found: $ORIG_TRACK01"
    exit 1
fi

# APROG.BIN location in disc image (found by binary search)
APROG_OFFSET=49408  # 0xC100

# Create output directory
OUTDIR="$PROJDIR/build/disc/rebuilt_disc"
mkdir -p "$OUTDIR"

echo "[1/3] Copying original disc track..."
cp "$ORIG_TRACK01" "$OUTDIR/Track 01.bin"
echo "  OK"

echo ""
echo "[2/3] Injecting rebuilt binary at offset $APROG_OFFSET..."

# Verify sizes match
ORIG_APROG_SIZE=394896  # Expected size
NEW_SIZE=$(stat -c%s "$INPUT_BIN")

if [ "$NEW_SIZE" -ne "$ORIG_APROG_SIZE" ]; then
    echo "  WARNING: Binary size mismatch (expected=$ORIG_APROG_SIZE got=$NEW_SIZE)"
    echo "  Proceeding anyway..."
fi

# Inject binary at correct offset
dd if="$INPUT_BIN" of="$OUTDIR/Track 01.bin" bs=1 seek=$APROG_OFFSET conv=notrunc 2>/dev/null

echo "  Injected $NEW_SIZE bytes at offset $APROG_OFFSET"

echo ""
echo "[3/3] Creating CUE sheet..."
cat > "$OUTDIR/daytona_rebuilt.cue" << 'EOF'
FILE "Track 01.bin" BINARY
  TRACK 01 MODE1/2352
    INDEX 01 00:00:00
EOF
echo "  OK"

echo ""
echo "============================================================"
echo "  Done!"
echo ""
echo "  Output:"
echo "    $OUTDIR/daytona_rebuilt.cue"
echo "    $OUTDIR/Track 01.bin"
echo ""
echo "  To test in Mednafen:"
echo "    mednafen \"$OUTDIR/daytona_rebuilt.cue\""
echo "============================================================"
