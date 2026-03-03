
    .section .text.FUN_060405B8


    .global evt_validate_multi
    .type evt_validate_multi, @function
evt_validate_multi:
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l r4, @r15
    mov r15, r4
    mov.l r5, @(4, r15)
    mov.l   .L_pool_06040630, r3
    jsr @r3
    add #0x8, r4
    mov r0, r4
    mov.l @(4, r15), r0
    tst r0, r0
    bt      .L_060405D4
    mov.l @(4, r15), r3
    mov.w r4, @r3
.L_060405D4:
    mov.l @r15, r0
    tst r0, r0
    bt      .L_060405E4
    mov.l @r15, r3
    mov r15, r2
    add #0x8, r2
    mov.l @(8, r2), r1
    mov.l r1, @r3
.L_060405E4:
    mov r15, r0
    add #0x8, r0
    mov.b @r0, r0
    extu.b r0, r0
    bra     .L_06040634
    and #0xF, r0

    .4byte  0x7F144F26
    .4byte  0x000BE002
    .4byte  0x7F144F26
    .4byte  0x000BE000
    .4byte  0x7F144F26
    .4byte  0x000BE001
    .4byte  0x7F144F26
    .4byte  0x000BE002
    .4byte  0x7F144F26
    .4byte  0x000BE001
    .4byte  0x7F144F26
    .4byte  0x000BE003
    .4byte  0x7F144F26
    .4byte  0x000BE004
.L_06040628:
    add #0x14, r15
    lds.l @r15+, pr
    rts
    mov #0x5, r0

.L_pool_06040630:
    .4byte  evt_validator_pair

.L_06040634:
    mov #0xB, r1
    cmp/hs r1, r0
    bt      .L_06040628
    shll r0
    mov r0, r1
    .word 0xC702
    mov.w @(r0, r1), r0
    braf r0
    nop

    .word 0xFFFF
    .word 0xFFAA
    .word 0xFFB2
    .word 0xFFB2
    .word 0xFFBA
    .word 0xFFC2
    .word 0xFFCA
    .word 0xFFD2
    .word 0xFFDA
    .word 0xFFBA
    .word 0xFFE2
    .word 0xFFE2

    add #0x14, r15
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xE500
