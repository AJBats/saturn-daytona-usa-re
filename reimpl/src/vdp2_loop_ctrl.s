
    .section .text.FUN_060172BC


    .global vdp2_loop_ctrl
    .type vdp2_loop_ctrl, @function
vdp2_loop_ctrl:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov #0x12, r12
    mov #0x0, r14
.L_slot_loop:
    extu.b r14, r13
    bsr     sym_060172E4
    mov r13, r4
    bsr     .L_init_scroll_entry
    mov r13, r4
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r12, r2
    bf      .L_slot_loop
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_060172E4
sym_060172E4:
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov.l   .L_pool_0601732C, r2
    add r2, r4
    mov #0x0, r5
    extu.b r5, r0
    mov.b r0, @(2, r4)
    mov.b r0, @(1, r4)
    mov.b r0, @r4
    mov.l r5, @(12, r4)
    mov r5, r3
    mov.l r5, @(8, r4)
    mov r3, r2
    mov.l r3, @(4, r4)
    mov.l r2, @(24, r4)
    mov.l r2, @(20, r4)
    mov.l r2, @(16, r4)
    mov.l r2, @(36, r4)
    mov.l r2, @(32, r4)
    mov.l r2, @(28, r4)
    mov.l r2, @(48, r4)
    mov.l r2, @(44, r4)
    mov.l r2, @(40, r4)
    mov.l r2, @(56, r4)
    mov.l r2, @(52, r4)
    mov #0x41, r0
    mov.b r2, @(r0, r4)
    mov #0x40, r0
    rts
    mov.b r2, @(r0, r4)
.L_pool_0601732C:
    .4byte  sym_06084FC8
.L_init_scroll_entry:
    mov #0x8, r7
    mov #0x0, r5
    extu.b r4, r6
    mov r6, r3
    shll2 r6
    shll r6
    shll2 r3
    shll2 r3
    add r3, r6
    exts.w r6, r6
    .byte   0xD2, 0x17    /* mov.l .L_pool_060173A4, r2 */
    add r2, r6
    extu.b r5, r3
    mov r3, r0
    mov.b r0, @(4, r6)
    mov.w r0, @(6, r6)
    extu.b r3, r3
    mov r3, r0
    mov.b r0, @(5, r6)
    extu.b r5, r4
.L_word_clear_loop:
    extu.b r4, r3
    mov r6, r2
    exts.w r5, r1
    shll r3
    add #0x1, r4
    add #0x8, r2
    add r2, r3
    mov.w r1, @r3
    extu.b r4, r3
    cmp/ge r7, r3
    bf      .L_word_clear_loop
    rts
    nop
