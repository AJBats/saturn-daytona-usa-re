
    .section .text.FUN_0600F8BE


    .global transition_handler_b
    .type transition_handler_b, @function
transition_handler_b:
    sts.l pr, @-r15
    .byte   0xD4, 0x07    /* mov.l .L_pool_0600F8E2, r4 */
    mov.w @r4, r3
    add #-0x1, r3
    mov.w r3, @r4
    exts.w r3, r3
    cmp/pl r3
    bf      .L_0600F8F8
    .byte   0xD3, 0x09    /* mov.l .L_pool_0600F8F6, r3 */
    jmp @r3
    lds.l @r15+, pr
    .4byte  0x0708FFFF
    .4byte  anim_ui_transition
    .4byte  hud_course_render
.L_pool_0600F8E2:
    .4byte  sym_0607887C
    .4byte  sym_0607887F
    .4byte  sym_06028560
    .4byte  sym_0607EBCC
    .4byte  sym_0607886E
.L_pool_0600F8F6:
    .4byte  hud_transparency
.L_0600F8F8:
    .byte   0xD3, 0x19    /* mov.l .L_pool_0600F960, r3 */
    jsr @r3
    mov #0x4, r4
    .byte   0xD4, 0x19    /* mov.l .L_pool_0600F964, r4 */
    lds.l @r15+, pr
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4

    .global loc_0600F90A
loc_0600F90A:
    .byte   0xD4, 0x16    /* mov.l .L_pool_0600F964, r4 */
    mov.b @r4, r3
    add #0x1, r3
    rts
    mov.b r3, @r4
