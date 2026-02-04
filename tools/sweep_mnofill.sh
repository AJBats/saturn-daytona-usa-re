#!/bin/bash
# Try -mnofill on all failing functions to find potential new PASSes
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

new_pass=0
improved=0

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expfile="$TDIR/$base.expected"
    [ -f "$expfile" ] || continue

    expected=$(tr -d '\r' < "$expfile" | sed '/^$/d')
    exp_count=$(echo "$expected" | wc -l)

    # Try several flag combos
    for flags in "-O2 -m2 -mnofill" "-O2 -m2 -mbsr -mnofill" "-O2 -m2 -mnofill -mnosignext" "-O2 -m2 -mbsr -mnofill -mnosignext"; do
        TMPFILE="/tmp/${base}_sweep.s"
        $CC1 -quiet $flags "$cfile" -o "$TMPFILE" 2>/dev/null || continue

        our=$(tr -d '\r' < "$TMPFILE" | grep -P '^\t[a-z]' | sed 's/^[[:space:]]*//' | awk '{print $1}')
        our_count=$(echo "$our" | wc -l)

        # Compare
        if [ "$(echo "$our")" = "$(echo "$expected")" ]; then
            # Check if already passing with default flags
            DEFAULT_FLAGS="-O2 -m2 -mbsr"
            if [ -f "$TDIR/$base.flags" ]; then
                DEFAULT_FLAGS=$(tr -d '\r' < "$TDIR/$base.flags")
            fi
            $CC1 -quiet $DEFAULT_FLAGS "$cfile" -o /tmp/${base}_default.s 2>/dev/null
            default_our=$(tr -d '\r' < /tmp/${base}_default.s | grep -P '^\t[a-z]' | sed 's/^[[:space:]]*//' | awk '{print $1}')
            if [ "$(echo "$default_our")" != "$(echo "$expected")" ]; then
                echo "NEW PASS: $base  flags=[$flags]  ($exp_count insns)"
                new_pass=$((new_pass + 1))
            fi
            break  # No need to try more flag combos
        fi
    done
done

echo ""
echo "=== Found $new_pass potential new PASSes ==="
