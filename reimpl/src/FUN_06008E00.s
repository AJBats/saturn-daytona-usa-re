
    .section .text.FUN_06008E00


    .global FUN_06008E00
    .type FUN_06008E00, @function
FUN_06008E00:
    sts.l pr, @-r15
    .byte   0xD3, 0x20    /* mov.l .L_fn_race_resource_init, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x1F    /* mov.l .L_fn_race_prep_init, r3 */
    jsr @r3
    nop
    mov #0xD, r2
    mov.l   .L_06008E8C, r3
    mov.l r2, @r3
    .byte   0xD3, 0x1E    /* mov.l .L_fn_car_physics_init, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x1E    /* mov.l .L_fn_obj_render_update, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x1D    /* mov.l .L_display_flags, r4 */
    .byte   0xD2, 0x1E    /* mov.l .L_race_ready_bit, r2 */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   .L_06008EA0, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_06008EA4, r3
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x1B    /* mov.l .L_phase_flag, r3 */
    mov.w r2, @r3
    mov #0xF, r6
    mov #0x5, r5
    mov r5, r4
    .byte   0xD3, 0x1A    /* mov.l .L_fn_handler_dispatch, r3 */
    jmp @r3
    lds.l @r15+, pr


    .global FUN_06008E48
    .type FUN_06008E48, @function
FUN_06008E48:
    sts.l pr, @-r15
    mov.l   .L_06008EB0, r3
    mov.l @r3, r3
    cmp/pz r3
    bt      .L_06008E68
    mov #0xE, r3
    mov.l   .L_06008E8C, r2
    mov.l r3, @r2
    mov.l   .L_06008EA0, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_06008EA4, r3
    mov.l r2, @r3
    bra     .L_06008E6E
    nop
.L_06008E68:
    mov.l   .L_06008EB4, r3
    jsr @r3
    nop
.L_06008E6E:
    mov.l   .L_06008E8C, r0
    mov.l @r0, r0
    cmp/eq #0xD, r0
    bt      .L_06008E7C
    mov.l   .L_06008EB8, r3
    jmp @r3
    lds.l @r15+, pr
.L_06008E7C:
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF
    .4byte  FUN_0600A0C0
    .4byte  FUN_06018FA4
.L_06008E8C:
    .4byte  FUN_0605ACC4
    .4byte  FUN_0600EC78
    .4byte  FUN_060210F6
    .4byte  sym_0605B6D8
    .4byte  0x40000000
.L_06008EA0:
    .4byte  sym_06026CE0
.L_06008EA4:
    .4byte  sym_06059F44
    .4byte  sym_0605A016
    .4byte  FUN_06018DDC
.L_06008EB0:
    .4byte  sym_0607EBCC
.L_06008EB4:
    .4byte  FUN_0600F424
.L_06008EB8:
    .4byte  FUN_06018E70
