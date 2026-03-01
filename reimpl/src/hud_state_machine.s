
    .section .text.FUN_0601E4D4


    .global hud_state_machine
    .type hud_state_machine, @function
hud_state_machine:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15

    mov #0x0, r8
    mov r15, r9
    add #0x8, r9
    mov.l   .L_smpc_comreg_ct, r10
    mov r10, r13
    add #0x44, r13
    mov #0x1, r14
    mov r15, r3
    add #0x4, r3
    mov.l r3, @r15

    mov r3, r5
    mov r9, r4
    mov.b r8, @r5
    mov.b r8, @r4
    add #0x1, r5
    add #0x1, r4
    extu.b r8, r2
    mov.b r2, @r5
    mov.b r2, @r4
    add #0x1, r5
    add #0x1, r4
    mov.b r8, @r5
    mov.b r8, @r4
    bra     .L_loop_check
    mov r8, r12

    .4byte  sym_06087084
    .4byte  sym_06000354
    .4byte  sym_06087094
    .4byte  sym_060877D8
    .4byte  sym_0604A5C0
.L_smpc_comreg_ct:
    .4byte  0x2010001F             /* SMPC COMREG (cache-through) */

.L_loop_body:
    mov r12, r11
    shll2 r11
    shll2 r11
    shll r11
    mov.l   .L_pool_0601E600, r3
    add r3, r11

.L_poll_sf_set_a:
    mov.b @r13, r3
    extu.b r3, r3
    and r14, r3
    cmp/eq r14, r3
    bt      .L_poll_sf_set_a
    mov.b r14, @r13
    mov #0x1A, r2
    mov.b r2, @r10
.L_poll_sf_clear_a:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_poll_sf_clear_a

    mov.l   .L_pool_0601E604, r3
    mov #0x0, r5
    mov.w @(28, r11), r0
    mov.l @r3, r3
    mov r0, r4
    mov.l @(4, r3), r2
    jsr @r2
    extu.w r4, r4

    mov.l   .L_pool_0601E608, r6
    mov.l   .L_pool_0601E60C, r5
    mov.l   .L_pool_0601E610, r2
    mov.w @(28, r11), r0
    mov.l @r6, r6
    mov.b @r5, r5
    extu.b r5, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    add r2, r5
    .byte   0xB0, 0xF0    /* bsr 0x0601E764 (hud_render_stage) */
    mov r0, r4
    mov r0, r4

.L_poll_sf_set_b:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_poll_sf_set_b
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.b r3, @r10
.L_poll_sf_clear_b:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_poll_sf_clear_b

    tst r4, r4
    bf      .L_skip_changed_flag
    mov r12, r3
    add r9, r3
    extu.b r14, r2
    mov.b r2, @r3

.L_skip_changed_flag:
    mov #0x1E, r0
    mov.b @(r0, r11), r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_next_element
    mov r15, r3
    add #0x4, r3
    add r12, r3
    extu.b r14, r2
    mov.b r2, @r3

.L_next_element:
    add #0x1, r12

.L_loop_check:
    mov.l   .L_pool_0601E614, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/ge r3, r12
    bf      .L_loop_body

    mov r8, r4

.L_scan_changed:
    mov r4, r3
    add r9, r3
    mov.b @r3, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_changed_not_set
    bra     .L_return
    extu.b r4, r0

.L_changed_not_set:
    add #0x1, r4
    mov #0x3, r3
    cmp/ge r3, r4
    bf      .L_scan_changed

    mov r15, r6
    mov.l @r15, r4
    add #0x7, r6
    cmp/hs r6, r4
    bt/s    .L_no_update_found
    mov #0x3, r5

.L_scan_update:
    mov.b @r4, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_update_not_set
    bra     .L_return
    extu.b r5, r0

.L_pool_0601E600:
    .4byte  sym_06087094
.L_pool_0601E604:
    .4byte  sym_06000354
.L_pool_0601E608:
    .4byte  sym_0605E098
.L_pool_0601E60C:
    .4byte  sym_060877D8
.L_pool_0601E610:
    .4byte  sym_0604A57C
.L_pool_0601E614:
    .4byte  sym_06087084

.L_update_not_set:
    add #0x1, r4
    cmp/hs r6, r4
    bf/s    .L_scan_update
    add #0x1, r5

.L_no_update_found:
    mov #0x8, r0

.L_return:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
