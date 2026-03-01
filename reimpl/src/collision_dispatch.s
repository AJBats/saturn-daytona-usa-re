
    .section .text.FUN_0600CF58


    .global collision_dispatch
    .type collision_dispatch, @function
collision_dispatch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov r15, r11
    mov.w   .L_wpool_0600CFE2, r12
    mov.l   .L_pool_0600CFEC, r13
    mov.l   .L_pool_0600CFF0, r4
    mov.l @r4, r14
    mov.l @(4, r14), r0
    tst r0, r0
    bf/s    .L_collision_active
    mov.l @r13, r13
    bra     .L_check_collision_ended
    nop
.L_collision_active:
    mov.l @(8, r14), r3
    mov.w   DAT_0600cfe4, r2
    cmp/gt r2, r3
    bt      .L_speed_sufficient
    bra     .L_check_collision_ended
    nop
.L_speed_sufficient:
    mov.l @r4, r2
    mov.l @r2, r3
    mov.l   .L_pool_0600CFF4, r2
    and r2, r3
    tst r3, r3
    bf      .L_car_is_capable
    bra     .L_epilogue
    nop
.L_car_is_capable:
    mov r11, r1
    mov r14, r2
    mov.l   .L_pool_0600CFF8, r3
    jsr @r3
    mov #0x4, r0
    mov.w   DAT_0600cfe6, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_severity_eval
    bsr     .L_speed_limit_clamp
    nop
    bra     .L_epilogue
    nop
.L_severity_eval:
    mov r11, r0
    mov.b @r0, r0
    tst #0x2, r0
    bt      .L_primary_distance_check
    mov.l @(8, r13), r3
    mov.l @(8, r14), r2
    cmp/ge r2, r3
    bt      .L_copy_speed_limit
    .byte   0xB0, 0xB4    /* bsr 0x0600D12C (external) -- speed response handler */
    nop
    bra     .L_primary_distance_check
    nop
.L_copy_speed_limit:
    mov.w   .L_wpool_0600CFE8, r0
    mov.l @(r0, r14), r2
    add #-0x4, r0
    mov.l r2, @(r0, r14)
    add #0xC, r0
    bra     .L_epilogue
    mov.l r12, @(r0, r14)
.L_primary_distance_check:
    mov.l @(8, r13), r3
    mov.l @(8, r14), r2
    cmp/ge r2, r3
    bt      .L_detailed_state_dispatch
    bra     .L_epilogue
    nop
.L_wpool_0600CFE2:
    .2byte  0x0080

    .global DAT_0600cfe4
DAT_0600cfe4:
    .2byte  0x0096

    .global DAT_0600cfe6
DAT_0600cfe6:
    .2byte  0x0210
.L_wpool_0600CFE8:
    .2byte  0x01FC
    .2byte  0xFFFF
.L_pool_0600CFEC:
    .4byte  sym_0607E944
.L_pool_0600CFF0:
    .4byte  sym_0607E940
.L_pool_0600CFF4:
    .4byte  0x00C00000
.L_pool_0600CFF8:
    .4byte  sym_06035168
.L_detailed_state_dispatch:
    mov r11, r0
    mov.b @r0, r0
    tst #0x1, r0
    bt      .L_default_handler
    mov.w   .L_wpool_0600D0AA, r0
    mov.l @(r0, r14), r0
    cmp/eq #0x2, r0
    bf      .L_check_state_1
    mov.l @(8, r13), r2
    mov.w   .L_wpool_0600D0AC, r3
    cmp/gt r3, r2
    bf      .L_normal_collision
    mov #0xA, r2
    mov.w   .L_wpool_0600D0AE, r0
    mov.l @(r0, r14), r3
    cmp/ge r2, r3
    bt      .L_normal_collision
    .byte   0xB0, 0xF7    /* bsr 0x0600D210 (external) -- severe collision handler */
    nop
    bra     .L_state_dispatch_done
    nop
.L_normal_collision:
    .byte   0xB0, 0x81    /* bsr 0x0600D12C (external) -- normal collision handler */
    nop
    bra     .L_state_dispatch_done
    nop
.L_check_state_1:
    mov.w   .L_wpool_0600D0AA, r0
    mov.l @(r0, r14), r0
    cmp/eq #0x1, r0
    bf      .L_state_dispatch_done
    mov.w   .L_wpool_0600D0B0, r0
    mov #0x2, r3
    mov.l @(r0, r13), r4
    mov.l @(r0, r14), r5
    shar r4
    shar r5
    shar r4
    shar r5
    shar r4
    shar r5
    shar r4
    shar r5
    shar r4
    shar r5
    shar r4
    shar r5
    shar r4
    shar r5
    shar r4
    shar r5
    cmp/hs r3, r4
    bt      .L_check_high_range
    mov #0x3, r3
    cmp/hs r3, r5
    bt      .L_check_high_range
    mov.w   .L_wpool_0600D0B2, r3
    mov.w   .L_wpool_0600D0B4, r0
    mov.l r3, @(r0, r14)
    add #0xC, r0
    bra     .L_state_dispatch_done
    mov.l r12, @(r0, r14)
.L_check_high_range:
    mov #0x5, r2
    cmp/hi r2, r4
    bf      .L_state_dispatch_done
    mov #0x4, r2
    cmp/hi r2, r5
    bf      .L_state_dispatch_done
    mov.w   .L_wpool_0600D0B6, r2
    mov.w   .L_wpool_0600D0B4, r0
    mov.l r2, @(r0, r14)
    add #0xC, r0
    mov.l r12, @(r0, r14)
.L_state_dispatch_done:
    bra     .L_epilogue
    nop
.L_default_handler:
    .byte   0xB0, 0x4D    /* bsr 0x0600D12C (external) -- default collision response */
    nop
.L_check_collision_ended:
    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_epilogue
    .byte   0xB0, 0x48    /* bsr 0x0600D12C (external) -- cleanup on collision end */
    nop
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_0600D0AA:
    .2byte  0x0210
.L_wpool_0600D0AC:
    .2byte  0x0AF0
.L_wpool_0600D0AE:
    .2byte  0x0224
.L_wpool_0600D0B0:
    .2byte  0x01FC
.L_wpool_0600D0B2:
    .2byte  0x0300
.L_wpool_0600D0B4:
    .2byte  0x01F8
.L_wpool_0600D0B6:
    .2byte  0x0400
.L_speed_limit_clamp:
    mov.w   .L_wpool_0600D112, r7
    mov.l   .L_pool_0600D120, r5
    mov.l   .L_pool_0600D124, r4
    mov.l @r4, r6
    mov r6, r3
    mov.l @r3, r2
    mov.l   .L_pool_0600D128, r3
    and r3, r2
    tst r2, r2
    bt/s    .L_clamp_return
    mov.l @r5, r5
    mov.w   DAT_0600d114, r0
    mov.l @(r0, r5), r3
    mov.l @(r0, r6), r2
    cmp/ge r2, r3
    bt      .L_clamp_decrement
    mov.w   DAT_0600d114, r0
    mov.l @(r0, r5), r4
    bra     .L_clamp_check_bounds
    add r7, r4
.L_clamp_decrement:
    mov.w   DAT_0600d114, r0
    mov.l @(r0, r5), r4
    mov.w   .L_wpool_0600D116, r2
    add r2, r4
.L_clamp_check_bounds:
    cmp/pz r4
    bt      .L_clamp_check_upper
    mov #0x0, r2
    mov.w   .L_wpool_0600D118, r0
    mov.l r2, @(r0, r6)
    bra     .L_clamp_write_cooldown
    nop
.L_clamp_check_upper:
    mov.w   DAT_0600d11a, r3
    cmp/gt r3, r4
    bf      .L_clamp_store_target
    mov.w   DAT_0600d11a, r3
    mov.w   .L_wpool_0600D118, r0
    mov.l r3, @(r0, r6)
    bra     .L_clamp_write_cooldown
    nop
.L_clamp_store_target:
    mov.w   .L_wpool_0600D118, r0
    mov.l r4, @(r0, r6)
.L_clamp_write_cooldown:
    mov.w   .L_wpool_0600D11C, r0
    mov.l r7, @(r0, r6)
.L_clamp_return:
    rts
    nop
.L_wpool_0600D112:
    .2byte  0x0200

    .global DAT_0600d114
DAT_0600d114:
    .2byte  0x01FC
.L_wpool_0600D116:
    .2byte  0xFE00
.L_wpool_0600D118:
    .2byte  0x01F8

    .global DAT_0600d11a
DAT_0600d11a:
    .2byte  0x0800
.L_wpool_0600D11C:
    .2byte  0x0204
    .2byte  0xFFFF
.L_pool_0600D120:
    .4byte  sym_0607E944
.L_pool_0600D124:
    .4byte  sym_0607E940
.L_pool_0600D128:
    .4byte  0x00C00000
