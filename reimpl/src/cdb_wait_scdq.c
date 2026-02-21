/* cdb_wait_scdq — Wait for CD block Subcode Q data ready
 *
 * LLM says - Polls HIRQ bit 10 (SCDQ) and acknowledges when set.
 * Retail version polls forever — a latent bug that hangs on real
 * hardware when CD timing is tight. This version adds a timeout.
 *
 * AJBats - Claude and I went back and forth on this one a ton. He
 * insists that this is a bug in Sega's code. Hard to argue since we
 * could never boot without it any time we changed code that shifted
 * function addresses. I still wonder if we never root caused this
 * properly but its enough of a fix to move on. I'm skeptical that
 * Sega had a link step that blew up their CD code unless they threaded
 * a timing bug perfectly, but I guess anything is possible.
 * Original address: 0x060423CC
 */

extern int sym_06035C4E(void);
extern void FUN_06035C54(int);

void cdb_wait_scdq(void)
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
    /* Timeout — force acknowledge so caller doesn't retry forever */
    FUN_06035C54((int)~0x0400);
}
