#!/bin/bash
# Analyze all delta=-1 functions to find what we're missing
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/dm1_$$
mkdir -p "$TMPDIR"

echo "=== DELTA=-1 DETAILED ANALYSIS ==="
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

    [ "$delta" -ne -1 ] && continue

    # What extra instruction does expected have that we don't?
    extra_in_exp=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" | grep '^>' | head -3)
    missing_in_ours=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" | grep '^<' | head -3)

    # Full diff context
    fulldiff=$(diff -u "$TMPDIR/$base.exp_clean" "$TMPDIR/$base.opcodes" | grep '^[+-][a-z]')

    echo "$base  flags=[$FLAGS]"
    echo "  Our extra: $missing_in_ours"
    echo "  Exp extra: $extra_in_exp"
    echo "  Diff: $fulldiff"
    echo ""
done

rm -rf "$TMPDIR"
