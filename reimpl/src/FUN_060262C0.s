
    .section .text.FUN_060262C0


    .global FUN_060262C0
    .type FUN_060262C0, @function
FUN_060262C0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r10, @-r15
    mov.l   .L_pool_06026314, r10
    mov #0xA, r12
    mov.l   .L_pool_06026318, r13
    mov.l   .L_pool_0602631C, r14
    mov #0x1, r7
    mov #0x2, r6
    mov #0x0, r0
    extu.w r0, r3
    mov.w r3, @r13
    extu.w r0, r2
    mov.w r2, @r14
    bra     .L_06026352
    extu.w r0, r5
.L_060262E2:
    extu.w r5, r2
    cmp/eq r4, r2
    bf      .L_060262EC
    bra     .L_06026350
    nop
.L_060262EC:
    extu.w r5, r0
    shll2 r0
    shll r0
    add r10, r0
    mov.w @(6, r0), r0
    bra     .L_06026320
    extu.w r0, r0
    .2byte  0xA001                          /* bra .L_case_23_store_id_b: store then bra loop */
    .4byte  0x627D626D                      /* extu.w r7,r2 / extu.w r6,r2 */
    .4byte  0xA0262D21                      /* bra .L_06026350 / mov.w r2,@r13 [delay] */
    .4byte  0xA001627D                      /* bra .L_case_811_store_id_b: bra / extu.w r7,r2 [delay] */
    .4byte  0x626DA021                      /* extu.w r6,r2 / bra .L_06026350 */
    .2byte  0x2E21                          /* mov.w r2,@r14 [delay: store r2 to course_id_b] */
.L_0602630E:
    bra     .L_06026350
    nop
    .2byte  0xFFFF
.L_pool_06026314:
    .4byte  sym_06060F2C
.L_pool_06026318:
    .4byte  sym_06089ED6
.L_pool_0602631C:
    .4byte  sym_06089ED4
.L_06026320:
    mov.w   .L_wpool_06026336, r1
    sub r1, r0
    mov #0xC, r1
    cmp/hs r1, r0
    bt      .L_0602630E
    shll r0
    mov r0, r1
    .word 0xC702
    mov.w @(r0, r1), r0
    braf r0
    nop
.L_wpool_06026336:
    .2byte  0x008A
    .4byte  0xFFC4FFC4
    .4byte  0xFFCEFFCE
    .4byte  0xFFC8FFC8
    .4byte  0xFFC8FFC8
    .4byte  0xFFD2FFD2
    .4byte  0xFFD2FFD2
.L_06026350:
    add #0x1, r5
.L_06026352:
    extu.w r5, r2
    cmp/ge r12, r2
    bf      .L_060262E2
    mov.l @r15+, r10
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06026362
    .type FUN_06026362, @function
FUN_06026362:
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
    .4byte  0xA001624D                      /* bra +2 / extu.w r4, r2 (case A entry) */
    .4byte  0x625DA027                      /* extu.w r5, r2 / bra loop_next (case C entry) */
    .4byte  0x2E21A001                      /* mov.w r2, @r14 [delay] / bra +2 (case B entry) */
    .4byte  0x624D625D                      /* extu.w r4, r2 [delay] / extu.w r5, r2 (case D entry) */
    .4byte  0xA0222721                      /* bra loop_next / mov.w r2, @r7 [delay] */
.L_06026398:
    bra     .L_060263DC
    nop
.L_pool_060263A0:
    .4byte  sym_06060F2C
.L_pool_060263A4:
    .4byte  sym_06060D2A
.L_pool_060263A8:
    .4byte  sym_06060D34
.L_060263A8:
    .4byte  0x00008000
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
    .2byte  0x008A
    .4byte  0xFFC2FFC2
    .4byte  0xFFCCFFCC
    .4byte  0xFFC6FFC6
    .4byte  0xFFC6FFC6
    .4byte  0xFFD0FFD0
    .4byte  0xFFD0FFD0
.L_060263DC:
    add #0x1, r6
    extu.w r6, r2
    cmp/ge r13, r2
    bf      .L_06026376
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
