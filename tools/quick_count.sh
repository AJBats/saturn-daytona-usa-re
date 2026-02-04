#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/qcount_$$
mkdir -p "$TMPDIR"

total=0
ok=0

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    
    total=$((total + 1))
    
    if "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>/dev/null; then
        ok=$((ok + 1))
    fi
done

echo "Compilable: $ok / $total"
rm -rf "$TMPDIR"
