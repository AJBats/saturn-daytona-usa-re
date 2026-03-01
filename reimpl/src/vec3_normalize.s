
    .section .text.FUN_06027498


    .global vec3_normalize
    .type vec3_normalize, @function
vec3_normalize:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    bsr     .L_060274DA
    mov r4, r5
    .byte   0xBF, 0xE8    /* bsr 0x06027476 (external: isqrt) */
    mov r0, r4
    cmp/pl r0
    bf      .L_060274D4
    mov.l   .L_060274F8, r4
    .byte   0xB0, 0x56    /* bsr 0x0602755C (external: fpdiv_setup) */
    mov r0, r5
    mov.l @(0, r14), r1
    mov.l @(4, r14), r2
    dmuls.l r0, r1
    mov.l @(8, r14), r3
    sts mach, r4
    sts macl, r1
    xtrct r4, r1
    dmuls.l r0, r2
    mov.l r1, @(0, r14)
    sts mach, r4
    sts macl, r2
    xtrct r4, r2
    dmuls.l r0, r3
    mov.l r2, @(4, r14)
    sts mach, r4
    sts macl, r3
    xtrct r4, r3
    mov.l r3, @(8, r14)
.L_060274D4:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060274DA:
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    rts
    xtrct r1, r0
    .2byte  0x0009
    .4byte  0x002F2F20
    .4byte  0x002F0000
    .4byte  0x00008000
.L_060274F8:
    .4byte  0x00010000
    .4byte  0x40003FFC
    .4byte  0x0FFC4000
    .4byte  0x3FEB3FD6
    .4byte  0x3FBA3F97
    .4byte  0x3F6A3F2F
    .4byte  0x3EFB3EA4
    .4byte  0x3D7403E8
    .4byte  0x001E0028
    .4byte  0x00320046
    .4byte  0x00640096
    .4byte  0x00FA01F4
    .4byte  0x00000AC0
    .4byte  0x00001581
    .4byte  0x000047AE
    .4byte  0x0000B333
    .4byte  0x00018000
    .4byte  0x0002F333
    .4byte  0x00053333
    .4byte  0x0008B333
    .4byte  0x0015B6DB

    .global swap_sign_ext
swap_sign_ext:
    swap.w r4, r0
    rts
    exts.w r0, r0
