#!/bin/bash
# Find newly-compilable functions that are close to matching (delta 0 or +1)
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/close_$$
mkdir -p "$TMPDIR"

extract_opcodes() {
    tr -d '\r' < "$1" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
}

echo "=== Functions with delta=0 (new matches in progress) ==="
delta0=0
delta1=0
delta_m1=0
pass=0
total=0

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TESTDIR/$base.expected"
    [ ! -f "$expected" ] && continue

    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TESTDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    if "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null; then
        extract_opcodes "$TMPDIR/$base.s" > "$TMPDIR/$base.opcodes"
        tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp_clean"

        our_count=$(wc -l < "$TMPDIR/$base.opcodes")
        exp_count=$(wc -l < "$TMPDIR/$base.exp_clean")
        delta=$((our_count - exp_count))

        if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" > /dev/null 2>&1; then
            pass=$((pass + 1))
        elif [ "$delta" -eq 0 ]; then
            diffs=$(diff "$TMPDIR/$base.exp_clean" "$TMPDIR/$base.opcodes" 2>/dev/null | grep '^[<>]' | wc -l)
            echo "DELTA=0  $base  (insns=$our_count, diff_lines=$diffs)"
            delta0=$((delta0 + 1))
        elif [ "$delta" -eq 1 ]; then
            echo "DELTA=+1 $base  (ours=$our_count, orig=$exp_count)"
            delta1=$((delta1 + 1))
        elif [ "$delta" -eq -1 ]; then
            delta_m1=$((delta_m1 + 1))
        fi
        total=$((total + 1))
    fi
done

echo ""
echo "=== Summary ==="
echo "Compilable: $total"
echo "PASS: $pass"
echo "Delta=0: $delta0"
echo "Delta=+1: $delta1"
echo "Delta=-1: $delta_m1"

rm -rf "$TMPDIR"
