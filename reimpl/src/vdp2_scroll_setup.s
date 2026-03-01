
    .section .text.FUN_0602E264


    .global vdp2_scroll_setup
    .type vdp2_scroll_setup, @function
vdp2_scroll_setup:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   .L_0602E2C4, r0
    mov.l @r0, r0
    mov.w   .L_0602E290, r5
    add r0, r5
    mov.w   .L_0602E292, r3
    mov.l @r5, r1
    mov.w   .L_0602E294, r4
    cmp/gt r3, r1
    bt      .L_0602E2D0
    mov r3, r1
    bra     .L_0602E2D6
    nop

    .global DAT_0602e284
DAT_0602e284:
    mov.b r1, @(r0, r2)
    .word 0x0088

    .global DAT_0602e288
DAT_0602e288:
    mov.b r4, @(r0, r0)

    .global DAT_0602e28a
DAT_0602e28a:
    stc vbr, r0
    .word 0x0011

    .global DAT_0602e28e
DAT_0602e28e:
    .word 0x0208
.L_0602E290:
    .2byte  0x00E4
.L_0602E292:
    .2byte  0x0708
.L_0602E294:
    .2byte  0x2134
    .2byte  0x0000
    .4byte  sym_0607EAC8
    .4byte  0x00000001
    .4byte  0x00000028
    .4byte  0x00000000
    .4byte  0x000000C0
    .4byte  sym_0602F3EC
    .4byte  sym_0602F7BC
    .4byte  sym_06030A06
    .4byte  sym_06030EE0
    .4byte  brake_force_apply
    .4byte  accel_response
.L_0602E2C4:
    .4byte  sym_0607E940
    .4byte  sym_0602D82A
    .4byte  sym_0602F17C
.L_0602E2D0:
    cmp/gt r1, r4
    bt      .L_0602E2D6
    mov r4, r1
.L_0602E2D6:
    sub r3, r1
    shll8 r1
    .byte   0x90, 0x0D    /* mov.w .L_wpool_0602E2F8, r0 */
    shlr r1
    .byte   0xDC, 0x07    /* mov.l .L_pool_0602E2FC, r12 */
