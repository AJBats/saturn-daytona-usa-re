#!/bin/bash
# Find .expected files that don't have corresponding .c source files
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

untested=0
small_untested=0

for exp in "$TDIR"/*.expected; do
    base=$(basename "$exp" .expected)
    cfile="$SRCDIR/$base.c"

    if [ ! -f "$cfile" ]; then
        count=$(tr -d '\r' < "$exp" | sed '/^$/d' | wc -l)
        if [ "$count" -le 10 ]; then
            echo "SMALL  $base  ($count insns)"
            small_untested=$((small_untested + 1))
        fi
        untested=$((untested + 1))
    fi
done

echo ""
echo "=== Summary: $untested untested functions with .expected files, $small_untested with <=10 insns ==="
