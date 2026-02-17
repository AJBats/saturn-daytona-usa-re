/* vdp_sprite_init.c -- VDP sprite initialization for background layers
 *
 * Functions:
 *   FUN_060032D4 (0x060032D4) -- Initialize 3 VDP sprite layers
 *
 * Sets up three sprite command entries at the same data source address
 * (0x06059ECE) with VDP format 0xF000, using vertical offsets:
 *   Layer 0: offset 0x0000
 *   Layer 1: offset 0x0D00 (3328 lines)
 *   Layer 2: offset 0x0D80 (3456 lines)
 *
 * FUN_060283E0 is the VDP sprite command register function (4 params).
 *
 * Original address: 0x060032D4
 */

/* VDP sprite command setup (r4=type, r5=y_offset, r6=format, r7=data_ptr) */
extern void FUN_060283E0(int type, int y_offset, int format, int data_ptr);

/* Data source address and VDP format flag */
#define SPRITE_DATA_SRC  0x06059ECE
#define SPRITE_FORMAT    0x0000F000


/* ================================================================
 * FUN_060032D4 -- VDP Sprite Triple Setup (0x060032D4)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060032D4-0x06003308)
 * Pool verified:
 *   0x06003378 = 0x06059ECE (sprite data source)
 *   0x0600337C = 0x060283E0 (VDP sprite command function)
 *   0x06003380 = 0x0000F000 (VDP pixel format)
 *   0x06003362 = 0x0D00 (layer 1 Y offset, mov.w pool)
 *   0x06003364 = 0x0D80 (layer 2 Y offset, mov.w pool)
 *
 * 26 instructions. Saves r12-r14, PR.
 * ================================================================ */
/* FUN_060032D4 -- original binary (54 bytes) */
__asm__(
    ".section .text.FUN_060032D4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060032D4\n"
    ".global _FUN_060032d4\n"
    ".type _FUN_060032D4, @function\n"
    "_FUN_060032D4:\n"
    "_FUN_060032d4:\n"
    ".byte 0x2F, 0xE6, 0xE5, 0x00, 0x2F, 0xD6, 0x2F, 0xC6, 0x4F, 0x22, 0xDC, 0x26, 0xDD, 0x26, 0xDE, 0x27\n"  /* 0x060032D4 */
    ".byte 0x67, 0xC3, 0x66, 0xE3, 0x4D, 0x0B, 0xE4, 0x08, 0x67, 0xC3, 0x66, 0xE3, 0x95, 0x37, 0x4D, 0x0B\n"  /* 0x060032E4 */
    ".byte 0xE4, 0x08, 0x67, 0xC3, 0x66, 0xE3, 0x95, 0x33, 0x4D, 0x0B, 0xE4, 0x08, 0x4F, 0x26, 0x6C, 0xF6\n"  /* 0x060032F4 */
    ".byte 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06003304 */
);

