
    .section .text.FUN_0603FF3A


    .global attract_cleanup
    .type attract_cleanup, @function
attract_cleanup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r7, r13
    tst r5, r5
    bf/s    .L_dst_valid
    mov r5, r14
    bra     .L_early_return
    nop
    .2byte  0x0101
    .4byte  0x25FE000C
    .4byte  sym_06000340
.L_dst_valid:
    mov #0x0, r4
    shll2 r6
    mov.l @(8, r15), r7
    mov.l @(12, r15), r5
    mov r4, r3
    shlr2 r5
    cmp/hs r5, r3
    bt/s    .L_copy_done
    shll2 r7
.L_copy_loop:
    add #0x1, r4
    mov.l @r13, r3
    mov.l r3, @r14
    add r6, r14
    cmp/hs r5, r4
    bf/s    .L_copy_loop
    add r7, r13
.L_copy_done:
    mov r13, r6
    mov r14, r5
    mov.l @(12, r15), r0
    and #0x3, r0
    mov r0, r4
    mov.l @r15+, r13
    .byte   0xA0, 0x31    /* bra 0x0603FFE6 (external) */ ! tail-call: copy remaining bytes
    mov.l @r15+, r14
.L_early_return:
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global loc_0603FF8A
loc_0603FF8A:
    rts
    mov #0x0, r0
    .2byte  0x7FFC
    .4byte  0x2F426043
    .4byte  0x50095448
    .4byte  0x402B7F04
