
    .section .text.FUN_06012AFA


    .global car_param_lookup
    .type car_param_lookup, @function
car_param_lookup:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDE, 0x12    /* mov.l .L_pool_06012B4F, r14 */
    mov.l @r14, r0
    tst #0x4, r0
    bt      .L_call_course_lookup
    .byte   0xD3, 0x11    /* mov.l .L_pool_06012B53, r3 */
    mov.l r3, @r15
    mov r3, r7
    mov.w   .L_wpool_06012B39, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    mov.w   .L_wpool_06012B3F, r3
    mov.l @r5, r5
    add r3, r7
    .byte   0xD3, 0x0E    /* mov.l .L_pool_06012B57, r3 */
    jsr @r3
    mov #0x8, r4
    bra     .L_increment_and_return
    nop
.L_call_course_lookup:
    .byte   0xBF, 0xCE    /* bsr 0x06012AC4 (external) */
    nop
.L_increment_and_return:
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_06012B39:
    .2byte  0x061C
    .4byte  0x069C071C
.L_wpool_06012B3F:
    .2byte  0x4000
    .2byte  0xFFFF
    .4byte  sym_0605ACDD
    .4byte  sym_060283E0
    .4byte  0x0000F000
.L_pool_06012B4F:
    .4byte  sym_060788FC
.L_pool_06012B53:
    .4byte  sym_06063800
.L_pool_06012B57:
    .4byte  sym_06028400
