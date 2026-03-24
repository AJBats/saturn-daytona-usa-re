
    .section .text.FUN_06033578


    .global FUN_06033578
    .type FUN_06033578, @function
FUN_06033578:
    sts.l pr, @-r15
    bsr     FUN_060335F4
    nop
    lds.l @r15+, pr
    .byte   0xD2, 0x19    /* mov.l .L_pool_060335E8, r2 */
    mov.l @(r0, r2), r3
    .byte   0xD2, 0x19    /* mov.l .L_pool_060335EC, r2 */
    mov.l @(r0, r2), r2
    mov r3, r4
    mov r8, r5
    .byte   0xD0, 0x18    /* mov.l .L_pool_060335F0, r0 */


    .global FUN_0603358E
    .type FUN_0603358E, @function
FUN_0603358E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r14
    mov r3, r4
    mov r7, r5
    .byte   0xD0, 0x14    /* mov.l .L_pool_060335F0, r0 */

    .global FUN_0603359E
    .type FUN_0603359E, @function
FUN_0603359E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r13
    mov r2, r4
    mov r8, r5
    .byte   0xD0, 0x10    /* mov.l .L_pool_060335F0, r0 */

    .global FUN_060335AE
    .type FUN_060335AE, @function
FUN_060335AE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r12
    mov r2, r4
    mov r7, r5
    .byte   0xD0, 0x0C    /* mov.l .L_pool_060335F0, r0 */

    .global FUN_060335BE
    .type FUN_060335BE, @function
FUN_060335BE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r11
    neg r11, r11
    add r11, r14
    mov.l r14, @-r1
    add r12, r13
    mov.l r13, @-r1
    mov.l @r15+, r0
    rts
    nop
    .4byte  sym_06033630
    .4byte  0x00000020
    .4byte  0x000001D8
    .4byte  0x000001CC
    .4byte  0x00000010
    .4byte  0x00000018
    .4byte  FUN_06027552
    .global FUN_060335F4
FUN_060335F4:
    .4byte  0x2F06D09F
    .4byte  0x60024008
    .4byte  0xD409340C
    .4byte  0x64422F46
    .2byte  0xD008

    .global FUN_06033606
    .type FUN_06033606, @function
FUN_06033606:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r7
    mov.l @r15+, r4
    .byte   0xD0, 0x06    /* mov.l .L_pool_0603362C, r0 */
