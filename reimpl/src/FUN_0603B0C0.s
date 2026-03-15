
    .section .text.FUN_0603B0C0


    .global FUN_0603B0C0
    .type FUN_0603B0C0, @function
FUN_0603B0C0:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l r4, @r15
    mov.l r5, @(4, r15)
    mov.l @r15, r14
    mov.l @r14, r14
    mov.b @(r0, r14), r14
    extu.b r14, r14
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov #0x8, r2
    and r14, r2
    tst r2, r2
    bt      .L_0603B0F8
    bra     .L_0603B0E2
    nop
.L_0603B0E2:
    mov #0x4, r2
    and r14, r2
    tst r2, r2
    bt      .L_0603B0F8
    bra     .L_0603B0EE
    nop
.L_0603B0EE:
    mov #0x0, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0603B0F8:
    mov.l @r15, r4
    mov.l @(4, r15), r1
    mov.l @r4, r4
    mov.l @(12, r4), r3
    add r3, r1
    mov r3, r0
    mov.l   .L_pool_0603B114, r3
    jsr @r3
    add #-0x1, r1
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_0603B114:
    .4byte  FUN_06035F44
