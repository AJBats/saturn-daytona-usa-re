#include "game.h"

/*
 * slot_dispatch.c -- Slot-based function table dispatcher
 *
 * Hand-translated from binary at 0x0601712C (64 instructions).
 *
 * Functions:
 *   FUN_0601712C (0x0601712C) -- Object slot dispatch iterator
 *
 * Iterates 18 object slots. For each slot, reads a type byte from a
 * 68-byte entry in the slot table at 0x06084FC8. If non-zero, uses
 * (type - 1) as an index into a function pointer table (22 entries,
 * copied from 0x0605BC14) and calls the function with the slot index.
 *
 * This is a key scene/rendering dispatch system: each slot can hold
 * a different object type, and the type byte selects which handler
 * function processes it. The handler receives the slot index (0-17)
 * so it can find the slot's full 68-byte data block.
 *
 * The original copies the function pointer table to the stack via
 * FUN_06035168 (memcpy-like, non-standard register calling convention
 * using r0/r1/r2). We inline the copy here.
 *
 * Called from course_select.c (FUN_06014A42).
 *
 * Original address: 0x0601712C
 */

/* Slot table: 18 entries, each 68 bytes. Byte 0 = type indicator */
#define SLOT_TABLE_BASE    ((volatile unsigned char *)0x06084FC8)
#define SLOT_ENTRY_SIZE    68    /* 0x44 bytes per slot */
#define SLOT_COUNT         18

/* Source function pointer table (22 pointers = 88 bytes) */
#define FUNC_PTR_SOURCE    ((volatile int *)0x0605BC14)
#define FUNC_PTR_COUNT     22    /* 88 / 4 */


/* ================================================================
 * FUN_0601712C -- Object Slot Dispatch Iterator (0x0601712C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601712C-0x06017196)
 * Pool verified:
 *   0x060171A0 = 0x06084FC8 (slot table base)
 *   0x060171A4 = 0x0605BC14 (function pointer source table)
 *   0x060171A8 = 0x06035168 (block copy function)
 *
 * 64 instructions. Saves r11-r14, PR. 88-byte stack frame.
 * ================================================================ */
#if 0 /* FUN_0601712C -- replaced by ASM import */
void FUN_0601712C(void)
{
    /* Copy function pointer table to local array
     * (Original: FUN_06035168 with r0=88, r1=dest, r2=0x0605BC14) */
    int func_ptrs[FUNC_PTR_COUNT];
    {
        int i;
        for (i = 0; i < FUNC_PTR_COUNT; i++)
            func_ptrs[i] = FUNC_PTR_SOURCE[i];
    }

    /* Iterate 18 object slots */
    {
        unsigned char idx = 0;

        while (idx < SLOT_COUNT) {
            /* Read type byte from first byte of slot entry */
            unsigned char slot_type =
                SLOT_TABLE_BASE[(unsigned short)(idx * SLOT_ENTRY_SIZE)];

            if (slot_type != 0) {
                /* Dispatch through function pointer table:
                 * index = (type - 1), call handler with slot index */
                void (*handler)(int) =
                    (void (*)(int))func_ptrs[slot_type - 1];
                handler((int)idx);
            }

            idx++;
        }
    }
}
#endif

/* FUN_0601712C -- original binary (128 bytes) */
__asm__(
    ".section .text.FUN_0601712C, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0601712C\n"
    ".global _FUN_0601712c\n"
    ".type _FUN_0601712C, @function\n"
    "_FUN_0601712C:\n"
    "_FUN_0601712c:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x4F, 0x22, 0xEB, 0x12, 0x7F, 0xA8, 0x6C, 0xF3\n"  /* 0x0601712C */
    ".byte 0xDD, 0x18, 0x61, 0xF3, 0xD2, 0x18, 0xD3, 0x19, 0x43, 0x0B, 0xE0, 0x58, 0xEE, 0x00, 0x62, 0xEC\n"  /* 0x0601713C */
    ".byte 0x63, 0x23, 0x42, 0x08, 0x43, 0x08, 0x43, 0x08, 0x43, 0x08, 0x32, 0x3C, 0x62, 0x2F, 0x32, 0xDC\n"  /* 0x0601714C */
    ".byte 0x62, 0x20, 0x62, 0x2C, 0x22, 0x28, 0x89, 0x0E, 0x60, 0xEC, 0x63, 0x03, 0x40, 0x08, 0x43, 0x08\n"  /* 0x0601715C */
    ".byte 0x43, 0x08, 0x43, 0x08, 0x30, 0x3C, 0x60, 0x0F, 0x00, 0xDC, 0x60, 0x0C, 0x70, 0xFF, 0x40, 0x08\n"  /* 0x0601716C */
    ".byte 0x03, 0xCE, 0x43, 0x0B, 0x64, 0xE3, 0x7E, 0x01, 0x62, 0xEC, 0x32, 0xB3, 0x8B, 0xDF, 0x7F, 0x58\n"  /* 0x0601717C */
    ".byte 0x4F, 0x26, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x06, 0x01, 0x8D, 0xDC\n"  /* 0x0601718C */
    ".byte 0x06, 0x01, 0x8E, 0x1E, 0x06, 0x08, 0x4F, 0xC8, 0x06, 0x05, 0xBC, 0x14, 0x06, 0x03, 0x51, 0x68\n"  /* 0x0601719C */
);

