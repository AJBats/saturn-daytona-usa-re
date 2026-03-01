
    .section .text.FUN_06020BCE


    .global obj_state_pack
    .type obj_state_pack, @function

obj_state_pack:
    sts.l pr, @-r15
    .byte   0xD3, 0x16    /* mov.l .L_06020C2C, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xD5, 0x16    /* mov.l .L_06020C30, r5 */
    .byte   0xD3, 0x16    /* mov.l .L_06020C34, r3 */
    jsr @r3
    mov r5, r4
    .byte   0xD3, 0x16    /* mov.l .L_06020C38, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x08    /* mov.l .L_06020C08, r4 */
    .byte   0xD2, 0x09    /* mov.l .L_06020C0C, r2 */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov #0x2, r2
    .byte   0xD3, 0x07    /* mov.l .L_06020C10, r3 */
    mov.w r2, @r3
    mov #0x0, r2
    .byte   0xD3, 0x07    /* mov.l .L_06020C14, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x07    /* mov.l .L_06020C18, r3 */
    jmp @r3
    lds.l @r15+, pr

    .4byte  sym_0607EBF4                     /* display/mode flags (32-bit) */
    .4byte  sym_0602853E                     /* display channel configure */
.L_06020C08:
    .4byte  sym_0605B6D8                     /* render mode flags (32-bit bitmask) */
.L_06020C0C:
    .4byte  0x04000000                       /* bit 26 flag constant */
.L_06020C10:
    .4byte  sym_0608780C                     /* display_timer (16-bit word; 2 = active) */
.L_06020C14:
    .4byte  sym_0605A00C                     /* input skip flag (nonzero = skip input) */
.L_06020C18:
    .4byte  sym_06026CE0                     /* display_update (tail-call target) */
    .4byte  sym_06059F6F                     /* (shared pool data) */
    .4byte  sym_06085F8A                     /* object compaction needed flag (byte) */
    .4byte  sym_0607EBCC                     /* countdown timer (attract mode) */
    .4byte  sym_06063F5C                     /* car struct array base pointer */
.L_06020C2C:
    .4byte  sym_0603850C                     /* command_slot_write */
.L_06020C30:
    .4byte  0x00010000                       /* 1.0 (16.16 fixed-point) */
.L_06020C34:
    .4byte  scene_color_intensity            /* scene color intensity function */
.L_06020C38:
    .4byte  sym_06038520                     /* command_queue_commit */
