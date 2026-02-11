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
void FUN_06012054(void)
{
    FUN_06038BD4(0x10, 7);     /* colorCalc = 7 */
    FUN_06038BD4(8, 6);        /* priority = 6 */
    FUN_06038BD4(0x100, 5);    /* texture = 5 */
    FUN_06038BD4(0x20, 3);     /* mesh = 3 */
    FUN_06038BD4(4, 1);        /* palette = 1 */
}


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
void FUN_06012084(void)
{
    FUN_06038BD4(8, 7);        /* priority = 7 */
    FUN_06038BD4(0x100, 5);    /* texture = 5 */
    FUN_06038BD4(0x10, 4);     /* colorCalc = 4 */
}


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
void FUN_060120A0(void)
{
    FUN_06038BD4(0x20, 7);     /* mesh = 7 */
    FUN_06038BD4(8, 6);        /* priority = 6 */
    FUN_06038BD4(0x100, 5);    /* texture = 5 */
    FUN_06038BD4(0x10, 4);     /* colorCalc = 4 */
}
