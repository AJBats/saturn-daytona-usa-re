
    .section .text.FUN_06042134


    .global player_vehicle_interp
    .type player_vehicle_interp, @function
player_vehicle_interp:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   pool_fn_chkpt_validate, r8
    mov #0x2, r9
    mov #0x1, r10
    mov.w   DAT_0604222c, r11
    mov #0x0, r12
    mov.l   pool_game_state_ptr, r14
    mov.l r4, @r15
    bra     .loop_cond_check
    mov r12, r13
.loop_body:
    mov.l @r14, r0
    exts.w r13, r3
    mov r3, r2
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    exts.w r2, r2
    mov.w   DAT_0604222e, r3
    add r3, r0
    add r2, r0
    mov.l @(4, r0), r0
    cmp/eq #-0x2, r0
    bf      .srcA_present
    mov r12, r5
    bra     .check_srcB
    mov r11, r6
.srcA_present:
    mov r10, r5
    mov.l @r14, r6
    exts.w r13, r3
    mov r3, r2
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    exts.w r2, r2
    mov.w   DAT_0604222e, r3
    add r3, r6
    add r2, r6
    mov.l @(4, r6), r6
.check_srcB:
    mov.l @r14, r0
    exts.w r13, r3
    mov r3, r2
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    exts.w r2, r2
    mov.w   DAT_0604222e, r3
    add r3, r0
    add r2, r0
    mov.l @(8, r0), r0
    cmp/eq #-0x2, r0
    bf      .srcB_present
    bra     .call_road_edge
    mov r11, r7
.srcB_present:
    or r9, r5
    exts.w r13, r3
    mov.l @r14, r7
    mov r3, r2
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    exts.w r2, r2
    mov.w   DAT_0604222e, r3
    add r3, r7
    add r2, r7
    mov.l @(8, r7), r7
.call_road_edge:
    exts.w r13, r3
    mov.l @r14, r4
    mov r3, r2
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    exts.w r2, r2
    mov.w   DAT_0604222e, r3
    add r3, r4
    add r2, r4
    mov.l   pool_fn_road_edge, r3
    jsr @r3
    mov.l @r4, r4
    mov r0, r4
    tst r4, r4
    bt      .edge_check_ok
    bra     .loop_exit
    nop
.edge_check_ok:
    mov r15, r4
    jsr @r8
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r15, r3
    mov.l @r3, r2
    add #0x1, r2
    mov.l r2, @r3
    add #0x1, r13
.loop_cond_check:
    mov.l @r14, r3
    mov.w   wpool_entry_count_off, r0
    mov.l @(r0, r3), r2
    cmp/ge r2, r13
    bf      .loop_body
.loop_exit:
    mov.l @r14, r2
    mov.w   wpool_entry_count_off, r0
    mov.l @(r0, r2), r3
    cmp/ge r3, r13
    bf      .compact_remaining
    mov.l @r14, r2
    mov.w   wpool_entry_count_off, r0
    bra     .post_compact
    mov.l r12, @(r0, r2)

    .global DAT_0604222c
DAT_0604222c:
    .2byte  0x00FF

    .global DAT_0604222e
DAT_0604222e:
    .2byte  0x01E4
wpool_entry_count_off:
    .2byte  0x01DC
    .2byte  0xFFFF
pool_fn_chkpt_validate:
    .4byte  ai_checkpoint_validate
pool_game_state_ptr:
    .4byte  sym_060A5400
pool_fn_road_edge:
    .4byte  track_road_edge_c
.compact_remaining:
    bra     .compact_cond_check
    mov r12, r5
.compact_body:
    mov.l @r14, r7
    exts.w r5, r4
    exts.w r13, r6
    .byte   0x93, 0x5E    /* mov.w .L_wpool_0604230A, r3 */  ! r3 = 0x01E4 (array base offset)
    add r3, r7
    mov r4, r3
    mov r7, r2
    shll2 r4
    shll2 r3
    shll r3
    add r3, r4
    exts.w r4, r4
    mov r6, r3
    add r4, r2
    shll2 r6
    shll2 r3
    shll r3
    add r3, r6
    exts.w r6, r6
    mov r7, r1
    add r6, r1
    mov.l @r1, r3
    mov.l r3, @r2
    mov.l @r14, r7
    .byte   0x93, 0x49    /* mov.w .L_wpool_0604230A, r3 */  ! r3 = 0x01E4 (array base offset)
    add r3, r7
    mov r7, r2
    add r4, r2
    mov r7, r3
    add r6, r3
    mov.l @(4, r3), r1
    mov.l r1, @(4, r2)
    mov.l @r14, r7
    .byte   0x93, 0x40    /* mov.w .L_wpool_0604230A, r3 */  ! r3 = 0x01E4 (array base offset)
    add r3, r7
    add r7, r4
    add r7, r6
    mov.l @(8, r6), r2
    mov.l r2, @(8, r4)
    add #0x1, r13
    add #0x1, r5
.compact_cond_check:
    mov.l @r14, r3
    .byte   0x90, 0x38    /* mov.w .L_wpool_0604230C, r0 */  ! r0 = 0x01DC (entry count offset)
    mov.l @(r0, r3), r2
    cmp/ge r2, r13
    bf      .compact_body
    mov.l @r14, r2
    .byte   0x90, 0x33    /* mov.w .L_wpool_0604230C, r0 */  ! r0 = 0x01DC (entry count offset)
    mov.l r5, @(r0, r2)
.post_compact:
    mov #0x40, r3
    mov.l r3, @r15
    .byte   0xD3, 0x19    /* mov.l .L_pool_06042310, r3 */   ! r3 = &sym_06035C4E (HIRQ reader)
    jsr @r3
    nop
    mov r0, r5
    mov.l @r15, r3
    exts.w r5, r4
    and r3, r4
    tst r4, r4
    bt      .hirq_bit_clear
    bra     .hirq_bit_test
    mov #0x1, r4
.hirq_bit_clear:
    mov #0x0, r4
.hirq_bit_test:
    tst r4, r4
    bt      .return_count
    mov.l @r14, r3
    .byte   0x90, 0x20    /* mov.w .L_wpool_0604230C, r0 */  ! r0 = 0x01DC (entry count offset)
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .return_count
    mov.l @r14, r3
    .byte   0x90, 0x1C    /* mov.w .L_wpool_0604230E, r0 */  ! r0 = 0x01E0 (ready flag offset)
    mov.l r12, @(r0, r3)
.return_count:
    mov.l @r14, r0
    .byte   0x91, 0x18    /* mov.w .L_wpool_0604230C, r1 */  ! r1 = 0x01DC (entry count offset)
    mov.l @(r0, r1), r0
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
