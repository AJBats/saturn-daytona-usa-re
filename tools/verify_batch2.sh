#!/bin/bash
set -e
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
OUT=/tmp/batch2_results.txt
echo "" > $OUT

##############################################################################
# FUN_06006838 v2 - Use << 6 instead of * 64 to avoid __mulsi3
##############################################################################
cat > /tmp/fun_06006838_v2.c << 'EOF'
int FUN_06006838(param_1, param_2)
    int param_1;
    int param_2;
{
    return (((unsigned int)(0x03FFFFFF - param_2) >> 21) << 6)
         + ((unsigned int)(param_1 + 0x04000000) >> 21);
}
EOF

echo "=== FUN_06006838 v2 (<<6 instead of *64) ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06006838_v2.c -o /tmp/fun_06006838_v2.s 2>&1
cat /tmp/fun_06006838_v2.s >> $OUT
echo "" >> $OUT

##############################################################################
# FUN_06006838 v3 - Try >> 15 with mask to see if GCC merges shifts
##############################################################################
cat > /tmp/fun_06006838_v3.c << 'EOF'
int FUN_06006838(param_1, param_2)
    int param_1;
    int param_2;
{
    return (((unsigned int)(0x03FFFFFF - param_2) >> 15) & ~63)
         + ((unsigned int)(param_1 + 0x04000000) >> 21);
}
EOF

echo "=== FUN_06006838 v3 (>>15 & ~63) ===" >> $OUT
$CC1 -quiet -O2 /tmp/fun_06006838_v3.c -o /tmp/fun_06006838_v3.s 2>&1
cat /tmp/fun_06006838_v3.s >> $OUT
echo "" >> $OUT

##############################################################################
# More LEAF functions from decomp_all.txt
##############################################################################

# FUN_060033E6 (16 insns)
# Read from decomp_all.txt: need to check what it does
# FUN_0601164A (7 insns)
# FUN_060192B4 (11 insns) - memory clear loop
# FUN_0601AEB6 (9 insns)
# FUN_0600D266 (2 insns) - trivial return
# FUN_06030EE0 (10 insns)
# FUN_060322E8 (10 insns)
# FUN_06033504 (10 insns)
# FUN_060359D2 (4 insns) - trivial getter/setter
# FUN_06035C48 (3 insns) - tiny function

# For now, just test the multiply fix
echo "=== Done ===" >> $OUT
cat $OUT
