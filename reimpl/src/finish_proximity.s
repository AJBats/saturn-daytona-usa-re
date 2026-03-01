
    .section .text.FUN_0600DA7C


    .global finish_proximity
    .type finish_proximity, @function
finish_proximity:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_0600DB48, r4
    mov.l   .L_0600DB4C, r14
    mov.l   .L_0600DB50, r5
    mov.w   DAT_0600db40, r0
    mov.l @r4, r4
    mov.l @(r0, r4), r0
    tst r0, r0
    bt/s    .L_0600DAB4
    mov #0x1, r6
    mov.w @r14, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_0600DB5C
    mov r6, r0
    mov.w   .L_0600DB42, r1
    mov.l   .L_0600DB54, r3
    jsr @r3
    mov r4, r2
    mov.w @r5, r2
    add #0x1, r2
    mov.w r2, @r5
    add #0x8, r15
    lds.l @r15+, pr
    bra     car_update_post
    mov.l @r15+, r14
.L_0600DAB4:
    mov.w   DAT_0600db44, r0
    mov.l @(r0, r4), r7
    add #-0x4, r0
    mov r7, r3
    shll2 r7
    shll2 r3
    shll r7
    shll2 r3
    add r3, r7
    mov.l @(r0, r4), r3
    add r3, r7
    mov.w @(14, r7), r0
    mov r0, r3
    shll2 r3
    mov.l r3, @r15
    mov.l @(40, r4), r2
    sub r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(4, r15)
    mov.l @(32, r4), r7
    mov.l @r15, r3
    mov.w @(4, r15), r0
    sub r3, r7
    mov r0, r2
    extu.w r2, r2
    mov.l r2, @r15
    mov.w   DAT_0600db46, r1
    cmp/ge r1, r2
    bf/s    .L_0600DB0A
    extu.w r7, r7
    mov.l @r15, r3
    mov.l   .L_0600DB58, r2
    cmp/gt r2, r3
    bt      .L_0600DB0A
    extu.w r7, r2
    mov.w   DAT_0600db46, r3
    cmp/ge r3, r2
    bf      .L_0600DB0A
    extu.w r7, r3
    mov.l   .L_0600DB58, r2
    cmp/gt r2, r3
    bf      .L_0600DB24
.L_0600DB0A:
    mov #0x0, r6
    mov.w   .L_0600DB42, r1
    mov.l   .L_0600DB54, r3
    mov r6, r0
    jsr @r3
    mov r4, r2
    mov.w r6, @r5
    extu.w r6, r6
    mov.w r6, @r14
    add #0x8, r15
    lds.l @r15+, pr
    bra     checkpoint_sound_trigger
    mov.l @r15+, r14
.L_0600DB24:
    mov r6, r0
    mov.w   .L_0600DB42, r1
    mov.l   .L_0600DB54, r3
    jsr @r3
    mov r4, r2
    mov.w @r5, r2
    add #0x1, r2
    mov.w r2, @r5
    extu.w r6, r6
    mov.w r6, @r14
    add #0x8, r15
    lds.l @r15+, pr
    bra     car_update_post
    mov.l @r15+, r14

    .global DAT_0600db40
DAT_0600db40:
    .2byte  0x00B8                      /* car struct offset: proximity state */
.L_0600DB42:
    .2byte  0x1C01                      /* bitfield param: bit_pos=28, count=1 -> bit 3 (proximity) */

    .global DAT_0600db44
DAT_0600db44:
    .2byte  0x01E4                      /* car struct offset: checkpoint index */

    .global DAT_0600db46
DAT_0600db46:
    .2byte  0x4000                      /* angular distance lower threshold */
.L_0600DB48:
    .4byte  sym_0607E940                /* -> car object pointer */
.L_0600DB4C:
    .4byte  sym_0607869A                /* -> proximity flag word */
.L_0600DB50:
    .4byte  sym_06078698                /* -> proximity counter */
.L_0600DB54:
    .4byte  sym_06034F78                /* -> bitfield write utility */
.L_0600DB58:
    .4byte  0x0000C000                  /* angular distance upper threshold */
.L_0600DB5C:
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sym_0600DB64
sym_0600DB64:
    mov.l   .L_0600DBE0, r4
    mov.l @r4, r4
    mov r4, r0
    mov.b @(2, r0), r0
    tst #0x4, r0
    bt      .L_0600DB9A
    mov r4, r3
    add #0x2, r3
    mov.b @r3, r0
    and #0xFB, r0
    or #0x0, r0
    mov.b r0, @r3
    mov.w   DAT_0600dbda, r0
    mov.l @(r0, r4), r2
    add #0x1, r2
    mov.l r2, @(r0, r4)
    mov #0x28, r3
    mov.l   .L_0600DBE4, r2
    mov.l r3, @r2
    mov.l   .L_0600DBE8, r4
    mov.l   .L_0600DBEC, r3
    mov.l @r3, r3
    mov.l @r4, r2
    add r3, r2
    mov.l   .L_0600DBF0, r3
    jmp @r3
    mov.l r2, @r4
.L_0600DB9A:
    rts
    nop

    .global car_update_post
    .type car_update_post, @function
car_update_post:
    mov #0x4, r3

    .global finish_display
    .type finish_display, @function
finish_display:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600DBF4, r14
    mov.l   .L_0600DBF8, r0
    mov.w @r0, r0
    extu.w r0, r0
    and #0x7, r0
    cmp/ge r3, r0
    bt      .L_0600DC24
    mov.l   .L_0600DBFC, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0600DC08
    mov.l   .L_0600DC00, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_0600dbdc, r3
    mov.w   .L_0600DBDE, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0600DC04, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_0600DC28
    nop

    .global DAT_0600dbda
DAT_0600dbda:
    .2byte  0x015C                      /* car struct offset: lap counter */

    .global DAT_0600dbdc
DAT_0600dbdc:
    .2byte  0x4000                      /* VDP Y offset for overlay */
.L_0600DBDE:
    .2byte  0x0AC0                      /* screen position Y (course 1) */
.L_0600DBE0:
    .4byte  sym_0607E940                /* -> car object pointer */
.L_0600DBE4:
    .4byte  sym_0607EABC                /* -> lap display timer (frames) */
.L_0600DBE8:
    .4byte  sym_0607EAAC                /* -> accumulated race time */
.L_0600DBEC:
    .4byte  sym_0607EAA0                /* -> current lap time delta */
.L_0600DBF0:
    .4byte  sound_notify_handler        /* -> lap complete sound handler */
.L_0600DBF4:
    .4byte  sym_060786A8                /* -> animation frame counter */
.L_0600DBF8:
    .4byte  sym_06078698                /* -> proximity counter (word) */
.L_0600DBFC:
    .4byte  sym_06078644                /* -> course type selector */
.L_0600DC00:
    .4byte  sym_060637F8                /* -> overlay sprite data (course 1) */
.L_0600DC04:
    .4byte  sym_06028400                /* -> overlay rendering function */
.L_0600DC08:
    mov.l   .L_0600DCA0, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_0600dc98, r3
    mov.w   DAT_0600dc9a, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0600DCA4, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_0600DC28
    nop
.L_0600DC24:
    bsr     checkpoint_sound_trigger
    nop
.L_0600DC28:
    mov.l   .L_0600DCA8, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst #0x3F, r0
    bf      .L_0600DC6A
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov r3, r2
    mov.l   .L_0600DCAC, r13
    mov #0x7, r3
    cmp/hs r3, r2
    bt      .L_0600DC4C
    mov.l   .L_0600DCB0, r5
    jsr @r13
    mov #0x0, r4
    bra     .L_0600DC6A
    nop
.L_0600DC4C:
    mov.l   .L_0600DCB4, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0600DC5A
    mov.l   .L_0600DCB8, r5
    bra     .L_0600DC5C
    nop
.L_0600DC5A:
    mov.l   .L_0600DCB0, r5
.L_0600DC5C:
    jsr @r13
    mov #0x0, r4
    mov #0x28, r2
    mov.l   .L_0600DCBC, r3
    mov.w r2, @r3
    mov #0x0, r2
    mov.l r2, @r14
.L_0600DC6A:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global checkpoint_sound_trigger
    .type checkpoint_sound_trigger, @function
checkpoint_sound_trigger:
    sts.l pr, @-r15
    mov #0x60, r6
    add #-0x4, r15
    mov.l   .L_0600DCC0, r3
    mov.l r3, @r15
    mov r3, r7
    mov.w   DAT_0600dc9c, r5
    mov.l   .L_0600DCC4, r3
    jsr @r3
    mov #0x8, r4
    mov.l @r15, r7
    mov #0x60, r6
    mov.w   DAT_0600dc9e, r5
    mov #0x8, r4
    add #0x4, r15
    mov.l   .L_0600DCC4, r3
    jmp @r3
    lds.l @r15+, pr

    .global DAT_0600dc98
DAT_0600dc98:
    .2byte  0x4000                      /* VDP Y offset (other courses) */

    .global DAT_0600dc9a
DAT_0600dc9a:
    .2byte  0x0B3C                      /* screen position Y (other courses) */

    .global DAT_0600dc9c
DAT_0600dc9c:
    .2byte  0x0ABC                      /* checkpoint sound screen position 1 */

    .global DAT_0600dc9e
DAT_0600dc9e:
    .2byte  0x0BBC                      /* checkpoint sound screen position 2 */
.L_0600DCA0:
    .4byte  sym_06063808                /* -> overlay sprite data (other courses) */
.L_0600DCA4:
    .4byte  sym_06028400                /* -> overlay rendering function */
.L_0600DCA8:
    .4byte  sym_06078698                /* -> proximity counter (word) */
.L_0600DCAC:
    .4byte  sound_cmd_dispatch          /* -> sound command dispatcher */
.L_0600DCB0:
    .4byte  0xAE1138FF                  /* standard lap/countdown SFX data */
.L_0600DCB4:
    .4byte  sym_06078644                /* -> course type selector */
.L_0600DCB8:
    .4byte  0xAE1139FF                  /* course 1 specific SFX variant */
.L_0600DCBC:
    .4byte  sym_06086054                /* -> sound/display timer */
.L_0600DCC0:
    .4byte  sym_0605ACE8                /* -> checkpoint SFX data block */
.L_0600DCC4:
    .4byte  sym_060284AE                /* -> VDP number+text renderer */
