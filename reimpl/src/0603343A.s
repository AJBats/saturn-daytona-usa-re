	.text
    .global split_hud_render
split_hud_render:
    sts.l pr, @-r15
    .byte   0xBE, 0x1E    /* bsr 0x0603307C (external) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    rts
    nop
    .long  sym_06033870
    .long  sym_060629AA
    .long  sym_0606299A
    .long  sym_06033880
    .long  sym_06033864
    .long  sym_0606298C
    .long  sym_0606299C
    .long  0xD31DE100
    .long  0xD01D6002
    .long  0x61024108
    .long  0x4100331C
    .long  0x61356235
    .long  0xD41AE000
    .long  0x14007001
    .long  0x8044D019
    .long  0x60026002
    .long  0x40094009
    .long  0x40098045
    .long  0xE00E8143
    .long  0x60136535
    .long  0x351CD614
    .long  0x66626660
    .long  0x46158B01
    .long  0x60536513
    .long  0x8144814A
    .long  0x60538146
    .long  0x81486023
    .long  0x81458147
    .long  0x6035302C
    .long  0x8149814B
    .long  0xD50B6552
    .short  0xD00B
