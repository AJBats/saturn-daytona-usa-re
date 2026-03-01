
    .section .text.FUN_0601A80C


    .global course_data_rom_load
    .type course_data_rom_load, @function
course_data_rom_load:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0601A874, r13
    mov.l   .L_pool_0601A878, r14
    mov.l   .L_pool_0601A87C, r6
    mov.l   .L_pool_0601A880, r4
    mov.w @(2, r13), r0
    mov r0, r3
    extu.w r3, r3
    and r6, r3
    tst r3, r3
    bt/s    .L_0601A83A
    mov #0x0, r12
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_0601A89E
    mov.b r2, @r4
.L_0601A83A:
    mov.w   DAT_0601a872, r5
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r5, r2
    tst r2, r2
    bt      .L_0601A854
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_0601A89E
    mov.b r2, @r4
.L_0601A854:
    mov.w @r13, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_0601A884
    mov.b @r4, r0
    cmp/eq #0x14, r0
    bf      .L_0601A89E
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    exts.b r12, r3
    mov.b r3, @r4
    bra     .L_0601A89E
    nop

    .global DAT_0601a872
DAT_0601a872:
    .2byte  0x4000
.L_pool_0601A874:
    .4byte  g_pad_state
.L_pool_0601A878:
    .4byte  sym_0605D248
.L_pool_0601A87C:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_0601A880:
    .4byte  sym_0605D243
.L_0601A884:
    mov.w @r13, r2
    extu.w r2, r2
    and r5, r2
    tst r2, r2
    bt      .L_0601A89E
    mov.b @r4, r0
    cmp/eq #0x14, r0
    bf      .L_0601A89E
    mov.l @r14, r2
    add #-0x1, r2
    mov.l r2, @r14
    exts.b r12, r3
    mov.b r3, @r4
.L_0601A89E:
    mov.w @(2, r13), r0
    extu.w r0, r0
    tst #0xF8, r0
    bt      .L_0601A8A8
    mov.l r12, @r14
.L_0601A8A8:
    mov.l @r14, r3
    mov #0x15, r2
    cmp/ge r2, r3
    bf      .L_0601A8B2
    mov.l r12, @r14
.L_0601A8B2:
    mov.l @r14, r2
    cmp/pz r2
    bt      .L_0601A8BC
    mov #0x14, r2
    mov.l r2, @r14
.L_0601A8BC:
    mov.w @(2, r13), r0
    mov.w   DAT_0601a926, r2
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0601A8D8
    mov #0x0, r6
    mov.l @r14, r5
    add #0x2, r5
    mov.l r5, @r15
    mov.l   .L_pool_0601A92C, r3
    jsr @r3
    mov r5, r4
.L_0601A8D8:
    mov.l   .L_pool_0601A930, r11
    mov #0x0, r6
    mov.w   DAT_0601a928, r5
    mov.l   .L_pool_0601A934, r7
    jsr @r11
    mov #0xC, r4
    mov.l   .L_pool_0601A934, r7
    mov #0x0, r6
    mov.w   DAT_0601a92a, r5
    jsr @r11
    mov #0xC, r4
    mov.l @r14, r7
    mov.l   .L_pool_0601A938, r3
    mov.l   .L_pool_0601A93C, r6
    mov.w   DAT_0601a928, r5
    shll r7
    shll2 r7
    add r3, r7
    mov.l @r7, r7
    jsr @r11
    mov #0xC, r4
    mov.l @r14, r7
    mov.l   .L_pool_0601A938, r3
    mov.l   .L_pool_0601A93C, r6
    mov.w   DAT_0601a92a, r5
    shll r7
    add #0x1, r7
    shll2 r7
    add r3, r7
    mov.l @r7, r7
    jsr @r11
    mov #0xC, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601a926
DAT_0601a926:
    .2byte  0x0600

    .global DAT_0601a928
DAT_0601a928:
    .2byte  0x079C

    .global DAT_0601a92a
DAT_0601a92a:
    .2byte  0x081C
.L_pool_0601A92C:
    .4byte  handler_dispatch
.L_pool_0601A930:
    .4byte  sym_060283E0
.L_pool_0601A934:
    .4byte  sym_06049CDC
.L_pool_0601A938:
    .4byte  sym_0605D2B4
.L_pool_0601A93C:
    .4byte  0x0000E000                  /* bits 15:13 mask */
