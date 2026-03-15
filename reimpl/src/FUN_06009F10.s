
    .section .text.FUN_06009F10


    .global FUN_06009F10
    .type FUN_06009F10, @function
FUN_06009F10:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0600A294 - 4
    .2byte 0xB000    /* bsr FUN_0600A294 (linker-resolved) */
    nop
    mov.l   .L_06009FB0, r4
    mov.l @r4, r2
    add #-0x1, r2
    mov.l r2, @r4
    mov r2, r3
    cmp/pz r3
    bt      .L_06009F52
    mov.l   .L_06009FB4, r4
    mov.l   .L_06009FB8, r2
    mov.w   .L_06009FAC, r0
    mov.l @r4, r3
    mov.b @r2, r2
    mov.l r2, @(r0, r3)
    add #0x1C, r0
    mov.l @r4, r3
    mov.l   .L_06009FBC, r2
    mov.l @r2, r2
    mov.l r2, @(r0, r3)
    mov.l   .L_06009FC0, r3
    mov.l   .L_06009FC4, r2
    mov.l @r3, r3
    mov.l r3, @r2
    mov #0x18, r3
    mov.l   .L_06009FC8, r2
    mov.l r3, @r2
    mov #0x3, r3
    mov.l   .L_06009FCC, r2
    lds.l @r15+, pr
    rts
    mov.w r3, @r2
.L_06009F52:
    mov.l   .L_06009FD0, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_06009F60
    mov.l   .L_06009FD4, r3
    jsr @r3
    nop
.L_06009F60:
    mov.l   .L_06009FD8, r3
    jsr @r3
    nop
    mov.l   .L_06009FCC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x3, r0
    bt      .L_06009F9A
    mov.l   .L_06009FDC, r3
    add #0x1, r3
    mov.b @r3, r0
    and #0x7F, r0
    or #0x80, r0
    mov.b r0, @r3
    mov.l   .L_06009FE0, r3
    jsr @r3
    nop
    mov.l   .L_06009FE4, r3
    jsr @r3
    nop
    mov.l   .L_06009FE8, r3
    jsr @r3
    nop
    mov.l   .L_06009FEC, r3
    jsr @r3
    nop
    mov.l   .L_06009FF0, r3
    jmp @r3
    lds.l @r15+, pr
.L_06009F9A:
    mov #0x0, r2
    mov.l   .L_06009FF4, r3
    mov.l r2, @r3
    mov.l   .L_06009FF8, r3
    jmp @r3
    lds.l @r15+, pr
    .2byte  0x4F26
    .4byte  0x000B0009
.L_06009FAC:
    .2byte  0x0224
    .2byte  0xFFFF
.L_06009FB0:
    .4byte  sym_0607EBCC
.L_06009FB4:
    .4byte  sym_0607E944
.L_06009FB8:
    .4byte  sym_06078637
.L_06009FBC:
    .4byte  sym_06078638
.L_06009FC0:
    .4byte  sym_0607863C
.L_06009FC4:
    .4byte  sym_060786A4
.L_06009FC8:
    .4byte  FUN_0605ACC4
.L_06009FCC:
    .4byte  sym_06087804
.L_06009FD0:
    .4byte  sym_0607EAD8
.L_06009FD4:
    .4byte  FUN_06033EA8
.L_06009FD8:
    .4byte  FUN_0601FD74
.L_06009FDC:
    .4byte  sym_06078900
.L_06009FE0:
    .4byte  FUN_0600DE40
.L_06009FE4:
    .4byte  FUN_0600A914
.L_06009FE8:
    .4byte  FUN_060055BC
.L_06009FEC:
    .4byte  FUN_0600BFFC
.L_06009FF0:
    .4byte  FUN_060078DC
.L_06009FF4:
    .4byte  sym_0605A00C
.L_06009FF8:
    .4byte  sym_06026CE0
