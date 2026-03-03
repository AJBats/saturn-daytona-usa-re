	.text
    .global state_results_screen
state_results_screen:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDE, 0x0D    /* mov.l .L_0600959C, r14 */
    .byte   0xD3, 0x18    /* mov.l .L_060095C8, r3 */
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_06009596, r3
    and r3, r2
    tst r2, r2
    bt      .L_0600957E
    mov #0x1D, r3
    .byte   0xD2, 0x15    /* mov.l .L_060095CC, r2 */
    mov.l r3, @r2
    mov #0x12, r3
    mov.l r3, @r14
.L_0600957E:
    .byte   0xD4, 0x06    /* mov.l .L_06009598, r4 */
    mov.l @r4, r0
    tst #0x1, r0
    bt      .L_060095D0
    mov #-0x2, r3
    mov.l @r4, r2
    and r3, r2
    mov.l r2, @r4
    mov #0x14, r3
    mov.l r3, @r14
    bra     .L_060095E0
    nop
.L_06009596:
    .short  0x0800
.L_06009598:
    .long  sym_0607EBF4
.L_0600959C:
    .long  g_game_state
    .long  sym_0607EAD0
    .long  sym_0607EBD0
    .long  race_update_abort
    .long  camera_system
    .long  sym_06063E24
    .long  sym_06063EEC
    .long  sym_06063EF8
    .long  camera_orient_calc
    .long  scene_update
    .long  frame_end_commit
.L_060095C8:
    .long  sym_06063D9A
.L_060095CC:
    .long  sym_0607EACC
.L_060095D0:
    .byte   0xD0, 0x2C    /* mov.l .L_06009684, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_060095E0
    .byte   0xD4, 0x2B    /* mov.l .L_06009688, r4 */
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_060095E0:
    .byte   0xD0, 0x2A    /* mov.l .L_0600968C, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060095EE
    .byte   0xD3, 0x29    /* mov.l .L_06009690, r3 */
    jsr @r3
    mov #0x0, r4
.L_060095EE:
    .byte   0xD3, 0x29    /* mov.l .L_06009694, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x28    /* mov.l .L_06009698, r3 */
    jsr @r3
    nop
    .byte   0xD6, 0x28    /* mov.l .L_0600969C, r6 */
    .byte   0xD5, 0x28    /* mov.l .L_060096A0, r5 */
    .byte   0xD4, 0x29    /* mov.l .L_060096A4, r4 */
    .byte   0xD3, 0x29    /* mov.l .L_060096A8, r3 */
    jsr @r3
    mov.l @r6, r6
    .byte   0xD3, 0x29    /* mov.l .L_060096AC, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x28    /* mov.l .L_060096B0, r0 */
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_0600961C
    .byte   0xD3, 0x27    /* mov.l .L_060096B4, r3 */
    jsr @r3
    nop
.L_0600961C:
    .byte   0xD0, 0x26    /* mov.l .L_060096B8, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06009632
    .byte   0xD7, 0x25    /* mov.l .L_060096BC, r7 */
    .byte   0xD6, 0x25    /* mov.l .L_060096C0, r6 */
    mov.w   .L_0600967C, r5
    .byte   0xD3, 0x25    /* mov.l .L_060096C4, r3 */
    jsr @r3
    mov #0x8, r4
.L_06009632:
    .byte   0xD2, 0x25    /* mov.l .L_060096C8, r2 */
    mov.w   .L_0600967E, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    cmp/pl r3
    bf      .L_06009642
    .byte   0xB5, 0x21    /* bsr 0x0600A084 (external sub-function) */
    nop
.L_06009642:
    .byte   0xD3, 0x22    /* mov.l .L_060096CC, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x1F    /* mov.l .L_060096C8, r0 */
    mov.w   .L_06009680, r1
    mov.l @r0, r0
    mov.l @(r0, r1), r0
    tst #0xCC, r0
    bf      .L_06009668
    .byte   0xD3, 0x1E    /* mov.l .L_060096D0, r3 */
    mov.l r3, @r15
    mov r3, r7
    mov r3, r5
    mov.w   .L_06009682, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    .byte   0xD3, 0x1C    /* mov.l .L_060096D4, r3 */
    jsr @r3
    mov #0x4, r4
.L_06009668:
    .byte   0xD0, 0x1B    /* mov.l .L_060096D8, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06009674
    mov #0x11, r3
    mov.l r3, @r14
.L_06009674:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0600967C:
    .short  0x0082
.L_0600967E:
    .short  0x00BC
.L_06009680:
    .short  0x0214
.L_06009682:
    .short  0x0900
.L_06009684:
    .long  sym_0607EAD0
.L_06009688:
    .long  sym_0607EBD0
.L_0600968C:
    .long  sym_0605AB18
.L_06009690:
    .long  menu_overlay_render
.L_06009694:
    .long  race_update_ending
.L_06009698:
    .long  camera_system
.L_0600969C:
    .long  sym_06063E24
.L_060096A0:
    .long  sym_06063EEC
.L_060096A4:
    .long  sym_06063EF8
.L_060096A8:
    .long  camera_orient_calc
.L_060096AC:
    .long  scene_update
.L_060096B0:
    .long  sym_0607ED8C
.L_060096B4:
    .long  sym_060033E6
.L_060096B8:
    .long  sym_06086030
.L_060096BC:
    .long  sym_0605A1C8
.L_060096C0:
    .long  0x0000F000
.L_060096C4:
    .long  sym_060283E0
.L_060096C8:
    .long  sym_0607E944
.L_060096CC:
    .long  frame_end_commit
.L_060096D0:
    .long  sym_06063798
.L_060096D4:
    .long  sym_06028400
.L_060096D8:
    .long  sym_0605A1C4
