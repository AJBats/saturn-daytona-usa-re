
    .section .text.FUN_06035C80


    .global smpc_cmd_helper_c
    .type smpc_cmd_helper_c, @function
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
    .4byte  0xD002000B
    .2byte  0x6001
.L_06035CA6:
    .2byte  0x0BE1                          /* [HIGH] HIRQ clear mask — bits 0,5-7,9-11 of CD HIRQ */
.L_06035CA8:
    .4byte  sym_06063590                    /* [HIGH] HIRQ status cache word in WRAM — also used by smpc_peripheral_query, smpc_cmd_helper_b */
    .4byte  0x2589000C
    .4byte  0xD30A000B
    .4byte  0x2341D00A
    .4byte  0x000B0009
