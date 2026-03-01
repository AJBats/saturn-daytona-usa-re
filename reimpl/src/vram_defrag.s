
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
    bra     .L_loop_test
    add r3, r14
.L_process_entry:
    mov.w @(2, r14), r0
    mov r0, r3
    cmp/pz r3
    bt      .L_alloc_path
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
    bra     .L_loop_done
    nop
.L_alloc_path:
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
.L_loop_test:
    mov.w @r11, r2
    mov.w @r14, r3
    extu.w r2, r2
    extu.w r3, r3
    cmp/gt r3, r2
    bt      .L_process_entry
.L_loop_done:
    mov.l   .L_pool_0602008C, r0
    mov.l @r0, r0
    cmp/eq #0x17, r0
    bf      .L_skip_pool_alloc
    .byte   0xB0, 0xB7    /* bsr 0x060201B8 (obj_pool_alloc */
    nop
.L_skip_pool_alloc:
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
    .2byte  0x0268                          /* car struct size: 616 bytes */
.L_wpool_06020066:
    .2byte  0x035A                          /* fpmul arg: fractional multiplier */
.L_wpool_06020068:
    .2byte  0x0194                          /* car struct field offset: fpmul result dest */
.L_wpool_0602006A:
    .2byte  0x01F8                          /* car struct field offset: size attribute */
.L_pool_0602006C:
    .4byte  sym_06087802                    /* iteration counter (16-bit) */
.L_pool_06020070:
    .4byte  sym_06087800                    /* entry count (16-bit) */
.L_pool_06020074:
    .4byte  sym_060877FC                    /* VRAM block pointer (indirect) */
.L_pool_06020078:
    .4byte  sym_060877F8                    /* VRAM pointer lookup table base */
.L_pool_0602007C:
    .4byte  sym_060877F4                    /* resolved VRAM destination address */
.L_pool_06020080:
    .4byte  sym_06087804                    /* handler mode / display timer (16-bit) */
.L_pool_06020084:
    .4byte  sym_06078900                    /* car struct array base */
.L_pool_06020088:
    .4byte  fpmul                           /* fixed-point multiply routine */
.L_pool_0602008C:
    .4byte  g_game_state                    /* game state dispatch value */

    .global loc_06020090
loc_06020090:
    mov.l   .L_pool_060200A0, r0
    mov.l @r0, r0
    cmp/eq #0x17, r0
    bf      .L_state_check_exit
    .byte   0xA0, 0x8E    /* bra 0x060201B8 (obj_pool_alloc */
    nop
.L_state_check_exit:
    rts
    nop
.L_pool_060200A0:
    .4byte  g_game_state                    /* game state dispatch value */
