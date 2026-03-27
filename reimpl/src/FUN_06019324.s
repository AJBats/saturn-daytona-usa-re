
    .section .text.FUN_06019324


    .global FUN_06019324
    .type FUN_06019324, @function
FUN_06019324:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x13    /* mov.l .L_pool_06019378, r14 */
    .byte   0x94, 0x23    /* mov.w .L_wpool_06019374, r4 */
    jsr @r14
    mov #0x1, r5
    mov #0x4, r5
    jsr @r14
    mov r5, r4
    mov #0x5, r5
    jsr @r14
    mov #0x8, r4
    mov #0x6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x7, r5
    jsr @r14
    mov #0x20, r4
    mov #0x0, r5
    jsr @r14
    mov #0x1, r4
    mov.l   .L_0601937C, r4
    .byte   0xD3, 0x0B    /* mov.l .L_pool_06019380, r3 */
    mov.l @r4, r2
    or r3, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_0601935E
    .type FUN_0601935E, @function
FUN_0601935E:
    sts.l pr, @-r15
    mov.l   .L_0601937C, r4
    mov.l   .L_06019384, r3
    mov.l @r4, r2
    or r3, r2
    mov.l   .L_06019388, r3
    jsr @r3
    mov.l r2, @r4
    mov.l   .L_06019388, r3
    jmp @r3
    lds.l @r15+, pr
    .4byte  0x0100FFFF
    .4byte  FUN_06038BD4
.L_0601937C:
    .4byte  sym_0605B6D8
    .4byte  0x40000000
.L_06019384:
    .4byte  0x80000000
.L_06019388:
    .4byte  sym_06026CE0
