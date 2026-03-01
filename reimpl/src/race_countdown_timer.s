/* VERIFIED: called exclusively when C is pressed on Circuit Select screen
 * Method: call-trace differential — 10 frames idle vs 10 frames with C on circuit select
 *   9 calls during C press, 0 calls during idle baseline [NEW — only during C]
 *   Not called at all during idle frames, confirming activation on circuit confirm.
 * Date: 2026-02-28
 */

    .section .text.FUN_0600F870


    .global race_countdown_timer
    .type race_countdown_timer, @function
race_countdown_timer:
    sts.l pr, @-r15
    .byte   0xD3, 0x19    /* mov.l .L_pool_0600F8D8, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x18    /* mov.l .L_pool_0600F8DC, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x18    /* mov.l .L_pool_0600F8E0, r4 */
    mov.w @r4, r2
    add #-0x1, r2
    mov.w r2, @r4
    exts.w r2, r2
    cmp/pl r2
    bt      .L_0600F892
    mov #0x4, r2
    .byte   0xD3, 0x15    /* mov.l .L_pool_0600F8E4, r3 */
    mov.b r2, @r3
.L_0600F892:
    lds.l @r15+, pr
    rts
    nop
