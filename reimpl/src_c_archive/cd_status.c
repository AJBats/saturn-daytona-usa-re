#include "game.h"

/*
 * cd_status.c -- CD block status query
 *
 * Hand-translated from binary at 0x06041648 (32 instructions).
 *
 * Functions:
 *   FUN_06041648 (0x06041648) -- Query CD status and execute command
 *
 * Queries CD block status via FUN_06036518 (CD status read), and if
 * successful, executes a CD command via FUN_060349B6 (CD command exec).
 * Copies the first byte of command result to a data block at offset 0x40.
 * Returns the CD status code, or -10 on error.
 *
 * Called from cd_block.c initialization code.
 */

/* CD status query function (batch L1 in batch_cd_system_36.c) */
extern int FUN_06036518(int *a, int *b, int *c);

/* CD command execute (in cd_cmd.c) */
extern int FUN_060349B6(void);

/* Data block pointer */
#define CD_DATA_BLOCK_PTR  (*(volatile int *)0x060A5400)


/* ================================================================
 * FUN_06041648 -- CD Status Query (0x06041648)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06041648-0x06041696)
 * Pool verified:
 *   0x06041674 = 0x06036518 (CD status query)
 *   0x0604172C = 0x060349B6 (CD command exec)
 *   0x06041730 = 0x060A5400 (data block pointer)
 *
 * Algorithm:
 *   1. Allocate 24-byte stack frame
 *   2. Call FUN_06036518(&local_18, &local_14, &local_1c)
 *   3. If error (!= 0): return -10
 *   4. Call FUN_060349B6() with result buffer
 *   5. Copy first byte of result to *(data_block + 0x40)
 *   6. Return local_1c (status code)
 *
 * 32 instructions. Saves PR. 24-byte stack frame.
 * ================================================================ */
#if 0 /* FUN_06041648 -- replaced by ASM import */
int FUN_06041648(void)
{
    int local_1c;
    int local_18;
    int local_14;
    char local_10[16];
    int result;

    /* Query CD status */
    result = FUN_06036518(&local_18, &local_14, &local_1c);
    if (result != 0) {
        return -10;  /* 0xFFFFFFF6 */
    }

    /* Execute CD command */
    FUN_060349B6();

    /* Copy first result byte to data block at offset 0x40 */
    {
        volatile char *data_block = (volatile char *)CD_DATA_BLOCK_PTR;
        data_block[0x40] = local_10[0];
    }

    return local_1c;
}
#endif

/* FUN_06041648 -- original binary (80 bytes) */
__asm__(
    ".section .text.FUN_06041648, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06041648\n"
    ".type _FUN_06041648, @function\n"
    "_FUN_06041648:\n"
    ".byte 0x4F, 0x22, 0x7F, 0xE8, 0x66, 0xF3, 0x65, 0xF3, 0x64, 0xF3, 0xD3, 0x08, 0x75, 0x08, 0x43, 0x0B\n"  /* 0x06041648 */
    ".byte 0x74, 0x04, 0x64, 0x03, 0x24, 0x48, 0x89, 0x0B, 0x7F, 0x18, 0x4F, 0x26, 0x00, 0x0B, 0xE0, 0xF6\n"  /* 0x06041658 */
    ".byte 0x06, 0x03, 0x6A, 0xF2, 0x06, 0x03, 0x49, 0xB6, 0x06, 0x0A, 0x54, 0x00, 0x06, 0x03, 0x65, 0x18\n"  /* 0x06041668 */
    ".byte 0x64, 0xF3, 0xD3, 0x2C, 0x43, 0x0B, 0x74, 0x0C, 0xD2, 0x2B, 0x62, 0x22, 0x63, 0xF3, 0x73, 0x0C\n"  /* 0x06041678 */
    ".byte 0x61, 0x30, 0xE0, 0x40, 0x02, 0x14, 0x60, 0xF2, 0x7F, 0x18, 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06041688 */
);

