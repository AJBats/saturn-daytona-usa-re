	.text
    .global hud_nop_stub_a
hud_nop_stub_a:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r13
