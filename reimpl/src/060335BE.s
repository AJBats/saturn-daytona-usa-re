	.text
    .global course_name_render
course_name_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r11
    neg r11, r11
    add r11, r14
    mov.l r14, @-r1
    add r12, r13
    mov.l r13, @-r1
    mov.l @r15+, r0
    rts
    nop
    .long  sym_06033630
    .long  0x00000020
    .long  0x000001D8
    .long  0x000001CC
    .long  0x00000010
    .long  0x00000018
    .long  fpmul
    .long  0x2F06D09F
    .long  0x60024008
    .long  0xD409340C
    .long  0x64422F46
    .short  0xD008
