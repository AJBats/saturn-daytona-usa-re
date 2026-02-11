#include "game.h"

/*
 * cd_command_exec.c -- CD block command execution wrapper
 *
 * Hand-translated from binary at 0x06035F04 (9 instructions).
 *
 * Functions:
 *   FUN_06035F04 (0x06035F04) -- Execute CD command via FUN_06035168
 *
 * Sets up r0=12 (command mode), r2=0x06063594 (CD command buffer),
 * and calls FUN_06035168 (CD command processor). Uses non-standard
 * register passing (r0/r1/r2) beyond the C calling convention.
 *
 * NOTE: The L1 batch version of FUN_06035168 (batch_cd_system_34.c)
 * does not correctly handle the register-passed parameters, so this
 * function currently has no effect beyond calling the batch stub.
 *
 * Called from cd_cmd.c (FUN_060349B6).
 */

/* CD command processor (batch L1 in batch_cd_system_34.c) */
extern void FUN_06035168(void);

/* CD command buffer address */
#define CD_CMD_BUFFER  0x06063594


/* ================================================================
 * FUN_06035F04 -- CD Command Execution (0x06035F04)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06035F04-0x06035F14)
 * Pool verified:
 *   0x06035F38 = 0x06063594 (CD command buffer)
 *   0x06035F3C = 0x06035168 (CD command processor)
 *
 * Algorithm:
 *   1. Set r0 = 12 (command mode)
 *   2. Set r1 = arg (from r4), r2 = 0x06063594 (buffer)
 *   3. Call FUN_06035168
 *   4. Return
 *
 * 9 instructions. Saves PR only.
 * ================================================================ */
void FUN_06035F04(void)
{
    /*
     * Original binary register setup before FUN_06035168 call:
     *   r0 = 12 (command mode / byte count)
     *   r1 = caller's r4 (command data pointer)
     *   r2 = 0x06063594 (CD command buffer)
     *   r4 = caller's r4 (preserved)
     *
     * These are non-standard register parameters that the C calling
     * convention does not support. The call here just invokes the
     * batch L1 stub.
     */
    FUN_06035168();
}
