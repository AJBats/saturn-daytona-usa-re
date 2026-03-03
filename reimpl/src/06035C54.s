	.text
    .global smpc_cmd_helper_b
smpc_cmd_helper_b:
    sts.l pr, @-r15
    mov.l   .L_06035C78, r3
    mov.w @r3, r3
    extu.w r3, r3
    mov.l   .L_pool_06035C7C, r2
    mov.w @r2, r2
    or r3, r2
    mov.l   .L_pool_06035C7C, r3
    mov.w r2, @r3
    mov #0x1, r1
    or r1, r4
    bra     sym_06035C6E
    lds.l @r15+, pr

    .global sym_06035C6E
sym_06035C6E:
    mov.l   .L_06035C78, r3
    rts
    mov.w r4, @r3
    .long  0x25818000
.L_06035C78:
    .long  0x25890008
.L_pool_06035C7C:
    .long  sym_06063590
