
    .section .text.FUN_0601FFB8


    .global vram_defrag
    .type vram_defrag, @function
vram_defrag:
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.w   .L_wpool_06020064, r8
    mov.l   .L_pool_0602006C, r11
    mov.l   .L_pool_06020070, r12
    mov r8, r10
    mov.w @r12, r14
    add #-0x68, r10
    extu.w r14, r14
    shll2 r14
    shll r14
    mov.l   .L_pool_06020074, r3
    mov.l @r3, r3
    bra     .L_06020032
    add r3, r14
.L_0601FFD6:
    mov.w @(2, r14), r0
    mov r0, r3
    cmp/pz r3
    bt      .L_0601FFFC
    mov.w @(4, r14), r0
    mov r0, r2
    extu.w r2, r2
    shll2 r2
    mov.l   .L_pool_06020078, r3
    mov.l @r3, r3
    add r3, r2
    mov.l @r2, r1
    mov.l   .L_pool_0602007C, r0
    mov.l r1, @r0
    extu.w r9, r2
    mov.l   .L_pool_06020080, r1
    mov.w r2, @r1
    bra     .L_0602003E
    nop
.L_0601FFFC:
    mov.w @(2, r14), r0
    mov.l   .L_pool_06020084, r3
    mov.w   .L_wpool_06020066, r4
    mov r0, r13
    mul.l r8, r13
    mov.w @(4, r14), r0
    sts macl, r13
    mov r0, r5
    add r3, r13
    extu.w r5, r5
    mov.l   .L_pool_06020088, r3
    jsr @r3
    shll16 r5
    mov.w   .L_wpool_06020068, r1
    add r13, r1
    mov.l r0, @r1
    mov.w @(6, r14), r0
    mov r0, r3
    extu.w r3, r3
    mov.w   .L_wpool_0602006A, r0
    mov.l r3, @(r0, r13)
    add #0xC, r0
    mov.l r10, @(r0, r13)
    mov.w @r12, r3
    add #0x1, r3
    mov.w r3, @r12
    add #0x8, r14
.L_06020032:
    mov.w @r11, r2
    mov.w @r14, r3
    extu.w r2, r2
    extu.w r3, r3
    cmp/gt r3, r2
    bt      .L_0601FFD6
.L_0602003E:
    mov.l   .L_pool_0602008C, r0
    mov.l @r0, r0
    cmp/eq #0x17, r0
    bf      .L_0602004A
    .byte   0xB0, 0xB7    /* bsr 0x060201B8 (obj_pool_alloc */
    nop
.L_0602004A:
    mov.w @r11, r2
    add #0x1, r2
    mov.w r2, @r11
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_06020064:
    .2byte  0x0268
.L_wpool_06020066:
    .2byte  0x035A
.L_wpool_06020068:
    .2byte  0x0194
.L_wpool_0602006A:
    .2byte  0x01F8
.L_pool_0602006C:
    .4byte  sym_06087802
.L_pool_06020070:
    .4byte  sym_06087800
.L_pool_06020074:
    .4byte  sym_060877FC
.L_pool_06020078:
    .4byte  sym_060877F8
.L_pool_0602007C:
    .4byte  sym_060877F4
.L_pool_06020080:
    .4byte  sym_06087804
.L_pool_06020084:
    .4byte  sym_06078900
.L_pool_06020088:
    .4byte  fpmul
.L_pool_0602008C:
    .4byte  g_game_state

    .global loc_06020090
loc_06020090:
    mov.l   .L_pool_060200A0, r0
    mov.l @r0, r0
    cmp/eq #0x17, r0
    bf      .L_0602009C
    .byte   0xA0, 0x8E    /* bra 0x060201B8 (obj_pool_alloc */
    nop
.L_0602009C:
    rts
    nop
.L_pool_060200A0:
    .4byte  g_game_state
