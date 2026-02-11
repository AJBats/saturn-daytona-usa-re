#include "game.h"

/*
 * checkpoint_continue.c -- Checkpoint crossing continuation
 *
 * Hand-translated from binary at 0x0600DBA0 (~83 instructions).
 *
 * Functions:
 *   FUN_0600DBA0 (0x0600DBA0) -- Checkpoint crossing continuation
 *
 * Called after checkpoint crossing detection confirms a crossing.
 * Takes a threshold parameter (normally 4, set by caller via
 * alternate entry at 0x0600DB9E: mov #4,r3).
 *
 * If counter & 7 >= threshold: treats as false alarm, calls
 * FUN_0600DC74 (not-crossed clear).
 * Otherwise: renders checkpoint display (via FUN_06028400), then
 * periodically plays crossing sounds and manages event counter.
 *
 * Called from checkpoint_detect.c.
 */

/* External dependencies */
extern int FUN_06028400(int cmd, int src, int size, int dst);
extern void FUN_0600DC74(void);   /* not-crossed display clear */
extern void FUN_0601D5F4(int channel, int sound_id);

/* Detection counter (shared with checkpoint_detect.c) */
#define DETECT_COUNTER_PTR  ((volatile unsigned short *)0x06078698)

/* Crossing event counter (incremented each 64-frame boundary) */
#define EVENT_COUNTER_PTR   ((volatile int *)0x060786A8)

/* Game mode flag (1 = specific mode with alternate display/sound) */
#define GAME_MODE_FLAG      (*(volatile int *)0x06078644)

/* Display struct pointers for checkpoint rendering */
#define DISPLAY_STRUCT_A    0x060637F8  /* mode 1 display data */
#define DISPLAY_STRUCT_B    0x06063808  /* default display data */

/* Display offset added to struct[4] */
#define DISPLAY_OFFSET      0x4000

/* Display sizes per mode */
#define DISPLAY_SIZE_MODE1  0x0AC0
#define DISPLAY_SIZE_MODE0  0x0B3C

/* Crossing sounds */
#define CROSSING_SOUND_A    0xAE1138FF  /* standard crossing sound */
#define CROSSING_SOUND_B    0xAE1139FF  /* mode 1 sound (count >= 7) */

/* Race timer register */
#define RACE_TIMER_REG      ((volatile unsigned short *)0x06086054)


/* ================================================================
 * FUN_0600DBA0 -- Checkpoint Crossing Continuation (0x0600DBA0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600DBA0-0x0600DC72)
 * Pool verified:
 *   0x0600DBF4 = 0x060786A8 (event counter)
 *   0x0600DBF8 = 0x06078698 (detection counter)
 *   0x0600DBFC = 0x06078644 (game mode flag)
 *   0x0600DC00 = 0x060637F8 (display struct A)
 *   0x0600DC04 = 0x06028400 (VDP render function)
 *   0x0600DCA0 = 0x06063808 (display struct B)
 *   0x0600DCA4 = 0x06028400 (VDP render function, reused)
 *   0x0600DCA8 = 0x06078698 (detection counter, reused)
 *   0x0600DCAC = 0x0601D5F4 (sound dispatch)
 *   0x0600DCB0 = 0xAE1138FF (crossing sound A)
 *   0x0600DCB4 = 0x06078644 (game mode flag, reused)
 *   0x0600DCB8 = 0xAE1139FF (crossing sound B)
 *   0x0600DCBC = 0x06086054 (race timer register)
 * Word pool:
 *   0x0600DBDC = 0x4000 (display offset, path 1)
 *   0x0600DBDE = 0x0AC0 (display size mode 1)
 *   0x0600DC98 = 0x4000 (display offset, path 2)
 *   0x0600DC9A = 0x0B3C (display size mode 0)
 *
 * Input: threshold in r3 (set by caller, normally 4)
 *   Alternate entry 0x0600DB9E: mov #4,r3 → falls through
 *
 * Algorithm:
 *   1. If (counter & 7) >= threshold → FUN_0600DC74 (false alarm)
 *   2. Else render checkpoint: select display struct by game mode,
 *      call FUN_06028400(8, struct[0], size, struct[4]+0x4000)
 *   3. Common: if counter divisible by 64:
 *      a. Increment event counter
 *      b. If count < 7: play standard sound
 *      c. If count >= 7: play mode-dependent sound, set timer=40,
 *         reset event counter
 *
 * ~83 instructions. Saves r14, r13, PR. 4 bytes stack.
 * ================================================================ */
void FUN_0600DBA0(int threshold)
{
    int counter = (unsigned short)*DETECT_COUNTER_PTR;

    if ((counter & 7) >= threshold) {
        /* Counter exceeded threshold: false alarm, clear display */
        FUN_0600DC74();
    } else {
        /* Confirmed crossing: render checkpoint display */
        int display_struct;
        int display_size;

        if (GAME_MODE_FLAG == 1) {
            display_struct = DISPLAY_STRUCT_A;
            display_size = DISPLAY_SIZE_MODE1;
        } else {
            display_struct = DISPLAY_STRUCT_B;
            display_size = DISPLAY_SIZE_MODE0;
        }

        int src = *(volatile int *)display_struct;
        int dst = *(volatile int *)(display_struct + 4) + DISPLAY_OFFSET;
        FUN_06028400(8, src, display_size, dst);
    }

    /* Common path: periodic sound and event management */
    counter = (unsigned short)*DETECT_COUNTER_PTR;

    if ((counter & 0x3F) != 0)
        return;

    /* 64-frame boundary: process crossing event */
    int event_count = *EVENT_COUNTER_PTR + 1;
    *EVENT_COUNTER_PTR = event_count;

    if ((unsigned int)event_count < 7) {
        /* Early crossings: play standard sound */
        FUN_0601D5F4(0, CROSSING_SOUND_A);
        return;
    }

    /* 7+ crossings: play mode-dependent sound and reset */
    int sound;
    if (GAME_MODE_FLAG == 1) {
        sound = CROSSING_SOUND_B;
    } else {
        sound = CROSSING_SOUND_A;
    }
    FUN_0601D5F4(0, sound);

    /* Set race timer and reset event counter */
    *RACE_TIMER_REG = 40;
    *EVENT_COUNTER_PTR = 0;
}
