
    .section .text.FUN_0600A0C0


    .global race_resource_init
    .type race_resource_init, @function
race_resource_init:
    mov.l r14, @-r15
    sts.l pr, @-r15

    mov.w   .L_w_channel_bitmask, r4
    mov.l   .L_fn_channel_nibble_config, r3
    jsr @r3
    mov #0x0, r5

    mov.l   .L_fn_camera_finalize, r3
    jsr @r3
    nop

    mov #0x0, r14
    mov.l   .L_ptr_anim_state, r3
    mov.l r14, @r3

    mov.l   .L_ptr_car_struct_base, r4
    mov.l   .L_fn_vdp2_scroll_update, r3
    jsr @r3
    nop

    mov.w   DAT_0600a110, r2
    mov r14, r6
    mov r14, r5
    mov.l r2, @-r15
    mov.w   DAT_0600a112, r7
    mov.l   .L_fn_erase_window_set, r3
    jsr @r3
    mov r14, r4

    mov.l   .L_ptr_dma_config, r3
    mov.l r14, @r3

    mov.l   .L_ptr_car_struct_base, r2
    mov.l   .L_fp_half, r3
    mov.l @r2, r2
    mov.w r3, @r2

    mov.l   .L_fn_camera_finalize, r3
    jsr @r3
    add #0x4, r15

    mov.l   .L_ptr_anim_state, r3
    mov.l r14, @r3

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600a10c
DAT_0600a10c:
    mov.b @(r0, r11), r0
.L_w_channel_bitmask:
    .2byte  0x0100                     /* [HIGH] channel priority bitmask */

    .global DAT_0600a110
DAT_0600a110:
    .2byte  0x00DF                     /* screen height - 1 (223) */

    .global DAT_0600a112
DAT_0600a112:
    .2byte  0x015F                     /* screen width - 1 (351) */
    .4byte  sym_0607E944               /* (adjacent TU pool entry) */
    .4byte  display_channel_b          /* (adjacent TU pool entry) */
    .4byte  sym_0607EBC8               /* (adjacent TU pool entry) */
.L_fn_channel_nibble_config:
    .4byte  channel_nibble_config      /* [HIGH] channel priority nibble config fn */
.L_fn_camera_finalize:
    .4byte  sym_06026CE0               /* [HIGH] display update / palette commit fn */
.L_ptr_anim_state:
    .4byte  sym_06059F44               /* [HIGH] VBlank-OUT counter / animation state */
.L_ptr_car_struct_base:
    .4byte  sym_06063F5C               /* [HIGH] VDP1 command buffer base pointer */
.L_fn_vdp2_scroll_update:
    .4byte  vdp2_scroll_update         /* [HIGH] VDP2 scroll plane update fn */
.L_fn_erase_window_set:
    .4byte  sym_060393FC               /* [HIGH] vdp1_erase_window_set fn */
.L_ptr_dma_config:
    .4byte  sym_0605A008               /* [HIGH] frame counter / DMA config state */
.L_fp_half:
    .4byte  0x00008000                 /* [HIGH] 0.5 (16.16 fixed-point) */
