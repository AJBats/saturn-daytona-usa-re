
    .section .text.FUN_0603ACEA


    .global menu_input_proc
    .type menu_input_proc, @function
menu_input_proc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.w   .L_wpool_0603AD2E, r0
    add r0, r15
    mov r5, r0
    mov.l r5, @r15
    .byte   0xDD, 0x0F    /* mov.l .L_pool_0603AD3A, r13 */
    tst r0, r0
    bf/s    .L_active_input_path
    mov r4, r12

    mov.l @r13, r3
    mov.w   .L_wpool_0603AD30, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_attract_flag_clear
    .byte   0xB6, 0x16    /* bsr 0x0603B93C (external) */
    mov #-0x7, r4
    bra     .L_return
    nop
.L_attract_flag_clear:
    .byte   0xD3, 0x09    /* mov.l .L_pool_0603AD3E, r3 */
    jsr @r3
    mov r12, r4
    mov r0, r4
    cmp/pz r4
    bt      .L_return_result
    .byte   0xB6, 0x0C    /* bsr 0x0603B93C (external) */
    mov #-0x1, r4
    bra     .L_return
    nop
.L_return_result:
    bra     .L_return
    mov r4, r0
.L_wpool_0603AD2E:
    .2byte  0xFF0C
.L_wpool_0603AD30:
    .2byte  0x00A0
    .4byte  hud_toggle_ctrl
    .4byte  save_size_calc
.L_pool_0603AD3A:
    .4byte  sym_060A4D14
.L_pool_0603AD3E:
    .4byte  credits_scroll_entry

.L_active_input_path:
    mov.l @r13, r2
    .byte   0x90, 0x4A    /* mov.w .L_wpool_0603ADDA, r0 */
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_flag_nonzero
    mov.l @r13, r5
    .byte   0x90, 0x46    /* mov.w .L_wpool_0603ADDC, r0 */
    .byte   0xD3, 0x24    /* mov.l .L_pool_0603ADE0, r3 */
    mov.l @(r0, r5), r5
    jsr @r3
    mov r12, r4
    bra     .L_dispatch_done
    nop
.L_flag_nonzero:
    mov.l @r13, r5
    .byte   0x90, 0x3E    /* mov.w .L_wpool_0603ADDC, r0 */
    .byte   0xD3, 0x21    /* mov.l .L_pool_0603ADE4, r3 */
    mov.l @(r0, r5), r5
    jsr @r3
    mov r12, r4
.L_dispatch_done:
    mov r0, r14
    mov.b @(11, r14), r0
    extu.b r0, r0
    tst #0x10, r0
    bt      .L_no_input_flag
    bra     .L_process_input
    nop
.L_no_input_flag:
    .byte   0xB5, 0xE2    /* bsr 0x0603B93C (external) */
    mov #-0x6, r4
    bra     .L_return
    nop
.L_process_input:
    mov r12, r6
    mov r14, r5
    mov r15, r4
    .byte   0xB6, 0x53    /* bsr 0x0603BA2C (external) */
    add #0x4, r4
    mov r0, r13
    mov.l @(4, r14), r6
    mov.l @r15, r5
    .byte   0xD3, 0x16    /* mov.l .L_pool_0603ADE8, r3 */
    jsr @r3
    mov r13, r4
    mov.l r0, @r15
    .byte   0xB6, 0x1F    /* bsr 0x0603B9D6 (external) */
    mov r13, r4
    .byte   0xB5, 0xD0    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov.l @r15, r0

.L_return:
    .byte   0x91, 0x1E    /* mov.w .L_wpool_0603ADDE, r1 */
    add r1, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
