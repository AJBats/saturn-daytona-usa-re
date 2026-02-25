/* render_orchestrator -- Per-Car Rendering Pipeline Orchestrator
 * Translation unit: 0x0602EEB8 - 0x0602EFDA
 *
 * Main dispatch function for the per-car rendering pipeline. Called once
 * per car per frame after physics integration. Sequences 18 sub-calls
 * that transform 3D car state into VDP1 display commands:
 *
 *   1. pipeline_prologue (sym_0602FDA4)   -- save r8-r13
 *   2. render_camera_compute              -- coordinate bounds clipping
 *   3. clear render state (sym_0607EAC8)  -- zero pipeline scratch word
 *   4. copy car+0x250 -> car+0x252        -- latch collision state
 *   5. damage_mac_core (sym_0602F3EC)     -- fixed-point damage calc
 *   6. timer_tick (sym_0602F7BC)          -- decrement animation timers
 *   7. perspective_project (sym_0602F0E8) -- 3D-to-2D projection
 *   8. collision response (conditional)   -- path A or B by car+0x9C
 *   9. lighting_select (sym_0602F474)     -- lighting intensity
 *  10. distance_fog (sym_0602F4B4)        -- fog attenuation
 *  11. color_material_blend               -- material color blending
 *  12. orientation_sincos (sym_0602EFCC)  -- sin/cos for car heading
 *  13. vdp1_display_list_setup            -- VDP1 display list init
 *  14. vdp1_color_setup                   -- VDP1 color commands
 *  15. vdp1_coord_setup                   -- VDP1 coordinate commands
 *  16. display submit (conditional)       -- sprite or list by car+0x9E
 *  17. vdp1_cmd_list_mgr                  -- display list finalization
 *  18. cleanup (sym_0602D814, sym_0602D8BC) -- render state teardown
 *  19. mask flags with 0xFFFFFC3F, restore r8-r14
 *
 * Contains two functions:
 *   render_orchestrator (0x0602EEB8) -- main dispatch loop
 *   orientation_sincos  (0x0602EFCC) -- compute sin/cos of car heading
 */

    .section .text.FUN_0602EEB8


    .global render_orchestrator
    .type render_orchestrator, @function
render_orchestrator:
    mov.l r14, @-r15              ! save frame pointer
    sts.l pr, @-r15               ! save return address
    mov.l   .L_pipeline_prologue, r13  ! r13 = pipeline_prologue (saves r8-r13)
    jsr @r13                      ! call pipeline_prologue
    nop                           ! delay slot
    mov.l   .L_render_camera_compute, r13  ! r13 = render_camera_compute
    jsr @r13                      ! call render_camera_compute (bounds clipping)
    nop                           ! delay slot
    mov.l   .L_render_state_scratch, r1  ! r1 = &render_state_scratch (0x0607EAC8)
    mov #0x0, r2                  ! r2 = 0
    mov.l r2, @r1                 ! clear pipeline scratch word
    mov.w   .L_off_collision_state, r1  ! r1 = 0x0250 (offset to collision state)
    mov.w @(r0, r1), r2           ! r2 = car[0x250] (collision state word)
    add #0x2, r1                  ! r1 = 0x0252 (latch destination)
    mov.w r2, @(r0, r1)           ! car[0x252] = car[0x250] (latch collision state)
    mov.l   .L_damage_mac_core, r13  ! r13 = damage_mac_core
    jsr @r13                      ! call damage_mac_core (fixed-point damage calc)
    nop                           ! delay slot
    mov.l   .L_timer_tick, r13    ! r13 = timer_tick
    jsr @r13                      ! call timer_tick (decrement animation timers)
    nop                           ! delay slot
    mov.l   .L_perspective_project, r13  ! r13 = perspective_project
    jsr @r13                      ! call perspective_project (3D-to-2D)
    nop                           ! delay slot
    mov.w   .L_off_collision_flag, r1  ! r1 = 0x009C (offset to collision flag)
    mov.w @(r0, r1), r2           ! r2 = car[0x9C] (collision flag)
    tst r2, r2                    ! test if collision flag is zero
    bt      .L_collision_path_a   ! if zero, take path A (simpler)
    mov.l   .L_collision_response_b, r13  ! r13 = collision_response_b
    jsr @r13                      ! call collision_response_b (state-driven)
    nop                           ! delay slot
    bra     .L_after_collision    ! skip path A
    nop                           ! delay slot
.L_off_collision_state:
    .2byte  0x0250                ! offset: car collision state word
.L_off_collision_flag:
    .2byte  0x009C                ! offset: car collision active flag
    .2byte  0x0000                ! alignment padding
.L_pipeline_prologue:
    .4byte  sym_0602FDA4          ! -> pipeline prologue (save r8-r13)
.L_render_camera_compute:
    .4byte  render_camera_compute ! -> bounds clipping / camera viewport
.L_render_state_scratch:
    .4byte  sym_0607EAC8          ! -> pipeline scratch word (cleared each frame)
.L_damage_mac_core:
    .4byte  sym_0602F3EC          ! -> fixed-point damage MAC core
.L_timer_tick:
    .4byte  sym_0602F7BC          ! -> animation timer decrement
.L_perspective_project:
    .4byte  sym_0602F0E8          ! -> perspective projection (3D-to-2D)
.L_collision_response_b:
    .4byte  collision_response_b  ! -> collision response path B (state-driven)
.L_collision_path_a:
    mov.l   .L_collision_response_a, r13  ! r13 = collision_response_a
    jsr @r13                      ! call collision_response_a (primary path)
    nop                           ! delay slot
.L_after_collision:
    mov.l   .L_lighting_select, r13  ! r13 = lighting_select
    jsr @r13                      ! call lighting intensity selection
    nop                           ! delay slot
    mov.l   .L_distance_fog, r13  ! r13 = distance_fog
    jsr @r13                      ! call distance fog calculation
    nop                           ! delay slot
    mov.l   .L_color_material_blend, r13  ! r13 = color_material_blend
    jsr @r13                      ! call material color blending
    nop                           ! delay slot
    mov.l   .L_orientation_sincos, r13  ! r13 = orientation_sincos
    jsr @r13                      ! call sin/cos for car heading
    nop                           ! delay slot
    mov.l   .L_vdp1_display_list_setup, r13  ! r13 = vdp1_display_list_setup
    jsr @r13                      ! call VDP1 display list init
    nop                           ! delay slot
    mov.l   .L_vdp1_color_setup, r13  ! r13 = vdp1_color_setup
    jsr @r13                      ! call VDP1 color command generation
    nop                           ! delay slot
    mov.l   .L_vdp1_coord_setup, r13  ! r13 = vdp1_coord_setup
    jsr @r13                      ! call VDP1 coordinate commands
    nop                           ! delay slot
    mov.w   .L_off_display_flag, r1  ! r1 = 0x009E (offset to display flag)
    mov.l   .L_vdp1_sprite_cmd, r12  ! r12 = vdp1_sprite_cmd (preload)
    mov.w @(r0, r1), r2           ! r2 = car[0x9E] (display submit flag)
    mov.l   .L_vdp1_display_submit, r13  ! r13 = vdp1_display_submit (preload)
    tst r2, r2                    ! test if display flag is zero
    bt      .L_submit_list_path   ! if zero, submit list directly
    jsr @r12                      ! call vdp1_sprite_cmd (sprite path)
    nop                           ! delay slot
    bra     .L_after_display_submit  ! skip list submit path
    nop                           ! delay slot
.L_off_display_flag:
    .2byte  0x009E                ! offset: car display submit flag
    .2byte  0x0000                ! alignment padding
.L_collision_response_a:
    .4byte  sym_0602F17C          ! -> collision response path A (primary)
.L_lighting_select:
    .4byte  sym_0602F474          ! -> lighting intensity selection
.L_distance_fog:
    .4byte  sym_0602F4B4          ! -> distance fog calculation
.L_color_material_blend:
    .4byte  color_material_blend  ! -> material color blending
.L_orientation_sincos:
    .4byte  sym_0602EFCC          ! -> orientation sin/cos compute
.L_vdp1_display_list_setup:
    .4byte  vdp1_display_list_setup  ! -> VDP1 display list init
.L_vdp1_color_setup:
    .4byte  vdp1_color_setup      ! -> VDP1 color command generation
.L_vdp1_coord_setup:
    .4byte  vdp1_coord_setup      ! -> VDP1 coordinate commands
.L_vdp1_sprite_cmd:
    .4byte  vdp1_sprite_cmd       ! -> VDP1 sprite command (non-zero flag)
.L_vdp1_display_submit:
    .4byte  vdp1_display_submit   ! -> VDP1 display list submit (zero flag)
.L_submit_list_path:
    jsr @r13                      ! call vdp1_display_submit (list path)
    nop                           ! delay slot
.L_after_display_submit:
    mov.l   .L_vdp1_cmd_list_mgr, r13  ! r13 = vdp1_cmd_list_mgr
    jsr @r13                      ! call display list finalization
    nop                           ! delay slot
    mov.l   .L_render_state_cleanup, r13  ! r13 = render_state_cleanup
    jsr @r13                      ! call render state cleanup
    nop                           ! delay slot
    mov.l   .L_final_cleanup, r13 ! r13 = final_cleanup
    jsr @r13                      ! call final cleanup
    nop                           ! delay slot
    mov.l @(0, r0), r2            ! r2 = car[0] (flags word)
    mov.l   .L_flag_mask, r3      ! r3 = 0xFFFFFC3F (clear bits 6-9)
    and r3, r2                    ! mask off render pipeline bits
    mov.l r2, @(0, r0)            ! store updated flags
    lds.l @r15+, pr               ! restore return address
    mov.l @r15+, r14              ! restore r14
    mov.l @r15+, r13              ! restore r13
    mov.l @r15+, r12              ! restore r12
    mov.l @r15+, r11              ! restore r11
    mov.l @r15+, r10              ! restore r10
    mov.l @r15+, r9               ! restore r9
    rts                           ! return
    mov.l @r15+, r8               ! restore r8 (delay slot)
.L_vdp1_cmd_list_mgr:
    .4byte  vdp1_cmd_list_mgr     ! -> display list finalization
.L_render_state_cleanup:
    .4byte  sym_0602D814          ! -> render state cleanup
.L_final_cleanup:
    .4byte  sym_0602D8BC          ! -> final pipeline cleanup
.L_flag_mask:
    .4byte  0xFFFFFC3F            ! mask: clear render pipeline bits 6-9

    .global sym_0602EFCC
sym_0602EFCC:                     ! orientation_sincos — compute sin/cos of car heading
    mov.l @(36, r0), r4           ! r4 = car[0x24] (orientation angle)
    .byte   0x95, 0x0A    /* mov.w DAT_0602efe6, r5 — offset to sin dest */
    .byte   0x96, 0x0A    /* mov.w DAT_0602efe8, r6 — offset to cos dest */
    add r0, r5                    ! r5 = car + sin_offset (absolute ptr)
    add r0, r6                    ! r6 = car + cos_offset (absolute ptr)
    mov r0, r14                   ! r14 = car base (save for epilogue)
    .byte   0xDC, 0x04    /* mov.l .L_sincos_pair, r12 — sincos function ptr */
