
    .section .text.FUN_06041204


    .global evt_field_update
    .type evt_field_update, @function
evt_field_update:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD7, 0x21    /* mov.l .L_pool_06041290, r7 */
    .byte   0x90, 0x40    /* mov.w .L_wpool_0604128E, r0 */
    mov.l @r7, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_0604121C
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x1, r0
.L_0604121C:
    mov.l @r7, r0
    mov.l @(52, r0), r0
    cmp/eq #0x1, r0
    bf      .L_0604122C
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x5, r0
.L_0604122C:
    mov.l @r7, r2
    mov #0x1, r3
    mov.l r3, @(52, r2)
    mov.l @r7, r2
    .byte   0x90, 0x2B    /* mov.w .L_wpool_0604128E, r0 */
    mov.l r3, @(r0, r2)
    mov.l @r7, r3
    add #0x4, r0
    mov.l r4, @(r0, r3)
    add #0x4, r0
    mov.l @r7, r3
    mov.l r5, @(r0, r3)
    mov.l @r7, r3
    add #0x4, r0
    mov.l r6, @(r0, r3)
    .byte   0xB5, 0x3D    /* bsr 0x06041CC8 (external) */
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
