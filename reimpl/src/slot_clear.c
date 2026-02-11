#include "game.h"

/*
 * slot_clear.c -- Clear a slot entry in the object/entity table
 *
 * Hand-translated from binary at 0x06020DEE (36 instructions).
 *
 * Functions:
 *   FUN_06020DEE (0x06020DEE) -- Clear slot entry
 *
 * Takes a byte index, computes base + index*68 to locate a 68-byte
 * entry in the table at 0x0608782C, and zeroes most fields.
 *
 * Called from various subsystems.
 */

/* Table base address, 68-byte entries */
#define SLOT_TABLE_BASE  0x0608782C
#define SLOT_ENTRY_SIZE  68


/* ================================================================
 * FUN_06020DEE -- Clear Slot Entry (0x06020DEE)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06020DEE-0x06020E34)
 * Pool verified:
 *   0x06020E38 = 0x0608782C (slot table base)
 *
 * Algorithm:
 *   1. entry = base + (byte)arg * 68
 *   2. Zero bytes at offsets 0, 1, 2
 *   3. Zero ints at offsets 0x04-0x38 (14 ints)
 *   4. Zero bytes at offsets 64, 65
 *   (Leaves byte 3, bytes 60-63, and bytes 66-67 untouched)
 *
 * 36 instructions. Leaf function.
 * ================================================================ */
void FUN_06020DEE(int arg)
{
    int idx = (unsigned char)arg;
    volatile char *entry = (volatile char *)(SLOT_TABLE_BASE + idx * SLOT_ENTRY_SIZE);
    volatile int *entry_i = (volatile int *)(entry + 4);

    /* Clear header bytes */
    entry[0] = 0;
    entry[1] = 0;
    entry[2] = 0;

    /* Clear ints at offsets 0x04 through 0x38 (14 longwords) */
    entry_i[0]  = 0;  /* 0x04 */
    entry_i[1]  = 0;  /* 0x08 */
    entry_i[2]  = 0;  /* 0x0C */
    entry_i[3]  = 0;  /* 0x10 */
    entry_i[4]  = 0;  /* 0x14 */
    entry_i[5]  = 0;  /* 0x18 */
    entry_i[6]  = 0;  /* 0x1C */
    entry_i[7]  = 0;  /* 0x20 */
    entry_i[8]  = 0;  /* 0x24 */
    entry_i[9]  = 0;  /* 0x28 */
    entry_i[10] = 0;  /* 0x2C */
    entry_i[11] = 0;  /* 0x30 */
    entry_i[12] = 0;  /* 0x34 */
    entry_i[13] = 0;  /* 0x38 */

    /* Clear tail bytes */
    entry[64] = 0;
    entry[65] = 0;
}
