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
 * FUN_06026CE0: VDP hardware sync -- busy-wait for VDP operation completion
 * FUN_0600A084: Render tilt parameter -- compute screen tilt from car physics
 *
 * Original addresses: 0x060148FC, 0x06014964, 0x06014994, 0x06012080, 0x0601209E,
 *   0x060210F6, 0x06021128, 0x06020BCE, 0x06020DD0, 0x060149E0, 0x060033E6,
 *   0x06026CE0, 0x0600A084
 */

extern void FUN_06020DEE(int);
extern int FUN_06038120(unsigned char *);
extern void FUN_060284AE(int, int, int, int);
extern void FUN_06014884(int type, int value, int flags);

/* FUN_060148FC -- original binary (48 bytes) */
__asm__(
    ".section .text.FUN_060148FC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060148FC\n"
    ".type _FUN_060148FC, @function\n"
    "_FUN_060148FC:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0xDE, 0x17, 0x94, 0x2B, 0x4E, 0x0B, 0xE5, 0x00, 0xE5, 0x00, 0x4E, 0x0B\n"  /* 0x060148FC */
    ".byte 0xE4, 0x04, 0xE5, 0x00, 0x4E, 0x0B, 0xE4, 0x08, 0xE5, 0x00, 0x4E, 0x0B, 0xE4, 0x10, 0xE5, 0x00\n"  /* 0x0601490C */
    ".byte 0x4E, 0x0B, 0xE4, 0x20, 0xE5, 0x00, 0x4E, 0x0B, 0xE4, 0x01, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0601491C */
);


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
/* FUN_06014964 -- original binary (48 bytes) */
__asm__(
    ".section .text.FUN_06014964, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06014964\n"
    ".type _FUN_06014964, @function\n"
    "_FUN_06014964:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0xDE, 0x17, 0x94, 0x2B, 0x4E, 0x0B, 0xE5, 0x00, 0xE5, 0x01, 0x4E, 0x0B\n"  /* 0x06014964 */
    ".byte 0xE4, 0x04, 0xE5, 0x00, 0x4E, 0x0B, 0xE4, 0x08, 0xE5, 0x00, 0x4E, 0x0B, 0xE4, 0x10, 0xE5, 0x00\n"  /* 0x06014974 */
    ".byte 0x4E, 0x0B, 0xE4, 0x20, 0xE5, 0x00, 0x4E, 0x0B, 0xE4, 0x01, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06014984 */
);


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

/* FUN_06021128 -- original binary (80 bytes) */
__asm__(
    ".section .text.FUN_06021128, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06021128\n"
    ".type _FUN_06021128, @function\n"
    "_FUN_06021128:\n"
    ".byte 0x4F, 0x22, 0xD3, 0x0B, 0x43, 0x0B, 0xE4, 0x08, 0xE2, 0x01, 0xD3, 0x0A, 0x23, 0x20, 0xD4, 0x0A\n"  /* 0x06021128 */
    ".byte 0xD3, 0x0A, 0x43, 0x0B, 0x00, 0x09, 0xD3, 0x0A, 0x43, 0x0B, 0x00, 0x09, 0xE4, 0x00, 0xD3, 0x09\n"  /* 0x06021138 */
    ".byte 0x23, 0x40, 0xD3, 0x09, 0x23, 0x40, 0xD3, 0x09, 0x4F, 0x26, 0x00, 0x0B, 0x23, 0x42, 0xFF, 0xFF\n"  /* 0x06021148 */
    ".byte 0x06, 0x03, 0x85, 0x0C, 0x06, 0x08, 0x7C, 0x87, 0x06, 0x08, 0x7C, 0x84, 0x06, 0x03, 0x81, 0x20\n"  /* 0x06021158 */
    ".byte 0x06, 0x03, 0x85, 0x20, 0x06, 0x08, 0x95, 0x94, 0x06, 0x08, 0x95, 0x95, 0x06, 0x08, 0x95, 0x98\n"  /* 0x06021168 */
);


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


/* ================================================================
 * FUN_06026CE0 -- VDP Hardware Sync (0x06026CE0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06026CE0-0x06026D20)
 * Pool verified:
 *   0x06026D24 = 0x060635C4 (VDP sync trigger register)
 *   0x06026D28 = 0x0605A010 (iteration counter output)
 *
 * Writes 1 to VDP sync register to trigger an operation, then
 * busy-waits with 20-nop padding until the register reads != 1
 * (hardware clears it when done). Counts polling iterations and
 * stores the count to 0x0605A010.
 *
 * Called from 40+ locations across state handlers, VDP init,
 * and rendering pipeline. Core synchronization primitive.
 *
 * Leaf function (no PR save). 34 instructions (20 are nops).
 * ================================================================ */
void FUN_06026CE0(void)
{
    volatile int *sync_reg = (volatile int *)0x060635C4;
    int count = 0;
    int val;

    /* Trigger VDP operation */
    *sync_reg = 1;

    /* Busy-wait until hardware clears the register */
    do {
        val = *sync_reg;
        /* 20 nops for bus timing / synchronization delay */
        asm volatile(
            "nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t"
            "nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t"
            "nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t"
            "nop\n\tnop\n\tnop\n\tnop\n\tnop"
        );
        val--;
        count++;
    } while (val == 0);

    *(volatile int *)0x0605A010 = count;
}


/* ================================================================
 * FUN_0600A084 -- Render Tilt Parameter (0x0600A084)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600A084-0x0600A0BE)
 * Pool verified:
 *   0x0600A114 = 0x0607E944 (car struct pointer)
 *   0x0600A10C = 0x00BC (car struct field offset, word pool)
 *   0x0600A118 = 0x06014884 (render parameter setter)
 *   0x0600A11C = 0x0607EBC8 (engine state flags)
 *
 * Reads car struct field at offset 0xBC (physics/tilt value).
 * If <= 1: sets render param 16 (colorCalc) to 0.
 * If > 1: shifts value left 15 bits, negates if engine flag
 * bit 0 is set, then sets render param 16 to the result.
 *
 * Used for screen banking/tilt effect during cornering.
 * Leaf function (no PR save). 30 instructions.
 * ================================================================ */
void FUN_0600A084(void)
{
    int *car_ptr = *(int **)0x0607E944;
    int field = *(int *)((char *)car_ptr + 0xBC);

    if (field <= 1) {
        FUN_06014884(16, 0, 0);
        return;
    }

    int value = *(int *)((char *)car_ptr + 0xBC);
    value <<= 15;

    if (*(volatile int *)0x0607EBC8 & 1) {
        value = -value;
    }

    FUN_06014884(16, value, 0);
}
