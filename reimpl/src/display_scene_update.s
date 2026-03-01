
    .section .text.FUN_0603C08C


    .global display_scene_update
    .type display_scene_update, @function
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
    .2byte  0x0009

    .global sym_0603C0A0
sym_0603C0A0:
    mov.l   .L_sh2_dvsr, r0
    swap.w r4, r2
    mov.l r5, @r0
    exts.w r2, r2
    mov.l r2, @(16, r0)
    shll16 r4
    mov.l r4, @(20, r0)
    rts
    mov.l @(20, r0), r0
    .2byte  0x0009
    .4byte  0x6043000B
    .4byte  0x40280009
    .4byte  0x60434029
    .4byte  0x000B600F
    .4byte  0x010A021A
    .4byte  0xE000400A
    .4byte  0x401A054F
    .4byte  0x054F054F
    .4byte  0x030A001A
    .4byte  0x410A421A
    .4byte  0x000B203D
    .4byte  0x2F36E3F0
    .4byte  0x4F03633C
    .4byte  0x430ED305
    .4byte  0x23020009
    .4byte  0x13110009
    .4byte  0x50350009
    .4byte  0x4F0763F6
    .4byte  0x000B6103
.L_sh2_dvsr:
    .4byte  0xFFFFFF00                  /* SH2 DVSR — divisor */
