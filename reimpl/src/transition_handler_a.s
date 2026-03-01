
    .section .text.FUN_0600F794


    .global transition_handler_a
    .type transition_handler_a, @function
transition_handler_a:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15

    mov.l   .L_pool_0600F7E4, r3
    mov.l r3, @r15
    mov r3, r14
    add #0x2, r14
    mov.l   .L_pool_0600F7E8, r3
    mov.w @r14, r14
    jsr @r3
    mov #0x0, r4

    mov.l   .L_pool_0600F7EC, r3
    jsr @r3
    nop

    mov.l @r15, r0
    mov.w @(6, r0), r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0600F7F0
    .byte   0xB5, 0x3D    /* bsr 0x06010238 (external) */
    nop
    bra     .L_0600F7F4
    nop

    .2byte  0x0B04
    .4byte  0x0B380170
    .4byte  0x0C2604B0
    .4byte  sym_06063750
    .4byte  0x00009000
    .4byte  0x0000A000
    .4byte  sym_0607EADC
    .4byte  sym_0607EBCC
    .4byte  sym_0607887F
.L_pool_0600F7E4:
    .4byte  g_pad_state
.L_pool_0600F7E8:
    .4byte  anim_ui_transition
.L_pool_0600F7EC:
    .4byte  hud_course_render

.L_0600F7F0:
    .byte   0xB5, 0x5A    /* bsr 0x060102A8 (external) */
    mov r14, r4

.L_0600F7F4:
    .byte   0xB5, 0x79    /* bsr 0x060102EA (external) */
    mov r14, r4

    .byte   0xD0, 0x14    /* mov.l .L_pool_0600F84C, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600F81A
    .byte   0xD4, 0x13    /* mov.l .L_pool_0600F850, r4 */
    .byte   0x92, 0x21    /* mov.w .L_wpool_0600F848, r2 */
    mov.w @r4, r4
    extu.w r4, r4
    and r2, r4
    tst r4, r4
    bt      .L_0600F812
    bra     .L_0600F814
    mov #0x1, r3
.L_0600F812:
    mov #0x0, r3
.L_0600F814:
    exts.b r3, r3
    .byte   0xD2, 0x0F    /* mov.l .L_pool_0600F854, r2 */
    mov.b r3, @r2

.L_0600F81A:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
