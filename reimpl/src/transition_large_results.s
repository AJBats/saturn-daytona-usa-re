
    .section .text.FUN_0600FB78


    .global transition_large_results
    .type transition_large_results, @function
transition_large_results:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_0600FC3C, r11
    mov.l   .L_0600FC40, r3
    jsr @r3
    nop
    mov.l   .L_0600FC44, r3
    jsr @r3
    nop
    mov.l   .L_0600FC48, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0600FBA4
    bra     .L_0600FCD6
    nop
.L_0600FBA4:
    mov.w   .L_0600FC2C, r10
    mov.w   .L_0600FC2E, r12
    mov.l   .L_0600FC4C, r13
    mov.l   .L_0600FC50, r14
    mov.l   .L_0600FC54, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600FBB8
    bra     .L_0600FCB0
    nop
.L_0600FBB8:
    mov.w   .L_0600FC30, r8
    mov.l   .L_0600FC58, r7
    mov.w   .L_0600FC32, r5
    mov r8, r6
    jsr @r14
    mov #0xC, r4
    mov.l   .L_0600FC5C, r9
    mov r8, r6
    mov.w   .L_0600FC34, r5
    mov.l   .L_0600FC60, r3
    mov.l @r9, r7
    shll2 r7
    add r3, r7
    mov.l @r7, r7
    jsr @r14
    mov #0xC, r4
    mov.l   .L_0600FC64, r7
    mov r8, r6
    mov.w   .L_0600FC36, r5
    jsr @r14
    mov #0xC, r4
    mov r8, r6
    mov.w   .L_0600FC38, r5
    mov.l @r9, r7
    mov.l   .L_0600FC68, r3
    shll2 r7
    add r3, r7
    mov.l @r7, r7
    jsr @r14
    mov #0xC, r4
    mov.l @r9, r2
    mov #0x9, r3
    cmp/hi r3, r2
    bf      .L_0600FC86
    mov #0xB, r2
    mov.l   .L_0600FC6C, r4
    mov.l @r9, r3
    cmp/hi r2, r3
    bf      .L_0600FC20
    mov.l @r4, r0
    cmp/eq #0x1, r0
    bf      .L_0600FC12
    mov.l   .L_0600FC70, r7
    bra     .L_0600FC14
    nop
.L_0600FC12:
    mov.l   .L_0600FC74, r7
.L_0600FC14:
    mov r10, r6
    mov r12, r5
    jsr @r13
    mov #0xC, r4
    bra     .L_0600FC86
    nop
.L_0600FC20:
    mov.l @r4, r0
    cmp/eq #0x1, r0
    bf      .L_0600FC7C
    mov.l   .L_0600FC78, r7
    bra     .L_0600FC7E
    nop
.L_0600FC2C:
    .2byte  0x0090
.L_0600FC2E:
    .2byte  0x07A2
.L_0600FC30:
    .2byte  0x2000
.L_0600FC32:
    .2byte  0x0686
.L_0600FC34:
    .2byte  0x06A0
.L_0600FC36:
    .2byte  0x0706
.L_0600FC38:
    .2byte  0x0720
    .2byte  0xFFFF
.L_0600FC3C:
    .4byte  g_pad_state
.L_0600FC40:
    .4byte  graphics_mode_setup
.L_0600FC44:
    .4byte  sym_06011EB4
.L_0600FC48:
    .4byte  sym_06085FF4
.L_0600FC4C:
    .4byte  sym_060284AE
.L_0600FC50:
    .4byte  sym_060283E0
.L_0600FC54:
    .4byte  sym_0607889C
.L_0600FC58:
    .4byte  sym_06044750
.L_0600FC5C:
    .4byte  sym_06078868
.L_0600FC60:
    .4byte  sym_0605AB28
.L_0600FC64:
    .4byte  sym_0604475D
.L_0600FC68:
    .4byte  sym_0605AB60
.L_0600FC6C:
    .4byte  sym_06078644
.L_0600FC70:
    .4byte  sym_06044878
.L_0600FC74:
    .4byte  sym_06044888
.L_0600FC78:
    .4byte  sym_06044898
.L_0600FC7C:
    mov.l   .L_0600FD3C, r7
.L_0600FC7E:
    mov r10, r6
    mov r12, r5
    jsr @r13
    mov #0xC, r4
.L_0600FC86:
    mov.w @(6, r11), r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0600FCA6
    mov.l   .L_0600FD40, r4
    mov.l @r4, r0
    tst r0, r0
    bf      .L_0600FC9E
    .byte   0xB5, 0x63    /* bsr 0x06010760 (external) */
    nop
    bra     .L_0600FCF2
    nop
.L_0600FC9E:
    mov.l @r4, r2
    add #-0x1, r2
    bra     .L_0600FCF2
    mov.l r2, @r4
.L_0600FCA6:
    mov.w @(2, r11), r0
    .byte   0xB4, 0x1A    /* bsr 0x060104E0 (external) */
    mov r0, r4
    bra     .L_0600FCF2
    nop
.L_0600FCB0:
    mov.l   .L_0600FD44, r2
    mov #0x0, r6
    mov.l r2, @r15
    mov r2, r7
    mov.w   .L_0600FD36, r5
    jsr @r14
    mov #0xC, r4
    mov #0x0, r6
    mov.w   .L_0600FD38, r5
    mov.l @r15, r7
    jsr @r14
    mov #0xC, r4
    mov.l   .L_0600FD48, r7
    mov r10, r6
    mov r12, r5
    jsr @r13
    mov #0xC, r4
    bra     .L_0600FCF2
    nop
.L_0600FCD6:
    mov.l   .L_0600FD4C, r3
    jsr @r3
    mov #0x1, r4
    mov.w @(6, r11), r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0600FCEC
    .byte   0xB3, 0xC4    /* bsr 0x06010470 (external) */
    nop
    bra     .L_0600FCF2
    nop
.L_0600FCEC:
    mov.w @(2, r11), r0
    .byte   0xB3, 0x63    /* bsr 0x060103B8 (external) */
    mov r0, r4
.L_0600FCF2:
    mov r11, r2
    mov.l r2, @r15
    mov r2, r3
    mov.w @r3, r2
    mov r2, r0
    mov.w r0, @(4, r15)
    mov.w @(4, r15), r0
    mov.w   .L_0600FD3A, r2
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0600FD16
    mov #0x1, r3
    mov.l   .L_0600FD50, r2
    mov.l r3, @r2
    bra     .L_0600FD1C
    nop
.L_0600FD16:
    mov #0x0, r3
    mov.l   .L_0600FD50, r2
    mov.l r3, @r2
.L_0600FD1C:
    mov.l @r15, r4
    add #0x2, r4
    mov.w @r4, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA6, 0xB7    /* bra 0x06010AA4 (external) */
    mov.l @r15+, r14
.L_0600FD36:
    .2byte  0x0686
.L_0600FD38:
    .2byte  0x0706
.L_0600FD3A:
    .2byte  0x0800
.L_0600FD3C:
    .4byte  sym_060448A8
.L_0600FD40:
    .4byte  sym_0605AA9C
.L_0600FD44:
    .4byte  sym_0605ACE1
.L_0600FD48:
    .4byte  sym_0605ACE3
.L_0600FD4C:
    .4byte  anim_ui_transition
.L_0600FD50:
    .4byte  sym_0607EAE0
