/*
 * cd_block.c -- CD Block (CDB) hardware interface
 *
 * CD Block registers at 0x25890000+
 * Translated from production ASM / existing decomp src/*.c
 */

#include "saturn.h"

/* FUN_06035C48 -- Return CD block base address */
void *cd_get_base_addr(void)
{
    return (void *)0x25818000;
}

/* FUN_06035C4E -- Read CD HIRQ request register */
int cd_read_hirq(void)
{
    return (int)CD_HIRQREQ;
}

/* FUN_06035C6E -- Write CD HIRQ request register */
void cd_write_hirq(short val)
{
    CD_HIRQREQ = val;
}

/* FUN_06035C92 -- Set bits in CD status word (work RAM 0x06063590) */
void cd_set_status_bits(unsigned short bits)
{
    *(volatile unsigned short *)0x06063590 |= bits;
}
