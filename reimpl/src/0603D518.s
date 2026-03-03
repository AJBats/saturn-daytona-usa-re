	.text
    .global name_entry_render
name_entry_render:
    sts.l pr, @-r15
    mov r6, r0
    mov.l   .L_0603D5C0, r7
    mov.l   .L_pool_0603D5C4, r5
    mov.l   .L_pool_0603D5C8, r4
    mov.w   .L_0603D5BC, r1
    mov.l   .L_pool_0603D5CC, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r7, r2
    mov.w r2, @r4
    mov.w   DAT_0603d5be, r14
    mov.w   .L_0603D5BC, r1
    mov.l   .L_pool_0603D5CC, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r14, r2
    mov.w r2, @r4
    mov.w   .L_0603D5BC, r1
    mov.l   .L_pool_0603D5CC, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_0603D5BC, r1
    mov.l   .L_pool_0603D5CC, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_0603D5BC, r1
    mov.l   .L_pool_0603D5CC, r3
    jsr @r3
    mov r5, r2
    mov #0x0, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_0603D5BC, r1
    mov.l   .L_pool_0603D5CC, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_0603D5BC, r1
    mov.l   .L_pool_0603D5CC, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_0603D5BC, r1
    mov.l   .L_pool_0603D5CC, r3
    jsr @r3
    mov r5, r2
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0603D5BC:
    .short  0x0401


    .global DAT_0603d5be
DAT_0603d5be:
    .short  0x00FF
.L_0603D5C0:
    .long  0x0000FF00
.L_pool_0603D5C4:
    .long  sym_060A4D58
.L_pool_0603D5C8:
    .long  sym_060A4D3E
.L_pool_0603D5CC:
    .long  sym_06034F78
