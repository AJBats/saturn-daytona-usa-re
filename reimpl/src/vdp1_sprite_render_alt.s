
    .section .text.FUN_06007790


    .global vdp1_sprite_render_alt
    .type vdp1_sprite_render_alt, @function
vdp1_sprite_render_alt:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x10, r15
    mov.l   _pool_slot_data_table, r12
    mov.l   _pool_slot_counter, r13
    mov.l   _pool_slot_config, r14
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0xA, r0
    bf      .L_060077BA
    mov.l @r13, r2
    shll2 r2
    shll r2
    mov.l   _pool_display_base_ptr, r3
    mov.l @r3, r3
    add r3, r2
    mov.l   _pool_dma_dest_ptr, r1
    mov.l r2, @r1
.L_060077BA:
    mov.w @(2, r4), r0
    mov r0, r7
    extu.w r7, r0
    mov.l r0, @r15
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    and #0x3F, r0
    extu.w r0, r0
    mov.w r0, @(12, r15)
    mov.l @r15, r0
    and #0xFF, r0
    extu.w r0, r0
    mov.w r0, @(8, r15)
    mov.w @r4, r3
    mov.l   _pool_cmd_jump_table, r2
    mov.l @r14, r1
    extu.w r3, r3
    shll r3
    add r2, r3
    mov.w r1, @r3
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r12, r3
    mov.l @r13, r2
    mov.l r2, @r3
    mov.w @r4, r1
    extu.w r1, r1
    mov r1, r0
    cmp/eq #0xD, r0
    bt      .L_06007838
    mov r1, r0
    cmp/eq #0xE, r0
    bt      .L_06007838
    mov r1, r0
    cmp/eq #0xF, r0
    bt      .L_06007838
    mov.l @r14, r2
    shll2 r2
    shll r2
    add r12, r2
    mov r7, r0
    bra     .L_06007870
    mov.w r0, @(4, r2)
    .2byte  0xFFFF                           /* alignment padding */
_pool_slot_data_table:
    .4byte  sym_06063F64                     /* per-slot data table base */
_pool_slot_counter:
    .4byte  sym_0606A4EC                     /* VDP1 command slot counter */
_pool_slot_config:
    .4byte  sym_0606A4F4                     /* VDP1 slot config register */
_pool_display_base_ptr:
    .4byte  sym_06063F5C                     /* display/scroll base table pointer */
_pool_dma_dest_ptr:
    .4byte  sym_06063F60                     /* DMA destination pointer */
_pool_cmd_jump_table:
    .4byte  sym_060684EC                     /* command type -> VRAM jump table */
.L_06007838:
    extu.w r7, r7
    mov.l r7, @(4, r15)
    mov.w   DAT_060078ca, r3
    and r3, r7
    extu.w r7, r7
    mov.w r7, @r15
    mov.l @(4, r15), r0
    mov.l   _pool_color_bank_lookup, r3
    and #0xFF, r0
    extu.w r0, r1
    mov #0x3, r0
    jsr @r3
    extu.w r1, r1
    mov r0, r7
    mov.w @r15, r3
    extu.w r7, r2
    extu.w r3, r3
    or r3, r2
    extu.w r2, r7
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r12, r3
    mov r7, r0
    mov.w r0, @(4, r3)
    mov.l @r13, r3
    mov.l   _pool_slot_counter_shadow, r2
    mov.l r3, @r2
.L_06007870:
    mov.l @r14, r3
    extu.w r5, r5
    mov.w @(4, r4), r0
    shll2 r3
    shll2 r5
    mov r0, r2
    shll r3
    extu.w r2, r2
    add r12, r3
    add r5, r2
    extu.w r2, r0
    mov.w r0, @(6, r3)
    mov.l @(8, r4), r4
    mov.l @r13, r5
    mov.l   _pool_display_base_ptr_b, r3
    mov.l   _pool_dma_transfer_fn, r2
    add r6, r4
    shll2 r5
    mov.l @r3, r3
    shll r5
    jsr @r2
    add r3, r5
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov.w @(12, r15), r0
    mov.l @r13, r2
    mov r0, r4
    mov.w @(8, r15), r0
    mov r0, r3
    mulu.w r3, r4
    mov #0x0, r3
    sts macl, r4
    cmp/gt r4, r3
    addc r3, r4
    shar r4
    add r4, r2
    mov.l r2, @r13
    add #0x10, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_060078ca
DAT_060078ca:
    .2byte  0x3F00                           /* color bank mask (bits 13:8) */
_pool_color_bank_lookup:
    .4byte  sym_06034FE0                     /* color bank lookup function */
_pool_slot_counter_shadow:
    .4byte  sym_0606A4F0                     /* slot counter shadow register */
_pool_display_base_ptr_b:
    .4byte  sym_06063F5C                     /* display/scroll base table pointer */
_pool_dma_transfer_fn:
    .4byte  dma_memory_transfer              /* DMA memory-to-memory copy */
