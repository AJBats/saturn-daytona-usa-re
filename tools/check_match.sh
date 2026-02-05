#!/bin/bash
cd /mnt/d/Projects/SaturnReverseTest
func=$1
./tools/gcc26-build/cc1 -quiet -O2 -m2 -mbsr "src/${func}.c" -o /tmp/test.s 2>&1
grep -P '^\t[a-z]' /tmp/test.s | sed 's/\t/ /g' | awk '{print $1}' > /tmp/got.txt
echo "=== Expected ==="
tr -d '\r' < "tests/${func}.expected"
echo "=== Got ==="
cat /tmp/got.txt
echo "=== Diff ==="
diff <(tr -d '\r' < "tests/${func}.expected") /tmp/got.txt || true
