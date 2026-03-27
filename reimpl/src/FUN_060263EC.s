
    .section .text.FUN_060263EC


    .global FUN_060263EC
    .type FUN_060263EC, @function
FUN_060263EC:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r10, @-r15
    mov.l   .L_pool_06026440, r10
    mov #0x8, r12
    mov.l   .L_pool_06026444, r13
    mov.l   .L_pool_06026448, r14
    mov #0x1, r7
    mov #0x2, r6
    mov #0x0, r0
    extu.w r0, r3
    mov.w r3, @r13
    extu.w r0, r2
    mov.w r2, @r14
    bra     .L_0602647E
    extu.w r0, r5
.L_0602640E:
    extu.w r5, r2
    cmp/eq r4, r2
    bf      .L_06026418
    bra     .L_0602647C
    nop
.L_06026418:
    extu.w r5, r0
    shll2 r0
    shll r0
    add r10, r0
    mov.w @(6, r0), r0
    bra     .L_0602644C
    extu.w r0, r0
    .2byte  0xA001                          /* branch instruction embedded in stream (not executed inline) */
    .4byte  0x627D626D
    .4byte  0xA0262D21
    .4byte  0xA001627D
    .4byte  0x626DA021
    .2byte  0x2E21
.L_0602643A:
    bra     .L_0602647C
    nop
    .2byte  0xFFFF
.L_pool_06026440:
    .4byte  sym_0606107C
.L_pool_06026444:
    .4byte  sym_06089ED6
.L_pool_06026448:
    .4byte  sym_06089ED4
.L_0602644C:
    mov.w   .L_wpool_06026462, r1
    sub r1, r0
    mov #0xC, r1
    cmp/hs r1, r0
    bt      .L_0602643A
    shll r0
    mov r0, r1
    .word 0xC702
    mov.w @(r0, r1), r0
    braf r0
    nop
.L_wpool_06026462:
    .2byte  0x008A
    .4byte  0xFFC4FFC4                      /* dispatch offsets for render_type 0x008A and 0x008C */
    .4byte  0xFFCEFFCE                      /* dispatch offsets for render_type 0x008E and 0x0090 */
    .4byte  0xFFC8FFC8                      /* dispatch offsets for render_type 0x0092 and 0x0094 */
    .4byte  0xFFC8FFC8                      /* dispatch offsets for render_type 0x0096 and 0x0098 */
    .4byte  0xFFD2FFD2                      /* dispatch offsets for render_type 0x009A and 0x009C */
    .4byte  0xFFD2FFD2                      /* dispatch offsets for render_type 0x009E and 0x00A0 */
.L_0602647C:
    add #0x1, r5
.L_0602647E:
    extu.w r5, r2
    cmp/ge r12, r2
    bf      .L_0602640E
    mov.l @r15+, r10
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0602648E
    .type FUN_0602648E, @function
FUN_0602648E:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_pool_060264CC, r12
    mov #0x8, r13
    mov.l   .L_pool_060264D0, r14
    mov.l   .L_pool_060264D4, r7
    mov.l   .L_pool_060264D8, r5
    mov #0x0, r4
    extu.w r4, r6
.L_060264A2:
    extu.w r6, r0
    shll2 r0
    shll r0
    add r12, r0
    mov.w @(6, r0), r0
    bra     .L_060264D8
    extu.w r0, r0
    .4byte  0xA001624D
    .4byte  0x625DA027
    .4byte  0x2E21A001
    .4byte  0x624D625D
    .4byte  0xA0222721
.L_060264C4:
    bra     .L_06026508
    nop
.L_pool_060264CC:
    .4byte  sym_0606107C
.L_pool_060264D0:
    .4byte  sym_06060D2A
.L_pool_060264D4:
    .4byte  sym_06060D34
.L_pool_060264D8:
    .4byte  0x00008000
.L_060264D8:
    mov.w   .L_wpool_060264F2, r1
    sub r1, r0
    mov #0xC, r1
    cmp/hs r1, r0
    bt      .L_060264C4
    shll r0
    mov r0, r1
    .word 0xC702
    mov.w @(r0, r1), r0
    braf r0
    nop
.L_wpool_060264F2:
    .2byte  0x008A
    .4byte  0xFFC2FFC2                      /* dispatch offsets for render_type 0x008A and 0x008B */
    .4byte  0xFFCCFFCC                      /* dispatch offsets for render_type 0x008C and 0x008D */
    .4byte  0xFFC6FFC6                      /* dispatch offsets for render_type 0x008E and 0x008F */
    .4byte  0xFFC6FFC6                      /* dispatch offsets for render_type 0x0090 and 0x0091 */
    .4byte  0xFFD0FFD0                      /* dispatch offsets for render_type 0x0092 and 0x0093 */
    .4byte  0xFFD0FFD0                      /* dispatch offsets for render_type 0x0094 and 0x0095 */
.L_06026508:
    add #0x1, r6
    extu.w r6, r2
    cmp/ge r13, r2
    bf      .L_060264A2
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
