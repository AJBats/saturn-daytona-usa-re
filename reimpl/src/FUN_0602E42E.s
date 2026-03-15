
    .section .text.FUN_0602E42E


    .global FUN_0602E42E
    .type FUN_0602E42E, @function
FUN_0602E42E:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .global FUN_0602E438
FUN_0602E438:
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    rts
    nop
    .2byte  0x0000
    .4byte  FUN_0603226C

    .global sym_0602E450
sym_0602E450:
    mov r0, r14
    mov.w   DAT_0602e460, r1
    mov.w @(r0, r1), r2
    mov #0x0, r1
    cmp/eq r1, r2
    .byte   0x89, 0x02    /* bt 0x0602E462 (external) */
    .reloc ., R_SH_IND12W, FUN_0602D924 - 4
    .2byte 0xA000    /* bra FUN_0602D924 (linker-resolved) */
    nop

    .global DAT_0602e460
DAT_0602e460:
    .2byte  0x0250
