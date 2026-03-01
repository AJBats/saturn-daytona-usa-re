
    .section .text.FUN_0603AC1C


    .global cmd_validate_exec
    .type cmd_validate_exec, @function
cmd_validate_exec:
    mov.l r14, @-r15
    mov #0x1, r3
    mov.l r13, @-r15
    sts.l pr, @-r15
    cmp/ge r3, r4
    bf/s    .L_cmd_id_out_of_range
    mov r6, r14
    mov #0x18, r3
    cmp/gt r3, r4
    bf      .L_validate_alignment
.L_cmd_id_out_of_range:
    bra     .L_return
    mov #-0x5, r0
.L_validate_alignment:
    mov #0x3, r3
    and r5, r3
    tst r3, r3
    bt      .L_check_params
    bra     .L_return
    mov #-0x15, r0
.L_check_params:
    tst r14, r14
    bt      .L_store_buffer
    mov.l @r14, r6
    tst r6, r6
    bt      .L_check_count
    mov r6, r0
    cmp/eq #0x1, r0
    bf      .L_invalid_params
.L_check_count:
    mov.l @(4, r14), r2
    mov #0x2, r3
    cmp/ge r3, r2
    bf      .L_invalid_params
    mov.l @(8, r14), r0
    tst r0, r0
    bf      .L_store_buffer
.L_invalid_params:
    bra     .L_return
    mov #-0x4, r0
.L_store_buffer:
    mov.l   .L_pool_0603ACA0, r3
    mov.l r5, @r3
    .byte   0xB5, 0x71    /* bsr 0x0603B74C (external) */  ! call sys_boot_table_init(r4=cmd_id)
    nop
    tst r14, r14
    bf      .L_has_params
    bra     .L_call_error_check
    mov #0x1, r4
.L_has_params:
    mov #0x0, r4
.L_call_error_check:
    mov.l   .L_pool_0603ACA4, r3
    jsr @r3
    nop
    mov r0, r4
    tst r4, r4
    bt      .L_check_status_bit
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xA6, 0x5A    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=error)
    mov.l @r15+, r14
.L_check_status_bit:
    mov.l   .L_pool_0603ACA0, r0
    mov.w   DAT_0603ac9e, r1
    mov.l @r0, r0
    mov.l @(r0, r1), r0
    tst #0x1, r0
    bf      .L_dispatch_command
    mov #-0x2, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xA6, 0x4F    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-2)
    mov.l @r15+, r14

    .global DAT_0603ac9e
DAT_0603ac9e:
    .2byte  0x00C4
.L_pool_0603ACA0:
    .4byte  sym_060A4D14
.L_pool_0603ACA4:
    .4byte  error_code_stub
.L_dispatch_command:
    tst r14, r14
    bf      .L_dispatch_with_params
    .byte   0xD3, 0x20    /* mov.l .L_pool_0603AD30, r3 */ ! r3 = &hud_toggle_ctrl (cross-TU pool)
    jsr @r3
    nop
    mov r0, r13
    cmp/pz r13
    bt      .L_finalize
    mov #-0x7, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xA6, 0x3D    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-7)
    mov.l @r15+, r14
.L_dispatch_with_params:
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0603AD34, r3 */ ! r3 = &save_size_calc (cross-TU pool)
    jsr @r3
    mov r14, r4
    mov r0, r13
    cmp/pl r13
    bt      .L_finalize
    mov #-0x1, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xA6, 0x32    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-1)
    mov.l @r15+, r14
.L_finalize:
    .byte   0xB0, 0x68    /* bsr 0x0603ADAC (external) */  ! call cmd_dispatch_helper(r4=params)
    mov r14, r4
    .byte   0xB6, 0x2E    /* bsr 0x0603B93C (external) */  ! call save_checksum_calc(r4=0)
    mov #0x0, r4
    mov r13, r0
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
