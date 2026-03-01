
    .section .text.FUN_0601E37C


    .global hud_large_element
    .type hud_large_element, @function
hud_large_element:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15

    mov.w   DAT_0601e444, r8
    mov #0x3, r9
    mov #0x0, r10
    mov #0x1, r11
    mov.l   .L_pool_elem_array, r14
    extu.w r10, r13
    bra     .L_loop_check
    mov r13, r12

.L_loop_body:
    extu.w r12, r2
    mov.l   .L_pool_id_table, r3
    shll2 r2
    add r3, r2
    mov.w @r2, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_slot_has_id
    bra     .L_next_input
    nop

.L_slot_has_id:
    extu.w r13, r2
    mov r12, r0
    shll2 r2
    shll2 r2
    shll r2
    add r14, r2
    mov.w r0, @(28, r2)
    .byte   0xB0, 0x63    /* bsr 0x0601E488 (hud_text_handler — query element state) */
    mov r13, r4
    bra     .L_state_dispatch
    nop

.L_state_2_check:
    extu.w r13, r4
    shll2 r4
    shll2 r4
    shll r4
    add r14, r4
    mov.w @(28, r4), r0
    mov r0, r4
    .byte   0xB1, 0x66    /* bsr 0x0601E6A4 (hud_utility — check display callback) */
    extu.w r4, r4
    tst r0, r0
    bt      .L_display_inactive
    extu.w r13, r3
    shll2 r3
    shll2 r3
    shll r3
    add r14, r3
    extu.b r8, r2
    mov #0x1F, r0
    mov.b r2, @(r0, r3)
    bra     .L_bounds_check
    nop

.L_display_inactive:
    extu.w r13, r2
    shll2 r2
    shll2 r2
    shll r2
    add r14, r2
    extu.b r11, r3
    mov #0x1F, r0
    mov.b r3, @(r0, r2)
    bra     .L_bounds_check
    nop

.L_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_bounds_check
    cmp/eq #0x1, r0
    bt      .L_next_input
    cmp/eq #0x2, r0
    bt      .L_state_2_check

.L_bounds_check:
    extu.w r13, r4
    mov.l   .L_pool_player_index, r3
    mov.l   .L_pool_course_size_table, r2
    shll2 r4
    mov.b @r3, r3
    shll2 r4
    extu.b r3, r3
    shll r4
    shll2 r3
    add r14, r4
    add r2, r3
    mov.l @(12, r4), r4
    mov.l @r3, r3
    add #0x20, r3
    cmp/hs r3, r4
    bt      .L_out_of_bounds

    extu.w r13, r3
    shll2 r3
    shll2 r3
    shll r3
    add r14, r3
    extu.b r10, r2
    mov #0x1E, r0
    mov.b r2, @(r0, r3)
    bra     .L_advance_output
    nop

    .global DAT_0601e444
DAT_0601e444:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_pool_elem_array:
    .4byte  sym_06087094
.L_pool_id_table:
    .4byte  sym_06087086
.L_pool_player_index:
    .4byte  sym_060877D8
.L_pool_course_size_table:
    .4byte  sym_0604A5C0

.L_out_of_bounds:
    extu.w r13, r2
    shll2 r2
    shll2 r2
    shll r2
    add r14, r2
    extu.b r11, r3
    mov #0x1E, r0
    mov.b r3, @(r0, r2)

.L_advance_output:
    add #0x1, r13

.L_next_input:
    add #0x1, r12

.L_loop_check:
    extu.w r12, r3
    cmp/ge r9, r3
    bf      .L_loop_body

    .byte   0xD3, 0x29    /* mov.l .L_pool_0601E518, r3 (out-of-TU: output element count address) */
    mov.w r13, @r3
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
