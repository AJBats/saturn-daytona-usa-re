/* dma_transfer.c -- DMA/VDP transfer wrappers
 *
 * These functions call indirect DMA transfer routines through fixed
 * function pointers. The DMA engine at 0x06028400 takes:
 *   (mode, src_data, size/dest_offset, src_base_or_param)
 *
 * FUN_0601143E: Transfer tile data from 0x0605A634 to VRAM (offset 0xD000)
 * FUN_06011450: Transfer tile data from 0x0605A718 to VRAM (offset 0xE000)
 * FUN_060285E0: Compute VRAM address from row/col and start transfer (via 0x060283B8)
 * FUN_06028600: Same as 060285E0 but via 0x060283E0
 *
 * Original addresses: 0x0601143E, 0x06011450, 0x060285E0, 0x06028600
 */

void FUN_0601143E(void)
{
    int arg4 = 0x0000D000 + *(int *)(0x06063828 + 4);
    int arg3 = 0xe;
    (*(void (*)(int, int, int, int))0x06028400)(4, 0x0605A634, arg3, arg4);
}

void FUN_06011450(void)
{
    int arg4 = 0x0000E000 + *(int *)(0x06063828 + 4);
    int arg3 = 0x10;
    (*(void (*)(int, int, int, int))0x06028400)(4, 0x0605A718, arg3, arg4);
}

void FUN_060285E0(int param_1, int param_2, int param_3)
{
    (*(void (*)(int, int, int, int))0x060283B8)(
        8, (((unsigned int)(param_2 << 8) >> 2) + param_1) << 1,
        0xFFFFF000, param_3);
}

void FUN_06028600(int param_1, int param_2, int param_3)
{
    (*(void (*)(int, int, int, int))0x060283E0)(
        8, (((unsigned int)(param_2 << 8) >> 2) + param_1) << 1,
        0xFFFFF000, param_3);
}
