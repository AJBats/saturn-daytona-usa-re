
    .section .text.FUN_060389A6


    .global scene_data_dispatch
    .type scene_data_dispatch, @function
scene_data_dispatch:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x18    /* mov.l .Lpool_ready_flag_ptr, r14 */  ! r14 = &scene_ready_flag (sym_060635AC)
    mov.w @r14, r0
    bra     .Ldispatch_switch
    extu.w r0, r0
.Lflag_1_block_copy:
    .byte   0xBF, 0x85    /* bsr 0x060388C0 (external) */  ! call scene_data_block_copy
    nop
    bra     .Lclear_flag_and_return
    nop
.Lflag_2_indexed_copy:
    .byte   0xD6, 0x15    /* mov.l .Lpool_entry_count_a_ptr, r6 */  ! r6 = &entry_count_a (sym_060635A0)
    .byte   0xD5, 0x15    /* mov.l .Lpool_scene_a_src, r5 */       ! r5 = &scene_a_source_ptr (sym_060A3D74)
    .byte   0xD4, 0x16    /* mov.l .Lpool_scene_a_dst, r4 */       ! r4 = &scene_a_dest_ptr (sym_060A3D70)
    mov.w @r6, r6
    mov.l @r5, r5
    extu.w r6, r6
    mov r6, r3
    shll2 r6
    shll2 r3
    shll r3
    add r3, r6
    bsr     sym_06038A48
    mov.l @r4, r4
    .byte   0xD6, 0x11    /* mov.l .Lpool_entry_count_b_ptr, r6 */ ! r6 = &entry_count_b (sym_060635A2)
    .byte   0xD5, 0x12    /* mov.l .Lpool_scene_b_src, r5 */      ! r5 = &scene_b_source_ptr (sym_060A3D7C)
    .byte   0xD4, 0x12    /* mov.l .Lpool_scene_b_dst, r4 */      ! r4 = &scene_b_dest_ptr (sym_060A3D78)
    mov.w @r6, r6
    mov.l @r5, r5
    extu.w r6, r6
    shll2 r6
    bsr     sym_06038A48
    mov.l @r4, r4
    .byte   0xBF, 0x6B    /* bsr 0x060388C0 (external) */  ! call scene_data_block_copy
    nop
.Lclear_flag_and_return:
    mov #0x0, r2
    bra     .Lepilog_return
    mov.w r2, @r14
    .4byte  0x00B000C0
    .4byte  sym_060A3D84
    .4byte  sym_060A3D88
    .4byte  sym_060A3DB0
    .4byte  sym_060A3DF8
    .4byte  sym_060A3E38
    .4byte  sym_060A3E48
.Lpool_ready_flag_ptr:
    .4byte  sym_060635AC
.Lpool_entry_count_a_ptr:
    .4byte  sym_060635A0
.Lpool_scene_a_src:
    .4byte  sym_060A3D74
.Lpool_scene_a_dst:
    .4byte  sym_060A3D70
.Lpool_entry_count_b_ptr:
    .4byte  sym_060635A2
.Lpool_scene_b_src:
    .4byte  sym_060A3D7C
.Lpool_scene_b_dst:
    .4byte  sym_060A3D78
.Ldispatch_switch:
    cmp/eq #0x1, r0
    bt      .Lflag_1_block_copy
    cmp/eq #0x2, r0
    bt      .Lflag_2_indexed_copy
    cmp/eq #0x3, r0
    bt      .Lepilog_return
    cmp/eq #0x4, r0
    bt      .Lepilog_return
    cmp/eq #0x5, r0
    bt      .Lepilog_return
    cmp/eq #0x6, r0
    bt      .Lepilog_return
    cmp/eq #0x7, r0
.Lepilog_return:
    lds.l @r15+, pr
    .byte   0xA0, 0x40    /* bra 0x06038AC8 (external) */  ! tail-call display_extra_config
    mov.l @r15+, r14

    .global sym_06038A48
sym_06038A48:
    shlr r6
    mov #0x0, r7
    mov r7, r3
    cmp/hs r6, r3
    bt      .Lcopy_done
.Lcopy_loop:
    add #0x1, r7
    mov.w @r5, r3
    mov.w r3, @r4
    add #0x2, r4
    cmp/hs r6, r7
    bf/s    .Lcopy_loop
    add #0x2, r5
.Lcopy_done:
    rts
    nop
