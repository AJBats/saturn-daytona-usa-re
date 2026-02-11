#include "game.h"

/*
 * sequence_player.c -- Animation/event sequence player
 *
 * Hand-translated from binary at 0x06014F34 (131 instructions).
 *
 * Functions:
 *   FUN_06014F34 (0x06014F34) -- Sequence step controller
 *
 * Plays through a sequence of entries from a data table, assigning
 * object types into the 18-slot dispatch table (0x06084FC8) used by
 * FUN_0601712C (slot_dispatch.c). Each sequence entry is 3 bytes:
 *   [0] = slot type byte (which handler to assign in the slot table)
 *   [1] = timer duration (loaded into timer_A as a short)
 *   [2] = parameter byte (stored at offset 64 in the slot entry)
 *
 * The data table is selected based on game state:
 *   State 25 AND flag bit 0: 0x0605B7A6 (40 entries)
 *   State 21:                 0x0605B821 (6 entries)
 *   Default:                  0x0605B73A (35 entries)
 *
 * Each step, the timer counts down by a decrement value (from 0x0606BDF8).
 * When the timer expires, FUN_06017372(0) is called to find an empty
 * slot (type byte == 0), and the next entry's data is written there.
 * If the new type is 21, the counter is set to 100 (sequence end marker).
 * If the new timer is 0, it immediately processes the next entry.
 *
 * Called from course_select.c (FUN_06014A42).
 *
 * Original address: 0x06014F34
 */

/* Timer/counter registers (16-bit shorts) */
#define TIMER_A           (*(volatile short *)0x06085F94)
#define SEQ_COUNTER       (*(volatile short *)0x06085F90)

/* Game state */
#define GAME_STATE        (*(volatile int *)0x0605AD10)
#define STATE_FLAGS       (*(volatile int *)0x0607EBF4)

/* Timer decrement value */
#define TIMER_DECREMENT   (*(volatile int *)0x0606BDF8)

/* Slot table (same as slot_dispatch.c) */
#define SLOT_TABLE_BASE   0x06084FC8
#define SLOT_ENTRY_SIZE   68    /* 0x44 bytes per entry */

/* Data tables: 3 bytes per entry (type, timer, param) */
#define TABLE_DEFAULT     ((unsigned char *)0x0605B73A)
#define TABLE_STATE25     ((unsigned char *)0x0605B7A6)
#define TABLE_STATE21     ((unsigned char *)0x0605B821)

/* Slot search: find first slot with type byte matching param */
extern unsigned char FUN_06017372(int param);


/* ================================================================
 * FUN_06014F34 -- Sequence Step Controller (0x06014F34)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06014F34-0x06015038)
 * Pool verified:
 *   0x06015008 = 0x06085F94 (timer A)
 *   0x0601500C = 0x06085F90 (sequence counter)
 *   0x06015010 = 0x0605B73A (default data table)
 *   0x06015014 = 0x0605AD10 (game state)
 *   0x06015018 = 0x0607EBF4 (state flags)
 *   0x0601501C = 0x0605B7A6 (state 25 data table)
 *   0x06015020 = 0x0605B821 (state 21 data table)
 *   0x06015024 = 0x0606BDF8 (timer decrement)
 *   0x06015028 = 0x06017372 (slot search function)
 *   0x0601502C = 0x06084FC8 (slot table)
 *
 * 131 instructions. Saves r12-r14, PR.
 * ================================================================ */
void FUN_06014F34(void)
{
    unsigned char *data_table;
    unsigned int limit;

    /* === Phase 1: Select data table and limit based on game state === */
    {
        int state = GAME_STATE;

        if (state == 25 && (STATE_FLAGS & 1) != 0) {
            /* State 25 with flag bit 0 set: alternate table A */
            data_table = TABLE_STATE25;
            limit = 40;
        } else if (state == 21) {
            /* State 21: short sequence table */
            data_table = TABLE_STATE21;
            limit = 6;
        } else {
            /* Default table */
            data_table = TABLE_DEFAULT;
            limit = 35;
        }
    }

    /* === Phase 2: Guard check === */
    {
        unsigned short counter = (unsigned short)SEQ_COUNTER;

        /* Only process if counter <= limit AND counter != 100 */
        if (counter > limit || counter == 100)
            return;
    }

    /* === Phase 3: Timer countdown === */
    {
        short timer = TIMER_A;
        timer -= (short)TIMER_DECREMENT;
        TIMER_A = timer;

        if (timer > 0)
            return;
    }

    /* === Phase 4: Timer expired — advance sequence === */
    for (;;) {
        /* Find an empty slot (type byte == 0) */
        unsigned char slot_idx = FUN_06017372(0);

        /* If no empty slot found (returns 17 = 0x11 → 18 slots checked),
         * sequence is done */
        if (slot_idx == 17)
            return;

        /* Compute slot entry pointer */
        unsigned char *slot = (unsigned char *)(SLOT_TABLE_BASE
            + (int)(short)(slot_idx * SLOT_ENTRY_SIZE));

        /* Read current counter */
        unsigned short counter = (unsigned short)SEQ_COUNTER;

        /* Copy entry data from sequence table to slot:
         *   slot[0]  = data_table[counter * 3 + 0]  (type byte)
         *   slot[64] = data_table[counter * 3 + 2]  (parameter)
         *   timer_A  = data_table[counter * 3 + 1]  (duration) */
        slot[0] = data_table[counter * 3];
        slot[64] = data_table[counter * 3 + 2];
        TIMER_A = (short)(unsigned char)data_table[counter * 3 + 1];

        /* Increment counter */
        SEQ_COUNTER = (short)(counter + 1);

        /* If the new type is 21, mark sequence as complete */
        if ((unsigned char)slot[0] == 21)
            SEQ_COUNTER = 100;

        /* If timer is still 0, immediately process next entry */
        if (TIMER_A != 0)
            return;
    }
}
