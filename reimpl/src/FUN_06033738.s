
    .section .text.FUN_06033738


    .global FUN_06033738
    .type FUN_06033738, @function
FUN_06033738:
    sts.l pr, @-r15
    jsr @r1
    nop
    lds.l @r15+, pr
    swap.w r0, r1
    exts.w r1, r14
    mov.l @r15+, r1
    .byte   0xD4, 0x26    /* mov.l .L_pool_060337E0, r4 */
    mov.l   sym_06033884, r3
    mov.b @r3, r3
    cmp/pl r3
    bf      .L_06033756
    neg r12, r12
    neg r14, r14
    .byte   0xD4, 0x23    /* mov.l .L_pool_060337E4, r4 */
.L_06033756:
    .byte   0xD0, 0x20    /* mov.l .L_pool_060337D8, r0 */
    add r1, r0
    mov.w @r0+, r1
    mov.w @r0+, r2
    sub r14, r1
    sub r13, r2
    mov r1, r14
    mov r2, r13
    cmp/pl r3
    bf      .L_06033772
    mov.w @r0+, r1
    mov.w @r0, r2
    add r1, r14
    add r2, r13
.L_06033772:
    add r4, r12
    .byte   0xD0, 0x1C    /* mov.l .L_pool_060337E8, r0 */
    and r0, r12
    shlr8 r12
    shlr2 r12
    shlr2 r12
    shll r12
    .byte   0xD1, 0x1A    /* mov.l .L_pool_060337EC, r1 */
    add r12, r1
    mov.b @r1+, r2
    add r11, r2
    mov.b @r1, r0
    mov r10, r4
    mov r14, r5
    mov r13, r6
    mov r14, r7
    mov r13, r8
    mov r14, r9
    mov r13, r10
    mov r14, r11
    mov r13, r12
    add r4, r7
    add r4, r9
    add r4, r10
    add r4, r12
    neg r4, r4
    add r4, r5
    add r4, r11
    add r4, r6
    add r4, r8


    .global FUN_060337AE
    .type FUN_060337AE, @function
FUN_060337AE:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033520 - 4
    .2byte 0xB000    /* bsr FUN_06033520 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0E    /* mov.l .L_pool_060337F0, r4 */
    .byte   0xD5, 0x0E    /* mov.l .L_pool_060337F4, r5 */
    mov.l @r5, r5
    .byte   0xD0, 0x0E    /* mov.l .L_pool_060337F8, r0 */

    .global FUN_060337BE
    .type FUN_060337BE, @function
FUN_060337BE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr

    .global FUN_060337C6
    .type FUN_060337C6, @function
FUN_060337C6:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033504 - 4
    .2byte 0xB000    /* bsr FUN_06033504 (linker-resolved) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r6
    mov.l @r15+, r0
    rts
    nop
    .2byte  0x0000
    .4byte  sym_06033894
    .4byte  FUN_0602755C
    .4byte  0xFFFFC800
    .4byte  0x00004800
    .4byte  0x0000FFFF
    .4byte  sym_06033A8C
    .4byte  sym_06062970
    .4byte  sym_060785FC
    .4byte  sym_060280F8
    .4byte  0x4008D102
    .4byte  0x301C6002
    .4byte  0x402B0009
    .4byte  sym_0603380C

    .global sym_0603380C
sym_0603380C:
    .4byte  FUN_0603381C
    .4byte  FUN_0603382E
    .4byte  FUN_06033840
    .4byte  FUN_06033852

    .global FUN_0603381C
FUN_0603381C:
    mov.w r12, @r4
    mov.w r11, @-r4
    mov.w r10, @-r4
    mov.w r9, @-r4
    mov.w r8, @-r4
    mov.w r7, @-r4
    mov.w r6, @-r4
    rts
    mov.w r5, @-r4

    .global FUN_0603382E
FUN_0603382E:
    mov.w r10, @r4
    mov.w r9, @-r4
    mov.w r8, @-r4
    mov.w r7, @-r4
    mov.w r6, @-r4
    mov.w r5, @-r4
    mov.w r12, @-r4
    rts
    mov.w r11, @-r4

    .global FUN_06033840
FUN_06033840:
    mov.w r8, @r4
    mov.w r7, @-r4
    mov.w r6, @-r4
    mov.w r5, @-r4
    mov.w r12, @-r4
    mov.w r11, @-r4
    mov.w r10, @-r4
    rts
    mov.w r9, @-r4

    .global FUN_06033852
FUN_06033852:
    mov.w r6, @r4
    mov.w r5, @-r4
    mov.w r12, @-r4
    mov.w r11, @-r4
    mov.w r10, @-r4
    mov.w r9, @-r4
    mov.w r8, @-r4
    rts
    mov.w r7, @-r4

    .global sym_06033864
sym_06033864:
    .4byte  sym_0607EAE0

    .global sym_06033868
sym_06033868:
    .4byte  sym_0607EAB8

    .global sym_0603386C
sym_0603386C:
    .4byte  sym_0607EA98

    .global sym_06033870
sym_06033870:
    .4byte  sym_06078900

    .global sym_06033874
sym_06033874:
    .4byte  sym_0607EAD8
    .4byte  sym_06063750

    .global sym_0603387C
sym_0603387C:
    .4byte  sym_0605B734

    .global sym_06033880
sym_06033880:
    .4byte  sym_06078635

    .global sym_06033884
sym_06033884:
    .4byte  sym_06078663
    .4byte  g_pad_state
    .4byte  sym_0605D240
    .4byte  sym_06085FF4

    .global sym_06033894
sym_06033894:
    mov.b r8, @(r0, r0)
    sts mach, r0
    .word 0x0000
    .word 0x0000
    sts mach, r0
    .word 0x0000
    sts mach, r0
    .word 0x0000
    mov.b r8, @(r0, r0)
    sts mach, r0
    .word 0x0000
    .word 0x0000
    mov.w r1, @(r0, r0)
    mov.b r0, @(0, gbr)
    .word 0x0013
    .word 0x0000
    mov.b r7, @(r0, r0)
    stc gbr, r0
    mov.l r0, @(r0, r0)
    .word 0xFFFE
    sts macl, r0
    .word 0x0000
    sett
    .word 0x0000

    .global sym_060338C4
sym_060338C4:
    .word 0x0060
    .word 0xFFEA
    .word 0x0048
    .word 0x0040
    .word 0x0060
    .word 0xFFEC
    .word 0x0048
    .word 0x0040
    .word 0x0048
    .word 0xFFF0
    .word 0x0060
    .word 0x0040

    .global sym_060338DC
sym_060338DC:
    .word 0x4444
    .word 0x4444
    mov.l @r5+, r5
    mov.l @r5+, r5
    mov.l @r5+, r5
    .word 0x4444

    .global sym_060338E8
sym_060338E8:
    mov.l @(20, r5), r5
    mov.l @(20, r5), r5
    mov.l @r2+, r2
    mov.l @r2+, r2
    mov.l @r2+, r2
    mov.l @(20, r5), r5

    .global sym_060338F4
sym_060338F4:
    .word 0x0000
    .word 0x0040
    .word 0x00E0
    .word 0x0060
    .word 0x0220
    .word 0x0020
    .word 0x05A0
    .word 0x0020
    .word 0x06A0
    .word 0x0060
    .word 0x07A0
    .word 0x0040

    .global sym_0603390C
sym_0603390C:
    mul.l r0, r0
    add #0x0, r0
    mul.l r0, r0
    add #0x0, r0
    stc sr, r0
    mov.b r0, @r0
    mul.l r0, r0
    add #0x0, r0
    stc sr, r0
    mov.b r0, @r0
    mul.l r0, r0
    add #0x0, r0
    .word 0x0000
    add #0x0, r7
    .word 0x0000
    add #0x0, r7
    stc sr, r0
    mov.b r0, @r0
    mul.l r0, r0
    add #0x0, r0
    stc vbr, r0
    .word 0x0000
    mul.l r7, r0
    .word 0x0000
    .word 0x0000
    .word 0x0700
    .word 0x0000
    add #0x70, r7
    mul.l r0, r0
    mov.b r0, @r7
    mul.l r2, r0
    add #0x0, r0
    .word 0x0772
    .word 0x0000
    .word 0x0070
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0770
    mul.l r0, r0
    mov.b r7, @r7
    mul.l r2, r7
    mov.b r0, @r0
    .word 0x0720
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mul.l r2, r7
    mov.b r7, @r7
    mul.l r2, r7
    mov.b r7, @r7
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0720
    .word 0x0000
    mul.l r2, r7
    mov.b r0, @r0
    mul.l r0, r0
    mov.b r7, @r7
    .word 0x0000
    .word 0x0770
    .word 0x0000
    .word 0x0000
    .word 0x0070
    .word 0x0000
    .word 0x0772
    .word 0x0000
    mul.l r2, r0
    add #0x0, r0
    mul.l r0, r0
    mov.b r0, @r7
    .word 0x0000
    add #0x70, r7
    .word 0x0000
    .word 0x0700
    mul.l r7, r0
    .word 0x0000
    stc vbr, r0
    .word 0x0000
    mul.l r0, r0
    add #0x0, r0
    stc sr, r0
    mov.b r0, @r0
    .word 0x0000
    add #0x0, r7
    .word 0x0000
    add #0x0, r7
    mul.l r0, r0
    add #0x0, r0
    stc sr, r0
    mov.b r0, @r0
    mul.l r0, r0
    add #0x0, r0
    stc sr, r0
    mov.b r0, @r0
    mul.l r0, r0
    add #0x0, r0
    mul.l r0, r0
    add #0x0, r0
    .word 0x0000
    add #0x0, r7
    .word 0x0000
    mov.b r0, @r2
    mul.l r0, r0
    add #0x0, r0
    stc sr, r0
    mov.b r0, @r0
    mul.l r7, r0
    .word 0x0000
    mul.l r7, r0
    .word 0x0000
    .word 0x0000
    .word 0x0700
    .word 0x0000
    mov.b r7, @r7
    mul.l r0, r0
    add #0x0, r2
    .word 0x0072
    add #0x0, r0
    mul.l r7, r7
    .word 0x0000
    .word 0x0070
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0270
    stc sr, r0
    add #0x70, r2
    .word 0x0772
    add #0x0, r0
    .word 0x0770
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0772
    add #0x70, r2
    .word 0x0772
    add #0x70, r2
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0770
    .word 0x0000
    .word 0x0772
    add #0x0, r0
    stc sr, r0
    add #0x70, r2
    .word 0x0000
    .word 0x0270
    .word 0x0000
    .word 0x0000
    .word 0x0070
    .word 0x0000
    mul.l r7, r7
    .word 0x0000
    .word 0x0072
    add #0x0, r0
    mul.l r0, r0
    add #0x0, r2
    .word 0x0000
    mov.b r7, @r7
    .word 0x0000
    .word 0x0700
    mul.l r7, r0
    .word 0x0000
    mul.l r7, r0
    .word 0x0000
    stc sr, r0
    mov.b r0, @r0
    mul.l r0, r0
    add #0x0, r0
    .word 0x0000
    mov.b r0, @r2
    .word 0x0000
    add #0x0, r7

    .global sym_06033A8C
sym_06033A8C:
    .word 0x0000
    .word 0x0100
    .word 0x0200
    .word 0x0300
    bsrf r0
    bsrf r1
    bsrf r2
    bsrf r3
    stc sr, r0
    stc sr, r1
    stc sr, r2
    stc sr, r3
    .word 0x0001
    .word 0x0101
    .word 0x0201
    .word 0x0301
