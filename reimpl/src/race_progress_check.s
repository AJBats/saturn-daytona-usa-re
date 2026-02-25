/* race_progress_check -- Race progress sound dispatcher
 *
 * Checks the state countdown timer (sym_0607EBCC) against race progress
 * milestones and plays the appropriate sound effect for each threshold:
 *   0x64 (100): race complete -- sets finish flag, copies car yaw to camera
 *   0x50 (80):  plays lap progress sound (0xAE1123FF)
 *   0x3C (60):  plays mid-race sound (0xAE1124FF)
 *   0x28 (40):  plays early-race sound (0xAE1125FF) + init sound (0xAE1116FF),
 *               sets countdown timer and race-ready flag
 * All threshold cases also play the persistent progress sound (0xAE1115FF).
 * After dispatch, calls mem_store_helper to check a state condition; if the
 * helper returns zero AND countdown > 0x6E (110), plays finish sound (0xAE110CFF).
 */

    .section .text.FUN_06012710


    .global race_progress_check
    .type race_progress_check, @function
race_progress_check:
    mov.l r14, @-r15                        ! save r14 (callee-saved)
    mov.l r13, @-r15                        ! save r13 (callee-saved)
    mov.l r12, @-r15                        ! save r12 (callee-saved)
    sts.l pr, @-r15                         ! save pr (return address)
    mov.l   _pool_countdown_ptr, r13        ! r13 = &state_countdown (sym_0607EBCC)
    mov.l   _pool_fn_sound_cmd, r14         ! r14 = sound_cmd_dispatch function ptr
    mov.l   _pool_snd_progress, r12         ! r12 = 0xAE1115FF (progress sound cmd)
    bra     .L_dispatch                     ! jump to threshold dispatch
    mov.l @r13, r0                          ! (delay) r0 = *countdown (current value)
.L_race_complete:
    mov #0x1, r2                            ! r2 = 1 (finish flag value)
    mov.l   _pool_finish_flag_ptr, r3       ! r3 = &finish_flag (sym_06078654, lap count byte)
    mov.b r2, @r3                           ! *finish_flag = 1 (mark race complete)
    mov.l   _pool_car_array_ptr, r2         ! r2 = &car_array_base (sym_0607E944)
    mov.l @r2, r2                           ! r2 = car_array_base (dereference pointer)
    mov.l @(48, r2), r3                     ! r3 = car[+0x30] (car yaw angle, offset 48)
    mov.l   _pool_camera_yaw_ptr, r1        ! r1 = &camera_yaw (sym_06063EF0)
    mov.l r3, @r1                           ! *camera_yaw = car yaw (snap camera to car)
    mov.l   _pool_snd_menu_select, r5       ! r5 = 0xAE1122FF (menu select / confirm sound)
    bra     .L_play_sound_pair              ! jump to play this sound + progress sound
    nop                                     ! (delay)
.L_progress_80:
    mov.l   _pool_snd_lap_progress, r5     ! r5 = 0xAE1123FF (lap progress sound)
    bra     .L_play_sound_pair              ! jump to play this sound + progress sound
    nop                                     ! (delay)
.L_progress_60:
    mov.l   _pool_snd_mid_race, r5         ! r5 = 0xAE1124FF (mid-race milestone sound)
.L_play_sound_pair:
    jsr @r14                                ! call sound_cmd_dispatch(r4=0, r5=milestone_snd)
    mov #0x0, r4                            ! (delay) r4 = 0 (sound channel)
    mov r12, r5                             ! r5 = 0xAE1115FF (progress sound cmd)
    jsr @r14                                ! call sound_cmd_dispatch(r4=0, r5=progress_snd)
    mov #0x0, r4                            ! (delay) r4 = 0 (sound channel)
    bra     .L_post_dispatch                ! jump to post-dispatch check
    nop                                     ! (delay)
.L_progress_40:
    mov.l   _pool_snd_early_race, r5       ! r5 = 0xAE1125FF (early-race start sound)
    jsr @r14                                ! call sound_cmd_dispatch(r4=0, r5=early_snd)
    mov #0x0, r4                            ! (delay) r4 = 0 (sound channel)
    mov.l   _pool_snd_init, r5             ! r5 = 0xAE1116FF (init / setup sound)
    jsr @r14                                ! call sound_cmd_dispatch(r4=0, r5=init_snd)
    mov #0x0, r4                            ! (delay) r4 = 0 (sound channel)
    mov #0x3C, r2                           ! r2 = 0x3C (60 frames = 1 second timer)
    mov.l   _pool_countdown_timer_ptr, r3   ! r3 = &countdown_timer (sym_06086056, 16-bit)
    mov.w r2, @r3                           ! *countdown_timer = 60 (1 second countdown)
    mov #0x1, r2                            ! r2 = 1 (race ready)
    mov.l   _pool_race_ready_ptr, r3        ! r3 = &race_ready_flag (sym_0608605A, byte)
    mov.b r2, @r3                           ! *race_ready_flag = 1 (signal race is ready)
    bra     .L_post_dispatch                ! jump to post-dispatch check
    nop                                     ! (delay)
.L_dispatch:
    cmp/eq #0x28, r0                        ! T = (countdown == 0x28)? (40 = early race)
    bt      .L_progress_40                  ! if countdown == 40, handle early-race
    cmp/eq #0x3C, r0                        ! T = (countdown == 0x3C)? (60 = mid-race)
    bt      .L_progress_60                  ! if countdown == 60, handle mid-race
    cmp/eq #0x50, r0                        ! T = (countdown == 0x50)? (80 = lap progress)
    bt      .L_progress_80                  ! if countdown == 80, handle lap progress
    cmp/eq #0x64, r0                        ! T = (countdown == 0x64)? (100 = race complete)
    bt      .L_race_complete                ! if countdown == 100, handle race complete
.L_post_dispatch:
    mov.l @r13, r1                          ! r1 = *countdown (reload current value)
    mov.l   _pool_fn_mem_store, r2          ! r2 = mem_store_helper (sym_06035C2C)
    jsr @r2                                 ! call mem_store_helper(r0=0x4, r1=countdown)
    mov #0x4, r0                            ! (delay) r0 = 0x4 (store mode argument)
    tst r0, r0                              ! T = (result == 0)? test helper return value
    .word 0x0029 /* movt r0 */              ! r0 = T (1 if helper returned zero, else 0)
    mov.l @r13, r3                          ! r3 = *countdown (reload)
    mov #0x6E, r2                           ! r2 = 0x6E (110 = finish threshold)
    cmp/gt r2, r3                           ! T = (countdown > 110)?
    .word 0x0129 /* movt r1 */              ! r1 = T (1 if countdown past finish, else 0)
    and r1, r0                              ! r0 = (helper_zero) AND (past_finish)
    tst r0, r0                              ! T = (combined == 0)?
    bt      .L_exit                         ! if either condition false, skip finish sound
    mov.l   _pool_snd_finish, r5            ! r5 = 0xAE110CFF (finish/fanfare sound)
    jsr @r14                                ! call sound_cmd_dispatch(r4=0, r5=finish_snd)
    mov #0x0, r4                            ! (delay) r4 = 0 (sound channel)
.L_exit:
    lds.l @r15+, pr                         ! restore pr (return address)
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! (delay) restore r14
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
