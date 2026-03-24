
    .section .text.FUN_0603BEB8


    .global FUN_0603BEB8
    .type FUN_0603BEB8, @function
FUN_0603BEB8:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_0603BF18, r3
    jsr @r3
    mov.l r11, @-r15
    bra     .L_0603BF0C
    add #0x10, r15
    .4byte  0x25588901                  /* tst r5,r5; bt +1 */
    .4byte  0x63422532                  /* mov.l @r4,r3; mov.l r3,@r5 */
    .4byte  0x26688901                  /* tst r6,r6; bt +1 */
    .4byte  0x53412632                  /* mov.l @(4,r4),r3; mov.l r3,@r6 */
    .4byte  0x2DD88903                  /* tst r13,r13; bt +3 */
    .4byte  0xE01C034C                  /* mov #0x1C,r0; mov.b @(r0,r4),r3 */
    .4byte  0x633C2D32                  /* extu.b r3,r3; mov.l r3,@r13 */
    .4byte  0x27788901                  /* tst r7,r7; bt +1 */
    .4byte  0x53432732                  /* mov.l @(12,r4),r3; mov.l r3,@r7 */
    .4byte  0x2BB88901                  /* tst r11,r11; bt +1 */
    .4byte  0x53442B32                  /* mov.l @(16,r4),r3; mov.l r3,@r11 */
    .4byte  0x2EE88903                  /* tst r14,r14; bt +3 */
    .4byte  0xE01D034C                  /* mov #0x1D,r0; mov.b @(r0,r4),r3 */
    .4byte  0x633C2E32                  /* extu.b r3,r3; mov.l r3,@r14 */
    .4byte  0x2CC88903                  /* tst r12,r12; bt +3 */
    .4byte  0x53435245                  /* mov.l @(12,r4),r3; mov.l @(20,r4),r2 */
    .4byte  0x33282C32                  /* sub r2,r3; mov.l r3,@r12 */
.L_0603BF0C:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603BF18:
    .4byte  sym_06040220
    .4byte  0x504A000B                  /* embedded: mov.l @(0x28,r4),r0; rts */
    .2byte  0x145A                      /* embedded: mov.l r5,@(0x28,r4) [delay slot] */


    .global FUN_0603BF22
    .type FUN_0603BF22, @function
FUN_0603BF22:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r5, r14
    add #-0x4, r15
    mov.l r4, @r15
    .reloc ., R_SH_IND12W, FUN_0603B9D6 - 4
    .2byte 0xB000    /* bsr FUN_0603B9D6 (linker-resolved) */
    mov r5, r4
    mov.l @r15, r4
    mov #0x0, r3
    mov.w   .L_0603BF6E, r0
    mov.l r3, @(r0, r4)
    tst r14, r14
    bf      .L_0603BF44
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0603BF44:
    mov.l @r14, r4
    mov.l @(24, r4), r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x08    /* mov.l .L_0603BF70, r3 */
    jmp @r3
    mov.l @r15+, r14
    .2byte  0x7F04
    .4byte  0x4F26000B
    .2byte 0x6EF6
    .global FUN_0603BF5A
FUN_0603BF5A:
    .2byte 0xE11D
    .4byte  0x6042001C
    .4byte  0x600CC860
    .4byte  0x8B066542
    .4byte  0x5556A004
    .2byte  0x5459

    .global DAT_0603bf6e
.L_0603BF6E:
DAT_0603bf6e:
    .2byte  0x00EC
.L_0603BF70:
    .4byte  FUN_0604087C
    .4byte  0xE400000B
    .4byte  0x60430000

    .global sym_0603BF7C
sym_0603BF7C:
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov #0x3F, r9
    mov #0x40, r10
    .byte   0xDB, 0x1C    /* mov.l .L_0603BFFC, r11 */
    mov.w   .L_0603BFF8, r12
    mov #0x0, r7
    mov.w   .L_0603BFFA, r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFE, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov r7, r13
.L_0603BF9E:
    mov.b @r5, r3
    extu.b r3, r3
    and r9, r3
    extu.b r13, r2
    or r2, r3
    extu.b r3, r3
    mov.b r3, @r5
    mov r11, r6
    mov r10, r1
.L_0603BFB0:
    mov.l r7, @r6
    add #-0x2, r1
    add #0x10, r6
    mov.l r7, @r6
    tst r1, r1
    bf/s    .L_0603BFB0
    add #0x10, r6
    add #0x40, r13
    cmp/hs r12, r13
    bf      .L_0603BF9E
    extu.b r4, r4
    mov.b @r5, r0
    extu.b r0, r0
    and #0xF7, r0
    or r4, r0
    mov.b r0, @r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFD, r0
    mov.b r0, @r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFB, r0
    mov.b r0, @r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFE, r0
    or #0x1, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r13
.L_0603BFF8:
    .2byte  0x0100
.L_0603BFFA:
    .2byte  0xFE92
.L_0603BFFC:
    .4byte  0x60000000

    .global sym_0603C000
sym_0603C000:
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x40, r10
    mov #0x3F, r11
    mov.w   DAT_0603c07a, r12
    .byte   0xDD, 0x1C    /* mov.l .L_0603C080, r13 */
    mov #0x0, r7
    mov.w   .L_0603C07C, r5
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFE, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov r7, r1
.L_0603C020:
    mov.b @r5, r3
    extu.b r3, r3
    and r11, r3
    extu.b r1, r2
    or r2, r3
    extu.b r3, r3
    mov.b r3, @r5
    mov r13, r4
    mov r10, r6
.L_0603C032:
    add #-0x2, r6
    mov.l r7, @r4
    add #0x10, r4
    mov.l r7, @r4
    tst r6, r6
    bf/s    .L_0603C032
    add #0x10, r4
    add #0x40, r1
    cmp/hs r12, r1
    bf      .L_0603C020
    mov.b @r5, r0
    extu.b r0, r0
    and #0xFE, r0
    or #0x1, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r13

    .global sym_0603C05C
sym_0603C05C:
    .byte   0xD3, 0x09    /* mov.l .L_0603C084, r3 */
    .byte   0xD2, 0x0A    /* mov.l .L_0603C088, r2 */
    and r3, r4
    or r2, r4
    mov r4, r7
    add r5, r7
    cmp/hs r7, r4
    bt/s    .L_0603C076
    mov #0x0, r6
.L_0603C06E:
    mov.l r6, @r4
    add #0x10, r4
    cmp/hs r7, r4
    bf      .L_0603C06E
.L_0603C076:
    rts
    nop

    .global DAT_0603c07a
DAT_0603c07a:
    .2byte  0x0100
.L_0603C07C:
    .2byte  0xFE92
    .2byte  0xFFFF
.L_0603C080:
    .4byte  0x60000000
.L_0603C084:
    .4byte  0x1FFFFFF0
.L_0603C088:
    .4byte  0x40000000
