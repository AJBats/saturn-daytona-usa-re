
    .section .text.FUN_06016C6A


    .global text_color_set
    .type text_color_set, @function
text_color_set:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xDE, 0x0B    /* mov.l .L_pool_06016CA1, r14 */
    .byte   0xB5, 0x5B    /* bsr 0x0601772E (external) */
    mov.b @r14, r4
    mov.b @r14, r2
    add #-0x6, r2
    mov.b r2, @r14
    mov.b @r14, r3
    cmp/pl r3
    bt      .L_still_counting
    .byte   0xB5, 0x53    /* bsr 0x0601772E (external) */
    mov #0x0, r4
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xA3, 0x28    /* bra 0x060172E4 (external) */
    mov.l @r15+, r14
.L_still_counting:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .4byte  sym_06084FC8
.L_pool_06016CA1:
    .4byte  sym_06085F88

    .global loc_06016CA4
loc_06016CA4:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    .byte   0xD1, 0x06    /* mov.l .L_pool_06016CD7, r1 */
    add r1, r3
    mov.b @(0x2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    .byte   0xD2, 0x04    /* mov.l .L_pool_06016CDB, r2 */
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15
    .2byte  0xFFFF
.L_pool_06016CD7:
    .4byte  sym_06084FC8
.L_pool_06016CDB:
    .4byte  sym_0605BB6C
