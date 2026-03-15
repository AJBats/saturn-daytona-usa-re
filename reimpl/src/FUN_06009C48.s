
    .section .text.FUN_06009C48


    .global FUN_06009C48
    .type FUN_06009C48, @function
FUN_06009C48:
    sts.l pr, @-r15
    mov.l   .L_06009CB8, r3
    jsr @r3
    nop
    mov.l   .L_06009CBC, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06009C6C
    mov.l   .L_06009CC0, r3
    jsr @r3
    nop
    mov.l   .L_06009CC4, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06009C6C
    mov.l   .L_06009CC8, r3
    jsr @r3
    nop
.L_06009C6C:
    mov.l   .L_06009CCC, r3
    jsr @r3
    nop
    mov.l   .L_06009CD0, r3
    jsr @r3
    nop
    mov.l   .L_06009CD4, r3
    jsr @r3
    nop
    mov.l   .L_06009CD8, r6
    mov.l   .L_06009CDC, r5
    mov.l   .L_06009CE0, r4
    mov.l   .L_06009CE4, r3
    jsr @r3
    mov.l @r6, r6
    mov.l   .L_06009CE8, r3
    jsr @r3
    nop
    mov.l   .L_06009CEC, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06009CA0
    mov.l   .L_06009CF0, r3
    jsr @r3
    nop
.L_06009CA0:
    mov.l   .L_06009CF4, r2
    mov.w   .L_06009CB6, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    cmp/pl r3
    bf      .L_06009CB0
    .reloc ., R_SH_IND12W, FUN_0600A084 - 4
    .2byte 0xB000    /* bsr FUN_0600A084 (linker-resolved) */
    nop
.L_06009CB0:
    mov.l   .L_06009CF8, r3
    jmp @r3
    lds.l @r15+, pr
.L_06009CB6:
    .2byte  0x00BC
.L_06009CB8:
    .4byte  FUN_06014A42
.L_06009CBC:
    .4byte  sym_0607EAE0
.L_06009CC0:
    .4byte  FUN_0601DF88
.L_06009CC4:
    .4byte  sym_0607EAD8
.L_06009CC8:
    .4byte  FUN_0601DBB8
.L_06009CCC:
    .4byte  FUN_0600DF66
.L_06009CD0:
    .4byte  FUN_0600A914
.L_06009CD4:
    .4byte  FUN_0600BB94
.L_06009CD8:
    .4byte  sym_06063E24
.L_06009CDC:
    .4byte  sym_06063EEC
.L_06009CE0:
    .4byte  sym_06063EF8
.L_06009CE4:
    .4byte  FUN_060053AC
.L_06009CE8:
    .4byte  FUN_0600BFFC
.L_06009CEC:
    .4byte  sym_0607ED8C
.L_06009CF0:
    .4byte  sym_060033E6
.L_06009CF4:
    .4byte  sym_0607E944
.L_06009CF8:
    .4byte  FUN_060078DC
