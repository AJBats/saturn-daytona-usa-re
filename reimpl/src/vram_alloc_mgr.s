/* vram_alloc_mgr -- VRAM allocation manager and geometry dispatch
 * Translation unit: 0x0601FD9C - 0x0601FE20
 *
 * Selects the active VRAM allocation table based on a mode flag bit,
 * indexes into it using the current car slot index, and triggers
 * geometry display processing for that slot.  After the geometry
 * pass, checks the game-state word and either tail-calls
 * race_start_obj_init (to restart object state) or returns normally.
 *
 * Flow:
 *   1. Read sym_0607EBC4 (mode flags word); mask with 0x00800000.
 *   2. If bit set  -> index sym_0607EAD8 into sym_0605F62C (table A).
 *      If bit clear -> index sym_0607EAD8 into sym_0605F5EC (table B).
 *   3. Store selected entry into sym_060877F8 (active alloc ptr).
 *   4. Dereference entry to get display-list descriptor; store to sym_060877F4.
 *   5. BSR geom_display_handler — iterate cars, submit geometry.
 *   6. Read g_game_state (game-state word).
 *      - If == 0x17 -> T-flag captured to r1 (movt r1).
 *      - If == 0x16 -> T-flag captured to r0 (movt r0).
 *      OR r1|r0: if any state matched -> tail-call race_start_obj_init.
 *   7. Otherwise return to caller.
 *
 * Pool layout (8 entries):
 *   sym_060877F8  active alloc ptr (write target)
 *   sym_0607EBC4  mode flags (bit 23 selects table A vs B)
 *   sym_06087804  handler mode word (tested by geom_display_handler)
 *   sym_0607EAD8  car slot index (used as table row)
 *   sym_0605F62C  alloc table A (3-entry pointer table, video mode A)
 *   sym_0605F5EC  alloc table B (3-entry pointer table, video mode B)
 *   sym_060877F4  display-list descriptor ptr (written before geometry call)
 *   g_game_state  game-state word (0x16/0x17 = race-start states)
 */

    .section .text.FUN_0601FD9C


    .global vram_alloc_mgr
    .type vram_alloc_mgr, @function
vram_alloc_mgr:
    sts.l pr, @-r15                        ! save return address (PR) to stack
    mov.l   .L_ptr_active_alloc, r4       ! r4 = &active_alloc_ptr (sym_060877F8)
    mov.l   .L_ptr_mode_flags, r3         ! r3 = &mode_flags (sym_0607EBC4)
    mov.l   .L_mask_bit23, r2             ! r2 = 0x00800000 (bit-23 select mask)
    mov.l @r3, r3                         ! r3 = mode_flags value
    and r2, r3                            ! r3 = mode_flags & 0x00800000 (isolate table-select bit)
    tst r3, r3                            ! test: bit clear?
    bt      .L_use_table_b                ! if zero (bit clear) -> use table B
    mov.l   .L_ptr_slot_index, r3         ! r3 = &slot_index (sym_0607EAD8)
    mov.l @r3, r3                         ! r3 = slot_index (car slot number)
    shll2 r3                              ! r3 = slot_index * 4 (word offset into table)
    mov.l   .L_ptr_table_a, r2            ! r2 = table_a base (sym_0605F62C)
    add r2, r3                            ! r3 = &table_a[slot_index]
    mov.l @r3, r1                         ! r1 = table_a[slot_index] (alloc descriptor ptr)
    bra     .L_store_alloc_ptr            ! jump to common store path
    nop                                   ! (delay slot)
.L_use_table_b:
    mov.l   .L_ptr_slot_index, r3         ! r3 = &slot_index (sym_0607EAD8)
    mov.l @r3, r3                         ! r3 = slot_index (car slot number)
    shll2 r3                              ! r3 = slot_index * 4 (word offset into table)
    mov.l   .L_ptr_table_b, r2            ! r2 = table_b base (sym_0605F5EC)
    add r2, r3                            ! r3 = &table_b[slot_index]
    mov.l @r3, r1                         ! r1 = table_b[slot_index] (alloc descriptor ptr)
.L_store_alloc_ptr:
    mov.l r1, @r4                         ! active_alloc_ptr = selected descriptor ptr
    mov r1, r2                            ! r2 = descriptor ptr (copy for dereference)
    mov.l @r2, r3                         ! r3 = descriptor[0] (display-list desc value)
    mov.l   .L_ptr_disp_desc, r1          ! r1 = &disp_desc_ptr (sym_060877F4)
    mov.l r3, @r1                         ! disp_desc_ptr = descriptor[0]
    .byte   0xB0, 0x25    /* bsr 0x0601FE20 (external) */  ! call geom_display_handler
    nop                                   ! (delay slot)
    mov.l   .L_ptr_game_state, r4         ! r4 = &game_state (g_game_state)
    mov.l @r4, r0                         ! r0 = game_state word
    cmp/eq #0x17, r0                      ! is game_state == 0x17 (race-start state A)?
    .word 0x0129 /* movt r1 */            ! r1 = T (1 if matched, else 0)
    cmp/eq #0x16, r0                      ! is game_state == 0x16 (race-start state B)?
    .word 0x0029 /* movt r0 */            ! r0 = T (1 if matched, else 0)
    or r1, r0                             ! r0 = (state==0x17) | (state==0x16)
    tst r0, r0                            ! test: any race-start state matched?
    bt      .L_return_normal              ! if no match -> return normally
    .byte   0xA1, 0x5C    /* bra 0x060200A4 (external) */  ! tail-call race_start_obj_init
    lds.l @r15+, pr                       ! (delay slot) restore PR before branch lands
.L_return_normal:
    lds.l @r15+, pr                       ! restore PR
    rts                                   ! return to caller
    nop                                   ! (delay slot)
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
