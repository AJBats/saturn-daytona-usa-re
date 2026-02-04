#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/cwarn_$$
mkdir -p "$TMPDIR"

# Check a few "warning" files - do they ALSO have errors or crashes?
for base in FUN_060055BC FUN_0600629C FUN_06006CDC FUN_0600AFB2 FUN_0600B6A0; do
    cfile="$SRCDIR/$base.c"
    [ ! -f "$cfile" ] && continue
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")

    echo "=== $base ==="
    "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>&1
    exitcode=$?
    echo "EXIT CODE: $exitcode"
    if [ -f "$TMPDIR/$base.s" ]; then
        lines=$(wc -l < "$TMPDIR/$base.s")
        echo "OUTPUT: $lines lines"
    else
        echo "OUTPUT: NO .s file produced"
    fi
    echo ""
done

rm -rf "$TMPDIR"
