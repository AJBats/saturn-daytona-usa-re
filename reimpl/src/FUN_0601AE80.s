
    .section .text.FUN_0601AE80


    .global FUN_0601AE80
    .type FUN_0601AE80, @function
FUN_0601AE80:
    sts.l pr, @-r15
    mov #0x0, r4
    mov #0x28, r1
    mov.l   .L_pool_0601AED4, r2
    extu.b r4, r3
    extu.b r4, r4
    mov.b r3, @r2
    mov.l   .L_pool_0601AED8, r2
    mov.b r1, @r2
    mov.l   .L_pool_0601AEDC, r2
    mov.b r4, @r2
    mov.l   .L_pool_0601AEE0, r5
    mov.l   .L_pool_0601AEE4, r4
    mov.l   .L_pool_0601AEE8, r2
    jsr @r2
    mov #0x60, r6
    mov.l   .L_pool_0601AEEC, r5
    mov.l   .L_pool_0601AEF0, r4
    mov.l   .L_pool_0601AEE8, r3
    jsr @r3
    mov #0x20, r6
    mov.w   .L_wpool_0601AEC8, r6
    mov.l   .L_pool_0601AEF4, r5
    mov.l   .L_pool_0601AEF8, r4
    mov.l   .L_pool_0601AEFC, r3
    jmp @r3
    lds.l @r15+, pr

    .global sym_0601AEB6
sym_0601AEB6:
    mov.l   .L_pool_0601AEDC, r3
    mov.b @r3, r3
    extu.b r3, r3
    shll2 r3
    mov.l   .L_pool_0601AF00, r2
    add r2, r3
    mov.l @r3, r3
    jmp @r3
    nop
.L_wpool_0601AEC8:
    .2byte  0x0180
    .2byte  0xFFFF
    .4byte  sym_06078868
    .4byte  sym_06078663
.L_pool_0601AED4:
    .4byte  sym_06086010
.L_pool_0601AED8:
    .4byte  sym_0608600F
.L_pool_0601AEDC:
    .4byte  sym_06086011
.L_pool_0601AEE0:
    .4byte  sym_0604866C
.L_pool_0601AEE4:
    .4byte  0x25F006C0
.L_pool_0601AEE8:
    .4byte  FUN_0602761E
.L_pool_0601AEEC:
    .4byte  sym_060485CC
.L_pool_0601AEF0:
    .4byte  0x25F00180
.L_pool_0601AEF4:
    .4byte  sym_0604996C
.L_pool_0601AEF8:
    .4byte  0x25F00000
.L_pool_0601AEFC:
    .4byte  FUN_0602766C
.L_pool_0601AF00:
    .4byte  sym_0605DEC8

    .global FUN_0601AF04
FUN_0601AF04:
    .byte   0xD4, 0x19    /* mov.l .L_pool_0601AF6C, r4 */
    mov.b @r4, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0601AF16
    .byte   0xD5, 0x18    /* mov.l .L_pool_0601AF70, r5 */
    mov.b @r5, r3
    add #0x1, r3
    mov.b r3, @r5
.L_0601AF16:
    mov.b @r4, r2
    add #-0x1, r2
    rts
    mov.b r2, @r4


    .global FUN_0601AF1E
    .type FUN_0601AF1E, @function
FUN_0601AF1E:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x13    /* mov.l .L_0601AF74, r3 */
    mov.l r3, @r15
    mov r3, r7
    mov.w   .L_0601AF6A, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    .byte   0xD3, 0x11    /* mov.l .L_0601AF78, r3 */
    mov.l @r5, r5
    add r3, r7
    .byte   0xD3, 0x11    /* mov.l .L_0601AF7C, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xDE, 0x10    /* mov.l .L_0601AF80, r14 */
    .byte   0xD5, 0x11    /* mov.l .L_0601AF84, r5 */
    .byte   0xD4, 0x11    /* mov.l .L_0601AF88, r4 */
    mov.b @r14, r6
    mov.l @r5, r5
    mov.l @r4, r4
    exts.b r5, r5
    .reloc ., R_SH_IND12W, FUN_0601B09A - 4
    .2byte 0xB000    /* bsr FUN_0601B09A (linker-resolved) */
    exts.b r4, r4
    mov #0xA, r3
    mov.b @r14, r2
    add #0x5, r2
    mov.b r2, @r14
    .byte   0xD2, 0x05    /* mov.l .L_0601AF6C, r2 */
    mov.b r3, @r2
    .byte   0xD4, 0x05    /* mov.l .L_0601AF70, r4 */
    mov.b @r4, r3
    add #0x1, r3
    mov.b r3, @r4
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601AF6A:
    .2byte  0x0096
.L_0601AF6C:
    .4byte  sym_0608600F
.L_0601AF70:
    .4byte  sym_06086011
.L_0601AF74:
    .4byte  sym_060638C8
.L_0601AF78:
    .4byte  0x0000C000
.L_0601AF7C:
    .4byte  sym_06028400
.L_0601AF80:
    .4byte  sym_06086010
.L_0601AF84:
    .4byte  sym_0605AD00
.L_0601AF88:
    .4byte  sym_0607EAD8
