	.text
    .global display_element_mgr
display_element_mgr:
    sts.l pr, @-r15
    .byte   0xBE, 0x9C    /* bsr 0x06033504 (external) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r6
    mov.l @r15+, r0
    rts
    nop
    .short  0x0000
    .long  sym_06033894
    .long  fpdiv_setup
    .long  0xFFFFC800
    .long  0x00004800
    .long  0x0000FFFF
    .long  sym_06033A8C
    .long  sym_06062970
    .long  sym_060785FC
    .long  sym_060280F8
    .long  0x4008D102
    .long  0x301C6002
    .long  0x402B0009
    .long  sym_0603380C

    .global sym_0603380C
sym_0603380C:
    .long  loc_0603381C
    .long  loc_0603382E
    .long  loc_06033840
    .long  loc_06033852

    .global loc_0603381C
loc_0603381C:
    mov.w r12, @r4
    mov.w r11, @-r4
    mov.w r10, @-r4
    mov.w r9, @-r4
    mov.w r8, @-r4
    mov.w r7, @-r4
    mov.w r6, @-r4
    rts
    mov.w r5, @-r4

    .global loc_0603382E
loc_0603382E:
    mov.w r10, @r4
    mov.w r9, @-r4
    mov.w r8, @-r4
    mov.w r7, @-r4
    mov.w r6, @-r4
    mov.w r5, @-r4
    mov.w r12, @-r4
    rts
    mov.w r11, @-r4

    .global loc_06033840
loc_06033840:
    mov.w r8, @r4
    mov.w r7, @-r4
    mov.w r6, @-r4
    mov.w r5, @-r4
    mov.w r12, @-r4
    mov.w r11, @-r4
    mov.w r10, @-r4
    rts
    mov.w r9, @-r4

    .global loc_06033852
loc_06033852:
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
    .long  sym_0607EAE0

    .global sym_06033868
sym_06033868:
    .long  sym_0607EAB8

    .global sym_0603386C
sym_0603386C:
    .long  sym_0607EA98

    .global sym_06033870
sym_06033870:
    .long  sym_06078900

    .global sym_06033874
sym_06033874:
    .long  sym_0607EAD8
    .long  sym_06063750

    .global sym_0603387C
sym_0603387C:
    .long  sym_0605B734

    .global sym_06033880
sym_06033880:
    .long  sym_06078635

    .global sym_06033884
sym_06033884:
    .long  sym_06078663
    .long  g_pad_state
    .long  sym_0605D240
    .long  sym_06085FF4

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
