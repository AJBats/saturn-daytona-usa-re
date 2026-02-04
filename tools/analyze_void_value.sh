#!/bin/bash
# Analyze remaining void_value errors to find sub-patterns
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/void_analyze_$$
mkdir -p "$TMPDIR"

count=0
# Check a sample of void_value functions
while IFS=$'\t' read -r name rest; do
    [ "$count" -ge 20 ] && break
    cfile="$SRCDIR/$name.c"
    [ ! -f "$cfile" ] && continue

    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TESTDIR/$name.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$name.flags")

    tr -d '\r' < "$cfile" > "$TMPDIR/$name.c"
    "$CC1" -quiet $FLAGS "$TMPDIR/$name.c" -o "$TMPDIR/$name.s" 2>"$TMPDIR/$name.err"

    if grep -q "void value not ignored" "$TMPDIR/$name.err"; then
        echo "=== $name ==="
        # Show the offending line
        grep "void value" "$TMPDIR/$name.err" | head -2 | while read line; do
            lineno=$(echo "$line" | grep -oP ':\K[0-9]+(?=:)')
            echo "  $line"
            if [ -n "$lineno" ]; then
                sed -n "${lineno}p" "$TMPDIR/$name.c" | sed 's/^/  >> /'
            fi
        done
        echo ""
        count=$((count + 1))
    fi
done < <(grep "void_value" /mnt/d/Projects/SaturnReverseTest/docs/catalog_raw.tsv)

rm -rf "$TMPDIR"
