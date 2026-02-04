#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/rerr_$$
mkdir -p "$TMPDIR"

> "$TMPDIR/all_real_errors.txt"

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")

    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if [ $? -ne 0 ]; then
        # Get actual error line (not "In function" context)
        real_err=$(echo "$errout" | grep -v "In function" | grep -v "^$" | head -1 | sed 's|^[^:]*:[0-9]*: ||')
        echo "$base: $real_err" >> "$TMPDIR/all_real_errors.txt"
    fi
done

echo "=== ERROR CATEGORIES ==="
sed 's/^[^:]*: //' "$TMPDIR/all_real_errors.txt" | sed "s/\`[^']*'/\`...'/g" | sort | uniq -c | sort -rn | head -30

echo ""
echo "=== RAW ERRORS (first 50) ==="
head -50 "$TMPDIR/all_real_errors.txt"

rm -rf "$TMPDIR"
