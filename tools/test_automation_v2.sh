#!/bin/bash
# Quick test of v2 automation commands: blocking pause, dump_regs_bin, pc_trace_frame
# Run from WSL: bash tools/test_automation_v2.sh

set -e

PROJDIR="/mnt/d/Projects/SaturnReverseTest"
MEDNAFEN="$PROJDIR/mednafen/src/mednafen"
CUE="$PROJDIR/external_resources/Daytona USA (USA)/Daytona USA (USA).cue"
IPC_DIR="/tmp/emu_test"
ACTION="$IPC_DIR/mednafen_action.txt"
ACK="$IPC_DIR/mednafen_ack.txt"

mkdir -p "$IPC_DIR"
rm -f "$ACTION" "$ACK"

# Set up mednafen home with firmware symlinks
MDFN_HOME="/tmp/mednafen_test_home"
mkdir -p "$MDFN_HOME/.mednafen/firmware" "$MDFN_HOME/.mednafen/pgconfig" "$MDFN_HOME/.mednafen/cheats" "$MDFN_HOME/.mednafen/snaps"
for f in sega_101.bin mpr-17933.bin; do
    src="$HOME/.mednafen/firmware/$f"
    dst="$MDFN_HOME/.mednafen/firmware/$f"
    if [ -f "$src" ] && [ ! -L "$dst" ]; then
        ln -sf "$src" "$dst"
    fi
done

echo "=== Starting Mednafen with automation ==="
HOME="$MDFN_HOME" "$MEDNAFEN" --sound 0 --automation "$IPC_DIR" "$CUE" 2>/dev/null &
MDFN_PID=$!

# Wait for ready ack
echo "Waiting for ready ack..."
for i in $(seq 1 60); do
    if [ -f "$ACK" ] && grep -q "ready" "$ACK" 2>/dev/null; then
        echo "Got: $(cat "$ACK")"
        break
    fi
    sleep 0.5
done

# Wait a bit for game loop to actually start (video init takes time)
echo "Waiting for game loop to start..."
sleep 5

send_cmd() {
    local cmd="$1"
    local desc="$2"
    echo ""
    echo "=== $desc ==="
    echo "Sending: $cmd"
    # Record current ack content
    local before_content=""
    [ -f "$ACK" ] && before_content=$(cat "$ACK" 2>/dev/null)
    # Write command
    echo "$cmd" > "$ACTION"
    # Wait for ack content to change
    for i in $(seq 1 120); do
        if [ -f "$ACK" ]; then
            local now_content=$(cat "$ACK" 2>/dev/null)
            if [ "$now_content" != "$before_content" ]; then
                echo "Ack: $now_content"
                return 0
            fi
        fi
        sleep 0.1
    done
    echo "TIMEOUT waiting for ack (last: $before_content)"
    return 1
}

# Test 1: Pause
send_cmd "pause" "Test pause (blocking)"

# Test 2: Frame advance 1 (should block after 1 frame)
send_cmd "frame_advance 1" "Test frame_advance 1"

# Test 3: dump_regs (text)
send_cmd "dump_regs" "Test dump_regs (text)"

# Test 4: dump_regs_bin
send_cmd "dump_regs_bin $IPC_DIR/regs.bin" "Test dump_regs_bin"
if [ -f "$IPC_DIR/regs.bin" ]; then
    SIZE=$(wc -c < "$IPC_DIR/regs.bin")
    echo "Binary regs file: $SIZE bytes (expected 88)"
    xxd "$IPC_DIR/regs.bin" | head -6
fi

# Test 5: Frame advance 5 then check status
send_cmd "frame_advance 5" "Test frame_advance 5"
send_cmd "status" "Test status after 5 frames"

# Test 6: pc_trace_frame
send_cmd "pc_trace_frame $IPC_DIR/trace.bin" "Test pc_trace_frame"
if [ -f "$IPC_DIR/trace.bin" ]; then
    SIZE=$(wc -c < "$IPC_DIR/trace.bin")
    INSTRS=$((SIZE / 4))
    echo "PC trace file: $SIZE bytes = $INSTRS instructions"
    echo "First PCs (hex):"
    xxd "$IPC_DIR/trace.bin" | head -4
fi

# Test 7: dump_mem_bin
send_cmd "dump_mem_bin 06003000 100 $IPC_DIR/mem.bin" "Test dump_mem_bin"
if [ -f "$IPC_DIR/mem.bin" ]; then
    SIZE=$(wc -c < "$IPC_DIR/mem.bin")
    echo "Memory dump: $SIZE bytes"
    xxd "$IPC_DIR/mem.bin" | head -4
fi

# Cleanup
send_cmd "quit" "Quit"
sleep 1
kill $MDFN_PID 2>/dev/null || true
wait $MDFN_PID 2>/dev/null || true

echo ""
echo "=== All tests complete ==="
