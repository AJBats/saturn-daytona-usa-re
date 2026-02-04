#!/bin/bash
# Extract full asm for specific functions from aprog.s
APROG=/mnt/d/Projects/SaturnReverseTest/build/aprog.s

for func in FUN_0601A5F8 FUN_06018634 FUN_06026E02 FUN_060270C6 FUN_0604249C FUN_06035C08 FUN_0602EFDA FUN_06032530 FUN_06033338 FUN_060333A4; do
    echo "=== $func ==="
    tr -d '\r' < "$APROG" | sed -n "/^${func}:/,/^FUN_[0-9A-F]\|^[a-z_]*:/p" | head -30
    echo ""
done
