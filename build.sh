#!/bin/bash
# ============================================================
#  build.sh — Unified build script for Daytona USA Saturn
#
#  Usage:
#    ./build.sh          Build patched disc
#    ./build.sh clean    Clean build artifacts, then build
#    ./build.sh test     Build + run test harness
#
#  Output:
#    build/disc/patched_disc/daytona_patched.cue
# ============================================================
set -e

PROJDIR="$(cd "$(dirname "$0")" && pwd)"

# Handle Windows path conversion for WSL
if [[ "$PROJDIR" == /mnt/* ]]; then
    # Already in WSL
    :
elif [[ "$PROJDIR" == *:* ]]; then
    # Windows path, convert to WSL
    PROJDIR=$(echo "$PROJDIR" | sed 's|\\|/|g' | sed 's|^\([A-Za-z]\):|/mnt/\L\1|')
fi

clean_build() {
    echo "=== Cleaning build artifacts ==="
    rm -rf "$PROJDIR/build/disc/patched_disc"
    rm -rf "$PROJDIR/build/disc/rebuilt_disc"
    rm -rf "$PROJDIR/build/disc/files"
    rm -f "$PROJDIR/build/disc/daytona_data.iso"
    rm -f "$PROJDIR/build/aprog_patched.bin"
    rm -rf "$PROJDIR/build/compiler_rebuilt"
    rm -rf "$PROJDIR/build/gen"
    echo "  Done"
    echo ""
}

build_disc() {
    echo "=== Building Patched Disc ==="
    echo ""

    # Step 1: Build compiler (if needed)
    CC1="$PROJDIR/tools/gcc26-build/cc1"
    if [ ! -f "$CC1" ]; then
        echo "[1/6] Building GCC 2.6.3 cc1 compiler..."
        bash "$PROJDIR/tools/final-rebuild.sh"
        echo ""
    else
        echo "[1/6] Compiler ready"
        echo "  OK"
        echo ""
    fi

    # Step 2: Verify toolchain
    echo "[2/6] Checking toolchain..."
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
        echo "  ERROR: Original disc not found"
        echo "  Expected: $ORIG_TRACK01"
        echo ""
        echo "  Place your Daytona USA (USA) disc dump in external_resources/"
        exit 1
    fi

    echo "  OK"
    echo ""

    # Step 3: Extract disc (if needed)
    APROG_BIN="$PROJDIR/build/disc/files/APROG.BIN"
    if [ ! -f "$APROG_BIN" ]; then
        echo "[3/6] Extracting disc image..."
        python3 "$PROJDIR/tools/extract_disc.py"
        echo ""
    else
        echo "[3/6] Disc already extracted"
        echo "  OK"
        echo ""
    fi

    # Step 4: Compile, compare, and patch
    echo "[4/6] Compiling and patching functions..."
    INCLUDE_FILE="$PROJDIR/build/test_include.txt"
    if [ -f "$INCLUDE_FILE" ]; then
        python3 "$PROJDIR/tools/patch_binary.py" --patch --level 2 --include-funcs "$INCLUDE_FILE" 2>&1
    else
        python3 "$PROJDIR/tools/patch_binary.py" --patch 2>&1
    fi
    echo ""

    # Step 5: Verify output
    echo "[5/6] Verifying output..."
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
            echo "  Binary identical to original (no patches applied)"
        else
            DIFF_BYTES=$(cmp -l "$ORIG_TRACK01" "$PATCHED_TRACK01" | wc -l)
            echo "  $DIFF_BYTES bytes patched"
        fi
    else
        echo "  ERROR: Disc not created"
        exit 1
    fi
    echo ""

    # Step 6: Verify audio tracks
    echo "[6/6] Checking audio tracks..."
    AUDIO_COUNT=$(ls -1 "$PROJDIR/build/disc/patched_disc/"*Track*.bin 2>/dev/null | wc -l)
    if [ "$AUDIO_COUNT" -ge 20 ]; then
        echo "  $AUDIO_COUNT tracks present (including audio)"
    else
        echo "  WARNING: Only $AUDIO_COUNT tracks found (expected 22)"
    fi
    echo ""

    echo "============================================================"
    echo "  Build complete!"
    echo ""
    echo "  Output: build/disc/patched_disc/daytona_patched.cue"
    echo ""
    echo "  To run:  run_patched.bat"
    echo "  To test: powershell -File tools/test_boot.ps1 -Cue patched"
    echo "============================================================"
}

run_test_harness() {
    echo "=== Running Test Harness ==="
    bash "$PROJDIR/tools/test_harness.sh"
}

# Main
case "${1:-}" in
    clean)
        clean_build
        build_disc
        ;;
    test)
        build_disc
        run_test_harness
        ;;
    "")
        build_disc
        ;;
    *)
        echo "Usage: $0 [clean|test]"
        exit 1
        ;;
esac
