
    .section .text.FUN_060326D8


    .global FUN_060326D8
    .type FUN_060326D8, @function
FUN_060326D8:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x3E    /* mov.l .L_pool_060327DC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x3E    /* mov.l .L_pool_060327E0, r0 */


    .global FUN_060326E6
    .type FUN_060326E6, @function
FUN_060326E6:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x3C    /* mov.l .L_pool_060327E4, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x23    /* mov.l .L_pool_060327B4, r0 */

    .global FUN_06032726
    .type FUN_06032726, @function
FUN_06032726:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x1F    /* mov.l .L_pool_060327AC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x2D    /* mov.l .L_pool_060327E8, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x22    /* mov.l .L_pool_060327C8, r0 */

    .global FUN_0603273E
    .type FUN_0603273E, @function
FUN_0603273E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x29    /* mov.l .L_pool_060327EC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x23    /* mov.l .L_pool_060327D8, r0 */
