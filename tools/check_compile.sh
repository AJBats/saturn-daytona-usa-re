#!/bin/bash
cd /mnt/d/Projects/SaturnReverseTest
errors=0
for f in src/*.c; do
    tr -d '\r' < "$f" > /tmp/test.c
    result=$(tools/gcc26-build/cc1 -quiet -O2 -m2 /tmp/test.c -o /tmp/test.s 2>&1)
    if echo "$result" | grep -q "error:"; then
        echo "ERROR: $f"
        echo "$result" | grep "error:" | head -3
        errors=$((errors+1))
    fi
done
echo "Total errors: $errors"
