#!/bin/bash
# Run the custom (CDB-fixed) Mednafen with a disc image.
# Usage: bash tools/run_debug_mednafen.sh [cue_path]
#   Default cue: rebuilt disc
#
# Run from WSL:  bash /mnt/d/Projects/SaturnReverseTest/tools/run_debug_mednafen.sh
# Run from Windows: wsl -d Ubuntu -- bash /mnt/d/Projects/SaturnReverseTest/tools/run_debug_mednafen.sh

PROJ=/mnt/d/Projects/SaturnReverseTest
MEDNAFEN="$PROJ/mednafen/src/mednafen"
DEFAULT_CUE="$PROJ/build/disc/rebuilt_disc/daytona_rebuilt.cue"

CUE="${1:-$DEFAULT_CUE}"

if [ ! -f "$MEDNAFEN" ]; then
    echo "ERROR: Custom Mednafen not found at $MEDNAFEN"
    echo "Build it: cd $PROJ/mednafen/src && make clean && make -j\$(nproc)"
    exit 1
fi

if [ ! -f "$CUE" ]; then
    echo "ERROR: CUE file not found: $CUE"
    exit 1
fi

# Isolated HOME avoids lock conflicts and keeps config separate
export HOME="/tmp/mdfn_debug"
export DISPLAY=:0
mkdir -p "$HOME/.mednafen/firmware"
cp /root/.mednafen/firmware/* "$HOME/.mednafen/firmware/" 2>/dev/null
rm -f "$HOME/.mednafen/mednafen.lck"

echo "Launching: $MEDNAFEN"
echo "Disc:      $CUE"
echo "---"
exec "$MEDNAFEN" --sound 0 "$CUE"
