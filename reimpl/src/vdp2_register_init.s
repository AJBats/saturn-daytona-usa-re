
    .section .text.FUN_06003578


    .global vdp2_register_init
    .type vdp2_register_init, @function
vdp2_register_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_06003638, r10
    mov.l   .L_0600363C, r12
    mov.l   .L_06003640, r13
    mov.w   .L_0600361E, r6
    mov.l   .L_06003644, r5
    mov.l   .L_06003648, r4
    jsr @r12
    mov #0x0, r11
    mov.w   DAT_06003620, r6
    mov.l   .L_0600364C, r5
    mov.l   .L_06003650, r4
    jsr @r13
    nop
    mov #0x8, r4
.L_060035A2:
    add #-0x2, r4
    tst r4, r4
    bf/s    .L_060035A2
    mov.l r11, @r10
    mov.w   DAT_06003622, r6
    mov.l   .L_06003654, r14
    mov.l   .L_06003658, r5
    mov.l   .L_0600365C, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003624, r6
    mov.l   .L_06003660, r5
    mov.l   .L_06003664, r4
    jsr @r13
    add r14, r5
    mov.l   .L_06003668, r6
    mov.l   .L_0600366C, r5
    mov.l   .L_06003670, r4
    jsr @r13
    add r14, r5
    mov.w   .L_06003626, r6
    mov.l   .L_06003674, r5
    mov.l   .L_06003678, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003628, r6
    mov.l   .L_0600367C, r5
    mov.l   .L_06003680, r4
    jsr @r13
    add r14, r5
    mov.w   .L_0600362A, r6
    mov.l   .L_06003684, r5
    mov.l   .L_06003688, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600362c, r6
    mov.l   .L_0600368C, r5
    mov.l   .L_06003690, r4
    jsr @r13
    add r14, r5
    mov.w   .L_0600362E, r6
    mov.l   .L_06003694, r5
    mov.l   .L_06003698, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003630, r6
    mov.l   .L_0600369C, r5
    mov.l   .L_060036A0, r4
    jsr @r13
    add r14, r5
    mov.w   .L_06003632, r6
    mov.l   .L_060036A4, r5
    mov.l   .L_060036A8, r4
    jsr @r13
    add r14, r5
    mov.w   .L_06003634, r6
    mov.l   .L_060036AC, r5
    mov.l   .L_060036B0, r4
    jsr @r13
    add r14, r5
    bra     .L_060036B4
    nop
.L_0600361E:
    .2byte  0x0240

    .global DAT_06003620
DAT_06003620:
    .2byte  0x1000

    .global DAT_06003622
DAT_06003622:
    .2byte  0x61A8

    .global DAT_06003624
DAT_06003624:
    .2byte  0x5808
.L_06003626:
    .2byte  0x07F0

    .global DAT_06003628
DAT_06003628:
    .2byte  0x089C
.L_0600362A:
    .2byte  0x0998

    .global DAT_0600362c
DAT_0600362c:
    .2byte  0x08DC
.L_0600362E:
    .2byte  0x0978

    .global DAT_06003630
DAT_06003630:
    .2byte  0x09C4
.L_06003632:
    .2byte  0x48E8
.L_06003634:
    .2byte  0x43F8
    .2byte  0xFFFF
.L_06003638:
    .4byte  0x25E20000
.L_0600363C:
    .4byte  memcpy_word_idx
.L_06003640:
    .4byte  memcpy_long_idx
.L_06003644:
    .4byte  sym_060481AC
.L_06003648:
    .4byte  0x25F00800
.L_0600364C:
    .4byte  0x002CF108
.L_06003650:
    .4byte  0x25E00000
.L_06003654:
    .4byte  0x002A0000
.L_06003658:
    .4byte  0x00031498
.L_0600365C:
    .4byte  0x25E4363C
.L_06003660:
    .4byte  0x00037640
.L_06003664:
    .4byte  0x25E497E4
.L_06003668:
    .4byte  0x00008094
.L_0600366C:
    .4byte  0x0003CE44
.L_06003670:
    .4byte  0x25E4EFEC
.L_06003674:
    .4byte  0x00044ED8
.L_06003678:
    .4byte  0x25E40000
.L_0600367C:
    .4byte  0x000456C8
.L_06003680:
    .4byte  0x25E407F0
.L_06003684:
    .4byte  0x00045F64
.L_06003688:
    .4byte  0x25E4108C
.L_0600368C:
    .4byte  0x000468FC
.L_06003690:
    .4byte  0x25E41A24
.L_06003694:
    .4byte  0x000471D8
.L_06003698:
    .4byte  0x25E42300
.L_0600369C:
    .4byte  0x00047B50
.L_060036A0:
    .4byte  0x25E42C78
.L_060036A4:
    .4byte  0x0001F370
.L_060036A8:
    .4byte  0x25E61CEC
.L_060036AC:
    .4byte  0x00023C58
.L_060036B0:
    .4byte  0x25E665D4
.L_060036B4:
    mov.w   .L_06003772, r6
    mov.l   .L_06003794, r5
    mov.l   .L_06003798, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003774, r9
    mov.l   .L_0600379C, r5
    mov.l   .L_060037A0, r4
    mov r9, r6
    jsr @r13
    add r14, r5
    mov r9, r6
    mov.l   .L_060037A4, r5
    mov.l   .L_060037A8, r4
    jsr @r13
    add r14, r5
    mov r9, r6
    mov.l   .L_060037AC, r5
    mov.l   .L_060037B0, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003776, r6
    mov.w   DAT_06003778, r5
    mov.l   .L_060037B4, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600377a, r6
    mov.w   DAT_0600377c, r5
    mov.l   .L_060037B8, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600377e, r6
    mov.l   .L_060037BC, r5
    mov.l   .L_060037C0, r4
    jsr @r13
    add r14, r5
    mov.w   .L_06003780, r6
    mov.l   .L_060037C4, r5
    mov.l   .L_060037C8, r4
    jsr @r13
    add r14, r5
    mov r9, r6
    mov.l   .L_060037CC, r5
    mov.l   .L_060037D0, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003782, r6
    mov.l   .L_060037D4, r5
    mov.l   .L_060037D8, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003784, r6
    mov.l   .L_060037DC, r5
    mov.l   .L_060037E0, r4
    jsr @r13
    add r14, r5
    mov.w   .L_06003786, r6
    mov.l   .L_060037E4, r5
    mov.l   .L_060037E8, r4
    jsr @r12
    add r14, r5
    mov.w   .L_06003786, r6
    mov.l   .L_060037EC, r5
    mov.l   .L_060037F0, r4
    jsr @r12
    add r14, r5
    mov.w   .L_06003788, r6
    mov.l   .L_060037F4, r5
    mov.l   .L_060037F8, r4
    jsr @r13
    add r14, r5
    mov.w   .L_0600378A, r6
    mov.l   .L_060037FC, r5
    mov.l   .L_06003800, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600378c, r6
    mov.l   .L_06003804, r5
    mov.l   .L_06003808, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600378e, r6
    mov.l   .L_0600380C, r5
    mov.l   .L_06003810, r4
    jsr @r13
    add r14, r5
    mov.w   .L_06003790, r9
    mov.l   .L_06003814, r5
    mov.l   .L_06003818, r4
    mov r9, r6
    jsr @r12
    add r14, r5
    mov r9, r6
    bra     .L_0600381C
    nop
.L_06003772:
    .2byte  0x4FF8

    .global DAT_06003774
DAT_06003774:
    .2byte  0x09A4

    .global DAT_06003776
DAT_06003776:
    .2byte  0x147C

    .global DAT_06003778
DAT_06003778:
    .2byte  0x0400

    .global DAT_0600377a
DAT_0600377a:
    .2byte  0x1354

    .global DAT_0600377c
DAT_0600377c:
    .2byte  0x187C

    .global DAT_0600377e
DAT_0600377e:
    .2byte  0x1A04
.L_06003780:
    .2byte  0x05C0

    .global DAT_06003782
DAT_06003782:
    .2byte  0x0C34

    .global DAT_06003784
DAT_06003784:
    .2byte  0x02BC
.L_06003786:
    .2byte  0x03F0
.L_06003788:
    .2byte  0x0088
.L_0600378A:
    .2byte  0x0D00

    .global DAT_0600378c
DAT_0600378c:
    .2byte  0x0C1C

    .global DAT_0600378e
DAT_0600378e:
    .2byte  0x3650
.L_06003790:
    .2byte  0x04D4
    .2byte  0xFFFF
.L_06003794:
    .4byte  0x00028050
.L_06003798:
    .4byte  0x25E6A9CC
.L_0600379C:
    .4byte  0x0002D41C
.L_060037A0:
    .4byte  0x25E60000
.L_060037A4:
    .4byte  0x0002DDC0
.L_060037A8:
    .4byte  0x25E609A4
.L_060037AC:
    .4byte  0x0002E764
.L_060037B0:
    .4byte  0x25E61348
.L_060037B4:
    .4byte  0x25E6F9C4
.L_060037B8:
    .4byte  0x25E70E40
.L_060037BC:
    .4byte  0x0000EAB0
.L_060037C0:
    .4byte  0x25E72194
.L_060037C4:
    .4byte  0x00017114
.L_060037C8:
    .4byte  0x25E73B98
.L_060037CC:
    .4byte  0x000176D0
.L_060037D0:
    .4byte  0x25E74158
.L_060037D4:
    .4byte  0x00018074
.L_060037D8:
    .4byte  0x25E74AFC
.L_060037DC:
    .4byte  0x00018B10
.L_060037E0:
    .4byte  0x25E75730
.L_060037E4:
    .4byte  0x00008F84
.L_060037E8:
    .4byte  0x25E759EC
.L_060037EC:
    .4byte  0x00009374
.L_060037F0:
    .4byte  0x25E75DDC
.L_060037F4:
    .4byte  0x00048514
.L_060037F8:
    .4byte  0x25E76174
.L_060037FC:
    .4byte  0x0004859C
.L_06003800:
    .4byte  0x25E761FC
.L_06003804:
    .4byte  0x0004929C
.L_06003808:
    .4byte  0x25E76EFC
.L_0600380C:
    .4byte  0x00049EB8
.L_06003810:
    .4byte  0x25E77B18
.L_06003814:
    .4byte  0x0000AA54
.L_06003818:
    .4byte  sym_060EE300
.L_0600381C:
    mov.l   .L_06003890, r5
    mov.l   .L_06003894, r4
    jsr @r12
    add r14, r5
    mov r9, r6
    mov.l   .L_06003898, r5
    mov.l   .L_0600389C, r4
    jsr @r12
    add r14, r5
    mov r9, r6
    mov.l   .L_060038A0, r5
    .2byte  0xD41C
    .4byte  0x4C0B35EC
    .4byte  0x6693D51B
    .4byte  0xD41B4C0B
    .4byte  0x35EC961F
    .4byte  0xD51AD41B
    .4byte  0x4C0B35EC
    .4byte  0x961BD51A
    .4byte  0xD41A4D0B
    .4byte  0x35EC9617
    .4byte  0xD519D41A
    .4byte  0x4D0B35EC
    .4byte  0x9613D519
    .4byte  0xD4194D0B
    .4byte  0x35EC960F
    .4byte  0x950FD418
    .4byte  0x4D0B35EC
    .4byte  0x4F2669F6
    .4byte  0x6AF66BF6
    .4byte  0x6CF66DF6
    .4byte  0x000B6EF6

    .global DAT_06003884
DAT_06003884:
    .4byte  0x03D40528
    .2byte  0x0228

    .global DAT_0600388a
DAT_0600388a:
    .2byte  0x014C

    .global DAT_0600388c
DAT_0600388c:
    .2byte  0x0834

    .global DAT_0600388e
DAT_0600388e:
    .2byte  0x7EC4
.L_06003890:
    .4byte  0x0000AF28
.L_06003894:
    .4byte  sym_060EE7D4
.L_06003898:
    .4byte  0x0000B3FC
.L_0600389C:
    .4byte  sym_060EECA8
.L_060038A0:
    .4byte  0x0000B8D0
    .4byte  sym_060EF17C
    .4byte  0x0000BDA4
    .4byte  sym_060EF650
    .4byte  0x0002D048
    .4byte  sym_060EFB24
    .4byte  0x00019BC4
    .4byte  0x25E33AD8
    .4byte  0x0001A0EC
    .4byte  0x25E33764
    .4byte  0x0004FEEC
    .4byte  0x25E3398C
    .4byte  0x25E7B168
