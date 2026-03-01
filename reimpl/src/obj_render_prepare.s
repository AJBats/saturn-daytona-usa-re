
    .section .text.FUN_06020E3C


    .global obj_render_prepare
    .type obj_render_prepare, @function
obj_render_prepare:
    mov.l   .L_pool_06020E70, r7
    mov #0x10, r6
    mov #0x0, r5
.L_search_loop:
    extu.b r4, r3
    extu.b r5, r2
    mov r2, r1
    shll2 r2
    shll2 r1
    shll2 r1
    shll2 r1
    add r1, r2
    exts.w r2, r2
    add r7, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/eq r2, r3
    bf      .L_no_match
    bra     .L_found
    nop
.L_no_match:
    add #0x1, r5
    extu.b r5, r2
    cmp/ge r6, r2
    bf      .L_search_loop
.L_found:
    rts
    extu.b r5, r0
    .2byte  0xFFFF
.L_pool_06020E70:
    .4byte  sym_0608782C
