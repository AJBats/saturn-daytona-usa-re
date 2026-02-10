/* vdp1_cmd.c -- VDP1 command table / sprite rendering wrappers
 *
 * FUN_06014868: VDP1 draw with setup/teardown (mode=position)
 * FUN_06014884: VDP1 draw with setup/teardown (mode=scaled)
 * FUN_060148A2: Configure VDP1 drawing parameters from data table
 * FUN_0601492C: Set default VDP1 drawing parameters
 *
 * The function at 0x0603850C = VDP1 begin batch
 * The function at 0x06038520 = VDP1 end batch
 * The function at 0x06038794 = VDP1 draw positioned sprite
 * The function at 0x0603853C = VDP1 draw scaled sprite
 * The function at 0x06038BD4 = VDP1 set attribute
 *
 * Original addresses: 0x06014868, 0x06014884, 0x060148A2, 0x0601492C
 */

void FUN_06014868(int param_1, int param_2, int param_3)
{
    (*(void (*)())0x0603850C)();
    (*(void (*)(int, int))0x06038794)(param_2, param_3);
    (*(void (*)())0x06038520)();
}

void FUN_06014884(int param_1, int param_2, int param_3)
{
    (*(void (*)())0x0603850C)();
    (*(void (*)(int, int, int))0x0603853C)(param_2, param_3, 0);
    (*(void (*)())0x06038520)();
}

void FUN_060148A2(void)
{
    void (*set_attr)(int, int) = (void (*)(int, int))0x06038BD4;
    char *data = (char *)0x0605B71C;

    set_attr(0x100, (int)(char)data[0]);
    set_attr(4, (int)(char)data[1]);
    set_attr(8, (int)(char)data[2]);
    set_attr(0x10, (int)(char)data[3]);
    set_attr(0x20, (int)(char)data[4]);
    set_attr(1, (int)(char)data[5]);
}

void FUN_0601492C(void)
{
    void (*set_attr)(int, int) = (void (*)(int, int))0x06038BD4;

    set_attr(0x100, 4);
    set_attr(4, 1);
    set_attr(8, 5);
    set_attr(0x10, 6);
    set_attr(0x20, 7);
    set_attr(1, 0);
}
