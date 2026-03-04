
    .section .text.FUN_0601AF8C


    .global replay_init_stub
    .type replay_init_stub, @function
replay_init_stub:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, course_state_setup - 4
    .2byte 0xB000    /* bsr course_state_setup (linker-resolved) */
    nop
    mov #0x14, r2
    .byte   0xD3, 0x0C    /* mov.l .L_pool_0601AFC8, r3 */
    mov.b r2, @r3
    .byte   0xD4, 0x0C    /* mov.l .L_pool_0601AFCC, r4 */
    lds.l @r15+, pr
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4
