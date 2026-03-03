	.text
    .global hud_results_stub_b
hud_results_stub_b:
    mov.l r14, @-r15
    mov #0x40, r0
    mov.l r13, @-r15
    mov r4, r13
