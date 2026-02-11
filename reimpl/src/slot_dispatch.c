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
