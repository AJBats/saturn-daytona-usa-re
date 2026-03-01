
    .section .text.FUN_06014994


    .global channel_config_b
    .type channel_config_b, @function
channel_config_b:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_060149C8, r14
    mov.w   .L_wpool_060149C4, r4
    jsr @r14
    mov #0x4, r5
    mov #0x1, r5
    jsr @r14
    mov #0x4, r4
    mov #0x0, r5
    jsr @r14
    mov #0x8, r4
    mov #0x6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x7, r5
    jsr @r14
    mov #0x20, r4
    mov #0x0, r5
    jsr @r14
    mov #0x1, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_060149C4:
    .2byte  0x0100
    .2byte  0xFFFF
.L_pool_060149C8:
    .4byte  channel_nibble_config

    .global sym_060149CC
sym_060149CC:
    mov.l   .L_pool_060149F8, r3
    mov.l   .L_pool_060149FC, r2
    mov.w @r2, r2
    or r3, r2
    mov.l   .L_pool_060149FC, r3
    mov.w r2, @r3
    mov #0x1, r2
    mov.l   .L_pool_06014A00, r3
    rts
    mov.w r2, @r3

    .global sym_060149E0
sym_060149E0:
    mov.w   .L_wpool_060149F4, r3
    mov.l   .L_pool_060149FC, r2
    mov.w @r2, r2
    and r3, r2
    mov.l   .L_pool_060149FC, r3
    mov.w r2, @r3
    mov #0x1, r2
    mov.l   .L_pool_06014A00, r3
    rts
    mov.w r2, @r3
.L_wpool_060149F4:
    .2byte  0x7FFF
    .2byte  0xFFFF
.L_pool_060149F8:
    .4byte  0x00008000
.L_pool_060149FC:
    .4byte  sym_060A3D88
.L_pool_06014A00:
    .4byte  sym_060635AC
