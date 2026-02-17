#include "game.h"

/* Per-file car struct access macros */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_UBYTE(car, off)  (*(volatile unsigned char *)((char *)(car) + (off)))

/*
 * gear_shift.c -- Gear-shift steering deflection system
 *
 * Hand-translated from binary at 0x060081F4 (96 instructions).
 *
 * Functions:
 *   FUN_060081F4 (0x060081F4) -- Gear shift deflection + timer management
 *
 * When the player shifts gears, this function:
 *   1. Starts a 48-frame timer (CAR_STEER_TIMER at +0xB8)
 *   2. Sets gear direction (+1 for up, -1 for down)
 *   3. Each frame while timer is active: looks up deflection from a
 *      curve table (different curves for gas pressed vs. released),
 *      applies it as steering deflection, and decelerates by 227/frame
 *   4. Plays gear shift sound (0xAE111BFF) if game state allows
 *   5. On exit, clears flag bits 28 and 29 of car[0] (shift input consumed)
 *
 * Called from physics_entry.c (pre-physics subsystem update).
 */

/* External dependencies */
extern void FUN_06034F78(int val, int param, int ptr);  /* bitfield write */
extern void FUN_0601D5F4(int channel, int sound_id);    /* sound command */

/* Force timer global (also used by force_system.c) */
#define FORCE_TIMER_GLOBAL  (*(volatile int *)0x0607EBD4)

/* Deflection curve tables (48 entries of signed 16-bit values each) */
#define DEFLECT_TABLE_GAS     0x0604540C  /* curve when gas button held */
#define DEFLECT_TABLE_NO_GAS  0x0604546C  /* curve when gas released */

/* Gear shift sound ID */
#define GEAR_SHIFT_SOUND      0xAE111BFF


/* ================================================================
 * FUN_060081F4 -- Gear Shift Deflection System (0x060081F4)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060081F4-0x06008316)
 * Pool verified:
 *   0x060082B4 = 0x0607E944 (CAR_PTR_TARGET)
 *   0x060082B8 = 0x0607EBD4 (FORCE_TIMER_GLOBAL)
 *   0x060082BC = 0x0604540C (deflection table - gas)
 *   0x060082C0 = 0x0604546C (deflection table - no gas)
 *   0x060082C4 = 0x0607EBC4 (GAME_STATE_BIT)
 *   0x060082C8 = 0x00020000 (state mask for sound enable)
 *   0x060082CC = 0xAE111BFF (gear shift sound ID)
 *   0x060082D0 = 0x0601D5F4 (sound command dispatch)
 *   0x0600836C = 0x06034F78 (bitfield write utility)
 * Word pool:
 *   0x060082AA = 0x00B8 (CAR_STEER_TIMER)
 *   0x060082AC = 0x01DC (CAR_GEAR_DIR)
 *   0x060082AE = 0x01D8 (CAR_STEER_DEFLECT)
 *   0x060082B0 = 0x00E3 (227, deceleration per frame)
 *   0x060082B2 = 0x00BC (CAR_PHYS_FIELD_BC)
 *   0x0600835C = 0x0301 (bitfield param: clear bit 28)
 *   0x0600835E = 0x0201 (bitfield param: clear bit 29)
 *
 * Algorithm:
 *   Path 1 (timer active):
 *     - Set FORCE_TIMER_GLOBAL = 70
 *     - Decrement steer timer
 *     - Table index = 48 - original_timer (counts up from 0)
 *     - Look up deflection from gas or no-gas table
 *     - Apply deflection: negate if gear_dir >= 0 (counter-steer)
 *     - Store to CAR_STEER_DEFLECT, decelerate by 227
 *   Path 2 (no timer):
 *     - Skip if speed < 20 or phys_field_BC != 0
 *     - If shift_down (flag 0x10): set timer=48, gear_dir=-1
 *     - Else if shift_up (flag 0x20): set timer=48, gear_dir=+1
 *     - Play sound if GAME_STATE_BIT & 0x20000
 *   Exit:
 *     - Clear bit 28 and bit 29 of car flags (shift input consumed)
 *
 * 96 instructions (0x060081F4-0x06008316). Saves r14 and PR.
 * ================================================================ */
void FUN_060081F4(void)
{
    int car = CAR_PTR_TARGET;
    int steer_timer = CAR_INT(car, CAR_STEER_TIMER);

    if (steer_timer != 0) {
        /* Path 1: Timer active — apply gear shift deflection curve */
        FORCE_TIMER_GLOBAL = 70;

        /* Decrement timer */
        CAR_INT(car, CAR_STEER_TIMER) = steer_timer - 1;

        /* Table index: counts up from 0 as timer counts down from 48 */
        int index = 48 - steer_timer;

        /* Select deflection table based on gas button */
        int table_base;
        if (*(volatile char *)car & CAR_FLAG_GAS) {
            table_base = DEFLECT_TABLE_GAS;
        } else {
            table_base = DEFLECT_TABLE_NO_GAS;
        }

        /* Look up signed 16-bit deflection value */
        short table_value = *(volatile short *)(table_base + index * 2);

        /* Apply deflection: oppose gear direction (counter-steer effect) */
        int gear_dir = CAR_INT(car, CAR_GEAR_DIR);
        int deflection;
        if (gear_dir >= 0) {
            deflection = -(int)table_value;
        } else {
            deflection = (int)table_value;
        }

        CAR_INT(car, CAR_STEER_DEFLECT) = deflection;

        /* Decelerate during gear shift */
        CAR_INT(car, CAR_ACCEL) -= 227;

        goto exit_clear_flags;
    }

    /* Path 2: No timer — check if gear shift should start */
    {
        int speed = CAR_INT(car, CAR_SPEED);
        if (speed < 20)
            goto exit_clear_flags;

        if (CAR_INT(car, CAR_PHYS_FIELD_BC) != 0)
            goto exit_clear_flags;

        int state_bits = GAME_STATE_BIT;
        int state_mask = 0x00020000;

        if (*(volatile char *)car & CAR_FLAG_SHIFT_DOWN) {
            /* Shift down: set timer and gear direction = -1 */
            CAR_INT(car, CAR_STEER_TIMER) = 48;
            CAR_INT(car, CAR_GEAR_DIR) = -1;

            if (state_bits & state_mask) {
                FUN_0601D5F4(0, (int)GEAR_SHIFT_SOUND);
            }
            goto exit_clear_flags;
        }

        if (*(volatile char *)car & CAR_FLAG_SHIFT_UP) {
            /* Shift up: set timer and gear direction = +1 */
            CAR_INT(car, CAR_STEER_TIMER) = 48;
            CAR_INT(car, CAR_GEAR_DIR) = 1;

            if (state_bits & state_mask) {
                FUN_0601D5F4(0, (int)GEAR_SHIFT_SOUND);
            }
        }
    }

exit_clear_flags:
    /* Clear shift input flags: bit 28 and bit 29 of car[0] */
    FUN_06034F78(0, 0x0301, car);
    FUN_06034F78(0, 0x0201, car);
}
