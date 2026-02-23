#!/bin/bash
# Test-assemble consolidated TU L3 files
# Usage: bash test_asm_modules.sh [stem1 stem2 ...]
PROJDIR=/mnt/d/Projects/SaturnReverseTest
TOOLDIR=${PROJDIR}/tools/sh-elf/bin
cd ${PROJDIR}/reimpl
passed=0
failed=0
fail_list=""
total=0

if [ $# -gt 0 ]; then
    for stem in "$@"; do
        f="src/${stem}.s"
        retail="retail/${stem}.s"
        if [ ! -f "$f" ] || [ ! -f "$retail" ]; then continue; fi
        total=$((total + 1))
        if ${TOOLDIR}/sh-elf-as --fatal-warnings -o /dev/null "$f" 2>/tmp/asm_err.txt; then
            passed=$((passed + 1))
        else
            failed=$((failed + 1))
            err=$(head -3 /tmp/asm_err.txt)
            fail_list="${fail_list}\n  ${stem}: ${err}"
        fi
    done
else
    for f in src/*.s; do
        stem=$(basename "$f" .s)
        retail="retail/${stem}.s"
        if [ ! -f "$retail" ]; then continue; fi
        if ! head -5 "$retail" | grep -q 'Translation unit'; then continue; fi
        total=$((total + 1))
        if ${TOOLDIR}/sh-elf-as --fatal-warnings -o /dev/null "$f" 2>/tmp/asm_err.txt; then
            passed=$((passed + 1))
        else
            failed=$((failed + 1))
            err=$(head -3 /tmp/asm_err.txt)
            fail_list="${fail_list}\n  ${stem}: ${err}"
        fi
    done
fi

echo "Total: $total"
echo "PASSED: $passed"
echo "FAILED: $failed"
if [ $failed -gt 0 ]; then
    echo -e "FAILED FILES:$fail_list"
fi
