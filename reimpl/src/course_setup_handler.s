
    .section .text.FUN_0601B074


    .global course_setup_handler
    .type course_setup_handler, @function
course_setup_handler:
    sts.l pr, @-r15
    mov #0x0, r7
    mov #0x30, r6
    mov.w   .L_const_color_offset, r3
    mov r6, r5
    mov.l r3, @-r15
    mov.w   .L_const_color_component, r2
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l   .L_fn_color_transform, r3
    jsr @r3
    mov r7, r4
    add #0x10, r15
    lds.l @r15+, pr
    rts
    nop

    .global loc_0601B096
loc_0601B096:
    rts
    nop
    .2byte  0x644E
    .4byte  0x655E7FFC
    .4byte  0x63432F60
    .4byte  0x44004308
    .4byte  0x343C4500
    .4byte  0x345CD208
    .4byte  0x6220622C
    .4byte  0x342C4408
    .4byte  0xD306343C
    .4byte  0x6442E606
    .4byte  0x65F0A583
    .2byte  0x7F04
.L_const_color_offset:
    .2byte  0x0100                          /* [HIGH] color intensity / offset value (256) */
.L_const_color_component:
    .2byte  0x0160                          /* [HIGH] color component value (352) */
    .2byte  0xFFFF                          /* alignment padding */
.L_fn_color_transform:
    .4byte  color_transform_calc            /* [HIGH] VDP2 color transform calculator */
    .4byte  sym_0605D4F7                    /* (cross-TU pool for course_state_setup) replay/attract state byte */
    .4byte  sym_0605DD6C                    /* (cross-TU pool for course_state_setup) course data pointer table */
