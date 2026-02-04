#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/svoid_$$
mkdir -p "$TMPDIR"

count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -q "void value not ignored"; then
        count=$((count + 1))
        echo "=== $base ==="
        # Show the specific error lines
        echo "$errout" | grep "void value" | head -3
        # Show what's on that line in the source
        for lineno in $(echo "$errout" | grep "void value" | head -3 | sed 's/^[^:]*:\([0-9]*\):.*/\1/'); do
            echo "  LINE $lineno: $(sed -n "${lineno}p" "$TMPDIR/$base.c")"
        done
        echo ""
        if [ $count -ge 15 ]; then
            break
        fi
    fi
done

echo "Showed $count files with void value errors"
rm -rf "$TMPDIR"
