/* resource_loader.c -- CD/asset resource loading wrappers
 *
 * These functions all call FUN_06012C3C (a CD data loader) with
 * different parameter table addresses and destination base addresses.
 * They form a family of resource loading entry points for different
 * game assets (models, textures, palettes, etc.).
 *
 * FUN_06012C3C takes: (param_table_addr, dest_base_addr)
 * Each param table presumably contains source offset, size, etc.
 *
 * Original addresses: 0x06012E00, 0x06012E62, 0x06012E6A, 0x06012E7C,
 *   0x06012E84, 0x06012EBC, 0x06012EC4, 0x06012EDC,
 *   0x06012F00, 0x06012F10, 0x06012F20, 0x06012F50,
 *   0x06012F58, 0x06012F60
 */

extern void FUN_06012C3C(int table, int base);

void FUN_06012E00(void)
{
    FUN_06012C3C(0x06044960, 0x002A0000);
}

void FUN_06012E62(void)
{
    FUN_06012C3C(0x06044990, 0x002A0000);
}

void game_subsystem_init2(void)
{
    FUN_06012C3C(0x0604499C, 0x002F0000);
    FUN_06012C3C(0x060449A8, 0x060F8000);
}

void FUN_06012E7C(void)
{
    FUN_06012C3C(0x060449B4, 0x002F8000);
}

void FUN_06012E84(void)
{
    FUN_06012C3C(0x060449BC, 0x25A00000);
}

void FUN_06012EBC(void)
{
    FUN_06012C3C(0x060449C8, 0x25A03000);
}

void FUN_06012EC4(void)
{
    FUN_06012C3C(0x060449C8, 0x00200000);
}

void FUN_06012EDC(void)
{
    FUN_06012C3C(0x060449EC, 0x25A03000);
}

void FUN_06012F00(void)
{
    FUN_06012C3C(0x060449EC, 0x0026D000);
}

void FUN_06012F10(void)
{
    FUN_06012C3C(0x06044A04, 0x25A03000);
}

void FUN_06012F20(void)
{
    FUN_06012C3C(0x06044A1C, 0x25A03000);
}

void FUN_06012F50(void)
{
    FUN_06012C3C(0x06044A34, 0x25A03000);
}

void FUN_06012F58(void)
{
    FUN_06012C3C(0x06044A40, 0x25A03000);
}

void FUN_06012F60(void)
{
    FUN_06012C3C(0x06044A4C, 0x25A03000);
}
