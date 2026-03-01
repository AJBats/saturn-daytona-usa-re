
    .section .text.FUN_060263EC


    .global transform_heading_alt
    .type transform_heading_alt, @function
transform_heading_alt:
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
    .4byte  0x627D626D                      /* embedded dispatch path bytes */
    .4byte  0xA0262D21                      /* embedded dispatch path bytes */
    .4byte  0xA001627D                      /* embedded dispatch path bytes */
    .4byte  0x626DA021                      /* embedded dispatch path bytes */
    .2byte  0x2E21                          /* embedded dispatch path bytes */
.L_0602643A:
    bra     .L_0602647C
    nop
    .2byte  0xFFFF                          /* alignment padding */
.L_pool_06026440:
    .4byte  sym_0606107C                    /* [HIGH] slot data table B (8-byte stride, 8 slots) */
.L_pool_06026444:
    .4byte  sym_06089ED6                    /* [HIGH] &course_id_a word */
.L_pool_06026448:
    .4byte  sym_06089ED4                    /* [HIGH] &course_id_b word */
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
    .2byte  0x008A                          /* [HIGH] dispatch base: lowest valid render_type */
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
