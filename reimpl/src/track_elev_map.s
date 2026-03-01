
    .section .text.FUN_060146D4


    .global track_elev_map
    .type track_elev_map, @function
track_elev_map:
    sts.l pr, @-r15
    mov.l   .L_ptr_countdown_timer, r2
    mov.l r3, @r2
    mov.l   .L_ptr_car_count, r4
    .byte   0xB0, 0x46    /* bsr perspective_proj_3d (file ID search) */
    nop
    exts.b r0, r0
    tst r0, r0
    bt      .L_search_terminated
    mov #0x6, r3
    mov.l   .L_ptr_phase_byte_a, r2
    mov.b r3, @r2
    bra     .L_check_status_flags
    nop
    .4byte  sym_06084B18                /* active car count (32-bit) — prev TU pool */
    .4byte  sym_06084AF0                /* frame timer base (16-bit) — prev TU pool */
.L_ptr_countdown_timer:
    .4byte  sym_0607EBCC                /* countdown timer (32-bit, in frames) */
.L_ptr_car_count:
    .4byte  sym_06084FB4                /* car count output parameter */
.L_ptr_phase_byte_a:
    .4byte  sym_06084AF2                /* phase byte (results state machine) */
.L_search_terminated:
    mov #0x4, r2
    mov.l   .L_ptr_phase_byte_b, r3
    mov.b r2, @r3
.L_check_status_flags:
    mov.l   .L_ptr_status_flags, r0
    mov.l @r0, r0
    tst #0x1, r0
    bf      .L_done
    mov.l   .L_ptr_cam_entry, r4
    mov.l @r4, r4
    tst r4, r4
    bt      .L_try_override_ptr
    mov.l   .L_ptr_variant_buf, r5
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5, r3
    mov.b r3, @r4
.L_try_override_ptr:
    mov.l   .L_ptr_cam_override, r4
    mov.l @r4, r4
    tst r4, r4
    bt      .L_done
    mov.l   .L_ptr_variant_buf, r5
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r5, r3
    mov.b r3, @r4
.L_done:
    lds.l @r15+, pr
    rts
    nop
.L_ptr_phase_byte_b:
    .4byte  sym_06084AF2                /* phase byte (results state machine) */
.L_ptr_status_flags:
    .4byte  sym_06084B10                /* status flags (bit 0 = skip variant copy) */
.L_ptr_cam_entry:
    .4byte  sym_06085FFC                /* active camera cut-point entry pointer */
.L_ptr_variant_buf:
    .4byte  sym_06084B14                /* variant char buffer (4 bytes) */
.L_ptr_cam_override:
    .4byte  sym_06086000                /* camera override pointer */
