
    .section .text.FUN_060193FE


    .global course_select_state
    .type course_select_state, @function
course_select_state:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD2, 0x2B    /* mov.l .L_060194B0, r2 */
    mov.b r3, @r2
    extu.b r4, r3
    .byte   0xD2, 0x2A    /* mov.l .L_060194B4, r2 */
    mov.b r4, @r2
    .byte   0xD2, 0x2A    /* mov.l .L_060194B8, r2 */
    mov.b r0, @r2
    extu.b r4, r0
    .byte   0xD2, 0x2A    /* mov.l .L_060194BC, r2 */
    extu.b r4, r4
    mov.b r0, @r2
    .byte   0xD2, 0x29    /* mov.l .L_060194C0, r2 */
    mov.b r3, @r2
    .byte   0xD2, 0x29    /* mov.l .L_060194C4, r2 */
    mov.b r4, @r2
    .byte   0xD5, 0x29    /* mov.l .L_060194C8, r5 */
    .byte   0xD2, 0x2A    /* mov.l .L_060194CC, r2 */
    jsr @r2
    mov #0xF, r4
    .byte   0xDE, 0x29    /* mov.l .L_060194D0, r14 */
    .byte   0xD3, 0x2A    /* mov.l .L_060194D4, r3 */
    mov.l @r14, r2
    or r3, r2
    .byte   0xD3, 0x29    /* mov.l .L_060194D8, r3 */
    jsr @r3
    mov.l r2, @r14
    .byte   0xD3, 0x28    /* mov.l .L_060194D8, r3 */
    jsr @r3
    nop
    .byte   0xBF, 0xA6    /* bsr 0x0601938C (external helper) */
    nop
    .byte   0xD3, 0x26    /* mov.l .L_060194DC, r3 */
    jsr @r3
    nop
    mov #0x9, r7
    .byte   0xD5, 0x25    /* mov.l .L_060194E0, r5 */
    .byte   0xD4, 0x26    /* mov.l .L_060194E4, r4 */
    .byte   0xD3, 0x26    /* mov.l .L_060194E8, r3 */
    jsr @r3
    mov #0x0, r6
    mov #0x8, r7
    .byte   0xD5, 0x25    /* mov.l .L_060194EC, r5 */
    .byte   0xD4, 0x26    /* mov.l .L_060194F0, r4 */
    .byte   0xD3, 0x23    /* mov.l .L_060194E8, r3 */
    jsr @r3
    mov #0x0, r6
    mov #0x0, r6
    .byte   0xDD, 0x24    /* mov.l .L_060194F4, r13 */
    mov r6, r5
    jsr @r13
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r13
    mov #0x10, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r13
    mov #0x20, r4
    .byte   0xD3, 0x1F    /* mov.l .L_060194F8, r3 */
    jsr @r3
    mov #0x4, r4
    .byte   0xD3, 0x1E    /* mov.l .L_060194F8, r3 */
    jsr @r3
    mov #0xC, r4
    mov.l @r14, r0
    .byte   0xD3, 0x1D    /* mov.l .L_060194FC, r3 */
    or #0x4, r0
    jsr @r3
    mov.l r0, @r14
    mov #0x0, r6
    .byte   0xD2, 0x1B    /* mov.l .L_06019500, r2 */
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    .byte   0xD3, 0x1A    /* mov.l .L_06019504, r3 */
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    .byte   0xD3, 0x19    /* mov.l .L_06019508, r3 */
    jsr @r3
    mov #0x4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xAF, 0x3A    /* bra 0x06019324 (external tail-call) */
    mov.l @r15+, r14
.L_060194B0:
    .4byte  sym_06085FF0
.L_060194B4:
    .4byte  sym_0605D245
.L_060194B8:
    .4byte  sym_06085FF1
.L_060194BC:
    .4byte  sym_06085FF2
.L_060194C0:
    .4byte  sym_06085FF3
.L_060194C4:
    .4byte  sym_06085FF5
.L_060194C8:
    .4byte  0xAE0003FF
.L_060194CC:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_060194D0:
    .4byte  sym_0605B6D8
.L_060194D4:
    .4byte  0x80000000
.L_060194D8:
    .4byte  sym_06026CE0
.L_060194DC:
    .4byte  sym_0601A73E
.L_060194E0:
    .4byte  0x00014000
.L_060194E4:
    .4byte  0x25E76174
.L_060194E8:
    .4byte  sym_0600511E
.L_060194EC:
    .4byte  0x00017700
.L_060194F0:
    .4byte  0x25E761FC
.L_060194F4:
    .4byte  display_channel_b
.L_060194F8:
    .4byte  sym_0602853E
.L_060194FC:
    .4byte  sym_06028560
.L_06019500:
    .4byte  sym_06063AF8
.L_06019504:
    .4byte  0x0000A000
.L_06019508:
    .4byte  sym_06028400
