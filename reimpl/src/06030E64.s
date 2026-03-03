
    .section .text.FUN_06030E64


    .global sound_subsys_wrapper
    .type sound_subsys_wrapper, @function
sound_subsys_wrapper:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r8
    mov r10, r4
    .byte   0xD0, 0x10    /* mov.l .L_pool_06030EB4, r0 */
