
    .section .text.FUN_0603B392


    .global FUN_0603B392
    .type FUN_0603B392, @function
FUN_0603B392:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r2
    mov #0x12, r0
    mov.b @(r0, r2), r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0603B3BC
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #0x1, r0
    .4byte  sym_0603F9DA
    .4byte  sym_0603EF54
    .4byte  FUN_0603FA1A
.L_0603B3BC:
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xE300
    .2byte  0xE012
