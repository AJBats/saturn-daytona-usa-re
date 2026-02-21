/* FUN_060423CC - Wait for CD SCDQ (subcode Q) interrupt
 *
 * Polls HIRQ bit 10 (SCDQ) and acknowledges when set.
 * Retail version polls forever — a latent bug that hangs on real
 * hardware when CD timing is tight. This version adds a timeout.
 */

extern int sym_06035C4E(void);
extern void FUN_06035C54(int);

void FUN_060423CC(void)
{
    int i;
    for (i = 0; i < 1000; i++) {
        int hirq = sym_06035C4E();
        hirq = (short)hirq;
        if (hirq & 0x0400) {
            FUN_06035C54((int)~0x0400);
            return;
        }
    }
    /* Timeout - force acknowledge so caller doesn't retry forever */
    FUN_06035C54((int)~0x0400);
}
