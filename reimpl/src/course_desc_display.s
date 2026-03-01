
    .section .text.FUN_06033614


    .global course_desc_display
    .type course_desc_display, @function
course_desc_display:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r8
    mov.l @r15+, r0
    rts
    nop
    .4byte  sym_0603363C
    .4byte  sin_lookup
    .4byte  cos_lookup

    .global sym_06033630
sym_06033630:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    shll r0
    .word 0x0000
    .word 0x8E00

    .global sym_0603363C
sym_0603363C:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mov.b r0, @(0, gbr)
    .word 0x0000
    add #0x0, r6
    mov.l r0, @-r15
    sts.l pr, @-r15
    .byte   0xB0, 0x51    /* bsr 0x060336F2 (external) — check_special_mode */
    nop
    lds.l @r15+, pr
    bf      .L_not_special_mode
    mov.l @r15+, r0
    bra     .L_check_element
    mov #0x1, r6
.L_not_special_mode:
    .byte   0xD0, 0x82    /* mov.l .L_pool_06033864, r0 — ptr to demo_mode_flag (0x0607EAE0) */
    mov.l @r0, r0
    cmp/pl r0
    .byte   0x89, 0x28    /* bt 0x060336B4 (external) — branch if demo mode active */
    mov.l @r15+, r0
    .byte   0xD6, 0x15    /* mov.l .L_pool_060336BC, r6 — ptr to element count indirect (0x0603386C) */
    mov.l @r6, r6
    mov.l @r6, r6
    add #-0x1, r6
.L_check_element:
    mov.l r0, @-r15
    .byte   0xD2, 0x14    /* mov.l .L_pool_060336C0, r2 — element struct offset (0x224) */
    mov.l @(r0, r2), r3
    mov #0x0, r4
    cmp/eq r4, r3
    .byte   0x8B, 0x00    /* bf 0x0603367A (external) — branch if slot populated */
    mov #0x1, r4
