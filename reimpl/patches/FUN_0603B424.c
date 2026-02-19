/* FUN_0603B424 - CD command state machine (sector reading)
 *
 * PATCHED: Accept PAUSE status (1) in the Calculate path gate.
 *
 * Root cause of TABLE.BIN deadlock:
 *   The +4 byte shift makes the SCDQ poll take longer. During that
 *   extra time, the CD drive finishes reading all 14 TABLE.BIN sectors
 *   and enters "play end pause" — all sectors pre-buffered, drive in
 *   PAUSE state. The original code's PAUSE handler calls GetBufSize
 *   and only proceeds when retval == 1 (buffer empty). With 14 sectors
 *   buffered, retval != 1, so it falls to the default path. The default
 *   path requires status == 2 to enter Calculate, but PAUSE is status 1.
 *   Result: infinite retry loop, each iteration calling the SCDQ poll
 *   (which hangs on real hardware because SCDQ doesn't fire in PAUSE).
 *
 * Fix: In the default path, also allow status == 1 (PAUSE) to enter
 *   the Calculate sequence when FUN_0603BDAC indicates sectors are ready.
 *   This lets the state machine read pre-buffered sectors instead of
 *   waiting for a PLAY status that will never come.
 *
 * Side benefit: C code uses proper relocatable calls, fixing the
 *   non-relocatable JSR constant pool entries in the original ASM
 *   (Calculate Actual Size, Get Actual Size).
 */

/* --- External function declarations --- */

/* Issue CD command (Get Sector Number), return drive status byte */
extern int FUN_0603BD1C(void *ctx);

/* Default path: query sector readiness, return 5 if ready */
extern int FUN_0603BDAC(void *ctx);

/* State notification / finalization, returns int */
extern int FUN_0603B93C(int state);

/* Helper functions called during Calculate and cleanup */
extern void FUN_0603B9D6(void *ctx);
extern void FUN_0603B8B4(void *ctx);
extern void FUN_0603AFD0(void *ctx, int size_diff, int flag);

/* Calculate Actual Size / Get Actual Size (sub-label entry points) */
extern int sym_0603F9F2(int subchan);
extern int sym_0603F9F6(int subchan);

/* GetBufSize entry is at FUN_0603BF22 + 0x38 (no dedicated symbol) */
extern char FUN_0603BF22[];

/* --- Function pointer types for mid-function entries --- */

typedef int  (*intfn_ctx)(void *);
typedef void (*voidfn_ctx)(void *);

#define GetBufSize    ((intfn_ctx)((char *)FUN_0603BF22 + 0x38))
#define FUN_0603B8F8  ((voidfn_ctx)((char *)FUN_0603B8B4 + 0x40))

/* --- State machine implementation --- */

int FUN_0603B424(unsigned char *ctx)
{
    unsigned char state = ctx[0x12];
    int cd_status, saved_status;

    if (state == 0)
        goto exit_path;

    /* Issue Get Sector Number, get drive status */
    cd_status = FUN_0603BD1C(ctx);
    saved_status = cd_status;

    /* Dispatch on drive status */
    switch (cd_status) {
    case 6:  /* OPEN */
        ctx[0x12] = 0xFF;
        return FUN_0603B93C(-1);

    case 3:  /* PLAY */
        ctx[0x12] = 0xE9;
        return FUN_0603B93C(-23);

    case 4:  /* SEEK */
        ctx[0x12] = 0xFE;
        return FUN_0603B93C(-2);

    case 5:  /* SCAN */
        ctx[0x12] = 0xEC;
        return FUN_0603B93C(-20);

    case 1:  /* PAUSE */
    {
        int bufret = GetBufSize(ctx);
        if (bufret == 1) {
            /* Buffer empty — original behavior */
            ctx[0x12] = 0xE8;
            return FUN_0603B93C(-24);
        }
        /* FIX: Buffer has sectors (play end pause).
         * Fall to default path — the widened status check below
         * will allow Calculate to proceed for PAUSE status. */
        break;
    }

    case 0:  /* BUSY */
    {
        unsigned char sub_status = ctx[0x11];
        if (sub_status == 2) {
            /* STANDBY: reset and return */
            ctx[0x12] = 0;
            FUN_0603B9D6(ctx);
            FUN_0603B93C(0);
            return ctx[0x12];
        }
        break;
    }

    default:
        break;
    }

    /* Default path: check if sectors are ready for Calculate */
    {
        int bdac_ret = FUN_0603BDAC(ctx);

        /* FIX: Original condition was (saved_status == 2 && bdac_ret == 5).
         * Status 2 is the only status that fell through the dispatch table
         * in the original code. PAUSE (status 1) also falls through when
         * GetBufSize != 1, but was blocked by the status == 2 check.
         * Widen to accept PAUSE so pre-buffered sectors get read. */
        if ((saved_status == 2 || saved_status == 1) && bdac_ret == 5) {
            /* CALCULATE sequence: read buffered sectors */
            int subchan = *(int *)(ctx + 8);
            int calc_size = sym_0603F9F2(subchan);
            int actual_size = sym_0603F9F6(subchan);
            FUN_0603AFD0(ctx, calc_size - actual_size, 1);
            ctx[0x12] = 0;
            FUN_0603B8B4(ctx);
            FUN_0603B8F8(ctx);
            FUN_0603B9D6(ctx);
        }
    }

exit_path:
    FUN_0603B93C(0);
    return ctx[0x12];
}
