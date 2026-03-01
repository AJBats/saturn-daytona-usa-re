
    .section .text.FUN_060331DA


    .global results_digit_group
    .type results_digit_group, @function
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
    .4byte  0x0000FFFF
    .4byte  sym_0606318C
    .4byte  sym_06063190
    .4byte  sincos_pair
    .4byte  fpmul
    .4byte  0x2F662F76
    .4byte  0xD3153138
    .4byte  0x3238D315
    .4byte  0x40084000
    .4byte  0x64034000
    .4byte  0x304C330C
    .4byte  0xE606E704
    .4byte  0x60346503
    .4byte  0x45094509
