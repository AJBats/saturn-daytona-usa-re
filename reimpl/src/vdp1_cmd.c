/* vdp1_cmd.c -- VDP1 command table / sprite rendering wrappers
 *
 * vdp2_scroll_setup: VDP1 draw with setup/teardown (mode=position)
 * vdp2_scroll_update: VDP1 draw with setup/teardown (mode=scaled)
 * FUN_060148A2: Configure VDP1 drawing parameters from data table
 * vdp_system_init_a: Set default VDP1 drawing parameters
 *
 * The function at 0x0603850C = VDP1 begin batch
 * The function at 0x06038520 = VDP1 end batch
 * The function at 0x06038794 = VDP1 draw positioned sprite
 * The function at 0x0603853C = VDP1 draw scaled sprite
 * The function at 0x06038BD4 = VDP1 set attribute
 *
 * Original addresses: 0x06014868, 0x06014884, 0x060148A2, 0x0601492C
 */

void vdp2_scroll_setup(int param_1, int param_2, int param_3)
{
    (*(void (*)())0x0603850C)();
    (*(void (*)(int, int))0x06038794)(param_2, param_3);
    (*(void (*)())0x06038520)();
}

void vdp2_scroll_update(int param_1, int param_2, int param_3)
{
    (*(void (*)())0x0603850C)();
    (*(void (*)(int, int, int))0x0603853C)(param_2, param_3, 0);
    (*(void (*)())0x06038520)();
}

/* FUN_060148A2 -- original binary (90 bytes) */
__asm__(
    ".section .text.FUN_060148A2, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060148A2\n"
    ".type _FUN_060148A2, @function\n"
    "_FUN_060148A2:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x4F, 0x22, 0xDD, 0x12, 0xDE, 0x13, 0x94, 0x19, 0x4E, 0x0B, 0x65, 0xD0\n"  /* 0x060148A2 */
    ".byte 0x84, 0xD1, 0x65, 0x03, 0x4E, 0x0B, 0xE4, 0x04, 0x84, 0xD2, 0x65, 0x03, 0x4E, 0x0B, 0xE4, 0x08\n"  /* 0x060148B2 */
    ".byte 0x84, 0xD3, 0x65, 0x03, 0x4E, 0x0B, 0xE4, 0x10, 0x84, 0xD4, 0x65, 0x03, 0x4E, 0x0B, 0xE4, 0x20\n"  /* 0x060148C2 */
    ".byte 0x84, 0xD5, 0x65, 0x03, 0x4E, 0x0B, 0xE4, 0x01, 0x4F, 0x26, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x060148D2 */
    ".byte 0x01, 0x00, 0x06, 0x03, 0x85, 0x0C, 0x06, 0x03, 0x87, 0x94, 0x06, 0x03, 0x85, 0x20, 0x06, 0x03\n"  /* 0x060148E2 */
    ".byte 0x85, 0x3C, 0x06, 0x05, 0xB7, 0x1C, 0x06, 0x03, 0x8B, 0xD4\n"  /* 0x060148F2 */
);


void vdp_system_init_a(void)
{
    void (*set_attr)(int, int) = (void (*)(int, int))0x06038BD4;

    set_attr(0x100, 4);
    set_attr(4, 1);
    set_attr(8, 5);
    set_attr(0x10, 6);
    set_attr(0x20, 7);
    set_attr(1, 0);
}


/* VDP command template helper: returns byte template pointer */
extern char *FUN_060282c0(int param);

/* VDP command lookup table base address */
#define VDP_CMD_TABLE_BASE  0x06028614


/* ================================================================
 * FUN_06028384 -- VDP1 Command Template Copy (0x06028384)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06028384-0x060283A8)
 * Pool verified:
 *   0x060283AC = 0x06028614 (command lookup table base)
 *   BSR target 0x060282C0 (template pointer helper)
 *
 * Looks up a base pointer from table at 0x06028614 using index,
 * double-dereferences to get an offset, adjusts destination base.
 * Calls FUN_060282c0 to get a byte template, then copies 12 bytes
 * (each sign-extended + offset) as 12 shorts to destination.
 *
 * 18 instructions. Saves PR.
 * ================================================================ */
void FUN_06028384(int index, int dest_base, int offset, int cmd_type)
{
    int i;
    char *src;

    /* Double-indirect lookup: table[index] -> ptr -> base_offset */
    int base_offset = *(int *)(*(int *)(VDP_CMD_TABLE_BASE + index));
    dest_base += base_offset;

    /* Get byte template from helper (r7 passed as r4 in original) */
    src = FUN_060282c0(cmd_type);

    /* Copy 12 bytes as shorts, adding offset to each */
    for (i = 0; i <= 22; i += 2) {
        *(short *)(dest_base + i) = (short)((int)*src++ + offset);
    }
}
