/* Stubs for FUN_0602D8C6 unit test.
 *
 * FUN_06027344 (sin) and FUN_06027348 (cos) are called with angle in r4.
 * Both builds (vanilla + decomp) call these same stubs, so the return
 * values just need to be deterministic — not accurate.
 *
 * We use simple identity-like functions: sin returns r4, cos returns r4>>1.
 * This gives different but predictable values for different angles,
 * exercising the multiply paths without needing a real trig table.
 */

    .section .text.stubs
    .align 2

    /* sin stub: return the input angle directly */
    .global FUN_06027344
FUN_06027344:
    rts
    mov r4, r0

    /* cos stub: return input >> 1 (different from sin) */
    .global FUN_06027348
FUN_06027348:
    shar r4
    rts
    mov r4, r0
