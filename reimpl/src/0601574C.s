	.text
    .global hud_minimap_stub
hud_minimap_stub:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    extu.b r14, r4
