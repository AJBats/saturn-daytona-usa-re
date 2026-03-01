
    .section .text.FUN_0601D5F4


    .global sound_cmd_dispatch
    .type sound_cmd_dispatch, @function
sound_cmd_dispatch:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601D670, r0
    mov.l @r0, r0
    tst r0, r0
    bf/s    .L_0601D6AC
    mov r5, r14
    mov.l   .L_0601D674, r5
    bra     .L_0601D690
    mov r4, r0
.L_0601D608:
    mov r14, r2
    and r5, r2
    cmp/eq r5, r2
    bf      .L_0601D6AC
    bsr     .L_0601DB84
    nop
    mov.l   .L_0601D678, r3
    mov.l r14, @r3
    mov.l   .L_0601D67C, r3
    mov.l r14, @r3
    bra     .L_0601D6AC
    nop
.L_0601D620:
    shll8 r14
    mov.l   .L_0601D680, r4
    add r14, r4
    lds.l @r15+, pr
    bra     sound_channel_a
    mov.l @r15+, r14
.L_0601D62C:
    shll8 r14
    mov.l   .L_0601D684, r4
    add r14, r4
    lds.l @r15+, pr
    bra     sound_channel_b
    mov.l @r15+, r14
.L_0601D638:
    shll8 r14
    mov.l   .L_0601D688, r4
    add r14, r4
    lds.l @r15+, pr
    bra     sound_channel_c
    mov.l @r15+, r14
.L_0601D644:
    mov r14, r4
    lds.l @r15+, pr
    bra     sound_pass_direct
    mov.l @r15+, r14
.L_0601D64C:
    shll8 r14
    mov.l   .L_0601D68C, r4
    add r14, r4
    lds.l @r15+, pr
    bra     sound_channel_d
    mov.l @r15+, r14
.L_0601D658:
    mov r14, r2
    and r5, r2
    cmp/eq r5, r2
    bf      .L_0601D6AC
    bsr     .L_0601DB84
    nop
    mov.l   .L_0601D678, r3
    mov.l r14, @r3
    mov.l   .L_0601D67C, r3
    mov.l r14, @r3
    bra     .L_0601D6AC
    nop
.L_0601D670:
    .4byte  sym_06086050                    /* busy flag: nonzero = sound driver busy */
.L_0601D674:
    .4byte  0xA0000000                      /* top-nibble validation mask */
.L_0601D678:
    .4byte  0x25A02C20                  /* Sound RAM +0x02C20 */
.L_0601D67C:
    .4byte  sym_0608604C                    /* last-command mirror */
.L_0601D680:
    .4byte  0xA07000FF                      /* chan A base: A0=chanA, 70=cmd, 00FF=param */
.L_0601D684:
    .4byte  0xA17000FF                      /* chan B base */
.L_0601D688:
    .4byte  0xA27000FF                      /* chan C base */
.L_0601D68C:
    .4byte  0xA37000FF                      /* chan D base */
.L_0601D690:
    cmp/eq #0x0, r0
    bt      .L_0601D608
    cmp/eq #0x1, r0
    bt      .L_0601D620
    cmp/eq #0x2, r0
    bt      .L_0601D62C
    cmp/eq #0x3, r0
    bt      .L_0601D638
    cmp/eq #0x4, r0
    bt      .L_0601D644
    cmp/eq #0x5, r0
    bt      .L_0601D64C
    cmp/eq #0xF, r0
    bt      .L_0601D658
.L_0601D6AC:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sound_write_direct
    .type sound_write_direct, @function
sound_write_direct:
    sts.l pr, @-r15
    add #-0x4, r15
    bsr     .L_0601DB84
    mov.l r4, @r15
    mov.l @r15, r2
    mov.l   .L_0601D6CC, r3
    mov.l r2, @r3
    mov.l @r15, r2
    mov.l   .L_0601D6D0, r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
.L_0601D6CC:
    .4byte  0x25A02C20                  /* Sound RAM +0x02C20 */
.L_0601D6D0:
    .4byte  sym_0608604C

    .global sound_channel_a
    .type sound_channel_a, @function
sound_channel_a:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_channel_a_body
    .type snd_channel_a_body, @function
snd_channel_a_body:
    sts.l pr, @-r15
    mov.l   .L_0601D71C, r3
    mov.l @r3, r3
    cmp/eq r14, r3
    bt      .L_0601D6F2
    bsr     .L_0601DB84
    nop
    mov.l   .L_0601D71C, r3
    mov.l r14, @r3
    mov.l   .L_0601D720, r3
    mov.l r14, @r3
    mov.l   .L_0601D724, r3
    mov.l r14, @r3
.L_0601D6F2:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sound_channel_b
    .type sound_channel_b, @function
sound_channel_b:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_channel_b_body
    .type snd_channel_b_body, @function
snd_channel_b_body:
    sts.l pr, @-r15
    mov.l   .L_0601D728, r3
    mov.l @r3, r3
    cmp/eq r14, r3
    bt      .L_0601D716
    bsr     .L_0601DB84
    nop
    mov.l   .L_0601D728, r3
    mov.l r14, @r3
    mov.l   .L_0601D720, r3
    mov.l r14, @r3
    mov.l   .L_0601D724, r3
    mov.l r14, @r3
.L_0601D716:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601D71C:
    .4byte  sym_0605DF94                    /* chan A last-command cache */
.L_0601D720:
    .4byte  sym_0608604C                    /* cmd mirror (shared A/B) */
.L_0601D724:
    .4byte  0x25A02C20                      /* Sound RAM mailbox (shared A/B) */
.L_0601D728:
    .4byte  sym_0605DF98                    /* chan B last-command cache */

    .global sound_channel_c
    .type sound_channel_c, @function
sound_channel_c:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_channel_c_handler
    .type snd_channel_c_handler, @function
snd_channel_c_handler:
    sts.l pr, @-r15
    mov.l   .L_0601D76C, r3
    mov.l @r3, r3
    cmp/eq r14, r3
    bt      .L_0601D74A
    bsr     .L_0601DB84
    nop
    mov.l   .L_0601D76C, r3
    mov.l r14, @r3
    mov.l   .L_0601D770, r3
    mov.l r14, @r3
    mov.l   .L_0601D774, r3
    mov.l r14, @r3
.L_0601D74A:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sound_channel_c2
    .type sound_channel_c2, @function
sound_channel_c2:
    sts.l pr, @-r15
    add #-0x4, r15
    bsr     .L_0601DB84
    mov.l r4, @r15
    mov.l @r15, r2
    mov.l   .L_0601D774, r3
    mov.l r2, @r3
    mov.l @r15, r2
    mov.l   .L_0601D770, r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
    .2byte  0xFFFF
.L_0601D76C:
    .4byte  sym_0605DF9C                    /* chan C last-command cache */
.L_0601D770:
    .4byte  sym_0608604C                    /* cmd mirror (chan C) */
.L_0601D774:
    .4byte  0x25A02C20                      /* Sound RAM mailbox (chan C) */

    .global sound_pass_direct
    .type sound_pass_direct, @function
sound_pass_direct:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_direct_pass
    .type snd_direct_pass, @function
snd_direct_pass:
    sts.l pr, @-r15
    mov.l   .L_0601D7C0, r3
    mov.l @r3, r3
    cmp/eq r14, r3
    bt      .L_0601D796
    bsr     .L_0601DB84
    nop
    mov.l   .L_0601D7C0, r3
    mov.l r14, @r3
    mov.l   .L_0601D7C4, r3
    mov.l r14, @r3
    mov.l   .L_0601D7C8, r3
    mov.l r14, @r3
.L_0601D796:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sound_channel_d
    .type sound_channel_d, @function
sound_channel_d:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_channel_d_handler
    .type snd_channel_d_handler, @function
snd_channel_d_handler:
    sts.l pr, @-r15
    mov.l   .L_0601D7CC, r3
    mov.l @r3, r3
    cmp/eq r14, r3
    bt      .L_0601D7BA
    bsr     .L_0601DB84
    nop
    mov.l   .L_0601D7CC, r3
    mov.l r14, @r3
    mov.l   .L_0601D7C4, r3
    mov.l r14, @r3
    mov.l   .L_0601D7C8, r3
    mov.l r14, @r3
.L_0601D7BA:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601D7C0:
    .4byte  sym_0605DFA4                    /* direct pass last-command cache */
.L_0601D7C4:
    .4byte  sym_0608604C                    /* cmd mirror (direct/chan D) */
.L_0601D7C8:
    .4byte  0x25A02C20                      /* Sound RAM mailbox (direct/chan D) */
.L_0601D7CC:
    .4byte  sym_0605DFA8                    /* chan D last-command cache */

    .global sound_notify_handler
    .type sound_notify_handler, @function
sound_notify_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x1, r12
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov #0x50, r8
    mov.l   .L_0601D888, r10
    mov.l   .L_0601D88C, r11
    mov.l   .L_0601D890, r13
    mov.l   .L_0601D894, r14
    mov.l   .L_0601D898, r4
    mov.l @r11, r0
    exts.b r0, r0
    mov r0, r3
    shll2 r0
    shll2 r3
    shll r3
    add r3, r0
    exts.b r0, r0
    mov.l   .L_0601D89C, r2
    add r2, r0
    mov.l   .L_0601D8A0, r5
    mov.l @r5, r5
    shll2 r5
    mov.l @(r0, r5), r5
    mov.l   .L_0601D8A4, r0
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_0601D852
    mov.l @r4, r4
    mov.l   .L_0601D8A8, r3
    mov.w   .L_0601D884, r0
    mov.l @r3, r3
    mov.l @(r0, r4), r2
    add #-0x1, r3
    cmp/eq r3, r2
    bf      .L_0601D83C
    mov.l   .L_0601D8AC, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601D83C
    mov.l   .L_0601D8B0, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    extu.w r8, r2
    mov.w r2, @r10
    mov.l   .L_0601D8AC, r3
    mov.l r12, @r3
    bra     .L_0601D99E
    nop
.L_0601D83C:
    mov.l   .L_0601D8B4, r5
    mov #0x0, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     sound_cmd_dispatch
    mov.l @r15+, r14
.L_0601D852:
    mov.l @r11, r0
    tst r0, r0
    bf      .L_0601D8BE
    mov r5, r2
    mov.w   .L_0601D884, r0
    mov.l @(r0, r4), r3
    sub r3, r2
    mov #0x8, r3
    cmp/gt r3, r2
    bt      .L_0601D8BE
    mov.b @r13, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0601D8B8
    mov.l   .L_0601D8A0, r3
    mov #0x0, r2
    mov.l @r3, r3
    cmp/hi r2, r3
    bf      .L_0601D8B8
    extu.b r12, r2
    mov.b r2, @r13
    mov #0x0, r3
    mov.w r3, @r14
    bra     .L_0601D8BE
    nop
.L_0601D884:
    .2byte  0x021C                          /* offset 0x21C into race data = lap count */
    .2byte  0xFFFF
.L_0601D888:
    .4byte  sym_06086054
.L_0601D88C:
    .4byte  sym_0607EAD8
.L_0601D890:
    .4byte  sym_06087060
.L_0601D894:
    .4byte  sym_06086058
.L_0601D898:
    .4byte  sym_0607E944
.L_0601D89C:
    .4byte  sym_0604A50C
.L_0601D8A0:
    .4byte  sym_0605AD00
.L_0601D8A4:
    .4byte  sym_06085FF4
.L_0601D8A8:
    .4byte  sym_06063F28
.L_0601D8AC:
    .4byte  sym_06086034
.L_0601D8B0:
    .4byte  0xAE1121FF                      /* "final lap" jingle */
.L_0601D8B4:
    .4byte  0xAE1146FF                      /* "lap complete" jingle */
.L_0601D8B8:
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
.L_0601D8BE:
    mov.l @r11, r0
    cmp/eq #0x1, r0
    bf      .L_0601D8F0
    mov r5, r3
    mov.w   DAT_0601d974, r0
    mov.l @(r0, r4), r2
    sub r2, r3
    mov #0x4, r2
    cmp/gt r2, r3
    bt      .L_0601D8F0
    mov.b @r13, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_0601D8EA
    mov.l   .L_0601D978, r3
    mov #0x0, r2
    mov.l @r3, r3
    cmp/hi r2, r3
    bf      .L_0601D8EA
    extu.b r12, r2
    bra     .L_0601D8F0
    mov.b r2, @r13
.L_0601D8EA:
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
.L_0601D8F0:
    mov.l @r11, r0
    cmp/eq #0x2, r0
    bf      .L_0601D922
    mov.w   DAT_0601d974, r0
    mov r5, r3
    mov.l @(r0, r4), r2
    sub r2, r3
    mov #0x2, r2
    cmp/gt r2, r3
    bt      .L_0601D922
    mov.b @r13, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_0601D91C
    mov #0x0, r2
    mov.l   .L_0601D978, r3
    mov.l @r3, r3
    cmp/hi r2, r3
    bf      .L_0601D91C
    extu.b r12, r2
    bra     .L_0601D922
    mov.b r2, @r13
.L_0601D91C:
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
.L_0601D922:
    mov #0x0, r2
    mov.l   .L_0601D97C, r9
    mov.w   DAT_0601d974, r0
    cmp/gt r5, r2
    mov.l @(r0, r4), r3
    addc r2, r5
    add #0x1, r3
    shar r5
    cmp/gt r5, r3
    bt      .L_0601D948
    mov.l   .L_0601D980, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    mov.w   DAT_0601d976, r2
    mov.w r2, @r10
    mov #0x14, r3
    mov.w r3, @r9
    bra     .L_0601D99E
    nop
.L_0601D948:
    mov.l   .L_0601D984, r2
    mov.w   DAT_0601d974, r0
    mov.l @r2, r2
    mov.l @(r0, r4), r3
    add #-0x1, r2
    cmp/eq r2, r3
    bf      .L_0601D990
    mov.l   .L_0601D988, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601D990
    mov.l   .L_0601D98C, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    extu.w r8, r2
    mov.w r2, @r9
    extu.w r8, r3
    mov.w r3, @r10
    mov.l   .L_0601D988, r3
    mov.l r12, @r3
    bra     .L_0601D99E
    nop

    .global DAT_0601d974
DAT_0601d974:
    .2byte  0x021C

    .global DAT_0601d976
DAT_0601d976:
    .2byte  0x04B0
.L_0601D978:
    .4byte  sym_0605AD00
.L_0601D97C:
    .4byte  sym_06086056
.L_0601D980:
    .4byte  0xAE1126FF                      /* halfway through race */
.L_0601D984:
    .4byte  sym_06063F28
.L_0601D988:
    .4byte  sym_06086034
.L_0601D98C:
    .4byte  0xAE1121FF                      /* "final lap" jingle (pool dup) */
.L_0601D990:
    mov.l   .L_0601DA40, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    mov.w   .L_0601DA3C, r2
    mov.w r2, @r10
    mov #0x14, r3
    mov.w r3, @r9
.L_0601D99E:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global snd_race_update
    .type snd_race_update, @function
snd_race_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x28, r12
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601DA44, r14
    mov.l   .L_0601DA48, r0
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_0601D9CC
    mov #0x0, r13
    bra     .L_0601DB56
    nop
.L_0601D9CC:
    mov.l   .L_0601DA4C, r2
    mov.w @r2, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_0601D9DA
    bra     .L_0601DB20
    nop
.L_0601D9DA:
    mov.l   .L_0601DA50, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601D9E8
    bra     .L_0601DB20
    nop
.L_0601D9E8:
    mov.l   .L_0601DA4C, r0
    mov.l   .L_0601DA4C, r3
    mov.w @r0, r0
    add #-0x1, r0
    mov.w r0, @r3
    add #0x1, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bt      .L_0601D9FE
    bra     .L_0601DB20
    nop
.L_0601D9FE:
    mov.l   .L_0601DA54, r5
    mov.l   .L_0601DA58, r4
    mov.l   .L_0601DA5C, r11
    mov.l @r5, r0
    tst r0, r0
    bf/s    .L_0601DAB6
    mov #0x64, r6
    mov.w @r4, r0
    bra     .L_0601DA9A
    extu.w r0, r0
.L_0601DA12:
    mov.l   .L_0601DA4C, r3
    mov.w r13, @r3
    mov.l   .L_0601DA60, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    bra     .L_0601DA2A
    nop
.L_0601DA20:
    mov.l   .L_0601DA4C, r3
    mov r11, r5
    mov.w r13, @r3
    bsr     sound_cmd_dispatch
    mov #0x0, r4
.L_0601DA2A:
    bra     .L_0601DA72
    nop
.L_0601DA2E:
    mov.l   .L_0601DA4C, r3
    mov.w r13, @r3
    mov.l   .L_0601DA64, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    bra     .L_0601DA90
    mov #0x14, r2
.L_0601DA3C:
    .2byte  0x04B0
    .2byte  0xFFFF
.L_0601DA40:
    .4byte  0xAE1127FF                      /* default race notify sound */
.L_0601DA44:
    .4byte  sym_06086054
.L_0601DA48:
    .4byte  sym_06085FF4
.L_0601DA4C:
    .4byte  sym_06086056
.L_0601DA50:
    .4byte  sym_0608605A
.L_0601DA54:
    .4byte  sym_0607EAD8
.L_0601DA58:
    .4byte  sym_06086058
.L_0601DA5C:
    .4byte  0xAE112BFF                      /* race loop/repeat music */
.L_0601DA60:
    .4byte  0xAE1129FF                      /* race state 1 sound */
.L_0601DA64:
    .4byte  0xAE112AFF                      /* race state 3 sound */
.L_0601DA68:
    mov.l   .L_0601DB64, r3
    mov r11, r5
    mov.w r13, @r3
    bsr     sound_cmd_dispatch
    mov #0x0, r4
.L_0601DA72:
    bra     .L_0601DA90
    extu.w r12, r2
.L_0601DA76:
    mov.l   .L_0601DB64, r3
    mov.w r13, @r3
    mov.l   .L_0601DB68, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    bra     .L_0601DA90
    mov #0x14, r2
.L_0601DA84:
    mov.l   .L_0601DB64, r3
    mov r11, r5
    mov.w r13, @r3
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    extu.w r12, r2
.L_0601DA90:
    bra     .L_0601DB20
    mov.w r2, @r14
.L_0601DA94:
    extu.w r6, r6
    bra     .L_0601DB20
    mov.w r6, @r14
.L_0601DA9A:
    cmp/eq #0x1, r0
    bt      .L_0601DA12
    cmp/eq #0x2, r0
    bt      .L_0601DA20
    cmp/eq #0x3, r0
    bt      .L_0601DA2E
    cmp/eq #0x4, r0
    bt      .L_0601DA68
    cmp/eq #0x5, r0
    bt      .L_0601DA76
    cmp/eq #0x6, r0
    bt      .L_0601DA84
    bra     .L_0601DA94
    nop
.L_0601DAB6:
    mov.l @r5, r0
    cmp/eq #0x1, r0
    bf      .L_0601DB04
    mov.w @r4, r0
    bra     .L_0601DAF4
    extu.w r0, r0
.L_0601DAC2:
    mov r11, r5
    mov.l   .L_0601DB64, r3
    mov.w r13, @r3
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    bra     .L_0601DAE8
    nop
.L_0601DAD0:
    mov.l   .L_0601DB64, r3
    mov r11, r5
    mov.w r13, @r3
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    bra     .L_0601DAE8
    nop
.L_0601DADE:
    mov.l   .L_0601DB64, r3
    mov.w r13, @r3
    mov.l   .L_0601DB6C, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
.L_0601DAE8:
    extu.w r12, r2
    bra     .L_0601DB20
    mov.w r2, @r14
.L_0601DAEE:
    extu.w r6, r6
    bra     .L_0601DB20
    mov.w r6, @r14
.L_0601DAF4:
    cmp/eq #0x1, r0
    bt      .L_0601DAC2
    cmp/eq #0x3, r0
    bt      .L_0601DAD0
    cmp/eq #0x6, r0
    bt      .L_0601DADE
    bra     .L_0601DAEE
    nop
.L_0601DB04:
    mov.l @r5, r0
    cmp/eq #0x2, r0
    bf      .L_0601DB20
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x8, r0
    bf      .L_0601DB20
    mov.l   .L_0601DB64, r3
    mov.w r13, @r3
    mov.l   .L_0601DB70, r5
    bsr     sound_cmd_dispatch
    mov #0x0, r4
    extu.w r12, r2
    mov.w r2, @r14
.L_0601DB20:
    mov.l   .L_0601DB74, r4
    mov.b @r4, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601DB56
    mov.l   .L_0601DB64, r0
    mov.l   .L_0601DB64, r3
    mov.w @r0, r0
    add #-0x1, r0
    mov.w r0, @r3
    add #0x1, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601DB56
    extu.b r13, r3
    mov.b r3, @r4
    mov.l   .L_0601DB64, r3
    mov.w r13, @r3
    mov.w r12, @r14
    mov.l   .L_0601DB78, r5
    mov #0x0, r4
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     sound_cmd_dispatch
    mov.l @r15+, r14
.L_0601DB56:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0601DB64:
    .4byte  sym_06086056
.L_0601DB68:
    .4byte  0xAE112CFF                      /* race state 5 sound */
.L_0601DB6C:
    .4byte  0xAE112DFF                      /* mode 1, state 6 sound */
.L_0601DB70:
    .4byte  0xAE112FFF                      /* mode 2, state 8 sound */
.L_0601DB74:
    .4byte  sym_0608605A
.L_0601DB78:
    .4byte  0xAE1120FF                      /* fade-out complete sound */
    .4byte  0x000B0009
    .4byte  0x000B0009
.L_0601DB84:
    mov.l   .L_0601DBA0, r7
    mov.l   .L_0601DBA4, r6
    mov #0x1, r5
    mov.l   .L_0601DBA8, r4
.L_0601DB8C:
    dt r4
    bf      .L_0601DB94
    bra     .L_0601DB9A
    mov.l r5, @r7
.L_0601DB94:
    mov.l @r6, r0
    tst r0, r0
    bf      .L_0601DB8C
.L_0601DB9A:
    rts
    nop
    .2byte  0xFFFF
.L_0601DBA0:
    .4byte  sym_06086050                    /* &busy_flag */
.L_0601DBA4:
    .4byte  0x25A02C20                      /* Sound RAM mailbox */
.L_0601DBA8:
    .4byte  0x000186A0                      /* 100,000 = max spin iterations */
    .4byte  0xE300D201
    .4byte  0x000B2230
    .4byte  0x25A02D97
