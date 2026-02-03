#!/bin/bash
set -e
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
RESULTS=/mnt/d/Projects/SaturnReverseTest/docs/verification_results.md

echo "# Batch Verification Results" > $RESULTS
echo "" >> $RESULTS
echo "Compiled with GCC 2.6.3 (patched for Saturn SH-2) at -O2" >> $RESULTS
echo "" >> $RESULTS

##############################################################################
# FUN_06006838 - Pure arithmetic (LEAF, 19 insns)
##############################################################################
cat > /tmp/fun_06006838.c << 'EOF'
int FUN_06006838(param_1, param_2)
    int param_1;
    int param_2;
{
    return ((unsigned int)(0x03FFFFFF - param_2) >> 21) * 64
         + ((unsigned int)(param_1 + 0x04000000) >> 21);
}
EOF

echo "## FUN_06006838 (LEAF, 19 insns) - Arithmetic: coordinate to tile" >> $RESULTS
echo '```' >> $RESULTS
echo "=== GCC 2.6.3 Output ===" >> $RESULTS
$CC1 -quiet -O2 /tmp/fun_06006838.c -o /tmp/fun_06006838.s 2>&1
grep -v '^\s*[!;]' /tmp/fun_06006838.s | grep -v '^\s*$' | grep -v '^\s*\.file' | grep -v '^\s*\.data' | grep -v 'gcc2_compiled' | grep -v 'gnu_compiled' >> $RESULTS
echo "" >> $RESULTS
echo "=== Original Binary ===" >> $RESULTS
cat >> $RESULTS << 'ORIG'
06006838: mov.l @(0x24,PC),r3   -> 0x03FFFFFF
0600683A: mov.l @(0x28,PC),r2   -> 0x04000000
0600683C: sub r5,r3
0600683E: add r2,r4
06006840: mov r3,r5
06006842: shlr16 r4
06006844: shlr16 r5
06006846: shlr2 r4
06006848: shlr2 r5
0600684A: shlr2 r4
0600684C: shlr2 r5
0600684E: shlr r4
06006850: shlr r5
06006852: shll2 r5
06006854: shll2 r5
06006856: shll2 r5
06006858: mov r5,r0
0600685A: rts
0600685C: add r4,r0   (delay slot)
ORIG
echo '```' >> $RESULTS
echo "" >> $RESULTS

##############################################################################
# FUN_060149CC - Bit OR + flag set (LEAF, 10 insns)
##############################################################################
cat > /tmp/fun_060149cc.c << 'EOF'
extern unsigned short reg_060A3D88;
extern short flag_060635AC;

void FUN_060149CC()
{
    reg_060A3D88 = reg_060A3D88 | 0x8000;
    flag_060635AC = 1;
}
EOF

echo "## FUN_060149CC (LEAF, 10 insns) - Bit OR + flag set" >> $RESULTS
echo '```' >> $RESULTS
echo "=== GCC 2.6.3 Output ===" >> $RESULTS
$CC1 -quiet -O2 /tmp/fun_060149cc.c -o /tmp/fun_060149cc.s 2>&1
grep -v '^\s*[!;]' /tmp/fun_060149cc.s | grep -v '^\s*$' | grep -v '^\s*\.file' | grep -v '^\s*\.data' | grep -v 'gcc2_compiled' | grep -v 'gnu_compiled' >> $RESULTS
echo "" >> $RESULTS
echo "=== Original Binary ===" >> $RESULTS
cat >> $RESULTS << 'ORIG'
060149CC: mov.l @(0x28,PC),r3   -> 0x00008000
060149CE: mov.l @(0x2C,PC),r2   -> 0x060A3D88
060149D0: mov.w @r2,r2
060149D2: or r3,r2
060149D4: mov.l @(0x24,PC),r3   -> 0x060A3D88
060149D6: mov.w r2,@r3
060149D8: mov #1,r2
060149DA: mov.l @(0x24,PC),r3   -> 0x060635AC
060149DC: rts
060149DE: mov.w r2,@r3   (delay slot)
ORIG
echo '```' >> $RESULTS
echo "" >> $RESULTS

##############################################################################
# FUN_060149E0 - Bit AND + flag set (LEAF, 10 insns)
# Companion to 060149CC
##############################################################################
cat > /tmp/fun_060149e0.c << 'EOF'
extern unsigned short reg_060A3D88;
extern short flag_060635AC;

void FUN_060149E0()
{
    reg_060A3D88 = reg_060A3D88 & 0x7FFF;
    flag_060635AC = 1;
}
EOF

echo "## FUN_060149E0 (LEAF, 10 insns) - Bit AND + flag set" >> $RESULTS
echo '```' >> $RESULTS
echo "=== GCC 2.6.3 Output ===" >> $RESULTS
$CC1 -quiet -O2 /tmp/fun_060149e0.c -o /tmp/fun_060149e0.s 2>&1
grep -v '^\s*[!;]' /tmp/fun_060149e0.s | grep -v '^\s*$' | grep -v '^\s*\.file' | grep -v '^\s*\.data' | grep -v 'gcc2_compiled' | grep -v 'gnu_compiled' >> $RESULTS
echo "" >> $RESULTS
echo "=== Original Binary ===" >> $RESULTS
cat >> $RESULTS << 'ORIG'
060149E0: mov.w @(0x10,PC),r3   (16-bit mask from constant pool)
060149E2: mov.l @(0x18,PC),r2   -> 0x060A3D88
060149E4: mov.w @r2,r2
060149E6: and r3,r2
060149E8: mov.l @(0x10,PC),r3   -> 0x060A3D88
060149EA: mov.w r2,@r3
060149EC: mov #1,r2
060149EE: mov.l @(0x10,PC),r3   -> 0x060635AC
060149F0: rts
060149F2: mov.w r2,@r3   (delay slot)
ORIG
echo '```' >> $RESULTS
echo "" >> $RESULTS

##############################################################################
# FUN_060054EA - Init function (LEAF, 12 insns)
##############################################################################
cat > /tmp/fun_060054ea.c << 'EOF'
extern int store_target;
extern short zero_target;
extern int copy_src;
extern int copy_dst;

void FUN_060054EA(param_1)
    int param_1;
{
    store_target = param_1;
    zero_target = 0;
    copy_dst = copy_src;
    copy_src = 0;
}
EOF

echo "## FUN_060054EA (LEAF, 12 insns) - Init/setup function" >> $RESULTS
echo '```' >> $RESULTS
echo "=== GCC 2.6.3 Output ===" >> $RESULTS
$CC1 -quiet -O2 /tmp/fun_060054ea.c -o /tmp/fun_060054ea.s 2>&1
grep -v '^\s*[!;]' /tmp/fun_060054ea.s | grep -v '^\s*$' | grep -v '^\s*\.file' | grep -v '^\s*\.data' | grep -v 'gcc2_compiled' | grep -v 'gnu_compiled' >> $RESULTS
echo "" >> $RESULTS
echo "(Decompiler output reference - need to extract original asm from binary)" >> $RESULTS
echo '```' >> $RESULTS
echo "" >> $RESULTS

##############################################################################
# Small getter/setter functions (4 insns each) - cluster at 0x06012Exx
##############################################################################
cat > /tmp/fun_06012e00.c << 'EOF'
extern int global_var;

int FUN_06012E00()
{
    return global_var;
}
EOF

echo "## FUN_06012E00 (LEAF, 4 insns) - Simple getter" >> $RESULTS
echo '```' >> $RESULTS
echo "=== GCC 2.6.3 Output ===" >> $RESULTS
$CC1 -quiet -O2 /tmp/fun_06012e00.c -o /tmp/fun_06012e00.s 2>&1
grep -v '^\s*[!;]' /tmp/fun_06012e00.s | grep -v '^\s*$' | grep -v '^\s*\.file' | grep -v '^\s*\.data' | grep -v 'gcc2_compiled' | grep -v 'gnu_compiled' >> $RESULTS
echo '```' >> $RESULTS
echo "" >> $RESULTS

echo "=== Batch verification complete ==="
echo "Results written to: $RESULTS"
