
    .section .text.FUN_0603D518


    .global name_entry_render
    .type name_entry_render, @function
name_entry_render:
    sts.l pr, @-r15
    mov r6, r0
    mov.l   .L_mask_byte1, r7
    mov.l   .L_pool_config_byte_ptr, r5
    mov.l   .L_pool_scroll_cfg_a, r4
    mov.w   .L_bitfield_pos_count, r1
    mov.l   .L_pool_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r7, r2
    mov.w r2, @r4
    mov.w   DAT_0603d5be, r14
    mov.w   .L_bitfield_pos_count, r1
    mov.l   .L_pool_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r14, r2
    mov.w r2, @r4
    mov.w   .L_bitfield_pos_count, r1
    mov.l   .L_pool_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_bitfield_pos_count, r1
    mov.l   .L_pool_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_bitfield_pos_count, r1
    mov.l   .L_pool_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov #0x0, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_bitfield_pos_count, r1
    mov.l   .L_pool_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_bitfield_pos_count, r1
    mov.l   .L_pool_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_bitfield_pos_count, r1
    mov.l   .L_pool_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_bitfield_pos_count:
    .2byte  0x0401                         /* [MEDIUM] bit position (4) | count (1) for bitfield commit */


    .global DAT_0603d5be
DAT_0603d5be:
    .2byte  0x00FF
.L_mask_byte1:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_pool_config_byte_ptr:
    .4byte  sym_060A4D58
.L_pool_scroll_cfg_a:
    .4byte  sym_060A4D3E
.L_pool_fn_bitfield_commit:
    .4byte  sym_06034F78
