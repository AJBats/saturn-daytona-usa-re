
    .section .text.FUN_060365D0


    .global FUN_060365D0
    .type FUN_060365D0, @function
FUN_060365D0:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_pool_06036646, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x52, r3
    extu.w r14, r14
    extu.b r12, r12
    extu.w r13, r13
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.w r0, @(2, r2)
    mov r12, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r13, r0
    mov.w r0, @(6, r3)
    .byte   0xD3, 0x13    /* mov.l .L_pool_06036648, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0603660E
    .type FUN_0603660E, @function
FUN_0603660E:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_pool_06036646, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x53, r3
    mov r15, r5
    mov r15, r4
    add #0x8, r2
    mov.b r3, @r2
    .reloc ., R_SH_IND12W, FUN_06036650 - 4
    .2byte 0xB000    /* bsr FUN_06036650 (linker-resolved) */
    add #0x8, r4
    mov r0, r4
    mov r15, r2
    mov r4, r0
    mov.l @r2, r3
    mov.l   .L_0603664C, r2
    and r2, r3
    mov.l r3, @r14
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_06036646:
    .4byte  FUN_06035E90
    .4byte  FUN_06035EC8
.L_0603664C:
    .4byte  0x00FFFFFF
