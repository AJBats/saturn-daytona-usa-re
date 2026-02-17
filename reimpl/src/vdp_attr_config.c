/* vdp_attr_config.c -- VDP1 attribute preset configuration (body functions)
 *
 * Functions:
 *   FUN_06012054 (0x06012054) -- Set 5 VDP1 attributes (cc=7, pri=6, tex=5, mesh=3, pal=1)
 *   FUN_06012084 (0x06012084) -- Set 3 VDP1 attributes (pri=7, tex=5, cc=4)
 *   FUN_060120A0 (0x060120A0) -- Set 4 VDP1 attributes (mesh=7, pri=6, tex=5, cc=4)
 *
 * These are the "body" halves of prologue+body function pairs:
 *   FUN_06012050 -> FUN_06012054 (prologue sets r5=7)
 *   FUN_06012080 -> FUN_06012084 (prologue sets r5=7)
 *   FUN_0601209E -> FUN_060120A0 (prologue sets r5=7)
 *
 * The prologue functions are already translated in:
 *   - batch_subsystem_12.c (FUN_06012050)
 *   - render_setup.c (FUN_06012080, FUN_0601209E)
 *
 * FUN_06038BD4 = VDP1 attribute setter (key, value)
 * Attribute keys (from render_setup.c):
 *   0x100=texture, 4=palette, 8=priority, 0x10=colorCalc, 0x20=mesh, 1=flip
 *
 * Original addresses: 0x06012054, 0x06012084, 0x060120A0
 */

extern void FUN_06038BD4(int key, int value);


/* ================================================================
 * FUN_06012054 -- VDP1 Attribute Preset: 5 Attrs (0x06012054)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06012054-0x06012078)
 * Pool verified:
 *   0x0601207A = 0x0100 (texture key)
 *   0x0601207C = 0x06038BD4 (attribute setter)
 *
 * Body of FUN_06012050. First call's value (r5) = 7 from prologue.
 * 18 instructions. Saves PR, uses r14 as function pointer.
 * ================================================================ */
/* FUN_06012054 -- original binary (44 bytes) */
__asm__(
    ".section .text.FUN_06012054, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06012054\n"
    ".type _FUN_06012054, @function\n"
    "_FUN_06012054:\n"
    ".byte 0x4F, 0x22, 0xDE, 0x09, 0x4E, 0x0B, 0xE4, 0x10, 0xE5, 0x06, 0x4E, 0x0B, 0xE4, 0x08, 0x94, 0x0A\n"  /* 0x06012054 */
    ".byte 0x4E, 0x0B, 0xE5, 0x05, 0xE5, 0x03, 0x4E, 0x0B, 0xE4, 0x20, 0xE5, 0x01, 0x4E, 0x0B, 0xE4, 0x04\n"  /* 0x06012064 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0x01, 0x00, 0x06, 0x03, 0x8B, 0xD4\n"  /* 0x06012074 */
);



/* ================================================================
 * FUN_06012084 -- VDP1 Attribute Preset: 3 Attrs (0x06012084)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06012084-0x0601209C)
 * Pool verified:
 *   0x060120C2 = 0x0100 (texture key)
 *   0x060120C4 = 0x06038BD4 (attribute setter)
 *
 * Body of FUN_06012080. First call's value (r5) = 7 from prologue.
 * 14 instructions. Saves PR, uses r14 as function pointer.
 * ================================================================ */
/* FUN_06012084 -- original binary (28 bytes) */
__asm__(
    ".section .text.FUN_06012084, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06012084\n"
    ".type _FUN_06012084, @function\n"
    "_FUN_06012084:\n"
    ".byte 0x4F, 0x22, 0xDE, 0x0F, 0x4E, 0x0B, 0xE4, 0x08, 0x94, 0x19, 0x4E, 0x0B, 0xE5, 0x05, 0xE5, 0x04\n"  /* 0x06012084 */
    ".byte 0x4E, 0x0B, 0xE4, 0x10, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0xE5, 0x07\n"  /* 0x06012094 */
);



/* ================================================================
 * FUN_060120A0 -- VDP1 Attribute Preset: 4 Attrs (0x060120A0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060120A0-0x060120C0)
 * Pool verified:
 *   0x060120C2 = 0x0100 (texture key)
 *   0x060120C4 = 0x06038BD4 (attribute setter)
 *
 * Body of FUN_0601209E. First call's value (r5) = 7 from prologue.
 * 18 instructions. Saves r14, PR, uses r14 as function pointer.
 * ================================================================ */
/* FUN_060120A0 -- original binary (40 bytes) */
__asm__(
    ".section .text.FUN_060120A0, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060120A0\n"
    ".global _FUN_060120a0\n"
    ".type _FUN_060120A0, @function\n"
    "_FUN_060120A0:\n"
    "_FUN_060120a0:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0xDE, 0x07, 0x4E, 0x0B, 0xE4, 0x20, 0xE5, 0x06, 0x4E, 0x0B, 0xE4, 0x08\n"  /* 0x060120A0 */
    ".byte 0x94, 0x07, 0x4E, 0x0B, 0xE5, 0x05, 0xE5, 0x04, 0x4E, 0x0B, 0xE4, 0x10, 0x4F, 0x26, 0x00, 0x0B\n"  /* 0x060120B0 */
    ".byte 0x6E, 0xF6, 0x01, 0x00, 0x06, 0x03, 0x8B, 0xD4\n"  /* 0x060120C0 */
);

