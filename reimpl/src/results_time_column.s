
    .section .text.FUN_060162AC


    .global results_time_column
    .type results_time_column, @function
results_time_column:
    sts.l pr, @-r15
    shll2 r12
    shll2 r3
    mov.l   .L_06016354, r13
    shll2 r3
    shll2 r3
    add r3, r12
    exts.w r12, r12
    add r13, r12
    mov.l @(16, r12), r2
    mov.l @(4, r12), r3
    add r2, r3
    mov.l r3, @(4, r12)
    mov r3, r4
    mov.l @(52, r12), r2
    mov.l   .L_06016358, r3
    jsr @r3
    sub r2, r4
    mov.l @(36, r12), r2
    cmp/gt r2, r0
    .word 0x0029
    xor #0x1, r0
    mov.l   .L_0601635C, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    .word 0x0129
    and r1, r0
    tst r0, r0
    bt      .L_0601630C
    extu.b r14, r4
    mov.l   .L_0601635C, r2
    mov.b r10, @r2
    mov r4, r2
    shll2 r4
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(32, r4), r3
    mov.l r3, @(4, r4)
    mov.l @(16, r4), r1
    mov.l   .L_06016360, r2
    jsr @r2
    mov #0xA, r0
    mov.l r0, @(16, r4)
.L_0601630C:
    mov #0x4, r4
    extu.b r14, r3
    cmp/ge r4, r3
    .word 0x0029
    xor #0x1, r0
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(4, r5), r2
    mov.l @(52, r5), r3
    cmp/gt r3, r2
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_06016364
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    mov.l r2, @(4, r4)
    bra     .L_060163A2
    extu.b r10, r11
.L_06016354:
    .4byte  sym_06084FC8                 /* → results entry table base address */
.L_06016358:
    .4byte  sym_06035438                 /* → abs_diff / time subtraction function */
.L_0601635C:
    .4byte  sym_0605BAF8                 /* → results state flag byte */
.L_06016360:
    .4byte  sym_06034FE0                 /* → scale/divide function */
.L_06016364:
    extu.b r14, r2
    cmp/ge r4, r2
    .word 0x0029
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(4, r5), r2
    mov.l @(52, r5), r3
    cmp/ge r3, r2
    .word 0x0129
    and r1, r0
    tst r0, r0
    bt      .L_060163A2
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    mov.l r2, @(4, r4)
    extu.b r10, r11
.L_060163A2:
    .byte   0xD0, 0x2E    /* mov.l .L_pool_0601645C, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060163E0
    extu.b r14, r4
    .byte   0x92, 0x55    /* mov.w .L_wpool_0601645A, r2 */
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(48, r4), r3
    add r2, r3
    mov.l r3, @(48, r4)
    mov r3, r2
    cmp/pz r2
    bf      .L_060163E0
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    mov #0x0, r1
    mov.l r1, @(48, r2)
.L_060163E0:
    .byte   0xB4, 0xFA    /* bsr 0x06016DD8 (external) */
    extu.b r14, r4
    extu.b r11, r11
    tst r11, r11
    bt      .L_06016402
    extu.b r14, r14
    mov r14, r3
    shll2 r14
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r14
    exts.w r14, r14
    add r13, r14
    mov #0x7, r2
    mov r2, r0
    mov.b r0, @(2, r14)
.L_06016402:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
