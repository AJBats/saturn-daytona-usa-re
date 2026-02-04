#!/bin/bash
# Categorize all failures by delta and diff type
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/catfail_$$
mkdir -p "$TMPDIR"

echo "=== FAILURE CATEGORIZATION ==="
echo ""

pos_delta=""
neg_delta=""
zero_delta=""

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

    if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" >/dev/null 2>&1; then
        continue  # PASS
    fi

    our_count=$(wc -l < "$TMPDIR/$base.opcodes")
    exp_count=$(wc -l < "$TMPDIR/$base.exp_clean")
    delta=$((our_count - exp_count))

    # Get first 3 diff lines showing the pattern
    difflines=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" 2>/dev/null | grep '^[<>]' | head -6 | tr '\n' ' ')

    if [ "$delta" -gt 0 ]; then
        pos_delta="$pos_delta$base delta=+$delta (ours=$our_count exp=$exp_count) $difflines\n"
    elif [ "$delta" -lt 0 ]; then
        neg_delta="$neg_delta$base delta=$delta (ours=$our_count exp=$exp_count) $difflines\n"
    else
        zero_delta="$zero_delta$base delta=0 (ours=$our_count exp=$exp_count) $difflines\n"
    fi
done

echo "=== DELTA > 0 (our code LONGER — C fixes or compiler patches needed) ==="
echo -e "$pos_delta" | sort -t= -k2 -rn
echo ""
echo "=== DELTA = 0 (same count, opcode ordering/selection diffs) ==="
echo -e "$zero_delta"
echo ""
echo "=== DELTA < 0 (our code SHORTER — need per-function flags or compiler config) ==="
echo -e "$neg_delta" | sort -t= -k2 -n
echo ""

pos_count=$(echo -e "$pos_delta" | grep -c 'FUN_')
neg_count=$(echo -e "$neg_delta" | grep -c 'FUN_')
zero_count=$(echo -e "$zero_delta" | grep -c 'FUN_')
echo "=== Summary: $pos_count delta>0, $zero_count delta=0, $neg_count delta<0 ==="

rm -rf "$TMPDIR"
