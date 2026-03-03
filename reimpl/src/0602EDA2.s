
    .section .text.FUN_0602EDA2


    .global secondary_render_pass
    .type secondary_render_pass, @function
secondary_render_pass:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDD, 0x0F    /* mov.l .L_pool_0602EDE5, r13 */
    jsr @r13
    nop
    .byte   0xA0, 0x89    /* bra 0x0602EEC2 (external) */
    nop
    .4byte  0x005C0108
    .4byte  0x010C0120
    .4byte  0x0080007C
    .4byte  0x007E00C8
    .4byte  0x009E00CC
    .4byte  sym_0602FDA1
    .4byte  sym_0607E944
    .4byte  sym_0607EAE4
    .4byte  0xFFFF0000
    .4byte  sym_0602EE90
    .4byte  sym_0602EDE8
    .4byte  sym_0602EE20
    .4byte  sym_0602EE58
.L_pool_0602EDE5:
    .4byte  sym_060302C6

    .global sym_0602EDE8
sym_0602EDE8:
    .4byte  loc_0604605C
    .4byte  loc_06045EEC
    .4byte  loc_0604633C
    .4byte  loc_060461CC
    .4byte  loc_0604661C
    .4byte  loc_060464AC
    .4byte  loc_0604605C
    .4byte  loc_06045EEC
    .4byte  loc_0604661C
    .4byte  loc_060464AC
    .4byte  loc_0604633C
    .4byte  loc_060461CC
    .4byte  loc_0604661C
    .4byte  loc_060464AC

    .global sym_0602EE20
sym_0602EE20:
    mov.l r8, @(0, r1)
    mov.l r8, @(0, r1)
    mov.l r8, @(0, r1)
    mov.l r8, @(0, r1)
    mov.l r8, @(0, r3)
    mov.l r0, @(0, r13)
    mov.l r8, @(0, r3)
    mov.l r0, @(0, r13)
    .word 0x0F00
    mov.l r0, @(0, r2)
    .word 0x0F00
    mov.l r0, @(0, r2)
    mov.l r0, @(0, r6)
    mov.l r0, @(0, r7)
    mov.l r0, @(0, r6)
    mov.l r0, @(0, r7)
    mov.l r0, @(0, r7)
    mov.l r4, @(0, r5)
    mov.l r0, @(0, r7)
    mov.l r4, @(0, r5)
    mov.l r8, @(0, r1)
    mov.l r8, @(0, r1)
    mov.l r8, @(0, r1)
    mov.l r8, @(0, r1)
    .word 0x0F00
    mov.l r0, @(0, r2)
    .word 0x0F00
    mov.l r0, @(0, r2)

    .global sym_0602EE58
sym_0602EE58:
    mov.l r12, @(0, r0)
    .word 0x0F80
    mov.l r12, @(0, r0)
    .word 0x0F80
    mov.l r0, @(0, r3)
    mov.l r0, @(0, r6)
    mov.l r0, @(0, r3)
    mov.l r0, @(0, r6)
    .word 0x0F20
    mov.l r0, @(0, r1)
    .word 0x0F20
    mov.l r0, @(0, r1)
    mov.l r0, @(0, r5)
    mov.l r0, @(0, r3)
    mov.l r0, @(0, r5)
    mov.l r0, @(0, r3)
    mov.l r8, @(0, r6)
    mov.l r4, @(0, r3)
    mov.l r8, @(0, r6)
    mov.l r4, @(0, r3)
    mov.l r12, @(0, r0)
    .word 0x0F80
    mov.l r12, @(0, r0)
    .word 0x0F80
    .word 0x0F20
    mov.l r0, @(0, r1)
    .word 0x0F20
    mov.l r0, @(0, r1)

    .global sym_0602EE90
sym_0602EE90:
    mov.w r0, @(r0, r7)
    mov.w r0, @(r0, r7)
    .word 0x4870
    .word 0x4870
    .word 0x0508
    .word 0x0508
    mov.b r3, @r8
    mov.b r3, @r8
    cmp/eq r1, r0
    cmp/eq r1, r0
    shal r0
    shal r0
    stc sr, r5
    stc sr, r5

    .global loc_0602EEAC
loc_0602EEAC:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
