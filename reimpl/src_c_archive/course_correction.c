#include "game.h"

/*
 * course_correction.c -- Course heading correction and sin/cos table lookup
 *
 * Hand-translated from annotated ASM (asm/collision.s) and verified
 * instruction-by-instruction against build/aprog.s binary.
 *
 * Functions:
 *   FUN_0600CA96 (0x0600CA96) -- Heading correction + direction lookup
 *   FUN_0600CC38 (0x0600CC38) -- Segment heading set + direction lookup
 *
 * Both functions interpolate direction vectors (X, Z) from a sin/cos
 * lookup table. The table is accessed through a pointer at 0x0607EB88.
 * Each table entry is 16 bytes:
 *   [0x00]: int   X direction component
 *   [0x04]: int   Z direction component
 *   [0x08]: short width factor
 *   [0x0A]: short heading delta
 *   [0x0C]: short extra parameter
 *   [0x0E]: short (padding)
 *
 * The heading value encodes both an index and a fraction:
 *   index    = (heading & 0xFFFF) >> 8
 *   fraction = (heading & 0xFF) >> 6  (gives 0-3)
 *
 * When fraction > 0 and index < 7, X and Z are linearly interpolated
 * between entry[index] and entry[index+1]:
 *   result = (entry[i] * (4-fraction) + entry[i+1] * fraction) >> 2
 *
 * An additional table offset from car[0x01EC] is multiplied by 8
 * and added to the index before lookup. This selects between different
 * track section sub-tables.
 *
 * NOTE: The ASM annotation for CA96 incorrectly states the first
 * offset as 0x01FC. Binary verification shows the first read is from
 * pool at 0x0600CAC2 = 0x01F8 (target heading), then add #4 gives
 * 0x01FC (current heading). delta = car[0x01F8] - car[0x01FC].
 */


/* Car struct access macros */
#define CAR_INT(car, off)   (*(volatile int *)((char *)(car) + (off)))

/* Heading offsets */
#define OFF_TARGET_HDG   0x01F8
#define OFF_CURRENT_HDG  0x01FC
#define OFF_TABLE_SEG    0x01EC

/* Table pointer address (dereference to get table base) */
#define TABLE_PTR        (*(volatile int *)0x0607EB88)

/* Table entry size in bytes */
#define ENTRY_SIZE       16

/* Dead zone threshold (both functions) */
#define DEAD_ZONE        8

/* Max index for interpolation (index must be < 7 to blend) */
#define MAX_INTERP_IDX   7


/* ================================================================
 * FUN_0600CA96 -- Heading Correction + Direction Lookup (0x0600CA96)
 *
 * CONFIDENCE: DEFINITE (collision.s lines 339-487, binary verified)
 * Pool verified:
 *   0x0600CAC2 = 0x01F8 (target heading offset)
 *   0x0600CAC4 = 0x0607E940 (car pointer global)
 *   0x0600CB84 = 0x01FC (current heading offset)
 *   0x0600CB86 = 0x00FF (fraction mask)
 *   0x0600CB88 = 0x01EC (table segment offset)
 *   0x0600CB8C = 0x0607EB88 (table pointer address)
 *
 * Called from player physics pipeline.
 * Parameters:
 *   r4 = output struct pointer (receives direction vector)
 *
 * Output struct:
 *   [0x00]: int   X direction
 *   [0x08]: int   Z direction
 *   [0x0C]: short width
 *   [0x0E]: short heading_delta * 4
 *   [0x10]: short extra
 *   [0x12]: short 0
 * ================================================================ */
void FUN_0600CA96(int r4)
{
    int car = CAR_PTR_CURRENT;
    int target = CAR_INT(car, OFF_TARGET_HDG);
    int current = CAR_INT(car, OFF_CURRENT_HDG);
    int delta = target - current;
    int heading;
    int frac, idx, adj_idx;
    int tbl, entry;

    /* Heading correction: snap if in dead zone, else step +/-4 */
    if (delta >= DEAD_ZONE || delta <= -DEAD_ZONE) {
        if (delta > 0)
            CAR_INT(car, OFF_CURRENT_HDG) = current + 4;
        else
            CAR_INT(car, OFF_CURRENT_HDG) = current - 4;
    } else {
        CAR_INT(car, OFF_CURRENT_HDG) = target;
    }

    /* Extract fraction and index from adjusted heading */
    heading = CAR_INT(car, OFF_CURRENT_HDG);
    frac = ((unsigned)heading & 0xFFu) >> 6;
    idx = ((unsigned)heading & 0xFFFFu) >> 8;
    adj_idx = idx + CAR_INT(car, OFF_TABLE_SEG) * 8;
    tbl = TABLE_PTR;

    if (frac != 0 && idx < MAX_INTERP_IDX) {
        /* Interpolated: blend between adjacent entries */
        int w = 4 - frac;
        int ea = tbl + adj_idx * ENTRY_SIZE;
        int eb = tbl + (adj_idx + 1) * ENTRY_SIZE;

        *(volatile int *)r4 =
            (*(volatile int *)ea * w + *(volatile int *)eb * frac) >> 2;
        *(volatile int *)(r4 + 8) =
            (*(volatile int *)(ea + 4) * w + *(volatile int *)(eb + 4) * frac) >> 2;

        entry = ea;
    } else {
        /* Direct: single entry read */
        entry = tbl + adj_idx * ENTRY_SIZE;
        *(volatile int *)r4 = *(volatile int *)entry;
        *(volatile int *)(r4 + 8) = *(volatile int *)(entry + 4);
    }

    /* Metadata from table entry */
    *(volatile short *)(r4 + 0x0C) = *(volatile short *)(entry + 8);
    *(volatile short *)(r4 + 0x0E) = (short)(*(volatile short *)(entry + 0x0A) << 2);
    *(volatile short *)(r4 + 0x10) = *(volatile short *)(entry + 0x0C);
    *(volatile short *)(r4 + 0x12) = 0;
}


/* ================================================================
 * FUN_0600CC38 -- Segment Heading Set + Direction Lookup (0x0600CC38)
 *
 * CONFIDENCE: DEFINITE (collision.s lines 504-562, binary verified)
 * Pool verified:
 *   0x0600CCF6 = 0x01F8 (target heading offset)
 *   0x0600CCF8 = 0x01FC (current heading offset)
 *   0x0600CCFA = 0x01EC (table segment offset)
 *   0x0600CCFC = 0x0607E940 (car pointer global)
 *   0x0600CD00 = 0x0607EB88 (table pointer address)
 *
 * Called from player physics pipeline with segment data.
 * Parameters:
 *   r4 = input segment data pointer
 *   r5 = output struct pointer (receives direction vector)
 *
 * Differences from CA96:
 *   - Step size is +/-8 (not +/-4)
 *   - Lookup uses segment heading from input[0x14] (not car heading)
 *   - Stores segment heading to car[0x01F8] as new target
 *   - Metadata copied from INPUT segment, not from table entry
 * ================================================================ */
void FUN_0600CC38(int r4, int r5)
{
    int car = CAR_PTR_CURRENT;
    int target = CAR_INT(car, OFF_TARGET_HDG);
    int current = CAR_INT(car, OFF_CURRENT_HDG);
    int delta = target - current;
    short seg_hdg;
    unsigned int hdg_u;
    int frac, idx, adj_idx;
    int tbl;

    /* Heading correction: snap if in dead zone, else step +/-8 */
    if (delta >= DEAD_ZONE || delta <= -DEAD_ZONE) {
        if (delta > 0)
            CAR_INT(car, OFF_CURRENT_HDG) = current + 8;
        else
            CAR_INT(car, OFF_CURRENT_HDG) = current - 8;
    } else {
        CAR_INT(car, OFF_CURRENT_HDG) = target;
    }

    /* Read segment heading from input, store as new target */
    seg_hdg = *(volatile short *)(r4 + 0x14);
    CAR_INT(car, OFF_TARGET_HDG) = (int)seg_hdg;

    /* Table lookup using segment heading */
    hdg_u = (unsigned short)seg_hdg;
    frac = (hdg_u & 0xFF) >> 6;
    idx = hdg_u >> 8;
    adj_idx = idx + CAR_INT(car, OFF_TABLE_SEG) * 8;
    tbl = TABLE_PTR;

    if (frac != 0 && idx < MAX_INTERP_IDX) {
        /* Interpolated: blend between adjacent entries */
        int w = 4 - frac;
        int ea = tbl + adj_idx * ENTRY_SIZE;
        int eb = tbl + (adj_idx + 1) * ENTRY_SIZE;

        *(volatile int *)r5 =
            (*(volatile int *)ea * w + *(volatile int *)eb * frac) >> 2;
        *(volatile int *)(r5 + 8) =
            (*(volatile int *)(ea + 4) * w + *(volatile int *)(eb + 4) * frac) >> 2;
    } else {
        int entry = tbl + adj_idx * ENTRY_SIZE;
        *(volatile int *)r5 = *(volatile int *)entry;
        *(volatile int *)(r5 + 8) = *(volatile int *)(entry + 4);
    }

    /* Metadata from INPUT segment (not from table entry) */
    *(volatile short *)(r5 + 0x0C) = *(volatile short *)(r4 + 0x0C);
    *(volatile short *)(r5 + 0x0E) = (short)(*(volatile short *)(r4 + 0x0E) << 2);
    *(volatile short *)(r5 + 0x10) = *(volatile short *)(r4 + 0x10);
    *(volatile short *)(r5 + 0x12) = *(volatile short *)(r4 + 0x12);
}
