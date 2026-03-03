	.text
    .global disp_digit_pair_render
disp_digit_pair_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD1, 0x0C    /* mov.l .L_pool_060325EC, r1 */
    .byte   0xD0, 0x0C    /* mov.l .L_pool_060325F0, r0 */
    mov.b @(r0, r14), r0
    .byte   0xD2, 0x0C    /* mov.l .L_pool_060325F4, r2 */
    tst r2, r0
    bf      .L_060325F8
    .byte   0xD0, 0x0C    /* mov.l .L_pool_060325F8, r0 */
    bra     .L_060325FA
    add r0, r1
    .long  sym_06026DBC
    .long  sym_06089EDC
    .long  0x00000000
    .long  0x00000004
    .long  0x00000008
    .long  sym_06026E2E
    .long  0x0000000C
    .long  mat_rot_y
.L_pool_060325EC:
    .long  0x00000054
.L_pool_060325F0:
    .long  0x000002DC
.L_pool_060325F4:
    .long  0xFFFFFFFC
.L_pool_060325F8:
    .long  sym_06081898
.L_060325F8:
    add r14, r1
.L_060325FA:
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032668, r0 */
    mov.l r1, @(r0, r14)
    .byte   0xD7, 0x1B    /* mov.l .L_pool_0603266C, r7 */
    mov.l r7, @-r15
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032670, r0 */
