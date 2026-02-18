/* FUN_060423CC - SCDQ poll with forced acknowledge bypass
 *
 * Original function polls HIRQ bit 10 (SCDQ) forever.
 * In shifted builds, CDB timing causes SCDQ to never fire.
 * This C replacement polls briefly, then forces the acknowledge.
 *
 * Critical: the CALLER (FUN_0603B21C) retries in a loop until
 * SCDQ is acknowledged. A simple timeout return causes the caller
 * to loop forever. We MUST call FUN_06035C54 to acknowledge.
 *
 * Original flow:
 *   1. Call sym_06035C4E() to read HIRQ register
 *   2. Sign-extend result, check bit 10 (0x0400 = SCDQ)
 *   3. If set: call FUN_06035C54(~0x0400) to acknowledge, return
 *   4. If not set: loop forever
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
