
    .section .text.FUN_06018166


    .global geom_math_calc
    .type geom_math_calc, @function
geom_math_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.w   DAT_06018212, r11
    .byte   0xDC, 0x2C    /* mov.l .L_pool_0601822C, r12 */
    .byte   0xDD, 0x2D    /* mov.l .L_pool_06018230, r13 */
    .byte   0xDE, 0x2D    /* mov.l .L_pool_06018234, r14 */
    .byte   0xD4, 0x2E    /* mov.l .L_pool_06018238, r4 */
    mov.w @r12, r3
    mov.l @r4, r4
    add #0x1, r3
    mov.w r3, @r12
    .byte   0xD2, 0x2C    /* mov.l .L_pool_0601823C, r2 */
    mov.w   DAT_06018214, r0
    mov.l @r2, r2
    mov.l @(r0, r4), r3
    add #-0x1, r2
    cmp/hs r2, r3
    bf      .L_06018196
    .byte   0xD4, 0x2A    /* mov.l .L_pool_06018240, r4 */
    mov.l @r4, r4
    bra     .L_0601819C
    mov #0x1, r5
.L_06018196:
    .byte   0xD4, 0x29    /* mov.l .L_pool_06018244, r4 */
    mov.l @r4, r4
    mov #0x0, r5
.L_0601819C:
    mov.w   DAT_06018216, r6
    mov #0x5, r3
    mov.w @r12, r2
    cmp/gt r3, r2
    bt      .L_060181D2
    mov.w   .L_wpool_06018220, r4
    mov r14, r3
    add r14, r6
    add r11, r3
    mov.w @r3, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r13, r2
    mov.l @r2, r3
    add r4, r3
    mov.l r3, @r2
    mov.w @r6, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r13, r2
    mov.l @r2, r3
    add r4, r3
    mov.l r3, @r2
    bra     .L_060181F8
    nop
.L_060181D2:
    mov r14, r2
    add r14, r6
    add r11, r2
    mov.w @r2, r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r13, r3
    mov.l r4, @r3
    mov.w @r6, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r13, r2
    .byte   0xD3, 0x14    /* mov.l .L_pool_06018248, r3 */
    mov.l @r3, r3
    mov.l r3, @r2
    mov #0x0, r2
    mov.w r2, @r12
.L_060181F8:
    extu.w r5, r5
    tst r5, r5
    bt      .L_06018244
    mov r14, r3
    add r11, r3
    mov.w @r3, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r13, r2
    mov.w   DAT_0601821a, r0
    bra     .L_06018258
    mov.w r0, @(6, r2)

    .global DAT_06018212
DAT_06018212:
    .2byte  0x1618                           /* track data offset: primary slot index */

    .global DAT_06018214
DAT_06018214:
    .2byte  0x021C                           /* car struct offset: position field */

    .global DAT_06018216
DAT_06018216:
    .2byte  0x1630                           /* track data offset: secondary slot index */
.L_wpool_06018220:
    .2byte  0x0090                           /* per-frame slot value increment */

    .global DAT_0601821a
DAT_0601821a:
    .2byte  0x056C                           /* slot flag value: above-threshold marker */
    .4byte  sym_06026DF8                     /* (out-of-TU pool) pop matrix frame cleanup */
    .4byte  obj_overlay_render               /* (out-of-TU pool) overlay render function */
.L_pool_0601822C:
    .4byte  sym_0605BE2C                     /* segment frame counter (16-bit) */
.L_pool_06018230:
    .4byte  sym_06063F64                     /* per-slot data table base (8-byte stride) */
.L_pool_06018234:
    .4byte  sym_060684EC                     /* track data / index mapping table */
.L_pool_06018238:
    .4byte  sym_0607E944                     /* car array base pointer */
.L_pool_0601823C:
    .4byte  sym_06063F28                     /* maximum lap count for current race */
.L_pool_06018240:
    .4byte  sym_06089E2C                     /* projection param B (above-threshold config) */
.L_pool_06018244:
    .4byte  sym_06089E28                     /* projection config (below-threshold config) */
.L_pool_06018248:
    .4byte  sym_06089E30                     /* projection param A (reset target for secondary slot) */
.L_06018244:
    mov r14, r2
    add r11, r2
    mov.w @r2, r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r13, r3
    .byte   0x92, 0x4E    /* mov.w .L_wpool_060182F2, r2 */
    mov r2, r0
    mov.w r0, @(6, r3)
.L_06018258:
    .byte   0xD3, 0x27    /* mov.l .L_pool_060182F8, r3 */
    .byte   0xD2, 0x28    /* mov.l .L_pool_060182FC, r2 */
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0601826E
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA1, 0xB5    /* bra 0x060185D8 (external) */
    mov.l @r15+, r14
.L_0601826E:
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0x54    /* bra 0x06018320 (external) */
    mov.l @r15+, r14
