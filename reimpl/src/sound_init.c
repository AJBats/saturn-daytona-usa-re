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
void FUN_0600A000(void)
{
    /* Initialize sound channel (cmd 1 ignores value parameter) */
    sound_cmd_dispatch(1, 0);

    /* Mute all channels */
    sound_cmd_dispatch(3, 0);

    /* Set volume to zero */
    sound_cmd_dispatch(2, 0);

    /* Configure SCSP slot 0 */
    sound_cmd_dispatch(0, (int)0xAE0001FF);

    /* Configure SCSP slot 6 */
    sound_cmd_dispatch(0, (int)0xAE0600FF);
}


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
void FUN_06018FFC(void)
{
    /* Clear sound state flag */
    SOUND_STATE_FLAG = 0;

    /* Configure SCSP slot 0 (cmd 15 = direct SCSP write) */
    sound_cmd_dispatch(15, (int)0xAE0001FF);

    /* Configure SCSP slot 5 */
    sound_cmd_dispatch(15, (int)0xAE0005FF);

    /* Run sound subsystem init */
    FUN_060192e8();

    /* If flag still clear, load sound data and reset VDP2 sync */
    if (SOUND_STATE_FLAG == 0) {
        FUN_06012EBC();
        VDP2_SOUND_SYNC = 0;
    }

    /* Configure SCSP slot 6 */
    sound_cmd_dispatch(15, (int)0xAE0600FF);

    /* Re-configure SCSP slot 0 */
    sound_cmd_dispatch(15, (int)0xAE0001FF);
}


/* ================================================================
 * FUN_06018FF8 -- Sound SCSP Init Prologue (0x06018FF8)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06018FF8-0x06018FFA)
 *
 * 2-instruction prologue: pushes r14, sets r3=0 (flag clear value),
 * falls through to FUN_06018FFC. In C, just calls FUN_06018FFC
 * (the r3=0 is hardcoded in the body).
 * ================================================================ */
void FUN_06018FF8(void)
{
    FUN_06018FFC();
}
