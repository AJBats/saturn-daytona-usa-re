#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/caterr_$$
mkdir -p "$TMPDIR"

total=0
ok=0
fail=0

# Collect all errors
> "$TMPDIR/all_errors.txt"
> "$TMPDIR/fail_files.txt"

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    
    total=$((total + 1))
    
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if [ $? -ne 0 ]; then
        fail=$((fail + 1))
        echo "$base" >> "$TMPDIR/fail_files.txt"
        # Get just the first error per file
        first_err=$(echo "$errout" | head -1 | sed 's|^[^:]*:[0-9]*: ||')
        echo "$base: $first_err" >> "$TMPDIR/all_errors.txt"
    else
        ok=$((ok + 1))
    fi
done

echo "=== COMPILE STATS ==="
echo "Total: $total"
echo "OK: $ok"
echo "FAIL: $fail"
echo ""

echo "=== ERROR CATEGORIES (first error per file) ==="
# Extract just the error message pattern and count
cat "$TMPDIR/all_errors.txt" | sed 's/^[^:]*: //' | sort | uniq -c | sort -rn | head -30

echo ""
echo "=== DETAILED: void value not ignored ==="
grep "void value" "$TMPDIR/all_errors.txt" | head -20

echo ""
echo "=== DETAILED: invalid type argument ==="
grep "invalid type" "$TMPDIR/all_errors.txt" | head -20

echo ""
echo "=== DETAILED: parse error ==="
grep "parse error" "$TMPDIR/all_errors.txt" | head -20

echo ""
echo "=== DETAILED: undeclared ==="
grep "undeclared" "$TMPDIR/all_errors.txt" | head -20

echo ""
echo "=== DETAILED: internal compiler error ==="
grep -i "internal\|abort\|signal" "$TMPDIR/all_errors.txt" | head -20

echo ""
echo "=== DETAILED: subscripted value ==="
grep "subscripted" "$TMPDIR/all_errors.txt" | head -20

rm -rf "$TMPDIR"
