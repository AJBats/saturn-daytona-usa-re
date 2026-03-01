
    .section .text.FUN_0601FD9C


    .global vram_alloc_mgr
    .type vram_alloc_mgr, @function
vram_alloc_mgr:
    sts.l pr, @-r15
    mov.l   .L_ptr_active_alloc, r4
    mov.l   .L_ptr_mode_flags, r3
    mov.l   .L_mask_bit23, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_use_table_b
    mov.l   .L_ptr_slot_index, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_ptr_table_a, r2
    add r2, r3
    mov.l @r3, r1
    bra     .L_store_alloc_ptr
    nop
.L_use_table_b:
    mov.l   .L_ptr_slot_index, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_ptr_table_b, r2
    add r2, r3
    mov.l @r3, r1
.L_store_alloc_ptr:
    mov.l r1, @r4
    mov r1, r2
    mov.l @r2, r3
    mov.l   .L_ptr_disp_desc, r1
    mov.l r3, @r1
    .byte   0xB0, 0x25    /* bsr 0x0601FE20 (external) */
    nop
    mov.l   .L_ptr_game_state, r4
    mov.l @r4, r0
    cmp/eq #0x17, r0
    .word 0x0129
    cmp/eq #0x16, r0
    .word 0x0029
    or r1, r0
    tst r0, r0
    bt      .L_return_normal
    .byte   0xA1, 0x5C    /* bra 0x060200A4 (external) */
    lds.l @r15+, pr
.L_return_normal:
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF                        /* padding / alignment */
    .4byte  sym_0605F498                  /* function table: [vram_alloc_mgr, geom_display_handler, vram_ptr_get, loc_06020090] */
    .4byte  sym_06035168                  /* secondary SH-2 command handler entry */
    .4byte  sym_06087804                  /* handler mode word (geom_display_handler state) */
.L_ptr_active_alloc:
    .4byte  sym_060877F8                  /* &active_alloc_ptr (selected descriptor) */
.L_ptr_mode_flags:
    .4byte  sym_0607EBC4                  /* &mode_flags (bit 23 = table A vs B select) */
.L_mask_bit23:
    .4byte  0x00800000                    /* bit-23 isolation mask for table select */
.L_ptr_slot_index:
    .4byte  sym_0607EAD8                  /* &slot_index (current car slot, used as table row) */
.L_ptr_table_a:
    .4byte  sym_0605F62C                  /* alloc table A base (video mode A, 3 entries) */
.L_ptr_table_b:
    .4byte  sym_0605F5EC                  /* alloc table B base (video mode B, 3 entries) */
.L_ptr_disp_desc:
    .4byte  sym_060877F4                  /* &disp_desc_ptr (written before geom call) */
.L_ptr_game_state:
    .4byte  g_game_state                  /* &game_state word (0x16/0x17 = race-start) */
