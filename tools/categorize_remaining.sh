#!/bin/bash
cd /mnt/d/Projects/SaturnReverseTest

grep -ohP 'FUN_[0-9A-Fa-f]+' reimpl/src/*.c | sort -u > /tmp/done_funs.txt
echo "Already translated: $(wc -l < /tmp/done_funs.txt)"

empty=0
return_input=0
single_write=0
dispatch=0
conditional=0
loop=0
complex=0

echo ""
echo "=== EMPTY (just return) ==="
for f in src/FUN_*.c; do
    fname=$(basename "$f" .c)
    if grep -qF "$fname" /tmp/done_funs.txt; then continue; fi
    body=$(tr -d '\r' < "$f" | grep -v '^$' | grep -v 'return;' | grep -v '{' | grep -v '}' | grep -v 'void\|int\|short\|char' | grep -v 'extern' | grep -v '/\*' | grep -v '\*/')
    if [ -z "$body" ]; then
        echo "$fname"
        empty=$((empty+1))
    fi
done

echo ""
echo "=== RETURN_INPUT (return in_r0 / return param) ==="
for f in src/FUN_*.c; do
    fname=$(basename "$f" .c)
    if grep -qF "$fname" /tmp/done_funs.txt; then continue; fi
    if grep -qP 'in_r0|return param' "$f" && [ $(wc -l < "$f") -le 10 ]; then
        echo "$fname"
        return_input=$((return_input+1))
    fi
done

echo ""
echo "=== SINGLE_WRITE (one or two memory writes, no loops) ==="
for f in src/FUN_*.c; do
    fname=$(basename "$f" .c)
    if grep -qF "$fname" /tmp/done_funs.txt; then continue; fi
    lines=$(wc -l < "$f")
    if [ "$lines" -le 15 ] && ! grep -qP 'while|for|do \{|in_r0' "$f" && grep -qP '\*\(.*\) =' "$f"; then
        echo "$fname ($lines lines)"
        single_write=$((single_write+1))
    fi
done

echo ""
echo "=== DISPATCH (function pointer call, no loops) ==="
for f in src/FUN_*.c; do
    fname=$(basename "$f" .c)
    if grep -qF "$fname" /tmp/done_funs.txt; then continue; fi
    lines=$(wc -l < "$f")
    if [ "$lines" -le 15 ] && ! grep -qP 'while|for|do \{|in_r0' "$f" && grep -qP '\(\*\(int\(\*\)' "$f"; then
        echo "$fname ($lines lines)"
        dispatch=$((dispatch+1))
    fi
done

echo ""
echo "Remaining functions by size bracket:"
total=0
for f in src/FUN_*.c; do
    fname=$(basename "$f" .c)
    if grep -qF "$fname" /tmp/done_funs.txt; then continue; fi
    total=$((total+1))
    lines=$(wc -l < "$f")
    echo "$lines"
done | sort -n | uniq -c | sort -rn -k2 | head -30

echo ""
echo "Total remaining: $total"
echo "Empty: $empty"
echo "Return input: $return_input"
echo "Single write: $single_write"
echo "Dispatch: $dispatch"
