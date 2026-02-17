/* sound_init.c -- Sound system command initialization
 *
 * Functions:
 *   FUN_0600A000 (0x0600A000) -- Send initial sound configuration commands
 *   FUN_06018FF8 (0x06018FF8) -- Prologue: clear flag, call FUN_06018FFC
 *   FUN_06018FFC (0x06018FFC) -- SCSP slot config + conditional VDP2 init
 *
 * FUN_0600A000 sends 5 commands via sound_cmd_dispatch to configure
 * audio channels and SCSP registers during game state init.
 *
 * FUN_06018FFC sends SCSP slot configs (cmd=15), calls FUN_060192e8,
 * conditionally loads sound data and clears a VDP2 register, then
 * sends final SCSP configs. Used for full sound system reset.
 *
 * Original addresses: 0x0600A000, 0x06018FF8, 0x06018FFC
 */

/* Sound command dispatcher (r4=command_id, r5=value) */
extern void sound_cmd_dispatch(int cmd, int value);

/* Sound subsystem init (defined in batch_subsystem_18.c) */
extern void FUN_060192e8(void);

/* Load sound data to SCSP RAM (defined in resource_loader.c) */
extern void FUN_06012EBC(void);

/* Sound state flag */
#define SOUND_STATE_FLAG  (*(volatile int *)0x06086050)

/* VDP2 register (sound-related display sync) */
#define VDP2_SOUND_SYNC   (*(volatile short *)0x25A02DBE)


/* ================================================================
 * FUN_0600A000 -- Sound Command Init (0x0600A000)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600A000-0x0600A024)
 * Pool verified:
 *   0x0600A06C = 0x0601D5F4 (sound_cmd_dispatch)
 *   0x0600A070 = 0xAE0001FF (SCSP slot 0 config)
 *   0x0600A074 = 0xAE0600FF (SCSP slot 6 config)
 *
 * 18 instructions. Saves r14, PR.
 * ================================================================ */
/* FUN_0600A000 -- original binary (38 bytes) */
__asm__(
    ".section .text.FUN_0600A000, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600A000\n"
    ".global _FUN_0600a000\n"
    ".type _FUN_0600A000, @function\n"
    "_FUN_0600A000:\n"
    "_FUN_0600a000:\n"
    ".byte 0x4F, 0x22, 0xDE, 0x1A, 0x4E, 0x0B, 0xE4, 0x01, 0xE5, 0x00, 0x4E, 0x0B, 0xE4, 0x03, 0xE5, 0x00\n"  /* 0x0600A000 */
    ".byte 0x4E, 0x0B, 0xE4, 0x02, 0xD5, 0x16, 0x4E, 0x0B, 0xE4, 0x00, 0xD5, 0x16, 0x4E, 0x0B, 0xE4, 0x00\n"  /* 0x0600A010 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0600A020 */
);



/* ================================================================
 * FUN_06018FFC -- SCSP Slot Config + Sound Data Load (0x06018FFC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06018FFC-0x06019038)
 * Pool verified:
 *   0x0601903C = 0x0601D5F4 (sound_cmd_dispatch)
 *   0x06019040 = 0x06086050 (sound state flag)
 *   0x06019044 = 0xAE0001FF (SCSP slot 0 config)
 *   0x06019048 = 0xAE0005FF (SCSP slot 5 config)
 *   0x0601904C = 0x06012EBC (load sound data)
 *   0x06019050 = 0x25A02DBE (VDP2 register)
 *   0x06019054 = 0xAE0600FF (SCSP slot 6 config)
 *
 * Body of FUN_06018FF8. Prologue sets r3=0 (flag clear value).
 * 30 instructions. Saves PR, uses r14 for sound_cmd_dispatch.
 * ================================================================ */
/* FUN_06018FFC -- original binary (92 bytes) */
__asm__(
    ".section .text.FUN_06018FFC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06018FFC\n"
    ".global _FUN_06018ffc\n"
    ".type _FUN_06018FFC, @function\n"
    "_FUN_06018FFC:\n"
    "_FUN_06018ffc:\n"
    ".byte 0x4F, 0x22, 0xDE, 0x0F, 0xD2, 0x0F, 0x22, 0x32, 0xD5, 0x0F, 0x4E, 0x0B, 0xE4, 0x0F, 0xD5, 0x0F\n"  /* 0x06018FFC */
    ".byte 0x4E, 0x0B, 0xE4, 0x0F, 0xB1, 0x6A, 0x00, 0x09, 0xD0, 0x0A, 0x60, 0x02, 0x20, 0x08, 0x8B, 0x05\n"  /* 0x0601900C */
    ".byte 0xD3, 0x0B, 0x43, 0x0B, 0x00, 0x09, 0xE2, 0x00, 0xD3, 0x0A, 0x23, 0x21, 0xD5, 0x0A, 0x4E, 0x0B\n"  /* 0x0601901C */
    ".byte 0xE4, 0x0F, 0xD5, 0x05, 0x4E, 0x0B, 0xE4, 0x0F, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6, 0xFF, 0xFF\n"  /* 0x0601902C */
    ".byte 0x06, 0x01, 0xD5, 0xF4, 0x06, 0x08, 0x60, 0x50, 0xAE, 0x00, 0x01, 0xFF, 0xAE, 0x00, 0x05, 0xFF\n"  /* 0x0601903C */
    ".byte 0x06, 0x01, 0x2E, 0xBC, 0x25, 0xA0, 0x2D, 0xBE, 0xAE, 0x06, 0x00, 0xFF\n"  /* 0x0601904C */
);



/* ================================================================
 * FUN_06018FF8 -- Sound SCSP Init Prologue (0x06018FF8)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06018FF8-0x06018FFA)
 *
 * 2-instruction prologue: pushes r14, sets r3=0 (flag clear value),
 * falls through to FUN_06018FFC. In C, just calls FUN_06018FFC
 * (the r3=0 is hardcoded in the body).
 * ================================================================ */
#if 0 /* FUN_06018FF8 -- replaced by ASM import */
void FUN_06018FF8(void)
{
    FUN_06018FFC();
}
#endif
