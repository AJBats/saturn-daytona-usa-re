#!/bin/bash
# Analyze delta=+1 functions to find potential fixes
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expfile="$TDIR/$base.expected"
    [ -f "$expfile" ] || continue

    FLAGS="-O2 -m2 -mbsr"
    if [ -f "$TDIR/$base.flags" ]; then
        FLAGS=$(tr -d '\r' < "$TDIR/$base.flags")
    fi

    expected=$(tr -d '\r' < "$expfile" | sed '/^$/d')
    exp_count=$(echo "$expected" | wc -l)

    TMPFILE="/tmp/${base}.s"
    $CC1 -quiet $FLAGS "$cfile" -o "$TMPFILE" 2>/dev/null || continue

    our=$(tr -d '\r' < "$TMPFILE" | grep -P '^\t[a-z]' | sed 's/^[[:space:]]*//' | awk '{print $1}')
    our_count=$(echo "$our" | wc -l)

    delta=$((our_count - exp_count))

    if [ "$delta" -eq 1 ]; then
        echo "================================================================"
        echo "=== $base  (ours=$our_count orig=$exp_count delta=+1) ==="
        echo "================================================================"
        diff <(echo "$our") <(echo "$expected")
        echo ""
    fi
done
