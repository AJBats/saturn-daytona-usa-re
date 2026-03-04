
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
    .reloc ., R_SH_IND12W, geom_display_handler - 4
    .2byte 0xB000    /* bsr geom_display_handler (linker-resolved) */
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
    .reloc ., R_SH_IND12W, race_start_obj_init - 4
    .2byte 0xA000    /* bra race_start_obj_init (linker-resolved) */
    lds.l @r15+, pr
.L_0601FDEC:
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF
    .4byte  sym_0605F498
    .4byte  sym_06035168                  /* secondary SH-2 command handler entry */
    .4byte  sym_06087804
.L_0601FE00:
    .4byte  sym_060877F8
.L_0601FE04:
    .4byte  sym_0607EBC4
.L_0601FE08:
    .4byte  0x00800000
.L_0601FE0C:
    .4byte  sym_0607EAD8
.L_0601FE10:
    .4byte  sym_0605F62C
.L_0601FE14:
    .4byte  sym_0605F5EC
.L_0601FE18:
    .4byte  sym_060877F4
.L_0601FE1C:
    .4byte  g_game_state
