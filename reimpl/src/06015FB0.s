	.text
    .global results_init_stub
results_init_stub:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    extu.b r14, r4
    mov.l r12, @-r15
    mov r4, r3
    mov.l r11, @-r15
    shll2 r4
    shll2 r3
