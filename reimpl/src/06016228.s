	.text
    .global hud_results_stub_a
hud_results_stub_a:
    mov.l r14, @-r15
    extu.b r4, r14
    mov.l r13, @-r15
    mov r14, r3
