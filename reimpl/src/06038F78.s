
    .section .text.FUN_06038F78


    .global vblank_display_write
    .type vblank_display_write, @function
vblank_display_write:
    sts.l pr, @-r15
    mov.l   .L_06038FE0, r11
    mov.l   .L_06038FE4, r12
    mov.l   .L_06038FE8, r13
    mov.l   .L_06038FEC, r14
    mov.l r10, @r12
    mov.l   .L_06038FF0, r4
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_06038FA0
    mov.l @r13, r0
    tst r0, r0
    bt      .L_06039042
    jsr @r11
    nop
    mov #0x2, r3
    mov.l r3, @r12
    bra     .L_06039042
    nop
.L_06038FA0:
    mov.l   .L_06038FF4, r6
    mov.l   .L_06038FF8, r5
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x3, r0
    bf      .L_06038FD0
    mov.l @r13, r0
    tst r0, r0
    bt      .L_06039042
    mov.l   .L_06038FFC, r0
    mov.l   .L_06039000, r3
    mov.w @r0, r0
    extu.w r0, r0
    or #0x8, r0
    mov.w r0, @r3
    mov.w @r6, r0
    extu.w r0, r0
    or #0x3, r0
    jsr @r11
    mov.w r0, @r5
    mov #0x3, r3
    mov.l r3, @r12
    bra     .L_06039042
    nop
.L_06038FD0:
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_06039004
    jsr @r11
    nop
    bra     .L_06039042
    mov.l r10, @r13
.L_06038FE0:
    .4byte  scene_data_dispatch
.L_06038FE4:
    .4byte  sym_060A4C84
.L_06038FE8:
    .4byte  sym_060635C4
.L_06038FEC:
    .4byte  sym_060635C0
.L_06038FF0:
    .4byte  sym_060635B4
.L_06038FF4:
    .4byte  sym_060A4C92
.L_06038FF8:
    .4byte  0x25D00002
.L_06038FFC:
    .4byte  sym_060A4C90
.L_06039000:
    .4byte  0x25D00000
.L_06039004:
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    .byte   0xD0, 0x1F    /* mov.l .L_pool_06039088, r0 */
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_06039028
    .byte   0xD2, 0x1E    /* mov.l .L_pool_0603908C, r2 */
    mov.l @r14, r3
    mov.l @r2, r2
    add #-0x1, r2
    cmp/gt r3, r2
    bt      .L_06039028
    mov.w @r6, r0
    extu.w r0, r0
    or #0x2, r0
    extu.w r0, r0
    mov.w r0, @r5
.L_06039028:
    .byte   0xD3, 0x18    /* mov.l .L_pool_0603908C, r3 */
    mov.l @r14, r2
    mov.l @r3, r3
    cmp/gt r2, r3
    bt      .L_06039042
    mov.l @r13, r0
    tst r0, r0
    bt      .L_06039040
    jsr @r11
    nop
    mov #0x1, r3
    mov.l r3, @r12
.L_06039040:
    mov.l r10, @r14
.L_06039042:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
