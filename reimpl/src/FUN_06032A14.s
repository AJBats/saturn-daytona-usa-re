
    .section .text.FUN_06032A14


    .global FUN_06032A14
    .type FUN_06032A14, @function
FUN_06032A14:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x2F    /* mov.l .L_pool_06032ADC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032A90, r0 */


    .global FUN_06032A22
    .type FUN_06032A22, @function
FUN_06032A22:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x2C    /* mov.l .L_pool_06032AE0, r0 */
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
    .byte   0xD0, 0x14    /* mov.l .L_pool_06032AB4, r0 */

    .global FUN_06032A62
    .type FUN_06032A62, @function
FUN_06032A62:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x03    /* mov.l .L_pool_06032A79, r13 */
    mov.l @r13, r13
    bra     .L_06032AE4
    nop
    .2byte  0x0000
    .4byte  sym_06026DBC
.L_pool_06032A79:
    .4byte  sym_06089EDC
    .4byte  0x00000018
    .4byte  sym_06026E2E
    .4byte  0x00000028
    .4byte  FUN_06026E94
    .4byte  0x0000002C
    .4byte  FUN_06026F2A
    .4byte  0x0000002A
    .4byte  FUN_06026EDE
    .4byte  0x000000B4
    .4byte  0x00000024
    .4byte  0x0000002E
    .4byte  0x000000E4
    .4byte  0x00000030
    .4byte  0x00000114
    .4byte  sym_06026DF8
    .4byte  0x0000003C
    .4byte  0x00000032
    .4byte  0x00000036
    .4byte  0x00000034
    .4byte  0x00000144
    .4byte  0x00000048
    .4byte  0x00000038
    .4byte  0x00000174
    .4byte  0x00000054
    .4byte  0x0000003A
    .4byte  0x000001A4
.L_06032AE4:
    .byte   0xD0, 0x8E    /* mov.l .L_pool_06032D20, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x8D    /* mov.l .L_pool_06032D24, r0 */
