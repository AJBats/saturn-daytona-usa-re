
    .section .text.FUN_060429EC


    .global color_palette_effect
    .type color_palette_effect, @function
color_palette_effect:
    mov.l r14, @-r15
    mov r6, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l r4, @r15
    mov.l r5, @(4, r15)
    mov.l   .L_pool_get_display_mode, r3
    jsr @r3
    mov.l r7, @(8, r15)
    cmp/eq #0x2, r0
    bf      .L_mode_not2
    mov.l @(8, r15), r13
    mov.l   .L_pool_cram_palette_index, r3
    jsr @r3
    mov.l @r15, r4
    shll8 r0
    mov.l   .L_vdp2_cram_0x000, r2
    mov.l @(4, r15), r3
    shll2 r0
    shll2 r3
    add r2, r0
    mov r0, r4
    add r3, r4
    mov r14, r0
    cmp/eq #0x1, r0
    bf      .L_mode2_multi
    mov.l @r13, r2
    bra     .L_return
    mov.l r2, @r4
.L_mode2_multi:
    mov r14, r6
    shll2 r6
    mov r13, r5
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_pool_word_copy_helper, r3
    jmp @r3
    mov.l @r15+, r14
.L_mode_not2:
    mov.l @(8, r15), r13
    mov.l   .L_pool_cram_palette_index, r3
    jsr @r3
    mov.l @r15, r4
    shll8 r0
    mov.l   .L_vdp2_cram_0x000, r2
    mov.l @(4, r15), r3
    shll r0
    shll r3
    add r2, r0
    mov r0, r4
    add r3, r4
    mov r14, r0
    cmp/eq #0x1, r0
    bf      .L_mode_not2_multi
    mov.w @r13, r2
    bra     .L_return
    mov.w r2, @r4
.L_mode_not2_multi:
    mov r14, r6
    shll r6
    mov r13, r5
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_pool_word_copy_helper, r3
    jmp @r3
    mov.l @r15+, r14
.L_return:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_get_display_mode:
    .4byte  sym_0603C156
.L_pool_cram_palette_index:
    .4byte  sym_06042BFC
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 */
.L_pool_word_copy_helper:
    .4byte  sym_06038A48

    .global sym_06042A8C
sym_06042A8C:
    mov #-0x50, r6
    mov #-0x9, r3
    mov.l @r4, r2
    mov #0x4, r7
    mov.l @r6, r5
    and r3, r5
    or r2, r5
    mov.l @(8, r4), r3
    and r7, r3
    cmp/eq r7, r3
    bf      .L_skip_bit1_clear
    mov #-0x2, r3
    and r3, r5
    mov.l @(4, r4), r2
    or r2, r5
.L_skip_bit1_clear:
    mov #0x1, r7
    mov.l @(8, r4), r3
    and r7, r3
    cmp/eq r7, r3
    bf      .L_skip_bit2_clear
    mov #-0x5, r3
    and r3, r5
.L_skip_bit2_clear:
    mov #0x2, r7
    mov.l @(8, r4), r2
    and r7, r2
    cmp/eq r7, r2
    bf      .L_skip_bits01_clear
    mov #-0x3, r2
    and r2, r5
.L_skip_bits01_clear:
    rts
    mov.l r5, @r6
