/* mode_dispatch.c -- Mode-based function pointer dispatch
 *
 * Functions:
 *   FUN_0601FD74 (0x0601FD74) -- Dispatch via function pointer table
 *   FUN_0601AEB6 (0x0601AEB6) -- Jump table dispatcher via byte index
 *   FUN_0601FD9C (0x0601FD9C) -- Race data table select + init
 *
 * FUN_0601FD74: Copies a 4-entry function table from ROM (0x0605F498)
 * to the stack, reads a 16-bit mode index from 0x06087804, and calls
 * the function pointer at table[mode].
 *
 * FUN_0601AEB6: Reads a byte index from 0x06086011, looks up function
 * pointer in table at 0x0605DEC8, and tail-calls it. Used by
 * pre_race_state_handlers and state_init_handlers.
 *
 * FUN_06035168 is a block copy function: copy(r0=count, r1=dest, r2=src).
 *
 * Original addresses: 0x0601FD74, 0x0601AEB6, 0x0601FD9C
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


/* ================================================================
 * FUN_0601AEB6 -- Jump Table Dispatcher (0x0601AEB6)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601AEB6-0x0601AEC6)
 * Pool verified:
 *   [0x0601AEDC] = 0x06086011 (byte index source)
 *   [0x0601AF00] = 0x0605DEC8 (function pointer table base)
 *
 * Reads a byte index from 0x06086011, looks up in function pointer
 * table at 0x0605DEC8, and tail-calls the target. 8 instructions.
 * Leaf function (no PR save), uses jmp for tail-call dispatch.
 * ================================================================ */
void FUN_0601AEB6(void)
{
    unsigned int idx = *(volatile unsigned char *)0x06086011;
    void (*fn)(void) = (void (*)(void))*(volatile int *)(0x0605DEC8 + idx * 4);
    fn();
}


/* Race rendering init (called via FUN_0601FD9C) */
extern void FUN_0601fe20(void);

/* Additional rendering setup for states 22/23 */
extern void FUN_060200a4(void);

/* ================================================================
 * FUN_0601FD9C -- Race Data Table Select + Init (0x0601FD9C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601FD9C-0x0601FDF0)
 * Pool verified:
 *   [0x0601FE00] = 0x060877F8 (race data pointer destination)
 *   [0x0601FE04] = 0x0607EBC4 (mode flags register)
 *   [0x0601FE08] = 0x00800000 (bit 23 mask)
 *   [0x0601FE0C] = 0x0607EAD8 (car index source)
 *   [0x0601FE10] = 0x0605F62C (data table A — bit 23 set path)
 *   [0x0601FE14] = 0x0605F5EC (data table B — bit 23 clear path)
 *   [0x0601FE18] = 0x060877F4 (struct first-word destination)
 *   [0x0601FE1C] = 0x0605AD10 (state register)
 *
 * Selects a data table entry based on mode flag bit 23 and car index.
 * Stores the result at 0x060877F8, copies first struct word to
 * 0x060877F4, calls race init (FUN_0601FE20). If state is 22 or 23,
 * tail-calls additional rendering setup (FUN_060200A4).
 *
 * 28 instructions. Saves PR.
 * ================================================================ */
void FUN_0601FD9C(void)
{
    int mode_flags = *(volatile int *)0x0607EBC4;
    int car_index = *(volatile int *)0x0607EAD8;
    int entry;

    /* Select data table based on bit 23 of mode flags */
    if (mode_flags & 0x00800000) {
        entry = *(volatile int *)(0x0605F62C + car_index * 4);
    } else {
        entry = *(volatile int *)(0x0605F5EC + car_index * 4);
    }

    /* Store selected data pointer */
    *(volatile int *)0x060877F8 = entry;

    /* Copy first word of selected struct to secondary location */
    *(volatile int *)0x060877F4 = *(volatile int *)entry;

    /* Initialize race rendering data */
    FUN_0601fe20();

    /* If game state is 22 or 23, perform additional rendering setup */
    {
        int state = *(volatile int *)0x0605AD10;
        if (state == 22 || state == 23) {
            FUN_060200a4();  /* tail-call in original */
        }
    }
}
