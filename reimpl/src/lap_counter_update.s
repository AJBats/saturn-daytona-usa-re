
    .section .text.FUN_060158DE


    .global lap_counter_update
    .type lap_counter_update, @function
lap_counter_update:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD0, 0x15    /* mov.l .L_race_end_flag, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt/s    .L_060158F8
    mov #0x1, r4
    exts.w r4, r4
    .byte   0xD3, 0x13    /* mov.l .L_final_lap_flag, r3 */
    mov.w r4, @r3
    bra     .L_06015926
    nop
.L_060158F8:
    mov.b @r15, r2
    extu.b r4, r0
    .byte   0xD1, 0x0D    /* mov.l .L_lap_slot_base, r1 */
    extu.b r2, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r1, r2
    mov.b r0, @(1, r2)
    .byte   0xD5, 0x0C    /* mov.l .L_car_struct_base, r5 */
    mov.w   .L_off_car_id, r0
    .byte   0xD3, 0x0C    /* mov.l .L_sound_table, r3 */
    .byte   0xD2, 0x0C    /* mov.l .L_fn_sound_cmd, r2 */
    mov.l @(r0, r5), r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    jsr @r2
    mov #0x0, r4
.L_06015926:
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .byte   0xD3, 0x08    /* mov.l .L_fn_lap_display, r3 */
    jmp @r3
    lds.l @r15+, pr
.L_off_car_id:
    .2byte  0x0224                      /* car struct offset: sound ID for this car */
.L_lap_slot_base:
    .4byte  sym_06084FC8               /* base of lap slot array (20 bytes per car) */
    .4byte  sym_0605B8A4               /* (adjacent data) */
.L_race_end_flag:
    .4byte  sym_0607EAE0               /* race end flag (32-bit, nonzero = ended) */
.L_final_lap_flag:
    .4byte  sym_06085F94               /* final lap completion flag (16-bit) */
.L_car_struct_base:
    .4byte  sym_06078900               /* car struct array base */
.L_sound_table:
    .4byte  sym_06044BD8               /* lap completion sound table (4 bytes per entry) */
.L_fn_sound_cmd:
    .4byte  sound_cmd_dispatch         /* sound command dispatch */
.L_fn_lap_display:
    .4byte  sym_060172E4               /* lap display handler */
