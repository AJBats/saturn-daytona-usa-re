/* vdp_init_advanced -- VDP1 display list initialization and text overlay
 * Translation unit: 0x0600330A - 0x06003466
 *
 * Contains four functions for VDP display list setup:
 *
 * vdp_init_advanced:
 *   Loads three display list segments from the scene config table
 *   (sym_06063750) into VDP1 VRAM via the display list loader
 *   (sym_06028400). Each segment has a different table offset,
 *   VRAM destination, and transfer size. Called during scene
 *   initialization to populate VDP1 command tables.
 *
 * sym_0600338C (dlist_slot_select):
 *   Selects and loads a VDP1 display list based on a slot mode flag.
 *   If bit 2 of arg is set: checks advanced display status word for
 *   bit 9 (interlace/hires); if clear, computes a VRAM offset from a
 *   per-slot struct and calls the display list loader. If bit 2 clear:
 *   uses a static element table source and tail-calls the geometry
 *   dispatch function.
 *
 * sym_060033E6 (replay_text_overlay):
 *   Checks environment flags for bit 2. Based on result, renders
 *   either the "REPLAY" string or an alternate text source via
 *   the VDP number/text renderer (sym_060284AE).
 *
 * sym_06003430 (dlist_variant_load):
 *   Checks a byte flag; if zero, loads display data from one table
 *   entry, otherwise loads from an alternate. Both paths tail-call
 *   the geometry dispatch function.
 *
 * Key symbols:
 *   sym_06063750  -- scene config / display list table base
 *   sym_06028400  -- display list loader (dma copy to VDP1 VRAM)
 *   sym_060284AE  -- VDP number/text renderer
 *   sym_06063DA0  -- advanced display status flags (16-bit)
 *   sym_06063AD0  -- per-slot display struct array
 *   sym_0607EBC8  -- environment/replay flags
 *   sym_06044638  -- "REPLAY" string constant
 *   sym_0605ACDD  -- static display element data
 *   sym_0605ACF0  -- alternate text data
 */

    .section .text.FUN_0600330A


    .global vdp_init_advanced
    .type vdp_init_advanced, @function
vdp_init_advanced:
    mov.l r14, @-r15                        ! save r14
    mov.l r13, @-r15                        ! save r13
    sts.l pr, @-r15                         ! save return address
    add #-0x4, r15                          ! allocate 4 bytes on stack
    .byte   0xDD, 0x1C    /* mov.l _pool_scene_table, r13 */
    .byte   0xDE, 0x1C    /* mov.l _pool_dlist_loader, r14 */
    mov.w   _w_tbl_offset_0, r7            ! r7 = 0x0368 (table offset for segment 0)
    add r13, r7                             ! r7 = &scene_table[0x0368]
    mov.l r7, @r15                          ! stack[0] = entry pointer
    mov.l @(4, r7), r7                      ! r7 = entry[1] (source data ptr)
    mov.w   _w_vram_dest_0, r3             ! r3 = 0x3000 (VDP1 VRAM dest offset)
    mov.w   _w_xfer_size_0, r6            ! r6 = 0x0BC8 (transfer byte count)
    mov.l @r15, r5                          ! r5 = entry pointer
    add r3, r7                              ! r7 = source + VRAM offset
    mov.l @r5, r5                           ! r5 = entry[0] (dest base addr)
    jsr @r14                                ! call display list loader
    mov #0xC, r4                            ! r4 = 0xC (DMA mode: block copy)
    mov.w   _w_tbl_offset_1, r7            ! r7 = 0x0378 (table offset for segment 1)
    add r13, r7                             ! r7 = &scene_table[0x0378]
    mov.l r7, @r15                          ! stack[0] = entry pointer
    mov.l @(4, r7), r7                      ! r7 = entry[1] (source data ptr)
    mov.w   _w_vram_dest_1, r3             ! r3 = 0x4000 (VDP1 VRAM dest offset)
    mov.w   _w_xfer_size_1, r6            ! r6 = 0x00C6 (transfer byte count)
    mov.l @r15, r5                          ! r5 = entry pointer
    add r3, r7                              ! r7 = source + VRAM offset
    mov.l @r5, r5                           ! r5 = entry[0] (dest base addr)
    jsr @r14                                ! call display list loader
    mov #0xC, r4                            ! r4 = 0xC (DMA mode: block copy)
    mov.w   _w_tbl_offset_2, r7            ! r7 = 0x0370 (table offset for segment 2)
    add r13, r7                             ! r7 = &scene_table[0x0370]
    mov.l r7, @r15                          ! stack[0] = entry pointer
    mov.l @(4, r7), r7                      ! r7 = entry[1] (source data ptr)
    mov.w   _w_vram_dest_2, r3             ! r3 = 0x5000 (VDP1 VRAM dest offset)
    mov.w   _w_xfer_size_2, r6            ! r6 = 0x0C02 (transfer byte count)
    mov.l @r15, r5                          ! r5 = entry pointer
    add r3, r7                              ! r7 = source + VRAM offset
    mov.l @r5, r5                           ! r5 = entry[0] (dest base addr)
    jsr @r14                                ! call display list loader
    mov #0xC, r4                            ! r4 = 0xC (DMA mode: block copy)
    add #0x4, r15                           ! deallocate stack frame
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! restore r14 (delay slot)
    .2byte  0x0D00                          ! padding / alignment
    .2byte  0x0D80                          ! padding / alignment

    .global DAT_06003366
_w_tbl_offset_0:
DAT_06003366:
    .2byte  0x0368                          ! scene table offset for segment 0

    .global DAT_06003368
_w_vram_dest_0:
DAT_06003368:
    .2byte  0x3000                          ! VDP1 VRAM dest offset for segment 0
_w_xfer_size_0:
    .2byte  0x0BC8                          ! transfer size for segment 0

    .global DAT_0600336c
_w_tbl_offset_1:
DAT_0600336c:
    .2byte  0x0378                          ! scene table offset for segment 1

    .global DAT_0600336e
_w_vram_dest_1:
DAT_0600336e:
    .2byte  0x4000                          ! VDP1 VRAM dest offset for segment 1

    .global DAT_06003370
_w_xfer_size_1:
DAT_06003370:
    .2byte  0x00C6                          ! transfer size for segment 1

    .global DAT_06003372
_w_tbl_offset_2:
DAT_06003372:
    .2byte  0x0370                          ! scene table offset for segment 2

    .global DAT_06003374
_w_vram_dest_2:
DAT_06003374:
    .2byte  0x5000                          ! VDP1 VRAM dest offset for segment 2

    .global DAT_06003376
_w_xfer_size_2:
DAT_06003376:
    .2byte  0x0C02                          ! transfer size for segment 2
    .4byte  sym_06059ECE                    ! (unreferenced pool entry)
    .4byte  sym_060283E0                    ! (unreferenced pool entry)
    .4byte  0x0000F000                      ! (unreferenced constant)
_pool_scene_table:
    .4byte  sym_06063750                    ! scene config / display list table base
_pool_dlist_loader:
    .4byte  sym_06028400                    ! display list loader function

    .global sym_0600338C
sym_0600338C:
    add #-0x8, r15                          ! allocate 8 bytes on stack
    mov #0x4, r3                            ! r3 = 0x4 (bit 2 mask)
    mov.l r5, @r15                          ! stack[0] = r5 (slot index arg)
    and r3, r4                              ! r4 = arg & 0x4 (isolate bit 2)
    tst r4, r4                              ! test if bit 2 is clear
    bt      .L_bit2_clear                   ! branch if bit 2 == 0
    .byte   0xD3, 0x1D    /* mov.l _pool_adv_display_status, r3 */
    mov.w @r3, r2                           ! r2 = advanced display status word
    extu.w r2, r2                           ! zero-extend to 32 bits
    mov.w   _w_interlace_mask, r3          ! r3 = 0x0200 (bit 9 = interlace/hires)
    and r3, r2                              ! r2 = status & 0x0200
    tst r2, r2                              ! test if interlace bit is clear
    bf      .L_interlace_active             ! branch if interlace is active (skip load)
    .byte   0xD3, 0x1B    /* mov.l _pool_slot_struct_base, r3 */
    mov.l r3, @(4, r15)                    ! stack[4] = slot struct base ptr
    mov r3, r7                              ! r7 = slot struct base
    mov.l @r15, r6                          ! r6 = slot index arg
    mov.l @(4, r7), r7                      ! r7 = slot_struct[1] (source data)
    mov.w   _w_slot_vram_offset, r3        ! r3 = 0x5000 (VDP1 VRAM dest offset)
    shll2 r6                                ! r6 *= 4
    add r3, r7                              ! r7 = source + VRAM offset
    shll2 r6                                ! r6 *= 4 (total: *16)
    shll2 r6                                ! r6 *= 4 (total: *64)
    add #0xB, r6                            ! r6 += 0xB (byte offset within slot)
    shll r6                                 ! r6 *= 2 (total: *128 + 0x16)
    mov.l @(4, r15), r5                    ! r5 = slot struct base ptr
    mov.l @r5, r5                           ! r5 = slot_struct[0] (dest base addr)
    mov #0xC, r4                            ! r4 = 0xC (DMA mode: block copy)
    .byte   0xD3, 0x14    /* mov.l _pool_fn_dlist_loader, r3 */
    jmp @r3                                 ! tail-call display list loader
    add #0x8, r15                           ! deallocate stack (delay slot)
.L_bit2_clear:
    mov #0x60, r6                           ! r6 = 0x60 (static element size)
    mov.l @r15, r5                          ! r5 = slot index arg
    .byte   0xD7, 0x13    /* mov.l _pool_static_elem_data, r7 */
    shll2 r5                                ! r5 *= 4
    shll2 r5                                ! r5 *= 4 (total: *16)
    shll2 r5                                ! r5 *= 4 (total: *64)
    add #0xB, r5                            ! r5 += 0xB
    shll r5                                 ! r5 *= 2 (total: *128 + 0x16)
    mov #0xC, r4                            ! r4 = 0xC (DMA mode: block copy)
    .byte   0xD3, 0x10    /* mov.l _pool_fn_geom_dispatch, r3 */
    jmp @r3                                 ! tail-call geometry dispatch
    add #0x8, r15                           ! deallocate stack (delay slot)
.L_interlace_active:
    rts                                     ! return (no-op when interlace active)
    add #0x8, r15                           ! deallocate stack (delay slot)

    .global sym_060033E6
sym_060033E6:
    .byte   0xD0, 0x0F    /* mov.l _pool_env_flags, r0 */
    mov.l @r0, r0                           ! r0 = environment/replay flags
    tst #0x4, r0                            ! test bit 2 (replay active?)
    bt      .L_no_replay                    ! branch if replay not active
    .byte   0xD7, 0x0E    /* mov.l _pool_replay_string, r7 */
    mov.w   _w_text_size, r6              ! r6 = 0x0090 (text element byte count)
    mov.w   _w_text_vram_dest, r5         ! r5 = 0x0C04 (VDP text dest offset)
    .byte   0xD3, 0x0A    /* mov.l _pool_fn_geom_dispatch, r3 */
    jmp @r3                                 ! tail-call geometry dispatch
    mov #0x8, r4                            ! r4 = 0x8 (text render mode, delay slot)
.L_no_replay:
    .byte   0xD7, 0x0C    /* mov.l _pool_alt_text_data, r7 */
    mov.w   _w_text_size, r6              ! r6 = 0x0090 (text element byte count)
    mov.w   _w_text_vram_dest, r5         ! r5 = 0x0C04 (VDP text dest offset)
    .byte   0xD3, 0x07    /* mov.l _pool_fn_geom_dispatch, r3 */
    jmp @r3                                 ! tail-call geometry dispatch
    mov #0x8, r4                            ! r4 = 0x8 (text render mode, delay slot)

    .global DAT_06003406
_w_interlace_mask:
DAT_06003406:
    .2byte  0x0200                          ! bit 9 mask (interlace/hires flag)

    .global DAT_06003408
_w_slot_vram_offset:
DAT_06003408:
    .2byte  0x5000                          ! VDP1 VRAM dest offset for slot load
_w_text_size:
    .2byte  0x0090                          ! text element byte count

    .global DAT_0600340c
_w_text_vram_dest:
DAT_0600340c:
    .2byte  0x0C04                          ! VDP text destination offset
    .2byte  0xFFFF                          ! alignment padding
_pool_adv_display_status:
    .4byte  sym_06063DA0                    ! advanced display status flags (16-bit)
_pool_slot_struct_base:
    .4byte  sym_06063AD0                    ! per-slot display struct array
_pool_fn_dlist_loader:
    .4byte  sym_06028400                    ! display list loader function
_pool_static_elem_data:
    .4byte  sym_0605ACDD                    ! static display element data base
_pool_fn_geom_dispatch:
    .4byte  sym_060284AE                    ! VDP number/text renderer (geometry dispatch)
_pool_env_flags:
    .4byte  sym_0607EBC8                    ! environment/replay flags
_pool_replay_string:
    .4byte  sym_06044638                    ! "REPLAY" string constant
_pool_alt_text_data:
    .4byte  sym_0605ACF0                    ! alternate text data source

    .global sym_06003430
sym_06003430:
    add #-0x4, r15                          ! allocate 4 bytes on stack
    .byte   0xD3, 0x1B    /* mov.l .L_pool_060034A0, r3 */
    mov.b @r3, r3                           ! r3 = byte flag (variant selector)
    tst r3, r3                              ! test if flag is zero
    bf      .L_variant_b                    ! branch if flag nonzero (variant B)
    .byte   0xD3, 0x1A    /* mov.l .L_pool_060034A4, r3 */
    mov.l r3, @r15                          ! stack[0] = table entry A base ptr
    mov r3, r7                              ! r7 = table entry A base
    mov.l @(4, r7), r7                      ! r7 = entry_A[1] (source data)
    .byte   0x96, 0x29    /* mov.w .L_wpool_06003498, r6 */
    mov r3, r5                              ! r5 = table entry A base
    mov.l @r5, r5                           ! r5 = entry_A[0] (dest base addr)
    mov #0x4, r4                            ! r4 = 0x4 (DMA mode: word copy)
    .byte   0xD3, 0x17    /* mov.l .L_pool_060034A8, r3 */
    jmp @r3                                 ! tail-call geometry dispatch
    add #0x4, r15                           ! deallocate stack (delay slot)
.L_variant_b:
    .byte   0xD2, 0x16    /* mov.l .L_pool_060034AC, r2 */
    mov.l r2, @r15                          ! stack[0] = table entry B base ptr
    mov r2, r7                              ! r7 = table entry B base
    mov.l @(4, r7), r7                      ! r7 = entry_B[1] (source data)
    .byte   0x96, 0x1F    /* mov.w .L_wpool_0600349A, r6 */
    mov r2, r5                              ! r5 = table entry B base
    mov.l @r5, r5                           ! r5 = entry_B[0] (dest base addr)
    mov #0x4, r4                            ! r4 = 0x4 (DMA mode: word copy)
    .byte   0xD3, 0x11    /* mov.l .L_pool_060034A8, r3 */
    jmp @r3                                 ! tail-call geometry dispatch
    add #0x4, r15                           ! deallocate stack (delay slot)
