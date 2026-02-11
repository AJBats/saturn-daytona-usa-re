#include "game.h"

/*
 * cd_io_retry.c -- CD block I/O with retry and busy-wait
 *
 * Hand-translated from binary at 0x06012C3C (92 instructions).
 *
 * Functions:
 *   FUN_06012C3C (0x06012C3C) -- CD I/O command with retry loop
 *
 * Executes a two-phase CD I/O operation with automatic retry:
 *
 * Phase 1: Issue CD command
 *   1. Busy-wait for CD flag (byte at 0x06084AEC) to be 0,
 *      calling FUN_06012BDC each iteration while waiting
 *   2. Call FUN_0603AE08(param_1) — issue CD command
 *   3. If result < 0 (error), retry from step 1
 *   4. Every 5 iterations, call a yield callback via *(0x0600026C)
 *
 * Phase 2: Transfer data
 *   1. Call FUN_0603B1B6(phase1_result, 0, param_2, -1) — transfer
 *   2. If result < 0 (error), retry
 *   3. Every 5 iterations, call the same yield callback
 *
 * The yield callback at *(int *)0x0600026C is likely a frame
 * sync / task yield to prevent starving other subsystems during
 * long CD operations.
 *
 * Called from race_init and other loading sequences.
 *
 * Original address: 0x06012C3C
 */

/* CD busy flag */
#define CD_FLAG          (*(volatile unsigned char *)0x06084AEC)

/* Yield callback function pointer */
#define YIELD_CALLBACK   (*(volatile int *)0x0600026C)

/* Max iterations before yield */
#define YIELD_THRESHOLD  5

/* Sub-functions */
extern void FUN_06012BDC(void);                  /* CD status poll */
extern int  FUN_0603AE08(int command);            /* CD command issue */
extern int  FUN_0603B1B6(int handle, int zero, int dest, int flag); /* CD data transfer */


/* ================================================================
 * FUN_06012C3C -- CD I/O Command with Retry (0x06012C3C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06012C3C-0x06012CF2)
 * Pool verified:
 *   0x06012C8C = 0x0603B1B6 (CD data transfer function)
 *   0x06012C90 = 0x06084AEC (CD busy flag byte)
 *   0x06012C94 = 0x0603AE08 (CD command issue function)
 *   0x06012C98 = 0x0600026C (yield callback pointer)
 * Inline pool:
 *   0x06012C66 = 0x060A1A06 (not used — misaligned data)
 *   0x06012C68 = 0x06018EAC (not used — data area)
 *
 * 92 instructions. Saves r8-r14, PR. 12-byte stack frame.
 * ================================================================ */
void FUN_06012C3C(int command, int dest)
{
    int result = -1;
    int count;

    /* === Phase 1: Issue CD command with retry === */
    count = 0;
    while (result < 0) {
        /* Busy-wait for CD ready (flag == 0) */
        while (CD_FLAG != 0) {
            FUN_06012BDC();
        }

        /* Issue CD command */
        result = FUN_0603AE08(command);

        /* Yield every 5 iterations */
        count++;
        if (count >= YIELD_THRESHOLD) {
            ((void (*)(void))YIELD_CALLBACK)();
        }
    }

    /* === Phase 2: Transfer data with retry === */
    {
        int xfer_result = -1;
        int xfer_count = 0;

        while (xfer_result < 0) {
            /* Transfer data: handle=phase1_result, zero=0, dest=param_2, flag=-1 */
            xfer_result = FUN_0603B1B6(result, 0, dest, -1);

            /* Yield every 5 iterations */
            xfer_count++;
            if (xfer_count >= YIELD_THRESHOLD) {
                ((void (*)(void))YIELD_CALLBACK)();
            }
        }
    }
}
