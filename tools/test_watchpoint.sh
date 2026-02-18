#!/bin/bash
# Watchpoint test: monitor writes to 0x0606367C.
# The watchpoint now logs non-blocking to watchpoint_hits.txt in the IPC dir.
# No CPU hook overhead — detection is inline in BusRW_DB_CS3.
#
# Usage: wsl -d Ubuntu -- bash tools/test_watchpoint.sh [vanilla|rebuilt] [seconds]
#   vanilla = production disc (default)
#   rebuilt = reimpl disc
#   seconds = how long to run (default: 60)

set -e

PROJDIR="/mnt/d/Projects/SaturnReverseTest"
MEDNAFEN="$PROJDIR/mednafen/src/mednafen"
IPC_DIR="/tmp/emu_watchpoint"
ACTION="$IPC_DIR/mednafen_action.txt"
ACK="$IPC_DIR/mednafen_ack.txt"
HITLOG="$IPC_DIR/watchpoint_hits.txt"

DISC_TYPE="${1:-vanilla}"
RUN_SECS="${2:-60}"

if [ "$DISC_TYPE" = "vanilla" ]; then
    CUE="$PROJDIR/external_resources/Daytona USA (USA)/Daytona USA (USA).cue"
elif [ "$DISC_TYPE" = "rebuilt" ]; then
    CUE="$PROJDIR/reimpl/build/disc/rebuilt.cue"
else
    echo "Usage: $0 [vanilla|rebuilt] [seconds]"
    exit 1
fi

WATCH_ADDR="0606367C"

mkdir -p "$IPC_DIR"
rm -f "$ACTION" "$ACK" "$HITLOG"

# Set up mednafen home with firmware symlinks
MDFN_HOME="/tmp/mednafen_wp_home"
mkdir -p "$MDFN_HOME/.mednafen/firmware" "$MDFN_HOME/.mednafen/pgconfig" "$MDFN_HOME/.mednafen/cheats" "$MDFN_HOME/.mednafen/snaps"
for f in sega_101.bin mpr-17933.bin; do
    src="$HOME/.mednafen/firmware/$f"
    dst="$MDFN_HOME/.mednafen/firmware/$f"
    if [ -f "$src" ] && [ ! -L "$dst" ]; then
        ln -sf "$src" "$dst"
    fi
done

echo "=== Watchpoint Test ==="
echo "Disc: $DISC_TYPE"
echo "Watch address: 0x$WATCH_ADDR"
echo "Run time: ${RUN_SECS}s"
echo "Starting Mednafen..."

MEDNAFEN_ALLOWMULTI=1 HOME="$MDFN_HOME" "$MEDNAFEN" --sound 0 --automation "$IPC_DIR" "$CUE" 2>/dev/null &
MDFN_PID=$!

# Wait for ready ack
echo "Waiting for ready..."
for i in $(seq 1 60); do
    if [ -f "$ACK" ] && grep -q "ready" "$ACK" 2>/dev/null; then
        echo "Got: $(cat "$ACK")"
        break
    fi
    sleep 0.5
done

if ! grep -q "ready" "$ACK" 2>/dev/null; then
    echo "FAILED: no ready ack after 30s"
    kill $MDFN_PID 2>/dev/null || true
    exit 1
fi

CMD_SEQ=0
send_cmd() {
    local cmd="$1"
    local desc="$2"
    local timeout="${3:-30}"
    echo "  $desc: $cmd"
    local before_content=""
    [ -f "$ACK" ] && before_content=$(cat "$ACK" 2>/dev/null)
    CMD_SEQ=$((CMD_SEQ + 1))
    local padding=""
    for p in $(seq 1 $((CMD_SEQ % 16))); do padding="${padding}."; done
    printf "# %d%s\n%s\n" "$CMD_SEQ" "$padding" "$cmd" > "$ACTION"
    local max=$((timeout * 10))
    for i in $(seq 1 $max); do
        if [ -f "$ACK" ]; then
            local now_content=$(cat "$ACK" 2>/dev/null)
            if [ "$now_content" != "$before_content" ]; then
                echo "  -> $now_content"
                return 0
            fi
        fi
        sleep 0.1
    done
    echo "  TIMEOUT after ${timeout}s"
    return 1
}

# Set watchpoint immediately (even during BIOS — catches early writes too)
send_cmd "watchpoint $WATCH_ADDR" "Set watchpoint"

# Resume free-running emulation (automation starts paused)
send_cmd "continue" "Resume emulation"

# Let it run
echo ""
echo "Running for ${RUN_SECS}s... (watchpoint hits logged to $HITLOG)"
sleep "$RUN_SECS"

# Check results
echo ""
echo "=== Watchpoint Results ==="
if [ -f "$HITLOG" ]; then
    HITS=$(grep -c "^pc=" "$HITLOG" 2>/dev/null || echo 0)
    echo "Total hits: $HITS"
    echo ""
    cat "$HITLOG"
else
    echo "No hits logged (watchpoint_hits.txt not created)"
fi

# Check emulation progress
send_cmd "status" "Status" 10 || true

# Quit
send_cmd "quit" "Quit" 5 || true
sleep 1
kill $MDFN_PID 2>/dev/null || true
wait $MDFN_PID 2>/dev/null || true

echo ""
echo "=== Done ==="
