#!/bin/bash
# Exhaustive flag sweep: try many flag combinations on all failing functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/flagsweep_$$
mkdir -p "$TMPDIR"

# Define all flag combinations to try
FLAG_COMBOS=(
    "-O2 -m2 -mbsr"
    "-O2 -m2"
    "-O2 -m2 -mnofill"
    "-O2 -m2 -mbsr -mnofill"
    "-O2 -m2 -mno-rts-fill"
    "-O2 -m2 -mbsr -mno-rts-fill"
    "-O2 -m2 -mnosignext"
    "-O2 -m2 -mbsr -mnosignext"
    "-O2 -m2 -mno-bsr-fill"
    "-O2 -m2 -mbsr -mno-bsr-fill"
    "-O2 -m2 -mnofill -mno-rts-fill"
    "-O2 -m2 -mbsr -mnofill -mno-rts-fill"
    "-O2 -m2 -mnofill -mnosignext"
    "-O2 -m2 -mbsr -mnofill -mnosignext"
    "-O2 -m2 -mno-rts-fill -mnosignext"
    "-O2 -m2 -mbsr -mno-rts-fill -mnosignext"
    "-O2 -m2 -mnofill -mno-rts-fill -mnosignext"
    "-O2 -m2 -mbsr -mnofill -mno-rts-fill -mnosignext"
    "-O2 -m2 -mbsr -mno-bsr-fill -mno-rts-fill"
    "-O2 -m2 -mbsr -mno-bsr-fill -mnofill"
    "-O2 -m2 -mbsr -mno-bsr-fill -mno-rts-fill -mnofill"
    "-O2 -m2 -mbsr -mno-bsr-fill -mno-rts-fill -mnofill -mnosignext"
    "-O1 -m2 -mbsr"
    "-O1 -m2"
)

echo "=== EXHAUSTIVE FLAG SWEEP ==="
echo "Testing ${#FLAG_COMBOS[@]} flag combinations on all failing functions"
echo ""

new_passes=0

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TDIR/$base.expected"
    [ ! -f "$expected" ] && continue

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp_clean"

    # Check if it already passes with current flags
    CUR_FLAGS="-O2 -m2 -mbsr"
    [ -f "$TDIR/$base.flags" ] && CUR_FLAGS=$(tr -d '\r' < "$TDIR/$base.flags")
    $CC1 -quiet $CUR_FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/$base.opcodes"
    diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" >/dev/null 2>&1 && continue

    # Try each flag combo
    best_flags=""
    best_diffs=999
    cur_diffs=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" 2>/dev/null | grep -c '^[<>]')

    for flags in "${FLAG_COMBOS[@]}"; do
        $CC1 -quiet $flags "$TMPDIR/$base.c" -o "$TMPDIR/${base}_test.s" 2>/dev/null || continue
        tr -d '\r' < "$TMPDIR/${base}_test.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_test.opcodes"

        if diff -q "$TMPDIR/${base}_test.opcodes" "$TMPDIR/$base.exp_clean" >/dev/null 2>&1; then
            echo "*** PASS  $base  flags: $flags"
            new_passes=$((new_passes + 1))
            best_flags="$flags"
            best_diffs=0
            break
        fi

        ndiffs=$(diff "$TMPDIR/${base}_test.opcodes" "$TMPDIR/$base.exp_clean" 2>/dev/null | grep -c '^[<>]')
        if [ "$ndiffs" -lt "$best_diffs" ]; then
            best_diffs=$ndiffs
            best_flags="$flags"
        fi
    done

    if [ "$best_diffs" -gt 0 ] && [ "$best_diffs" -lt "$cur_diffs" ]; then
        echo "+++ BETTER  $base  diffs: $cur_diffs -> $best_diffs  flags: $best_flags"
    fi
done

rm -rf "$TMPDIR"
echo ""
echo "=== Summary: $new_passes new PASSes found ==="
