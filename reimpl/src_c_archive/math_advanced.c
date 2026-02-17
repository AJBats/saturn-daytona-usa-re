/* math_advanced.c -- Advanced math: atan2, division, division hardware
 *
 * math_div64_unprotected: Hardware-accelerated 32-bit division using SH-2 DIVU registers
 *   The SH-2 division unit is at 0xFFFFFF00:
 *     +0x00 = DVSR (divisor), +0x10 = DVDNH (dividend high), +0x14 = DVDNL (dividend low)
 *     +0x1C = DVDNTL (quotient result)
 *
 * FUN_0602744C: atan2(y, x) -- compute angle from two fixed-point deltas
 *   Returns angle in 16-bit fixed point (0x0000-0xFFFF = 0-360 degrees)
 *   Uses math_div64_unprotected (division) and FUN_06027378 (atan table lookup)
 *
 * FUN_060283B8: Unpack nibbles -- extracts 4-bit values from param_4 and writes
 *   them as shorts to a VDP name table row
 *
 * FUN_060102A8: Input processing -- adjust a mode counter based on button bits
 *
 * Original addresses: 0x0602755C, 0x0602744C, 0x060283B8, 0x060102A8
 */

extern int FUN_06027378(int);

int math_div64_unprotected(int param_1, int param_2)
{
    volatile int *divu = (volatile int *)0xFFFFFF00;
    *divu = param_2;
    divu[4] = (int)(short)((unsigned int)param_1 >> 0x10);
    divu[5] = param_1 << 0x10;
    return divu[7];
}

int FUN_0602744C(int param_1, int param_2)
{
    short sVar3;

    if (param_2 == 0) {
        sVar3 = *(volatile short *)0x060274FC;
        if (param_1 < 0) {
            sVar3 = -sVar3;
        }
        return sVar3;
    }

    int uVar2 = math_div64_unprotected(param_1, param_2);
    sVar3 = FUN_06027378(uVar2);

    if (param_2 < 0) {
        sVar3 = sVar3 + (short)0x8000;
    }

    return (int)sVar3;
}

int FUN_060283B8(int param_1, int param_2, int param_3, unsigned int param_4)
{
    int i;
    int base;

    i = 0x10;
    base = **(int **)(0x06028614 + param_1);
    do {
        i -= 2;
        *(unsigned short *)(base + param_2 + i) = (param_4 & 0xf) + param_3;
        param_4 >>= 4;
    } while (i);
    return 0;
}

void FUN_060102A8(unsigned int param_1)
{
    int val;
    unsigned short p = param_1;

    if ((p & 0x8000) != 0 && *(int *)0x0607EADC < 2) {
        *(int *)0x0607EADC = *(int *)0x0607EADC + 1;
    }

    if ((p & *(volatile short *)0x0601030A) != 0 && *(int *)0x0607EADC > 0) {
        *(int *)0x0607EADC = *(int *)0x0607EADC - 1;
    }

    val = *(int *)0x0607EADC;
    *(char *)0x0607887E = (char)val;
    *(int *)0x0607EAD8 = val;
}
