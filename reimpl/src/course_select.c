/* course_select.c -- Course selection and game mode utilities
 *
 * FUN_06011494: Set course/track data pointer from a lookup table
 *   Clears a flag at 0x0607EADC, then loads a pointer from
 *   a table at 0x060447A8 indexed by param * 16.
 *
 * FUN_06014A42: Wrapper that calls two subsystem update functions
 *   FUN_06014F34 + FUN_0601712C (likely render + physics update pair)
 *
 * FUN_06012198: Dispatch based on a mode flag
 *   If 0x0607EAD8 != 0, call one path; otherwise call another.
 *
 * FUN_06040954: Compute VRAM offset from a result (shift left by 11)
 * FUN_06040964: Clamp a value to be >= 0 (calls FUN_06041648)
 *
 * Original addresses: 0x06011494, 0x06014A42, 0x06012198, 0x06040954, 0x06040964
 */

extern int FUN_06041648(void);
extern void FUN_06014F34(void);
extern void FUN_0601712C(void);

void FUN_06011494(unsigned short param_1)
{
    *(int *)0x0607EADC = 0;
    *(int *)0x06078860 = *(int *)(0x060447A8 + ((unsigned int)param_1 << 4));
}

void FUN_06014A42(void)
{
    FUN_06014F34();
    FUN_0601712C();
}

void FUN_06012198(void)
{
    int val = *(volatile int *)0x0607EAD8;
    if (val != 0) {
        (*(void (*)())0x0601228A)();
    } else {
        (*(void (*)())0x060127E0)();
    }
}

static int FUN_06040964(void);

int FUN_06040954(void)
{
    return FUN_06040964() << 11;
}

int FUN_06040964(void)
{
    int result;
    result = FUN_06041648();
    if (result < 0)
        result = 0;
    return result;
}
