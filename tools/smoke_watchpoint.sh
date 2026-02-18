#!/bin/bash
# Smoke test: watch 0x06003000 (first word of game binary) to verify watchpoints work.
# The BIOS MUST write here when loading the game. Also checks frame count.
set -e

PROJDIR="/mnt/d/Projects/SaturnReverseTest"
MEDNAFEN="$PROJDIR/mednafen/src/mednafen"
WATCH_ADDR="${1:-06003000}"
RUN_SECS="${2:-20}"
IPC_DIR="/tmp/emu_wp_smoke"
ACTION="$IPC_DIR/mednafen_action.txt"
ACK="$IPC_DIR/mednafen_ack.txt"
HITLOG="$IPC_DIR/watchpoint_hits.txt"
CUE="$PROJDIR/external_resources/Daytona USA (USA)/Daytona USA (USA).cue"

mkdir -p "$IPC_DIR"
rm -f "$ACTION" "$ACK" "$HITLOG"

MDFN_HOME="/tmp/mdfn_smoke"
mkdir -p "$MDFN_HOME/.mednafen/firmware" "$MDFN_HOME/.mednafen/pgconfig" "$MDFN_HOME/.mednafen/cheats" "$MDFN_HOME/.mednafen/snaps"
for f in sega_101.bin mpr-17933.bin; do
    src="$HOME/.mednafen/firmware/$f"
    dst="$MDFN_HOME/.mednafen/firmware/$f"
    [ -f "$src" ] && [ ! -L "$dst" ] && ln -sf "$src" "$dst"
done

echo "Smoke test: watch 0x$WATCH_ADDR for ${RUN_SECS}s"
MEDNAFEN_ALLOWMULTI=1 HOME="$MDFN_HOME" "$MEDNAFEN" --sound 0 --automation "$IPC_DIR" "$CUE" >/dev/null 2>&1 &
PID=$!

# Wait ready
for i in $(seq 1 60); do
    [ -f "$ACK" ] && grep -q ready "$ACK" 2>/dev/null && break
    sleep 0.5
done
echo "Ready: $(cat "$ACK" 2>/dev/null)"

# Set watchpoint
printf "# 1.\nwatchpoint $WATCH_ADDR\n" > "$ACTION"
sleep 2
echo "WP set: $(cat "$ACK" 2>/dev/null)"

# Resume emulation (automation starts paused)
printf "# 2..\ncontinue\n" > "$ACTION"
sleep 1
echo "Continue: $(cat "$ACK" 2>/dev/null)"

# Run
echo "Running ${RUN_SECS}s..."
sleep "$RUN_SECS"

# Status
printf "# 3...\nstatus\n" > "$ACTION"
sleep 2
echo "Status: $(cat "$ACK" 2>/dev/null)"

# Results
echo ""
echo "=== Hit log ==="
if [ -f "$HITLOG" ]; then
    LINES=$(wc -l < "$HITLOG")
    echo "$LINES lines"
    head -20 "$HITLOG"
else
    echo "No hits file created"
fi

# Quit
printf "# 4....\nquit\n" > "$ACTION"
sleep 1
kill $PID 2>/dev/null || true
wait $PID 2>/dev/null || true
echo "Done."
