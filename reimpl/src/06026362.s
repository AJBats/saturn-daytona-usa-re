	.text
    .global transform_rotation_apply
transform_rotation_apply:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    .byte   0xDC, 0x0C    /* mov.l .L_pool_060263A0, r12 */
    mov #0xA, r13
    .byte   0xDE, 0x0C    /* mov.l .L_pool_060263A4, r14 */
    .byte   0xD7, 0x0D    /* mov.l .L_pool_060263A8, r7 */
    .byte   0xD5, 0x0D    /* mov.l .L_060263A8, r5 */
    mov #0x0, r4
    extu.w r4, r6
.L_06026376:
    extu.w r6, r0
    shll2 r0
    shll r0
    add r12, r0
    mov.w @(6, r0), r0
    bra     .L_060263AC
    extu.w r0, r0
    .long  0xA001624D                      /* bra +2 / extu.w r4, r2 (case A entry) */
    .long  0x625DA027                      /* extu.w r5, r2 / bra loop_next (case C entry) */
    .long  0x2E21A001                      /* mov.w r2, @r14 [delay] / bra +2 (case B entry) */
    .long  0x624D625D                      /* extu.w r4, r2 [delay] / extu.w r5, r2 (case D entry) */
    .long  0xA0222721                      /* bra loop_next / mov.w r2, @r7 [delay] */
.L_06026398:
    bra     .L_060263DC
    nop
.L_pool_060263A0:
    .long  sym_06060F2C
.L_pool_060263A4:
    .long  sym_06060D2A
.L_pool_060263A8:
    .long  sym_06060D34
.L_060263A8:
    .long  0x00008000
.L_060263AC:
    mov.w   .L_wpool_060263C6, r1
    sub r1, r0
    mov #0xC, r1
    cmp/hs r1, r0
    bt      .L_06026398
    shll r0
    mov r0, r1
    .word 0xC702
    mov.w @(r0, r1), r0
    braf r0
    nop
.L_wpool_060263C6:
    .short  0x008A
    .long  0xFFC2FFC2
    .long  0xFFCCFFCC
    .long  0xFFC6FFC6
    .long  0xFFC6FFC6
    .long  0xFFD0FFD0
    .long  0xFFD0FFD0
.L_060263DC:
    add #0x1, r6
    extu.w r6, r2
    cmp/ge r13, r2
    bf      .L_06026376
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
