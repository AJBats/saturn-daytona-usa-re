#!/bin/bash
# Extract and compare opcodes for delta=0 functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

for F in FUN_06011494 FUN_06026E0C FUN_060270D0 FUN_060285E0 FUN_06028600 FUN_0603C0A0; do
    echo "=== $F ==="

    # Compile
    tr -d '\r' < "$TDIR/$F.c" > /tmp/$F.c
    $CC1 -quiet -O2 -m2 -mbsr /tmp/$F.c -o /tmp/$F.s 2>/dev/null

    echo "--- OURS ---"
    grep -P '^\t[a-z]' /tmp/$F.s | awk '{print $1}' | sed 's/,$//' | tr -d '\r'

    echo "--- EXPECTED ---"
    tr -d '\r' < "$TDIR/$F.expected" | sed '/^$/d'

    echo "--- FULL ASM ---"
    grep -P '^\t[a-z]' /tmp/$F.s | tr -d '\r'

    echo ""
done
