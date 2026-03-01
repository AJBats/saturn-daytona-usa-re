
    .section .text.FUN_0603D2D0


    .global high_score_render
    .type high_score_render, @function
high_score_render:
    sts.l pr, @-r15
    mov r6, r0
    mov.l   .L_mask_low_nibble, r7
    mov.l   .L_src_table_ptr, r5
    mov.l   .L_cfg_word_array, r4
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r7, r2
    mov.w r2, @r4
    mov.l   .L_mask_mid_nibble, r14
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r14, r2
    mov.w r2, @r4
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_nibble_pos_count, r1
    mov.l   .L_bitfield_rmw_fn, r3
    jsr @r3
    mov r5, r2
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_nibble_pos_count:
    .2byte  0x0101                          /* [MEDIUM] nibble position/count param for bitfield RMW */
.L_mask_low_nibble:
    .4byte  0x0000FFF0                      /* mask to clear low nibble (bits 0-3) */
.L_src_table_ptr:
    .4byte  sym_060A4D58                    /* source parameter table */
.L_cfg_word_array:
    .4byte  sym_060A4D28                    /* config word array (4 words at offsets 0/2/4/6) */
.L_bitfield_rmw_fn:
    .4byte  sym_06034F78                    /* bitfield read-modify-write utility */
.L_mask_mid_nibble:
    .4byte  0x0000F0FF                      /* mask to clear mid nibble (bits 8-11) */
