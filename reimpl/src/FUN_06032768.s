
    .section .text.FUN_06032768


    .global FUN_06032768
    .type FUN_06032768, @function
FUN_06032768:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    mov.l   .L_pool_060327F8, r0
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    bra     .L_060327FC
    nop
    .2byte  0x0000
    .4byte  sym_06089EDC
    .4byte  sym_060623C8
    .4byte  sym_06026DBC
    .4byte  sym_06026E0C
    .4byte  0x00000010
    .4byte  0x00000014
    .4byte  0x00000018
    .4byte  sym_06026E2E
    .4byte  0x0000001E
    .4byte  FUN_06026EDE
    .4byte  0x0000001C
    .4byte  FUN_06026E94
    .4byte  0x00000020
    .4byte  FUN_06026F2A
    .4byte  0x00000054
    .4byte  0x0000000C
    .4byte  0x00000022
    .4byte  0x00000026
    .4byte  0x00000024
.L_pool_060327F8:
    .4byte  0x00000084
.L_060327FC:
    .byte   0xD0, 0x9D    /* mov.l @cross-TU pool (render pipeline dispatch), r0 */
