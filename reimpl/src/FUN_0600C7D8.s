
    .section .text.FUN_0600C7D8


    /* THEORY: heading_and_position_update — smooths car[+0x20] toward
       target heading car[+0x28] (speed-dependent rate: >>3 above 0x118,
       >>2 above 0xFA, >>1 above 0xDC). Then integrates position:
       car[+0x10] += FUN_06027552(car[+0x0c], sin(heading)),
       car[+0x18] += FUN_06027552(car[+0x0c], cos(heading)).
       Also saves old position to car[+0x38]/[+0x3c], writes car[+0x30],
       car[+0x1c], car[+0x24], car[+0x1B0], car[+0x18C]/[+0x190].
       Reads car[+0x0c] (speed) but does NOT write it.
       Evidence: NOP'd BSR→FUN_0600C7D4 at 0x0600c71e in FUN_0600C5D6.
       Cars 1,3 held starting speed (car[1]: +723, car[3]: +371 vs
       baseline -6599, -7682). Effect is INDIRECT: position stops
       updating, so track-driven speed changes don't occur.
       Confirmed read/write set via ghidra_reference/FUN_0600C7D8.c. */
    .global FUN_0600C7D8
    .type FUN_0600C7D8, @function
FUN_0600C7D8:
    sts.l pr, @-r15

    mov.l @(32, r14), r3
    mov.w   DAT_0600c8b6, r0
    mov.l r3, @(r0, r14)

    mov.l @(40, r14), r4
    mov.l @(32, r14), r3
    mov.l @(8, r14), r2
    extu.w r4, r4
    neg r3, r3
    extu.w r3, r3
    add r3, r4

    mov.w   .L_wpool_0600C8B8, r3
    cmp/gt r3, r2
    bf/s    .L_0600C7FE
    exts.w r4, r4
    shar r4
    shar r4
    bra     .L_0600C816
    shar r4

.L_0600C7FE:
    mov.l @(8, r14), r2
    mov.w   .L_wpool_0600C8BA, r3
    cmp/gt r3, r2
    bf      .L_0600C80C
    shar r4
    bra     .L_0600C816
    shar r4

.L_0600C80C:
    mov.l @(8, r14), r2
    mov.w   DAT_0600c8bc, r3
    cmp/gt r3, r2
    bf      .L_0600C816
    shar r4

.L_0600C816:
    extu.w r4, r4
    mov.l @(32, r14), r3
    extu.w r3, r3
    add r4, r3
    exts.w r3, r3
    mov.l r3, @(32, r14)

    mov r3, r2
    mov.w   DAT_0600c8be, r0
    extu.w r2, r2
    mov.l @(r0, r14), r3
    neg r3, r3
    mov.w @(18, r5), r0
    extu.w r3, r3
    add r3, r2
    mov r0, r3
    neg r3, r3
    extu.w r3, r3
    add r3, r2
    exts.w r2, r2
    mov.l r2, @(48, r14)

    mov.w @(12, r5), r0
    mov.l @(28, r14), r2
    mov r0, r3
    extu.w r2, r2
    extu.w r3, r3
    add r2, r3
    exts.w r3, r3
    shar r3
    mov.l r3, @(28, r14)

    mov.w @(16, r5), r0
    mov.l @(36, r14), r2
    mov r0, r3
    extu.w r2, r2
    extu.w r3, r3
    add r2, r3
    exts.w r3, r3
    shar r3
    mov.l r3, @(36, r14)

    mov.l @(16, r14), r3
    mov.l r3, @(56, r14)
    mov.l @(24, r14), r2
    mov.l r2, @(60, r14)

    mov.l @(32, r14), r3
    mov.w @(18, r5), r0
    extu.w r3, r3
    mov r0, r2
    neg r2, r2
    shar r2
    shar r2
    extu.w r2, r2
    add r2, r3
    exts.w r3, r3
    mov.l r3, @(32, r14)

    mov.w   DAT_0600c8c0, r6
    mov.w   DAT_0600c8c2, r5
    mov.l @(40, r14), r4
    mov.l   .L_0600C8C4, r3
    add r14, r6
    add r14, r5
    jsr @r3
    neg r4, r4

    mov.w   DAT_0600c8c2, r0
    mov.l   .L_0600C8C8, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov.l @(12, r14), r4

    mov.l @(16, r14), r2
    add r0, r2
    mov.l r2, @(16, r14)

    mov.w   DAT_0600c8c0, r0
    mov.l   .L_0600C8C8, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov.l @(12, r14), r4

    mov.l @(24, r14), r2
    add r0, r2
    mov.l r2, @(24, r14)

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600c8b6
DAT_0600c8b6:
    .2byte  0x01B0
.L_wpool_0600C8B8:
    .2byte  0x0118
.L_wpool_0600C8BA:
    .2byte  0x00FA

    .global DAT_0600c8bc
DAT_0600c8bc:
    .2byte  0x00DC

    .global DAT_0600c8be
DAT_0600c8be:
    .2byte  0x01D8

    .global DAT_0600c8c0
DAT_0600c8c0:
    .2byte  0x0190

    .global DAT_0600c8c2
DAT_0600c8c2:
    .2byte  0x018C
.L_0600C8C4:
    .4byte  FUN_06027358
.L_0600C8C8:
    .4byte  FUN_06027552
