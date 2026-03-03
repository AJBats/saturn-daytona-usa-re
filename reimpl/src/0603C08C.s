	.text
    .global display_scene_update
display_scene_update:
    sts mach, r1
    sts macl, r2
    dmuls.l r4, r5
    sts mach, r3
    sts macl, r0
    lds r1, mach
    lds r2, macl
    rts
    xtrct r3, r0
    .short  0x0009

    .global sym_0603C0A0
sym_0603C0A0:
    mov.l   .L_0603C100, r0
    swap.w r4, r2
    mov.l r5, @r0
    exts.w r2, r2
    mov.l r2, @(16, r0)
    shll16 r4
    mov.l r4, @(20, r0)
    rts
    mov.l @(20, r0), r0
    .short  0x0009
    .long  0x6043000B
    .long  0x40280009
    .long  0x60434029
    .long  0x000B600F
    .long  0x010A021A
    .long  0xE000400A
    .long  0x401A054F
    .long  0x054F054F
    .long  0x030A001A
    .long  0x410A421A
    .long  0x000B203D
    .long  0x2F36E3F0
    .long  0x4F03633C
    .long  0x430ED305
    .long  0x23020009
    .long  0x13110009
    .long  0x50350009
    .long  0x4F0763F6
    .long  0x000B6103
.L_0603C100:
    .long  0xFFFFFF00
