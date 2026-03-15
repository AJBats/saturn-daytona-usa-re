
    .section .text.FUN_0600F822


    .global FUN_0600F822
    .type FUN_0600F822, @function
FUN_0600F822:
    sts.l pr, @-r15
    .byte   0xD5, 0x0C    /* mov.l .L_pool_0600F85E, r5 */
    .byte   0xD3, 0x0D    /* mov.l .L_pool_0600F862, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x0C    /* mov.l .L_pool_0600F866, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x0C    /* mov.l .L_pool_0600F86A, r3 */
    jsr @r3
    nop
    mov #0x78, r2
    .byte   0xD3, 0x0B    /* mov.l .L_pool_0600F86E, r3 */
    mov.w r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x0A    /* mov.l .L_pool_0600F872, r3 */
    lds.l @r15+, pr
    rts
    mov.b r2, @r3
    .4byte  0x0800FFFF
    .4byte  sym_06085FF4
    .4byte  g_pad_state
    .4byte  sym_06078663
.L_pool_0600F85E:
    .4byte  0xAB1101FF
.L_pool_0600F862:
    .4byte  FUN_0601D5F4           /* sound command dispatcher */
.L_pool_0600F866:
    .4byte  FUN_060114AC
.L_pool_0600F86A:
    .4byte  FUN_06011094
.L_pool_0600F86E:
    .4byte  sym_0607887C
.L_pool_0600F872:
    .4byte  sym_0607887F
