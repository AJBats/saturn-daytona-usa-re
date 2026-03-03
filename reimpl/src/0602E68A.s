
    .section .text.FUN_0602E68A


    .global vdp2_color_bank_sel
    .type vdp2_color_bank_sel, @function
vdp2_color_bank_sel:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    add r0, r7
    cmp/pz r7
    .byte   0x89, 0x13    /* bt 0x0602E6C0 (external) */
    mov r7, r4
    shlr2 r4
    .byte   0xDD, 0x07    /* mov.l .L_pool_0602E6BC, r13 */
