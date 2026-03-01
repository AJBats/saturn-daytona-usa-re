
    .section .text.FUN_0601D3C0


    .global render_setup_dispatch
    .type render_setup_dispatch, @function
render_setup_dispatch:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0601D448, r14
    mov.l   .L_pool_0601D44C, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601D430
    mov.l   .L_pool_0601D450, r3
    mov.w @r3, r2
    mov.w   DAT_0601d444, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601D430
    mov.l   .L_pool_0601D454, r3
    mov.w @r3, r2
    mov.l   .L_pool_0601D458, r3
    extu.w r2, r2
    cmp/eq r3, r2
    bf      .L_0601D3EE
    mov.b @r14, r0
    or #0x7, r0
    mov.b r0, @r14
.L_0601D3EE:
    mov.l   .L_pool_0601D454, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   DAT_0601d446, r3
    cmp/eq r3, r2
    bf      .L_0601D408
    mov.b @r14, r0
    or #0x7, r0
    mov.b r0, @r14
    mov.l   .L_pool_0601D45C, r4
    mov.b @r4, r0
    or #0x7, r0
    mov.b r0, @r4
.L_0601D408:
    mov #0x0, r6
    mov.l   .L_pool_0601D460, r3
    mov r6, r5
    jsr @r3
    mov #0x20, r4
    mov #0x0, r7
    mov.l   .L_pool_0601D464, r5
    mov.l   .L_pool_0601D468, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r4
    mov #0xC, r2
    mov.l   .L_pool_0601D46C, r3
    mov.l r2, @r3
    mov #0x4, r2
    mov.l   .L_pool_0601D470, r3
    mov.b r2, @r3
    mov #0x1, r2
    mov.l   .L_pool_0601D44C, r3
    mov.l r2, @r3
.L_0601D430:
    mov.l   .L_pool_0601D470, r2
    mov.b @r2, r2
    extu.b r2, r2
    shll2 r2
    mov.l   .L_pool_0601D474, r3
    add r3, r2
    mov.l @r2, r2
    lds.l @r15+, pr
    jmp @r2
    mov.l @r15+, r14

    .global DAT_0601d444
DAT_0601d444:
    .2byte  0x0800

    .global DAT_0601d446
DAT_0601d446:
    .2byte  0x5D50
.L_pool_0601D448:
    .4byte  sym_0605AB16
.L_pool_0601D44C:
    .4byte  sym_06086024
.L_pool_0601D450:
    .4byte  sym_06063D9A
.L_pool_0601D454:
    .4byte  g_pad_state
.L_pool_0601D458:
    .4byte  0x0000AAA8
.L_pool_0601D45C:
    .4byte  sym_0605AB17
.L_pool_0601D460:
    .4byte  display_channel_b
.L_pool_0601D464:
    .4byte  sym_06094FA8
.L_pool_0601D468:
    .4byte  sym_06028400
.L_pool_0601D46C:
    .4byte  sym_0607EBCC
.L_pool_0601D470:
    .4byte  sym_0607887F
.L_pool_0601D474:
    .4byte  sym_0605DF80
