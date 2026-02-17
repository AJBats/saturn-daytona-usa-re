#include "saturn.h"
#include "game.h"

/*
 * State handler jump table -- indexed by GAME_STATE (0-31)
 * Original addresses from jump table at 0x0600307C (32 entries):
 *   [0]  = 0x060088CC   [1]  = 0x0600890A   [2]  = 0x06008938
 *   [3]  = 0x06008A18   [4]  = 0x06008CCC   [5]  = 0x06008D74
 *   [6]  = 0x06008B04   [7]  = 0x06008B34   [8]  = 0x06008B78
 *   [9]  = 0x06008B9C   [10] = 0x06008BD8   [11] = 0x06008BFC
 *   [12] = 0x06008E00   [13] = 0x06008E48   [14] = 0x06008EBC
 *   [15] = 0x06009098   [16] = 0x06009290   [17] = 0x060092D0
 *   [18] = 0x060096DC   [19] = 0x06009788   [20] = 0x06009A60
 *   [21] = 0x06009C48   [22] = 0x06009E60   [23] = 0x06009F10
 *   [24] = 0x06009CFC   [25] = 0x06009D4E   [26] = 0x06009DD0
 *   [27] = 0x06009E02   [28] = 0x06009508   [29] = 0x0600955E
 *   [30] = 0x06008C14   [31] = 0x06008C76
 */
const state_handler_t state_handlers[] = {
    state_0_handler,       /* 0: game/course init */
    state_1_handler,       /* 1: transition */
    state_2_handler,       /* 2: first-run (init sets state=2) */
    state_3_handler,       /* 3: attract mode / title timeout */
    state_4_handler,       /* 4: state boundary normalizer */
    state_5_handler,       /* 5: timed/conditional branch */
    state_6_handler,       /* 6: course select init */
    state_7_handler,       /* 7: course select active */
    state_8_handler,       /* 8: car select init */
    state_9_handler,       /* 9: car select active */
    state_10_handler,      /* 10: loading init */
    state_11_handler,      /* 11: loading check */
    state_12_handler,      /* 12: race preparation */
    state_13_handler,      /* 13: race readiness check */
    state_14_handler,      /* 14: race first-frame setup */
    state_15_handler,      /* 15: MAIN RACE LOOP */
    state_16_handler,      /* 16: post-countdown cleanup */
    state_17_handler,      /* 17: post-lap results */
    state_18_handler,      /* 18: time extension setup */
    state_19_handler,      /* 19: time extension active */
    state_20_handler,      /* 20: race completion init */
    state_21_handler,      /* 21: post-race gameplay */
    state_22_handler,      /* 22: post-race transition */
    state_23_handler,      /* 23: counter transition */
    state_24_handler,      /* 24: post-race display init */
    state_25_handler,      /* 25: post-race display loop */
    state_26_handler,      /* 26: post-race transition alt */
    state_27_handler,      /* 27: counter transition alt */
    state_28_handler,      /* 28: abort processing */
    state_29_handler,      /* 29: abort menu */
    state_30_handler,      /* 30: resource check router */
    state_31_handler,      /* 31: memory router */
};

/*
 * boot() -- C entry point, called from start.s crt0
 *
 * start.s sets SP and clears SR, then jumps here.
 * All function calls use linker-resolved symbols — no hardcoded addresses.
 *
 * Sequence:
 *   1. Call system_init (FUN_060030FC) — game hardware + subsystem init
 *   2. Enter main loop:
 *      a. Call per_frame_setup (per-frame update)
 *      b. Read game state, compute bitmask, increment frame counter
 *      c. Dispatch to state handler via jump table
 */
void boot(void) __attribute__((noreturn));
void boot(void)
{
    int state;

    system_init();

    for (;;) {
        per_frame_setup();

        state = GAME_STATE;
        GAME_STATE_COPY = state;
        GAME_STATE_BIT = 1 << state;
        FRAME_COUNTER++;

        if (state >= 0 && state < NUM_GAME_STATES)
            state_handlers[state]();
    }
}
