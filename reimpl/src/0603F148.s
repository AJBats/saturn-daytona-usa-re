
    .section .text.FUN_0603F148


    .global slave_sh2_setup
    .type slave_sh2_setup, @function
slave_sh2_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov r4, r13
    mov.l r11, @-r15
    mov r5, r12
    mov.l r10, @-r15
    mov r6, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_0603F18C, r9
    mov.w   .L_0603F180, r11
    mov.l   .L_0603F190, r0
    mov.l   .L_0603F194, r3
    jsr @r3
    mov r5, r1
    tst r0, r0
    bf      .L_0603F170
    bra     .L_0603F1D0
    mov #0x0, r0
.L_0603F170:
    mov.l   .L_0603F198, r0
    mov.l   .L_0603F194, r3
    jsr @r3
    mov r12, r1
    tst r0, r0
    bf      .L_0603F19C
    bra     .L_0603F1D0
    mov #0x1, r0
.L_0603F180:
    .2byte  0x0080
    .2byte  0xFFFF
    .4byte  cmd_dispatch_main
    .4byte  menu_state_handler
.L_0603F18C:
    .4byte  sym_06036D94
.L_0603F190:
    .4byte  sym_06059CB8
.L_0603F194:
    .4byte  sym_06036D14
.L_0603F198:
    .4byte  sym_06059CBC
.L_0603F19C:
    mov #0x2, r14
    cmp/ge r10, r14
    bt/s    .L_0603F1CE
    add #0x30, r13
.L_0603F1A4:
    mov #0xC, r6
    mov r13, r5
    add #0xC, r5
    jsr @r9
    mov r12, r4
    tst r0, r0
    bf      .L_0603F1B6
    bra     .L_0603F1D0
    mov r14, r0
.L_0603F1B6:
    mov.b @(11, r13), r0
    mov r0, r3
    extu.b r3, r3
    and r11, r3
    tst r3, r3
    bt      .L_0603F1C6
    bra     .L_0603F1CE
    nop
.L_0603F1C6:
    add #0x1, r14
    cmp/ge r10, r14
    bf/s    .L_0603F1A4
    add #0x18, r13
.L_0603F1CE:
    mov #-0x1, r0
.L_0603F1D0:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0603F1E0
sym_0603F1E0:
    mov r4, r0
    mov r4, r3
    shll2 r0
    shll2 r3
    shll r3
    add r3, r0
    rts
    add r5, r0

    .global sym_0603F1F0
sym_0603F1F0:
    mov r4, r0
    mov r4, r3
    shll2 r0
    shll2 r3
    shll r0
    shll2 r3
    add r3, r0
    rts
    add r5, r0
