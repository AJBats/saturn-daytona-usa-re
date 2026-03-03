	.text
    .global vdp1_normal_sprite
vdp1_normal_sprite:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xA2, 0x98    /* bra 0x0602E16C (external) */
    nop
    .long  sym_06082A30
    .long  sym_0602DC44

    .global sym_0602DC44
sym_0602DC44:
    .long  loc_0602DC58
    .long  loc_0602DD10
    .long  loc_0602DE60
    .long  loc_0602E078
    .long  loc_0602E108

    .global loc_0602DC58
loc_0602DC58:
    .byte   0xD1, 0x10    /* mov.l .L_pool_0602DC9C, r1 */
    mov.l @r1, r3
    add #0x1, r3
    mov.l r3, @r1
    .byte   0xD4, 0x0F    /* mov.l .L_pool_0602DCA0, r4 */
    cmp/eq r3, r4
    .byte   0x8B, 0x08    /* bf 0x0602DC78 (external) */
    .byte   0xDD, 0x0F    /* mov.l .L_pool_0602DCA4, r13 */
