
    .section .text.FUN_06032694


    .global FUN_06032694
    .type FUN_06032694, @function
FUN_06032694:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x43    /* mov.l .L_pool_060327AC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x45    /* mov.l .L_pool_060327B8, r0 */


    .global FUN_060326A2
    .type FUN_060326A2, @function
FUN_060326A2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x40    /* mov.l .L_pool_060327AC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x43    /* mov.l .L_pool_060327BC, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x43    /* mov.l .L_pool_060327C0, r0 */
    mov.l @(r0, r14), r5
    .byte   0xD0, 0x43    /* mov.l .L_pool_060327C4, r0 */
    mov.l @(r0, r14), r6
    .byte   0xD0, 0x43    /* mov.l .L_pool_060327C8, r0 */
