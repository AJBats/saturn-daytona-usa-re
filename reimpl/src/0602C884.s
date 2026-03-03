	.text
    .global vdp1_texture_setup
vdp1_texture_setup:
    sts.l pr, @-r15
    jsr @r12
    mov r9, r0
    lds.l @r15+, pr
    mov.l @r15+, r0
    shll2 r1
    add r2, r1
    mov.l @r1, r4
    rts
    mov.l @r15+, r10
    .long  0x000100EE

    .global DAT_0602c89c
DAT_0602c89c:
    mov.b r0, @(r0, r0)
    mov.b r11, @(r0, r0)

    .global DAT_0602c8a0
DAT_0602c8a0:
    stc sr, r0
    .word 0x00D2
    .word 0x0010
    mov.l r15, @(r0, r0)
    .word 0x0020
    .word 0x00FA
    mov.l r9, @(r0, r0)
    .word 0x0000
    .long  sym_06045AEC
    .long  sym_0602ECCC
    .long  0x4808328C
    .long  0x6AF6000B
    .long  0x64224801
    .long  0x4808328C
    .long  0x6AF6000B
    .long  0x64224809
    .long  0x4808328C
    .long  0x6AF6000B
    .long  0x6422E401
    .long  0x6AF6000B
    .short  0x4428
