
    .section .text.FUN_06032F84


    .global FUN_06032F84
    .type FUN_06032F84, @function
FUN_06032F84:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x16    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    mov.l @r15+, r1
    .byte   0xD0, 0x21    /* mov.l .L_pool_06033018, r0 */
    tst r0, r1
    .byte   0x89, 0x1C    /* bt 0x06032FD2 (external) */
    .byte   0xD0, 0x12    /* mov.l .L_pool_06032FE4, r0 */


    .global FUN_06032F9A
    .type FUN_06032F9A, @function
FUN_06032F9A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x11    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x18    /* mov.l .L_pool_06033008, r0 */
    mov.l @(32, r0), r4
    mov.l @(36, r0), r5
    mov.l @(40, r0), r6
    .byte   0xD0, 0x12    /* mov.l .L_pool_06032FF8, r0 */
