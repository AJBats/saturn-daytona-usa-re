#include "game.h"

/*
 * vdp_polygon_setup.c -- VDP polygon vertex data setup
 *
 * Hand-translated from binary at 0x06038120 (215 instructions).
 *
 * Functions:
 *   FUN_06038120 (0x06038120) -- Configure polygon vertex buffers
 *
 * Processes a polygon descriptor structure and fills two output buffers
 * with vertex coordinate and normal data for VDP rendering.
 *
 * Only active when the render mode is 4 or 8. The first 5 bytes of
 * the input structure control which data channels are enabled and the
 * iteration stride.
 *
 * Input structure layout:
 *   [0..4]    Channel enable flags (byte each: [0]=Z, [1]=Y, [2]=X, [3]=N, [4]=stride_mode)
 *   [8..11]   Coordinate data descriptor A (32-bit)
 *   [12..15]  Coordinate data descriptor B (32-bit)
 *   [16+]     Vertex data entries (12 bytes each: X, Y, Z coordinates)
 *   [0x1810+] Normal data entries (4 bytes each, 64 entries max)
 *
 * Output buffers:
 *   0x060A2470 -- Vertex coordinate buffer (selected channels)
 *   0x060A3C70 -- Normal data buffer
 *
 * Called from render_setup.c.
 */

/* Output buffers */
#define VERTEX_BUF_BASE      ((volatile int *)0x060A2470)
#define NORMAL_BUF_BASE      ((volatile int *)0x060A3C70)

/* Config structs (data + buffer pointer pairs) */
#define CONFIG_A_DATA        (*(volatile int *)0x060A3D70)
#define CONFIG_A_BUF         (*(volatile int *)0x060A3D74)
#define CONFIG_B_DATA        (*(volatile int *)0x060A3D78)
#define CONFIG_B_BUF         (*(volatile int *)0x060A3D7C)

/* Output structure base (bitfield + offsets) */
#define OUT_STRUCT_BASE      0x060A3DF8
#define OUT_BITFIELD         (*(volatile short *)(OUT_STRUCT_BASE + 0x2A))
#define OUT_HALF_A           (*(volatile int *)(OUT_STRUCT_BASE + 0x2C))

/* Mode-dependent output slots */
#define OUT_SLOT_MODE4       (*(volatile int *)(OUT_STRUCT_BASE + 0x30))
#define OUT_SLOT_MODE8       (*(volatile int *)(OUT_STRUCT_BASE + 0x34))

/* Render mode flag */
#define RENDER_MODE          (*(volatile int *)0x060635A8)

/* Output count registers */
#define VERTEX_COUNT         (*(volatile short *)0x060635A0)
#define NORMAL_COUNT         (*(volatile short *)0x060635A2)
#define MODE_OUTPUT          (*(volatile short *)0x060635AC)

/* Constants */
#define HALF_MASK            0x0007FFFF
#define VERTEX_ENTRIES       512
#define NORMAL_ENTRIES       64
#define ENTRY_SIZE           12   /* 3 ints per vertex entry */
#define NORMAL_DATA_OFFSET   0x1810


/* ================================================================
 * FUN_06038120 -- VDP Polygon Vertex Setup (0x06038120)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06038120-0x060382F2)
 * Pool verified:
 *   0x0603815C = 0x060A3DF8 (output struct base)
 *   0x06038160 = 0x060A3C70 (normal buffer)
 *   0x06038164 = 0x060A2470 (vertex buffer)
 *   0x06038168 = 0x060635A8 (render mode)
 *   0x060382A0 = 0x0000FF00 (8-bit shift mask)
 *   0x060382A4 = 0x060A3D70 (config A)
 *   0x060382A8 = 0x060A3D78 (config B)
 *   0x060382AC = 0x0007FFFF (19-bit mask)
 *   0x060382B0 = 0x060635A0 (vertex count)
 *   0x060382F4 = 0x1810 (normal data offset)
 *   0x060382F8 = 0x060635A2 (normal count)
 *   0x060382FC = 0x060635AC (mode output)
 * Word pool:
 *   0x0603815A = 0x0200 (512 entries)
 *
 * 215 instructions. Saves r8-r14. 4-byte stack frame.
 * ================================================================ */
int FUN_06038120(unsigned char *param)
{
    int mode = RENDER_MODE;

    /* Only process for render modes 4 or 8 */
    if (mode != 4 && mode != 8)
        return 1;  /* non-zero = no processing needed */

    /* Build channel enable bitfield from first 5 bytes */
    unsigned short bitfield =
        ((param[3] & 1) << 0) |
        ((param[2] & 1) << 1) |
        ((param[1] & 1) << 2) |
        ((param[0] & 1) << 3) |
        ((param[4] & 3) << 4);

    /* For mode 8: shift bitfield into high byte */
    if (mode == 8)
        bitfield = (bitfield << 8) & 0xFF00;

    /* Store bitfield to output struct */
    OUT_BITFIELD = bitfield;

    /* Set up coordinate data config structs */
    unsigned int desc_a = *(unsigned int *)(param + 8);
    unsigned int desc_b = *(unsigned int *)(param + 12);

    CONFIG_A_DATA = (int)desc_a;
    CONFIG_A_BUF = (int)VERTEX_BUF_BASE;
    CONFIG_B_DATA = (int)desc_b;
    CONFIG_B_BUF = (int)NORMAL_BUF_BASE;

    /* Store half-values with 19-bit mask */
    if (mode == 8) {
        OUT_SLOT_MODE8 = (int)((desc_a >> 1) & HALF_MASK);
    } else {
        OUT_SLOT_MODE4 = (int)((desc_a >> 1) & HALF_MASK);
    }
    OUT_HALF_A = (int)((desc_b >> 1) & HALF_MASK);

    /* Compute stride from param[4] (0→1, 1→2, 2→4, 3→8) */
    unsigned short stride;
    {
        unsigned char s = param[4];
        if (s == 0) stride = 1;
        else if (s == 1) stride = 2;
        else if (s == 2) stride = 4;
        else if (s == 3) stride = 8;
        else stride = 0;
    }

    /* === Loop 1: Fill vertex buffer from coordinate data === */
    {
        unsigned short out_idx = 0;
        unsigned short in_idx = 0;

        while (in_idx < VERTEX_ENTRIES) {
            /* Channel X (param[2]) */
            if (param[2] != 0) {
                short entry_off = (short)(in_idx * 4 + in_idx * 8);  /* in_idx * 12 */
                int val = *(int *)(param + 0x10 + entry_off);
                ((volatile int *)VERTEX_BUF_BASE)[out_idx] = val;
                out_idx++;
            }

            /* Channel Y (param[1]) */
            if (param[1] != 0) {
                short entry_off = (short)(in_idx * 4 + in_idx * 8);
                int val = *(int *)(param + 0x10 + entry_off + 4);
                ((volatile int *)VERTEX_BUF_BASE)[out_idx] = val;
                out_idx++;
            }

            /* Channel Z (param[0]) */
            if (param[0] != 0) {
                short entry_off = (short)(in_idx * 4 + in_idx * 8);
                int val = *(int *)(param + 0x10 + entry_off + 8);
                ((volatile int *)VERTEX_BUF_BASE)[out_idx] = val;
                out_idx++;
            }

            in_idx += stride;
        }

        VERTEX_COUNT = out_idx;
    }

    /* === Loop 2: Fill normal buffer (64 entries) === */
    {
        unsigned short out_idx = 0;
        unsigned short in_idx = 0;

        while (in_idx < NORMAL_ENTRIES) {
            /* Channel N (param[3]) */
            if (param[3] != 0) {
                int val = *(int *)(param + NORMAL_DATA_OFFSET + in_idx * 4);
                ((volatile int *)NORMAL_BUF_BASE)[out_idx] = val;
                out_idx++;
            }

            in_idx++;
        }

        NORMAL_COUNT = out_idx;
    }

    /* Set mode output flag */
    MODE_OUTPUT = 2;

    return 0;
}
