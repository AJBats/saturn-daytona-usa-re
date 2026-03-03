	.text
    .global disc_sector_read
disc_sector_read:
    sts.l pr, @-r15
    mov #0x30, r14
    mov.l   .L_0601B064, r3
    mov r14, r6
    mov r14, r5
    mov.l r14, @r3
    mov.w   .L_0601B05E, r2
    mov.l r2, @-r15
    mov.w   .L_0601B060, r3
    extu.w r14, r2
    mov.l r3, @-r15
    mov #0x1, r3
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l   .L_0601B068, r3
    jsr @r3
    mov r7, r4
    .byte   0xB0, 0x47    /* bsr 0x0601B0D8 (external) */
    add #0x10, r15
    mov #0x14, r2
    mov.l   .L_0601B070, r3
    mov.b r2, @r3
    mov.l   .L_0601B06C, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601B05E:
    .short  0x00A7
.L_0601B060:
    .short  0x0160
    .short  0xFFFF
.L_0601B064:
    .long  sym_06086014
.L_0601B068:
    .long  color_transform_calc
.L_0601B06C:
    .long  sym_06086011
.L_0601B070:
    .long  sym_0608600F
