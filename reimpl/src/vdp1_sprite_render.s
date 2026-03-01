
    .section .text.FUN_06007658


    .global vdp1_sprite_render
    .type vdp1_sprite_render, @function
vdp1_sprite_render:
    mov.l r14, @-r15
    extu.w r4, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x10, r15
    mov.l   _pool_slot_data_table, r12
    mov.l   _pool_vram_offset_ptr, r13
    mov.l   _pool_sprite_index_ptr, r14
    mov.l r7, @(4, r15)
    cmp/eq #0xA, r0
    bf      .L_06007682
    mov.l @r13, r2
    shll2 r2
    shll r2
    mov.l   _pool_vram_base_ptr, r3
    mov.l @r3, r3
    add r3, r2
    mov.l   _pool_vram_addr_store, r1
    mov.l r2, @r1
.L_06007682:
    extu.w r5, r0
    extu.w r4, r2
    mov.l r0, @r15
    shll r2
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
    mov.w r0, @(8, r15)
    mov.w   _wpool_lo_byte_mask, r7
    mov.l @r15, r3
    and r7, r3
    extu.w r3, r3
    mov r3, r0
    mov.w r0, @(12, r15)
    mov.l   _pool_slot_index_table, r1
    mov.l @r14, r0
    add r1, r2
    mov.w r0, @r2
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r12, r3
    mov.l @r13, r2
    mov.l r2, @r3
    extu.w r4, r1
    mov r1, r0
    cmp/eq #0xD, r0
    bt      .L_060076FC
    mov r1, r0
    cmp/eq #0xE, r0
    bt      .L_060076FC
    mov r1, r0
    cmp/eq #0xF, r0
    bt      .L_060076FC
    mov.l @r14, r2
    shll2 r2
    shll r2
    add r12, r2
    mov r5, r0
    bra     .L_06007732
    mov.w r0, @(4, r2)

    .global DAT_060076e2
_wpool_lo_byte_mask:
DAT_060076e2:
    .2byte  0x00FF
_pool_slot_data_table:
    .4byte  sym_06063F64
_pool_vram_offset_ptr:
    .4byte  sym_0606A4EC
_pool_sprite_index_ptr:
    .4byte  sym_0606A4F4
_pool_vram_base_ptr:
    .4byte  sym_06063F5C
_pool_vram_addr_store:
    .4byte  sym_06063F60
_pool_slot_index_table:
    .4byte  sym_060684EC
.L_060076FC:
    extu.w r5, r4
    mov #0x3, r0
    mov.w   _wpool_color_hi_mask, r2
    mov r4, r5
    and r4, r2
    and r7, r5
    extu.w r2, r2
    extu.w r5, r1
    mov.w r2, @r15
    mov.l   _pool_fn_color_lookup, r3
    jsr @r3
    extu.w r1, r1
    mov r0, r5
    mov.w @r15, r3
    extu.w r5, r1
    extu.w r3, r3
    or r3, r1
    extu.w r1, r5
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r12, r3
    mov r5, r0
    mov.w r0, @(4, r3)
    mov.l @r13, r3
    mov.l   _pool_saved_index_store, r2
    mov.l r3, @r2
.L_06007732:
    mov r6, r0
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r12, r3
    mov.w r0, @(6, r3)
    mov.l @r13, r5
    mov.l   _pool_vram_base_ptr_b, r3
    mov.l   _pool_fn_dma_transfer, r2
    shll2 r5
    mov.l @r3, r3
    shll r5
    add r3, r5
    jsr @r2
    mov.l @(4, r15), r4
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov.w @(8, r15), r0
    mov.l @r13, r2
    mov r0, r4
    mov.w @(12, r15), r0
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

    .global DAT_0600777e
_wpool_color_hi_mask:
DAT_0600777e:
    .2byte  0x3F00
_pool_fn_color_lookup:
    .4byte  sym_06034FE0
_pool_saved_index_store:
    .4byte  sym_0606A4F0
_pool_vram_base_ptr_b:
    .4byte  sym_06063F5C
_pool_fn_dma_transfer:
    .4byte  dma_memory_transfer
