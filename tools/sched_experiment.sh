#!/bin/bash
# Stage 2: Scheduling experiment — compare with/without -fno-schedule-insns2
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/sched_exp_$$
mkdir -p "$TMPDIR"

echo "=== SCHEDULING EXPERIMENT: -fno-schedule-insns2 ==="
echo ""

for cfile in "$TDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TDIR/$base.expected"
    [ ! -f "$expected" ] && continue

    # Strip CRLF from source
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    # Compile WITH sched2 (default -O2 behavior)
    $CC1 -quiet -O2 -m2 -mbsr "$TMPDIR/$base.c" -o "$TMPDIR/${base}_sched.s" 2>/dev/null
    tr -d '\r' < "$TMPDIR/${base}_sched.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_sched.ops"

    # Compile WITHOUT sched2
    $CC1 -quiet -O2 -m2 -mbsr -fno-schedule-insns2 "$TMPDIR/$base.c" -o "$TMPDIR/${base}_nosched.s" 2>/dev/null
    tr -d '\r' < "$TMPDIR/${base}_nosched.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_nosched.ops"

    # Normalize expected
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/${base}_exp.ops"

    # Check matches
    sched_match="FAIL"
    nosched_match="FAIL"
    diff -q "$TMPDIR/${base}_sched.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1 && sched_match="PASS"
    diff -q "$TMPDIR/${base}_nosched.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1 && nosched_match="PASS"

    sched_count=$(wc -l < "$TMPDIR/${base}_sched.ops")
    nosched_count=$(wc -l < "$TMPDIR/${base}_nosched.ops")
    exp_count=$(wc -l < "$TMPDIR/${base}_exp.ops")

    # Check if output changed
    changed=""
    diff -q "$TMPDIR/${base}_sched.ops" "$TMPDIR/${base}_nosched.ops" >/dev/null 2>&1 || changed="CHANGED"

    if [ "$sched_match" != "$nosched_match" ]; then
        echo "*** $base: sched=$sched_match nosched=$nosched_match (s=$sched_count ns=$nosched_count exp=$exp_count) <<< STATUS CHANGE"
    elif [ -n "$changed" ]; then
        sched_diffs=$(diff "$TMPDIR/${base}_sched.ops" "$TMPDIR/${base}_exp.ops" 2>/dev/null | grep -c '^[<>]')
        nosched_diffs=$(diff "$TMPDIR/${base}_nosched.ops" "$TMPDIR/${base}_exp.ops" 2>/dev/null | grep -c '^[<>]')
        echo "~~~ $base: sched=FAIL($sched_diffs) nosched=FAIL($nosched_diffs) (s=$sched_count ns=$nosched_count exp=$exp_count) CHANGED"
        # Show the actual diff between sched and nosched
        diff "$TMPDIR/${base}_sched.ops" "$TMPDIR/${base}_nosched.ops" | head -8
        echo ""
    else
        echo "    $base: $sched_match (unchanged)"
    fi
done

rm -rf "$TMPDIR"
echo ""
echo "=== DONE ==="
