
    .section .text.FUN_06016750


    .global results_awards
    .type results_awards, @function
results_awards:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r6
    mov r15, r1
    mov.l   .L_pool_060167BC, r2
    mov.l   .L_pool_060167C0, r3
    jsr @r3
    mov #0x10, r0
    mov.l   .L_pool_060167C4, r7
    extu.b r4, r5
    mov #0x40, r0
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r7, r5
    mov.b @(r0, r5), r0
    extu.b r0, r0
    shll2 r0
    mov.l @(r0, r6), r3
    mov.l r3, @(60, r5)
    mov.b @(2, r5), r0
    mov r0, r2
    add #0x1, r2
    mov r2, r0
    mov.b r0, @(2, r5)
    mov #0x4, r2
    mov #0x40, r0
    mov.b @(r0, r5), r3
    add #0x1, r3
    mov.b r3, @(r0, r5)
    mov.b @(r0, r5), r3
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_done
    extu.b r4, r4
    mov r4, r2
    shll2 r4
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r4
    exts.w r4, r4
    add r7, r4
    mov #0x2, r3
    mov r3, r0
    mov.b r0, @(2, r4)
.L_done:
    add #0x10, r15
    lds.l @r15+, pr
    rts
    nop
.L_pool_060167BC:
    .4byte  sym_0605BB0C
.L_pool_060167C0:
    .4byte  sym_06035168
.L_pool_060167C4:
    .4byte  sym_06084FC8
