
    .section .text.FUN_06005A22


    .global input_event_handler
    .type input_event_handler, @function
input_event_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD4, 0x26    /* mov.l .L_pool_06005AC4, r4 */
    mov.l @r4, r3
    cmp/pl r3
    bf      .L_06005AE0
    mov.l @r4, r3
    add #-0x1, r3
    mov r3, r0
    tst #0x1, r0
    bt/s    .L_06005A9C
    mov.l r3, @r4
    .byte   0xD0, 0x22    /* mov.l .L_pool_06005AC8, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06005A4A
    mov.w   .L_wpool_06005ABA, r14
    bra     .L_06005A4C
    nop
.L_06005A4A:
    mov #0x21, r14
.L_06005A4C:
    .byte   0xD0, 0x1F    /* mov.l .L_pool_06005ACC, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06005A78
    mov r14, r7
    shll2 r7
    shll r7
    .byte   0xD3, 0x1D    /* mov.l .L_pool_06005AD0, r3 */
    add r3, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06005abc, r3
    add r3, r7
    mov.w   DAT_06005abe, r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x18    /* mov.l .L_pool_06005AD4, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_06005A78:
    mov r14, r7
    shll2 r7
    shll r7
    .byte   0xD3, 0x14    /* mov.l .L_pool_06005AD0, r3 */
    add r3, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06005abc, r3
    add r3, r7
    mov.w   DAT_06005ac0, r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06005AD4, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_06005A9C:
    .byte   0xD7, 0x0E    /* mov.l .L_pool_06005AD8, r7 */
    mov.w   .L_wpool_06005AC2, r6
    mov.w   DAT_06005abe, r5
    .byte   0xD3, 0x0E    /* mov.l .L_pool_06005ADC, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xD7, 0x0B    /* mov.l .L_pool_06005AD8, r7 */
    mov.w   .L_wpool_06005AC2, r6
    mov.w   DAT_06005ac0, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x09    /* mov.l .L_pool_06005ADC, r3 */
    jmp @r3
    mov.l @r15+, r14


.L_wpool_06005ABA:
    .2byte  0x00B0

    .global DAT_06005abc
DAT_06005abc:
    .2byte  0x5000

    .global DAT_06005abe
DAT_06005abe:
    .2byte  0x049C

    .global DAT_06005ac0
DAT_06005ac0:
    .2byte  0x059C

.L_wpool_06005AC2:
    .2byte  0x0090


.L_pool_06005AC4:
    .4byte  sym_0607EABC
.L_pool_06005AC8:
    .4byte  sym_06085FF4
.L_pool_06005ACC:
    .4byte  sym_0607EAC0
.L_pool_06005AD0:
    .4byte  sym_06063750
.L_pool_06005AD4:
    .4byte  sym_06028400
.L_pool_06005AD8:
    .4byte  sym_0605ACDD
.L_pool_06005ADC:
    .4byte  sym_060284AE


.L_06005AE0:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
