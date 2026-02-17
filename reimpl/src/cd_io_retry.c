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
#if 0 /* FUN_06012C3C -- replaced by ASM import */
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
#endif

/* FUN_06012C3C -- original binary (184 bytes) */
__asm__(
    ".section .text.FUN_06012C3C, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06012C3C\n"
    ".global _FUN_06012c3c\n"
    ".type _FUN_06012C3C, @function\n"
    "_FUN_06012C3C:\n"
    "_FUN_06012c3c:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x2F, 0x96, 0x2F, 0x86, 0x4F, 0x22\n"  /* 0x06012C3C */
    ".byte 0x7F, 0xF4, 0xD8, 0x0F, 0xDA, 0x0F, 0xDB, 0x10, 0xED, 0x05, 0xDE, 0x10, 0x2F, 0x42, 0x1F, 0x51\n"  /* 0x06012C4C */
    ".byte 0xE4, 0xFF, 0x6C, 0x43, 0x1F, 0x42, 0xA0, 0x1D, 0xE9, 0x00, 0x0A, 0x1A, 0x06, 0x01, 0x8E, 0xAC\n"  /* 0x06012C5C */
    ".byte 0x06, 0x04, 0x48, 0xD4, 0x00, 0x00, 0xE0, 0x00, 0x06, 0x02, 0x83, 0xE0, 0x06, 0x06, 0x12, 0xC4\n"  /* 0x06012C6C */
    ".byte 0x06, 0x06, 0x12, 0xB4, 0x06, 0x02, 0x76, 0x1E, 0x06, 0x03, 0x4C, 0x48, 0x06, 0x05, 0xAC, 0xCA\n"  /* 0x06012C7C */
    ".byte 0x06, 0x03, 0xB1, 0xB6, 0x06, 0x08, 0x4A, 0xEC, 0x06, 0x03, 0xAE, 0x08, 0x06, 0x00, 0x02, 0x6C\n"  /* 0x06012C8C */
    ".byte 0xBF, 0x9E, 0x00, 0x09, 0x60, 0xA0, 0x20, 0x08, 0x8B, 0xFA, 0x4B, 0x0B, 0x64, 0xF2, 0x79, 0x01\n"  /* 0x06012C9C */
    ".byte 0x39, 0xD3, 0x8F, 0x03, 0x6C, 0x03, 0x62, 0xE2, 0x42, 0x0B, 0x00, 0x09, 0x4C, 0x11, 0x8B, 0xF4\n"  /* 0x06012CAC */
    ".byte 0xE2, 0x00, 0x2F, 0x22, 0xE7, 0xFF, 0xE5, 0x00, 0x56, 0xF1, 0x48, 0x0B, 0x64, 0xC3, 0x69, 0x03\n"  /* 0x06012CBC */
    ".byte 0x63, 0xF2, 0x73, 0x01, 0x33, 0xD3, 0x8F, 0x03, 0x2F, 0x32, 0x63, 0xE2, 0x43, 0x0B, 0x00, 0x09\n"  /* 0x06012CCC */
    ".byte 0x49, 0x11, 0x8B, 0xEF, 0x7F, 0x0C, 0x4F, 0x26, 0x68, 0xF6, 0x69, 0xF6, 0x6A, 0xF6, 0x6B, 0xF6\n"  /* 0x06012CDC */
    ".byte 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06012CEC */
);

