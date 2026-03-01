
    .section .text.FUN_06041826


    .global evt_callback_handler
    .type evt_callback_handler, @function
evt_callback_handler:
    mov.l r14, @-r15
    mov r5, r14
    bra     .L_dispatch_switch
    mov r4, r0
.L_case_0:
    mov r14, r4
    .byte   0xA0, 0x45    /* bra 0x060418BE (external) */  ! tail-call track_road_validate
    mov.l @r15+, r14
.L_case_1:
    mov r14, r4
    .byte   0xA1, 0x33    /* bra 0x06041AA0 (external) */  ! tail-call track_boundary_check
    mov.l @r15+, r14
.L_case_2:
    mov r14, r4
    .byte   0xA1, 0x7E    /* bra 0x06041B3C (external) */  ! tail-call cmd_enqueue target
    mov.l @r15+, r14
.L_case_3:
    mov r14, r4
    .byte   0xA2, 0x41    /* bra 0x06041CC8 (external) */  ! tail-call state_transition_handler
    mov.l @r15+, r14
.L_case_4:
    mov r14, r4
    .byte   0xA2, 0x90    /* bra 0x06041D6C (external) */  ! tail-call large_func_prologue
    mov.l @r15+, r14
.L_case_5:
    mov r14, r4
    .byte   0xA3, 0x4B    /* bra 0x06041EE8 (external) */  ! tail-call track_edge_validate
    mov.l @r15+, r14
.L_case_6:
    mov r14, r4
    .byte   0xA4, 0x6E    /* bra 0x06042134 (external) */  ! tail-call player_vehicle_interp
    mov.l @r15+, r14
.L_case_7:
    mov r14, r4
    .byte   0xA4, 0x15    /* bra 0x06042088 (external) */  ! tail-call track_shadow_validate
    mov.l @r15+, r14
    .2byte  0x0360
.L_dispatch_switch:
    cmp/eq #0x0, r0
    bt      .L_case_0
    cmp/eq #0x1, r0
    bt      .L_case_1
    cmp/eq #0x2, r0
    bt      .L_case_2
    cmp/eq #0x3, r0
    bt      .L_case_3
    cmp/eq #0x4, r0
    bt      .L_case_4
    cmp/eq #0x5, r0
    bt      .L_case_5
    cmp/eq #0x6, r0
    bt      .L_case_6
    cmp/eq #0x7, r0
    bt      .L_case_7
    rts
    mov.l @r15+, r14

    .global sym_06041884
sym_06041884:
    .byte   0xD3, 0x08    /* mov.l .L_pool_060418A8, r3 */  ! r3 = &game_state_base_ptr (sym_060A5400)
    mov.l @r3, r3
    rts
    mov.l r4, @(60, r3)
