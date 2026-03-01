
    .section .text.FUN_06012710


    .global race_progress_check
    .type race_progress_check, @function
race_progress_check:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   _pool_countdown_ptr, r13
    mov.l   _pool_fn_sound_cmd, r14
    mov.l   _pool_snd_progress, r12
    bra     .L_dispatch
    mov.l @r13, r0
.L_race_complete:
    mov #0x1, r2
    mov.l   _pool_finish_flag_ptr, r3
    mov.b r2, @r3
    mov.l   _pool_car_array_ptr, r2
    mov.l @r2, r2
    mov.l @(48, r2), r3
    mov.l   _pool_camera_yaw_ptr, r1
    mov.l r3, @r1
    mov.l   _pool_snd_menu_select, r5
    bra     .L_play_sound_pair
    nop
.L_progress_80:
    mov.l   _pool_snd_lap_progress, r5
    bra     .L_play_sound_pair
    nop
.L_progress_60:
    mov.l   _pool_snd_mid_race, r5
.L_play_sound_pair:
    jsr @r14
    mov #0x0, r4
    mov r12, r5
    jsr @r14
    mov #0x0, r4
    bra     .L_post_dispatch
    nop
.L_progress_40:
    mov.l   _pool_snd_early_race, r5
    jsr @r14
    mov #0x0, r4
    mov.l   _pool_snd_init, r5
    jsr @r14
    mov #0x0, r4
    mov #0x3C, r2
    mov.l   _pool_countdown_timer_ptr, r3
    mov.w r2, @r3
    mov #0x1, r2
    mov.l   _pool_race_ready_ptr, r3
    mov.b r2, @r3
    bra     .L_post_dispatch
    nop
.L_dispatch:
    cmp/eq #0x28, r0
    bt      .L_progress_40
    cmp/eq #0x3C, r0
    bt      .L_progress_60
    cmp/eq #0x50, r0
    bt      .L_progress_80
    cmp/eq #0x64, r0
    bt      .L_race_complete
.L_post_dispatch:
    mov.l @r13, r1
    mov.l   _pool_fn_mem_store, r2
    jsr @r2
    mov #0x4, r0
    tst r0, r0
    .word 0x0029
    mov.l @r13, r3
    mov #0x6E, r2
    cmp/gt r2, r3
    .word 0x0129
    and r1, r0
    tst r0, r0
    bt      .L_exit
    mov.l   _pool_snd_finish, r5
    jsr @r14
    mov #0x0, r4
.L_exit:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_pool_countdown_ptr:
    .4byte  sym_0607EBCC                    /* &state_countdown (race progress counter) */
_pool_fn_sound_cmd:
    .4byte  sound_cmd_dispatch              /* sound command dispatcher function */
_pool_snd_progress:
    .4byte  0xAE1115FF                      /* sound cmd: persistent progress tone */
_pool_finish_flag_ptr:
    .4byte  sym_06078654                    /* &finish_flag / lap count (byte) */
_pool_car_array_ptr:
    .4byte  sym_0607E944                    /* &car_array_base pointer (deref to get array) */
_pool_camera_yaw_ptr:
    .4byte  sym_06063EF0                    /* &camera_yaw angle storage */
_pool_snd_menu_select:
    .4byte  0xAE1122FF                      /* sound cmd: menu select / race-complete confirm */
_pool_snd_lap_progress:
    .4byte  0xAE1123FF                      /* sound cmd: lap progress milestone */
_pool_snd_mid_race:
    .4byte  0xAE1124FF                      /* sound cmd: mid-race milestone */
_pool_snd_early_race:
    .4byte  0xAE1125FF                      /* sound cmd: early-race start */
_pool_snd_init:
    .4byte  0xAE1116FF                      /* sound cmd: race init / setup */
_pool_countdown_timer_ptr:
    .4byte  sym_06086056                    /* &countdown_timer (16-bit word) */
_pool_race_ready_ptr:
    .4byte  sym_0608605A                    /* &race_ready_flag (byte) */
_pool_fn_mem_store:
    .4byte  sym_06035C2C                    /* mem_store_helper function */
_pool_snd_finish:
    .4byte  0xAE110CFF                      /* sound cmd: race finish fanfare */
