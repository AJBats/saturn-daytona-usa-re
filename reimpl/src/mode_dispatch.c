/* mode_dispatch.c -- Mode-based function pointer dispatch
 *
 * Functions:
 *   FUN_0601FD74 (0x0601FD74) -- Dispatch via function pointer table
 *
 * Copies a 4-entry function table from ROM (0x0605F498) to the stack,
 * reads a 16-bit mode index from 0x06087804, and calls the function
 * pointer at table[mode]. The table holds up to 4 function pointers
 * for different operational modes.
 *
 * FUN_06035168 is a block copy function: copy(r0=count, r1=dest, r2=src).
 *
 * Original address: 0x0601FD74
 */

/* Block copy: copies r0 bytes from r2 to r1 */
extern void FUN_06035168(void);

/* Function table source (4 function pointers in ROM) */
#define FUNC_TABLE_SRC   0x0605F498

/* Mode index register (16-bit) */
#define MODE_INDEX       (*(volatile unsigned short *)0x06087804)


/* ================================================================
 * FUN_0601FD74 -- Mode Function Dispatch (0x0601FD74)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601FD74-0x0601FD9A)
 * Pool verified:
 *   0x0601FDF4 = 0x0605F498 (function table source)
 *   0x0601FDF8 = 0x06035168 (block copy function)
 *   0x0601FDFC = 0x06087804 (mode index address)
 *
 * 20 instructions. Saves PR.
 * ================================================================ */
void FUN_0601FD74(void)
{
    typedef void (*func_ptr)(void);
    func_ptr table[4];

    /* Copy 4 function pointers from ROM table to local stack */
    {
        volatile int *src = (volatile int *)FUNC_TABLE_SRC;
        table[0] = (func_ptr)src[0];
        table[1] = (func_ptr)src[1];
        table[2] = (func_ptr)src[2];
        table[3] = (func_ptr)src[3];
    }

    /* Read mode index (0-3) and dispatch */
    {
        unsigned int mode = MODE_INDEX;
        table[mode]();
    }
}
