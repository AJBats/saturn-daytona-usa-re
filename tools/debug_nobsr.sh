#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

for func in FUN_060210F6 FUN_06041180 FUN_06041330 FUN_0601FD20 FUN_0600A4AA; do
    cfile="$SRCDIR/$func.c"
    [ -f "$cfile" ] || continue

    FLAGS="-O2 -m2"  # NO -mbsr

    echo "=== $func (flags: $FLAGS) ==="

    TMPFILE="/tmp/${func}.s"
    $CC1 -quiet $FLAGS "$cfile" -o "$TMPFILE" 2>/dev/null

    # Extract opcodes
    OUR=$(tr -d '\r' < "$TMPFILE" | grep -P '^\t[a-z]' | sed 's/^[[:space:]]*//' | awk '{print $1}')
    EXP=$(tr -d '\r' < "$TDIR/$func.expected" | sed '/^$/d')

    echo "OURS: $(echo "$OUR" | wc -l) insns    EXPECTED: $(echo "$EXP" | wc -l) insns"

    # Show diff
    DIFF=$(diff <(echo "$OUR") <(echo "$EXP"))
    if [ -z "$DIFF" ]; then
        echo "*** MATCH! ***"
    else
        echo "$DIFF"
    fi
    echo ""
done
