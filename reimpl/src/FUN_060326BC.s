
    .section .text.FUN_060326BC


    .global FUN_060326BC
    .type FUN_060326BC, @function
FUN_060326BC:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x41    /* mov.l .L_pool_060327CC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x41    /* mov.l .L_pool_060327D0, r0 */


    .global FUN_060326CA
    .type FUN_060326CA, @function
FUN_060326CA:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x40    /* mov.l .L_pool_060327D4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x40    /* mov.l .L_pool_060327D8, r0 */
