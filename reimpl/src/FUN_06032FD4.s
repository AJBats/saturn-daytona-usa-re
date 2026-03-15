
    .section .text.FUN_06032FD4


    .global FUN_06032FD4
    .type FUN_06032FD4, @function
FUN_06032FD4:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_06032FE8, r13
    mov.l @r13, r13
    rts
    nop
    .4byte  sym_06026DBC
.L_pool_06032FE8:
    .4byte  sym_06089EDC
    .4byte  0x00000000
    .4byte  0x00000004
    .4byte  0x00000008
    .4byte  sym_06026E2E
    .4byte  0x0000000C
    .4byte  FUN_06026EDE
    .4byte  0x0000000E
    .4byte  sym_060624C8
    .4byte  FUN_06026F2A
    .4byte  FUN_0600A4AA
    .4byte  sym_06026DF8
    .4byte  0x00000010
    .4byte  FUN_0600A474
