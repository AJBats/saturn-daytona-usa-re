/* render_setup.c -- VDP1 rendering setup and mode configuration
 *
 * Functions that configure VDP1 sprite rendering attributes.
 * The function at 0x06038BD4 = set VDP1 attribute (key, value)
 * Attribute keys: 0x100=texture, 4=palette, 8=priority, 0x10=colorCalc, 0x20=mesh, 1=flip
 *
 * FUN_060148FC: Clear all VDP1 sprite attributes to 0
 * FUN_06014964: Set minimal attribute config (texture=0,palette=1,all others=0)
 * FUN_06014994: Set alternate attribute config (texture=4,palette=1,pri=0,cc=6,mesh=7,flip=0)
 * FUN_06012080: Set 3 VDP1 attributes (pri=7, texture=5, cc=4)
 * FUN_0601209E: Set 4 VDP1 attributes (mesh=7, pri=6, texture=5, cc=4)
 * FUN_060210F6: VDP1 batch render: begin, clear flag, draw, end
 * FUN_06021128: VDP1 batch render: begin, set flag, draw, end, clear counters
 * FUN_06020BCE: VDP1 draw + set engine flags + call 0x06026CE0
 * FUN_06020DD0: Loop calling FUN_06020DEE for channels 0-15
 * FUN_060149E0: VDP1 flag clear + enable (clear bit 15, set enable=1)
 * FUN_060033E6: Conditional VDP batch transfer (flag-based source select)
 *
 * Original addresses: 0x060148FC, 0x06014964, 0x06014994, 0x06012080, 0x0601209E,
 *   0x060210F6, 0x06021128, 0x06020BCE, 0x06020DD0, 0x060149E0, 0x060033E6
 */

extern void FUN_06020DEE(int);
extern int FUN_06038120(unsigned char *);
extern void FUN_060284AE(int, int, int, int);

void FUN_060148FC(void)
{
    void (*set_attr)(int, int) = (void (*)(int, int))0x06038BD4;
    set_attr(0x100, 0);
    set_attr(4, 0);
    set_attr(8, 0);
    set_attr(0x10, 0);
    set_attr(0x20, 0);
    set_attr(1, 0);
}

/* ================================================================
 * FUN_06014964 -- VDP1 Minimal Attribute Config (0x06014964)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06014964-0x06014992)
 * Pool verified:
 *   word pool at 0x060149C4 = 0x0100 (texture key)
 *   0x060149C8 = 0x06038BD4 (set_attr function)
 *
 * Sets VDP1 attributes: texture=0, palette=1, all others=0.
 * Used as a reset/minimal config for sprite rendering.
 *
 * 24 instructions. Saves PR + r14.
 * ================================================================ */
void FUN_06014964(void)
{
    void (*set_attr)(int, int) = (void (*)(int, int))0x06038BD4;
    set_attr(0x100, 0);
    set_attr(4, 1);
    set_attr(8, 0);
    set_attr(0x10, 0);
    set_attr(0x20, 0);
    set_attr(1, 0);
}

void FUN_06014994(void)
{
    void (*set_attr)(int, int) = (void (*)(int, int))0x06038BD4;
    set_attr(0x100, 4);
    set_attr(4, 1);
    set_attr(8, 0);
    set_attr(0x10, 6);
    set_attr(0x20, 7);
    set_attr(1, 0);
}

void FUN_06012080(void)
{
    void (*set_attr)(int, int) = (void (*)(int, int))0x06038BD4;
    set_attr(8, 7);
    set_attr(0x100, 5);
    set_attr(0x10, 4);
}

void FUN_0601209E(void)
{
    void (*set_attr)(int, int) = (void (*)(int, int))0x06038BD4;
    set_attr(0x20, 7);
    set_attr(8, 6);
    set_attr(0x100, 5);
    set_attr(0x10, 4);
}

void FUN_060210F6(void)
{
    (*(void (*)(int))0x0603850C)(8);
    *(char *)0x06087C87 = 0;
    FUN_06038120((unsigned char *)0x06087C84);
    (*(void (*)())0x06038520)();
}

void FUN_06021128(void)
{
    (*(void (*)(int))0x0603850C)(8);
    *(int *)0x06087C87 = 1;
    FUN_06038120((unsigned char *)0x06087C84);
    (*(void (*)())0x06038520)();
    *(int *)0x06089594 = 0;
    *(int *)0x06089595 = 0;
    *(int *)0x06089598 = 0;
}

void FUN_06020BCE(void)
{
    (*(void (*)(int))0x0603850C)(8);
    (*(void (*)(int))0x06038794)(0x00010000);
    (*(void (*)())0x06038520)();
    *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | (unsigned int)0x04000000;
    *(short *)0x0608780C = 2;
    *(int *)0x0605A00C = 0;
    (*(void (*)())0x06026CE0)();
}

void FUN_06020DD0(void)
{
    unsigned char i = 0;
    do {
        FUN_06020DEE(i);
        i = i + 1;
    } while (i < 0x10);
}


/* ================================================================
 * FUN_060149E0 -- VDP1 Flag Clear + Enable (0x060149E0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060149E0-0x060149F2)
 * Pool verified:
 *   word pool at 0x060149F4 = 0x7FFF (bit 15 mask)
 *   0x060149FC = 0x060A3D88 (VDP1 control flag)
 *   0x06014A00 = 0x060635AC (VDP1 enable register)
 *
 * Clears bit 15 of VDP1 control flag at 0x060A3D88, then sets
 * the VDP1 enable register at 0x060635AC to 1.
 * Leaf function (no PR save). 10 instructions.
 * ================================================================ */
void FUN_060149E0(void)
{
    *(volatile short *)0x060A3D88 &= 0x7FFF;
    *(volatile short *)0x060635AC = 1;
}


/* ================================================================
 * FUN_060033E6 -- Conditional VDP Batch Transfer (0x060033E6)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060033E6-0x06003404)
 * Pool verified:
 *   0x06003424 = 0x0607EBC8 (engine state flags)
 *   0x06003428 = 0x06044638 (VDP data source A)
 *   0x0600342C = 0x0605ACF0 (VDP data source B)
 *   0x06003420 = 0x060284AE (VDP batch transfer function)
 *   word pool at 0x0600340A = 0x0090 (size A)
 *   word pool at 0x0600340C = 0x0C04 (size B)
 *   word pool at 0x06003406 = 0x0200 (size C)
 *   word pool at 0x06003408 = 0x5000 (size D)
 *
 * Tests bit 2 of engine state flags. If set, transfers from
 * source A (0x06044638) with sizes 0x0C04/0x0090. If clear,
 * transfers from source B (0x0605ACF0) with sizes 0x5000/0x0200.
 * Both paths tail-call FUN_060284AE with cmd=8.
 *
 * Leaf function (no PR save). 16 instructions + pool.
 * ================================================================ */
void FUN_060033E6(void)
{
    if (*(volatile int *)0x0607EBC8 & 0x04) {
        FUN_060284AE(8, 0x0C04, 0x0090, 0x06044638);
    } else {
        FUN_060284AE(8, 0x5000, 0x0200, 0x0605ACF0);
    }
}
