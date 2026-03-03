	.text
    .global hud_render_stage
hud_render_stage:
    mov.l r14, @-r15
    mov r4, r0
    mov.l r13, @-r15
    mov #0x1, r14
    mov.l r12, @-r15
    mov r5, r12
