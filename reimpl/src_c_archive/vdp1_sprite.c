/* vdp1_sprite.c -- VDP1 sprite command construction
 *
 * These functions build VDP1 command table entries for sprite drawing.
 * The command table entry is a short array:
 *   [0] = command word (from const table at 0x060280F4 or 0x060281E4)
 *   [2] = link field
 *   [3] = color/size param
 *   [6-12] = vertex coordinates (from source data at param_1+8..param_1+0x14)
 *
 * FUN_060280C4: Build VDP1 command from data pointer (auto color from param_1+6)
 * FUN_060281B8: Build VDP1 command with explicit color/size param_3
 *
 * Original addresses: 0x060280C4, 0x060281B8
 */

void FUN_060280C4(int param_1, short *param_2)
{
    short *puVar1 = (short *)0x060280F4 + 1;

    *param_2 = *(int *)0x060280F4;
    param_2[2] = *puVar1;
    param_2[3] = *(short *)(param_1 + 6);
    *(int *)(param_2 + 6) = *(int *)(param_1 + 8);
    *(int *)(param_2 + 8) = *(int *)(param_1 + 0xc);
    *(int *)(param_2 + 10) = *(int *)(param_1 + 0x10);
    *(int *)(param_2 + 0xc) = *(int *)(param_1 + 0x14);
}

void FUN_060281B8(int param_1, short *param_2, short param_3)
{
    short *puVar1 = (short *)0x060281E4 + 1;

    *param_2 = *(int *)0x060281E4;
    param_2[2] = *puVar1;
    param_2[3] = param_3;
    *(int *)(param_2 + 6) = *(int *)(param_1 + 8);
    *(int *)(param_2 + 8) = *(int *)(param_1 + 0xc);
    *(int *)(param_2 + 10) = *(int *)(param_1 + 0x10);
    *(int *)(param_2 + 0xc) = *(int *)(param_1 + 0x14);
}
