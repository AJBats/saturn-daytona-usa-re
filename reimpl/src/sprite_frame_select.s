
    .section .text.FUN_0600553C


    .global sprite_frame_select
    .type sprite_frame_select, @function
sprite_frame_select:
    mov.l r14, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.b @r4, r14
    tst r5, r5
    bf/s    .L_0600554E
    mov #0x1, r4
    bra     .L_06005558
    nop
.L_0600554E:
    exts.b r14, r2
    mov.b @r5, r3
    cmp/eq r3, r2
    bf      .L_06005558
    mov #0x0, r4
.L_06005558:
    exts.b r4, r4
    tst r4, r4
    bt      .L_06005598
    mov.l   .L_pool_060055A4, r3
    jsr @r3
    nop
    exts.b r14, r0
    cmp/eq #-0x1, r0
    bt      .L_06005598
    exts.b r14, r14
    mov.w   .L_wpool_060055A0, r2
    mov.l   .L_pool_060055A8, r3
    mul.l r2, r14
    sts macl, r14
    add r3, r14
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_pool_060055AC, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l   .L_pool_060055B0, r3
    jsr @r3
    mov.l @(32, r14), r4
    mov.l   .L_pool_060055B4, r3
    jsr @r3
    mov.l @(28, r14), r4
    mov.l @(36, r14), r4
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l   .L_pool_060055B8, r3
    jmp @r3
    mov.l @r15+, r14
.L_06005598:
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_060055A0:
    .2byte  0x0268
    .2byte  0xFFFF
.L_pool_060055A4:
    .4byte  sym_06026E0C
.L_pool_060055A8:
    .4byte  sym_06078900
.L_pool_060055AC:
    .4byte  sym_06026E2E
.L_pool_060055B0:
    .4byte  mat_rot_y
.L_pool_060055B4:
    .4byte  mat_rot_x
.L_pool_060055B8:
    .4byte  mat_rot_z
