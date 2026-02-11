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
void FUN_06018E70(void)
{
    int buf[2];
    buf[0] = 3;
    FUN_06034DEA(buf);
}


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
void FUN_06018E88(void)
{
    int buf[2];
    buf[0] = 0;
    FUN_06034DEA(buf);
}


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
int cd_status_read(void)
{
    int buf[3];
    FUN_060349C4(buf);
    return ((*(volatile unsigned char *)buf) & 0xFF) & 31;
}
void FUN_06018EAC(void) __attribute__((alias("cd_status_read")));
