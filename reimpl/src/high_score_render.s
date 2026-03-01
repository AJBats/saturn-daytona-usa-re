
    .section .text.FUN_0603D2D0


    .global high_score_render
    .type high_score_render, @function
high_score_render:
    sts.l pr, @-r15
    mov r6, r0
    mov.l   .L_0603D394, r7
    mov.l   .L_0603D398, r5
    mov.l   .L_0603D39C, r4
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r7, r2
    mov.w r2, @r4
    mov.l   .L_0603D3A4, r14
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r14, r2
    mov.w r2, @r4
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_0603D392, r1
    mov.l   .L_0603D3A0, r3
    jsr @r3
    mov r5, r2
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0603D392:
    .2byte  0x0101                          /* [MEDIUM] nibble position/count param for bitfield RMW */
.L_0603D394:
    .4byte  0x0000FFF0                      /* mask to clear low nibble (bits 0-3) */
.L_0603D398:
    .4byte  sym_060A4D58                    /* source parameter table */
.L_0603D39C:
    .4byte  sym_060A4D28                    /* config word array (4 words at offsets 0/2/4/6) */
.L_0603D3A0:
    .4byte  sym_06034F78                    /* bitfield read-modify-write utility */
.L_0603D3A4:
    .4byte  0x0000F0FF                      /* mask to clear mid nibble (bits 8-11) */
