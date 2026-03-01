
    .section .text.FUN_06033240


    .global results_full_render
    .type results_full_render, @function
results_full_render:
    sts.l pr, @-r15
    bsr     place_result_cell
    nop
    lds.l @r15+, pr
    mov.l   .L_fp_one, r4
    add r4, r1
    add #-0x1, r7
    cmp/pl r7
    .byte   0x89, 0xEA    /* bt 0x06033228 (external) */ ! if yes, branch back to outer loop in caller
    mov.l   .L_pool_06033276, r0
    add r0, r1
    mov.l   .L_fp_one, r0
    add r0, r2
    add #-0x1, r6
    cmp/pl r6
    .byte   0x89, 0xE2    /* bt 0x06033226 (external) */ ! if yes, branch back to inner loop in caller
    mov.l @r15+, r7
    mov.l @r15+, r6
    rts
    nop

    .4byte  0x00030000                   /* 3.0 (16.16 fixed-point) — unused padding / alignment */
    .4byte  sym_0603390C                 /* pointer to display element descriptor table */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_pool_06033276:
    .4byte  0xFFF80000                   /* -8.0 (16.16 fixed-point) — X row-reset delta */

place_result_cell:
    mov.l r0, @-r15
    mov.l r1, @-r15
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov #0x0, r0
    cmp/eq r0, r5
    bt      .ret_restore
    mov.l   .L_pool_06033312, r0
    mov.l   .L_pool_06033316, r3
    add r0, r1
    add r3, r2
    mov.l   .L_fp_four, r0
    cmp/gt r1, r0
    bt      .ret_restore
    cmp/gt r2, r0
    bt      .ret_restore
    mov.l   .L_pool_0603331E, r0
    cmp/gt r0, r1
    bt      .ret_restore
    mov.l   .L_pool_06033322, r0
    cmp/gt r0, r2
    bt      .ret_restore
    mov.l   .L_fp_half, r0
    mov.l   .L_fp_one_b, r3
    tst r0, r2
    bt      .y_no_round
    add r3, r2
.y_no_round:
    tst r0, r1
    bt      .x_no_round
    add r3, r1
.x_no_round:
    shlr16 r2
    shlr16 r1
    exts.w r2, r2
    exts.w r1, r1

    mov r2, r0
    and #0xF8, r0
    shll2 r0
    mov r0, r3
    shll r0
    shll2 r0
    add r0, r3
    mov r2, r0
    and #0x7, r0
    shll2 r0
    add r0, r3

    mov r1, r0
    and #0xF8, r0
    shll2 r0
    mov r0, r4
    mov r1, r0
    and #0x7, r0
    shlr r0
    add r0, r4
    add r4, r3

    mov.l   .L_pool_0603332E, r4
    add r3, r4
    mov.b @r4, r0
    mov.l r4, @-r15

    mov #-0x10, r2
    mov #0x1, r4
    tst r4, r1
    bf      .odd_x
    mov #0xF, r2
    shll2 r5
    shll2 r5
.odd_x:
    and r2, r0
    or r5, r0
    mov.l @r15+, r4
    mov.b r0, @r4
.ret_restore:
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @r15+, r1
    mov.l @r15+, r0
    rts
    nop

    .2byte  0x0000                       /* alignment padding */
.L_pool_06033312:
    .4byte  0x00240000                   /* 36.0 (16.16) — results grid X origin offset */
.L_pool_06033316:
    .4byte  0x001C0000                   /* 28.0 (16.16) — results grid Y origin offset */
.L_fp_four:
    .4byte  0x00040000                  /* 4.0 (16.16 fixed-point) */
.L_pool_0603331E:
    .4byte  0x00460000                   /* 70.0 (16.16) — results grid right clip boundary */
.L_pool_06033322:
    .4byte  0x00360000                   /* 54.0 (16.16) — results grid bottom clip boundary */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_fp_one_b:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_pool_0603332E:
    .4byte  sym_060629AC                 /* base address of results colour cell table */
    .4byte  0xD505D406                   /* trailing data (after cell table ptr — not code) */
    .4byte  0x9606D006                   /* trailing data */
