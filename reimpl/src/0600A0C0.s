	.text
    .global race_resource_init
race_resource_init:
    mov.l r14, @-r15
    sts.l pr, @-r15

    mov.w   .L_0600A10E, r4
    mov.l   .L_0600A120, r3
    jsr @r3
    mov #0x0, r5

    mov.l   .L_0600A124, r3
    jsr @r3
    nop

    mov #0x0, r14
    mov.l   .L_0600A128, r3
    mov.l r14, @r3

    mov.l   .L_0600A12C, r4
    mov.l   .L_0600A130, r3
    jsr @r3
    nop

    mov.w   DAT_0600a110, r2
    mov r14, r6
    mov r14, r5
    mov.l r2, @-r15
    mov.w   DAT_0600a112, r7
    mov.l   .L_0600A134, r3
    jsr @r3
    mov r14, r4

    mov.l   .L_0600A138, r3
    mov.l r14, @r3

    mov.l   .L_0600A12C, r2
    mov.l   .L_0600A13C, r3
    mov.l @r2, r2
    mov.w r3, @r2

    mov.l   .L_0600A124, r3
    jsr @r3
    add #0x4, r15

    mov.l   .L_0600A128, r3
    mov.l r14, @r3

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600a10c
DAT_0600a10c:
    mov.b @(r0, r11), r0
.L_0600A10E:
    .short  0x0100

    .global DAT_0600a110
DAT_0600a110:
    .short  0x00DF

    .global DAT_0600a112
DAT_0600a112:
    .short  0x015F
    .long  sym_0607E944
    .long  display_channel_b
    .long  sym_0607EBC8
.L_0600A120:
    .long  channel_nibble_config
.L_0600A124:
    .long  sym_06026CE0
.L_0600A128:
    .long  sym_06059F44
.L_0600A12C:
    .long  sym_06063F5C               /* [HIGH] VDP1 command buffer base pointer */
.L_0600A130:
    .long  vdp2_scroll_update
.L_0600A134:
    .long  sym_060393FC
.L_0600A138:
    .long  sym_0605A008
.L_0600A13C:
    .long  0x00008000
