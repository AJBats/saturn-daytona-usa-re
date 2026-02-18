/* FUN_060423CC - SCDQ poll with timeout bypass
 *
 * Original function polls HIRQ bit 10 (SCDQ) forever.
 * In shifted builds, CDB timing causes SCDQ to never fire.
 * This C replacement adds a large timeout so the boot continues.
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
    for (i = 0; i < 50000000; i++) {
        int hirq = sym_06035C4E();
        hirq = (short)hirq;
        if (hirq & 0x0400) {
            FUN_06035C54((int)~0x0400);
            return;
        }
    }
    /* Timeout - return without acknowledging SCDQ */
}
