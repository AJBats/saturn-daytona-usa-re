
    .section .text.FUN_0603660E


    .global track_distance_calc
    .type track_distance_calc, @function
track_distance_calc:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    add #-0x10, r15
    mov r15, r4
    .byte   0xD3, 0x0A    /* mov.l .L_pool_06036646, r3 */
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x53, r3
    mov r15, r5
    mov r15, r4
    add #0x8, r2
    mov.b r3, @r2
    .byte   0xB0, 0x11    /* bsr 0x06036650 (external) */
    add #0x8, r4
    mov r0, r4
    mov r15, r2
    mov r4, r0
    mov.l @r2, r3
    .byte   0xD2, 0x05    /* mov.l .L_0603664C, r2 */
    and r2, r3
    mov.l r3, @r14
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_06036646:
    .4byte  input_proc_analog
    .4byte  input_proc_buttons
.L_0603664C:
    .4byte  0x00FFFFFF
