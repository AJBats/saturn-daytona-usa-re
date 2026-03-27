
    .section .text.FUN_060170FC


    .global FUN_060170FC
    .type FUN_060170FC, @function
FUN_060170FC:
    sts.l pr, @-r15
    mov #0x0, r6
    mov #0x12, r5
    add #-0x4, r15
    mov.b r4, @r15
    mov.l   .L_pool_06017198, r3
    jsr @r3
    mov r5, r4
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_060172E4 - 4
    .2byte 0xA000    /* bra FUN_060172E4 (linker-resolved) */
    lds.l @r15+, pr


    .global FUN_06017116
    .type FUN_06017116, @function
FUN_06017116:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    mov.l   .L_pool_0601719C, r3
    jsr @r3
    mov #0x12, r4
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_060172E4 - 4
    .2byte 0xA000    /* bra FUN_060172E4 (linker-resolved) */
    lds.l @r15+, pr


    .global FUN_0601712C
    .type FUN_0601712C, @function
FUN_0601712C:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov #0x12, r11
    add #-0x58, r15
    mov r15, r12
    mov.l   .L_pool_060171A0, r13
    mov r15, r1
    mov.l   .L_pool_060171A4, r2
    mov.l   .L_pool_060171A8, r3
    jsr @r3
    mov #0x58, r0
    mov #0x0, r14
.L_0601714A:
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bt      .L_06017182
    extu.b r14, r0
    mov r0, r3
    shll2 r0
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r0
    exts.w r0, r0
    mov.b @(r0, r13), r0
    extu.b r0, r0
    add #-0x1, r0
    shll2 r0
    mov.l @(r0, r12), r3
    jsr @r3
    mov r14, r4
.L_06017182:
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r11, r2
    bf      .L_0601714A
    add #0x58, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_06017198:
    .4byte  FUN_06018DDC
.L_pool_0601719C:
    .4byte  sym_06018E1E
.L_pool_060171A0:
    .4byte  sym_06084FC8
.L_pool_060171A4:
    .4byte  sym_0605BC14
.L_pool_060171A8:
    .4byte  sym_06035168
