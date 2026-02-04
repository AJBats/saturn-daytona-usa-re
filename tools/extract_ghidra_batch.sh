#!/bin/bash
# Extract Ghidra decomps for candidate functions
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt

for func in FUN_060359d2 FUN_06026e02 FUN_060270c6 FUN_060359da FUN_06018634 FUN_0601a5f8 FUN_06035c08 FUN_06035e90 FUN_06035f04 FUN_0602a134 FUN_0602a754 FUN_0602b8dc FUN_0602c380 FUN_0602e450 FUN_0601ebda FUN_0602834a FUN_0602efcc FUN_060192ca; do
    LINE=$(grep -n "^FUNC $func " "$GHIDRA" | head -1 | cut -d: -f1)
    if [ -z "$LINE" ]; then
        echo "=== $func === NOT FOUND"
        continue
    fi
    ENDLINE=$(tail -n +$((LINE+1)) "$GHIDRA" | grep -n "^FUNC " | head -1 | cut -d: -f1)
    if [ -z "$ENDLINE" ]; then
        ENDLINE=40
    fi
    echo "=== $func ==="
    sed -n "${LINE},$((LINE+ENDLINE-1))p" "$GHIDRA" | tr -d '\r'
    echo ""
done
