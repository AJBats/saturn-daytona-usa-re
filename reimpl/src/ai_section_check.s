
    .section .text.FUN_0604134E


    .global ai_section_check
    .type ai_section_check, @function
ai_section_check:
    sts.l pr, @-r15
    .byte   0xD3, 0x04    /* mov.l .L_pool_06041365, r3 */
    mov.l @r3, r3
    mov.l @(56, r3), r2
    cmp/eq r5, r2
    bt      .L_06041374
    lds.l @r15+, pr
    rts
    mov #-0x9, r0
    .4byte  0x0338033C
.L_pool_06041365:
    .4byte  sym_060A5400                /* [HIGH] AI/game state base pointer */
    .4byte  cd_block_read_safe       /* [HIGH] fn ptr: AI section transition handler */
    .4byte  ai_checkpoint_section       /* [HIGH] fn ptr: AI checkpoint section processor */
    .4byte  sym_06035C4E                /* [MEDIUM] fn ptr: HIRQ register read utility */
.L_06041374:
    .byte   0xD3, 0x1E    /* mov.l @cross-TU pool (ai_checkpoint_validate), r3 */
    jsr @r3
    nop
    mov #0x0, r0
    lds.l @r15+, pr
    rts
    nop
