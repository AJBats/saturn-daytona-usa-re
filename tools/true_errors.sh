#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/terr_$$
mkdir -p "$TMPDIR"

> "$TMPDIR/all_true_errors.txt"
> "$TMPDIR/crash_files.txt"
> "$TMPDIR/error_files.txt"
> "$TMPDIR/warn_only_files.txt"

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")

    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>&1)
    exitcode=$?
    if [ $exitcode -ne 0 ]; then
        # Check if cc1 crashed (exit >= 128 means signal)
        if [ $exitcode -ge 128 ]; then
            # Find the internal error line
            ice=$(echo "$errout" | grep -m1 "internal error\|Aborted\|Segmentation")
            echo "$base: CRASH($exitcode): $ice" >> "$TMPDIR/crash_files.txt"
        fi

        # Find first actual ERROR (not warning, not "In function")
        real_error=$(echo "$errout" | grep -v "In function" | grep -v "^$" | grep -v "^.*: warning:" | head -1 | sed 's|^[^:]*:[0-9]*: ||')

        if [ -n "$real_error" ]; then
            echo "$base: $real_error" >> "$TMPDIR/error_files.txt"
        else
            # Only warnings, no real errors - but still failed
            echo "$base: exit=$exitcode" >> "$TMPDIR/warn_only_files.txt"
        fi

        # Capture the real category
        if [ -n "$real_error" ]; then
            echo "$base: $real_error" >> "$TMPDIR/all_true_errors.txt"
        else
            echo "$base: WARN_ONLY(exit=$exitcode)" >> "$TMPDIR/all_true_errors.txt"
        fi
    fi
done

echo "=== TRUE ERROR CATEGORIES (excluding warnings) ==="
sed 's/^[^:]*: //' "$TMPDIR/all_true_errors.txt" | sed "s/\`[^']*'/\`...'/g" | sort | uniq -c | sort -rn

echo ""
echo "=== CRASH FILES (cc1 ICE/abort) ==="
wc -l < "$TMPDIR/crash_files.txt"
cat "$TMPDIR/crash_files.txt"

echo ""
echo "=== WARN-ONLY FILES (warnings but no errors, yet exit!=0) ==="
wc -l < "$TMPDIR/warn_only_files.txt"
cat "$TMPDIR/warn_only_files.txt"

rm -rf "$TMPDIR"
