
    .section .text.FUN_0602E892


    .global main_scene_render
    .type main_scene_render, @function
main_scene_render:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0x77    /* bra 0x0602E78C (external) */
    nop
    .2byte  0x0000
    .4byte  0x00000000
    .4byte  0xAE1109FF
    .4byte  sound_cmd_dispatch

    .global sym_0602E8AC
sym_0602E8AC:
    .4byte  loc_06060BD4
    .4byte  loc_06060C44
    .4byte  loc_06060CB4

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
    .byte   0xB3, 0x33    /* bsr 0x0602EF48 (external) — data, not a real branch */
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
    bt/s    .L_scene_data_block_a
    mov.w @r15+, r8
    mov.l @(0, r0), r0
    mov.l @(40, r7), r2
    bt/s    .L_scene_data_block_b
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
    .byte   0xD8, 0xF5    /* mov.l .L_pool_0602ED3C, r8 — data, not code */
    mov.w   .L_wpool_0602E963, r0
    add #0x7A, r1
.L_wpool_0602E963:
    .2byte  0xED4F
    .2byte  0xD8F5
    .4byte  0x9000717A
    .4byte  0xCD4F98F5
    .4byte  0x81EB847A
    .4byte  0xCD4F98F5
    .4byte  0x81EB847A
    .4byte  0x8D4F68F5
    .4byte  0x51EB547A
    .4byte  0x8D4F68F5
    .4byte  0x51EB547A
    .4byte  0xCD4FC8F5
    .4byte  0xA1EB847A
    .4byte  0xCD4FC8F5
    .4byte  0xA1EB847A
    .4byte  0x8D4F68F5
    .4byte  0x5000517A
    .4byte  0x8D4F68F5
    .4byte  0x5000517A

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
.L_scene_data_block_a:
    .byte   0xD0, 0x00    /* mov.l .L_pool_0602E9E0, r0 */
.L_pool_0602E9E0:
    .4byte  0x00003C00
    .2byte  0x0004
.L_scene_data_block_b:
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
    .2byte  0xD200
    .4byte  0x00006800
    .4byte  0x0001E800
    .4byte  0x00000000
    .4byte  0x00000017
    .4byte  0x00000010
    .4byte  0xFFFF0000
    .4byte  0x00000000
    .4byte  0x0000D000
    .4byte  0x0000B000
    .4byte  0x00021800
    .4byte  0x00000000
    .4byte  0x0000001F
    .4byte  0x00000010
    .4byte  0x00000000
    .4byte  0x00000000
    .4byte  0x0000F300
    .4byte  0x0000C000
    .4byte  0x00058000
    .4byte  0x00000000
    .4byte  0xFFFFFFFF

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
    .4byte  0x00007C00
    .4byte  0x00048000
    .4byte  0x00000000
    .4byte  0x0000000E
    .4byte  0x00000018
    .4byte  0x00000000
    .4byte  0x00010000
    .4byte  0x0000E000
    .4byte  0x0000A000
    .4byte  0x00000000
    .4byte  0x00000000
    .4byte  0x0000000F
    .4byte  0x0000000C
    .4byte  0x00000000
    .4byte  0x00008000
    .4byte  0x0000E800
    .4byte  0x0000B000
    .4byte  0x00050000
    .4byte  0x00000000
    .4byte  0x0000001F
    .4byte  0x00000018
    .4byte  0xFFFF6800
    .4byte  0x00002800
    .4byte  0x0000D200
    .4byte  0x0000A800
    .4byte  0x0001E800
    .4byte  0x00000000
    .4byte  0x0000000F
    .4byte  0x00000010
    .4byte  0x00000000
    .4byte  0xFFFF0000
    .4byte  0x0000D000
    .4byte  0x0000F000
    .4byte  0x00021800
    .4byte  0x00000000
    .4byte  0x0000001F
    .4byte  0x00000010
    .4byte  0x00000000
    .4byte  0x00000000
    .4byte  0x0000F300
    .4byte  0x00010000
    .4byte  0x00058000
    .4byte  0x00000000
    .4byte  0xFFFFFFFF

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
    .4byte  0x0000AF33
    .4byte  0x00048000
    .4byte  0x00000000
    .4byte  0x00000016
    .4byte  0x00000018
    .4byte  0xFFFF0000
    .4byte  0x00000000
    .4byte  0x0000E000
    .4byte  0x0000D333
    .4byte  0x00000000
    .4byte  0x00000000
    .4byte  0x00000017
    .4byte  0x0000000C
    .4byte  0xFFFF8000
    .4byte  0x00000000
    .4byte  0x0000E800
    .4byte  0x0000E333
    .4byte  0x00050000
    .4byte  0x00000000
    .4byte  0x0000001F
    .4byte  0x00000018
    .4byte  0xFFFFD800
    .4byte  0xFFFF3800
    .4byte  0x0000D200
    .4byte  0x0000DB33
    .4byte  0x0001F800
    .4byte  0x00000000
    .4byte  0x00000017
    .4byte  0x00000010
    .4byte  0x00010000
    .4byte  0x00000000
    .4byte  0x0000D000
    .4byte  0x00012333
    .4byte  0x00023800
    .4byte  0x00000000
    .4byte  0x0000001F
    .4byte  0x00000010
    .4byte  0x00000000
    .4byte  0x00000000
    .4byte  0x0000F300
    .4byte  0x00013333
    .4byte  0x00058000
    .4byte  0x00000000
    .4byte  0xFFFFFFFF

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
    .4byte  0x00000040
    .4byte  0x00000000
    .4byte  0xFFFFC000
    .4byte  0x00000000
    .4byte  0x00004000
    .4byte  0x00000000

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
    .4byte  loc_0602E9A8
    .4byte  loc_0602EA8C
    .4byte  loc_0602EB70
    .4byte  loc_0602EA8C

    .global sym_0602ECCC
sym_0602ECCC:
    mov.l r3, @-r15
    mov #-0x10, r3
    stc.l sr, @-r15
    extu.b r3, r3
    .4byte  0x430ED305
    .4byte  0x23020009
    .4byte  0x13110009
    .4byte  0x50350009
    .4byte  0x4F0763F6
    .4byte  0x000B6103
    .4byte  0xFFFFFF00
    .2byte  0xFF00

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
    .2byte  0x0000
.L_pool_0602ED0C:
    .4byte  sym_0607EAE4
.L_pool_0602ED10:
    .4byte  sym_0602ED0C

    .global sym_0602ED0C
sym_0602ED0C:
    .4byte  loc_0602ED18
    .4byte  loc_0602ED18
    .4byte  loc_0602EEAC

    .global loc_0602ED18
loc_0602ED18:
    .byte   0xD0, 0x2A    /* mov.l .L_pool_sound_cooldown_ptr, r0 — [HIGH] sym_0602FDA1 SINIT sound cooldown counter */
    mov #0x50, r1
    mov.b r1, @r0
    .byte   0xD0, 0x2A    /* mov.l .L_pool_car_ptr_global, r0 — [HIGH] sym_0607E944 current car pointer */
    mov.l @r0, r0
    .byte   0xD1, 0x2A    /* mov.l .L_pool_physics_step_counter, r1 — [HIGH] sym_0607EAE4 physics step counter */
    mov.l @r1, r2
    add #0x1, r2
    mov.l r2, @r1
    mov.l @(8, r0), r2
    shll16 r2
    .byte   0x92, 0x3F    /* mov.w .L_wpool_render_dim_const, r2 — [LOW] loads 0x005C render dimension constant */
.L_pool_0602ED3C:
    .4byte  0xE3000236
    .4byte  0x913DE301
    .4byte  0x923C4328
    .4byte  0x01360236
    .4byte  0x9139E301
    .4byte  0x310C2132
    .4byte  0x11311132
    .4byte  0x11339133
    .4byte  0xD31F310C
    .4byte  0x21329230
    .4byte  0xD11E022D
    .4byte  0x932E4200
    .4byte  0x312C330C
    .4byte  0x64142340
    .4byte  0x64107301
    .4byte  0x2340D11A
    .4byte  0x93254200
    .4byte  0x312C6112
    .4byte  0x03169121
    .4byte  0x041D2448
    .4byte  0xD1168900
    .4byte  0xD116931C
    .4byte  0x312C330C
    .4byte  0x62152321
    .4byte  0x62117302
    .4byte  0x23212F86
    .4byte  0x2F962FA6
    .4byte  0x2FB62FC6
    .2byte  0x2FD6
