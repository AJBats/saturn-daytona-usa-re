	.text
    .global display_cmd_position
display_cmd_position:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0x6A    /* bra 0x0603230A (external) */
    nop
    .short  0x0000
    .long  sound_cmd_dispatch

    .global loc_0603243C
loc_0603243C:
    .byte   0xD2, 0x04    /* mov.l .L_pool_06032450, r2 */
    .byte   0xD0, 0x05    /* mov.l .L_pool_06032454, r0 */
    mov.b @r0, r1
    or r2, r1
    mov.b r1, @r0
    xor r1, r1
    .byte   0xD0, 0x03    /* mov.l .L_pool_06032458, r0 */
    .byte   0xAF, 0x5E    /* bra 0x0603230A (external) */
    mov.l r1, @r0
    .short  0x0000
.L_pool_06032450:
    .long  0x00000001
.L_pool_06032454:
    .long  sym_06082A25
.L_pool_06032458:
    .long  sym_06082A28

    .global loc_0603245C
loc_0603245C:
    .byte   0xD2, 0x03    /* mov.l .L_pool_0603246C, r2 */
    .byte   0xD0, 0x04    /* mov.l .L_pool_06032470, r0 */
    not r2, r2
    mov.b @r0, r1
    and r2, r1
    .byte   0xAF, 0x50    /* bra 0x0603230A (external) */
    mov.b r1, @r0
    .short  0x0000
.L_pool_0603246C:
    .long  0x00000001
.L_pool_06032470:
    .long  sym_06082A25

    .global loc_06032474
loc_06032474:
    .byte   0xD2, 0x03    /* mov.l .L_pool_06032484, r2 */
    .byte   0xD0, 0x04    /* mov.l .L_pool_06032488, r0 */
    not r2, r2
    mov.b @r0, r1
    and r2, r1
    .byte   0xAF, 0x44    /* bra 0x0603230A (external) */
    mov.b r1, @r0
    .short  0x0000
.L_pool_06032484:
    .long  0x00000002
.L_pool_06032488:
    .long  sym_06082A25

    .global loc_0603248C
loc_0603248C:
    .byte   0xD2, 0x02    /* mov.l .L_pool_06032498, r2 */
    .byte   0xD0, 0x03    /* mov.l .L_pool_0603249C, r0 */
    mov.b @r0, r1
    or r2, r1
    .byte   0xAF, 0x39    /* bra 0x0603230A (external) */
    mov.b r1, @r0
.L_pool_06032498:
    .long  0x00000002
.L_pool_0603249C:
    .long  sym_06082A25

    .global loc_060324A0
loc_060324A0:
    .byte   0xD0, 0x07    /* mov.l .L_pool_060324C0, r0 */
    mov.l @r0, r0
    mov.l @r0, r1
    .byte   0xD2, 0x07    /* mov.l .L_pool_060324C4, r2 */
    and r2, r1
    mov.l r1, @r0
    .byte   0xD0, 0x06    /* mov.l .L_pool_060324C8, r0 */
    xor r1, r1
    mov.b r1, @r0
    .byte   0xD0, 0x06    /* mov.l .L_pool_060324CC, r0 */
    mov.b @r0, r1
    .byte   0xD2, 0x06    /* mov.l .L_pool_060324D0, r2 */
    or r2, r1
    .byte   0xAF, 0x26    /* bra 0x0603230A (external) */
    mov.b r1, @r0
    .short  0x0000
.L_pool_060324C0:
    .long  sym_0607E944
.L_pool_060324C4:
    .long  0xFFFEFFFF
.L_pool_060324C8:
    .long  sym_06082A24
.L_pool_060324CC:
    .long  sym_06082A25
.L_pool_060324D0:
    .long  0x00000004
    .long  0xD00401EC
    .long  0x21188919
    .long  0xE0042108
    .long  0x8B04A021
    .long  0x00090000
    .long  0x000002DC
