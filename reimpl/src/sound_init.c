/* sound_init.c -- Sound system command initialization
 *
 * Functions:
 *   FUN_0600A000 (0x0600A000) -- Send initial sound configuration commands
 *
 * Sends 5 commands to the sound subsystem via sound_cmd_dispatch
 * (FUN_0601D5F4) to configure audio channels and SCSP registers.
 *
 * Commands sent:
 *   1. cmd=1 (channel init, no value)
 *   2. cmd=3, value=0 (mute all)
 *   3. cmd=2, value=0 (volume zero)
 *   4. cmd=0, value=0xAE0001FF (SCSP register write: slot 0 config)
 *   5. cmd=0, value=0xAE0600FF (SCSP register write: slot 6 config)
 *
 * Called during game state initialization to reset sound hardware.
 *
 * Original address: 0x0600A000
 */

/* Sound command dispatcher (r4=command_id, r5=value) */
extern void sound_cmd_dispatch(int cmd, int value);


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
