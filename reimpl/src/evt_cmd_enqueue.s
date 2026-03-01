
    .section .text.FUN_060408B0


    .global evt_cmd_enqueue
    .type evt_cmd_enqueue, @function
evt_cmd_enqueue:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov r6, r13
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l r5, @(16, r15)
    mov.l r6, @-r15
    mov r15, r7
    mov.l @(20, r15), r6
    mov.l @(16, r14), r5
    mov.l   .L_ptr_cmd_enqueue, r3
    add #0x4, r7
    jsr @r3
    mov.l @(4, r14), r4
    mov r0, r4
    tst r4, r4
    bt/s    .L_enqueue_ok
    add #0x4, r15
    bra     .L_return_early
    mov #0x0, r0
.L_enqueue_ok:
    mov.l   .L_ptr_state_field_read, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_state_ok
    bra     .L_return_early
    mov #0x0, r0
.L_state_ok:
    tst r13, r13
    bt      .L_return_result
    mov #0x0, r12
    mov r12, r6
    mov r12, r5
    mov.l r12, @-r15
    mov.l r12, @-r15
    mov r15, r3
    add #0xC, r3
    mov.l r3, @-r15
    mov r15, r2
    add #0x18, r2
    mov.l r2, @-r15
    mov r15, r7
    mov.l   .L_ptr_evt_field_extract, r3
    add #0x18, r7
    jsr @r3
    mov.l @r14, r4
    add #0x10, r15
    mov r14, r4
    mov.l @(12, r15), r3
    mov.l @(8, r4), r5
    mov.l @(16, r4), r2
    add r2, r5
    mov.l @r15, r2
    add r2, r5
    cmp/ge r3, r5
    bf      .L_return_result
    mov.l @(4, r15), r0
    tst r0, r0
    bt      .L_return_result
    mov.l @r15, r3
    cmp/pl r3
    bf      .L_return_result
    mov.l @(8, r15), r2
    mov.l @(4, r15), r3
    sub r3, r2
    mov.l @r13, r1
    sub r2, r1
    mov.l r1, @r13
.L_return_result:
    mov.l @r15, r0
.L_return_early:
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_ptr_cmd_enqueue:
    .4byte  cmd_enqueue
.L_ptr_state_field_read:
    .4byte  state_field_read
.L_ptr_evt_field_extract:
    .4byte  sym_06040220
