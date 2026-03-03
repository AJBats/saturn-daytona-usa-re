	.text
    .global secondary_render_pass
secondary_render_pass:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDD, 0x0F    /* mov.l .L_pool_0602EDE5, r13 */
    jsr @r13
    nop
    .byte   0xA0, 0x89    /* bra 0x0602EEC2 (external) */
    nop
    .long  0x005C0108
    .long  0x010C0120
    .long  0x0080007C
    .long  0x007E00C8
    .long  0x009E00CC
    .long  sym_0602FDA1
    .long  sym_0607E944
    .long  sym_0607EAE4
    .long  0xFFFF0000
    .long  sym_0602EE90
    .long  sym_0602EDE8
    .long  sym_0602EE20
    .long  sym_0602EE58
.L_pool_0602EDE5:
    .long  sym_060302C6

    .global sym_0602EDE8
sym_0602EDE8:
    .long  loc_0604605C
    .long  loc_06045EEC
    .long  loc_0604633C
    .long  loc_060461CC
    .long  loc_0604661C
    .long  loc_060464AC
    .long  loc_0604605C
    .long  loc_06045EEC
    .long  loc_0604661C
    .long  loc_060464AC
    .long  loc_0604633C
    .long  loc_060461CC
    .long  loc_0604661C
    .long  loc_060464AC

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
