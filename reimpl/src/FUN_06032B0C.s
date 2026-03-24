
    .section .text.FUN_06032B0C


    .global FUN_06032B0C
    .type FUN_06032B0C, @function
FUN_06032B0C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032D38, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032D3C, r0 */


    .global FUN_06032B1A
    .type FUN_06032B1A, @function
FUN_06032B1A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x86    /* mov.l .L_pool_06032D40, r0 */
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
    .byte   0xD0, 0x7A    /* mov.l .L_pool_06032D44, r0 */

    .global FUN_06032B5A
    .type FUN_06032B5A, @function
FUN_06032B5A:
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

    .global FUN_06032B72
    .type FUN_06032B72, @function
FUN_06032B72:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x75    /* mov.l .L_pool_06032D50, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x6B    /* mov.l .L_pool_06032D2C, r0 */
