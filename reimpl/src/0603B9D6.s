
    .section .text.FUN_0603B9D6


    .global save_field_read
    .type save_field_read, @function
save_field_read:
    mov.l r14, @-r15
    sts.l pr, @-r15
    tst r4, r4
    bf      .L_0603B9E8
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .4byte  sym_060A4D14
.L_0603B9E8:
    .byte   0xBF, 0xBF    /* bsr 0x0603B96A (external) */
    nop
    cmp/eq #-0x1, r0
    bt/s    .L_0603BA26
    mov r0, r4
    mov #0x60, r0
    mov r4, r6
    mov r4, r5
    .byte   0xD7, 0x1B    /* mov.l .L_pool_0603BA68, r7 */
    add #0x1, r6
    mov.l @r7, r7
    shll2 r6
    add #0x34, r7
    mov.l @(r0, r7), r3
    add #-0x1, r3
    mov r3, r14
    mov.l r3, @(r0, r7)
    cmp/ge r14, r4
    bt/s    .L_0603BA26
    shll2 r5
.L_0603BA10:
    mov r7, r0
    mov r7, r2
    mov r6, r3
    add #0x1, r4
    add r5, r2
    add #0x4, r6
    mov.l @(r0, r3), r1
    mov.l r1, @r2
    cmp/ge r14, r4
    bf/s    .L_0603BA10
    add #0x4, r5
.L_0603BA26:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
