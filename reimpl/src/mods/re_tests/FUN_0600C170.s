
    .section .text.FUN_0600C170


    .global FUN_0600C170
    .type FUN_0600C170, @function
FUN_0600C170:
    sts.l pr, @-r15
    mov.l   .L_0600C1B0, r3
    jsr @r3
    nop
    mov.l   .L_0600C1B4, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600C1B8
    .reloc ., R_SH_IND12W, FUN_0600B340 - 4
    .2byte 0xB000    /* bsr FUN_0600B340 (linker-resolved) */
    nop
    bra     .L_0600C1BE
    nop
    .4byte  FUN_0600C170
    .4byte  sym_06063574
    .4byte  0x0000FFFF
    .4byte  0x21000000
    .4byte  0x02800008
    .4byte  FUN_060058FA
    .4byte  FUN_06006868
    .4byte  0x02000000
    .4byte  FUN_0601BDEC
    .4byte  sym_0607EA98
.L_0600C1B0:
    .4byte  sym_0603C000
.L_0600C1B4:
    .4byte  sym_06083255
.L_0600C1B8:
    mov.l   .L_0600C1F4, r3
    jsr @r3
    nop
.L_0600C1BE:
    nop                    /* RE_TEST 6b: NOP'd BSR to FUN_0600B914 (loop B) */
    nop                    /* RE_TEST 6b: was delay slot */
    mov.l   .L_0600C1F8, r0
    mov.l   .L_0600C1FC, r3
    mov.l @r0, r0
    mov.l @r3, r3
    add r3, r0
    cmp/eq #0x8, r0
    bf      .L_0600C1DA
    mov.l   .L_0600C200, r3
    jsr @r3
    nop
    bra     .L_0600C1E0
    nop
.L_0600C1DA:
    mov.l   .L_0600C204, r3
    jsr @r3
    nop
.L_0600C1E0:
    mov.l   .L_0600C208, r2
    mov.l   .L_0600C20C, r3
    mov.l @r2, r2
    mov.l r2, @r3
    mov.l   .L_0600C210, r2
    mov.l   .L_0600C214, r3
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
    .2byte  0xFFFF
.L_0600C1F4:
    .4byte  FUN_0600AFB2
.L_0600C1F8:
    .4byte  sym_06063E1C
.L_0600C1FC:
    .4byte  sym_06063E20
.L_0600C200:
    .4byte  FUN_06006A9C
.L_0600C204:
    .4byte  FUN_06006CDC
.L_0600C208:
    .4byte  sym_06059F40
.L_0600C20C:
    .4byte  sym_06059F4C
.L_0600C210:
    .4byte  0x0000FFFF
.L_0600C214:
    .4byte  0x21800000
