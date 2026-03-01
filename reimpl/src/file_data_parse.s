
    .section .text.FUN_06012344


    .global file_data_parse
    .type file_data_parse, @function
file_data_parse:
    mov.l r14, @-r15
    mov #0x0, r3
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_060123E4, r12
    mov.l   .L_pool_060123E8, r11
    mov.w   DAT_060123de, r5
    mov.l @r12, r12
    cmp/gt r12, r3
    addc r3, r12
    shar r12
    shll16 r12
    jsr @r11
    mov r12, r4
    mov r0, r13
    mov.w   DAT_060123e0, r5
    jsr @r11
    mov r12, r4
    mov r0, r14
    mov.w   DAT_060123e2, r5
    jsr @r11
    mov r12, r4
    mov r0, r4
    mov r13, r5
    mov.l   .L_pool_060123EC, r6
    mov r4, r1
    shll r5
    mov.l @r6, r2
    sub r5, r2
    mov.l r2, @r6
    mov.l @(4, r6), r3
    add r14, r3
    mov.l r3, @(4, r6)
    mov.l @(8, r6), r2
    add r4, r2
    mov.l r2, @(8, r6)
    mov.l   .L_pool_060123F0, r6
    mov.l @r6, r3
    sub r14, r3
    mov.l r3, @r6
    mov.l @(4, r6), r2
    sub r13, r2
    mov.l r2, @(4, r6)
    mov.l @(8, r6), r3
    sub r13, r3
    mov.l r3, @(8, r6)
    mov.l   .L_pool_060123F4, r6
    mov.l @r6, r2
    add r5, r2
    mov.l r2, @r6
    mov.l   .L_pool_060123F8, r3
    jsr @r3
    mov #0x4, r0
    mov.l @(4, r6), r2
    sub r0, r2
    mov.l r2, @(4, r6)
    mov.l @(8, r6), r3
    sub r4, r3
    mov.l r3, @(8, r6)
    mov.l   .L_pool_060123FC, r5
    mov.l @r5, r2
    add r14, r2
    mov.l r2, @r5
    mov.l @(4, r5), r3
    add r14, r3
    mov.l r3, @(4, r5)
    mov.l @(8, r5), r2
    add r4, r2
    mov.l r2, @(8, r5)
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_060123de
DAT_060123de:
    .2byte  0x07AE
    .global DAT_060123e0
DAT_060123e0:
    .2byte  0x170A
    .global DAT_060123e2
DAT_060123e2:
    .2byte  0x2666
.L_pool_060123E4:
    .4byte  sym_060788AC                    /* frame timer / animation state counter */
.L_pool_060123E8:
    .4byte  fpmul                           /* 16.16 fixed-point multiply: fpmul(r4, r5) -> r0 */
.L_pool_060123EC:
    .4byte  sym_060788C0                    /* position vector B (XYZ triplet, 12 bytes) */
.L_pool_060123F0:
    .4byte  sym_060788CC                    /* position vector C (XYZ triplet, 12 bytes) */
.L_pool_060123F4:
    .4byte  sym_060788D8                    /* position vector D (XYZ triplet, 12 bytes) */
.L_pool_060123F8:
    .4byte  sym_06034FE0                    /* hw_divide(r0=divisor, r1=dividend) -> r0=quotient */
.L_pool_060123FC:
    .4byte  sym_060788E4                    /* position vector E (XYZ triplet, 12 bytes) */
