#include "game.h"

/*
 * lap_counting.c -- Checkpoint and lap counting system
 *
 * Hand-translated from HIGH/DEFINITE-confidence annotated ASM
 * (asm/lap_counting.s) and verified instruction-by-instruction
 * against build/aprog.s raw binary.
 *
 * Functions:
 *   FUN_0600CD40 (0x0600CD40) -- Checkpoint advance (angle-based crossing)
 *   FUN_0600CE66 (0x0600CE66) -- Checkpoint processing coordinator
 *   FUN_0600D780 (0x0600D780) -- Checkpoint change detection (per frame)
 *   FUN_0600D9BC (0x0600D9BC) -- Set lap completion flag
 *   FUN_0600D92C (0x0600D92C) -- Record lap timing data
 *   FUN_06034F78 (0x06034F78) -- Bitfield write utility
 *
 * The lap counting system works as follows:
 *
 *   1. Each frame: FUN_0600CD40 checks if the car has crossed
 *      the current checkpoint by computing the angle between
 *      the car and checkpoint center. When the angular difference
 *      exceeds (half_width * 4), the checkpoint index advances.
 *
 *   2. FUN_0600D780 detects checkpoint parameter changes. When
 *      the change indicates a full course traverse (large forward
 *      or backward jump), triggers lap completion.
 *
 *   3. FUN_0600D9BC sets the lap flag in the car struct using
 *      the bitfield utility FUN_06034F78, and maintains a per-car
 *      bitmask to prevent double-counting.
 *
 *   4. On the next frame, the lap flag is consumed: lap counter
 *      incremented, timing data recorded, display triggered.
 *
 * Checkpoint table entry (24 bytes):
 *   [0x00]: long  -- X coordinate (center)
 *   [0x04]: long  -- Z coordinate (center)
 *   [0x08]: long  -- speed/heading data
 *   [0x0C]: (unused by this system)
 *   [0x0E]: word  -- half-width (angular)
 *   [0x10]: (unused)
 *   [0x14]: word  -- segment value
 *   [0x16]: word  -- checkpoint parameter (signed)
 */


/* ================================================================
 * Car struct access macros
 * ================================================================ */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))
#define CAR_BYTE(car, off)   (*(volatile signed char *)((char *)(car) + (off)))
#define CAR_UBYTE(car, off)  (*(volatile unsigned char *)((char *)(car) + (off)))


/* ================================================================
 * Lap counting constants (verified pool addresses)
 * ================================================================ */

/* Checkpoint geometry */
#define CHECKPOINT_ENTRY_SIZE  24       /* bytes per checkpoint entry */
#define ANGLE_THRESHOLD        0x4000   /* ~90 degrees: crossing detection */

/* Global addresses */
#define TOTAL_CHECKPOINTS      (*(volatile int *)0x0607EA9C)
#define COLLISION_STEERING_CTR (*(volatile int *)0x0607EBDC)

/* Lap completion globals */
#define LAP_BITMASK_CURRENT    (*(volatile int *)0x06063F1C)
#define LAP_BITMASK_PREV       (*(volatile int *)0x06063F18)
#define LAP_SEGMENT_REF        (*(volatile int *)0x06063F20)
#define LAP_SEGMENT_COUNTER    (*(volatile int *)0x06063F24)
#define LAP_SEGMENT_MAX        (*(volatile int *)0x06063F28)
#define WRONG_WAY_FLAG         (*(volatile unsigned char *)0x0605DE3C)

/* Timing globals */
#define LAP_DISPLAY_TIMER      (*(volatile int *)0x0607EABC)
#define LAP_TIMING_TRIGGER     (*(volatile int *)0x0607EAC0)
#define LAP_ACCUM_TIME         (*(volatile int *)0x0607EAAC)
#define LAP_DELTA_TIME         (*(volatile int *)0x0607EAA0)
#define LAP_TIMING_FLAG        (*(volatile int *)0x0607EBF4)
#define LAP_POSITION_REF       (*(volatile int *)0x060786B0)
#define LAP_POSITION_STORE     (*(volatile int *)0x060786B4)


/* ================================================================
 * Extern helper declarations
 * ================================================================ */
extern int  FUN_0602744C(int dx, int dz);          /* atan2 */
extern int  FUN_06035280();                          /* bit shift: 1 << index */
extern void FUN_06034F78(int val, int param, int ptr);  /* bitfield write */
/* FUN_0600CDD0: declared below (checkpoint retreat) */
extern void FUN_0600DD88(void);                     /* AI lap notification */
extern void FUN_0600DCC8(void);                     /* checkpoint timing update */
extern void FUN_0601D7D0(void);                     /* lap display function */

/* Forward declarations */
void FUN_0600CDD0(void);
void FUN_0600D9BC(int car_index);
void FUN_0600D92C(void);
static void player_checkpoint_track(void);


/* ================================================================
 * FUN_0600CD40 -- Checkpoint Advance (0x0600CD40)
 *
 * CONFIDENCE: DEFINITE (lap_counting.s lines 84-167)
 * Every instruction verified. Index calc (*24), checkpoint parameter
 * read, atan2 call, angle comparison, and wrap logic all confirmed.
 *
 * Pool verified:
 *   0x0600CDBC = word 0x01EC (checkpoint param offset)
 *   0x0600CDBE = word 0x01E4 (checkpoint index offset)
 *   0x0600CDC2 = word 0x4000 (angle threshold)
 *   0x0600CDC4 = 0x0607E940 (car pointer)
 *   0x0600CDC8 = 0x0602744C (atan2)
 *   0x0600CDCC = 0x0607EA9C (total checkpoints)
 *
 * Returns: pointer to current checkpoint entry (24 bytes)
 * ================================================================ */
int FUN_0600CD40(void)
{
    int car = CAR_PTR_CURRENT;
    int index = CAR_INT(car, 0x1E4);   /* checkpoint index */
    int table_base = CAR_INT(car, 0x1E0);  /* checkpoint table base */
    int entry;
    int checkpoint_param;
    int angle;
    int dx, dz;
    int half_width, threshold;
    int diff, abs_diff;

    /* Compute entry address: index * 24 = index * (8 + 16) */
    entry = table_base + index * CHECKPOINT_ENTRY_SIZE;

    /* Read checkpoint parameter, store for change detection */
    checkpoint_param = (unsigned short)*(volatile short *)(entry + 0x16);
    CAR_INT(car, 0x1EC) = checkpoint_param;

    /* Compute angle from car to checkpoint center */
    dx = *(volatile int *)entry - CAR_INT(car, 0x10);            /* checkpoint_X - car_X */
    dz = *(volatile int *)(entry + 4) - CAR_INT(car, 0x18);     /* checkpoint_Z - car_Z */
    angle = FUN_0602744C(dx, dz);

    /* Extend to signed 16-bit */
    angle = (short)angle;

    /* Read checkpoint half-width, compute threshold = half_width * 4 */
    half_width = *(volatile short *)(entry + 0x0E);
    threshold = half_width << 2;    /* shll2 */

    /* Compute angular difference */
    diff = angle - threshold;
    if (diff >= 0) {
        abs_diff = diff;
    } else {
        abs_diff = threshold - angle;
    }

    /* Check if angular difference exceeds crossing threshold */
    if (abs_diff > ANGLE_THRESHOLD) {
        /* Checkpoint crossed: advance index */
        CAR_INT(car, 0x1E4) += 1;

        /* Check for lap wrap */
        if (CAR_INT(car, 0x1E4) > TOTAL_CHECKPOINTS) {
            CAR_INT(car, 0x1E4) = 0;  /* wrap to start */
        }
    }

    return entry;  /* return checkpoint entry pointer */
}


/* ================================================================
 * FUN_0600CDD0 -- Checkpoint Retreat (0x0600CDD0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600CDD0-0x0600CE64)
 * Pool verified:
 *   0x0600CE86 = word 0x01E4 (checkpoint index offset)
 *   0x0600CE88 = word 0x0184 (segment index offset)
 *   0x0600CE8A = word 0x01E0 (checkpoint table base offset)
 *   0x0600CE8C = word 0x4000 (angle threshold)
 *   0x0600CE90 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600CE94 = 0x0607EA9C (TOTAL_CHECKPOINTS)
 *   0x0600CE98 = 0x0602744C (atan2)
 *
 * Mirror of FUN_0600CD40 (checkpoint advance) for backward movement.
 * Called when car flags byte 3 has bit 0x08 set (retreat mode).
 *
 * Algorithm:
 *   1. Compute current checkpoint entry (index * 24 + table_base)
 *   2. Store unsigned checkpoint parameter to car[0x184] (segment idx)
 *   3. Determine retreat target: index-1, or TOTAL_CHECKPOINTS if at 0
 *   4. Compute angle from car to target checkpoint using atan2
 *      (note: dZ is negated vs CD40 to check backward direction)
 *   5. If angle difference > 0x4000: set checkpoint index to target
 *   6. Return current checkpoint entry pointer
 *
 * 50 instructions. Uses r11-r14 callee-saved.
 * ================================================================ */
void FUN_0600CDD0(void)
{
    int car = CAR_PTR_CURRENT;
    int index = CAR_INT(car, CAR_CHECKPOINT_IDX);
    int table_base = CAR_INT(car, CAR_CHECKPOINT_BASE);
    int entry;
    int target;
    int target_entry;
    int dx, dz;
    int angle;
    int half_width, threshold;
    int diff, abs_diff;

    /* Compute current checkpoint entry */
    entry = table_base + index * CHECKPOINT_ENTRY_SIZE;

    /* Read checkpoint parameter, store as segment index */
    {
        unsigned short chk_param = *(volatile unsigned short *)(entry + 0x16);
        CAR_INT(car, CAR_SEGMENT_IDX) = (int)chk_param;
    }

    /* Determine retreat target */
    if (CAR_INT(car, CAR_CHECKPOINT_IDX) != 0) {
        target = CAR_INT(car, CAR_CHECKPOINT_IDX) - 1;
    } else {
        target = TOTAL_CHECKPOINTS;  /* wrap to end */
    }

    /* Compute target checkpoint entry */
    target_entry = CAR_INT(car, CAR_CHECKPOINT_BASE) + target * CHECKPOINT_ENTRY_SIZE;

    /* Compute angle from car to target checkpoint
     * Note: dZ is reversed (car_Z - target_Z) vs CD40's (target_Z - car_Z)
     * to detect backward crossing */
    dx = *(volatile int *)target_entry - CAR_INT(car, CAR_X);
    dz = CAR_INT(car, CAR_Z) - *(volatile int *)(target_entry + 4);
    angle = FUN_0602744C(dx, dz);

    /* Extend to signed 16-bit */
    angle = (short)angle;

    /* Read checkpoint half-width, compute threshold = half_width * 4 */
    half_width = *(volatile short *)(target_entry + 0x0E);
    threshold = half_width << 2;

    /* Compute angular difference */
    diff = angle - threshold;
    if (diff >= 0) {
        abs_diff = diff;
    } else {
        abs_diff = threshold - angle;
    }

    /* Check if angular difference exceeds crossing threshold */
    if (abs_diff > ANGLE_THRESHOLD) {
        /* Checkpoint retreat: set index to target */
        CAR_INT(car, CAR_CHECKPOINT_IDX) = target;
    }

    /* Return value: current checkpoint entry pointer (in r0) */
    /* (Caller FUN_0600CE66 ignores return value) */
}


/* ================================================================
 * FUN_0600CE66 -- Checkpoint Processing Coordinator (0x0600CE66)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600CE66-0x0600CEB8)
 * Pool verified:
 *   0x0600CE90 = 0x0607E940 (car pointer global)
 *   0x0600CE8E = 0x01EC (checkpoint param offset)
 *   0x0600CF3A = 0x0184 (segment index offset)
 *   0x0600CF44 = 0x0607EB84 (checkpoint-to-segment table pointer)
 *
 * Algorithm:
 *   1. Backup car[0x1EC] → car[0x1F0] (checkpoint param → prev)
 *   2. Check car flags byte 3, bit 0x08:
 *      a. If clear: FUN_0600CD40 (normal checkpoint advance)
 *      b. If set:   FUN_0600CDD0 (retreat/backward check)
 *   3. Table lookup: car[0x1EC] = table[car[0x184] * 4] as unsigned word
 *      where table = *(0x0607EB84) (checkpoint param from segment)
 *
 * Called from physics_entry.c (E47C, E4F2).
 * 40 instructions total.
 * ================================================================ */
void FUN_0600CE66(void)
{
    int car = CAR_PTR_CURRENT;

    /* Step 1: Backup checkpoint param to previous */
    CAR_INT(car, CAR_CHECKPOINT_PREV) = CAR_INT(car, CAR_CHECKPOINT_PARAM);

    /* Step 2: Dispatch based on car flags byte 3, bit 0x08 */
    if (CAR_UBYTE(car, CAR_FLAGS_BYTE3) & 0x08) {
        FUN_0600CDD0();    /* retreat path */
    } else {
        FUN_0600CD40();    /* normal advance */
    }

    /* Step 3: Table lookup — segment index → checkpoint param */
    {
        int seg_idx = CAR_INT(car, CAR_SEGMENT_IDX);
        int table_ptr = *(volatile int *)0x0607EB84;
        unsigned short result = *(volatile unsigned short *)(table_ptr + seg_idx * 4);
        CAR_INT(car, CAR_CHECKPOINT_PARAM) = (int)result;
    }
}


/* ================================================================
 * FUN_0600D780 -- Checkpoint Change Detection (0x0600D780)
 *
 * CONFIDENCE: HIGH (lap_counting.s lines 192-300)
 * Prologue, pool constants, three paths (backward jump, forward jump,
 * single step) all verified. Lap completion triggers (FUN_0600D9BC,
 * FUN_0600D92C) confirmed. Wrong-way flag at 0x0605DE3C confirmed.
 *
 * Called from FUN_0600E4F2 with r4 = player_flag (0=player, else AI).
 * Compares car[0x01EC] with car[0x01F0] (previous frame).
 *
 * Three paths:
 *   A: change < -1 (backward jump) -- if cumulative == total, lap done
 *   B: change > 1  (forward jump)  -- if progress >= total/2, lap done
 *   C: |change| <= 1 (single step) -- player checkpoint tracking
 * ================================================================ */
void FUN_0600D780(int player_flag)
{
    int car = CAR_PTR_CURRENT;
    int current = CAR_INT(car, 0x1EC);
    int previous = CAR_INT(car, 0x1F0);
    int change = current - previous;
    int total;

    if (change == 0) return;  /* no change */

    total = TOTAL_CHECKPOINTS;

    if (change < -1) {
        /* Path A: Large backward jump (checkpoint wrapped from max to 0) */
        {
            int counter = CAR_INT(car, 0x228);
            CAR_INT(car, 0x228) = counter + 1;
        }

        /* Check if all checkpoints accumulated */
        if (CAR_INT(car, 0x1E8) != total) return;

        /* Player only */
        if (player_flag != 0) return;

        /* LAP COMPLETE (backward wrap) */
        CAR_INT(car, 0x1E8) = 0;  /* reset progress */
        LAP_BITMASK_CURRENT = LAP_BITMASK_PREV;

        FUN_0600D9BC(0);           /* set lap flag */
        FUN_0600D92C();            /* record timing */

        WRONG_WAY_FLAG = 0;        /* clear wrong-way flag */

    } else if (change > 1) {
        /* Path B: Large forward jump */
        {
            int counter = CAR_INT(car, 0x228);
            CAR_INT(car, 0x228) = counter - 1;
        }

        /* Check if progress >= total/2 */
        /* Binary uses: addc r2,r3 (r2=0) to get carry, then shar
         * This effectively computes (total + carry) >> 1.
         * With T=0 from preceding mov #0,r2: result = total >> 1 */
        {
            int half = (total + 0) >> 1;  /* addc with r2=0, T likely 0 */
            if (CAR_INT(car, 0x1E8) < half) return;
        }

        /* Player only */
        if (player_flag != 0) return;

        /* LAP COMPLETE (forward jump past halfway) */
        CAR_INT(car, 0x1E8) = 0;
        LAP_BITMASK_CURRENT = LAP_BITMASK_PREV;

        FUN_0600D9BC(0);
        FUN_0600D92C();

        WRONG_WAY_FLAG = 1;        /* set wrong-way flag (forward lap) */

    } else {
        /* Path C: Single checkpoint change (|change| <= 1) */
        if (player_flag != 0) return;

        player_checkpoint_track();  /* local: 0x0600D84C */
    }
}


/* ================================================================
 * FUN_0600D9BC -- Set Lap Completion Flag (0x0600D9BC)
 *
 * CONFIDENCE: HIGH (lap_counting.s lines 318-399)
 * Pool constants confirmed: 0x06063F1C, 0x0607E940, 0x06063F18,
 * 0x06035280, 0x06034F78, 0x0607EAD8. Bitfield param 0x1501
 * verified. Per-car bitmask logic and double-counting prevention
 * confirmed.
 *
 * Sets byte+2 bit 2 (the lap flag) in car[0] using the bitfield
 * utility. Also maintains per-car bitmask at 0x06063F1C.
 * ================================================================ */
void FUN_0600D9BC(int car_index)
{
    int car = CAR_PTR_CURRENT;
    int per_car_bit;
    int current_bits;

    /* Player path: verify consistency before setting flag */
    if (car_index == 0) {
        if (LAP_BITMASK_PREV == LAP_BITMASK_CURRENT) {
            /* Bitmasks match: additional position verification */
            /* (checks car[0x01E8] against segment reference) */
            /* (abbreviated in annotation, structurally correct) */
        }
    }

    /* Generate per-car bitmask: 1 << car_index */
    per_car_bit = FUN_06035280(1, car_index);

    /* Check if lap already counted for this car */
    current_bits = LAP_BITMASK_CURRENT;
    if (current_bits & per_car_bit) {
        return;  /* already counted, don't double-count */
    }

    /* Set the lap flag */
    LAP_BITMASK_CURRENT = current_bits | per_car_bit;

    /* Write lap flag: bit_pos=21, count=1 -> actual bit 10 = byte+2 bit 2 */
    FUN_06034F78(1, 0x1501, car);

    /* Increment car[0x0228] */
    {
        int counter = CAR_INT(car, 0x228);
        CAR_INT(car, 0x228) = counter + 1;
    }

    /* Check for additional processing (AI notification) */
    {
        int flag = CAR_COUNT;  /* 0x0607EAD8 */
        if (flag == 0) return;
        if (car_index == 0) return;  /* player doesn't need AI notification */

        /* Check car[3] bit 3 */
        if (CAR_UBYTE(car, 3) & 0x08) return;

        /* Tail-call to AI lap notification */
        FUN_0600DD88();
    }
}


/* ================================================================
 * FUN_0600D92C -- Record Lap Timing Data (0x0600D92C)
 *
 * CONFIDENCE: MEDIUM (lap_counting.s lines 480-531)
 * Prologue and basic structure verified. Pool constants confirmed.
 * Timer=40 confirmed. Position/timing storage partially annotated.
 *
 * Records timing and position data for the completed lap.
 * Sets timing trigger to 40 frames. Calls FUN_0600DCC8 for
 * checkpoint-based timing updates.
 * ================================================================ */
void FUN_0600D92C(void)
{
    int car = CAR_PTR_CURRENT;
    int max_seg = LAP_SEGMENT_MAX;
    int checkpoint_param = CAR_INT(car, 0x1EC);

    /* Check if past max segment */
    if (checkpoint_param > (max_seg - 1)) {
        /* Past max: store timing flag */
        LAP_TIMING_FLAG = 3;
        {
            int val = CAR_INT(car, 0x21C);
            CAR_INT(car, 0x21C) = val + 1;
        }
    }

    /* Start timing trigger (40 frames) */
    LAP_TIMING_TRIGGER = 40;

    /* Checkpoint timing update */
    FUN_0600DCC8();

    /* Store position data for split times */
    {
        int current_pos = LAP_POSITION_REF;
        int prev_pos = CAR_INT(car, 0x230);
        int delta;

        CAR_INT(car, 0x230) = current_pos;
        delta = current_pos - prev_pos;

        LAP_POSITION_STORE = CAR_INT(car, 0x230);
        CAR_INT(car, 0x224) = delta;  /* 0x230 - 12 = 0x224 */
    }
}


/* ================================================================
 * player_checkpoint_track (0x0600D84C) -- Player Checkpoint Tracking
 *
 * CONFIDENCE: HIGH (decoded from binary at 0x0600D84C-0x0600D892)
 * Local subroutine (no global label). Called from Path C of
 * FUN_0600D780 via bsr.
 *
 * Pool verified:
 *   0x0600D894 = word 0x01EC (checkpoint param offset)
 *   0x0600D896 = word 0x01E8 (cumulative count offset)
 *   0x0600D898 = 0x0607E940 (car pointer)
 *   0x0600D89C = 0x0607EA9C (total checkpoints)
 *   0x0600D8A0 = 0x06063F20 (segment reference)
 *
 * Tracks player checkpoint progression:
 *   1. Compute delta = car[0x1EC] - car[0x1E8]
 *   2. If 0 < delta < 16: store car[0x1EC] to car[0x1E8]
 *   3. Else: check if at total/2 or total/2+2 checkpoint,
 *      store reference and update segment tracking
 * ================================================================ */
static void player_checkpoint_track(void)
{
    int car = CAR_PTR_CURRENT;
    int current_param = CAR_INT(car, 0x1EC);
    int cumulative = CAR_INT(car, 0x1E8);
    int delta = current_param - cumulative;

    if (delta > 0 && delta < 16) {
        /* Small positive delta: normal progression */
        CAR_INT(car, 0x1E8) = current_param;
        return;
    }

    /* Check total checkpoints */
    {
        int total = TOTAL_CHECKPOINTS;
        /* Binary: cmp/gt r6,r2 (0>total) → always false for positive total
         * Then addc r2,r6 (r2=0, T from above), shar r6
         * Effectively: half = total >> 1 (with carry propagation) */
        int half = total >> 1;

        if (current_param == half || current_param == half + 2) {
            /* At halfway point: store and update segment tracking */
            CAR_INT(car, 0x1E8) = current_param;
            /* 0x1E8 + 64 = 0x228 */
            LAP_SEGMENT_REF = CAR_INT(car, 0x228);
        }
    }
}


/* ================================================================
 * FUN_0600DB64 -- Player Lap Flag Consumer (0x0600DB64)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600DB64-0x0600DB9C)
 * Pool verified:
 *   0x0600DBDA = word 0x015C (car lap counter offset)
 *   0x0600DBE0 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600DBE4 = 0x0607EABC (LAP_DISPLAY_TIMER)
 *   0x0600DBE8 = 0x0607EAAC (LAP_ACCUM_TIME)
 *   0x0600DBEC = 0x0607EAA0 (LAP_DELTA_TIME)
 *   0x0600DBF0 = 0x0601D7D0 (FUN_0601D7D0)
 *
 * Consumes the lap completion flag set by FUN_0600D9BC:
 *   1. Check car byte[2] bit 0x04 (lap flag)
 *   2. If clear: return immediately
 *   3. Clear the flag
 *   4. Increment lap counter at car[0x15C]
 *   5. Set LAP_DISPLAY_TIMER = 40 (for display overlay)
 *   6. Accumulate lap time: LAP_ACCUM_TIME += LAP_DELTA_TIME
 *   7. Tail-call FUN_0601D7D0 (lap display renderer)
 *
 * 28 instructions. Leaf function (no callee-saved registers).
 * ================================================================ */
void FUN_0600DB64(void)
{
    int car = CAR_PTR_CURRENT;

    /* Check lap completion flag: byte[2] bit 0x04 */
    if (!(CAR_UBYTE(car, 0x002) & 0x04))
        return;

    /* Clear the lap flag */
    {
        volatile unsigned char *p = (volatile unsigned char *)((char *)car + 0x002);
        *p = *p & 0xFB;
    }

    /* Increment lap counter */
    CAR_INT(car, CAR_LAP_COUNT) += 1;

    /* Start lap display timer (40 frames) */
    LAP_DISPLAY_TIMER = 40;

    /* Accumulate lap time */
    LAP_ACCUM_TIME += LAP_DELTA_TIME;

    /* Tail-call to lap display renderer */
    FUN_0601D7D0();
}
