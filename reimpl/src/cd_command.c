/* cd_command.c -- CD subsystem command dispatch helpers
 *
 * Functions:
 *   FUN_06018E70 (0x06018E70) -- Send CD command 3 (play/resume)
 *   FUN_06018E88 (0x06018E88) -- Send CD command 0 (stop/reset)
 *   cd_status_read / FUN_06018EAC (0x06018EAC) -- Read CD status register
 *
 * These are small wrappers around the CD command dispatch subsystem.
 * FUN_06034DEA is the underlying CD command executor that takes a
 * pointer to a command buffer (first word = command ID).
 * FUN_060349C4 is the CD status query function.
 *
 * Original addresses: 0x06018E70, 0x06018E88, 0x06018EAC
 */

/* External CD subsystem functions */
extern void FUN_06034DEA(int *cmd_buf);     /* CD command executor */
extern void FUN_060349C4(int *result_buf);  /* CD status query */


/* ================================================================
 * FUN_06018E70 -- Send CD Command 3 (0x06018E70)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06018E70-0x06018E86)
 * Pool verified:
 *   0x06018EA8 = 0x06034DEA (CD command executor)
 *
 * Allocates 8-byte stack buffer, sets command ID = 3,
 * calls FUN_06034DEA with pointer to buffer.
 * Called from 5+ game state handlers (states 0, 3, 6, 13, 17).
 *
 * 10 instructions. Saves PR.
 * ================================================================ */
/* FUN_06018E70 -- original binary (24 bytes) */
__asm__(
    ".section .text.FUN_06018E70, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06018E70\n"
    ".global _FUN_06018e70\n"
    ".type _FUN_06018E70, @function\n"
    "_FUN_06018E70:\n"
    "_FUN_06018e70:\n"
    ".byte 0x4F, 0x22, 0xE2, 0x03, 0x7F, 0xF8, 0x63, 0xF3, 0x23, 0x22, 0xD3, 0x0B, 0x43, 0x0B, 0x64, 0xF3\n"  /* 0x06018E70 */
    ".byte 0x7F, 0x08, 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06018E80 */
);



/* ================================================================
 * FUN_06018E88 -- Send CD Command 0 (0x06018E88)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06018E88-0x06018E9E)
 * Pool verified:
 *   0x06018EA8 = 0x06034DEA (CD command executor)
 *
 * Identical to FUN_06018E70 but command ID = 0.
 *
 * 10 instructions. Saves PR.
 * ================================================================ */
#if 0 /* FUN_06018E88 -- replaced by ASM import */
void FUN_06018E88(void)
{
    int buf[2];
    buf[0] = 0;
    FUN_06034DEA(buf);
}
#endif

/* FUN_06018E88 -- original binary (36 bytes) */
__asm__(
    ".section .text.FUN_06018E88, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06018E88\n"
    ".global _FUN_06018e88\n"
    ".type _FUN_06018E88, @function\n"
    "_FUN_06018E88:\n"
    "_FUN_06018e88:\n"
    ".byte 0x4F, 0x22, 0xE2, 0x00, 0x7F, 0xF8, 0x63, 0xF3, 0x23, 0x22, 0xD3, 0x05, 0x43, 0x0B, 0x64, 0xF3\n"  /* 0x06018E88 */
    ".byte 0x7F, 0x08, 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09, 0x00, 0xFF, 0xFF, 0xFF, 0x06, 0x03, 0x4D, 0x1C\n"  /* 0x06018E98 */
    ".byte 0x06, 0x03, 0x4D, 0xEA\n"  /* 0x06018EA8 */
);



/* ================================================================
 * cd_status_read / FUN_06018EAC -- Read CD Status (0x06018EAC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06018EAC-0x06018EC6)
 * Pool verified:
 *   0x06018ED8 = 0x060349C4 (CD status query)
 *
 * Allocates 12-byte stack buffer, calls FUN_060349C4 to fill it,
 * reads the first byte of the result, masks with 0x1F, returns it.
 *
 * The 5-bit result represents the CD drive state:
 *   bits 4:0 = status code (busy, ready, playing, etc.)
 *
 * 14 instructions. Saves PR. Returns int.
 * ================================================================ */
#if 0 /* cd_status_read -- replaced by ASM import of FUN_06018EAC below */
int cd_status_read(void)
{
    int buf[3];
    FUN_060349C4(buf);
    return ((*(volatile unsigned char *)buf) & 0xFF) & 31;
}
#endif
#if 0 /* FUN_06018EAC -- replaced by ASM import */
void FUN_06018EAC(void) __attribute__((alias("cd_status_read")));
#endif

/* FUN_06018EAC -- original binary (56 bytes) */
__asm__(
    ".section .text.FUN_06018EAC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06018EAC\n"
    ".global _FUN_06018eac\n"
    ".global _cd_status_read\n"
    ".type _FUN_06018EAC, @function\n"
    "_FUN_06018EAC:\n"
    "_FUN_06018eac:\n"
    "_cd_status_read:\n"
    ".byte 0x4F, 0x22, 0x7F, 0xF4, 0xD3, 0x09, 0x43, 0x0B, 0x64, 0xF3, 0x60, 0xF3, 0xE4, 0x1F, 0x60, 0x00\n"  /* 0x06018EAC */
    ".byte 0x7F, 0x0C, 0x60, 0x0C, 0x4F, 0x26, 0x24, 0x09, 0x00, 0x0B, 0x60, 0x43, 0x94, 0x05, 0xD2, 0x04\n"  /* 0x06018EBC */
    ".byte 0x63, 0x4C, 0x22, 0x30, 0xD3, 0x03, 0x00, 0x0B, 0x23, 0x40, 0x00, 0xE0, 0x06, 0x03, 0x49, 0xC4\n"  /* 0x06018ECC */
    ".byte 0x25, 0xB0, 0x02, 0x17, 0x25, 0xB0, 0x02, 0x37\n"  /* 0x06018EDC */
);
