#!/bin/bash
# Find functions where the diff shows missing extu.w or exts.w
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/extpat_$$
mkdir -p "$TMPDIR"

echo "=== Functions with extu/exts in diff ==="
echo ""

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TDIR/$base.expected"
    [ ! -f "$expected" ] && continue

    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TDIR/$base.flags")

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    $CC1 -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null || continue

    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/$base.opcodes"
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp_clean"

    diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" >/dev/null 2>&1 && continue

    our_count=$(wc -l < "$TMPDIR/$base.opcodes")
    exp_count=$(wc -l < "$TMPDIR/$base.exp_clean")
    delta=$((our_count - exp_count))

    # Check if diff involves extu or exts
    diffs=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" 2>/dev/null)
    if echo "$diffs" | grep -q 'ext'; then
        echo "$base  delta=$delta  (ours=$our_count exp=$exp_count)"
        echo "$diffs" | grep '^[<>]' | head -8
        echo ""
    fi
done

rm -rf "$TMPDIR"
