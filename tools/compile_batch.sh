#!/bin/bash
# Compile all 8 functions and show outputs
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src

FUNCS="FUN_06018EC8 FUN_0601DB84 FUN_06027358 FUN_0602E5E4 FUN_06038F34 FUN_0603B878 FUN_0603F4E0 FUN_0603F500"

for func in $FUNCS; do
    echo "========================================"
    echo "  $func"
    echo "========================================"
    tr -d '\r' < "$SRCDIR/$func.c" > "/tmp/$func.c"
    if $CC1 -quiet -O2 -m2 -mbsr "/tmp/$func.c" -o "/tmp/$func.s" 2>"/tmp/$func.err"; then
        cat "/tmp/$func.s"
        echo ""
        echo "--- OPCODES ---"
        grep -P '^\t[a-z]' "/tmp/$func.s" | awk '{print $1}' | sed 's/,$//'
        echo "--- END ---"
    else
        echo "COMPILE ERROR:"
        cat "/tmp/$func.err"
    fi
    echo ""
done
