
    .section .text.FUN_060120A0


    .global file_close
    .type file_close, @function
file_close:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_channel_nibble_config, r14
    jsr @r14
    mov #0x20, r4
    mov #0x6, r5
    jsr @r14
    mov #0x8, r4
    mov.w   .L_wpool_bitmask_0x0100, r4
    jsr @r14
    mov #0x5, r5
    mov #0x4, r5
    jsr @r14
    mov #0x10, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_bitmask_0x0100:
    .2byte  0x0100                          /* [MEDIUM] bitmask for array_a[0] low nibble field */
.L_pool_channel_nibble_config:
    .4byte  channel_nibble_config           /* [HIGH] channel nibble config function pointer */
