
    .section .text.FUN_06033020


    .global FUN_06033020
    .type FUN_06033020, @function
FUN_06033020:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l   .L_pool_06033040, r0
    mov.b @r0, r1
    mov.l   .L_pool_06033044, r0
    tst r0, r1
    bt      .L_0603304C
    mov.l   .L_pool_06033048, r5
    bra     .L_0603304E
    nop
    .2byte  0x0000
.L_pool_06033040:
    .4byte  sym_06082A25
.L_pool_06033044:
    .4byte  0x00000001
.L_pool_06033048:
    .4byte  0x00003333
.L_0603304C:
    xor r5, r5
.L_0603304E:
    mov.l   .L_pool_06033074, r0
    mov.l @r0, r1
    sub r1, r5
    shar r5
    add r5, r1
    mov.l r1, @r0
    mov.l @r4, r2
    add r1, r2
    mov.l r2, @r4
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
    .2byte  0x0000
.L_pool_06033074:
    .4byte  sym_06082A28
    .4byte  0x000B0009
    .global FUN_0603307C
FUN_0603307C:
    .4byte  0xD0076002
    .4byte  0x60024015
    .2byte  0x8907


    .global FUN_06033086
    .type FUN_06033086, @function
FUN_06033086:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033330 - 4
    .2byte 0xB000    /* bsr FUN_06033330 (linker-resolved) */
    nop
    lds.l @r15+, pr

    .global FUN_0603308E
    .type FUN_0603308E, @function
FUN_0603308E:
    sts.l pr, @-r15
    bsr     .L_060330A0
    nop
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x0000
    .4byte  sym_06033864
.L_060330A0:
    .byte   0xD0, 0x28    /* mov.l .L_pool_06033144, r0 */
    mov.l @r0, r0


    .global FUN_060330A4
    .type FUN_060330A4, @function
FUN_060330A4:
    sts.l pr, @-r15
    bsr     FUN_0603316C
    nop
    lds.l @r15+, pr
    .byte   0xD8, 0x26    /* mov.l .L_pool_06033148, r8 */
    .byte   0xD9, 0x27    /* mov.l .L_pool_0603314C, r9 */
    mov.l @(r0, r8), r13
    mov.l @(r0, r9), r14
    .byte   0xDA, 0x26    /* mov.l .L_pool_06033150, r10 */
    add r10, r0
    .byte   0xD7, 0x26    /* mov.l .L_pool_06033154, r7 */
    mov.l @r7, r7
    mov.l @r7, r7
    add #-0x1, r7
    mov.l @(r0, r8), r11
    mov.l @(r0, r9), r12
    neg r11, r11
    neg r12, r12
    add r13, r11
    add r14, r12
    mov r11, r4
    shar r4
    add r4, r11
    mov r12, r4
    mov r11, r1
    .byte   0xD2, 0x20    /* mov.l .L_pool_06033158, r2 */
    cmp/pz r1
    bt      .L_060330DE
    neg r1, r1
.L_060330DE:
    cmp/gt r2, r1
    .byte   0x89, 0x29    /* bt 0x06033136 (external) */
    mov r12, r1
    .byte   0xD2, 0x1D    /* mov.l .L_pool_0603315C, r2 */
    cmp/pz r1
    bt      .L_060330EC
    neg r1, r1
.L_060330EC:
    cmp/gt r2, r1
    .byte   0x89, 0x22    /* bt 0x06033136 (external) */
    mov.l r0, @-r15
    mov.l r6, @-r15
    sts.l pr, @-r15
    bsr     FUN_0603316C
    nop
    lds.l @r15+, pr
    neg r6, r0
    mov.l @r15+, r6

    .global FUN_06033100
    .type FUN_06033100, @function
FUN_06033100:
    sts.l pr, @-r15
    bsr     FUN_06033188
    nop
    lds.l @r15+, pr
    add r6, r0
    .byte   0xD3, 0x15    /* mov.l .L_pool_06033160, r3 */
    mov.l @r3, r3
    mov.b @r3, r3
    extu.b r3, r3
    .byte   0xD4, 0x14    /* mov.l .L_pool_06033164, r4 */
    cmp/pl r3
    bt      .L_0603311A
    neg r0, r0
.L_0603311A:
    add r4, r0
    .byte   0xD4, 0x12    /* mov.l .L_pool_06033168, r4 */
    and r4, r0
    shlr8 r0
    shlr2 r0
    shlr2 r0
    cmp/pl r3
    .byte   0x89, 0x00    /* bt 0x0603312C (external) */
    neg r1, r1

    .global FUN_0603312C
    .type FUN_0603312C, @function
FUN_0603312C:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603320C - 4
    .2byte 0xB000    /* bsr FUN_0603320C (linker-resolved) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r0
    add r10, r0
    add #-0x1, r7
    cmp/pl r7
    .byte   0x89, 0xC0    /* bt 0x060330C0 (external) */
    rts
    nop
    .2byte  0x0000
    .4byte  sym_06033870
    .4byte  0x00000010
    .4byte  0x00000018
    .4byte  0x00000268
    .4byte  sym_0603386C
    .4byte  0x00220000
    .4byte  0x001A0000
    .4byte  sym_06033884
    .4byte  0x00000700
    .4byte  0x0000FFFF
    .global FUN_0603316C
FUN_0603316C:
    .4byte  0xD204042E
    .4byte  0xD204032E
    .4byte  0x343C343C
    .4byte  0x664B000B
    .4byte  0x00090000
    .4byte  0x00000020
    .4byte  0x000001D8
    .global FUN_06033188
FUN_06033188:
    .4byte  0x2F062F66
    .4byte  0x2F762F86
    .4byte  0x6463D019
    .4byte  0x2409D519
    .4byte  0xD619D01A
