
    .section .text.FUN_0603ADAC


    .global cmd_dispatch_helper
    .type cmd_dispatch_helper, @function
cmd_dispatch_helper:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_state_ptr, r5
    mov.w   .L_woff_cmd_slot_base, r3
    mov.l @r5, r14
    tst r4, r4
    bf/s    .L_copy_command
    add r3, r14
    mov.l @r5, r3
    mov.w   .L_woff_active_count, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_clear_slot
    mov #-0x7, r4
    lds.l @r15+, pr
    .byte   0xA5, 0xB7    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(-7)
    mov.l @r15+, r14
.L_clear_slot:
    mov #0x0, r4
    mov.l r4, @(8, r14)
    mov.l r4, @(12, r14)
    mov r4, r2
    bra     .L_report_success
    mov.l r4, @(4, r14)
.L_woff_cmd_slot_base:
    .2byte  0x0098
.L_woff_active_count:
    .2byte  0x00A0
    .2byte  0x00F4
    .4byte  sym_0603F1E0
    .4byte  sym_0603F1F0
    .4byte  scene_frame_render
.L_pool_state_ptr:
    .4byte  sym_060A4D14
.L_copy_command:
    mov r14, r1
    mov r4, r2
    .byte   0xD3, 0x1C    /* mov.l pool_memcpy_long@0x0603AE68, r3 */  ! r3 = memcpy_long (sym_06035168)
    jsr @r3
    mov #0xC, r0
    .byte   0xB4, 0xE1    /* bsr 0x0603B7C0 (external) */  ! call sys_timer_config (element flag search)
    nop
    mov.l r0, @(12, r14)
.L_report_success:
    mov #0x0, r4
    lds.l @r15+, pr
    .byte   0xA5, 0x9A    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(0)
    mov.l @r15+, r14
