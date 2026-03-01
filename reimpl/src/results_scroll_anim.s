
    .section .text.FUN_06016230


    .global results_scroll_anim
    .type results_scroll_anim, @function
results_scroll_anim:
    sts.l pr, @-r15
    extu.b r4, r13
    shll2 r14
    shll2 r3
    add #-0x4, r15
    shll2 r13
    shll2 r3
    mov.l   .L_pool_slot_data_base, r2
    shll2 r3
    add r3, r14
    exts.w r14, r14
    mov #0x0, r3
    add r2, r14
    mov.l r3, @(44, r14)
    shll r13
    mov.l   .L_pool_scroll_pos_table, r3
    add r3, r13
    mov.w @r13, r2
    shll16 r2
    mov.l r2, @(52, r14)
    mov r13, r3
    add #0x2, r3
    mov.l r3, @r15
    mov.w @r3, r2
    shll16 r2
    mov.l r2, @(16, r14)
    mov.l @r15, r4
    mov.l   .L_pool_abs_diff_fn, r3
    jsr @r3
    mov.w @r4, r4
    shll16 r0
    mov.l r0, @(36, r14)
    mov.w @(6, r13), r0
    mov r0, r2
    shll16 r2
    mov.l r2, @(32, r14)
    mov.b @(2, r14), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    mov.b r0, @(2, r14)
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_slot_data_base:
    .4byte  sym_06084FC8
.L_pool_scroll_pos_table:
    .4byte  sym_0605BAB8
.L_pool_abs_diff_fn:
    .4byte  sym_06035438
