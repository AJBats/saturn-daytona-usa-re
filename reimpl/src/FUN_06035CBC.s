
    .section .text.FUN_06035CBC


    .global FUN_06035CBC
    .type FUN_06035CBC, @function
FUN_06035CBC:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov r5, r12
    add #-0x4, r15
    mov.l   .L_pool_06035CE4, r13
    mov.l   .L_pool_06035CE8, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06035CEC
    bra     .L_06035D16
    mov r4, r0
    .4byte  0x2589000C
    .4byte  0x25818028
.L_pool_06035CE4:
    .4byte  0x25898000
.L_pool_06035CE8:
    .4byte  FUN_06034C68
.L_06035CEC:
    mov r12, r4
    cmp/pl r14
    bf/s    .L_06035D00
    mov #0x0, r5
.L_06035CF4:
    mov.w @r13, r2
    add #0x1, r5
    mov.w r2, @r4
    cmp/ge r14, r5
    bf/s    .L_06035CF4
    add #0x2, r4
.L_06035D00:
    .byte   0xD3, 0x22    /* mov.l .L_pool_06035D8C, r3 */
    jsr @r3
    mov r15, r4
    mov r0, r4
    tst r4, r4
    bf      .L_06035D14
    mov.l @r15, r3
    cmp/eq r3, r14
    bt      .L_06035D14
    mov #-0x7, r4
.L_06035D14:
    mov r4, r0
.L_06035D16:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06035D22
    .type FUN_06035D22, @function
FUN_06035D22:
    mov.l r14, @-r15
    sts.l pr, @-r15
    stc sr, r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov r0, r14
    stc sr, r0
    .byte   0x93, 0x29    /* mov.w .L_wpool_06035D88, r3 */
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    bsr     FUN_06035D5A
    nop
    mov r0, r4
    mov r14, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r2
    .byte   0x93, 0x1D    /* mov.w .L_wpool_06035D88, r3 */
    and r3, r2
    or r2, r0
    ldc r0, sr
    mov r4, r0
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global FUN_06035D5A
    .type FUN_06035D5A, @function
FUN_06035D5A:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r5, r13
    mov.l r12, @-r15
    mov r4, r12
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15

    mov.l   .L_06035D90, r14
    mov.l   .L_06035D94, r3
    mov.w @r14, r2
    mov.w @r3, r3
    extu.w r3, r3
    or r3, r2
    mov.w r2, @r14

    mov.w @r14, r3
    extu.w r3, r3
    and r12, r3
    cmp/eq r12, r3
    bt/s    .L_06035D98
    mov r6, r11
    bra     .L_06035DF2
    mov #-0x1, r0

    .4byte  0xFF0FFFFF
    .4byte  FUN_06034CC8
.L_06035D90:
    .4byte  sym_06063590
.L_06035D94:
    .4byte  0x25890008

.L_06035D98:
    mov.w @r14, r0
    extu.w r0, r0
    tst #0x1, r0
    bf      .L_06035DA4
    bra     .L_06035DF2
    mov #-0x2, r0

.L_06035DA4:
    mov #0x1, r4
    or r12, r4
    not r4, r4
    .byte   0xBF, 0x60    /* bsr sym_06035C6E (FUN_06035C54: write HIRQ) */
    extu.w r4, r4

    mov #-0x2, r2
    mov.w @r14, r3
    and r2, r3
    mov.w r3, @r14

    .reloc ., R_SH_IND12W, FUN_06035E3C - 4
    .2byte 0xB000    /* bsr FUN_06035E3C (linker-resolved) */
    mov r13, r4

    mov r15, r5
    .byte   0xB0, 0x20    /* bsr FUN_06035E00 (poll HIRQ for response) */
    mov #0x1, r4

    mov r0, r13
    tst r13, r13
    bt      .L_06035DCA
    bra     .L_06035DF2
    mov r13, r0

.L_06035DCA:
    .byte   0xB0, 0x48    /* bsr sym_06035E5E (read CD command registers into buffer) */
    mov r11, r4

    mov.b @r11, r4
    .byte   0x93, 0x27    /* mov.w .L_wpool_06035E22, r3 */
    extu.b r4, r2
    cmp/eq r3, r2
    bf      .L_06035DDC
    bra     .L_06035DE4
    mov #-0x5, r13

.L_06035DDC:
    extu.b r4, r0
    tst #0x80, r0
    bt      .L_06035DE4
    mov #-0x6, r13

.L_06035DE4:
    tst r13, r13
    bf      .L_06035DF0
    not r12, r12
    mov.w @r14, r3
    and r12, r3
    mov.w r3, @r14

.L_06035DF0:
    mov r13, r0
.L_06035DF2:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
