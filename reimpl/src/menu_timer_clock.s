
    .section .text.FUN_0603B634


    .global menu_timer_clock
    .type menu_timer_clock, @function
menu_timer_clock:
    sts.l pr, @-r15
    mov r4, r14
    mov.l @r14, r0
    mov.b @(r0, r1), r0
    extu.b r0, r0
    tst #0x60, r0
    bf      .L_0603B666
    bra     .L_0603B646
    nop
.L_0603B646:
    .byte   0xBD, 0x07    /* bsr 0x0603B058 (external) */
    mov r14, r4
    mov r0, r5
    .byte   0xD3, 0x13    /* mov.l .L_pool_0603B69C, r3 */
    jsr @r3
    mov.l @r14, r4
    tst r0, r0
    bf      .L_0603B65E
    mov #-0x14, r4
    lds.l @r15+, pr
    .byte   0xA1, 0x6F    /* bra 0x0603B93C (external) */
    mov.l @r15+, r14
.L_0603B65E:
    .byte   0xD2, 0x10    /* mov.l .L_pool_0603B6A0, r2 */
    mov.l @r2, r2
    .byte   0x90, 0x19    /* mov.w .L_wpool_0603B698, r0 */
    mov.l r14, @(r0, r2)
.L_0603B666:
    mov #0x0, r4
    lds.l @r15+, pr
    .byte   0xA1, 0x67    /* bra 0x0603B93C (external) */
    mov.l @r15+, r14
    .2byte  0xD60C
    .4byte  0x63629012
    .4byte  0x03466362
    .4byte  0x70040356
    .4byte  0xA15EE400
