
    .section .text.FUN_06017372


    .global vdp2_data_lookup
    .type vdp2_data_lookup, @function
vdp2_data_lookup:
    .byte   0xD7, 0x0D    /* mov.l .L_pool_060173A9, r7 */
    mov #0x12, r6
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
    bra     .L_return
    nop
.L_no_match:
    add #0x1, r5
    extu.b r5, r2
    cmp/ge r6, r2
    bf      .L_search_loop
.L_return:
    rts
    extu.b r5, r0
    .4byte  sym_06085490
.L_pool_060173A9:
    .4byte  sym_06084FC8
