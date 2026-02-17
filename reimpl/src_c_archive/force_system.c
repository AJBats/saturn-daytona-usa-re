#include "game.h"

/*
 * force_system.c -- Force table / acceleration pipeline
 *
 * Hand-translated from HIGH/DEFINITE-confidence annotated ASM
 * (asm/force_tables.s, asm/force_system.s) and verified
 * instruction-by-instruction against build/aprog.s raw binary.
 *
 * Functions:
 *   force_apply_frame (0x06008730) -- Per-frame force application (static)
 *   FUN_060086C0  -- Force table initialization
 *   FUN_06008640  -- Force table selection (replaces stub)
 *   FUN_060085B8  -- Brake force application
 *
 * The force system is a KEYFRAME ANIMATION: pre-baked arrays of
 * 12-byte force records, one per frame. Each record contains
 * steering + X/Z/angular forces. A countdown timer controls how
 * many frames the profile runs. When done, forces zero out.
 *
 * Two force profiles exist:
 *   Profile A: 64 records at 0x0604508C (gentle, normal racing)
 *   Profile B: 85 records at 0x06044C90 (aggressive, countdown mode)
 *
 * Gas/brake state determines force SIGN:
 *   Gas (0x40):    +X, -Z, -angular (forward thrust, resist drift)
 *   Brake (0x80):  -X, -Z, +angular (deceleration, looser steering)
 *   Neutral:       raw values from record (coasting)
 *
 * Force record layout (12 bytes):
 *   [0x00]: long  -- speed reference (monotonically increasing)
 *   [0x04]: word  -- steering response factor
 *   [0x06]: word  -- X force component (signed)
 *   [0x08]: word  -- Z force component (signed)
 *   [0x0A]: word  -- angular force component (signed)
 */


/* ================================================================
 * Car struct access macros
 * ================================================================ */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))
#define CAR_BYTE(car, off)   (*(volatile signed char *)((char *)(car) + (off)))
#define CAR_UBYTE(car, off)  (*(volatile unsigned char *)((char *)(car) + (off)))


/* ================================================================
 * Force system constants (verified pool addresses)
 * ================================================================ */

/* Force table hierarchy */
#define TABLE_A_BASE        0x060453B4   /* Normal racing (2 sub-entries) */
#define TABLE_B_BASE        0x060453C4   /* Countdown/special (1 sub-entry) */
#define BIT23_MASK          0x00800000   /* Table B select mask */

/* Force timers */
#define FORCE_TIMER_INIT    70           /* Global timer reset value */
#define FORCE_COUNTDOWN_BIAS (-40)       /* Secondary = primary - 40 */

/* Steering */
#define STEERING_THRESHOLD  0x0100       /* 256: high steering cutoff */

/* Phase/expiry signaling */
#define PHASE_FLAG_EXPIRED  4

/* Global addresses */
#define FORCE_TIMER_GLOBAL  (*(volatile int *)0x0607EBD4)
#define STATE_COUNTER       (*(volatile int *)0x0607EBC4)
#define STATE_VAR           (*(volatile int *)0x0607EBD0)
#define SETUP_COUNTER       (*(volatile char *)0x0607EBEC)
#define TYPE_BYTE           (*(volatile unsigned char *)0x0607EBBC)
#define SIGNAL_BYTE_A       (*(volatile unsigned char *)0x0607866C)
#define SIGNAL_BYTE_B       (*(volatile unsigned char *)0x06078635)
#define INIT_FLAG_WORD      (*(volatile unsigned short *)0x0607ED8C)
#define DIFFICULTY_BYTE     (*(volatile unsigned char *)0x06078654)

/* Brake system constants */
#define BRAKE_FLAG_MASK     0x00200000


/* ================================================================
 * Extern helper declarations
 * ================================================================ */
extern void FUN_06034F78(int val, int param, int base_ptr);
extern void FUN_0601D5F4(int channel, int sound_id);

/* Forward declarations */
void FUN_060086C0(int descriptor);
static void force_apply_frame(void);


/* ================================================================
 * force_apply_frame (0x06008730) -- Per-frame force application
 *
 * CONFIDENCE: DEFINITE (force_tables.s lines 448-715)
 * Every instruction verified. Three gas/brake/neutral code paths
 * match exactly. Countdown decrement, pointer advance by 12,
 * record field reads at offsets 0/4/6/8/A all confirmed.
 * Phase flag write to 0x0605A016 confirmed.
 *
 * Pool verified: 0x060087F8=0x0607E940, word pool at
 * 0x060087E8-0x060087F6 = {0x01BC,0x00BC,0x00D4,0x01B8,
 *   0x01C0,0x01C8,0x01CC,0x01D0}
 * ================================================================ */
static void force_apply_frame(void)
{
    int car = CAR_PTR_CURRENT;
    int record;
    int steering_factor;

    /* Decrement primary countdown (car[0x01BC]) if > 0 */
    if (CAR_INT(car, 0x1BC) > 0) {
        CAR_INT(car, 0x1BC) -= 1;
    }

    /* Decrement secondary countdown (car[0x00BC]) if > 0 */
    if (CAR_INT(car, 0x0BC) > 0) {
        CAR_INT(car, 0x0BC) -= 1;
    }

    /* Check mode field: if mode == 10, cap it at 10 (word write) */
    if (CAR_INT(car, 0x0D4) == 10) {
        CAR_SHORT(car, 0x0D4) = 10;
    }

    /* Advance force record pointer by 12 bytes, read current record */
    {
        int ptr = CAR_INT(car, 0x1B8);
        CAR_INT(car, 0x1B8) = ptr + 12;  /* advance for next frame */
        record = ptr;                      /* current record */
    }

    /* Read speed reference from record[0] */
    CAR_INT(car, 0x1B4) = *(volatile int *)record;

    /* Read steering factor from record[4] (word) */
    steering_factor = *(volatile short *)(record + 4);

    /* Apply forces based on gas/brake/neutral state */
    /* NOTE: flags byte is at car[0x1C0], verified in binary pool */
    {
        unsigned char flags = CAR_UBYTE(car, 0x1C0);

        if (flags & 0x40) {
            /* GAS: +X, -Z, -angular */
            int x = (int)*(volatile short *)(record + 6);
            int z = (int)*(volatile short *)(record + 8);
            int ang = (int)*(volatile short *)(record + 0xA);
            CAR_INT(car, 0x1C8) = x;       /* +X */
            CAR_INT(car, 0x1CC) = -z;      /* -Z */
            CAR_INT(car, 0x1D0) = -ang;    /* -angular */
        } else if (flags & 0x80) {
            /* BRAKE: -X, -Z, +angular */
            int x = (int)*(volatile short *)(record + 6);
            int z = (int)*(volatile short *)(record + 8);
            int ang = (int)*(volatile short *)(record + 0xA);
            CAR_INT(car, 0x1C8) = -x;      /* -X */
            CAR_INT(car, 0x1CC) = -z;      /* -Z */
            CAR_INT(car, 0x1D0) = ang;     /* +angular */
        } else {
            /* NEUTRAL: raw values from record */
            int x = (int)*(volatile short *)(record + 6);
            int z = (int)*(volatile short *)(record + 8);
            int ang = (int)*(volatile short *)(record + 0xA);
            CAR_INT(car, 0x1C8) = x;
            CAR_INT(car, 0x1CC) = z;
            CAR_INT(car, 0x1D0) = ang;
        }
    }

    /* Steering processing: check if this car matches the type byte */
    {
        int car_subtype = CAR_INT(car, 0x04);
        unsigned char type = TYPE_BYTE;

        if (car_subtype == (int)type) {
            /* Increment steering counter */
            CAR_INT(car, 0x1C4) += 1;

            /* If steering factor exceeds threshold, reset counter */
            if ((short)steering_factor > STEERING_THRESHOLD) {
                CAR_INT(car, 0x1C4) = 0;
            }
        }
    }

    /* Countdown expiry check */
    if (CAR_INT(car, 0x1BC) == 0) {
        /* Force expired: signal phase change */
        SIGNAL_BYTE_A = 0;

        if (SIGNAL_BYTE_B != 0 || INIT_FLAG_WORD == 0) {
            PHASE_FLAG = PHASE_FLAG_EXPIRED;
        }
    }

    /* Final force clear: if countdown is 0, zero all force values */
    if (CAR_INT(car, 0x1BC) == 0) {
        CAR_INT(car, 0x1B4) = 0;   /* speed reference */
        CAR_INT(car, 0x1C8) = 0;   /* X force */
        CAR_INT(car, 0x1CC) = 0;   /* Z force */
        CAR_INT(car, 0x1D0) = 0;   /* angular force */
    }
}


/* ================================================================
 * FUN_060086C0 -- Force Table Initialization (0x060086C0)
 *
 * CONFIDENCE: HIGH (force_tables.s lines 364-444)
 * Pool verified at 0x06008714-0x0600872C:
 *   0x01C0, 0x0101, 0x01B8, 0x01BC, 0x00BC, 0x0208
 *   0x0607EBD0, 0x0607E940, 0x06034F78, 0x0607EBEC
 *
 * Called from FUN_06008640 with r4 = force sequence descriptor.
 * Initializes force fields in the car struct, then falls through
 * to force_apply_frame.
 * ================================================================ */
void FUN_060086C0(int descriptor)
{
    int car = CAR_PTR_CURRENT;
    int state = STATE_VAR;
    int force_array_ptr;
    int countdown;

    /* Write low 2 bits of game state to bits 30-31 of car[0x01C0] */
    FUN_06034F78(state & 1, 1, car + 0x1C0);
    FUN_06034F78((state >> 1) & 1, 0x0101, car + 0x1C0);

    /* Read force descriptor: [0]=array pointer, [4]=countdown */
    force_array_ptr = *(volatile int *)descriptor;
    countdown = *(volatile int *)(descriptor + 4);

    /* Store to car struct */
    CAR_INT(car, 0x1B8) = force_array_ptr;   /* running pointer */
    CAR_INT(car, 0x1BC) = countdown;          /* primary countdown */
    CAR_INT(car, 0x0BC) = countdown - 40;     /* secondary countdown */
    CAR_INT(car, 0x208) = countdown - 40;     /* timer copy */

    /* Increment setup counter */
    SETUP_COUNTER++;

    /* Fall through to per-frame force application */
    force_apply_frame();
}


/* ================================================================
 * FUN_06008640 -- Force Table Selection (0x06008640)
 *
 * CONFIDENCE: HIGH (force_tables.s lines 270-361,
 *                   force_system.s lines 386-454)
 * Pool verified: 0x060086AC=0x0607EBC4, 0x060086B0=0x00800000,
 *   0x060086B4=0x060453C4, 0x060086B8=0x0607EBD0,
 *   0x060086BC=0x060453B4
 *
 * Called from player physics pipeline (FUN_0600E71A, step 2).
 * Triggered by bit 0x08 of car[0] (force table trigger).
 * Selects force profile based on game state:
 *   - Bit 23 of STATE_COUNTER: Table B (countdown/special)
 *   - Otherwise: Table A + (state & 1) * 8 (normal racing)
 * Falls through to FUN_060086C0 -> force_apply_frame.
 * ================================================================ */
void FUN_06008640(void)
{
    int car = CAR_PTR_CURRENT;
    unsigned char flags = CAR_UBYTE(car, 0);

    if (flags & 0x08) {
        /* Force trigger bit set: clear it */
        CAR_UBYTE(car, 0) = flags & 0xF7;

        /* Check if forces already active */
        if (CAR_INT(car, 0x1BC) != 0) {
            force_apply_frame();
            return;
        }

        /* Setup new forces */
        CAR_SHORT(car, 0x0D4) = 20;  /* mode = 20 (force init) */

        /* Select table based on bit 23 of state counter */
        if (STATE_COUNTER & BIT23_MASK) {
            /* Table B: countdown/special mode */
            int descriptor = *(volatile int *)TABLE_B_BASE;
            FUN_060086C0(descriptor);
        } else {
            /* Table A: normal racing, indexed by state & 1 */
            int index = (STATE_VAR & 1) * 8;
            int descriptor = *(volatile int *)(TABLE_A_BASE + index);
            FUN_060086C0(descriptor);
        }
    } else {
        /* No trigger: check if forces already running */
        if (CAR_INT(car, 0x1BC) == 0) {
            return;  /* nothing to do */
        }
        /* Forces active: apply this frame */
        force_apply_frame();
    }
}


/* ================================================================
 * FUN_060085B8 -- Brake Force Application (0x060085B8)
 *
 * CONFIDENCE: HIGH (force_system.s lines 258-358)
 * Pool verified: 0x0607E940 (indirect), 0x0607EBD4,
 *   0x06078654, 0x0607EBC4, 0x00200000.
 * State==1 check, 0x80 flag test, speed save confirmed.
 *
 * Called from the per-frame force pipeline. Handles braking state:
 *   1. If force active: reset global timer to 70
 *   2. If braking (state==1) with flag 0x80: save speed reference
 *   3. Call force_apply_frame for actual force application
 *   4. If speed dropped to <= 1: update difficulty byte
 * ================================================================ */
void FUN_060085B8(void)
{
    int car = CAR_PTR_CURRENT;

    /* Check if force is active (car[0x1BC] != 0) */
    if (CAR_INT(car, 0x1BC) == 0) {
        return;
    }

    /* Reset global force timer */
    FORCE_TIMER_GLOBAL = FORCE_TIMER_INIT;

    /* Check braking state: car[0x1EC] == 1 and byte flag 0x80 */
    if (CAR_INT(car, 0x1EC) == 1) {
        /* Check the state byte for high bit */
        unsigned char state_byte = CAR_UBYTE(car, 0x1D4);
        if (state_byte & 0x80) {
            /* Save current speed as brake reference */
            CAR_INT(car, 0x28) = CAR_INT(car, 0x30);
            /* Copy state field */
            {
                int val = CAR_INT(car, 0x1EC);
                CAR_INT(car, 0x1E4) = val;
            }
        }
    }

    /* Apply forces this frame */
    force_apply_frame();

    /* Check if speed dropped to <= 1 */
    if (CAR_INT(car, 0x1BC) <= 1) {
        /* Update difficulty byte based on master flags */
        if (STATE_COUNTER == (int)BRAKE_FLAG_MASK) {
            DIFFICULTY_BYTE = 4;    /* heavy braking */
        } else {
            DIFFICULTY_BYTE = 1;    /* light braking */
        }
    }
}
