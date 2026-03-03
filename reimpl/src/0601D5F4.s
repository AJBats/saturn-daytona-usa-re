	.text
    .global sound_cmd_dispatch
sound_cmd_dispatch:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601D670, r0
    mov.l @r0, r0
    tst r0, r0
    bf.s    .L_0601D6AC
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
    .long  sym_06086050
.L_0601D674:
    .long  0xA0000000
.L_0601D678:
    .long  0x25A02C20
.L_0601D67C:
    .long  sym_0608604C                    /* last-command mirror */
.L_0601D680:
    .long  0xA07000FF
.L_0601D684:
    .long  0xA17000FF
.L_0601D688:
    .long  0xA27000FF
.L_0601D68C:
    .long  0xA37000FF
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
    .long  0x25A02C20
.L_0601D6D0:
    .long  sym_0608604C

    .global sound_channel_a
sound_channel_a:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_channel_a_body
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
sound_channel_b:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_channel_b_body
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
    .long  sym_0605DF94                    /* chan A last-command cache */
.L_0601D720:
    .long  sym_0608604C
.L_0601D724:
    .long  0x25A02C20
.L_0601D728:
    .long  sym_0605DF98                    /* chan B last-command cache */

    .global sound_channel_c
sound_channel_c:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_channel_c_handler
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
    .short  0xFFFF
.L_0601D76C:
    .long  sym_0605DF9C                    /* chan C last-command cache */
.L_0601D770:
    .long  sym_0608604C
.L_0601D774:
    .long  0x25A02C20

    .global sound_pass_direct
sound_pass_direct:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_direct_pass
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
sound_channel_d:
    mov.l r14, @-r15
    mov r4, r14

    .global snd_channel_d_handler
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
    .long  sym_0605DFA4                    /* direct pass last-command cache */
.L_0601D7C4:
    .long  sym_0608604C
.L_0601D7C8:
    .long  0x25A02C20
.L_0601D7CC:
    .long  sym_0605DFA8                    /* chan D last-command cache */

    .global sound_notify_handler
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
    bt.s    .L_0601D852
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
    .short  0x021C
    .short  0xFFFF
.L_0601D888:
    .long  sym_06086054
.L_0601D88C:
    .long  sym_0607EAD8
.L_0601D890:
    .long  sym_06087060
.L_0601D894:
    .long  sym_06086058
.L_0601D898:
    .long  sym_0607E944
.L_0601D89C:
    .long  sym_0604A50C
.L_0601D8A0:
    .long  sym_0605AD00
.L_0601D8A4:
    .long  sym_06085FF4
.L_0601D8A8:
    .long  sym_06063F28
.L_0601D8AC:
    .long  sym_06086034
.L_0601D8B0:
    .long  0xAE1121FF
.L_0601D8B4:
    .long  0xAE1146FF
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
    .short  0x021C

    .global DAT_0601d976
DAT_0601d976:
    .short  0x04B0
.L_0601D978:
    .long  sym_0605AD00
.L_0601D97C:
    .long  sym_06086056
.L_0601D980:
    .long  0xAE1126FF
.L_0601D984:
    .long  sym_06063F28
.L_0601D988:
    .long  sym_06086034
.L_0601D98C:
    .long  0xAE1121FF
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
    bt.s    .L_0601D9CC
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
    bf.s    .L_0601DAB6
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
    .short  0x04B0
    .short  0xFFFF
.L_0601DA40:
    .long  0xAE1127FF
.L_0601DA44:
    .long  sym_06086054
.L_0601DA48:
    .long  sym_06085FF4
.L_0601DA4C:
    .long  sym_06086056
.L_0601DA50:
    .long  sym_0608605A
.L_0601DA54:
    .long  sym_0607EAD8
.L_0601DA58:
    .long  sym_06086058
.L_0601DA5C:
    .long  0xAE112BFF
.L_0601DA60:
    .long  0xAE1129FF
.L_0601DA64:
    .long  0xAE112AFF
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
    .short  0xFFFF
.L_0601DB64:
    .long  sym_06086056
.L_0601DB68:
    .long  0xAE112CFF
.L_0601DB6C:
    .long  0xAE112DFF
.L_0601DB70:
    .long  0xAE112FFF
.L_0601DB74:
    .long  sym_0608605A
.L_0601DB78:
    .long  0xAE1120FF
    .long  0x000B0009
    .long  0x000B0009
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
    .short  0xFFFF
.L_0601DBA0:
    .long  sym_06086050
.L_0601DBA4:
    .long  0x25A02C20
.L_0601DBA8:
    .long  0x000186A0
    .long  0xE300D201
    .long  0x000B2230
    .long  0x25A02D97
