	.text
    .global vram_alloc_mgr
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
    .short  0xFFFF
    .long  sym_0605F498
    .long  sym_06035168                  /* secondary SH-2 command handler entry */
    .long  sym_06087804
.L_0601FE00:
    .long  sym_060877F8
.L_0601FE04:
    .long  sym_0607EBC4
.L_0601FE08:
    .long  0x00800000
.L_0601FE0C:
    .long  sym_0607EAD8
.L_0601FE10:
    .long  sym_0605F62C
.L_0601FE14:
    .long  sym_0605F5EC
.L_0601FE18:
    .long  sym_060877F4
.L_0601FE1C:
    .long  g_game_state
