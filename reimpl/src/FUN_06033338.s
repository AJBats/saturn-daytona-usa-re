
    .section .text.FUN_06033338


    .global FUN_06033338
    .type FUN_06033338, @function
FUN_06033338:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    rts
    nop
    .4byte  0x07E00000
    .4byte  sym_060430CE
    .4byte  sym_060629AC
    .4byte  FUN_0602761E

    .global sym_06033354
sym_06033354:
    mov.l   .L_pool_060333B4, r5
    mov.l   .L_pool_060333B8, r0
    mov.l @r0, r0
    mov.l @r0, r0
    cmp/pl r0
    bf      .L_06033362
    mov.l   .L_pool_060333BC, r5
.L_06033362:
    mov.l   .L_pool_060333C0, r4
    mov #0x6, r1
.L_06033366:
    mov.b @r5+, r0
    mov.b r0, @r4
    add #0x1, r4
    mov.b @r5+, r0
    mov.b r0, @r4
    add #0x3, r4
    add #-0x1, r1
    mov #0x0, r0
    cmp/eq r0, r1
    bf      .L_06033366
    mov #0x6, r7
    mov.l   .L_pool_060333C4, r8
    mov.l   .L_pool_060333C8, r9
    mov.l   .L_pool_060333CC, r10
    mov.w @r8+, r4
    mov r4, r5
    add r10, r4
    add r9, r5
    mov.w @r8+, r6
    mov.l   .L_pool_060333D0, r0


    .global FUN_0603338E
    .type FUN_0603338E, @function
FUN_0603338E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    add #-0x1, r7
    cmp/pl r7
    .byte   0x89, 0xF2    /* bt 0x06033382 (external) */
    mov.l   .L_pool_060333CC, r5
    mov.l   .L_pool_060333D4, r4
    mov.w   .L_pool_060333B0, r6
    mov.l   .L_pool_060333D0, r0


    .global FUN_060333A4
    .type FUN_060333A4, @function
FUN_060333A4:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    rts
    nop
.L_pool_060333B0:
    .4byte  0x07E00000
.L_pool_060333B4:
    .4byte  sym_060338DC
.L_pool_060333B8:
    .4byte  sym_06033868
.L_pool_060333BC:
    .4byte  sym_060338E8
.L_pool_060333C0:
    .4byte  sym_06062D95
.L_pool_060333C4:
    .4byte  sym_060338F4
.L_pool_060333C8:
    .4byte  sym_060430CE
.L_pool_060333CC:
    .4byte  sym_060629AC
.L_pool_060333D0:
    .4byte  FUN_0602761E
.L_pool_060333D4:
    .4byte  0x25E03700

    .global sym_060333D8
sym_060333D8:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
