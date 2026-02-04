#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/ice_$$
mkdir -p "$TMPDIR"

# Known ICE files
ICE_FILES="FUN_060055BC FUN_06006CDC FUN_0600B914 FUN_0600CD40 FUN_0600E7C8 FUN_0600EA18 FUN_06016DD8 FUN_06017814"

> "$TMPDIR/ice_patterns.txt"

for base in $ICE_FILES; do
    cfile="$SRCDIR/$base.c"
    [ ! -f "$cfile" ] && continue
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    echo "=== $base ===" >> "$TMPDIR/ice_patterns.txt"
    echo "$errout" | grep -A5 "internal error\|unrecognizable" >> "$TMPDIR/ice_patterns.txt"
    echo "" >> "$TMPDIR/ice_patterns.txt"
done

echo "=== ICE PATTERNS ==="
cat "$TMPDIR/ice_patterns.txt"

echo ""
echo "=== UNIQUE PATTERNS ==="
grep "set\|sign_extend\|mem:" "$TMPDIR/ice_patterns.txt" | sort -u

rm -rf "$TMPDIR"
