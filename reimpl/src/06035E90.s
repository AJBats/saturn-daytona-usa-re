	.text
    .global input_proc_analog
input_proc_analog:
    sts.l pr, @-r15
    mov r4, r1
    .byte   0xD2, 0x13    /* mov.l .L_pool_06035EE4, r2 */
    .byte   0xD3, 0x14    /* mov.l .L_pool_06035EE8, r3 */
    jsr @r3
    mov #0x8, r0
    lds.l @r15+, pr
    rts
    nop
