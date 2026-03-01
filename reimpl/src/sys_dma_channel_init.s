
    .section .text.FUN_0603B8B4


    .global sys_dma_channel_init
    .type sys_dma_channel_init, @function
sys_dma_channel_init:
    mov.l r14, @-r15
    mov r4, r14
    add #-0x4, r15
    mov.l   .L_pool_0603B920, r4
    mov.w   .L_wpool_0603B91C, r0
    mov.l @r4, r3
    mov.l @(r0, r3), r2
    cmp/eq r14, r2
    bf      .L_0603B8EE
    mov.l @r4, r2
    mov #0x0, r3
    mov.w   .L_wpool_0603B91C, r0
    mov.l r3, @(r0, r2)
    mov.l @r4, r3
    mov #0x10, r0
    mov.b @(r0, r14), r2
    extu.b r2, r2
    shll2 r2
    shll2 r2
    add #0x4, r3
    add r3, r2
    mov.l r2, @r15
    mov r2, r3
    mov.l @(4, r3), r3
    mov #0x1, r5
    mov.l @r14, r4
    add #0x4, r15
    jmp @r3
    mov.l @r15+, r14
.L_0603B8EE:
    add #0x4, r15
    rts
    mov.l @r15+, r14
    .4byte  0x7FFC2F42
    .4byte  0xD4099010
    .4byte  0x6342023E
    .4byte  0x63F23230
    .4byte  0x8B106342
    .4byte  0xE2009008
    .4byte  0x0326E5FF
    .4byte  0x64F25442
    .4byte  0xD303432B
    .4byte  0x7F0400F0
.L_wpool_0603B91C:
    .2byte  0x00A8

    .global DAT_0603b91e
DAT_0603b91e:
    .2byte  0x00B4
.L_pool_0603B920:
    .4byte  sym_060A4D14
    .4byte  race_timer_sync
    .4byte  0x000B7F04
