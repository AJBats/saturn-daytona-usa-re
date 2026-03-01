
    .section .text.FUN_0604140E


    .global nmi_handler
    .type nmi_handler, @function
nmi_handler:
    sts.l pr, @-r15
    add #-0xC, r15
    cmp/pz r4
    bf      .L_slot_out_of_range
    mov #0x18, r2
    cmp/ge r2, r4
    bf      .L_check_occupancy
.L_slot_out_of_range:
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov #-0x6, r0
.L_check_occupancy:
    .byte   0xD0, 0x09    /* mov.l .L_ai_state_base, r0 */
    mov.l @r0, r0
    mov.b @(r0, r4), r3
    tst r3, r3
    bf      .L_compute_distance
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov #-0x7, r0
.L_compute_distance:
    .byte   0xD3, 0x06    /* mov.l .L_fn_track_dist, r3 */
    jsr @r3
    nop
    mov r0, r4
    tst r4, r4
    bt      .L_write_result
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov #-0xA, r0
    .2byte  0x0348
.L_ai_state_base:
    .4byte  sym_060A5400
.L_fn_track_dist:
    .4byte  track_dist_stub
.L_write_result:
    .byte   0xD3, 0x1C    /* mov.l .L_pool_060414C8, r3 — external fn (cross-TU) */
    jsr @r3
    mov r15, r4
    .byte   0xD2, 0x1C    /* mov.l .L_pool_060414CC, r2 — AI state ptr (cross-TU) */
    mov.l @r2, r2
    mov r15, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov #0x0, r0
    add #0xC, r15
    lds.l @r15+, pr
    rts
    nop
