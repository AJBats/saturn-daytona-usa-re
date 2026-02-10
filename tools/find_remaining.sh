#!/bin/bash
cd /mnt/d/Projects/SaturnReverseTest

# Get all done function names
grep -ohP 'FUN_[0-9A-Fa-f]+' reimpl/src/*.c | sort -u > /tmp/done_funs.txt
echo "Done functions: $(wc -l < /tmp/done_funs.txt)"

# Get sizes of all src functions, exclude done ones
for f in src/FUN_*.c; do
    fname=$(basename "$f" .c)
    lines=$(wc -l < "$f")
    echo "$lines $fname"
done > /tmp/all_sizes.txt

echo "Total src functions: $(wc -l < /tmp/all_sizes.txt)"

# Filter out done ones
grep -vFf /tmp/done_funs.txt /tmp/all_sizes.txt | sort -n > /tmp/remaining_sizes.txt
echo "Remaining: $(wc -l < /tmp/remaining_sizes.txt)"
echo ""
echo "=== Shortest 150 remaining ==="
head -150 /tmp/remaining_sizes.txt
