/* session_check.c -- CD session/status checking
 *
 * FUN_06041014: Check if a CD session param matches the current active session
 * FUN_06041310: Check if a specific CD sector/track is loaded
 * FUN_06041180: Validate CD transfer matches expected param, then call cleanup
 * FUN_06040EEC: Allocate a slot from a 24-entry table (different from slot_manager.c)
 * FUN_06040F82: Read CD-ROM TOC or status via two indirect calls
 *
 * The base pointer at 0x060A5400 points to a CD session control block.
 *
 * Original addresses: 0x06041014, 0x06041310, 0x06041180, 0x06040EEC, 0x06040F82
 */

extern void FUN_06034D1C(void);

int FUN_06041014(int param_1)
{
    if (*(int *)(*(int *)0x060A5400 + 0x30) == 0)
        return 0;
    return *(int *)(*(int *)0x060A5400 + 0x38) == param_1;
}

int FUN_06041310(int param_1)
{
    if ((*(int *)(*(int *)0x060A5400 + 0x0338) != 0) &&
        (*(int *)(*(int *)0x060A5400 + 0x033C) == param_1))
        return 0;
    return 1;
}

int FUN_06041180(int param_1, int param_2)
{
    if (((int **)0x060A5400)[0][14] != param_2)
        return -9;
    FUN_06034D1C();
    return 0;
}

int FUN_06040EEC(int *param_1)
{
    int i;
    i = 0;
    do {
        if (*(char *)(i + *(int *)0x060A5400) == '\0') {
            *(char *)(i + *(int *)0x060A5400) = 1;
            *param_1 = i;
            return 0;
        }
        i = i + 1;
    } while (i < 0x18);
    *param_1 = -1;
    return -4;
}

unsigned int FUN_06040F82(void)
{
    unsigned int local_8[2];
    (*(void (*)(int, unsigned int *))0x06034B54)(0, local_8);
    (*(void (*)(unsigned int, unsigned int *))0x06034B54)(local_8[0], local_8);
    return local_8[0] & 0x00FFFFFF;
}
