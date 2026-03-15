
    .section .text.FUN_060323E4


    .global FUN_060323E4
    .type FUN_060323E4, @function
FUN_060323E4:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_060321C0 - 4
    .2byte 0xB000    /* bsr FUN_060321C0 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    nop

    .global FUN_060323F0
FUN_060323F0:
    extu.b r7, r1
    swap.w r7, r2
    extu.b r2, r2
    mov.l   .L_pool_06032400, r0
    add r14, r0
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    mov.b r1, @(r0, r2)
    .2byte  0x0000
.L_pool_06032400:
    .4byte  0x000002DE

    .global FUN_06032404
FUN_06032404:
    mov.l   .L_pool_06032410, r0
    mov.w @(r0, r14), r1
    or r7, r1
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    mov.w r1, @(r0, r14)
    .2byte  0x0000
.L_pool_06032410:
    .4byte  0x0000000E

    .global FUN_06032414
FUN_06032414:
    mov.l   .L_pool_06032420, r0
    mov.w @(r0, r14), r1
    not r7, r2
    and r2, r1
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    mov.w r1, @(r0, r14)
.L_pool_06032420:
    .4byte  0x0000000E

    .global FUN_06032424
FUN_06032424:
    mov #0x0, r4
    mov r7, r5
    .byte   0xD0, 0x03    /* mov.l .L_pool_06032438, r0 */
