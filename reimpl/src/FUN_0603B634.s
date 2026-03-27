
    .section .text.FUN_0603B634


    .global FUN_0603B634
    .type FUN_0603B634, @function
FUN_0603B634:
    sts.l pr, @-r15
    mov r4, r14
    mov.l @r14, r0
    mov.b @(r0, r1), r0
    extu.b r0, r0
    tst #0x60, r0
    bf      .L_0603B666
    bra     .L_0603B646
    nop
.L_0603B646:
    .reloc ., R_SH_IND12W, FUN_0603B058 - 4
    .2byte 0xB000    /* bsr FUN_0603B058 (linker-resolved) */
    mov r14, r4
    mov r0, r5
    .byte   0xD3, 0x13    /* mov.l .L_pool_0603B69C, r3 */
    jsr @r3
    mov.l @r14, r4
    tst r0, r0
    bf      .L_0603B65E
    mov #-0x14, r4
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603B65E:
    .byte   0xD2, 0x10    /* mov.l .L_pool_0603B6A0, r2 */
    mov.l @r2, r2
    .byte   0x90, 0x19    /* mov.w .L_wpool_0603B698, r0 */
    mov.l r14, @(r0, r2)
.L_0603B666:
    mov #0x0, r4
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
    .2byte  0xD60C
    .4byte  0x63629012
    .4byte  0x03466362
    .4byte  0x70040356
    .4byte  0xA15EE400


    .global FUN_0603B680
    .type FUN_0603B680, @function
FUN_0603B680:
    sts.l pr, @-r15
    mov r4, r1
    mov.l   .L_0603B6A0, r2
    mov.w   .L_0603B69A, r3
    mov.l @r2, r2
    add r3, r2
    mov.l   .L_0603B6A4, r3
    jsr @r3
    mov #0xC, r0
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x00A8
.L_0603B69A:
    .2byte  0x00B8
    .4byte  FUN_060406B4
.L_0603B6A0:
    .4byte  sym_060A4D14               /* [HIGH] global UI/command state pointer — dereferenced to get struct base */
.L_0603B6A4:
    .4byte  sym_06035168
