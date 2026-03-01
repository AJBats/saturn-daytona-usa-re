
    .section .text.FUN_06008D74


    .global state_mode_select_active
    .type state_mode_select_active, @function
state_mode_select_active:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   _pool_display_status_ptr, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x70, r0
    bf/s    .L_skip_saturn_mode
    mov #0x0, r14
    mov #0x2, r2
    mov.l   _pool_course_type_ptr, r3
    mov.l r2, @r3
.L_skip_saturn_mode:
    mov.l   _pool_countdown_ptr, r4
    mov.l @r4, r2
    add #-0x1, r2
    mov.l r2, @r4
    mov r2, r3
    cmp/pz r3
    bt      .L_countdown_ok
    mov.l   _pool_game_state_ptr, r3
    mov.l r14, @r3
    mov.l   _pool_fn_disable_display, r3
    jsr @r3
    nop
.L_countdown_ok:
    mov.l   _pool_button_status_ptr, r2
    mov.w @r2, r3
    extu.w r3, r3
    mov.w   _wpool_confirm_mask, r2
    and r2, r3
    tst r3, r3
    bt      .L_no_confirm
    mov.l   _pool_game_state_ptr, r3
    mov.l r14, @r3
    mov.l   _pool_fn_disable_display, r3
    jsr @r3
    nop
.L_no_confirm:
    mov.l   _pool_fn_render_dispatch, r3
    jsr @r3
    nop
    mov.l   _pool_render_flags_ptr, r4
    mov.l   _pool_fn_camera_finalize, r3
    mov.l @r4, r0
    or #0x4, r0
    jsr @r3
    mov.l r0, @r4
    mov.l   _pool_anim_state_ptr, r3
    mov.l r14, @r3
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
_wpool_confirm_mask:
    .2byte  0x0100
_pool_display_status_ptr:
    .4byte  sym_06063DA0
_pool_course_type_ptr:
    .4byte  sym_06078644
_pool_countdown_ptr:
    .4byte  sym_0607EBCC
_pool_game_state_ptr:
    .4byte  g_game_state
_pool_fn_disable_display:
    .4byte  sym_060149E0
_pool_button_status_ptr:
    .4byte  sym_06063D9A
_pool_fn_render_dispatch:
    .4byte  render_setup_dispatch
_pool_render_flags_ptr:
    .4byte  sym_0605B6D8
_pool_fn_camera_finalize:
    .4byte  sym_06026CE0
_pool_anim_state_ptr:
    .4byte  sym_06059F44
