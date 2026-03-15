
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
    .byte   0xD0, 0x17    /* mov.l .L_pool_06033208, r0 */
