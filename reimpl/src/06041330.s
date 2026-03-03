
    .section .text.FUN_06041330


    .global evt_validator_pair
    .type evt_validator_pair, @function
evt_validator_pair:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x0C    /* mov.l .L_pool_06041368, r3 */
    jsr @r3
    mov.l r4, @r15
    mov r0, r4
    tst r4, r4
    bt      .L_06041346
    .byte   0xD3, 0x0A    /* mov.l .L_pool_0604136C, r3 */
    jsr @r3
    mov.l @r15, r4
.L_06041346:
    add #0x4, r15
    .byte   0xD3, 0x09    /* mov.l .L_pool_06041370, r3 */
    jmp @r3
    lds.l @r15+, pr
