	.text
    .global mat_rot_yz_b
mat_rot_yz_b:
    sts.l pr, @-r15
    .byte   0xD6, 0x50    /* mov.l .L_pool_06027334, r6 */
    mov #0x8, r5
    .byte   0xB0, 0xB0    /* bsr 0x06027358 (external) */
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(4, r6)
    .byte   0xD0, 0x4A    /* mov.l .L_pool_0602732C, r0 */
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
.L_0602720A:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov r4, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(4, r4)
    bf.s    .L_0602720A
    add #0xC, r4
    rts
    nop
    .short  0xD03D
    .long  0xD63F6502
    .long  0xE303E203
    .long  0x0028054F
    .long  0x7408054F
    .long  0x74084210
    .long  0x054F74E8
    .long  0x75F4000A
    .long  0x011A210D
    .long  0x26128FF1
    .long  0x760474F4
    .long  0x43108FEC
    .long  0x750C6753
    .long  0x75DC7424
    .long  0xE3030028
    .long  0x054F054F
    .long  0x4310054F
    .long  0x74F4000A
    .long  0x011A210D
    .long  0x6076310C
    .long  0x26128FF2
    .long  0x760476D0
    .long  0x77D05060
    .long  0x51615262
    .long  0x53635464
    .long  0x55651700
    .long  0x17111722
    .long  0x17331744
    .long  0x17555066
    .long  0x51675268
    .long  0x5369546A
    .long  0x556B1706
    .long  0x17171728
    .long  0x1739174A
    .long  0x000B175B
