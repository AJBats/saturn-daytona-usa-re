#!/bin/bash
# Detailed analysis of delta=0 failures - show full opcode comparison
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/delta0_analysis

mkdir -p "$TMPDIR"

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expfile="$TDIR/$base.expected"
    [ -f "$expfile" ] || continue

    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TDIR/$base.flags")

    outfile="$TMPDIR/${base}.s"
    tr -d '\r' < "$cfile" > "$TMPDIR/${base}_clean.c"
    $CC1 -quiet $FLAGS "$TMPDIR/${base}_clean.c" -o "$outfile" 2>/dev/null

    ours=$(tr -d '\r' < "$outfile" | grep -P '^\t[a-z]' | awk '{print $1}' | head -100)
    expected=$(tr -d '\r' < "$expfile" | sed '/^$/d')

    our_count=$(echo "$ours" | wc -l)
    exp_count=$(echo "$expected" | wc -l)
    delta=$((our_count - exp_count))

    if [ "$delta" -eq 0 ]; then
        diff_output=$(diff <(echo "$ours") <(echo "$expected"))
        if [ -n "$diff_output" ]; then
            diff_count=$(echo "$diff_output" | grep -c "^[<>]")
            echo "=== $base ($our_count insns, $diff_count opcode diffs) ==="

            # Show full opcodes side-by-side
            paste <(echo "$ours") <(echo "$expected") | awk -F'\t' '{
                n=NR
                our=$1; exp=$2;
                gsub(/^[[:space:]]+/, "", our); gsub(/[[:space:]]+$/, "", our);
                gsub(/^[[:space:]]+/, "", exp); gsub(/[[:space:]]+$/, "", exp);
                if (our != exp)
                    printf "  %2d: %-14s | %-14s  <-- DIFF\n", n, our, exp
                else
                    printf "  %2d: %-14s | %-14s\n", n, our, exp
            }'
            echo ""
        fi
    fi
done
