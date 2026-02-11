#include "game.h"

/*
 * lap_announce.c -- Lap distance announcement / race progress system
 *
 * Hand-translated from binary at 0x0601D7D0 (~120 instructions).
 *
 * Functions:
 *   FUN_0601D7D0 (0x0601D7D0) -- Lap/distance announcement trigger
 *
 * Monitors car progress through the race and triggers announcements
 * at key distance milestones:
 *   - Proximity to target distance (mode-dependent threshold: 8/4/2)
 *   - Halfway point crossing (target / 2)
 *   - Final lap detection (car[0x21C] == progress - 1)
 *
 * Plays sound effects via FUN_0601D5F4 and sets display timer shorts.
 * Called from lap_counting.c.
 */

#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))

/* Display/timer registers */
#define DISPLAY_TIMER_A      (*(volatile short *)0x06086054)
#define DISPLAY_TIMER_B      (*(volatile short *)0x06086058)
#define DISPLAY_TIMER_C      (*(volatile short *)0x06086056)

/* Mode/course flag */
#define MODE_FLAG_INT        (*(volatile int *)0x0607EAD8)

/* Announce trigger flag byte */
#define ANNOUNCE_TRIGGER     (*(volatile unsigned char *)0x06087060)

/* Car pointer (secondary) */
#define CAR_PTR_SECONDARY    (*(volatile int *)0x0607E944)

/* Distance lookup table base (modes x states, 12 bytes per mode) */
#define DIST_TABLE_BASE      0x0604A50C

/* Player state */
#define PLAYER_STATE         (*(volatile int *)0x0605AD00)

/* Race active byte flag */
#define RACE_ACTIVE_BYTE     (*(volatile unsigned char *)0x06085FF4)

/* Progress counter (total laps/checkpoints) */
#define PROGRESS_COUNTER     (*(volatile int *)0x06063F28)

/* Final lap announcement flag */
#define FINAL_LAP_FLAG       (*(volatile int *)0x06086034)

/* Car distance/progress field offset */
#define CAR_DIST_FIELD       0x021C

/* Sound effect codes */
#define SND_FINAL_LAP        ((int)0xAE1121FF)
#define SND_PASSING          ((int)0xAE1146FF)
#define SND_HALFWAY          ((int)0xAE1126FF)
#define SND_ANNOUNCE         ((int)0xAE1127FF)

/* Sound/announcement playback */
extern void FUN_0601D5F4(int channel, int sound_id);


/* ================================================================
 * FUN_0601D7D0 -- Lap/Distance Announcement (0x0601D7D0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601D7D0-0x0601D9AE)
 * Pool verified:
 *   0x0601D888 = 0x06086054 (display timer A)
 *   0x0601D88C = 0x0607EAD8 (mode flag)
 *   0x0601D890 = 0x06087060 (announce trigger byte)
 *   0x0601D894 = 0x06086058 (display timer B)
 *   0x0601D898 = 0x0607E944 (car ptr)
 *   0x0601D89C = 0x0604A50C (distance table)
 *   0x0601D8A0 = 0x0605AD00 (player state)
 *   0x0601D8A4 = 0x06085FF4 (race active byte)
 *   0x0601D8A8 = 0x06063F28 (progress counter)
 *   0x0601D8AC = 0x06086034 (final lap flag)
 *   0x0601D8B0 = 0xAE1121FF (final lap sound)
 *   0x0601D8B4 = 0xAE1146FF (passing sound)
 *   0x0601D97C = 0x06086056 (display timer C)
 *   0x0601D980 = 0xAE1126FF (halfway sound)
 *   0x0601DA40 = 0xAE1127FF (announcement sound)
 * Word pool:
 *   0x0601D884 = 0x021C (car distance field offset)
 *   0x0601D976 = 0x04B0 (1200 — display timer value)
 *
 * Algorithm:
 *   1. Look up target distance from table[mode][player_state]
 *   2. If race active: check final lap → play sound, return
 *   3. If race not active: check proximity by mode threshold
 *   4. Check midpoint / final lap for appropriate sound
 *
 * ~120 instructions. Saves r8-r14, PR.
 * ================================================================ */
void FUN_0601D7D0(void)
{
    /* Compute target distance from 2D lookup table */
    int mode_byte = (signed char)MODE_FLAG_INT;
    int table_offset = (signed char)(mode_byte * 12);
    int player = PLAYER_STATE;
    int target = *(volatile int *)(DIST_TABLE_BASE + table_offset + player * 4);

    int car = CAR_PTR_SECONDARY;

    /* === Path A: Race is active (announcement already triggered) === */
    if (RACE_ACTIVE_BYTE != 0) {
        int progress = PROGRESS_COUNTER;
        int car_dist = CAR_INT(car, CAR_DIST_FIELD);

        if (car_dist == progress - 1 && FINAL_LAP_FLAG == 0) {
            /* Final lap crossing */
            FUN_0601D5F4(0, SND_FINAL_LAP);
            DISPLAY_TIMER_A = 80;
            FINAL_LAP_FLAG = 1;
            return;
        }

        /* Normal passing sound (tail call in binary) */
        FUN_0601D5F4(0, SND_PASSING);
        return;
    }

    /* === Path B: Race not yet active — distance proximity checks === */

    /* Mode 0: threshold 8 */
    if (MODE_FLAG_INT == 0) {
        int delta = target - CAR_INT(car, CAR_DIST_FIELD);
        if (delta <= 8) {
            if (ANNOUNCE_TRIGGER == 0 && PLAYER_STATE > 0) {
                ANNOUNCE_TRIGGER = 1;
                DISPLAY_TIMER_B = 0;
            } else {
                DISPLAY_TIMER_B = DISPLAY_TIMER_B + 1;
            }
        }
    }

    /* Mode 1: threshold 4 */
    if (MODE_FLAG_INT == 1) {
        int delta = target - CAR_INT(car, CAR_DIST_FIELD);
        if (delta <= 4) {
            if (ANNOUNCE_TRIGGER == 0 && PLAYER_STATE > 0) {
                ANNOUNCE_TRIGGER = 1;
            } else {
                DISPLAY_TIMER_B = DISPLAY_TIMER_B + 1;
            }
        }
    }

    /* Mode 2: threshold 2 */
    if (MODE_FLAG_INT == 2) {
        int delta = target - CAR_INT(car, CAR_DIST_FIELD);
        if (delta <= 2) {
            if (ANNOUNCE_TRIGGER == 0 && PLAYER_STATE > 0) {
                ANNOUNCE_TRIGGER = 1;
            } else {
                DISPLAY_TIMER_B = DISPLAY_TIMER_B + 1;
            }
        }
    }

    /* === Midpoint and final lap sound triggers === */
    {
        int car_dist = CAR_INT(car, CAR_DIST_FIELD);
        int midpoint = target / 2;  /* signed div-by-2 (subc+shar pattern) */

        if (car_dist + 1 > midpoint) {
            /* Past midpoint: check for final lap */
            if (car_dist == PROGRESS_COUNTER - 1 && FINAL_LAP_FLAG == 0) {
                /* Final lap announcement */
                FUN_0601D5F4(0, SND_FINAL_LAP);
                DISPLAY_TIMER_C = 80;
                DISPLAY_TIMER_A = 80;
                FINAL_LAP_FLAG = 1;
            } else {
                /* Standard announcement */
                FUN_0601D5F4(0, SND_ANNOUNCE);
                DISPLAY_TIMER_A = 1200;
                DISPLAY_TIMER_C = 20;
            }
        } else {
            /* Not past midpoint: halfway sound */
            FUN_0601D5F4(0, SND_HALFWAY);
            DISPLAY_TIMER_A = 1200;
            DISPLAY_TIMER_C = 20;
        }
    }
}
