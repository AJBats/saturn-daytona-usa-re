
    .section .text.FUN_0600A5B2


    .global camera_param_load
    .type camera_param_load, @function
camera_param_load:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    add #-0x4, r15
    shll2 r14
    mov.l r4, @r15
    .byte   0xD5, 0x0E    /* mov.l .L_pool_0600A5FF, r5 */
    .byte   0xD4, 0x0E    /* mov.l .L_pool_0600A603, r4 */
    .byte   0xD3, 0x0F    /* mov.l .L_pool_0600A607, r3 */
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xD6, 0x0D    /* mov.l .L_pool_0600A60B, r6 */
    add r14, r6
    mov.l @r6, r6
    .byte   0xD5, 0x0C    /* mov.l .L_pool_0600A60F, r5 */
    mov.w @r5, r5
    .byte   0xD4, 0x0C    /* mov.l .L_pool_0600A613, r4 */
    add r14, r4
    mov.l @r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x0B    /* mov.l .L_pool_0600A617, r3 */
    jmp @r3
    mov.l @r15+, r14
    .4byte  sym_060634A4
    .4byte  sym_06063450
    .4byte  sym_060634C0
    .4byte  sym_0606346C
.L_pool_0600A5FF:
    .4byte  sym_06063538
.L_pool_0600A603:
    .4byte  sym_06063520
.L_pool_0600A607:
    .4byte  sym_06031D8C
.L_pool_0600A60B:
    .4byte  sym_0606352C
.L_pool_0600A60F:
    .4byte  sym_06089E98
.L_pool_0600A613:
    .4byte  sym_06063514
.L_pool_0600A617:
    .4byte  sym_06031A28
