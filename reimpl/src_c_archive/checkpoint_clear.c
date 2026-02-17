#include "game.h"

/*
 * checkpoint_clear.c -- Checkpoint not-crossed display clear
 *
 * Hand-translated from binary at 0x0600DC74 (14 instructions).
 *
 * Functions:
 *   FUN_0600DC74 (0x0600DC74) -- Clear checkpoint display state
 *
 * Called when checkpoint crossing detection fails or when the
 * crossing counter exceeds threshold. Writes two VDP commands
 * to clear/reset the checkpoint display elements.
 *
 * Called from checkpoint_detect.c and checkpoint_continue.c.
 */

/* External dependencies */
extern void FUN_060284AE(int cmd, int pos, int size, int buffer);

/* Display buffer for checkpoint VDP commands */
#define CHECKPOINT_DISPLAY_BUF  0x0605ACE8


/* ================================================================
 * FUN_0600DC74 -- Checkpoint Display Clear (0x0600DC74)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600DC74-0x0600DC96)
 * Pool verified:
 *   0x0600DCC0 = 0x0605ACE8 (checkpoint display buffer)
 *   0x0600DCC4 = 0x060284AE (VDP command write)
 * Word pool:
 *   0x0600DC9C = 0x0ABC (command position 1)
 *   0x0600DC9E = 0x0BBC (command position 2)
 *
 * Algorithm:
 *   1. Call FUN_060284AE(8, 0x0ABC, 96, buffer) — clear cmd 1
 *   2. Tail-call FUN_060284AE(8, 0x0BBC, 96, buffer) — clear cmd 2
 *
 * 14 instructions (0x0600DC74-0x0600DC96). Saves PR, 4 bytes stack.
 * ================================================================ */
void FUN_0600DC74(void)
{
    FUN_060284AE(8, 0x0ABC, 96, CHECKPOINT_DISPLAY_BUF);
    FUN_060284AE(8, 0x0BBC, 96, CHECKPOINT_DISPLAY_BUF);
}
