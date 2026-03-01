
   .section .text.FUN_06038AC8


   .global display_mode_config
   .type display_mode_config, @function
display_mode_config:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_06038B7C, r14
    mov.l   .L_06038B80, r3
    jsr @r3
    mov #0x0, r13

    mov r14, r0
    mov.b @r0, r0
    tst #0x80, r0
    bt      .L_06038AF2
    mov #0x10, r6
    mov.l   .L_06038B84, r5
    mov.l   .L_06038B88, r4
    .byte   0xBF, 0xB0    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov r14, r2
    mov.l   .L_06038B8C, r3
    jsr @r3
    mov #0x1, r1

.L_06038AF2:
    mov r14, r0
    mov.b @r0, r0
    tst #0x40, r0
    bt      .L_06038B0E
    mov #0x8, r6
    mov.l   .L_06038B90, r5
    mov.l   .L_06038B94, r4
    .byte   0xBF, 0xA2    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov.w   .L_06038B74, r1
    mov.l   .L_06038B8C, r3
    jsr @r3
    mov r14, r2

.L_06038B0E:
    mov r14, r0
    mov.b @r0, r0
    tst #0x20, r0
    bt      .L_06038B2A
    mov #0x6, r6
    mov.l   .L_06038B98, r5
    mov.l   .L_06038B9C, r4
    .byte   0xBF, 0x94    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov.w   .L_06038B76, r1
    mov.l   .L_06038B8C, r3
    jsr @r3
    mov r14, r2

.L_06038B2A:
    mov r14, r0
    mov.b @r0, r0
    tst #0x10, r0
    bt      .L_06038B46
    mov #0x8, r6
    mov.l   .L_06038BA0, r5
    mov.l   .L_06038BA4, r4
    .byte   0xBF, 0x86    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov.w   .L_06038B78, r1
    mov.l   .L_06038B8C, r3
    jsr @r3
    mov r14, r2

.L_06038B46:
    mov r14, r0
    mov.b @r0, r0
    tst #0x8, r0
    bt      .L_06038B62
    mov #0x8, r6
    mov.l   .L_06038BA8, r5
    mov.l   .L_06038BAC, r4
    .byte   0xBF, 0x78    /* bsr 0x06038A48 (data_loader) */
    mov.l @r4, r4
    mov r13, r0
    mov.w   .L_06038B7A, r1
    mov.l   .L_06038B8C, r3
    jsr @r3
    mov r14, r2

.L_06038B62:
    mov r14, r0
    mov.b @r0, r0
    tst #0x4, r0
    bt      .L_06038BC6
    mov #0x10, r6
    mov.l   .L_06038BB0, r5
    mov.l   .L_06038BB4, r4
    bra     .L_06038BB8
    mov.l @r4, r4

.L_06038B74:
    .2byte  0x0101                            /* channel 1 ID */
.L_06038B76:
    .2byte  0x0201                            /* channel 2 ID */
.L_06038B78:
    .2byte  0x0301                            /* channel 3 ID */
.L_06038B7A:
    .2byte  0x0401                            /* channel 4 ID */
.L_06038B7C:
    .4byte  sym_060A4D58               /* display config byte (bitmask) */
.L_06038B80:
    .4byte  hud_display_ext            /* HUD extended display setup */
.L_06038B84:
    .4byte  sym_060A4D18               /* channel 0 source data */
.L_06038B88:
    .4byte  sym_0606360C               /* channel 0 dest pointer */
.L_06038B8C:
    .4byte  sym_06034F78               /* channel data commit */
.L_06038B90:
    .4byte  sym_060A4D28               /* channel 1 source data */
.L_06038B94:
    .4byte  sym_06063610               /* channel 1 dest pointer */
.L_06038B98:
    .4byte  sym_060A4D30               /* channel 2 source data */
.L_06038B9C:
    .4byte  sym_06063614               /* channel 2 dest pointer */
.L_06038BA0:
    .4byte  sym_060A4D36               /* channel 3 source data */
.L_06038BA4:
    .4byte  sym_06063618               /* channel 3 dest pointer */
.L_06038BA8:
    .4byte  sym_060A4D3E               /* channel 4 source data */
.L_06038BAC:
    .4byte  sym_0606361C               /* channel 4 dest pointer */
.L_06038BB0:
    .4byte  sym_060A4D46               /* channel 5 source data */
.L_06038BB4:
    .4byte  sym_06063620               /* channel 5 dest pointer */

.L_06038BB8:
    .byte   0xBF, 0x46    /* bsr 0x06038A48 (data_loader) */
    nop
    mov r13, r0
    mov.w   .L_06038BCE, r1
    mov.l   .L_06038BD0, r3
    jsr @r3
    mov r14, r2

.L_06038BC6:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06038BCE:
    .2byte  0x0501                        /* channel 5 ID */
.L_06038BD0:
    .4byte  sym_06034F78               /* channel data commit (same fn) */
