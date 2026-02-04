#!/bin/bash
# Extract Ghidra decomps and assembly for candidate functions
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt
APROG=/mnt/d/Projects/SaturnReverseTest/build/aprog.s

for func in FUN_06035C08 FUN_06035E90 FUN_06035F04 FUN_06014A42 FUN_0601444C FUN_06014868 FUN_06014884 FUN_060210F6 FUN_0600A4AA FUN_06034C48 FUN_06041180 FUN_06041330 FUN_0601B074 FUN_0601FD20 FUN_0601FD74 FUN_06035EA2 FUN_0600DC74 FUN_06040F82; do
    echo "================================================================"
    echo "=== $func ==="
    echo "================================================================"

    # Get assembly
    echo "--- ASSEMBLY ---"
    LINE=$(grep -n "^${func}:" "$APROG" | head -1 | cut -d: -f1)
    if [ -n "$LINE" ]; then
        # Find next function label after this one
        END=$(tail -n +$((LINE+1)) "$APROG" | grep -n "^FUN_\|^[a-z_]*:" | head -1 | cut -d: -f1)
        if [ -n "$END" ]; then
            sed -n "${LINE},$((LINE+END-1))p" "$APROG" | tr -d '\r'
        else
            sed -n "${LINE},$((LINE+30))p" "$APROG" | tr -d '\r'
        fi
    fi

    # Get Ghidra decomp
    echo ""
    echo "--- GHIDRA ---"
    func_lower=$(echo "$func" | tr 'A-F' 'a-f')
    GLINE=$(grep -n "^FUNC $func_lower " "$GHIDRA" | head -1 | cut -d: -f1)
    if [ -n "$GLINE" ]; then
        GEND=$(tail -n +$((GLINE+1)) "$GHIDRA" | grep -n "^FUNC " | head -1 | cut -d: -f1)
        if [ -z "$GEND" ]; then GEND=50; fi
        sed -n "${GLINE},$((GLINE+GEND-1))p" "$GHIDRA" | tr -d '\r'
    fi
    echo ""
done
