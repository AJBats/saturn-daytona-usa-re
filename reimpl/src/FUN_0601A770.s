
    .section .text.FUN_0601A770


    .global FUN_0601A770
    .type FUN_0601A770, @function
FUN_0601A770:
    sts.l pr, @-r15
    .byte   0xD0, 0x1C    /* mov.l .L_ptr_course_active_flag, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601A78E
    .byte   0xD3, 0x1A    /* mov.l .L_fn_load_gamed_lowram, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x1A    /* mov.l .L_fn_load_slctd_lowram, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x16    /* mov.l .L_ptr_course_active_flag, r3 */
    mov.b r2, @r3
.L_0601A78E:
    .byte   0xD2, 0x18    /* mov.l .L_ptr_variant_init_flag, r2 */
    mov.b @r2, r2
    tst r2, r2
    bt      .L_0601A7A2
    .byte   0xD3, 0x17    /* mov.l .L_fn_race_variant_e, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x14    /* mov.l .L_ptr_variant_init_flag, r3 */
    mov.b r2, @r3
.L_0601A7A2:
    .byte   0xD5, 0x15    /* mov.l .L_snd_init_cmd, r5 */
    mov #0x0, r4
    .byte   0xD3, 0x15    /* mov.l .L_fn_sound_cmd_dispatch, r3 */
    jmp @r3
    lds.l @r15+, pr


    .global FUN_0601A7AC
    .type FUN_0601A7AC, @function
FUN_0601A7AC:
    sts.l pr, @-r15
    mov.l   .L_pool_0601A800, r5
    mov.l   .L_pool_0601A804, r4
    mov.w   .L_0601A7E2, r2
    mov.w @(2, r4), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0601A7C8
    mov #0x0, r3
    mov.b r3, @r5
    bra     .L_0601A7DA
    nop
.L_0601A7C8:
    mov.w @(2, r4), r0
    mov.l   .L_pool_0601A808, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601A7DA
    mov #0x1, r3
    mov.b r3, @r5
.L_0601A7DA:
    .reloc ., R_SH_IND12W, FUN_0601A65E - 4
    .2byte 0xB000    /* bsr FUN_0601A65E (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601A73E - 4
    .2byte 0xA000    /* bra FUN_0601A73E (linker-resolved) */
    lds.l @r15+, pr
.L_0601A7E2:
    .2byte  0x4000
    .4byte  sym_06085FF6
    .4byte  sym_06012EC4
    .4byte  sym_06012F00
    .4byte  sym_06085FF7
    .4byte  FUN_060191E0
    .4byte  0xAE0001FF
    .4byte  FUN_0601D5F4
.L_pool_0601A800:
    .4byte  sym_0605D241
.L_pool_0601A804:
    .4byte  g_pad_state
.L_pool_0601A808:
    .4byte  0x00008000
