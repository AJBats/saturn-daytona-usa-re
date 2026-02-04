#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/chkc_$$
mkdir -p "$TMPDIR"

count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "called object is not a function"; then
        echo "=== $base ==="
        lineno=$(echo "$errout" | grep "called object" | head -1 | sed 's/^[^:]*:\([0-9]*\):.*/\1/')
        echo "  ERROR LINE: $lineno"
        echo "  CONTENT: $(sed -n "${lineno}p" "$TMPDIR/$base.c")"
        # Show a few lines of context
        start=$((lineno - 2))
        [ $start -lt 1 ] && start=1
        end=$((lineno + 2))
        sed -n "${start},${end}p" "$TMPDIR/$base.c" | while IFS= read -r line; do
            echo "    $line"
        done
        echo ""
        count=$((count + 1))
        [ $count -ge 10 ] && break
    fi
done

echo "Total: $count files with 'called object is not a function'"
rm -rf "$TMPDIR"
