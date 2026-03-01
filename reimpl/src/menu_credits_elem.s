
    .section .text.FUN_0603B680


    .global menu_credits_elem
    .type menu_credits_elem, @function
menu_credits_elem:
    sts.l pr, @-r15
    mov r4, r1
    mov.l   .L_0603B6A0, r2
    mov.w   .L_0603B69A, r3
    mov.l @r2, r2
    add r3, r2
    mov.l   .L_0603B6A4, r3
    jsr @r3
    mov #0xC, r0
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x00A8
.L_0603B69A:
    .2byte  0x00B8                      /* [HIGH] offset into state struct for credits element slot */
    .4byte  timer_stub                  /* [HIGH] shared pool: timer_stub address (used by menu_timer_clock) */
.L_0603B6A0:
    .4byte  sym_060A4D14               /* [HIGH] global UI/command state pointer — dereferenced to get struct base */
.L_0603B6A4:
    .4byte  sym_06035168               /* [HIGH] memcpy_long — unrolled longword copy (r0=nbytes, r1=dst, r2=src) */
