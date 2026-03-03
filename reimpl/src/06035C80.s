	.text
    .global smpc_cmd_helper_c
smpc_cmd_helper_c:
    sts.l pr, @-r15
    mov.w   .L_06035CA6, r4
    .byte   0xBF, 0xF3    /* bsr sym_06035C6E (hirq_write: writes r4 to CD HIRQ register) */
    nop
    mov #0x0, r2
    mov.l   .L_06035CA8, r3
    lds.l @r15+, pr
    rts
    mov.w r2, @r3

    .global sym_06035C92
sym_06035C92:
    extu.w r4, r4
    mov.l   .L_06035CA8, r3
    mov.l   .L_06035CA8, r2
    mov.w @r3, r3
    or r4, r3
    rts
    mov.w r3, @r2
    .long  0xD002000B
    .short  0x6001
.L_06035CA6:
    .short  0x0BE1
.L_06035CA8:
    .long  sym_06063590
    .long  0x2589000C
    .long  0xD30A000B
    .long  0x2341D00A
    .long  0x000B0009
