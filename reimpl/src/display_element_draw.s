
    .section .text.FUN_0603D5D0


    .global display_element_draw
    .type display_element_draw, @function
display_element_draw:
    sts.l pr, @-r15
    mov #0x1, r6
    mov.l   .L_mask_clear_bit0, r7
    mov.l   .L_ptr_config_base, r5
    mov.l   .L_ptr_elem_base, r4
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    mov r6, r0
    jsr @r3
    mov r5, r2
    mov.w @r4, r2
    mov r6, r0
    extu.w r2, r2
    and r7, r2
    mov.w r2, @r4
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    mov.l   .L_mask_clear_bit1, r3
    extu.w r2, r2
    and r3, r2
    mov.w r2, @r4
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    mov.l   .L_mask_clear_bit2, r3
    extu.w r2, r2
    and r3, r2
    mov.w r2, @r4
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    mov.l   .L_mask_clear_bit3, r3
    extu.w r2, r2
    and r3, r2
    mov.w r2, @r4
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    mov.l   .L_mask_clear_bit4, r3
    extu.w r2, r2
    and r3, r2
    mov.w r2, @r4
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    mov.l   .L_mask_clear_bit5, r3
    extu.w r2, r2
    and r3, r2
    mov.w r2, @r4
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    mov.l   .L_mask_clear_bit6, r3
    extu.w r2, r2
    and r3, r2
    mov.w r2, @r4
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov.l   .L_mask_clear_bit1, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov.l   .L_mask_clear_bit2, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov.l   .L_mask_clear_bit3, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_chan5_id, r1
    mov.l   .L_fn_bitfield_commit, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    mov.l   .L_mask_clear_bit4, r3
    and r3, r2
    extu.w r2, r0
    bra     .L_clear_flags_b
    nop
.L_chan5_id:
    .2byte  0x0501
    .2byte  0xFFFF
.L_mask_clear_bit0:
    .4byte  0x0000FFFE
.L_ptr_config_base:
    .4byte  sym_060A4D58
.L_ptr_elem_base:
    .4byte  sym_060A4D46
.L_fn_bitfield_commit:
    .4byte  sym_06034F78
.L_mask_clear_bit1:
    .4byte  0x0000FFFD
.L_mask_clear_bit2:
    .4byte  0x0000FFFB
.L_mask_clear_bit3:
    .4byte  0x0000FFF7
.L_mask_clear_bit4:
    .4byte  0x0000FFEF
.L_mask_clear_bit5:
    .4byte  0x0000FFDF
.L_mask_clear_bit6:
    .4byte  0x0000FFBF
.L_clear_flags_b:
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov.l   .L_mask_clear_bit5_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov #0x0, r7
    mov.l   .L_mask_clear_bit6_b, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    extu.w r7, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    extu.w r7, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    extu.w r7, r0
    mov.w r0, @(8, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    extu.w r7, r0
    mov.w r0, @(10, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    extu.w r7, r0
    mov.w r0, @(12, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    extu.w r7, r0
    mov.w r0, @(14, r4)
    mov r6, r0
    mov.w   .L_chan5_id_b, r1
    mov.l   .L_fn_bitfield_commit_b, r3
    jsr @r3
    mov r5, r2
    lds.l @r15+, pr
    rts
    nop
.L_chan5_id_b:
    .2byte  0x0501
    .2byte  0xFFFF
.L_fn_bitfield_commit_b:
    .4byte  sym_06034F78
.L_mask_clear_bit5_b:
    .4byte  0x0000FFDF
.L_mask_clear_bit6_b:
    .4byte  0x0000FFBF
