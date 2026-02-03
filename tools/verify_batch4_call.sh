#!/bin/bash
set -e
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
OUT=/tmp/batch4_results.txt
echo "" > $OUT

##############################################################################
# FUN_0600DE40 (10 insns, CALL) - shift+store + 2 direct calls
# Last call is tail call in original (bra + lds.l pr in delay slot)
##############################################################################
cat > /tmp/fun_0600de40.c << 'EOF'
extern int source_0600deb4;
extern short target_0600deb8;
extern void FUN_0600e410();
extern void FUN_0600e0c0();

void FUN_0600DE40()
{
    target_0600deb8 = (short)(source_0600deb4 >> 1);
    FUN_0600e410();
    FUN_0600e0c0();
}
EOF

echo "=== FUN_0600DE40 (10 insns, CALL) - shift+store + 2 calls ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_0600de40.c -o /tmp/fun_0600de40.s 2>&1
cat /tmp/fun_0600de40.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "0600DE40: sts.l pr,@-r15" >> $OUT
echo "0600DE42: mov.l @(0x70,PC),r3   -> 0x0607EA98 (source)" >> $OUT
echo "0600DE44: mov.l @(0x70,PC),r2   -> 0x060786CA (target)" >> $OUT
echo "0600DE46: mov.l @r3,r3" >> $OUT
echo "0600DE48: shar r3                (arithmetic shift right)" >> $OUT
echo "0600DE4A: mov.w r3,@r2" >> $OUT
echo "0600DE4C: bsr 0x0600E410        (first call)" >> $OUT
echo "0600DE4E: nop" >> $OUT
echo "0600DE50: bra 0x0600E0C0        (TAIL CALL)" >> $OUT
echo "0600DE52: lds.l @r15+,pr        (PR restore in bra delay slot!)" >> $OUT
echo "" >> $OUT

##############################################################################
# FUN_0600DE54 (14 insns, CALL) - shift+store + memory copy + 2 calls
# Last call is tail call
##############################################################################
cat > /tmp/fun_0600de54.c << 'EOF'
extern int source_0600deb4;
extern short target_0600deb8;
extern int copy_src_0600debc;
extern int copy_dst_0600dec0;
extern void FUN_0600e99c();
extern void FUN_0600e0c0();

void FUN_0600DE54()
{
    target_0600deb8 = (short)(source_0600deb4 >> 1);
    copy_dst_0600dec0 = copy_src_0600debc;
    FUN_0600e99c();
    FUN_0600e0c0();
}
EOF

echo "=== FUN_0600DE54 (14 insns, CALL) - shift+store+copy + 2 calls ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_0600de54.c -o /tmp/fun_0600de54.s 2>&1
cat /tmp/fun_0600de54.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "0600DE54: sts.l pr,@-r15" >> $OUT
echo "0600DE56: mov.l @(0x5C,PC),r3   -> 0x0607EA98 (source)" >> $OUT
echo "0600DE58: mov.l @(0x5C,PC),r2   -> 0x060786CA (target)" >> $OUT
echo "0600DE5A: mov.l @r3,r3          load int" >> $OUT
echo "0600DE5C: shar r3               arithmetic shift right" >> $OUT
echo "0600DE5E: mov.w r3,@r2          store short" >> $OUT
echo "0600DE60: mov.l @(0x58,PC),r1   -> 0x0607E944 (copy_src)" >> $OUT
echo "0600DE62: mov.l @(0x5C,PC),r2   -> 0x0607E940 (copy_dst)" >> $OUT
echo "0600DE64: mov.l @r1,r1          load copy_src value" >> $OUT
echo "0600DE66: mov.l r1,@r2          store to copy_dst" >> $OUT
echo "0600DE68: bsr 0x0600E99C        (first call)" >> $OUT
echo "0600DE6A: nop" >> $OUT
echo "0600DE6C: bra 0x0600E0C0        (TAIL CALL)" >> $OUT
echo "0600DE6E: lds.l @r15+,pr        (PR restore in bra delay slot!)" >> $OUT
echo "" >> $OUT

##############################################################################
# FUN_06018E70 (12 insns, CALL) - stack local + indirect call
##############################################################################
cat > /tmp/fun_06018e70.c << 'EOF'
extern int func_ptr_06018ea8();

int FUN_06018E70()
{
    int local_c[2];
    local_c[0] = 3;
    return func_ptr_06018ea8(local_c);
}
EOF

echo "=== FUN_06018E70 (12 insns, CALL) - stack local + call ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06018e70.c -o /tmp/fun_06018e70.s 2>&1
cat /tmp/fun_06018e70.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06018E70: sts.l pr,@-r15" >> $OUT
echo "06018E72: mov #3,r2" >> $OUT
echo "06018E74: add #-8,r15           alloc stack" >> $OUT
echo "06018E76: mov r15,r3" >> $OUT
echo "06018E78: mov.l r2,@r3          local[0] = 3" >> $OUT
echo "06018E7A: mov.l @(0x2C,PC),r3   -> 0x06034DEA (func ptr)" >> $OUT
echo "06018E7C: jsr @r3               call" >> $OUT
echo "06018E7E: mov r15,r4            arg = &local (delay slot)" >> $OUT
echo "06018E80: add #8,r15            dealloc stack" >> $OUT
echo "06018E82: lds.l @r15+,pr" >> $OUT
echo "06018E84: rts" >> $OUT
echo "06018E86: nop" >> $OUT
echo "" >> $OUT

##############################################################################
# FUN_06018EAC (14 insns, CALL) - stack array + indirect call + mask
##############################################################################
cat > /tmp/fun_06018eac.c << 'EOF'
extern int func_ptr_06018ed8();

int FUN_06018EAC()
{
    char local_10[16];
    func_ptr_06018ed8(local_10);
    return (int)(local_10[0] & 0x1f);
}
EOF

echo "=== FUN_06018EAC (14 insns, CALL) - stack array + call + mask ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06018eac.c -o /tmp/fun_06018eac.s 2>&1
cat /tmp/fun_06018eac.s >> $OUT
echo "" >> $OUT

# Get the original binary for FUN_06018EAC
echo "--- Original binary (need to extract) ---" >> $OUT
echo "" >> $OUT

##############################################################################
# FUN_060210F6 (14 insns, CALL) - 3 indirect calls + flag set
##############################################################################
cat > /tmp/fun_060210f6.c << 'EOF'
extern void func1_06021118();
extern void func2_0602111c();
extern void func3_06021120();
extern char flag_06021124;
extern char param_06021114;

void FUN_060210F6()
{
    func1_06021118(8);
    flag_06021124 = 0;
    func2_0602111c(&param_06021114);
    func3_06021120();
}
EOF

echo "=== FUN_060210F6 (14 insns, CALL) - 3 calls + flag ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_060210f6.c -o /tmp/fun_060210f6.s 2>&1
cat /tmp/fun_060210f6.s >> $OUT
echo "" >> $OUT

##############################################################################
# FUN_06014868 (14 insns, CALL) - 3 indirect calls, pass-through params
##############################################################################
cat > /tmp/fun_06014868.c << 'EOF'
extern void func1_060148e4();
extern void func2_060148e8();
extern void func3_060148ec();

void FUN_06014868(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
    func1_060148e4();
    func2_060148e8(param_2, param_3);
    func3_060148ec();
}
EOF

echo "=== FUN_06014868 (14 insns, CALL) - 3 calls pass params ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06014868.c -o /tmp/fun_06014868.s 2>&1
cat /tmp/fun_06014868.s >> $OUT
echo "" >> $OUT

echo "=== DONE ===" >> $OUT
cat $OUT
