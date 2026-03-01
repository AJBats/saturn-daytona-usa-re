
    .section .text.FUN_0600A392


    .global FUN_0600A392
    .type FUN_0600A392, @function
FUN_0600A392:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    .byte   0xDD, 0x10    /* mov.l .L_pool_0600A3E6, r13 */
    .byte   0xD3, 0x11    /* mov.l .L_pool_0600A3EA, r3 */
    jsr @r3
    nop
    mov #0xF, r14
    and r0, r14
    mov r14, r0
    cmp/eq #0x6, r0
    bf      .L_0600A3B6
    .byte   0xD3, 0x0E    /* mov.l .L_pool_0600A3EE, r3 */
    mov.l @r3, r3
    jsr @r3
    nop
.L_0600A3B6:
    .byte   0xDC, 0x0D    /* mov.l .L_pool_0600A3F2, r12 */
    mov.b @r12, r0
    tst r0, r0
    bf      .L_0600A3F8
    .byte   0xD3, 0x0C    /* mov.l .L_pool_0600A3F6, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r4
    mov #0x64, r2
    mov.b @(6, r4), r0
    mov r0, r4
    extu.b r4, r3
    cmp/ge r2, r3
    bt      .L_0600A40E
    .byte   0xD3, 0x08    /* mov.l .L_pool_0600A3FA, r3 */
    mov.b r4, @r3
    bra     .L_0600A40E
    nop
    .2byte  0xFFFF
    .4byte  sym_06078644
.L_pool_0600A3E6:
    .4byte  g_game_state
.L_pool_0600A3EA:
    .4byte  cdb_read_status
.L_pool_0600A3EE:
    .4byte  sym_0600026C
.L_pool_0600A3F2:
    .4byte  sym_0607864A
.L_pool_0600A3F6:
    .4byte  cd_block_read_safe
.L_pool_0600A3FA:
    .4byte  sym_06078649
.L_0600A3F8:
    mov.b @r12, r0
    cmp/eq #0x1, r0
    bf      .L_0600A40E
    mov r14, r0
    cmp/eq #0x1, r0
    bf      .L_0600A40E
    .byte   0xD3, 0x17    /* mov.l .L_pool_0600A46E, r3 */
    jsr @r3
    nop
    mov #0x2, r2
    mov.b r2, @r12
.L_0600A40E:
    .byte   0xD5, 0x16    /* mov.l .L_pool_0600A472, r5 */
    mov.w   DAT_0600a460, r2
    mov.w @(2, r5), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0600A454
    mov.w   .L_wpool_0600A46C, r4
    mov.w @r5, r3
    extu.w r3, r3
    and r4, r3
    cmp/eq r4, r3
    bf      .L_0600A454
    .byte   0xBD, 0xE7    /* bsr 0x06009FFC (external) */
    nop
    mov #0x6, r3
    mov.l @r13, r2
    cmp/hs r3, r2
    bf      .L_0600A44C
    .byte   0xBE, 0xBF    /* bsr 0x0600A1B8 (external) */
    nop
    mov.l @r13, r0
    cmp/eq #0x17, r0
    bf      .L_0600A446
    .byte   0xD3, 0x0A    /* mov.l .L_pool_0600A476, r3 */
    jsr @r3
    nop
.L_0600A446:
    mov #0x0, r2
    bra     .L_0600A454
    mov.l r2, @r13
.L_0600A44C:
    .byte   0xD2, 0x08    /* mov.l .L_pool_0600A47A, r2 */
    mov.l @r2, r2
    jsr @r2
    nop
.L_0600A454:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600a460
DAT_0600a460:
    .2byte  0x0800
.L_wpool_0600A46C:
    .2byte  0x0700
.L_pool_0600A46E:
    .4byte  cd_status_reader
.L_pool_0600A472:
    .4byte  g_pad_state
.L_pool_0600A476:
    .4byte  obj_state_pack
.L_pool_0600A47A:
    .4byte  sym_0600026C
