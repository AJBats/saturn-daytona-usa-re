/* VERIFIED (2026-03-02): steering input dispatch during racing.
 * Writes LEFT/RIGHT button masks to sym_06063F48 and sym_06063F4A.
 * Downstream physics reads those to steer the car.
 * sym_06078663 swaps the assignment (player-side/viewport flag).
 * Also calls sym_0601A5F8 + sprite_pair_render (unverified, display-related).
 * Evidence: RE_TEST #3 swapped LEFT/RIGHT masks, confirmed inverted steering.
 */
	.text
    .global steering_input_dispatch
steering_input_dispatch:
    sts.l pr, @-r15
    mov.l   .L_pool_0600681C, r3
    jsr @r3
    nop
    extu.w r0, r5
    mov.l   .L_pool_06006820, r4
    mov.l   .L_pool_06006824, r3
    jsr @r3
    mov.b @r4, r4
    mov.l   .L_pool_06006828, r7
    mov.l   .L_pool_0600682C, r6
    mov.w   DAT_06006804, r5
    mov.l   .L_06006830, r4
    mov.l   .L_pool_06006834, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_060067F4
    extu.w r5, r5
    mov.w r5, @r6
    extu.w r4, r4
    bra     .L_060067FC
    mov.w r4, @r7
.L_060067F4:
    extu.w r4, r4
    mov.w r4, @r6
    extu.w r5, r5
    mov.w r5, @r7
.L_060067FC:
    lds.l @r15+, pr
    rts
    nop

    .global DAT_06006802
DAT_06006802:
    mov.l r9, @(36, r9)

    .global DAT_06006804
DAT_06006804:
    .short  0x4000
    .short  0xFFFF
    .long  fpmul
    .long  sym_06063F04
    .long  sym_06063F08
    .long  sym_06059F30
    .long  sym_06063E20
.L_pool_0600681C:
    .long  sym_0601A5F8
.L_pool_06006820:
    .long  sym_0605D240
.L_pool_06006824:
    .long  sprite_pair_render
.L_pool_06006828:
    .long  sym_06063F4A
.L_pool_0600682C:
    .long  sym_06063F48
.L_06006830:
    .long  0x00008000
.L_pool_06006834:
    .long  sym_06078663

    .global sym_06006838
sym_06006838:
    mov.l   .L_pool_06006860, r3
    mov.l   .L_pool_06006864, r2
    sub r5, r3
    add r2, r4
    mov r3, r5
    shlr16 r4
    shlr16 r5
    shlr2 r4
    shlr2 r5
    shlr2 r4
    shlr2 r5
    shlr r4
    shlr r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov r5, r0
    rts
    add r4, r0
    .short  0xFFFF
.L_pool_06006860:
    .long  0x03FFFFFF
.L_pool_06006864:
    .long  0x04000000
