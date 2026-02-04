#!/bin/bash
# BSR Experiment: Compare output with and without -mbsr
# Find functions that improve or flip to PASS when compiled without BSR
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/bsr_exp_$$
mkdir -p "$TMPDIR"

echo "=== BSR EXPERIMENT: with -mbsr vs without ==="
echo ""

new_pass=0
improved=0
regressed=0

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TDIR/$base.expected"
    [ ! -f "$expected" ] && continue

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    # Compile WITH -mbsr (default)
    $CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/$base.c" -o "$TMPDIR/${base}_bsr.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/${base}_bsr.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_bsr.ops"

    # Compile WITHOUT -mbsr
    $CC1 -quiet -O2 -m2 "$TMPDIR/$base.c" -o "$TMPDIR/${base}_nobsr.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/${base}_nobsr.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_nobsr.ops"

    # Normalize expected
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/${base}_exp.ops"

    # Check matches
    bsr_match="FAIL"
    nobsr_match="FAIL"
    diff -q "$TMPDIR/${base}_bsr.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1 && bsr_match="PASS"
    diff -q "$TMPDIR/${base}_nobsr.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1 && nobsr_match="PASS"

    bsr_count=$(wc -l < "$TMPDIR/${base}_bsr.ops")
    nobsr_count=$(wc -l < "$TMPDIR/${base}_nobsr.ops")
    exp_count=$(wc -l < "$TMPDIR/${base}_exp.ops")

    bsr_diffs=$(diff "$TMPDIR/${base}_bsr.ops" "$TMPDIR/${base}_exp.ops" 2>/dev/null | grep -c '^[<>]')
    nobsr_diffs=$(diff "$TMPDIR/${base}_nobsr.ops" "$TMPDIR/${base}_exp.ops" 2>/dev/null | grep -c '^[<>]')

    # Report interesting cases
    if [ "$bsr_match" = "FAIL" ] && [ "$nobsr_match" = "PASS" ]; then
        echo "*** NEW PASS  $base  (bsr=$bsr_count nobsr=$nobsr_count exp=$exp_count)"
        new_pass=$((new_pass + 1))
    elif [ "$bsr_match" = "PASS" ] && [ "$nobsr_match" = "FAIL" ]; then
        echo "!!! REGRESS   $base  (would lose PASS without -mbsr)"
        regressed=$((regressed + 1))
    elif [ "$bsr_match" = "FAIL" ] && [ "$nobsr_match" = "FAIL" ]; then
        if [ "$nobsr_diffs" -lt "$bsr_diffs" ]; then
            echo "+++ BETTER    $base  diffs: $bsr_diffs -> $nobsr_diffs  (bsr=$bsr_count nobsr=$nobsr_count exp=$exp_count)"
            improved=$((improved + 1))
        elif [ "$nobsr_diffs" -gt "$bsr_diffs" ]; then
            echo "--- WORSE     $base  diffs: $bsr_diffs -> $nobsr_diffs  (bsr=$bsr_count nobsr=$nobsr_count exp=$exp_count)"
        fi
    fi
done

rm -rf "$TMPDIR"
echo ""
echo "=== Summary: $new_pass new PASS, $improved improved, $regressed would regress ==="
