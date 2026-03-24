
    .section .text.FUN_06016A60


    .global FUN_06016A60
    .type FUN_06016A60, @function
FUN_06016A60:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    extu.b r14, r3
    mov.l   .L_pool_06016AD8, r13
    mov.l   .L_06016AE8, r5
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(12, r3), r3
    cmp/gt r5, r3
    bf      .L_06016B64
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(16, r4), r2
    mov.l @(4, r4), r3
    add r2, r3
    mov.l r3, @(4, r4)
    extu.b r14, r2
    mov #0x4, r3
    cmp/ge r3, r2
    bt      .L_06016AEC
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(4, r4), r2
    mov.l @(52, r4), r3
    cmp/ge r3, r2
    bf      .L_06016B1C
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    bra     .L_06016B1C
    mov.l r2, @(4, r4)
    .2byte  0xFFFF
.L_pool_06016AD8:
    .4byte  sym_06084FC8
    .4byte  0x000B0000
    .4byte  0x00040000
    .4byte  0x0000C000
.L_06016AE8:
    .4byte  0x00010000
.L_06016AEC:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(4, r4), r2
    mov.l @(52, r4), r3
    cmp/gt r3, r2
    bt      .L_06016B1C
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    mov.l r2, @(4, r4)
.L_06016B1C:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(24, r4), r2
    mov.l @(12, r4), r3
    sub r2, r3
    mov.l r3, @(12, r4)
    mov.l @(36, r4), r2
    mov.l @(24, r4), r3
    sub r2, r3
    mov.l r3, @(24, r4)
    mov r3, r2
    mov.l   .L_06016B94, r3
    cmp/gt r3, r2
    bt      .L_06016B86
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.w   .L_wpool_06016B92, r2
    mov.l r2, @(24, r4)
    mov #0x0, r3
    mov.l r3, @(16, r4)
    bra     .L_06016B86
    nop
.L_06016B64:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l r5, @(12, r4)
    mov #0x0, r2
    mov.l r2, @(36, r4)
    mov r2, r3
    mov.l r2, @(24, r4)
    mov #0x2, r2
    mov r2, r0
    mov.b r0, @(2, r4)
.L_06016B86:
    extu.b r14, r4
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_06016DD8 - 4
    .2byte 0xA000    /* bra FUN_06016DD8 (linker-resolved) */
    mov.l @r15+, r14

    .global FUN_06016B8E
FUN_06016B8E:
    rts
    nop
.L_wpool_06016B92:
    .2byte  0x0600
.L_06016B94:
    .4byte  0x00020000

    .global FUN_06016B98
FUN_06016B98:
    mov.l   .L_pool_06016C34, r6
    extu.b r4, r5
    mov #0x41, r0
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r6, r5
    mov.b @(r0, r5), r2
    add #-0x1, r2
    mov.b r2, @(r0, r5)
    mov.b @(r0, r5), r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_06016BD4
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r6, r4
    mov #0x7, r2
    mov r2, r0
    mov.b r0, @(2, r4)
.L_06016BD4:
    rts
    nop

    .global FUN_06016BD8
FUN_06016BD8:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l   .L_pool_06016C34, r1
    add r1, r3
    mov.b @(2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    mov.l   .L_pool_06016C38, r2
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15

    .global FUN_06016C06
FUN_06016C06:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    mov.l   .L_pool_06016C34, r1
    add r1, r3
    mov.b @(2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    mov.l   .L_pool_06016C3C, r2
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15
.L_pool_06016C34:
    .4byte  sym_06084FC8
.L_pool_06016C38:
    .4byte  sym_0605BB1C
.L_pool_06016C3C:
    .4byte  sym_0605BB48

    .global FUN_06016C40
FUN_06016C40:
    extu.b r4, r5
    mov #0x1, r0
    .byte   0xD2, 0x15    /* mov.l pool@0x06016C9C (external: text_obj_array base), r2 */
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    mov #0x27, r3
    add r2, r5
    mov.b r0, @(1, r5)
    .byte   0xD2, 0x11    /* mov.l pool@0x06016CA0 (external: global entry-counter ptr), r2 */
    mov.b r3, @r2
    mov.b @(2, r5), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    rts
    mov.b r0, @(2, r5)


    .global FUN_06016C6A
    .type FUN_06016C6A, @function
FUN_06016C6A:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xDE, 0x0B    /* mov.l .L_pool_06016CA1, r14 */
    .reloc ., R_SH_IND12W, FUN_0601772E - 4
    .2byte 0xB000    /* bsr FUN_0601772E (linker-resolved) */
    mov.b @r14, r4
    mov.b @r14, r2
    add #-0x6, r2
    mov.b r2, @r14
    mov.b @r14, r3
    cmp/pl r3
    bt      .L_06016C94
    .reloc ., R_SH_IND12W, FUN_0601772E - 4
    .2byte 0xB000    /* bsr FUN_0601772E (linker-resolved) */
    mov #0x0, r4
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_060172E4 - 4
    .2byte 0xA000    /* bra FUN_060172E4 (linker-resolved) */
    mov.l @r15+, r14
.L_06016C94:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .4byte  sym_06084FC8
.L_pool_06016CA1:
    .4byte  sym_06085F88

    .global FUN_06016CA4
FUN_06016CA4:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    .byte   0xD1, 0x06    /* mov.l .L_pool_06016CD7, r1 */
    add r1, r3
    mov.b @(0x2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    .byte   0xD2, 0x04    /* mov.l .L_pool_06016CDB, r2 */
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15
    .2byte  0xFFFF
.L_pool_06016CD7:
    .4byte  sym_06084FC8
.L_pool_06016CDB:
    .4byte  sym_0605BB6C
