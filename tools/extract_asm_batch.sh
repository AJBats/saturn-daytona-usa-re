#!/bin/bash
# Extract assembly from aprog.s for candidate functions
APROG=/mnt/d/Projects/SaturnReverseTest/build/aprog.s

for func in FUN_060359D2 FUN_060359DA FUN_0601A5F8 FUN_06035C08 FUN_06035E90 FUN_06035F04 FUN_0602EFCC FUN_060192CA FUN_06035F44 FUN_06034FFC FUN_06034C48 FUN_06035F16 FUN_06039FE8 FUN_06041014 FUN_06041180 FUN_06013E12 FUN_0601B074 FUN_0601209E FUN_06017C78 FUN_0601F87A; do
    echo "=== $func ==="
    # Try exact label match
    LINE=$(grep -n "^${func}:" "$APROG" | head -1 | cut -d: -f1)
    if [ -z "$LINE" ]; then
        # Try lowercase
        func_lower=$(echo "$func" | tr 'A-F' 'a-f')
        LINE=$(grep -n "^${func_lower}:" "$APROG" | head -1 | cut -d: -f1)
    fi
    if [ -z "$LINE" ]; then
        echo "NOT FOUND in aprog.s"
        continue
    fi
    # Extract up to 30 lines or next function label
    tail -n +$LINE "$APROG" | head -40 | tr -d '\r'
    echo ""
done
