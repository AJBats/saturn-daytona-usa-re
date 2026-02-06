
    .text

    .equiv STATE_VAR,        0x0605AD10
    .equiv RESUME_STATE,     0x0607EACC
    .equiv CAR_OBJECT,       0x0607EAD8
    .equiv RACE_END_FLAG,    0x0607EAD0
    .equiv COUNTDOWN,        0x0607EAAC
    .equiv FRAME_COUNTER,    0x0607EBD0
    .equiv FLAGS_WORD,       0x0607EBF4
    .equiv DISPLAY_FLAGS,    0x0605B6D8
    .equiv CURRENT_CAR,      0x0607E944
    .equiv RACE_RESULT,      0x06078638
    .equiv INIT_FLAG,        0x0607ED8C
    .equiv TIMER_BYTE,       0x0607ED88
    .equiv MENU_OVERLAY,     0x0605AB18
    .equiv MODE_FLAG,        0x0605A1C4
    .equiv BACK_TO_TITLE,    0x0605AD08
    .equiv BUTTONS_HELD,     0x06063D98
    .equiv BUTTONS_NEW,      0x06063D9A
    .equiv BTN_START,        0x0800
    .equiv BTN_UP,           0x8000
    .equiv CAR_COUNT,        0x06078634
    .equiv PHASE_FLAG,       0x06078635
    .equiv RACE_ACTIVE,      0x06078634
    .equiv SOUND_TIMER,      0x06086054
    .equiv DISPLAY_BYTE,     0x06078636
    .equiv RESULTS_FLAG,     0x06059F44
    .equiv SPEED_BYTE,       0x06078649
    .equiv MODE_BYTE,        0x0607864A
    .equiv DIFFICULTY_CUR,   0x06078654
    .equiv DIFFICULTY_SAVE,  0x06078652
    .equiv FRAME_COUNT_W,    0x06078650
    .equiv BUTTON_EVENTS,    0x06078648
    .equiv SOUND_CMD_API,    0x0601D5F4
    .equiv FRAME_SYNC,       0x060078DC
    .equiv VDP_TEXT,          0x060283E0
    .equiv VDP_NUMTEXT,      0x060284AE
    .equiv MENU_FUNC,        0x060268B0
    .equiv DISPLAY_UPDATE,   0x06026CE0
    .equiv RESET_SOUND,      0x060192CA
    .equiv CLEANUP_A,        0x060121A8
    .equiv CLEANUP_B,        0x06012198


    .equiv SND_TRANSITION,   0xAE0004FF
    .equiv SND_COUNTDOWN,    0xAE1134FF



FUN_06008EBC:
    sts.l   pr, @-r15
    mov.l   r14, @-r15
    mov.l   r13, @-r15
    mov.l   r12, @-r15
    mov.l   r11, @-r15
    mov.l   r10, @-r15
    mov.l   r9, @-r15
    mov.l   r8, @-r15

    mov     #0, r3
    mov.l   .L14_phase, r2          /* r2 = 0x06078635 */
    mov.b   r3, @r2                 /* [phase_flag] = 0  (clear phase) */

    mov     #1, r3
    mov.l   .L14_active, r2         /* r2 = 0x06078634 */
    mov.b   r3, @r2                 /* [race_active] = 1 */

    mov     #8, r3
    mov.l   .L14_timer, r2          /* r2 = 0x0607ED88 */
    mov.l   r3, @r2                 /* [timer_byte] = 8 */

    /* --- Button event mapping --- */
    /* Reads mask from 0x06063D98, ANDs with flag words at */
    /* 0x06078656/58/5A/5C to map buttons to event IDs 0-3 */
    /* Result written to [0x06078648] */
    /* (omitted ~20 insns of button mapping logic) */

    /* --- Main race pipeline --- */
    /* FUN_0600A0C0  - pre-update */
    /* FUN_06018A3C  - timing setup */
    /* FUN_0601F784  - AI/course setup */
    /* FUN_0600EB14  - RACE UPDATE (physics, collision, movement) */
    /* FUN_06010A5C  - post-update */
    /* FUN_06033AAC  - HUD rendering */
    /* FUN_060321C0  - display commit */

    /* --- Transition to State 15 --- */
    mov     #15, r3
    mov.l   .L14_state, r2          /* r2 = STATE_VAR */
    mov.l   r3, @r2                 /* state = 15 */

    mov.l   .L14_dispflags, r2      /* r2 = DISPLAY_FLAGS */
    mov.l   @r2, r3
    mov.l   .L14_bit30, r0          /* r0 = 0x40000000 */
    or      r0, r3
    mov.l   r3, @r2                 /* set bit 30 in display_flags */

    mov.l   @r15+, r8
    mov.l   @r15+, r9
    mov.l   @r15+, r10
    mov.l   @r15+, r11
    mov.l   @r15+, r12
    mov.l   @r15+, r13
    mov.l   @r15+, r14
    lds.l   @r15+, pr
    rts
    nop

    .align 2
.L14_phase:     .long 0x06078635
.L14_active:    .long 0x06078634
.L14_timer:     .long 0x0607ED88
.L14_state:     .long 0x0605AD10
.L14_dispflags: .long 0x0605B6D8
.L14_bit30:     .long 0x40000000



FUN_06009098:
    mov.l   r14, @-r15
    mov.l   r13, @-r15
    mov.l   r12, @-r15
    mov.l   r11, @-r15
    mov.l   r10, @-r15
    mov.l   r9, @-r15
    mov.l   r8, @-r15
    sts.l   pr, @-r15
    add     #-4, r15

    /* Cache key addresses in callee-saved registers */
    mov.l   .L15_timer, r8          /* r8 = &timer_byte (0x0607ED88) */
    mov.l   .L15_curobj, r9         /* r9 = &current_car (0x0607E940) */
    mov.l   .L15_state, r10         /* r10 = &state_var (0x0605AD10) */
    mov.l   .L15_init, r11          /* r11 = &init_flag (0x0607ED8C) */
    mov.l   .L15_carobj2, r14       /* r14 = &current_car2 (0x0607E944) */

    /* --- Start button check --- */
    mov.l   .L15_btnnew, r3         /* r3 = &BUTTONS_NEW */
    mov.w   @r3, r2                 /* r2 = new buttons */
    extu.w  r2, r2
    mov.w   .L15_startmask, r3      /* r3 = 0x0800 */
    and     r3, r2
    tst     r2, r2
    bt      .L15_no_start

    /* Start pressed => pause/time extension */
    mov     #15, r3
    mov.l   .L15_resume, r2         /* r2 = &RESUME_STATE */
    mov.l   r3, @r2                 /* resume_state = 15 */
    mov     #18, r3
    mov.l   r3, @r10                /* state = 18  (time extension setup) */
.L15_no_start:

    /* --- Decrement countdown --- */
    mov.l   .L15_countdown, r2      /* r2 = &COUNTDOWN */
    mov.l   @r2, r3                 /* r3 = countdown_value */
    add     #-1, r3
    mov.l   r3, @r2                 /* countdown-- */

    /* --- Menu overlay (optional) --- */
    mov.l   .L15_overlay, r0
    mov.b   @r0, r0
    tst     r0, r0
    bt      .L15_no_menu
    mov.l   .L15_menufn, r3
    jsr     @r3                     /* call FUN_060268B0 (menu overlay) */
    mov     #0, r4
.L15_no_menu:

    /* --- Sub-init (optional) --- */
    mov.w   @r11, r0
    extu.w  r0, r0
    tst     r0, r0
    bt      .L15_no_subinit
    mov.l   .L15_subinit, r3
    jsr     @r3                     /* call FUN_060033E6 */
    nop
.L15_no_subinit:

    /* ========================================= */
    /* PER-CAR INNER LOOP                        */
    /* r12 iterates from 0 to [car_count]        */
    /* Each iteration = one car per frame         */
    /* ========================================= */
    mov     #0, r12                 /* r12 = car_index = 0 */

.L15_car_loop:
    cmp/eq  #0, r12
    bf      .L15_not_first

    /* --- First iteration (r12==0): player car --- */
    mov     #1, r3
    mov.w   r3, @r11                /* [init_flag] = 1 */
    mov.l   @r14, r3                /* r3 = car_obj_ptr */
    mov.l   .L15_curobj, r2
    mov.l   r3, @r2                 /* copy to working car object */
    bra     .L15_car_update
    nop

.L15_not_first:
    /* --- Subsequent iterations: AI cars --- */
    mov     #0, r3
    mov.w   r3, @r11                /* [init_flag] = 0 */
    /* Load next car from array at 0x06078900 */
    /* Decrement timer by 2: [timer_byte] -= 2 */
    mov.l   @r8, r3
    add     #-2, r3
    mov.l   r3, @r8

.L15_car_update:
    /* Per-car function calls: */
    mov.l   .L15_snd_upd, r3
    jsr     @r3                     /* FUN_060302C6 - per-car sound update */
    nop
    mov.l   .L15_render1, r3
    jsr     @r3                     /* FUN_0602EFF0 - rendering pass 1 */
    nop
    mov.l   .L15_render2, r3
    jsr     @r3                     /* FUN_0602F0E8 - rendering pass 2 */
    nop
    mov.l   .L15_raceupd, r3
    jsr     @r3                     /* FUN_0600DE54 - RACE STATE UPDATE */
    nop                             /* (physics, position, collision per car) */

    /* --- Increment car index and loop --- */
    add     #1, r12
    mov.l   .L15_carcount, r2
    mov.b   @r2, r2
    extu.b  r2, r2
    cmp/ge  r2, r12
    bf      .L15_car_loop

    /* ========================================= */
    /* POST-LOOP: Race end condition checks      */
    /* ========================================= */

    /* Check car object existence */
    mov.l   .L15_carobj, r0         /* r0 = &CAR_OBJECT (0x0607EAD8) */
    mov.l   @r0, r0
    tst     r0, r0
    bt      .L15_no_car_cleanup
    mov.l   .L15_c302, r3
    jsr     @r3                     /* FUN_0600C302 - car state finalize */
    nop
.L15_no_car_cleanup:

    /* Check countdown reached zero */
    mov.l   .L15_countdown, r2
    mov.l   @r2, r3
    tst     r3, r3
    bf      .L15_no_timeout
    mov     #16, r13                /* prepare state 16 */
.L15_no_timeout:

    /* Check external race end flag */
    mov.l   .L15_raceend, r0
    mov.l   @r0, r0
    tst     r0, r0
    bt      .L15_no_raceend
    mov     #16, r13                /* prepare state 16 */
.L15_no_raceend:

    /* If r13 was set to 16, transition now */
    /* (state = r13 written to STATE_VAR) */

    /* --- Frame finalization --- */
    /* Tail-call FUN_060078DC (frame timing/sync) */
    lds.l   @r15+, pr
    mov.l   @r15+, r8
    mov.l   @r15+, r9
    mov.l   @r15+, r10
    mov.l   @r15+, r11
    mov.l   @r15+, r12
    mov.l   @r15+, r13
    mov.l   .L15_framesync, r3
    jmp     @r3                     /* tail call FUN_060078DC */
    mov.l   @r15+, r14

    .align 2
.L15_timer:     .long 0x0607ED88
.L15_curobj:    .long 0x0607E940
.L15_state:     .long 0x0605AD10
.L15_init:      .long 0x0607ED8C
.L15_carobj2:   .long 0x0607E944
.L15_btnnew:    .long 0x06063D9A
.L15_resume:    .long 0x0607EACC
.L15_countdown: .long 0x0607EAAC
.L15_overlay:   .long 0x0605AB18
.L15_menufn:    .long 0x060268B0
.L15_subinit:   .long 0x060033E6
.L15_snd_upd:   .long 0x060302C6
.L15_render1:   .long 0x0602EFF0
.L15_render2:   .long 0x0602F0E8
.L15_raceupd:   .long 0x0600DE54
.L15_carcount:  .long 0x06078634
.L15_carobj:    .long 0x0607EAD8
.L15_c302:      .long 0x0600C302
.L15_raceend:   .long 0x0607EAD0
.L15_framesync: .long 0x060078DC
.L15_startmask: .word 0x0800



FUN_06009290:
    sts.l   pr, @-r15

    /* Immediately transition to state 17 */
    mov     #17, r3
    mov.l   .L16_state, r2          /* r2 = STATE_VAR */
    mov.l   r3, @r2                 /* state = 17 */

    /* Check car object existence for cleanup */
    mov.l   .L16_carobj, r0         /* r0 = &CAR_OBJECT */
    mov.l   @r0, r0
    tst     r0, r0
    bt      .L16_no_car

    /* Car exists: call cleanup A (FUN_060121A8) */
    mov.l   .L16_cleanupA, r3
    jsr     @r3
    nop
    bra     .L16_done
    nop

.L16_no_car:
    /* No car: call cleanup B (FUN_06012198) */
    mov.l   .L16_cleanupB, r3
    jsr     @r3
    nop

.L16_done:
    /* Set phase flag = 4 */
    mov     #4, r2
    mov.l   .L16_phase, r3          /* r3 = 0x0605A016 */
    lds.l   @r15+, pr
    rts
    mov.w   r2, @r3                 /* [0x0605A016] = 4 */

    .align 2
.L16_state:     .long 0x0605AD10
.L16_carobj:    .long 0x0607EAD8
.L16_cleanupA:  .long 0x060121A8
.L16_cleanupB:  .long 0x06012198
.L16_phase:     .long 0x0605A016



FUN_060092D0:
    mov.l   r14, @-r15
    mov.l   r13, @-r15
    sts.l   pr, @-r15

    mov.l   .L17_carobj, r13        /* r13 = &CAR_OBJECT (0x0607EAD8) */
    mov.l   .L17_state, r14         /* r14 = &STATE_VAR (0x0605AD10) */

    /* --- Start button => state 18 --- */
    mov.l   .L17_btnnew, r3         /* r3 = &BUTTONS_NEW */
    mov.w   @r3, r2
    extu.w  r2, r2
    mov.w   .L17_startmask, r3      /* 0x0800 */
    and     r3, r2
    tst     r2, r2
    bt      .L17_no_start

    mov     #17, r3
    mov.l   .L17_resume, r2
    mov.l   r3, @r2                 /* resume_state = 17 */
    mov     #18, r3
    mov.l   r3, @r14                /* state = 18 (time extension) */
.L17_no_start:

    /* Call FUN_0600A33C (general update) */
    mov.l   .L17_a33c, r3
    jsr     @r3
    nop

    /* Check skip-flag at [0x06085FF4] */
    mov.l   .L17_skipflag, r0
    mov.b   @r0, r0
    tst     r0, r0
    bf      .L17_post_section       /* skip if flag set */

    /* Check race end flag */
    mov.l   .L17_raceend, r0
    mov.l   @r0, r0
    tst     r0, r0
    bf      .L17_post_section       /* skip if race ended */

    /* --- Countdown timer --- */
    mov.l   .L17_countdown, r3
    mov.l   .L17_countdown, r2
    mov.l   @r3, r3                 /* r3 = countdown */
    add     #-1, r3                 /* countdown-- */
    cmp/pl  r3
    bt/s    .L17_post_section       /* if countdown > 0, continue */
    mov.l   r3, @r2                 /* store (delay slot) */

    /* === Timer expired! === */
    mov.l   .L17_resetsnd, r3
    jsr     @r3                     /* FUN_060192CA - reset sound channels */
    nop

    /* Read finish position from car_obj[0x82] */
    mov.l   .L17_curcar, r2
    mov.l   @r2, r2                 /* r2 = car_obj */
    mov.w   .L17_posoff, r0         /* r0 = 0x0082 */
    mov.l   @(r0, r2), r3           /* r3 = car_obj[0x82] (finish position) */
    mov.l   .L17_result, r1
    mov.l   r3, @r1                 /* [RACE_RESULT] = finish_position */

    mov     #24, r3
    mov.l   r3, @r14                /* state = 24 (post-race) */
    bra     .L17_post_section
    nop

.L17_post_section:
    /* --- Check abort flag (bit 0 of FLAGS_WORD) --- */
    mov.l   .L17_flags, r4
    mov.l   @r4, r0
    tst     #0x01, r0
    bt      .L17_no_abort

    /* Abort: clear bit 0, reset sound, go to state 20 */
    mov     #-2, r3                 /* mask 0xFFFFFFFE */
    mov.l   @r4, r2
    and     r3, r2
    mov.l   .L17_resetsnd, r3
    jsr     @r3                     /* reset sound */
    mov.l   r2, @r4                 /* clear bit 0 (delay slot) */

    mov     #20, r2
    mov.l   .L17_sndsetup, r3
    jsr     @r3                     /* FUN_06018E70 - sound transition */
    mov.l   r2, @r14                /* state = 20 (delay slot) */
    bra     .L17_section3
    nop

.L17_no_abort:
    /* If race not ended, increment frame counter */
    mov.l   .L17_raceend2, r0
    mov.l   @r0, r0
    tst     r0, r0
    bf      .L17_section3
    mov.l   .L17_framecnt, r4
    mov.l   @r4, r3
    add     #1, r3
    mov.l   r3, @r4                 /* frame_counter++ */

.L17_section3:
    /* --- Sound trigger at countdown == 200 --- */
    mov.l   .L17_sndtimer, r2      /* r2 = &SOUND_TIMER (0x06086054) */
    mov.w   @r2, r2
    extu.w  r2, r2
    tst     r2, r2
    bf      .L17_no_sound           /* if timer != 0, skip */

    mov.l   .L17_countdown, r3
    mov.w   .L17_val200, r2         /* r2 = 200 (0xC8) */
    mov.l   @r3, r3
    cmp/eq  r2, r3                  /* countdown == 200? */
    bf      .L17_no_sound

    mov.l   .L17_sndcmd, r5         /* r5 = 0xAE1134FF */
    mov.l   .L17_sndapi, r3
    jsr     @r3                     /* play countdown sound! */
    mov     #0, r4

    mov     #40, r2
    mov.l   .L17_sndtimer2, r3
    mov.w   r2, @r3                 /* [SOUND_TIMER] = 40 */
.L17_no_sound:

    /* --- Car display/cleanup --- */
    mov.l   .L17_dispbyte, r0
    mov.b   @r0, r0
    tst     r0, r0
    bt      .L17_no_display

    mov.l   @r13, r0                /* car_object */
    tst     r0, r0
    bt      .L17_cleanup_b
    mov.l   .L17_cleanupA, r3
    jsr     @r3                     /* FUN_060121A8 */
    nop
    bra     .L17_no_display
    nop
.L17_cleanup_b:
    mov.l   .L17_cleanupB, r3
    jsr     @r3                     /* FUN_06012198 */
    nop
.L17_no_display:

    /* --- External event check [0x0607EAE0] --- */
    mov.l   .L17_extevt, r0
    mov.l   @r0, r0
    tst     r0, r0
    bt      .L17_no_ext
    mov.l   .L17_extfn, r3
    jsr     @r3                     /* FUN_0601DE50 - external event */
    nop
    mov.l   @r13, r0
    tst     r0, r0
    bt      .L17_no_ext
    mov.l   .L17_sndext, r3
    jsr     @r3                     /* FUN_0601DBB8 - sound event */
    nop
.L17_no_ext:

    /* --- Menu overlay check --- */
    mov.l   .L17_overlay, r0
    mov.b   @r0, r0
    tst     r0, r0
    bt      .L17_no_menu
    mov.l   .L17_menufn, r3
    jsr     @r3                     /* FUN_060268B0 */
    mov     #0, r4
.L17_no_menu:

    /* --- Mode check: mode == 1 => state 28 --- */
    mov.l   .L17_modeflag, r0
    mov.l   @r0, r0
    cmp/eq  #1, r0
    bf      .L17_no_mode28
    mov     #28, r3
    mov.l   r3, @r14                /* state = 28 */
.L17_no_mode28:

    /* --- Car object == 2 => HUD update --- */
    mov.l   @r13, r0
    cmp/eq  #2, r0
    bf      .L17_no_hud
    mov.l   .L17_hudfn, r3
    jsr     @r3                     /* FUN_06033BC8 */
    nop
.L17_no_hud:

    /* --- Main update pipeline --- */
    mov.l   .L17_de70, r3
    jsr     @r3                     /* FUN_0600DE70 */
    nop
    mov.l   .L17_a914, r3
    jsr     @r3                     /* FUN_0600A914 */
    nop
    mov.l   .L17_bb94, r3
    jsr     @r3                     /* FUN_0600BB94 */
    nop

    /* Display system */
    mov.l   .L17_disp1, r6          /* r6 = &0x06063E24 */
    mov.l   .L17_disp2, r5          /* r5 = &0x06063EEC */
    mov.l   .L17_disp3, r4          /* r4 = &0x06063EF8 */
    mov.l   .L17_dispfn, r3
    jsr     @r3                     /* FUN_060053AC (display commit) */
    mov.l   @r6, r6                 /* delay slot: dereference */

    mov.l   .L17_d9b0, r3
    jsr     @r3                     /* FUN_0601D9B0 (sound update) */
    nop
    mov.l   .L17_bffc, r3
    jsr     @r3                     /* FUN_0600BFFC */
    nop

    /* --- Sub-init and debug checks --- */
    mov.l   .L17_initflag, r0
    mov.w   @r0, r0
    extu.w  r0, r0
    tst     r0, r0
    bt      .L17_no_subinit
    mov.l   .L17_subinit, r3
    jsr     @r3                     /* FUN_060033E6 */
    nop
.L17_no_subinit:

    /* Position check: car_obj[0x82] > 0 => FUN_0600A084 */
    mov.l   .L17_curcar, r2
    mov.w   .L17_posoff, r0         /* r0 = 0x0082 */
    mov.l   @r2, r2
    mov.l   @(r0, r2), r3
    cmp/pl  r3
    bf      .L17_no_score
    bsr     FUN_0600A084
    nop
.L17_no_score:

    /* --- Tail call frame sync --- */
    lds.l   @r15+, pr
    mov.l   @r15+, r13
    mov.l   .L17_framesync, r3
    jmp     @r3                     /* tail call FUN_060078DC */
    mov.l   @r15+, r14

    .align 2
.L17_carobj:    .long 0x0607EAD8
.L17_state:     .long 0x0605AD10
.L17_btnnew:    .long 0x06063D9A
.L17_resume:    .long 0x0607EACC
.L17_a33c:      .long 0x0600A33C
.L17_skipflag:  .long 0x06085FF4
.L17_raceend:   .long 0x0607EAD0
.L17_countdown: .long 0x0607EAAC
.L17_resetsnd:  .long 0x060192CA
.L17_curcar:    .long 0x0607E944
.L17_result:    .long 0x06078638
.L17_flags:     .long 0x0607EBF4
.L17_sndsetup:  .long 0x06018E70
.L17_raceend2:  .long 0x0607EAD0
.L17_framecnt:  .long 0x0607EBD0
.L17_sndtimer:  .long 0x06086054
.L17_sndcmd:    .long 0xAE1134FF
.L17_sndapi:    .long 0x0601D5F4
.L17_sndtimer2: .long 0x06086054
.L17_dispbyte:  .long 0x06078636
.L17_cleanupA:  .long 0x060121A8
.L17_cleanupB:  .long 0x06012198
.L17_extevt:    .long 0x0607EAE0
.L17_extfn:     .long 0x0601DE50
.L17_sndext:    .long 0x0601DBB8
.L17_overlay:   .long 0x0605AB18
.L17_menufn:    .long 0x060268B0
.L17_modeflag:  .long 0x0605A1C4
.L17_hudfn:     .long 0x06033BC8
.L17_de70:      .long 0x0600DE70
.L17_a914:      .long 0x0600A914
.L17_bb94:      .long 0x0600BB94
.L17_disp1:     .long 0x06063E24
.L17_disp2:     .long 0x06063EEC
.L17_disp3:     .long 0x06063EF8
.L17_dispfn:    .long 0x060053AC
.L17_d9b0:      .long 0x0601D9B0
.L17_bffc:      .long 0x0600BFFC
.L17_initflag:  .long 0x0607ED8C
.L17_subinit:   .long 0x060033E6
.L17_framesync: .long 0x060078DC
.L17_startmask: .word 0x0800
.L17_val200:    .word 0x00C8
.L17_posoff:    .word 0x0082



FUN_060096DC:
    mov.l   r14, @-r15
    sts.l   pr, @-r15
    add     #-4, r15

    /* Call time extension initialization/UI */
    bsr     FUN_06009FFC            /* time extension UI setup */
    nop

    /* Transition to state 19 */
    mov     #19, r2
    mov.l   .L18_state, r3
    mov     #0, r14
    mov.l   r2, @r3                 /* state = 19 */

    /* Save current difficulty, clear it */
    mov.l   .L18_diffcur, r4        /* r4 = &DIFFICULTY_CUR (0x06078654) */
    mov.l   .L18_diffsave, r3       /* r3 = &DIFFICULTY_SAVE (0x06078652) */
    mov.b   @r4, r2
    mov.b   r2, @r3                 /* save current -> saved */
    extu.b  r14, r2
    mov.b   r2, @r4                 /* current = 0 (clear) */

    /* Clear frame counter */
    mov.l   .L18_framecnt, r2       /* r2 = &FRAME_COUNT_W (0x06078650) */
    mov.w   r14, @r2                /* frame_counter = 0 */

    /* Display "TIME EXTENSION" text overlay via VDP */
    mov.l   .L18_textdata, r7       /* r7 = 0x060446CC (text data) */
    mov.w   .L18_pos1, r6           /* VDP position */
    mov.w   .L18_pos2, r5           /* VDP position */
    mov.l   .L18_vdpnum, r2         /* r2 = FUN_060284AE */
    jsr     @r2
    mov     #8, r4

    /* Display additional overlay lines */
    mov.l   .L18_hudarea, r3        /* r3 = 0x0605AC9C (HUD area) */
    mov.l   r3, @r15                /* save to stack */
    mov     r3, r7
    mov.l   .L18_f000, r6           /* r6 = 0x0000F000 (color) */
    mov.w   .L18_off1, r5
    add     #46, r7                 /* position offset */
    mov.l   .L18_vdptext, r3
    jsr     @r3                     /* FUN_060283E0 */
    mov     #8, r4

    mov.l   @r15, r7
    mov.l   .L18_f000, r6
    mov.w   .L18_off2, r5
    mov.l   .L18_vdptext, r3
    add     #47, r7
    jsr     @r3                     /* FUN_060283E0 */
    mov     #8, r4

    /* Set display flag bit 2 */
    mov.l   .L18_dispflags, r4      /* r4 = &DISPLAY_FLAGS */
    mov.l   .L18_dispupd, r3        /* r3 = FUN_06026CE0 */
    mov.l   @r4, r0
    or      #0x04, r0               /* set bit 2 */
    jsr     @r3                     /* call display update */
    mov.l   r0, @r4                 /* store (delay slot) */

    /* Clear results and play transition sound */
    mov.l   .L18_results, r3
    mov.l   r14, @r3                /* [RESULTS_FLAG] = 0 */

    mov.l   .L18_sndcmd, r5         /* r5 = 0xAE0004FF (transition sound) */
    mov     r14, r4                 /* r4 = 0 (type 0 = direct) */
    add     #4, r15
    lds.l   @r15+, pr
    mov.l   .L18_sndapi, r3
    jmp     @r3                     /* tail call FUN_0601D5F4 */
    mov.l   @r15+, r14

    .align 2
.L18_state:     .long 0x0605AD10
.L18_diffcur:   .long 0x06078654
.L18_diffsave:  .long 0x06078652
.L18_framecnt:  .long 0x06078650
.L18_textdata:  .long 0x060446CC
.L18_vdpnum:    .long 0x060284AE
.L18_hudarea:   .long 0x0605AC9C
.L18_f000:      .long 0x0000F000
.L18_vdptext:   .long 0x060283E0
.L18_dispflags: .long 0x0605B6D8
.L18_dispupd:   .long 0x06026CE0
.L18_results:   .long 0x06059F44
.L18_sndcmd:    .long 0xAE0004FF
.L18_sndapi:    .long 0x0601D5F4
.L18_pos1:      .word 0x0090
.L18_pos2:      .word 0x051C
.L18_off1:      .word 0x061C
.L18_off2:      .word 0x049C



FUN_06009788:
    mov.l   r14, @-r15
    mov.l   r13, @-r15
    mov.l   r12, @-r15
    mov.l   r11, @-r15
    mov.l   r10, @-r15
    mov.l   r9, @-r15
    mov.l   r8, @-r15
    sts.l   pr, @-r15
    add     #-8, r15

    /* Cache constants in callee-saved registers */
    mov.l   .L19_f000, r8           /* r8 = 0x0000F000 (VDP color) */
    mov.l   .L19_dispflags, r10     /* r10 = &DISPLAY_FLAGS (0x0605B6D8) */
    mov.l   .L19_initflag, r11      /* r11 = &INIT_FLAG (0x0607ED8C) */
    mov.l   .L19_speed, r12         /* r12 = &SPEED_BYTE (0x06078649) */

    /* Read button states, save to stack */
    mov.l   .L19_input, r4          /* r4 = &BUTTONS_HELD */
    mov.w   @(2, r4), r0            /* new buttons */
    mov     r0, r3
    mov.w   r3, @r15                /* stack[0] = new_buttons */
    mov.w   @r4, r3                 /* held buttons */
    mov     r3, r0
    mov.w   r0, @(4, r15)           /* stack[4] = held_buttons */

    /* --- Menu overlay check --- */
    mov.l   .L19_overlay, r0
    mov.b   @r0, r0
    tst     r0, r0
    bt      .L19_no_menu
    mov.l   .L19_menufn, r3
    jsr     @r3                     /* FUN_060268B0 */
    mov     #0, r4
.L19_no_menu:

    /* --- Mode flag check --- */
    mov.l   .L19_modebyte, r0       /* r0 = &MODE_BYTE (0x0607864A) */
    mov.b   @r0, r0
    tst     r0, r0
    bt      .L19_frame_counter      /* mode == 0: skip to frame counter */

    /* ======================================== */
    /* MODE != 0: Speed selection UI            */
    /* Up/Down adjust speed 1-99 at [0x06078649]*/
    /* ======================================== */

    /* Check UP button (0x8000) */
    mov.w   @r15, r3                /* new_buttons */
    mov.l   .L19_upmask, r2         /* 0x00008000 */
    extu.w  r3, r3
    and     r2, r3
    tst     r3, r3
    bt      .L19_check_down

    /* UP pressed: speed++ (max 99) */
    mov     #99, r2
    mov.b   @r12, r3
    extu.b  r3, r3
    cmp/ge  r2, r3                  /* speed >= 99? */
    bt      .L19_display_speed      /* already at max */
    mov.b   @r12, r2
    add     #1, r2
    bra     .L19_display_speed
    mov.b   r2, @r12                /* speed++ (delay slot) */

.L19_check_down:
    /* Check DOWN button */
    mov.w   @r15, r2                /* new_buttons */
    mov.w   .L19_downmask, r3       /* down button mask */
    extu.w  r2, r2
    and     r3, r2
    tst     r2, r2
    bt      .L19_display_speed

    /* DOWN pressed: speed-- (min 1) */
    mov     #1, r2
    mov.b   @r12, r3
    extu.b  r3, r3
    cmp/gt  r2, r3                  /* speed > 1? */
    bf      .L19_display_speed      /* already at min */
    mov.b   @r12, r2
    add     #-1, r2
    mov.b   r2, @r12                /* speed-- */

.L19_display_speed:
    /* Display speed number */
    mov.b   @r12, r7                /* r7 = speed value */
    mov     r8, r6                  /* r6 = 0xF000 (color) */
    mov.w   .L19_numpos, r5         /* position */
    mov.l   .L19_numfn, r3          /* FUN_0602834A (number display) */
    extu.b  r7, r7
    jsr     @r3
    mov     #8, r4

    /* Display speed label text */
    mov     r8, r6
    mov.w   .L19_txtpos, r5
    mov.l   .L19_spdtext, r7        /* 0x060446E0 ("SPEED" text) */
    mov.l   .L19_vdptext, r3
    jsr     @r3                     /* FUN_060283E0 */
    mov     #8, r4

.L19_frame_counter:
    /* ======================================== */
    /* START BUTTON CONFIRMATION                */
    /* Must have >= 20 frames elapsed           */
    /* ======================================== */
    mov.w   .L19_const1, r9         /* r9 = constant */
    mov.w   .L19_const2, r13        /* r13 = constant */
    mov.l   .L19_vdpnum, r14        /* r14 = FUN_060284AE */

    mov.w   @r15, r2                /* new_buttons */
    mov.w   .L19_startmask, r3      /* 0x0800 */
    extu.w  r2, r2
    and     r3, r2
    tst     r2, r2
    bt      .L19_no_start           /* start not pressed */

    /* Start pressed - check debounce */
    mov     #20, r2
    mov.l   .L19_framecnt, r3       /* [FRAME_COUNT_W] */
    mov.w   @r3, r3
    extu.w  r3, r3
    cmp/ge  r2, r3                  /* frame_counter >= 20? */
    bf      .L19_no_start           /* too early, ignore */

    /* Check if already processed */
    mov.l   .L19_modebyte, r0
    mov.b   @r0, r0
    cmp/eq  #1, r0                  /* mode == 1? */
    bt      .L19_no_start           /* already confirmed */

    /* === Confirmed! Play sound, restore state === */
    mov.l   .L19_sndcmd, r5         /* 0xAE0004FF (transition sound) */
    mov.l   .L19_sndapi, r3
    jsr     @r3                     /* play sound */
    mov     #0, r4

    /* Display final overlay */
    mov     r13, r6
    mov.l   .L19_hudarea, r2
    mov.l   r2, @r15
    mov     r2, r7
    mov.w   .L19_hoff1, r5
    add     #59, r7
    jsr     @r14                    /* VDP text display */
    mov     #8, r4

    mov     r13, r6
    mov     r9, r5
    mov.l   @r15, r7
    add     #40, r7
    jsr     @r14
    mov     #8, r4

    mov     r13, r6
    mov.w   .L19_hoff2, r5
    mov.l   @r15, r7
    add     #46, r7
    jsr     @r14
    mov     #8, r4

    /* Restore saved state from RESUME_STATE */
    mov.l   .L19_resume, r3
    mov.l   .L19_statevar, r2
    mov.l   @r3, r3                 /* r3 = saved_state (was 15 or 17) */
    mov.l   r3, @r2                 /* state = saved_state (RETURN TO RACE!) */

    /* Restore saved difficulty */
    mov.l   .L19_diffsave, r3
    mov.l   .L19_diffcur, r2
    mov.b   @r3, r3
    mov.b   r3, @r2                 /* difficulty_cur = difficulty_save */

    /* Check mode for difficulty setup */
    mov.l   .L19_modebyte, r0
    mov.b   @r0, r0
    tst     r0, r0
    bf      .L19_mode_setup         /* mode != 0: setup new difficulty */

    /* Mode 0: direct return to race */
    bra     .L19_common_end
    nop

.L19_mode_setup:
    /* Clear mode byte, call difficulty setup with selected speed */
    mov     #0, r3
    mov     #15, r6
    mov.l   .L19_modebyte2, r2
    mov.b   r3, @r2                 /* [MODE_BYTE] = 0 */

    mov.b   @r12, r5                /* r5 = speed */
    extu.b  r5, r5
    mov.l   r5, @r15                /* save */
    mov.l   .L19_difffn, r3
    jsr     @r3                     /* FUN_06018DDC(speed) - difficulty setup! */
    mov     r5, r4

    /* Display updated difficulty text */
    mov.l   .L19_difftxt, r7        /* 0x060446EC (text) */
    mov     r8, r6
    mov.w   .L19_diffpos, r5
    mov.l   .L19_vdptext, r3
    jsr     @r3                     /* display */
    mov     #8, r4
    bra     .L19_common_end
    nop

.L19_no_start:
    /* ======================================== */
    /* No start: check for secret button combo  */
    /* Held buttons & 0x70 == 0x70 (A+B+C held)*/
    /* ======================================== */
    mov     #0x70, r4               /* mask = A+B+C buttons */
    mov.w   @(4, r15), r0           /* held_buttons */
    mov     r0, r2
    extu.w  r2, r2
    and     r4, r2
    cmp/eq  r4, r2                  /* all three held? */
    bf      .L19_normal_frame

    /* === Secret input! A+B+C held === */
    bsr     FUN_0600A1B8            /* call special function */
    nop
    mov.l   .L19_bit31, r2          /* 0x80000000 */
    mov.l   @r10, r3
    or      r2, r3
    mov.l   r3, @r10                /* set bit 31 in display_flags */

    /* Check init flag */
    mov.w   @r11, r0
    extu.w  r0, r0
    tst     r0, r0
    bt      .L19_back_to_title      /* init_flag == 0: back to title */

    /* Init flag set: force to post-race state 24 */
    mov     #1, r3
    mov.l   .L19_flagsword, r2
    mov.l   r3, @r2                 /* [FLAGS_WORD] = 1 */
    mov     #2, r3
    mov     #24, r2
    mov.w   r3, @r11                /* [INIT_FLAG] = 2 */
    mov.l   .L19_statevar, r3
    mov.l   r2, @r3                 /* state = 24 (post-race) */
    mov.l   .L19_dispupd, r3
    jsr     @r3                     /* FUN_06026CE0 */
    nop
    mov     #0, r2
    mov.l   .L19_results, r3
    mov.l   r2, @r3                 /* clear results */
    bra     .L19_common_end
    nop

.L19_back_to_title:
    /* A+B+C held, no init flag: back to title screen */
    mov     #1, r2
    mov.l   .L19_backtitle, r3      /* &BACK_TO_TITLE (0x0605AD08) */
    mov.l   r2, @r3                 /* set back-to-title flag */
    mov     #14, r2
    mov.l   .L19_statevar, r3
    mov.l   r2, @r3                 /* state = 14 (restart race setup) */
    bra     .L19_common_end
    nop

.L19_normal_frame:
    /* ======================================== */
    /* Normal frame: increment counter + blink  */
    /* ======================================== */
    mov.l   .L19_framecnt2, r4      /* &FRAME_COUNT_W */
    mov.w   @r4, r0
    add     #1, r0
    mov.w   r0, @r4                 /* frame_counter++ */
    extu.w  r0, r0
    tst     #0x10, r0               /* bit 4: toggles every 16 frames */
    bt      .L19_blink_off

    /* Bit 4 set: show "TIME EXTENSION" blinking text */
    mov     r13, r6
    mov     r9, r5
    mov.l   .L19_blinkarea, r3
    mov.l   r3, @r15
    mov     r3, r7
    jsr     @r14                    /* VDP text (line 1) */
    mov     #8, r4
    mov.l   @r15, r7
    mov     r13, r6
    mov.w   .L19_blinkoff, r5
    jsr     @r14                    /* VDP text (line 2) */
    mov     #8, r4
    bra     .L19_common_end
    nop

.L19_blink_off:
    /* Check init flag for display variant */
    mov.w   @r11, r0
    extu.w  r0, r0
    tst     r0, r0
    bt      .L19_standard_display

    /* Active time extension: different text */
    mov     r13, r6
    mov     r9, r5
    mov.l   .L19_text_active, r7    /* 0x060446FC */
    jsr     @r14
    mov     #8, r4
    mov.l   .L19_text_active2, r7   /* 0x06044718 */
    bra     .L19_display_tail
    nop

.L19_standard_display:
    /* Standard display text */
    mov.l   .L19_text_std, r7       /* 0x060446FC */
    mov     r13, r6
    mov     r9, r5
    jsr     @r14
    mov     #8, r4
    mov.l   .L19_text_std2, r7      /* 0x0604472C */

.L19_display_tail:
    mov     r13, r6
    mov.w   .L19_tailpos, r5
    jsr     @r14
    mov     #8, r4

.L19_common_end:
    /* --- Sub-init check --- */
    mov.w   @r11, r0
    extu.w  r0, r0
    tst     r0, r0
    bt      .L19_no_subinit
    mov.l   .L19_subinit, r3
    jsr     @r3                     /* FUN_060033E6 */
    nop
.L19_no_subinit:

    /* --- Debug display check --- */
    mov.l   .L19_debug, r0
    mov.b   @r0, r0
    extu.b  r0, r0
    tst     r0, r0
    bt      .L19_no_debug
    mov     r8, r6
    mov.w   .L19_dbgpos, r5
    mov.l   .L19_dbgaddr, r7
    mov.l   .L19_vdptext, r3
    jsr     @r3                     /* debug VDP display */
    mov     #8, r4
.L19_no_debug:

    /* --- Display update + cleanup --- */
    mov.l   @r10, r0                /* display_flags */
    mov.l   .L19_dispupd, r3
    or      #0x04, r0               /* set bit 2 */
    jsr     @r3                     /* FUN_06026CE0 */
    mov.l   r0, @r10                /* store (delay slot) */

    mov     #0, r2
    mov.l   .L19_results, r3
    mov.l   r2, @r3                 /* clear results flag */

    /* Epilogue */
    add     #8, r15
    lds.l   @r15+, pr
    mov.l   @r15+, r8
    mov.l   @r15+, r9
    mov.l   @r15+, r10
    mov.l   @r15+, r11
    mov.l   @r15+, r12
    mov.l   @r15+, r13
    rts
    mov.l   @r15+, r14

    .align 2
.L19_f000:       .long 0x0000F000
.L19_dispflags:  .long 0x0605B6D8
.L19_initflag:   .long 0x0607ED8C
.L19_speed:      .long 0x06078649
.L19_input:      .long 0x06063D98
.L19_overlay:    .long 0x0605AB18
.L19_menufn:     .long 0x060268B0
.L19_modebyte:   .long 0x0607864A
.L19_modebyte2:  .long 0x0607864A
.L19_upmask:     .long 0x00008000
.L19_numfn:      .long 0x0602834A
.L19_spdtext:    .long 0x060446E0
.L19_vdptext:    .long 0x060283E0
.L19_vdpnum:     .long 0x060284AE
.L19_framecnt:   .long 0x06078650
.L19_sndcmd:     .long 0xAE0004FF
.L19_sndapi:     .long 0x0601D5F4
.L19_hudarea:    .long 0x0605AC9C
.L19_resume:     .long 0x0607EACC
.L19_statevar:   .long 0x0605AD10
.L19_diffsave:   .long 0x06078652
.L19_diffcur:    .long 0x06078654
.L19_difffn:     .long 0x06018DDC
.L19_difftxt:    .long 0x060446EC
.L19_bit31:      .long 0x80000000
.L19_flagsword:  .long 0x0607EBF4
.L19_dispupd:    .long 0x06026CE0
.L19_results:    .long 0x06059F44
.L19_backtitle:  .long 0x0605AD08
.L19_framecnt2:  .long 0x06078650
.L19_blinkarea:  .long 0x0605ACC4
.L19_text_active:  .long 0x060446FC
.L19_text_active2: .long 0x06044718
.L19_text_std:   .long 0x060446FC
.L19_text_std2:  .long 0x0604472C
.L19_subinit:    .long 0x060033E6
.L19_debug:      .long 0x06086030
.L19_dbgaddr:    .long 0x0605A1C8
.L19_startmask:  .word 0x0800
.L19_downmask:   .word 0x4000
.L19_numpos:     .word 0x0CCC
.L19_txtpos:     .word 0x0CB8
.L19_const1:     .word 0x0694
.L19_const2:     .word 0x0090
.L19_hoff1:      .word 0x0526
.L19_hoff2:      .word 0x079C
.L19_blinkoff:   .word 0x04CC
.L19_tailpos:    .word 0x0794
.L19_dbgpos:     .word 0x0214
.L19_diffpos:    .word 0x0900


FUN_06009508:
    sts.l   pr, @-r15

    /* Check abort flag bit 0 */
    mov.l   .L20_flags, r4          /* r4 = &FLAGS_WORD (0x0607EBF4) */
    mov.l   @r4, r0
    tst     #0x01, r0
    bt      .L20_no_abort

    /* Abort: clear bit 0, stay in state 20 */
    mov     #-2, r3
    mov.l   @r4, r2
    and     r3, r2
    mov.l   r2, @r4                 /* clear bit 0 */
    mov     #20, r3
    mov.l   .L20_state, r2
    mov.l   r3, @r2                 /* state = 20 (self-loop) */
    bra     .L20_main
    nop

.L20_no_abort:
    /* Check race end flag for frame counter */
    mov.l   .L20_raceend, r0
    mov.l   @r0, r0
    tst     r0, r0
    bf      .L20_main
    mov.l   .L20_framecnt, r4
    mov.l   @r4, r3
    add     #1, r3
    mov.l   r3, @r4                 /* frame_counter++ */

.L20_main:
    /* Transition to state 29 */
    mov     #29, r2
    mov.l   .L20_state, r3
    mov.l   r2, @r3                 /* state = 29 */

    /* Update pipeline (simpler than state 15/17) */
    mov.l   .L20_dfd0, r3
    jsr     @r3                     /* FUN_0600DFD0 */
    nop
    mov.l   .L20_bb94, r3
    jsr     @r3                     /* FUN_0600BB94 */
    nop

    /* Display system */
    mov.l   .L20_disp1, r6
    mov.l   .L20_disp2, r5
    mov.l   .L20_disp3, r4
    mov.l   .L20_dispfn, r3
    jsr     @r3                     /* FUN_060053AC */
    mov.l   @r6, r6

    mov.l   .L20_c218, r3
    jsr     @r3                     /* FUN_0600C218 */
    nop

    /* Tail call frame sync */
    mov.l   .L20_framesync, r3
    jmp     @r3                     /* FUN_060078DC */
    lds.l   @r15+, pr

    .align 2
.L20_flags:     .long 0x0607EBF4
.L20_state:     .long 0x0605AD10
.L20_raceend:   .long 0x0607EAD0
.L20_framecnt:  .long 0x0607EBD0
.L20_dfd0:      .long 0x0600DFD0
.L20_bb94:      .long 0x0600BB94
.L20_disp1:     .long 0x06063E24
.L20_disp2:     .long 0x06063EEC
.L20_disp3:     .long 0x06063EF8
.L20_dispfn:    .long 0x060053AC
.L20_c218:      .long 0x0600C218
.L20_framesync: .long 0x060078DC
