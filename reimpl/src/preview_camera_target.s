
    .section .text.FUN_0601A7AC


    .global preview_camera_target
    .type preview_camera_target, @function
preview_camera_target:
    sts.l pr, @-r15
    mov.l   .L_pool_0601A800, r5
    mov.l   .L_pool_0601A804, r4
    mov.w   .L_w_down_btn_mask, r2
    mov.w @(2, r4), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_check_up_button
    mov #0x0, r3
    mov.b r3, @r5
    bra     .L_init_and_trigger
    nop
.L_check_up_button:
    mov.w @(2, r4), r0
    mov.l   .L_pool_0601A808, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_init_and_trigger
    mov #0x1, r3
    mov.b r3, @r5
.L_init_and_trigger:
    .byte   0xBF, 0x40    /* bsr 0x0601A65E (external) */
    nop
    .byte   0xAF, 0xAE    /* bra 0x0601A73E (external) */
    lds.l @r15+, pr
.L_w_down_btn_mask:
    .2byte  0x4000                             /* [HIGH] Down button mask (bit 14) */
    .4byte  sym_06085FF6                       /* (unused pool entry) */
    .4byte  sym_06012EC4                       /* (unused pool entry) */
    .4byte  sym_06012F00                       /* (unused pool entry) */
    .4byte  sym_06085FF7                       /* (unused pool entry) */
    .4byte  race_variant_e                     /* (unused pool entry) */
    .4byte  0xAE0001FF                         /* (unused pool entry) */
    .4byte  sound_cmd_dispatch                 /* (unused pool entry) */
.L_pool_0601A800:
    .4byte  sym_0605D241                       /* [HIGH] two-player mode flag (byte, 0=1P, 1=2P) */
.L_pool_0601A804:
    .4byte  g_pad_state                       /* [HIGH] held button state struct */
.L_pool_0601A808:
    .4byte  0x00008000                         /* [HIGH] Up button mask (bit 15, 32-bit for AND) */
