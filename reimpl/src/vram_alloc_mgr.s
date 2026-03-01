
    .section .text.FUN_0601FD9C


    .global vram_alloc_mgr
    .type vram_alloc_mgr, @function
vram_alloc_mgr:
    sts.l pr, @-r15
    mov.l   .L_0601FE00, r4
    mov.l   .L_0601FE04, r3
    mov.l   .L_0601FE08, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0601FDBC
    mov.l   .L_0601FE0C, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_0601FE10, r2
    add r2, r3
    mov.l @r3, r1
    bra     .L_0601FDC8
    nop
.L_0601FDBC:
    mov.l   .L_0601FE0C, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_0601FE14, r2
    add r2, r3
    mov.l @r3, r1
.L_0601FDC8:
    mov.l r1, @r4
    mov r1, r2
    mov.l @r2, r3
    mov.l   .L_0601FE18, r1
    mov.l r3, @r1
    .byte   0xB0, 0x25    /* bsr 0x0601FE20 (external) */
    nop
    mov.l   .L_0601FE1C, r4
    mov.l @r4, r0
    cmp/eq #0x17, r0
    .word 0x0129
    cmp/eq #0x16, r0
    .word 0x0029
    or r1, r0
    tst r0, r0
    bt      .L_0601FDEC
    .byte   0xA1, 0x5C    /* bra 0x060200A4 (external) */
    lds.l @r15+, pr
.L_0601FDEC:
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF                        /* padding / alignment */
    .4byte  sym_0605F498                  /* function table: [vram_alloc_mgr, geom_display_handler, vram_ptr_get, loc_06020090] */
    .4byte  sym_06035168                  /* secondary SH-2 command handler entry */
    .4byte  sym_06087804                  /* handler mode word (geom_display_handler state) */
.L_0601FE00:
    .4byte  sym_060877F8                  /* &active_alloc_ptr (selected descriptor) */
.L_0601FE04:
    .4byte  sym_0607EBC4                  /* &mode_flags (bit 23 = table A vs B select) */
.L_0601FE08:
    .4byte  0x00800000                    /* bit-23 isolation mask for table select */
.L_0601FE0C:
    .4byte  sym_0607EAD8                  /* &slot_index (current car slot, used as table row) */
.L_0601FE10:
    .4byte  sym_0605F62C                  /* alloc table A base (video mode A, 3 entries) */
.L_0601FE14:
    .4byte  sym_0605F5EC                  /* alloc table B base (video mode B, 3 entries) */
.L_0601FE18:
    .4byte  sym_060877F4                  /* &disp_desc_ptr (written before geom call) */
.L_0601FE1C:
    .4byte  g_game_state                  /* &game_state word (0x16/0x17 = race-start) */
