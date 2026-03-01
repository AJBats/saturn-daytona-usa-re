
    .section .text.FUN_06032D0E


    .global hud_master_compositor
    .type hud_master_compositor, @function
hud_master_compositor:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x0C    /* mov.l .L_mat_stack_a_ptr, r13 */
    mov.l @r13, r13
    rts
    nop
    .2byte  0x0000
    .4byte  0x00000060
    .4byte  sym_06026E2E
    .4byte  0x0000003C
    .4byte  mat_rot_x
    .4byte  0x00000040
    .4byte  mat_rot_z
    .4byte  0x0000003E
    .4byte  mat_rot_y
    .4byte  0x000001D4
    .4byte  sym_06026DBC
.L_mat_stack_a_ptr:
    .4byte  sym_06089EDC                   /* [HIGH] matrix stack A pointer (VDP1 display list) */
    .4byte  0x0000006C
    .4byte  0x00000042
    .4byte  0x00000046
    .4byte  0x00000044
    .4byte  0x00000204
    .4byte  0x00000078
    .4byte  0x00000048
    .4byte  0x00000234
    .4byte  sym_06026DF8
    .4byte  0x00000084
    .4byte  0x0000004A
    .4byte  0x0000004E
    .4byte  0x0000004C
    .4byte  0x00000264
    .4byte  0x00000090
    .4byte  0x00000050
    .4byte  0x00000294
    .4byte  0xD0166002
    .4byte  0xD116210E
    .4byte  0x001AD316
    .4byte  0x330CD013
    .4byte  0x60024008
    .4byte  0xD114021E
    .4byte  0xD01401EC
    .4byte  0x41084108
    .4byte  0x321C6126
    .4byte  0x6436314C
    .4byte  0xD0110E16
    .4byte  0x61266436
    .4byte  0x314CD010
    .4byte  0x0E166126
    .4byte  0x6436314C
    .4byte  0xD00E0E16
    .4byte  0x6125D007
    .4byte  0x0E156124
    .4byte  0xD00C0E14
    .4byte  0xD00B01EC
    .4byte  0x4108D00B
    .4byte  0x021ED00B
    .4byte  0x000B0E26
    .4byte  sym_0607EAD8
    .4byte  0x0000000C
    .4byte  sym_060624A4
    .4byte  sym_060624F8
    .4byte  0x000002DC
    .4byte  0x00000000
    .4byte  0x00000004
    .4byte  0x00000008
    .4byte  0x000002DD
    .4byte  sym_06062624
    .4byte  0x000002D8
    .4byte  0xD00A0E46
    .4byte  0x44084400
    .4byte  0xD009340C
    .4byte  0x61466246
    .4byte  0xD0080E16
    .4byte  0xD0080E26
    .4byte  0xD00801ED
    .4byte  0xD0082108
    .4byte  0x89106123
    .4byte  0x71FFA00E
    .4byte  0x00090000
    .4byte  0x000002D0
    .4byte  sym_060627F8
    .4byte  0x000002CC
    .4byte  0x000002C8
    .4byte  0x0000000E
    .4byte  0x00000002
    .4byte  0xD101D002
    .4byte  0x000B0E16
    .4byte  0x00000001
    .4byte  0x000002C4
    .4byte  0xD00800EE
    .4byte  0xD108210F
    .4byte  0x011AD008
    .4byte  0x02EE321C
    .4byte  0xD30733EC
    .4byte  0xD6076726
    .4byte  0x23727304
    .4byte  0x46108BFA
    .4byte  0x000B0009
    .4byte  0x000002C4
    .4byte  0x00000044
    .4byte  0x000002CC
    .4byte  0x00000010
    .4byte  0x00000011
    .4byte  0xD00301ED
    .4byte  0xD0032108
    .4byte  0x8B06000B
    .4byte  0x00090000
    .4byte  0x0000000E
    .4byte  0x0000001C
    .2byte  0xD049
