#!/bin/bash
# Detailed diff for specific delta=-1 functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/dm1d_$$
mkdir -p "$TMPDIR"

for base in FUN_0603B734 FUN_06042BEE FUN_06042BBE FUN_0603EF54 FUN_06018E70 FUN_06040964 FUN_0602755C FUN_0603F520; do
    echo "=== $base ==="
    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TDIR/$base.flags")
    echo "flags: $FLAGS"

    tr -d '\r' < "$SRCDIR/$base.c" > "$TMPDIR/$base.c"
    $CC1 -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null

    echo "Our asm:"
    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]'
    echo ""
    echo "Expected:"
    tr -d '\r' < "$TDIR/$base.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|'
    echo ""
    echo "---"
    echo ""
done

rm -rf "$TMPDIR"
