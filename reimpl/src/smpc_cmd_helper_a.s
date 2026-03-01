
    .section .text.FUN_06035C08


    .global smpc_cmd_helper_a
    .type smpc_cmd_helper_a, @function
smpc_cmd_helper_a:
    sts.l pr, @-r15
    mov r5, r1
    mov.l   .L_pool_06035C18, r3
    jsr @r3
    mov r4, r0
    lds.l @r15+, pr
    rts
    nop
.L_pool_06035C18:
    .4byte  sym_06035FEC

    .global sym_06035C1C
sym_06035C1C:
    bra     .L_strlen_test
    mov #0x0, r5
.L_strlen_inc:
    add #0x1, r5
.L_strlen_test:
    mov.b @r4+, r3
    tst r3, r3
    bf      .L_strlen_inc
    rts
    mov r5, r0

    .global sym_06035C2C
sym_06035C2C:
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.w   .L_wpool_06035C46, r3
    mov #0x0, r2
    mov.l r0, @r3
    add #0x8, r3
    mov.l r2, @r3
    mov.l r1, @-r3
    add #0xC, r3
    mov.l @r3, r0
    mov.l @r15+, r3
    rts
    mov.l @r15+, r2
.L_wpool_06035C46:
    .2byte  0xFF00                      /* [HIGH] SH-2 division unit base (DVSR register at 0xFFFFFF00) */

    .global sym_06035C48
sym_06035C48:
    .byte   0xD0, 0x0A    /* mov.l pool@0x06035C74 (external: 0x25818000 VDP1 TVMR), r0 */
    rts
    nop

    .global sym_06035C4E
sym_06035C4E:
    .byte   0xD0, 0x0A    /* mov.l pool@0x06035C78 (external: CD HIRQ reg addr), r0 */
    rts
    mov.w @r0, r0
