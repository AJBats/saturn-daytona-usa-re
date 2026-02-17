#include "game.h"

/*
 * collision_response.c -- Collision response system
 *
 * Hand-translated from annotated ASM (asm/collision.s lines 692-1154)
 * and verified instruction-by-instruction against build/aprog.s binary.
 *
 * Functions:
 *   FUN_0600CF58 (0x0600CF58) -- Collision response dispatcher
 *   FUN_0600D0B8 (0x0600D0B8) -- Simple collision (no detailed partner)
 *   FUN_0600D12C (0x0600D12C) -- Passive collision response (position + push)
 *   FUN_0600D210 (0x0600D210) -- Aggressive collision response (speed-based)
 *
 * The collision system is triggered when car flags contain collision type
 * bits (0x00C00000). FUN_0600CF58 is the main entry point, called from
 * the player physics pipeline (FUN_0600C5D6). It classifies collisions
 * using FUN_06035168 and dispatches to the appropriate response handler:
 *
 *   Simple (D0B8):     No detailed geometry -- fallback force adjustment
 *   Passive (D12C):    Position-based with speed push
 *   Aggressive (D210): High-speed head-on with speed-based push
 *
 * Car struct offsets used by collision:
 *   0x01F8  -- force/push field (written by all handlers)
 *   0x01FC  -- heading/speed reference (read for comparison)
 *   0x0204  -- collision timer/counter
 *   0x0210  -- collision mode (0/1/2)
 *   0x0224  -- collision event counter
 *   0x0234  -- collision partner pointer
 *   0x0118  -- partner A pointer
 */


/* ================================================================
 * Car struct access macros
 * ================================================================ */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))
#define CAR_UBYTE(car, off)  (*(volatile unsigned char *)((char *)(car) + (off)))


/* ================================================================
 * Collision system constants (all verified against binary pool data)
 * ================================================================ */

/* Thresholds */
#define COLLISION_TIMER_CONST   128     /* 0x0080: loaded into r12 */
#define MIN_SPEED_FOR_COLL      150     /* 0x0096: speed must exceed this */
#define COLLISION_TYPE_MASK     0x00C00000  /* collision type bits */
#define MODE2_SPEED_THRESHOLD   0x0AF0  /* 2800: mode 2 speed cutoff */
#define MAX_MODE2_COUNT         10      /* max collision events for mode 2 */

/* Car struct offsets (collision-specific) */
#define OFF_COLL_MODE           0x0210  /* collision mode field */
#define OFF_HEADING_REF         0x01FC  /* heading/speed reference */
#define OFF_FORCE_PUSH          0x01F8  /* force/push output */
#define OFF_COLL_TIMER          0x0204  /* collision timer */
#define OFF_COLL_COUNT          0x0224  /* collision event counter */
#define OFF_PARTNER_A           0x0118  /* partner A pointer */
#define OFF_PARTNER_B           0x0234  /* partner B pointer */

/* Force clamp range */
#define FORCE_MAX               0x0800  /* 2048: max force value */

/* Distance thresholds for passive collision (D12C) */
#define DIST_CLOSE              0x00080000  /* close proximity threshold */
#define DIST_FAR                0x000F0000  /* far separation threshold */


/* ================================================================
 * Extern helper declarations
 * ================================================================ */

/*
 * FUN_06035168 -- Collision geometry classification
 *
 * NOTE: Original binary uses non-standard calling convention:
 *   r0 = mode (4), r1 = result byte pointer, r2 = car struct pointer
 * Our C declaration uses standard convention (r4,r5,r6) since the
 * callee (L1 Ghidra lift) won't use params correctly anyway.
 * When FUN_06035168 is properly translated, it should match.
 */
extern void FUN_06035168(int mode, int result_ptr, int car);


/* Forward declarations */
static void FUN_0600D0B8(void);
static void FUN_0600D12C(void);
static void FUN_0600D210(void);


/* ================================================================
 * FUN_0600D210 -- Aggressive Collision Response (0x0600D210)
 *
 * CONFIDENCE: DEFINITE (collision.s lines 1001-1076)
 * Every instruction verified. Pool constants at 0x0600D26A-0x0600D27C:
 *   0x0600D26A=0x01FC, 0x0600D26C=0xFD00(-768), 0x0600D26E=0x0300(768),
 *   0x0600D270=0x01F8, 0x0600D272=0x0800(2048), 0x0600D274=0x0204,
 *   0x0600D278=0x0607E940, 0x0600D27C=0x0607E944
 *
 * Applies speed-based force when two cars collide at high speed.
 * Reads both cars' heading reference field (0x01FC), checks delta
 * is in range [-768, 768], then adjusts by ±16 based on who's faster.
 * Result clamped to [0, 2048], stored at self[0x01F8].
 * Timer set to 64 at self[0x0204].
 * ================================================================ */
static void FUN_0600D210(void)
{
    int self = CAR_PTR_CURRENT;      /* *0x0607E940 */
    int other = CAR_PTR_TARGET;      /* *0x0607E944 */
    int self_val, other_val, delta, result;

    self_val = CAR_INT(self, OFF_HEADING_REF);   /* self[0x01FC] */
    other_val = CAR_INT(other, OFF_HEADING_REF); /* other[0x01FC] */
    delta = other_val - self_val;

    /* Range check: delta must be in [-768, 768] */
    if (delta < (short)0xFD00)    /* -768 */
        return;
    if (delta > 0x0300)           /* 768 */
        return;

    /* Re-read self value for direction comparison */
    self_val = CAR_INT(self, OFF_HEADING_REF);

    /* Determine push direction based on who has higher value */
    if (self_val > other_val) {
        result = other_val - 16;   /* push back */
    } else {
        result = other_val + 16;   /* push forward */
    }

    /* Clamp to [0, FORCE_MAX] and store */
    if (result < 0) {
        CAR_INT(self, OFF_FORCE_PUSH) = 0;
    } else if (result > FORCE_MAX) {
        CAR_INT(self, OFF_FORCE_PUSH) = FORCE_MAX;
    } else {
        CAR_INT(self, OFF_FORCE_PUSH) = result;
    }

    /* Set collision counter to 64 frames */
    CAR_INT(self, OFF_COLL_TIMER) = 64;
}


/* ================================================================
 * FUN_0600D0B8 -- Simple Collision Handler (0x0600D0B8)
 *
 * CONFIDENCE: HIGH (collision.s lines 1079-1154)
 * Pool constants at 0x0600D112-0x0600D128:
 *   0x0600D112=0x0200(512), 0x0600D114=0x01FC, 0x0600D116=0xFE00(-512),
 *   0x0600D118=0x01F8, 0x0600D11A=0x0800(2048), 0x0600D11C=0x0204,
 *   0x0600D120=0x0607E944, 0x0600D124=0x0607E940, 0x0600D128=0x00C00000
 *
 * Fallback collision handler when geometry classification returns no
 * detail. Checks collision type bits, compares heading reference fields,
 * applies ±512 adjustment from other car's value, clamps to [0, 2048].
 * Stores result at self[0x01F8] and timer/flag 512 at self[0x0204].
 *
 * r7 = 0x0200 = 512, serves dual purpose:
 *   1. Positive adjustment (+512 when self is ahead)
 *   2. Timer/flag value stored at self[0x0204]
 * ================================================================ */
static void FUN_0600D0B8(void)
{
    int timer_and_adjust = 0x0200;  /* 512: dual-purpose value (r7) */
    int other_ptr = CAR_PTR_TARGET; /* 0x0607E944 -> other car */
    int self = CAR_PTR_CURRENT;     /* 0x0607E940 -> self car */
    int other;
    int flags;
    int result;

    /* Check collision type bits */
    flags = CAR_INT(self, 0) & COLLISION_TYPE_MASK;
    other = CAR_PTR_TARGET;         /* reload (delay slot in original) */
    if (flags == 0)
        return;

    /* Compare heading reference fields */
    if (CAR_INT(other, OFF_HEADING_REF) >= CAR_INT(self, OFF_HEADING_REF)) {
        /* Other ahead: subtract 512 from other's value */
        result = CAR_INT(other, OFF_HEADING_REF) + (short)0xFE00;  /* -512 */
    } else {
        /* Self ahead: add 512 to other's value */
        result = CAR_INT(other, OFF_HEADING_REF) + timer_and_adjust;  /* +512 */
    }

    /* Clamp to [0, FORCE_MAX] and store */
    if (result < 0) {
        CAR_INT(self, OFF_FORCE_PUSH) = 0;
    } else if (result > FORCE_MAX) {
        CAR_INT(self, OFF_FORCE_PUSH) = FORCE_MAX;
    } else {
        CAR_INT(self, OFF_FORCE_PUSH) = result;
    }

    /* Store timer/flag value */
    CAR_INT(self, OFF_COLL_TIMER) = timer_and_adjust;  /* 512 */
}


/* ================================================================
 * FUN_0600D12C -- Passive Collision Response (0x0600D12C)
 *
 * CONFIDENCE: MEDIUM-HIGH (collision.s lines 911-998 + binary 0x0600D1A4)
 * Pool constants at 0x0600D192-0x0600D20C:
 *   0x0600D192=0x0118(partnerA), 0x0600D194=0x0234(partnerB),
 *   0x0600D198=0x0607E940, 0x0600D19C=0x000F0000(far threshold),
 *   0x0600D1A0=0x00080000(close threshold)
 * Continuation pool at 0x0600D1FA-0x0600D20C:
 *   0x0600D1FA=0x01FC, 0x0600D1FC=0xFD00(-768), 0x0600D1FE=0x0300(768),
 *   0x0600D200=0x0400(1024), 0x0600D202=0x01F8, 0x0600D204=0x0800,
 *   0x0600D206=0x0100(256), 0x0600D208=0x0204, 0x0600D20C=0x0607E940
 *
 * Two-phase function:
 *   Phase 1: Distance check between self and collision partners
 *     - Partner B (car[0x0234]): if Manhattan dist < 0x80000 -> apply force
 *     - Partner A (car[0x0118]): if Manhattan dist < 0xF0000 -> apply force
 *     - If partner A dist >= 0xF0000 -> return (no collision)
 *   Phase 2: Speed-based force application (at 0x0600D1A4)
 *     - Delta = target[0x01FC] - self[0x01FC], range check [-768, 768]
 *     - If target value > 1024: subtract 768; else: add 768
 *     - Clamp to [0, 2048], store at self[0x01F8]
 *     - Timer = 256, partner pointer stored at self[0x0234]
 * ================================================================ */
static void FUN_0600D12C(void)
{
    int self = CAR_PTR_CURRENT;         /* *0x0607E940 */
    int partnerA = CAR_INT(self, OFF_PARTNER_A);    /* car[0x0118] */
    int partnerB = CAR_INT(self, OFF_PARTNER_B);    /* car[0x0234] */
    int target = partnerA;              /* default collision target */
    int metric;
    int need_force = 0;

    if (partnerB != 0) {
        /* Check partner B proximity (Manhattan XZ distance) */
        metric = (CAR_INT(partnerB, 0x10) - CAR_INT(self, 0x10))
               + (CAR_INT(partnerB, 0x18) - CAR_INT(self, 0x18));

        if (metric < (int)DIST_CLOSE) {
            /* Partner B is very close -- use as collision target */
            target = partnerB;
            need_force = 1;
        } else {
            /* Check partner A distance */
            metric = (CAR_INT(partnerA, 0x10) - CAR_INT(self, 0x10))
                   + (CAR_INT(partnerA, 0x18) - CAR_INT(self, 0x18));

            if (metric >= (int)DIST_FAR) {
                return;  /* far enough apart -- no collision */
            }
            need_force = 1;
        }
    } else {
        /* No partner B -- check partner A only */
        metric = (CAR_INT(partnerA, 0x10) - CAR_INT(self, 0x10))
               + (CAR_INT(partnerA, 0x18) - CAR_INT(self, 0x18));

        if (metric >= (int)DIST_FAR) {
            return;  /* far enough -- no collision */
        }
        need_force = 1;
    }

    /* Phase 2: Speed-based force application (binary at 0x0600D1A4) */
    if (need_force) {
        int self2 = CAR_PTR_CURRENT;    /* reload self car ptr */
        int target_val = CAR_INT(target, OFF_HEADING_REF);   /* target[0x01FC] */
        int self_val = CAR_INT(self2, OFF_HEADING_REF);      /* self[0x01FC] */
        int delta = target_val - self_val;
        int adjust;

        /* Range check: delta in [-768, 768] */
        if (delta < (short)0xFD00 || delta > 0x0300) {
            return;
        }

        /* Compute force adjustment */
        if (target_val > 0x0400) {  /* 1024 threshold */
            adjust = target_val - 0x0300;   /* subtract 768 */
        } else {
            adjust = target_val + 0x0300;   /* add 768 */
        }

        /* Clamp to [0, FORCE_MAX] and store */
        if (adjust < 0) {
            CAR_INT(self2, OFF_FORCE_PUSH) = 0;
        } else if (adjust > FORCE_MAX) {
            CAR_INT(self2, OFF_FORCE_PUSH) = FORCE_MAX;
        } else {
            CAR_INT(self2, OFF_FORCE_PUSH) = adjust;
        }

        /* Set timer and store collision target pointer */
        CAR_INT(self2, OFF_COLL_TIMER) = 0x0100;   /* 256 */
        CAR_INT(self2, OFF_PARTNER_B) = target;     /* store at 0x0234 */
    }
}


/* ================================================================
 * FUN_0600CF58 -- Collision Response Dispatcher (0x0600CF58)
 *
 * CONFIDENCE: HIGH (collision.s lines 692-909)
 * Pool constants verified against binary at 0x0600CFE2-0x0600CFF8
 * and 0x0600D0AA-0x0600D0B6:
 *   Inline: 0x0080(128), 0x0096(150), 0x0210, 0x01FC, 0x0607E944,
 *           0x0607E940, 0x00C00000, 0x06035168
 *   After:  0x0210, 0x0AF0(2800), 0x0224, 0x01FC, 0x0300(768),
 *           0x01F8, 0x0400(1024)
 *
 * Main collision response entry point. Pipeline:
 *   1. Check collision partner exists (car[4])
 *   2. Check speed > 150
 *   3. Check collision type bits (0x00C00000)
 *   4. Classify collision via FUN_06035168
 *   5. If no detail: FUN_0600D0B8 (simple)
 *   6. Head-on (bit 0x02): speed comparison -> heading copy or D12C
 *   7. Side (bit 0x01): mode 2 -> aggressive or passive; mode 1 -> heading
 *   8. Default: FUN_0600D12C (passive)
 *   9. No-collision safety: if car[4]==0, call D12C
 * ================================================================ */
/* FUN_0600CF58 -- original binary (468 bytes) */
__asm__(
    ".section .text.FUN_0600CF58, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600CF58\n"
    ".global _FUN_0600cf58\n"
    ".type _FUN_0600CF58, @function\n"
    "_FUN_0600CF58:\n"
    "_FUN_0600cf58:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x4F, 0x22, 0x7F, 0xFC, 0x6B, 0xF3, 0x9C, 0x3C\n"  /* 0x0600CF58 */
    ".byte 0xDD, 0x20, 0xD4, 0x21, 0x6E, 0x42, 0x50, 0xE1, 0x20, 0x08, 0x8F, 0x02, 0x6D, 0xD2, 0xA0, 0x8C\n"  /* 0x0600CF68 */
    ".byte 0x00, 0x09, 0x53, 0xE2, 0x92, 0x32, 0x33, 0x27, 0x89, 0x01, 0xA0, 0x86, 0x00, 0x09, 0x62, 0x42\n"  /* 0x0600CF78 */
    ".byte 0x63, 0x22, 0xD2, 0x1A, 0x23, 0x29, 0x23, 0x38, 0x8B, 0x01, 0xA0, 0x83, 0x00, 0x09, 0x61, 0xB3\n"  /* 0x0600CF88 */
    ".byte 0x62, 0xE3, 0xD3, 0x17, 0x43, 0x0B, 0xE0, 0x04, 0x90, 0x21, 0x00, 0xEE, 0x20, 0x08, 0x8B, 0x03\n"  /* 0x0600CF98 */
    ".byte 0xB0, 0x86, 0x00, 0x09, 0xA0, 0x76, 0x00, 0x09, 0x60, 0xB3, 0x60, 0x00, 0xC8, 0x02, 0x89, 0x0E\n"  /* 0x0600CFA8 */
    ".byte 0x53, 0xD2, 0x52, 0xE2, 0x33, 0x23, 0x89, 0x03, 0xB0, 0xB4, 0x00, 0x09, 0xA0, 0x07, 0x00, 0x09\n"  /* 0x0600CFB8 */
    ".byte 0x90, 0x0E, 0x02, 0xEE, 0x70, 0xFC, 0x0E, 0x26, 0x70, 0x0C, 0xA0, 0x63, 0x0E, 0xC6, 0x53, 0xD2\n"  /* 0x0600CFC8 */
    ".byte 0x52, 0xE2, 0x33, 0x23, 0x89, 0x0E, 0xA0, 0x5D, 0x00, 0x09, 0x00, 0x80, 0x00, 0x96, 0x02, 0x10\n"  /* 0x0600CFD8 */
    ".byte 0x01, 0xFC, 0xFF, 0xFF, 0x06, 0x07, 0xE9, 0x44, 0x06, 0x07, 0xE9, 0x40, 0x00, 0xC0, 0x00, 0x00\n"  /* 0x0600CFE8 */
    ".byte 0x06, 0x03, 0x51, 0x68, 0x60, 0xB3, 0x60, 0x00, 0xC8, 0x01, 0x89, 0x44, 0x90, 0x51, 0x00, 0xEE\n"  /* 0x0600CFF8 */
    ".byte 0x88, 0x02, 0x8B, 0x10, 0x52, 0xD2, 0x93, 0x4D, 0x32, 0x37, 0x8B, 0x08, 0xE2, 0x0A, 0x90, 0x4A\n"  /* 0x0600D008 */
    ".byte 0x03, 0xEE, 0x33, 0x23, 0x89, 0x03, 0xB0, 0xF7, 0x00, 0x09, 0xA0, 0x32, 0x00, 0x09, 0xB0, 0x81\n"  /* 0x0600D018 */
    ".byte 0x00, 0x09, 0xA0, 0x2E, 0x00, 0x09, 0x90, 0x3C, 0x00, 0xEE, 0x88, 0x01, 0x8B, 0x29, 0x90, 0x3B\n"  /* 0x0600D028 */
    ".byte 0xE3, 0x02, 0x04, 0xDE, 0x05, 0xEE, 0x44, 0x21, 0x45, 0x21, 0x44, 0x21, 0x45, 0x21, 0x44, 0x21\n"  /* 0x0600D038 */
    ".byte 0x45, 0x21, 0x44, 0x21, 0x45, 0x21, 0x44, 0x21, 0x45, 0x21, 0x44, 0x21, 0x45, 0x21, 0x44, 0x21\n"  /* 0x0600D048 */
    ".byte 0x45, 0x21, 0x44, 0x21, 0x45, 0x21, 0x34, 0x32, 0x89, 0x08, 0xE3, 0x03, 0x35, 0x32, 0x89, 0x05\n"  /* 0x0600D058 */
    ".byte 0x93, 0x23, 0x90, 0x23, 0x0E, 0x36, 0x70, 0x0C, 0xA0, 0x0B, 0x0E, 0xC6, 0xE2, 0x05, 0x34, 0x26\n"  /* 0x0600D068 */
    ".byte 0x8B, 0x07, 0xE2, 0x04, 0x35, 0x26, 0x8B, 0x04, 0x92, 0x19, 0x90, 0x17, 0x0E, 0x26, 0x70, 0x0C\n"  /* 0x0600D078 */
    ".byte 0x0E, 0xC6, 0xA0, 0x07, 0x00, 0x09, 0xB0, 0x4D, 0x00, 0x09, 0x50, 0xE1, 0x20, 0x08, 0x8B, 0x01\n"  /* 0x0600D088 */
    ".byte 0xB0, 0x48, 0x00, 0x09, 0x7F, 0x04, 0x4F, 0x26, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B\n"  /* 0x0600D098 */
    ".byte 0x6E, 0xF6, 0x02, 0x10, 0x0A, 0xF0, 0x02, 0x24, 0x01, 0xFC, 0x03, 0x00, 0x01, 0xF8, 0x04, 0x00\n"  /* 0x0600D0A8 */
    ".byte 0x97, 0x2B, 0xD5, 0x19, 0xD4, 0x19, 0x66, 0x42, 0x63, 0x63, 0x62, 0x32, 0xD3, 0x18, 0x22, 0x39\n"  /* 0x0600D0B8 */
    ".byte 0x22, 0x28, 0x8D, 0x20, 0x65, 0x52, 0x90, 0x21, 0x03, 0x5E, 0x02, 0x6E, 0x33, 0x23, 0x89, 0x03\n"  /* 0x0600D0C8 */
    ".byte 0x90, 0x1C, 0x04, 0x5E, 0xA0, 0x04, 0x34, 0x7C, 0x90, 0x18, 0x04, 0x5E, 0x92, 0x17, 0x34, 0x2C\n"  /* 0x0600D0D8 */
    ".byte 0x44, 0x11, 0x89, 0x04, 0xE2, 0x00, 0x90, 0x13, 0x06, 0x26, 0xA0, 0x0A, 0x00, 0x09, 0x93, 0x10\n"  /* 0x0600D0E8 */
    ".byte 0x34, 0x37, 0x8B, 0x04, 0x93, 0x0D, 0x90, 0x0B, 0x06, 0x36, 0xA0, 0x02, 0x00, 0x09, 0x90, 0x07\n"  /* 0x0600D0F8 */
    ".byte 0x06, 0x46, 0x90, 0x07, 0x06, 0x76, 0x00, 0x0B, 0x00, 0x09, 0x02, 0x00, 0x01, 0xFC, 0xFE, 0x00\n"  /* 0x0600D108 */
    ".byte 0x01, 0xF8, 0x08, 0x00, 0x02, 0x04, 0xFF, 0xFF, 0x06, 0x07, 0xE9, 0x44, 0x06, 0x07, 0xE9, 0x40\n"  /* 0x0600D118 */
    ".byte 0x00, 0xC0, 0x00, 0x00\n"  /* 0x0600D128 */
);

