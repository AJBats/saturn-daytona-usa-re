
    .section .text.FUN_0600FDFE


    .global transition_small_d
    .type transition_small_d, @function
transition_small_d:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x09    /* mov.l .L_pool_0600FE2C, r14 */
    mov.l @r14, r3
    add #-0x1, r3
    cmp/pz r3
    bt/s    .L_0600FE20
    mov.l r3, @r14
    .byte   0xD5, 0x07    /* mov.l .L_pool_0600FE30, r5 */
    .byte   0xD3, 0x07    /* mov.l .L_pool_0600FE34, r3 */
    jsr @r3
    mov #0x0, r4
    mov.w   .L_wpool_0600FE2A, r2
    mov.l r2, @r14
    mov #0xF, r3
    .byte   0xD2, 0x05    /* mov.l .L_pool_0600FE38, r2 */
    mov.b r3, @r2
.L_0600FE20:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_0600FE2A:
    .2byte  0x00B4
.L_pool_0600FE2C:
    .4byte  sym_0607EBCC
.L_pool_0600FE30:
    .4byte  0xAB110DFF
.L_pool_0600FE34:
    .4byte  sound_cmd_dispatch               /* [HIGH] sound command dispatcher function */
.L_pool_0600FE38:
    .4byte  sym_0607887F
