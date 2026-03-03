
    .section .text.FUN_0600EB14


    .global race_init_master
    .type race_init_master, @function
race_init_master:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r14
    mov.w   DAT_0600ebd8, r6
    mov.l   .L_0600EBDC, r4
    mov r14, r5
.L_0600EB20:
    mov.l r14, @r4
    add #0x1, r5
    cmp/hs r6, r5
    bf/s    .L_0600EB20
    add #0x4, r4
    mov.l   .L_0600EBE0, r3
    jsr @r3
    nop
    mov.l   .L_0600EBE4, r3
    jsr @r3
    nop
    mov.l   .L_0600EBE8, r3
    jsr @r3
    nop
    mov #0x1, r5
    mov.l   .L_0600EBDC, r4
    mov.w   .L_0600EBDA, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    extu.w r14, r3
    mov.l   .L_0600EBEC, r2
    mov.w r3, @r2
    mov.l   .L_0600EBF0, r2
    mov.l r14, @r2
    mov.l   .L_0600EBF4, r2
    mov.l r14, @r2
    mov.l   .L_0600EBF8, r2
    mov.l r14, @r2
    mov.l   .L_0600EBFC, r2
    mov.l r14, @r2
    mov #0x0, r1
    mov.l   .L_0600EC00, r2
    mov.l r1, @r2
    mov #0x5, r1
    mov.l   .L_0600EC04, r2
    mov.b r1, @r2
    mov.l   .L_0600EC08, r2
    mov.l r14, @r2
    mov.l   .L_0600EC0C, r2
    mov.l r14, @r2
    mov.l   .L_0600EC10, r2
    mov.l r14, @r2
    mov.l   .L_0600EC14, r2
    mov.l r14, @r2
    exts.b r14, r1
    mov.l   .L_0600EC18, r2
    mov.b r1, @r2
    exts.b r14, r0
    mov.l   .L_0600EC1C, r2
    mov.b r0, @r2
    mov.l   .L_0600EC20, r3
    mov.l r14, @r3
    mov.l   .L_0600EC24, r3
    mov.l r14, @r3
    mov.l   .L_0600EC28, r3
    mov.b r14, @r3
    mov.l   .L_0600EC2C, r3
    mov.l r14, @r3
    mov.l   .L_0600EC30, r3
    mov.l r14, @r3
    mov #0x0, r1
    mov.l   .L_0600EC34, r3
    mov.l r1, @r3
    extu.w r14, r1
    mov.l   .L_0600EC38, r3
    mov.w r1, @r3
    extu.b r14, r0
    mov.l   .L_0600EC3C, r3
    mov.b r0, @r3
    mov.l   .L_0600EC40, r3
    mov.b r14, @r3
    mov #0x0, r1
    mov.l   .L_0600EC44, r3
    mov.l r1, @r3
    mov.l   .L_0600EC48, r3
    mov.l r14, @r3
    mov.l   .L_0600EC4C, r3
    mov.b r14, @r3
    extu.b r14, r0
    mov.l   .L_0600EC50, r3
    mov.b r0, @r3
    mov.l   .L_0600EC54, r4
    mov.w r14, @r4
    extu.w r14, r0
    mov.w r0, @(2, r4)
    bra     .L_0600EC58
    nop

    .global DAT_0600ebd8
DAT_0600ebd8:
    .2byte  0x1810
.L_0600EBDA:
    .2byte  0x0120
.L_0600EBDC:
    .4byte  sym_06078900
.L_0600EBE0:
    .4byte  sym_06026E02
.L_0600EBE4:
    .4byte  sym_060270C6
.L_0600EBE8:
    .4byte  car_array_init
.L_0600EBEC:
    .4byte  sym_06063F46
.L_0600EBF0:
    .4byte  sym_0607EAE4
.L_0600EBF4:
    .4byte  sym_0607EAE8
.L_0600EBF8:
    .4byte  sym_0607EAEC
.L_0600EBFC:
    .4byte  sym_0607EBD0
.L_0600EC00:
    .4byte  sym_0607EBF4
.L_0600EC04:
    .4byte  sym_06078654
.L_0600EC08:
    .4byte  sym_0605A1C4
.L_0600EC0C:
    .4byte  sym_06082A30
.L_0600EC10:
    .4byte  sym_0607EABC
.L_0600EC14:
    .4byte  sym_0607EAC0
.L_0600EC18:
    .4byte  sym_06083260
.L_0600EC1C:
    .4byte  sym_06082A26
.L_0600EC20:
    .4byte  sym_060788FC
.L_0600EC24:
    .4byte  sym_06082A38
.L_0600EC28:
    .4byte  sym_06083261
.L_0600EC2C:
    .4byte  sym_0608325C
.L_0600EC30:
    .4byte  sym_06083258
.L_0600EC34:
    .4byte  sym_0605A21C
.L_0600EC38:
    .4byte  sym_06086058
.L_0600EC3C:
    .4byte  sym_0608605A
.L_0600EC40:
    .4byte  sym_0605DE3C
.L_0600EC44:
    .4byte  sym_060786A8
.L_0600EC48:
    .4byte  sym_060786BC
.L_0600EC4C:
    .4byte  sym_06085FCC
.L_0600EC50:
    .4byte  sym_06087060
.L_0600EC54:
    .4byte  sym_0602FD98
.L_0600EC58:
    extu.w r14, r0
    mov.w r0, @(4, r4)
    extu.w r14, r0
    mov.w r0, @(6, r4)
    extu.w r14, r0
    mov.l   .L_0600EC70, r3
    jsr @r3
    mov.w r0, @(8, r4)
    lds.l @r15+, pr
    mov.l   .L_0600EC74, r3
    jmp @r3
    mov.l @r15+, r14
.L_0600EC70:
    .4byte  track_obj_placement
.L_0600EC74:
    .4byte  sym_06018634
