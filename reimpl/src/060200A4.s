	.text
    .global race_start_obj_init
race_start_obj_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_06020150, r5
    mov.l   .L_06020154, r4
    mov.l   .L_06020158, r3
    jsr @r3
    mov #0x20, r6
    mov.l   .L_0602015C, r5
    mov.l   .L_06020160, r4
    mov.l   .L_06020158, r3
    jsr @r3
    mov #0x20, r6
    mov #0x8, r7
    mov.l   .L_06020168, r5
    mov.l   .L_06020164, r14
    mov.l   .L_0602016C, r4
    jsr @r14
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_06020170, r5
    mov.l   .L_06020174, r4
    jsr @r14
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_06020178, r5
    mov.l   .L_0602017C, r4
    jsr @r14
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_06020180, r5
    mov.l   .L_06020184, r4
    jsr @r14
    mov #0x0, r6
    mov.l   .L_06020188, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_0602014a, r3
    mov.w   DAT_0602014c, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0602018C, r3
    jsr @r3
    mov #0xC, r4
    mov #0x0, r6
    mov.l   .L_06020190, r3
    mov r6, r5
    jsr @r3
    mov #0x20, r4
    mov #0x0, r6
    mov.l   .L_06020190, r3
    mov r6, r5
    jsr @r3
    mov #0x8, r4
    .byte   0xB6, 0x5C    /* bsr 0x06020DD0 (external) */
    nop
    mov #0x0, r2
    mov.l   .L_06020194, r3
    mov.w r2, @r3
    mov.l   .L_06020198, r3
    mov.w r2, @r3
    mov.l   .L_0602019C, r3
    mov.l r2, @r3
    mov.l   .L_060201A0, r3
    mov.w r2, @r3
    mov.l   .L_060201A4, r5
    mov.l   .L_060201A8, r3
    jsr @r3
    mov r2, r4
    mov #0x0, r2
    mov.l   .L_060201AC, r3
    mov.b r2, @r3
    mov.l   .L_060201B0, r3
    mov.b r2, @r3
    mov #0xF, r2
    mov.l   .L_060201B4, r3
    mov.b r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0602014a
DAT_0602014a:
    .short  0x6000

    .global DAT_0602014c
DAT_0602014c:
    .short  0x0A02
    .short  0xFFFF
.L_06020150:
    .long  sym_0604896C
.L_06020154:
    .long  0x25F006C0
.L_06020158:
    .long  memcpy_word_idx
.L_0602015C:
    .long  sym_0604BC14
.L_06020160:
    .long  0x25F00060
.L_06020164:
    .long  sym_0600511E
.L_06020168:
    .long  0x00017700
.L_0602016C:
    .long  0x25E33AD8
.L_06020170:
    .long  0x00018B40
.L_06020174:
    .long  0x25E33764
.L_06020178:
    .long  0x0001D2A0
.L_0602017C:
    .long  sym_0605E164
.L_06020180:
    .long  0x00018F20
.L_06020184:
    .long  0x25E3398C
.L_06020188:
    .long  sym_06063CA0
.L_0602018C:
    .long  sym_06028400
.L_06020190:
    .long  display_channel_b
.L_06020194:
    .long  sym_0608780A
.L_06020198:
    .long  sym_06087808
.L_0602019C:
    .long  sym_06087814
.L_060201A0:
    .long  sym_06087806
.L_060201A4:
    .long  0xAB1128FF
.L_060201A8:
    .long  sound_cmd_dispatch         /* sound command dispatch */
.L_060201AC:
    .long  sym_06087826
.L_060201B0:
    .long  sym_06087824
.L_060201B4:
    .long  sym_06087825
