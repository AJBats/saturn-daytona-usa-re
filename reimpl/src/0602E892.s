	.text
    .global main_scene_render
main_scene_render:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0x77    /* bra 0x0602E78C (external) */
    nop
    .short  0x0000
    .long  0x00000000
    .long  0xAE1109FF
    .long  sound_cmd_dispatch

    .global sym_0602E8AC
sym_0602E8AC:
    .long  loc_06060BD4
    .long  loc_06060C44
    .long  loc_06060CB4

    .global sym_0602E8B8
sym_0602E8B8:
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0000
    mov #0x66, r6
    .word 0x0000
    .word 0xCCCC
    .word 0x0000
    .byte   0xB3, 0x33    /* bsr 0x0602EF48 (external) */
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0001
    .word 0x0000

    .global sym_0602E938
sym_0602E938:
    bt.s    .L_0602E9DA
    mov.w @r15+, r8
    mov.l @(0, r0), r0
    mov.l @(40, r7), r2
    bt.s    .L_0602E9E2
    mov.w @r15+, r8
    mov.l @(0, r0), r0
    mov.l @(40, r7), r2
    .word 0xFD4F
    tst #0xF5, r0
    mov.w r0, @(22, r14)
    mov.w @(0, r0), r0
    .word 0xFD4F
    tst #0xF5, r0
    mov.w r0, @(22, r14)
    mov.w @(0, r0), r0
    mov #0x4F, r13
    .byte   0xD8, 0xF5    /* mov.l .L_pool_0602ED3C, r8 */
    mov.w   .L_wpool_0602E963, r0
    add #0x7A, r1
.L_wpool_0602E963:
    .short  0xED4F
    .short  0xD8F5
    .long  0x9000717A
    .long  0xCD4F98F5
    .long  0x81EB847A
    .long  0xCD4F98F5
    .long  0x81EB847A
    .long  0x8D4F68F5
    .long  0x51EB547A
    .long  0x8D4F68F5
    .long  0x51EB547A
    .long  0xCD4FC8F5
    .long  0xA1EB847A
    .long  0xCD4FC8F5
    .long  0xA1EB847A
    .long  0x8D4F68F5
    .long  0x5000517A
    .long  0x8D4F68F5
    .long  0x5000517A

    .global loc_0602E9A8
loc_0602E9A8:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    sett
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mul.l r1, r0
    .word 0x0000
    .word 0x0060
    .word 0x0001
    mov.b r0, @(0, r0)
    .word 0x0000
    .word 0x0000
    .word 0x0000
.L_0602E9DA:
    .byte   0xD0, 0x00    /* mov.l .L_pool_0602E9E0, r0 */
.L_pool_0602E9E0:
    .long  0x00003C00
    .short  0x0004
.L_0602E9E2:
    mov.b r0, @(0, r0)
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mov.l r1, @(r0, r0)
    .word 0x0000
    sett
    .word 0x0001
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mov #0x0, r0
    .word 0x0000
    mov.b @r0, r0
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mul.l r1, r0
    .word 0x0000
    mov.b @(r0, r0), r0
    .word 0x0000
    mov.b r0, @(0, r0)
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mov #0x0, r8
    .word 0x0000
    add #0x0, r0
    mov.w r0, @(r0, r0)
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mac.l @r1+, @r0+
    .word 0x0000
    sett
    .word 0x0000
    mov.b r0, @r8
    .word 0x0000
    mov.w   .L_wpool_0602EA3E, r8
    .word 0x0000
.L_wpool_0602EA3E:
    .short  0xD200
    .long  0x00006800
    .long  0x0001E800
    .long  0x00000000
    .long  0x00000017
    .long  0x00000010
    .long  0xFFFF0000
    .long  0x00000000
    .long  0x0000D000
    .long  0x0000B000
    .long  0x00021800
    .long  0x00000000
    .long  0x0000001F
    .long  0x00000010
    .long  0x00000000
    .long  0x00000000
    .long  0x0000F300
    .long  0x0000C000
    .long  0x00058000
    .long  0x00000000
    .long  0xFFFFFFFF

    .global loc_0602EA8C
loc_0602EA8C:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0020
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mac.l @r0+, @r0+
    .word 0x0000
    .word 0x0060
    .word 0x0000
    .word 0x0000
    .word 0x0001
    mov.b r0, @(0, r0)
    .word 0x0000
    .byte   0xD0, 0x00    /* mov.l .L_pool_0602EAC5, r0 */
.L_pool_0602EAC5:
    .long  0x00007C00
    .long  0x00048000
    .long  0x00000000
    .long  0x0000000E
    .long  0x00000018
    .long  0x00000000
    .long  0x00010000
    .long  0x0000E000
    .long  0x0000A000
    .long  0x00000000
    .long  0x00000000
    .long  0x0000000F
    .long  0x0000000C
    .long  0x00000000
    .long  0x00008000
    .long  0x0000E800
    .long  0x0000B000
    .long  0x00050000
    .long  0x00000000
    .long  0x0000001F
    .long  0x00000018
    .long  0xFFFF6800
    .long  0x00002800
    .long  0x0000D200
    .long  0x0000A800
    .long  0x0001E800
    .long  0x00000000
    .long  0x0000000F
    .long  0x00000010
    .long  0x00000000
    .long  0xFFFF0000
    .long  0x0000D000
    .long  0x0000F000
    .long  0x00021800
    .long  0x00000000
    .long  0x0000001F
    .long  0x00000010
    .long  0x00000000
    .long  0x00000000
    .long  0x0000F300
    .long  0x00010000
    .long  0x00058000
    .long  0x00000000
    .long  0xFFFFFFFF

    .global loc_0602EB70
loc_0602EB70:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    sett
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mul.l r1, r0
    .word 0x0000
    .word 0x0060
    .word 0xFFFE
    mov.b r0, @(0, r0)
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .byte   0xD0, 0x00    /* mov.l .L_pool_0602EBAA, r0 */
.L_pool_0602EBAA:
    .long  0x0000AF33
    .long  0x00048000
    .long  0x00000000
    .long  0x00000016
    .long  0x00000018
    .long  0xFFFF0000
    .long  0x00000000
    .long  0x0000E000
    .long  0x0000D333
    .long  0x00000000
    .long  0x00000000
    .long  0x00000017
    .long  0x0000000C
    .long  0xFFFF8000
    .long  0x00000000
    .long  0x0000E800
    .long  0x0000E333
    .long  0x00050000
    .long  0x00000000
    .long  0x0000001F
    .long  0x00000018
    .long  0xFFFFD800
    .long  0xFFFF3800
    .long  0x0000D200
    .long  0x0000DB33
    .long  0x0001F800
    .long  0x00000000
    .long  0x00000017
    .long  0x00000010
    .long  0x00010000
    .long  0x00000000
    .long  0x0000D000
    .long  0x00012333
    .long  0x00023800
    .long  0x00000000
    .long  0x0000001F
    .long  0x00000010
    .long  0x00000000
    .long  0x00000000
    .long  0x0000F300
    .long  0x00013333
    .long  0x00058000
    .long  0x00000000
    .long  0xFFFFFFFF

    .global sym_0602EC54
sym_0602EC54:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0020
    .word 0x0000
    .word 0x0050
    .word 0x0000
    .word 0x0080
    .word 0x0000
    .word 0x00B0
    .word 0x0000
    .word 0x00D0
    .word 0x0000
    .word 0x00D0
    .word 0x0000
    .word 0x00D0
    .word 0x0000
    .word 0x00D0
    .word 0x0000
    .word 0x00D0
    .word 0x0000
    .word 0x00D0
    .word 0x0000
    .word 0x0080
    .long  0x00000040
    .long  0x00000000
    .long  0xFFFFC000
    .long  0x00000000
    .long  0x00004000
    .long  0x00000000

    .global sym_0602ECAC
sym_0602ECAC:
    .word 0xFFFF
    .word 0xF800
    .word 0x0000
    cmp/eq r0, r8
    .word 0x0000
    add #0x0, r8
    .word 0x0000
    .word 0x0000

    .global sym_0602ECBC
sym_0602ECBC:
    .long  loc_0602E9A8
    .long  loc_0602EA8C
    .long  loc_0602EB70
    .long  loc_0602EA8C

    .global sym_0602ECCC
sym_0602ECCC:
    mov.l r3, @-r15
    mov #-0x10, r3
    stc.l sr, @-r15
    extu.b r3, r3
    .long  0x430ED305
    .long  0x23020009
    .long  0x13110009
    .long  0x50350009
    .long  0x4F0763F6
    .long  0x000B6103
    .long  0xFFFFFF00
    .short  0xFF00

    .global sym_0602ECF2
sym_0602ECF2:
    .byte   0xD1, 0x04    /* mov.l .L_pool_0602ED0C, r1 */
    mov.l @r1, r2
    .byte   0xD3, 0x04    /* mov.l .L_pool_0602ED10, r3 */
    shll2 r2
    add r2, r3
    mov.l @r3, r3
    jmp @r3
    nop
    .short  0x0000
.L_pool_0602ED0C:
    .long  sym_0607EAE4
.L_pool_0602ED10:
    .long  sym_0602ED0C

    .global sym_0602ED0C
sym_0602ED0C:
    .long  loc_0602ED18
    .long  loc_0602ED18
    .long  loc_0602EEAC

    .global loc_0602ED18
loc_0602ED18:
    .byte   0xD0, 0x2A    /* mov.l .L_pool_0602EDC8, r0 */
    mov #0x50, r1
    mov.b r1, @r0
    .byte   0xD0, 0x2A    /* mov.l .L_pool_0602EDD0, r0 */
    mov.l @r0, r0
    .byte   0xD1, 0x2A    /* mov.l .L_pool_0602EDD4, r1 */
    mov.l @r1, r2
    add #0x1, r2
    mov.l r2, @r1
    mov.l @(8, r0), r2
    shll16 r2
    .byte   0x92, 0x3F    /* mov.w .L_wpool_0602EDB6, r2 */
.L_pool_0602ED3C:
    .long  0xE3000236
    .long  0x913DE301
    .long  0x923C4328
    .long  0x01360236
    .long  0x9139E301
    .long  0x310C2132
    .long  0x11311132
    .long  0x11339133
    .long  0xD31F310C
    .long  0x21329230
    .long  0xD11E022D
    .long  0x932E4200
    .long  0x312C330C
    .long  0x64142340
    .long  0x64107301
    .long  0x2340D11A
    .long  0x93254200
    .long  0x312C6112
    .long  0x03169121
    .long  0x041D2448
    .long  0xD1168900
    .long  0xD116931C
    .long  0x312C330C
    .long  0x62152321
    .long  0x62117302
    .long  0x23212F86
    .long  0x2F962FA6
    .long  0x2FB62FC6
    .short  0x2FD6
