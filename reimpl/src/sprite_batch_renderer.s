/* sprite_batch_renderer -- display channel table copy + display list dispatch
 * Translation unit: 0x0601155E - 0x060115F0
 *
 * Copies 28 display channel entries (4 bytes each = two 16-bit words) from a
 * dynamically-loaded source table into the flat display_channel_dest_table
 * (sym_0605AAA6), then tail-calls the display_list_loader (sym_06028400) to
 * commit them to the display system.
 *
 * The source table is accessed via double indirection: a pointer at
 * sym_06063788 points to a struct whose first dword is the source table base
 * (offset +4 past the header). Each source row has a stride of 88 bytes
 * (44 * 2), and the mode_index selects the 2-byte column within each row.
 *
 * After the copy loop, the function reads a second pointer from the struct
 * at sym_06063788+4 (e.g. a texture/palette data pointer), adds 0xF000 to it,
 * and passes it along with mode=8 and the masked mode_index to the
 * display_list_loader.
 *
 * Inputs:
 *   r4 = mode_index (16-bit) — selects column in source table and display
 *        list slot. Typically 0 for initial flush.
 *
 * Tail-calls:
 *   display_list_loader(r4=0x8, r5=&display_config_word, r6=(mode&0x3F)*2,
 *                       r7=struct_field2 + 0xF000)
 *
 * Data references:
 *   sym_06063788    = pointer to source data struct (double-indirected)
 *   sym_0605AAA6    = display_channel_dest_table (28 x 4-byte entries)
 *   sym_0605AAA2    = display_config_word (16-bit)
 *   sym_06028400    = display_list_loader function
 *
 * Cross-TU pool (DAT_060115c6 data area, shared with hud_layer_composite):
 *   DAT_060115c6    = 0x8000 (mov.w pool target for hud_layer_composite)
 *   sym_060447A4    = layer attribute data
 *   0x00010000      = fixed-point 1.0 / stride constant
 *   sym_060447A8    = target position table
 *   sym_06044764    = layer X-offset table
 *   sym_06044784    = layer Y-offset table
 */

    .section .text.FUN_0601155E


    .global sprite_batch_renderer
    .type sprite_batch_renderer, @function

/* ============================================================
 * sprite_batch_renderer
 *
 * Copy 28 display channel entries from a mode-indexed source
 * table (via pointer indirection) to the flat dest table, then
 * tail-call the display list loader to commit them.
 *
 * r4 = mode_index (16-bit)
 * Returns: does not return (tail-calls display_list_loader)
 * ============================================================ */
sprite_batch_renderer:
    mov.l r14, @-r15                        ! save r14 (callee-saved)
    mov.l r13, @-r15                        ! save r13 (callee-saved)
    mov #0x1C, r14                          ! r14 = 28 (loop limit: number of channel entries)
    mov.l r12, @-r15                        ! save r12 (callee-saved)
    mov #0x2C, r13                          ! r13 = 44 (source row stride before doubling)
    sts.l macl, @-r15                       ! save MACL (used by mul.l)
    add #-0x4, r15                          ! allocate 4 bytes on stack for local
    mov.w r4, @r15                          ! stack[0] = mode_index (16-bit, from r4 arg)
    mov #0x0, r4                            ! r4 = 0 (loop counter i)
    mov.w @r15, r1                          ! r1 = mode_index (reload from stack)
    .byte   0xDC, 0x1A    /* mov.l .L_ptr_source_struct, r12 */  ! r12 = &source_data_struct (sym_06063788)
    .byte   0xD7, 0x1A    /* mov.l .L_ptr_dest_table, r7 */     ! r7 = &display_channel_dest_table (sym_0605AAA6)
    extu.w r1, r1                           ! zero-extend mode_index to 32-bit
    mov.l @r12, r12                         ! r12 = *source_data_struct (dereference pointer)
    add #0x4, r12                           ! r12 += 4 (skip header, point to source entries)
    shll r1                                 ! r1 = mode_index * 2 (column offset in bytes)

/* ---- Copy loop: 28 entries, 4 bytes each (two 16-bit words) ---- */
.L_copy_loop:
    extu.w r4, r5                           ! r5 = i (zero-extended, for dest index)
    extu.w r4, r6                           ! r6 = i (zero-extended, for src row calc)
    shll r5                                 ! r5 = i * 2
    mul.l r13, r6                           ! MACL = i * 44 (source row offset before doubling)
    add #0x1, r4                            ! i++ (increment loop counter)
    shll r5                                 ! r5 = i * 4 (dest entry byte offset)
    sts macl, r6                            ! r6 = i * 44
    add r7, r5                              ! r5 = &dest_table[i] (dest entry address)
    shll r6                                 ! r6 = i * 88 (source row byte offset, doubled)
    add r1, r6                              ! r6 += mode_column_offset (select column in src)
    add r12, r6                             ! r6 = &src_table[i * 88 + column] (source addr)
    mov.w @r6, r3                           ! r3 = src_entry word 0 (first 16 bits)
    mov.w r3, @r5                           ! dest_table[i].word0 = src word 0
    mov.w @(2, r6), r0                      ! r0 = src_entry word 1 (second 16 bits)
    extu.w r4, r3                           ! r3 = i+1 (for loop bound check)
    cmp/ge r14, r3                          ! is (i+1) >= 28? (loop done?)
    bf/s    .L_copy_loop                    ! no: continue copying
    mov.w r0, @(2, r5)                      ! (delay) dest_table[i].word1 = src word 1

/* ---- Post-loop: set up args for display_list_loader tail call ---- */
    .byte   0xD7, 0x0E    /* mov.l .L_ptr_source_struct, r7 */  ! r7 = &source_data_struct (sym_06063788)
    .byte   0xD3, 0x0F    /* mov.l .L_offset_f000, r3 */        ! r3 = 0x0000F000 (palette/texture offset)
    mov.w @r15, r0                          ! r0 = mode_index (reload from stack)
    mov.l @(4, r7), r7                      ! r7 = source_struct[1] (second field: data pointer)
    extu.w r0, r0                           ! zero-extend mode_index
    add r3, r7                              ! r7 += 0xF000 (arg4: data_ptr + palette offset)
    and #0x3F, r0                           ! r0 = mode_index & 0x3F (mask to 6-bit slot index)
    mov r0, r6                              ! r6 = masked mode index
    shll r6                                 ! r6 *= 2 (arg3: slot index as word offset)
    .byte   0xD5, 0x0C    /* mov.l .L_ptr_config_word, r5 */    ! r5 = &display_config_word (arg2: sym_0605AAA2)
    mov #0x8, r4                            ! r4 = 8 (arg1: display list load mode)
    add #0x4, r15                           ! free stack local
    lds.l @r15+, macl                       ! restore MACL
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    .byte   0xD3, 0x0A    /* mov.l .L_ptr_dlist_loader, r3 */   ! r3 = &display_list_loader (sym_06028400)
    jmp @r3                                 ! tail-call display_list_loader(8, config, idx, data)
    mov.l @r15+, r14                        ! restore r14 (delay slot)

/* ---- Cross-TU data pool (shared with hud_layer_composite) ---- */
    .global DAT_060115c6
DAT_060115c6:
    mov.b r0, @(0, r0)
    .4byte  sym_060447A4
    .4byte  0x00010000
    .4byte  sym_060447A8
    .4byte  sym_06044764
    .4byte  sym_06044784
.L_ptr_source_struct:
    .4byte  sym_06063788                    /* -> source data struct (pointer-to-pointer) */
.L_ptr_dest_table:
    .4byte  sym_0605AAA6                    /* -> display_channel_dest_table (28 x 4 bytes) */
.L_offset_f000:
    .4byte  0x0000F000                      /* palette/texture data offset */
.L_ptr_config_word:
    .4byte  sym_0605AAA2                    /* -> display_config_word (16-bit) */
.L_ptr_dlist_loader:
    .4byte  sym_06028400                    /* -> display_list_loader function */
