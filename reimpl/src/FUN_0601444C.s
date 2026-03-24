
    .section .text.FUN_0601444C


    .global FUN_0601444C
    .type FUN_0601444C, @function
FUN_0601444C:
    sts.l pr, @-r15
    .byte   0xD1, 0x23    /* mov.l .L_pool_060144DC, r1 */
    .byte   0xD3, 0x23    /* mov.l .L_pool_060144E0, r3 */
    mov.w @r1, r1
    jsr @r3
    mov #0x3C, r0
    mov r0, r7
    mov #0x18, r6
    .byte   0x95, 0x3C    /* mov.w .L_wpool_060144D8, r5 */
    mov #0xC, r4
    .byte   0xD3, 0x20    /* mov.l .L_pool_060144E4, r3 */
    jmp @r3
    lds.l @r15+, pr


    .global FUN_06014466
    .type FUN_06014466, @function
FUN_06014466:
    mov #0x1C, r5
