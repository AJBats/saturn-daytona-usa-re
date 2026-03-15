
    .section .text.FUN_06040AF8


    .global FUN_06040AF8
    .type FUN_06040AF8, @function
FUN_06040AF8:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    bsr     .L_06040B32
    mov.l r4, @r15
    mov r0, r14
    tst r14, r14
    bf      .L_06040B12
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06040B12:
    mov.l @r15, r5
    .reloc ., R_SH_IND12W, FUN_06040C10 - 4
    .2byte 0xB000    /* bsr FUN_06040C10 (linker-resolved) */
    mov r14, r4
    mov r0, r4
    tst r4, r4
    bf      .L_06040B28
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06040B28:
    mov r14, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06040B32:
    mov #0x10, r0
