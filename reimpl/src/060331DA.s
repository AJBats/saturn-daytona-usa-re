	.text
    .global results_digit_group
results_digit_group:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r7
    neg r6, r1
    add r8, r1
    mov r3, r2
    add r7, r2
    mov.l @r15+, r8
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r0
    rts
    nop
    .long  0x0000FFFF
    .long  sym_0606318C
    .long  sym_06063190
    .long  sincos_pair
    .long  fpmul
    .long  0x2F662F76
    .long  0xD3153138
    .long  0x3238D315
    .long  0x40084000
    .long  0x64034000
    .long  0x304C330C
    .long  0xE606E704
    .long  0x60346503
    .long  0x45094509
