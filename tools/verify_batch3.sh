#!/bin/bash
set -e
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
OUT=/tmp/batch3_results.txt
echo "" > $OUT

##############################################################################
# GROUP 1: TRIVIAL FUNCTIONS (2-3 insns)
##############################################################################

# FUN_0600D266 (2 insns) - void return
cat > /tmp/fun_0600d266.c << 'EOF'
void FUN_0600D266()
{
    return;
}
EOF

echo "=== FUN_0600D266 (2 insns) - void return ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_0600d266.c -o /tmp/fun_0600d266.s 2>&1
cat /tmp/fun_0600d266.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "0600D266: rts" >> $OUT
echo "0600D268: nop" >> $OUT
echo "" >> $OUT

# FUN_06035C48 (3 insns) - pointer return
cat > /tmp/fun_06035c48.c << 'EOF'
extern int global_06035c74;
int *FUN_06035C48()
{
    return &global_06035c74;
}
EOF

echo "=== FUN_06035C48 (3 insns) - pointer return ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06035c48.c -o /tmp/fun_06035c48.s 2>&1
cat /tmp/fun_06035c48.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06035C48: mov.l @(0x28,PC),r0  -> 0x25818000" >> $OUT
echo "06035C4A: rts" >> $OUT
echo "06035C4C: nop" >> $OUT
echo "" >> $OUT

# FUN_06035C4E (3 insns) - short read from hardware register
cat > /tmp/fun_06035c4e.c << 'EOF'
extern short hw_reg_06035c78;
int FUN_06035C4E()
{
    return (int)hw_reg_06035c78;
}
EOF

echo "=== FUN_06035C4E (3 insns) - short read from hw reg ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06035c4e.c -o /tmp/fun_06035c4e.s 2>&1
cat /tmp/fun_06035c4e.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06035C4E: mov.l @(0x28,PC),r0  -> 0x25890008" >> $OUT
echo "06035C50: rts" >> $OUT
echo "06035C52: mov.w @r0,r0  (delay slot - fills!)" >> $OUT
echo "" >> $OUT

##############################################################################
# GROUP 2: SIMPLE STORES/LOADS (5-7 insns)
##############################################################################

# FUN_06026DF8 (5 insns) - subtract 0x30 from memory word
cat > /tmp/fun_06026df8.c << 'EOF'
extern int counter_06027068;
void FUN_06026DF8()
{
    counter_06027068 = counter_06027068 + -0x30;
}
EOF

echo "=== FUN_06026DF8 (5 insns) - subtract 0x30 from memory ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06026df8.c -o /tmp/fun_06026df8.s 2>&1
cat /tmp/fun_06026df8.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06026DF8: mov.l @(0x26C,PC),r1  -> 0x06089EDC" >> $OUT
echo "06026DFA: mov.l @r1,r0" >> $OUT
echo "06026DFC: add #-48,r0" >> $OUT
echo "06026DFE: rts" >> $OUT
echo "06026E00: mov.l r0,@r1  (delay slot)" >> $OUT
echo "" >> $OUT

# FUN_0601164A (7 insns) - VDP2 register writes
cat > /tmp/fun_0601164a.c << 'EOF'
extern int val_long_06011670;
extern int dst_long_06011674;
extern short val_short_0601165a;
void FUN_0601164A()
{
    int *p;
    p = &dst_long_06011674;
    *p = val_long_06011670;
    *(short *)((char *)p + -10) = val_short_0601165a;
}
EOF

echo "=== FUN_0601164A (7 insns) - VDP2 register writes ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_0601164a.c -o /tmp/fun_0601164a.s 2>&1
cat /tmp/fun_0601164a.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "0601164A: mov.l @(0x24,PC),r3  -> 0x12F2FC00" >> $OUT
echo "0601164C: mov.l @(0x24,PC),r2  -> 0x25F800A4" >> $OUT
echo "0601164E: mov.l r3,@r2" >> $OUT
echo "06011650: mov.w @(0x6,PC),r3   -> 0x0200" >> $OUT
echo "06011652: add #-10,r2" >> $OUT
echo "06011654: rts" >> $OUT
echo "06011656: mov.w r3,@r2  (delay slot)" >> $OUT
echo "" >> $OUT

# FUN_06018EC8 (7 insns) - byte copy to two VDP2 registers
cat > /tmp/fun_06018ec8.c << 'EOF'
extern short val_src_06018ed6;
extern char dst1_06018edc;
extern char dst2_06018ee0;
void FUN_06018EC8()
{
    char v;
    v = (char)val_src_06018ed6;
    dst1_06018edc = v;
    dst2_06018ee0 = v;
}
EOF

echo "=== FUN_06018EC8 (7 insns) - byte copy to two VDP2 regs ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06018ec8.c -o /tmp/fun_06018ec8.s 2>&1
cat /tmp/fun_06018ec8.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06018EC8: mov.w @(0xA,PC),r4    -> 0x00E0" >> $OUT
echo "06018ECA: mov.l @(0x10,PC),r2   -> 0x25B00217" >> $OUT
echo "06018ECC: extu.b r4,r3" >> $OUT
echo "06018ECE: mov.b r3,@r2" >> $OUT
echo "06018ED0: mov.l @(0xC,PC),r3    -> 0x25B00237" >> $OUT
echo "06018ED2: rts" >> $OUT
echo "06018ED4: mov.b r4,@r3  (delay slot)" >> $OUT
echo "" >> $OUT

##############################################################################
# GROUP 3: CONDITIONAL (10 insns)
##############################################################################

# FUN_06030EE0 (10 insns) - conditional decrement short
cat > /tmp/fun_06030ee0.c << 'EOF'
extern short idx_06030ef4;
extern int *base_ptr_06030ef8;
int FUN_06030EE0()
{
    int i;
    short val;
    i = (int)idx_06030ef4;
    val = *(short *)((char *)*base_ptr_06030ef8 + i);
    if (val > 0) {
        *(short *)((char *)*base_ptr_06030ef8 + i) = val + -1;
    }
    return i;
}
EOF

echo "=== FUN_06030EE0 (10 insns) - conditional decrement ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06030ee0.c -o /tmp/fun_06030ee0.s 2>&1
cat /tmp/fun_06030ee0.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06030EE0: mov.w @(0x10,PC),r0   -> 0x0150" >> $OUT
echo "06030EE2: mov.l @(0x14,PC),r1   -> 0x0607E940" >> $OUT
echo "06030EE4: mov.l @r1,r3" >> $OUT
echo "06030EE6: mov.w @(r0,r3),r2" >> $OUT
echo "06030EE8: cmp/pl r2" >> $OUT
echo "06030EEA: bf 0x06030EF0" >> $OUT
echo "06030EEC: add #-1,r2" >> $OUT
echo "06030EEE: mov.w r2,@(r0,r3)" >> $OUT
echo "06030EF0: rts" >> $OUT
echo "06030EF2: nop" >> $OUT
echo "" >> $OUT

# FUN_060322E8 (10 insns) - conditional increment + return pointer
cat > /tmp/fun_060322e8.c << 'EOF'
extern char flag_060322fc;
extern int counter_06032300;
int *FUN_060322E8()
{
    if (flag_060322fc != 0) {
        counter_06032300 = counter_06032300 + 1;
        return &counter_06032300;
    }
    return (int *)&flag_060322fc;
}
EOF

echo "=== FUN_060322E8 (10 insns) - conditional increment ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_060322e8.c -o /tmp/fun_060322e8.s 2>&1
cat /tmp/fun_060322e8.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "060322E8: mov.l @(0x10,PC),r0   -> 0x06082A24" >> $OUT
echo "060322EA: mov.b @r0,r1" >> $OUT
echo "060322EC: tst r1,r1" >> $OUT
echo "060322EE: bt 0x060322F8" >> $OUT
echo "060322F0: mov.l @(0xC,PC),r0    -> 0x06082A20" >> $OUT
echo "060322F2: mov.l @r0,r1" >> $OUT
echo "060322F4: add #1,r1" >> $OUT
echo "060322F6: mov.l r1,@r0" >> $OUT
echo "060322F8: rts" >> $OUT
echo "060322FA: nop" >> $OUT
echo "" >> $OUT

# FUN_06033504 (10 insns) - dual increment + return pointer
cat > /tmp/fun_06033504.c << 'EOF'
extern int counter_06033518;
extern int offset_0603351c;
int *FUN_06033504()
{
    int *p;
    p = &counter_06033518;
    counter_06033518 = counter_06033518 + 1;
    offset_0603351c = offset_0603351c + 0x20;
    return p;
}
EOF

echo "=== FUN_06033504 (10 insns) - dual increment ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06033504.c -o /tmp/fun_06033504.s 2>&1
cat /tmp/fun_06033504.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06033504: mov.l @(0x10,PC),r0   -> 0x0605A008" >> $OUT
echo "06033506: mov.l @r0,r1" >> $OUT
echo "06033508: add #1,r1" >> $OUT
echo "0603350A: mov.l r1,@r0" >> $OUT
echo "0603350C: mov.l @(0xC,PC),r2    -> 0x060785FC" >> $OUT
echo "0603350E: mov.l @r2,r1" >> $OUT
echo "06033510: add #32,r1" >> $OUT
echo "06033512: mov.l r1,@r2" >> $OUT
echo "06033514: rts" >> $OUT
echo "06033516: nop" >> $OUT
echo "" >> $OUT

##############################################################################
# GROUP 4: LOOPS AND COMPLEX (11-18 insns)
##############################################################################

# FUN_060192B4 (11 insns) - byte clear loop (dt+bf/s)
cat > /tmp/fun_060192b4.c << 'EOF'
extern int count_06019300;
extern char *dest_060192fc;
void FUN_060192B4()
{
    char *p;
    int n;
    p = dest_060192fc;
    n = count_06019300;
    do {
        *p = 0;
        p = p + 1;
        n = n - 1;
    } while (n != 0);
}
EOF

echo "=== FUN_060192B4 (11 insns) - byte clear loop (dt+bf/s) ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_060192b4.c -o /tmp/fun_060192b4.s 2>&1
cat /tmp/fun_060192b4.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "060192B4: mov #0,r5" >> $OUT
echo "060192B6: mov.l @(0x44,PC),r6   -> 0x25A00000" >> $OUT
echo "060192B8: mov.l @(0x44,PC),r4   -> 0x0007FFFF" >> $OUT
echo "060192BA: mov r6,r3" >> $OUT
echo "060192BC: exts.b r5,r2" >> $OUT
echo "060192BE: add #1,r6" >> $OUT
echo "060192C0: dt r4" >> $OUT
echo "060192C2: bf/s 0x060192BA" >> $OUT
echo "060192C4: mov.b r2,@r3  (delay slot)" >> $OUT
echo "060192C6: rts" >> $OUT
echo "060192C8: nop" >> $OUT
echo "" >> $OUT

# FUN_06005174 (18 insns) - zero 8 shorts at pointer
cat > /tmp/fun_06005174.c << 'EOF'
extern short arr_06005220[8];
void FUN_06005174()
{
    arr_06005220[0] = 0;
    arr_06005220[1] = 0;
    arr_06005220[2] = 0;
    arr_06005220[3] = 0;
    arr_06005220[4] = 0;
    arr_06005220[5] = 0;
    arr_06005220[6] = 0;
    arr_06005220[7] = 0;
}
EOF

echo "=== FUN_06005174 (18 insns) - zero 8 shorts ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06005174.c -o /tmp/fun_06005174.s 2>&1
cat /tmp/fun_06005174.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06005174: mov.l @(0xA8,PC),r5   -> 0x06063D98" >> $OUT
echo "06005176: mov #0,r4" >> $OUT
echo "06005178: mov.w r4,@r5" >> $OUT
echo "0600517A: extu.w r4,r0" >> $OUT
echo "0600517C: mov.w r0,@(0x2,r5)" >> $OUT
echo "0600517E: extu.w r4,r0" >> $OUT
echo "06005180: mov.w r0,@(0x4,r5)" >> $OUT
echo "06005182: extu.w r4,r0" >> $OUT
echo "06005184: mov.w r0,@(0x6,r5)" >> $OUT
echo "06005186: add #8,r5" >> $OUT
echo "06005188: extu.w r4,r0" >> $OUT
echo "0600518A: mov.w r4,@r5" >> $OUT
echo "0600518C: mov.w r0,@(0x2,r5)" >> $OUT
echo "0600518E: extu.w r4,r0" >> $OUT
echo "06005190: mov.w r0,@(0x4,r5)" >> $OUT
echo "06005192: extu.w r4,r0" >> $OUT
echo "06005194: rts" >> $OUT
echo "06005196: mov.w r0,@(0x6,r5)  (delay slot)" >> $OUT
echo "" >> $OUT

# FUN_0600C970 (18 insns) - range check + table lookup with parameter
cat > /tmp/fun_0600c970.c << 'EOF'
extern short offset_0600c9e4;
extern short table_0600c9e8[];
int FUN_0600C970(param_1)
    int param_1;
{
    int idx;
    int val;
    idx = (int)offset_0600c9e4;
    val = *(int *)(param_1 + idx);
    if (val >= 0x45 && val <= 98) {
        *(int *)(param_1 + 0xc) =
            *(int *)(param_1 + 0xc) + (int)table_0600c9e8[val - 0x45];
    }
    return idx;
}
EOF

echo "=== FUN_0600C970 (18 insns) - range check + table lookup ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_0600c970.c -o /tmp/fun_0600c970.s 2>&1
cat /tmp/fun_0600c970.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "0600C970: mov.w @(0x70,PC),r0   -> offset value" >> $OUT
echo "0600C972: mov #69,r3" >> $OUT
echo "0600C974: mov.l @(r0,r4),r5" >> $OUT
echo "0600C976: cmp/ge r3,r5" >> $OUT
echo "0600C978: bf 0x0600C990" >> $OUT
echo "0600C97A: mov #98,r3" >> $OUT
echo "0600C97C: cmp/gt r3,r5" >> $OUT
echo "0600C97E: bt 0x0600C990" >> $OUT
echo "0600C980: add #-69,r5" >> $OUT
echo "0600C982: shll r5" >> $OUT
echo "0600C984: mov.l @(0x60,PC),r3   -> 0x0605A1E0" >> $OUT
echo "0600C986: add r3,r5" >> $OUT
echo "0600C988: mov.w @r5,r2" >> $OUT
echo "0600C98A: mov.l @(0xC,r4),r1" >> $OUT
echo "0600C98C: add r2,r1" >> $OUT
echo "0600C98E: mov.l r1,@(0xC,r4)" >> $OUT
echo "0600C990: rts" >> $OUT
echo "0600C992: nop" >> $OUT
echo "" >> $OUT

##############################################################################
# GROUP 5: TAIL CALL (4 insns)
##############################################################################

# FUN_06012E00 (4 insns) - tail call to file loader
cat > /tmp/fun_06012e00.c << 'EOF'
extern void FUN_06012c3c();
extern char filename_06044960[];
extern int dest_addr_002a0000;
void FUN_06012E00()
{
    FUN_06012c3c(filename_06044960, dest_addr_002a0000);
}
EOF

echo "=== FUN_06012E00 (4 insns) - tail call to file loader ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06012e00.c -o /tmp/fun_06012e00.s 2>&1
cat /tmp/fun_06012e00.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "06012E00: mov.l @(0x38,PC),r5   -> 0x002A0000" >> $OUT
echo "06012E02: mov.l @(0x3C,PC),r4   -> 0x06044960 (TEX_PL.BIN)" >> $OUT
echo "06012E04: bra 0x06012C3C         (tail call)" >> $OUT
echo "06012E06: nop" >> $OUT
echo "" >> $OUT

##############################################################################
# GROUP 6: CORRECTED FUN_060054EA (12 insns)
##############################################################################

# FUN_060054EA (12 insns) - init/setup with corrected order
cat > /tmp/fun_060054ea.c << 'EOF'
extern int store_target_0600552c;
extern short zero_target_06005530;
extern int copy_src_06005534;
extern int copy_dst_06005538;
void FUN_060054EA(param_1)
    int param_1;
{
    store_target_0600552c = param_1;
    zero_target_06005530 = 0;
    copy_src_06005534 = 0;
    copy_dst_06005538 = copy_src_06005534;
}
EOF

echo "=== FUN_060054EA (12 insns) - init/setup ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_060054ea.c -o /tmp/fun_060054ea.s 2>&1
cat /tmp/fun_060054ea.s >> $OUT
echo "" >> $OUT
echo "--- Original binary ---" >> $OUT
echo "060054EA: mov.l @(0x40,PC),r3   -> 0x06063E04" >> $OUT
echo "060054EC: mov.l r4,@r3" >> $OUT
echo "060054EE: mov #0,r4" >> $OUT
echo "060054F0: mov.l @(0x3C,PC),r3   -> 0x06063E08" >> $OUT
echo "060054F2: mov.w r4,@r3" >> $OUT
echo "060054F4: mov.l @(0x3C,PC),r3   -> 0x06063F08" >> $OUT
echo "060054F6: mov.l r4,@r3" >> $OUT
echo "060054F8: mov r3,r1" >> $OUT
echo "060054FA: mov.l @r1,r1" >> $OUT
echo "060054FC: mov.l @(0x38,PC),r3   -> 0x06063F04" >> $OUT
echo "060054FE: rts" >> $OUT
echo "06005500: mov.l r1,@r3  (delay slot)" >> $OUT
echo "" >> $OUT

echo "=== DONE ===" >> $OUT
cat $OUT
