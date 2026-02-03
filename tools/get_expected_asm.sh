#!/bin/bash
# Extract full disassembly (with operands) from aprog.s for a given function
APROG=/mnt/d/Projects/SaturnReverseTest/build/aprog.s
SYMS=/mnt/d/Projects/SaturnReverseTest/build/aprog_syms.txt

for FUNC in FUN_0602760C FUN_06035C80; do
  ADDR=$(echo "$FUNC" | sed 's/FUN_//' | tr 'A-F' 'a-f')
  echo "=== $FUNC (0x$ADDR) ==="
  # Find the function in aprog.s and show ~30 lines
  grep -n "^0${ADDR}" "$APROG" | head -1
  LINE=$(grep -n "^0${ADDR}" "$APROG" | head -1 | cut -d: -f1)
  if [ -n "$LINE" ]; then
    sed -n "${LINE},$((LINE+35))p" "$APROG"
  else
    echo "Not found"
  fi
  echo ""
done
