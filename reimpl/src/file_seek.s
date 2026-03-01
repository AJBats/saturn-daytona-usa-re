
    .section .text.FUN_06012054


    .global file_seek
    .type file_seek, @function
file_seek:
    sts.l pr, @-r15
    mov.l   .L_pool_chan_nibble_cfg, r14
    jsr @r14
    mov #0x10, r4
    mov #0x6, r5
    jsr @r14
    mov #0x8, r4
    mov.w   .L_wpool_bit_a0_lo_nib, r4
    jsr @r14
    mov #0x5, r5
    mov #0x3, r5
    jsr @r14
    mov #0x20, r4
    mov #0x1, r5
    jsr @r14
    mov #0x4, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_bit_a0_lo_nib:
    .2byte  0x0100                  /* [HIGH] bitmask 0x0100: channel array_a[0] low nibble selector */
.L_pool_chan_nibble_cfg:
    .4byte  channel_nibble_config   /* [HIGH] &channel_nibble_config -- display channel nibble-pack setter */
