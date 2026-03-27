
    .section .text.FUN_0603319C


    .global FUN_0603319C
    .type FUN_0603319C, @function
FUN_0603319C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r2, r4
    mov r11, r5
    mov.l   .L_pool_06033208, r0


    .global FUN_060331AA
    .type FUN_060331AA, @function
FUN_060331AA:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r3
    mov r2, r4
    mov r12, r5
    mov.l   .L_pool_06033208, r0

    .global FUN_060331BA
    .type FUN_060331BA, @function
FUN_060331BA:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r6
    mov r1, r4
    mov r11, r5
    mov.l   .L_pool_06033208, r0

    .global FUN_060331CA
    .type FUN_060331CA, @function
FUN_060331CA:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r8
    mov r1, r4
    mov r12, r5
    mov.l   .L_pool_06033208, r0

    .global FUN_060331DA
    .type FUN_060331DA, @function
FUN_060331DA:
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
    .4byte  FUN_06027358
.L_pool_06033208:
    .4byte  FUN_06027552
    .global FUN_0603320C
FUN_0603320C:
    .4byte  0x2F662F76
    .4byte  0xD3153138
    .4byte  0x3238D315
    .4byte  0x40084000
    .4byte  0x64034000
    .4byte  0x304C330C
    .4byte  0xE606E704
    .4byte  0x60346503
    .4byte  0x45094509
