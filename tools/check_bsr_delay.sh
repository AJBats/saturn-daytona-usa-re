#!/bin/bash
# Check how many delta=-1 functions have BSR delay slot filling as the cause
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

bsr_delay_count=0
other_count=0

for f in FUN_060054EA FUN_0600DE40 FUN_0600DE54 FUN_060149CC FUN_060149E0 \
         FUN_060192B4 FUN_0602755C FUN_06033504 FUN_06034560 FUN_06035438 \
         FUN_0603850C FUN_06038520 FUN_0603B734 FUN_0603B9A4 FUN_0603EF54 \
         FUN_0603EFD4 FUN_06041310 FUN_06042BBE FUN_06042BEE; do
  $CC1 -quiet -O2 -m2 -mbsr $TDIR/$f.c -o /tmp/$f.s 2>/dev/null

  # Check if our output has bsr with non-nop in delay slot
  if grep -P '^\tbsr\t' /tmp/$f.s > /dev/null 2>&1; then
    # Get the line after bsr
    delay=$(grep -P -A1 '^\tbsr\t' /tmp/$f.s | tail -1 | awk '{print $1}')
    if [ "$delay" != "nop" ]; then
      echo "BSR-DELAY: $f (delay=$delay)"
      bsr_delay_count=$((bsr_delay_count + 1))
    else
      echo "BSR-NOP:   $f"
    fi
  else
    # Check expected for bsr/nop pattern
    exp_bsr=$(grep -c '^bsr' <(tr -d '\r' < $TDIR/$f.expected) 2>/dev/null || echo 0)
    if [ "$exp_bsr" -gt 0 ]; then
      echo "NO-BSR-OURS: $f (expected has bsr but we don't)"
    else
      echo "NO-BSR:    $f"
      other_count=$((other_count + 1))
    fi
  fi
done

echo ""
echo "BSR delay slot filled: $bsr_delay_count"
echo "Other pattern: $other_count"
