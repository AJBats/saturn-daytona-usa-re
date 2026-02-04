#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/callerr_$$
mkdir -p "$TMPDIR"

for cfile in "$SRCDIR"/FUN_06003578.c "$SRCDIR"/FUN_060038d4.c "$SRCDIR"/FUN_06004a98.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    echo "=== $base ==="
    "$CC1" -quiet -O2 -m2 -mbsr "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>&1 | grep -v warning | head -5
    echo ""
done
rm -rf "$TMPDIR"
