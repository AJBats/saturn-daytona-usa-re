
    .section .text.FUN_06032642


    .global disp_rank_elem_c
    .type disp_rank_elem_c, @function
disp_rank_elem_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x0A    /* mov.l .L_pool_06032674, r13 */
    mov.l @r13, r13
    mov.l @r15+, r7
    dt r7
    .byte   0x8B, 0xD5    /* bf 0x06032600 (external) */
    .byte   0xD0, 0x0C    /* mov.l .L_pool_06032688, r0 */
