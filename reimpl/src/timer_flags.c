/* timer_flags.c -- Hardware timer/interrupt flag accessors
 *
 * FUN_06042BAC: Set bit 0 of timer enable flags
 * FUN_06042BBE: Clear bit 0 of timer enable flags
 * FUN_06042BEE: Read bit 1 of timer enable flags
 *
 * Timer enable flags stored at ((param << 4) - 0x74).
 * These seem to be SH-2 on-chip I/O register accessors
 * (FRT/WDT area in 0xFFFFFExx range when param is large).
 *
 * Original addresses: 0x06042BAC, 0x06042BBE, 0x06042BEE
 */

void FUN_06042BAC(int param_1)
{
    unsigned int *ptr = (unsigned int *)((param_1 << 4) + -0x74);
    *ptr = *ptr | 1;
}

void FUN_06042BBE(int param_1)
{
    unsigned int *ptr = (unsigned int *)((param_1 << 4) + -0x74);
    *ptr = *ptr & 0xfffffffe;
}

unsigned int FUN_06042BEE(int param_1)
{
    unsigned int val = *(unsigned int *)((param_1 << 4) + -0x74);
    return val & 2;
}
