
    .section .text.FUN_06041826


    .global evt_callback_handler
    .type evt_callback_handler, @function
evt_callback_handler:
    mov.l r14, @-r15
    mov r5, r14
    bra     .L_06041860
    mov r4, r0
.L_0604182E:
    mov r14, r4
    .reloc ., R_SH_IND12W, track_road_validate - 4
    .2byte 0xA000    /* bra track_road_validate (linker-resolved) */
    mov.l @r15+, r14
.L_06041834:
    mov r14, r4
    .reloc ., R_SH_IND12W, track_boundary_check - 4
    .2byte 0xA000    /* bra track_boundary_check (linker-resolved) */
    mov.l @r15+, r14
.L_0604183A:
    mov r14, r4
    .reloc ., R_SH_IND12W, track_surface_validate - 4
    .2byte 0xA000    /* bra track_surface_validate (linker-resolved) */
    mov.l @r15+, r14
.L_06041840:
    mov r14, r4
    .reloc ., R_SH_IND12W, state_transition_handler - 4
    .2byte 0xA000    /* bra state_transition_handler (linker-resolved) */
    mov.l @r15+, r14
.L_06041846:
    mov r14, r4
    .reloc ., R_SH_IND12W, large_func_prologue - 4
    .2byte 0xA000    /* bra large_func_prologue (linker-resolved) */
    mov.l @r15+, r14
.L_0604184C:
    mov r14, r4
    .reloc ., R_SH_IND12W, track_edge_validate - 4
    .2byte 0xA000    /* bra track_edge_validate (linker-resolved) */
    mov.l @r15+, r14
.L_06041852:
    mov r14, r4
    .reloc ., R_SH_IND12W, player_vehicle_interp - 4
    .2byte 0xA000    /* bra player_vehicle_interp (linker-resolved) */
    mov.l @r15+, r14
.L_06041858:
    mov r14, r4
    .reloc ., R_SH_IND12W, track_shadow_validate - 4
    .2byte 0xA000    /* bra track_shadow_validate (linker-resolved) */
    mov.l @r15+, r14
    .2byte  0x0360
.L_06041860:
    cmp/eq #0x0, r0
    bt      .L_0604182E
    cmp/eq #0x1, r0
    bt      .L_06041834
    cmp/eq #0x2, r0
    bt      .L_0604183A
    cmp/eq #0x3, r0
    bt      .L_06041840
    cmp/eq #0x4, r0
    bt      .L_06041846
    cmp/eq #0x5, r0
    bt      .L_0604184C
    cmp/eq #0x6, r0
    bt      .L_06041852
    cmp/eq #0x7, r0
    bt      .L_06041858
    rts
    mov.l @r15+, r14

    .global sym_06041884
sym_06041884:
    .byte   0xD3, 0x08    /* mov.l .L_pool_060418A8, r3 */
    mov.l @r3, r3
    rts
    mov.l r4, @(60, r3)
