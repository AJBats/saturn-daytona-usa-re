
    .section .text.FUN_06007CEC


    .global FUN_06007CEC
    .type FUN_06007CEC, @function
FUN_06007CEC:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    .byte   0xD8, 0x29    /* mov.l .L_fn_distorted_sprite_builder, r8 */
    .byte   0xD9, 0x2A    /* mov.l .L_ptr_sort_key_array, r9 */
    .byte   0xDA, 0x2A    /* mov.l .L_const_cmdpmod_hss, r10 */
    .byte   0xDD, 0x2B    /* mov.l .L_ptr_sprite_data_table, r13 */
    .byte   0xDE, 0x2B    /* mov.l .L_ptr_vdp1_write_cursor, r14 */
    .byte   0xD3, 0x2C    /* mov.l .L_fn_render_finalize, r3 */
    jsr @r3
    nop
    bra     .L_06007D6E
    mov #0x0, r11
.L_06007D10:
    mov r11, r0
    shll r0
    mov.w @(r0, r9), r12
    extu.w r12, r12
    extu.w r12, r0
    mov r0, r3
    shll2 r0
    shll2 r3
    shll r0
    shll2 r3
    add r3, r0
    extu.w r0, r0
    add r13, r0
    mov.w @(6, r0), r0
    extu.w r0, r0
    cmp/eq #0x9, r0
    bf      .L_06007D4E
    mov r10, r6
    extu.w r12, r4
    mov.l @r14, r5
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    extu.w r4, r4
    jsr @r8
    add r13, r4
    bra     .L_06007D66
    nop
.L_06007D4E:
    extu.w r12, r4
    mov.l @r14, r5
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    extu.w r4, r4
    .byte   0xD3, 0x16    /* mov.l .L_fn_normal_sprite_builder, r3 */
    jsr @r3
    add r13, r4
.L_06007D66:
    add #0x1, r11
    mov.l @r14, r2
    add #0x20, r2
    mov.l r2, @r14
.L_06007D6E:
    .byte   0xD3, 0x14    /* mov.l .L_ptr_sprite_count, r3 */
    mov.l @r3, r3
    cmp/hs r3, r11
    bf      .L_06007D10
    .byte   0xD3, 0x13    /* mov.l .L_const_vdp1_end_marker, r3 */
    .byte   0xD2, 0x13    /* mov.l .L_const_vdp1_cmd_table, r2 */
    mov.w r3, @r2
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06007D8E
    .type FUN_06007D8E, @function
FUN_06007D8E:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x1, r12
    mov.w   .L_wpool_06007D9E, r13
    mov.w   .L_wpool_06007DA0, r14
    bra     .L_06007DCE
    mov #0x0, r4
.L_wpool_06007D9E:
    .2byte  0xFE11
.L_wpool_06007DA0:
    .2byte  0x0080
    .2byte  0xFFFF
    .4byte  sym_060281B8
    .4byte  sym_0606A4F8
    .4byte  0x00008000
    .4byte  sym_0608AC20
    .4byte  sym_06078624
    .4byte  sym_0603C000
    .4byte  sym_060280F8
    .4byte  sym_06078620
    .4byte  0x0000FFFF
    .4byte  0x21800000
.L_06007DCC:
    mov r12, r4
.L_06007DCE:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_06007DCC
    mov.b @r13, r0
    and #0xF, r0
    mov.b r0, @r13
    mov.l   .L_pool_06007E02, r5
    tst r4, r4
    bt      .L_06007DEE
    mov.w @r5, r3
    add #-0xA, r3
    mov.w r3, @r5
    bra     .L_06007DF4
    nop
.L_06007DEE:
    mov.w @r5, r2
    add #0xA, r2
    mov.w r2, @r5
.L_06007DF4:
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_pool_06007E06, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06007E02:
    .4byte  sym_0605A1C0
.L_pool_06007E06:
    .4byte  sym_0603C000
