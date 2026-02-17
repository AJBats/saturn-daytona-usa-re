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

#if 0 /* FUN_06014A42 -- replaced by ASM import */
void FUN_06014A42(void)
{
    FUN_06014F34();
    FUN_0601712C();
}
#endif

/* FUN_06014A42 -- original binary (50 bytes) */
__asm__(
    ".section .text.FUN_06014A42, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06014A42\n"
    ".global _FUN_06014a42\n"
    ".type _FUN_06014A42, @function\n"
    "_FUN_06014A42:\n"
    "_FUN_06014a42:\n"
    ".byte 0x4F, 0x22, 0xB2, 0x76, 0x00, 0x09, 0xD3, 0x09, 0x43, 0x2B, 0x4F, 0x26, 0x02, 0x60, 0x25, 0xC0\n"  /* 0x06014A42 */
    ".byte 0x00, 0x00, 0x06, 0x04, 0x4B, 0x64, 0x06, 0x05, 0x9F, 0xFC, 0x06, 0x02, 0x76, 0x1E, 0x06, 0x01\n"  /* 0x06014A52 */
    ".byte 0x72, 0xBC, 0x06, 0x07, 0xEB, 0xF4, 0x06, 0x08, 0x5F, 0x90, 0x06, 0x08, 0x5F, 0x94, 0x06, 0x01\n"  /* 0x06014A62 */
    ".byte 0x71, 0x2C\n"  /* 0x06014A72 */
);


void FUN_06012198(void)
{
    int val = *(volatile int *)0x0607EAD8;
    if (val != 0) {
        (*(void (*)())0x0601228A)();
    } else {
        (*(void (*)())0x060127E0)();
    }
}

#if 0 /* FUN_06040964 -- replaced by ASM import */
int FUN_06040964(void);

/* FUN_06040954 -- original binary (16 bytes) */
__asm__(
    ".section .text.FUN_06040954, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06040954\n"
    ".type _FUN_06040954, @function\n"
    "_FUN_06040954:\n"
    ".byte 0x4F, 0x22, 0xB0, 0x05, 0x00, 0x09, 0x40, 0x18, 0x4F, 0x26, 0x40, 0x08, 0x00, 0x0B, 0x40, 0x00\n"  /* 0x06040954 */
);


int FUN_06040964(void)
{
    int result;
    result = FUN_06041648();
    if (result < 0)
        result = 0;
    return result;
}
#endif

/* FUN_06040964 -- original binary (24 bytes) */
__asm__(
    ".section .text.FUN_06040964, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06040964\n"
    ".type _FUN_06040964, @function\n"
    "_FUN_06040964:\n"
    ".byte 0x4F, 0x22, 0xD3, 0x12, 0x43, 0x0B, 0x00, 0x09, 0x64, 0x03, 0x44, 0x11, 0x89, 0x00, 0xE4, 0x00\n"  /* 0x06040964 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x60, 0x43, 0x62, 0x63\n"  /* 0x06040974 */
);

