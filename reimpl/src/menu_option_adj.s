
    .section .text.FUN_0603B324


    .global menu_option_adj
    .type menu_option_adj, @function
menu_option_adj:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r5, @r15
    mov.b @(r0, r14), r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_not_busy
    mov #-0x10, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    .byte   0xA2, 0xFF    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-0x10)
    mov.l @r15+, r14
.L_not_busy:
    .byte   0xB3, 0x31    /* bsr 0x0603B9A4 (external) */  ! call save_data_validate(r4=descriptor)
    mov r14, r4
    mov #0x2, r2
    mov #0x11, r0
    mov #0x1, r3
    mov.b r2, @(r0, r14)
    mov #0x12, r0
    mov.b r3, @(r0, r14)
    mov.l @r14, r3
    mov.l @(16, r3), r8
    .byte   0xBE, 0x81    /* bsr 0x0603B058 (external) */  ! call menu_element_dispatch(r4=descriptor)
    mov r14, r4
    mov r8, r4
    mov.l @r15, r3
    sub r0, r4
    cmp/ge r4, r3
    bt      .L_use_max_pos
    bra     .L_pos_clamped
    mov.l @r15, r5
.L_use_max_pos:
    mov r4, r5
.L_pos_clamped:
    .byte   0xB5, 0x89    /* bsr 0x0603BE7C (external) */  ! call apply_scroll_offset(r4=data_block, r5=clamped_pos)
    mov.l @r14, r4
    mov #0x0, r5
    .byte   0xD3, 0x10    /* mov.l .L_pool_0603B3B0, r3 */  ! r3 = &timer_block_init_fields
    jsr @r3
    mov.l @(8, r14), r4
    mov #0x1, r7
    mov #0x0, r6
    .byte   0xD3, 0x0F    /* mov.l .L_pool_0603B3B4, r3 */  ! r3 = &color_transform_set_params
    mov r6, r5
    jsr @r3
    mov.l @(4, r14), r4
    mov #-0x1, r5
    .byte   0xD3, 0x0D    /* mov.l .L_pool_0603B3B8, r3 */  ! r3 = &timer_set_active_flag
    jsr @r3
    mov.l @(8, r14), r4
    mov #0x0, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    .byte   0xA2, 0xD5    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=0)
    mov.l @r15+, r14
