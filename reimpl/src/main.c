#include "saturn.h"
#include "game.h"

/*
 * State handler jump table -- indexed by GAME_STATE (0-17)
 * Original addresses from jump table at 0x0600307C:
 *   [0]  = 0x060088CC   [1]  = 0x0600890A   [2]  = 0x06008938
 *   [3]  = 0x06008A18   [4]  = 0x06008CCC   [5]  = 0x06008D74
 *   [6]  = 0x06008B04   [7]  = 0x06008B34   [8]  = 0x06008B78
 *   [9]  = 0x06008B9C   [10] = 0x06008BD8   [11] = 0x06008BFC
 *   [12] = 0x06008E00   [13] = 0x06008E48   [14] = 0x06008EBC
 *   [15] = 0x06009098   [16] = 0x06009290   [17] = 0x06009290
 */
const state_handler_t state_handlers[] = {
    state_0_handler,
    state_1_handler,
    state_2_handler,
    state_3_handler,
    state_4_handler,
    state_5_handler,
    state_6_handler,
    state_7_handler,
    state_8_handler,
    state_9_handler,
    state_10_handler,
    state_11_handler,
    state_12_handler,
    state_13_handler,
    state_14_handler,
    state_15_handler,
    state_16_handler,
    state_17_handler,
};

/*
 * boot() -- C entry point, called from start.s
 *
 * Mirrors the original entry at 0x06003000:
 *   1. Call system_init (FUN_060030FC)
 *   2. Enter main loop:
 *      a. Call FUN_0600A392 (per-frame update)
 *      b. Read game state
 *      c. Compute state bitmask (1 << state)
 *      d. Increment frame counter
 *      e. Dispatch to state handler
 *      f. Repeat
 */
void boot(void) __attribute__((noreturn));
void boot(void)
{
    int state;

    system_init();

    for (;;) {
        FUN_0600A392();

        state = GAME_STATE;
        GAME_STATE_COPY = state;
        GAME_STATE_BIT = 1 << state;
        FRAME_COUNTER++;

        if (state >= 0 && state < 18)
            state_handlers[state]();
    }
}
