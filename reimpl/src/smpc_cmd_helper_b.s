
    .section .text.FUN_06035C54


    .global smpc_cmd_helper_b
    .type smpc_cmd_helper_b, @function
smpc_cmd_helper_b:
    sts.l pr, @-r15
    mov.l   .L_cd_hirq, r3
    mov.w @r3, r3
    extu.w r3, r3
    mov.l   .L_pool_hirq_status_cache, r2
    mov.w @r2, r2
    or r3, r2
    mov.l   .L_pool_hirq_status_cache, r3
    mov.w r2, @r3
    mov #0x1, r1
    or r1, r4
    bra     sym_06035C6E
    lds.l @r15+, pr

    .global sym_06035C6E
sym_06035C6E:
    mov.l   .L_cd_hirq, r3
    rts
    mov.w r4, @r3
    .4byte  0x25818000
.L_cd_hirq:
    .4byte  0x25890008                  /* CD HIRQ — interrupt request */
.L_pool_hirq_status_cache:
    .4byte  sym_06063590                /* [MEDIUM] cached HIRQ status word in RAM */
