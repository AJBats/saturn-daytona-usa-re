
    .section .text.FUN_0603BB86


    .global save_header_parse
    .type save_header_parse, @function
save_header_parse:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    .byte   0xDD, 0x0B    /* mov.l .L_pool_0603BBBD, r13 */
    mov.w   DAT_0603bbb4, r1
    mov.l @r13, r0
    mov.l @(r0, r1), r0
    tst #0x1, r0
    bf/s    .L_0603BB9E
    mov r4, r14
    bra     .L_0603BC0A
    mov #0x0, r0
.L_0603BB9E:
    mov.l @r13, r4
    mov.w   DAT_0603bbb6, r3
    add r3, r4
    .byte   0xBF, 0x8F    /* bsr 0x0603BAC6 (external) */
    nop
    tst r0, r0
    bf      .L_0603BBC0
    bra     .L_0603BC0A
    mov #0x0, r0

    .global DAT_0603bbb0
DAT_0603bbb0:
    mov.l r10, @(r0, r0)
    .word 0x0800

    .global DAT_0603bbb4
DAT_0603bbb4:
    .2byte  0x00C4

    .global DAT_0603bbb6
DAT_0603bbb6:
    .2byte  0x043C
    .4byte  evt_boundary_check
.L_pool_0603BBBD:
    .4byte  sym_060A4D14
.L_0603BBC0:
    mov.l @r13, r3
    mov #0x4, r6
    .byte   0x92, 0x45    /* mov.w .L_wpool_0603BC52, r2 */
    .byte   0x9D, 0x43    /* mov.w .L_wpool_0603BC50, r13 */
    add r3, r13
    add r2, r13
    .byte   0xD3, 0x22    /* mov.l .L_pool_0603BC58, r3 */
    mov r13, r5
    add #0x6, r5
    jsr @r3
    mov r14, r4
    mov #0x4, r6
    mov r13, r5
    mov r14, r4
    .byte   0x92, 0x3A    /* mov.w .L_wpool_0603BC54, r2 */
    mov.l @r14, r3
    add #0xE, r5
    add r2, r3
    mov.l r3, @r14
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0603BC58, r3 */
    jsr @r3
    add #0x4, r4
    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_0603BBF6
    bra     .L_0603BC0A
    mov #0x0, r0
.L_0603BBF6:
    mov #0x0, r4
    extu.b r4, r0
    mov.b r0, @(10, r14)
    extu.b r4, r0
    mov.b r0, @(11, r14)
    extu.b r4, r0
    mov.b r0, @(8, r14)
    extu.b r4, r0
    mov.b r0, @(9, r14)
    mov #0x1, r0
.L_0603BC0A:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
