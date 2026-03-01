    .section .text.FUN_0600FD8A


    .global FUN_0600FD8A
    .type FUN_0600FD8A, @function
FUN_0600FD8A:
    sts.l pr, @-r15
    .byte   0xD4, 0x13    /* mov.l .L_pool_0600FDDC, r4 */
    mov.w @r4, r3
    add #-0x1, r3
    mov.w r3, @r4
    exts.w r3, r3
    cmp/pz r3
    bt      .L_0600FDB8
    mov #0xC, r3
    .byte   0xD2, 0x10    /* mov.l .L_pool_0600FDE0, r2 */
    mov r3, r4
    mov.b r3, @r2
    .byte   0xD3, 0x13    /* mov.l .L_pool_0600FDF0, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x11    /* mov.l .L_pool_0600FDF0, r3 */
    jsr @r3
    mov #0x4, r4
    mov #0x14, r2
    .byte   0xD3, 0x10    /* mov.l .L_pool_0600FDF4, r3 */
    mov.l r2, @r3
    bra     .L_0600FDF8
    nop
.L_0600FDB8:
    .byte   0xB7, 0x04    /* bsr 0x06010BC4 (external) */
    nop
    .byte   0xD3, 0x09    /* mov.l .L_pool_0600FDE4, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x09    /* mov.l .L_pool_0600FDE8, r0 */
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0600FDF8
    mov #0x1, r4
    .byte   0xD3, 0x07    /* mov.l .L_pool_0600FDEC, r3 */
    jmp @r3
    lds.l @r15+, pr
    .2byte  0xFFFF
    .4byte  0xAB1101FF
    .4byte  sound_cmd_dispatch
.L_pool_0600FDDC:
    .4byte  sym_0607887A
.L_pool_0600FDE0:
    .4byte  sym_0607887F
.L_pool_0600FDE4:
    .4byte  sym_06011EB4
.L_pool_0600FDE8:
    .4byte  sym_06085FF4
.L_pool_0600FDEC:
    .4byte  anim_ui_transition
.L_pool_0600FDF0:
    .4byte  sym_0602853E
.L_pool_0600FDF4:
    .4byte  sym_0607EBCC
.L_0600FDF8:
    lds.l @r15+, pr
    rts
    nop
