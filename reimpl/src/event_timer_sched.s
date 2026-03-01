
    .section .text.FUN_06040B34


    .global event_timer_sched
    .type event_timer_sched, @function
event_timer_sched:
    mov.l r14, @-r15
    mov #0x0, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x18, r15
    mov.l r5, @(20, r15)
    mov.l   .L_pool_06040B50, r3
    mov.b @(r0, r3), r2
    extu.b r2, r2
    tst r2, r2
    bt/s    .L_06040B54
    mov r4, r13
    .byte   0xA0, 0x51    /* bra 0x06040BF2 (external: event_callback_dispatch epilogue) */
    mov #0x0, r0
.L_pool_06040B50:
    .4byte  sym_0606367C
.L_06040B54:
    mov r15, r3
    add #0x4, r3
    mov.l r3, @-r15
    mov r15, r7
    mov.l @(24, r15), r6
    mov.l @(16, r13), r5
    .byte   0xD3, 0x26    /* mov.l .L_pool_06040BFC, r3 */
    add #0x4, r7
    jsr @r3
    mov.l @(4, r13), r4
    tst r0, r0
    bt/s    .L_06040B72
    add #0x4, r15
    .byte   0xA0, 0x40    /* bra 0x06040BF2 (external: event_callback_dispatch epilogue) */
    mov #0x0, r0
.L_06040B72:
    .byte   0xD3, 0x23    /* mov.l .L_pool_06040C00, r3 */
    jsr @r3
    nop
    tst r0, r0
    bt      .L_06040B80
    .byte   0xA0, 0x39    /* bra 0x06040BF2 (external: event_callback_dispatch epilogue) */
    mov #0x0, r0
.L_06040B80:
    mov.l @(4, r15), r3
    cmp/pl r3
    bt      .L_06040B8A
    .byte   0xA0, 0x34    /* bra 0x06040BF2 (external: event_callback_dispatch epilogue) */
    mov #0x0, r0
.L_06040B8A:
    mov r14, r6
    mov r14, r5
