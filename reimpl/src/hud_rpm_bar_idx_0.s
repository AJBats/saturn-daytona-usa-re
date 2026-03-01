
    .section .text.FUN_06032B5A


    .global hud_rpm_bar_idx_0
    .type hud_rpm_bar_idx_0, @function
hud_rpm_bar_idx_0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x79    /* mov.l .L_pool_06032D48, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x79    /* mov.l .L_pool_06032D4C, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x6C    /* mov.l .L_pool_06032D24, r0 */
