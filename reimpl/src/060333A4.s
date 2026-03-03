	.text
    .global results_sub_elem
results_sub_elem:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    rts
    nop
    .long  0x07E00000
    .long  sym_060338DC
    .long  sym_06033868
    .long  sym_060338E8
    .long  sym_06062D95
    .long  sym_060338F4
    .long  sym_060430CE
    .long  sym_060629AC
    .long  memcpy_word_idx
    .long  0x25E03700

    .global sym_060333D8
sym_060333D8:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
