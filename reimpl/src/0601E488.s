	.text
    .global hud_text_handler
hud_text_handler:
    mov.l r14, @-r15
    mov #0x0, r5
