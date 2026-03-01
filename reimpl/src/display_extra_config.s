
    .section .text.FUN_06038A64


    .global display_extra_config
    .type display_extra_config, @function
display_extra_config:
    mov.w   DAT_06038a9a, r6
    mov.l   .L_pool_disp_state_ptr, r5
    bra     .L_dispatch_mode
    mov r4, r0
.L_mode_0_clear_upper:
    mov.w @(14, r5), r0
    mov r0, r2
    extu.w r2, r2
    bra     .L_write_back
    and r6, r2
.L_mode_1_set_bit12:
    mov.w @(14, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    mov.w   .L_wpool_bit12_mask, r3
    or r3, r2
    bra     .L_write_back
    nop
.L_mode_2_set_bit13:
    mov.w @(14, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    mov.w   DAT_06038a9e, r3
    or r3, r2
.L_write_back:
    extu.w r2, r2
    mov r2, r0
    bra     .L_signal_ready
    mov.w r0, @(14, r5)

    .global DAT_06038a9a
DAT_06038a9a:
    .2byte  0x0FFF
.L_wpool_bit12_mask:
    .2byte  0x1000                      /* [HIGH] bit 12 set mask (mode 1 — low-nibble channel select) */

    .global DAT_06038a9e
DAT_06038a9e:
    .2byte  0x2000
.L_pool_disp_state_ptr:
    .4byte  sym_060A3D88
.L_dispatch_mode:
    cmp/eq #0x0, r0
    bt      .L_mode_0_clear_upper
    cmp/eq #0x1, r0
    bt      .L_mode_1_set_bit12
    cmp/eq #0x2, r0
    bt      .L_mode_2_set_bit13
.L_signal_ready:
    mov.l   .L_pool_cmd_ready_flag, r4
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_return
    mov #0x1, r3
    mov.w r3, @r4
.L_return:
    rts
    nop
    .2byte  0xFFFF
.L_pool_cmd_ready_flag:
    .4byte  sym_060635AC
