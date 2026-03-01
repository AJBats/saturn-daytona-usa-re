
    .section .text.FUN_06020430


    .global obj_init_defaults
    .type obj_init_defaults, @function
obj_init_defaults:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.w   .L_w_tex_data_const, r10
    mov.l   .L_pool_obj_table, r12
    mov.b r4, @r15
    mov r12, r11
    mov r12, r9
    mov.l r7, @(4, r15)
    add #0x4, r11
    mov.l r6, @(8, r15)
    mov.b @r15, r3
    cmp/pl r3
    bf/s    .L_epilogue
    add #0x6, r9
.L_loop_top:
    extu.b r13, r0
    mov.l @(4, r15), r3
    shll r0
    mov.w @(r0, r3), r4
    extu.b r4, r4
    extu.b r4, r0
    cmp/eq #0x20, r0
    bf      .L_compute_index
    extu.w r14, r3
    mov.w r3, @r11
    extu.w r14, r2
    bra     .L_call_loader
    mov.w r2, @r9
.L_compute_index:
    extu.b r4, r5
    add #-0x40, r5
    shll r5
    extu.w r5, r3
    mov.w r3, @r11
    add #0x1, r5
    extu.w r5, r5
    mov.w r5, @r9
.L_call_loader:
    mov r10, r7
    extu.w r8, r6
    mov r12, r5
    mov.l   .L_pool_dlist_loader, r2
    mov.l @(8, r15), r3
    add r3, r6
    shll r6
    jsr @r2
    mov #0x8, r4
    add #0x1, r13
    mov.b @r15, r2
    extu.b r13, r3
    cmp/ge r2, r3
    bf/s    .L_loop_top
    add #0x1, r8
.L_epilogue:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_w_tex_data_const:
    .2byte  0x3C79                     /* [MEDIUM] texture data constant */
    .2byte  0xFFFF
.L_pool_obj_table:
    .4byte  sym_0605F44E               /* [HIGH] object display list base table */
.L_pool_dlist_loader:
    .4byte  sym_06028400               /* [HIGH] display_list_loader function */
