#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

for func in FUN_06014A42 FUN_060210F6 FUN_06041180 FUN_06041330 FUN_0601FD20 FUN_0600A4AA; do
    cfile="$SRCDIR/$func.c"
    [ -f "$cfile" ] || continue

    # Get flags
    FLAGS="-O2 -m2 -mbsr"
    if [ -f "$TDIR/$func.flags" ]; then
        FLAGS=$(tr -d '\r' < "$TDIR/$func.flags")
    fi

    echo "================================================================"
    echo "=== $func (flags: $FLAGS) ==="
    echo "================================================================"

    # Compile
    TMPFILE="/tmp/${func}.s"
    $CC1 -quiet $FLAGS "$cfile" -o "$TMPFILE" 2>/dev/null

    echo "--- OUR OUTPUT ---"
    tr -d '\r' < "$TMPFILE" | grep -P '^\t[a-z]' | sed 's/^[[:space:]]*//'
    echo ""

    echo "--- EXPECTED ---"
    tr -d '\r' < "$TDIR/$func.expected" | sed '/^$/d'
    echo ""

    # Show diff
    OUR=$(tr -d '\r' < "$TMPFILE" | grep -P '^\t[a-z]' | sed 's/^[[:space:]]*//' | awk '{print $1}')
    EXP=$(tr -d '\r' < "$TDIR/$func.expected" | sed '/^$/d')
    echo "--- DIFF (opcode only) ---"
    diff <(echo "$OUR") <(echo "$EXP")
    echo ""
done
