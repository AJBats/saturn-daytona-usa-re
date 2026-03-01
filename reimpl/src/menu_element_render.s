
    .section .text.FUN_0603F3F6


    .global menu_element_render
    .type menu_element_render, @function
menu_element_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov r5, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.w   .L_ring_buf_size, r11
    mov.l @r14, r0
    tst r0, r0
    bf/s    .L_source_valid
    mov r6, r13
    mov r13, r6
    mov #0x0, r5
    mov r10, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x04    /* mov.l .L_pool_memset, r3 */  ! r3 = &memset (sym_06036D78)
    jmp @r3
    mov.l @r15+, r14
    .2byte  0x043C
.L_ring_buf_size:
    .2byte  0x0800                      /* [HIGH] ring buffer size constant (2048 bytes) */
    .2byte  0xFFFF
    .4byte  sym_06036D94
    .4byte  sym_060A4D14
.L_pool_memset:
    .4byte  sym_06036D78
.L_source_valid:
    mov.l @(8, r14), r4
    mov r4, r0
    cmp/eq #-0x1, r0
    bt      .L_refill_buffer
    .byte   0x93, 0x3D    /* mov.w .L_ring_buf_size_ext, r3 */  ! r3 = 0x0800 (buf_size, from external pool)
    cmp/ge r3, r4
    bf      .L_cursor_valid
.L_refill_buffer:
    mov r11, r7
    mov.l @(4, r14), r6
    mov #0x1, r5
    .byte   0xD3, 0x1C    /* mov.l .L_fn_cmd_multi_validate, r3 */  ! r3 = &cmd_multi_validate
    jsr @r3
    mov.l @r14, r4
    mov #0x0, r2
    mov.l r2, @(8, r14)
.L_cursor_valid:
    mov.l @(8, r14), r9
    neg r9, r12
    add r11, r12
    cmp/hs r12, r13
    bt      .L_no_wrap
    bra     .L_clamp_to_request
    mov r13, r12
.L_no_wrap:
    mov r11, r12
    sub r9, r12
.L_clamp_to_request:
    mov r12, r6
    mov.l @(4, r14), r5
    .byte   0xD3, 0x15    /* mov.l .L_fn_memmove, r3 */  ! r3 = &memmove (sym_060360FC)
    add r9, r5
    jsr @r3
    mov r10, r4
    mov.l @(8, r14), r2
    add r12, r2
    cmp/hs r13, r12
    bt/s    .L_done
    mov.l r2, @(8, r14)
    sub r12, r13
    mov r11, r7
    mov #0x1, r5
    .byte   0xD3, 0x0E    /* mov.l .L_fn_cmd_multi_validate, r3 */  ! r3 = &cmd_multi_validate
    mov.l @(4, r14), r6
    jsr @r3
    mov.l @r14, r4
    mov r13, r6
    mov r12, r4
    .byte   0xD3, 0x0C    /* mov.l .L_fn_memmove, r3 */  ! r3 = &memmove (sym_060360FC)
    mov.l @(4, r14), r5
    jsr @r3
    add r10, r4
    mov.l r13, @(8, r14)
.L_done:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xE601
