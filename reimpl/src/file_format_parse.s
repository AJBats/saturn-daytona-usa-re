
    .section .text.FUN_06012454


    .global file_format_parse
    .type file_format_parse, @function
file_format_parse:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_060124D4, r3
    jsr @r3
    mov.b r5, @r15
    mov.l   .L_060124D8, r3
    jsr @r3
    nop
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    mov.l   .L_060124DC, r3
    jsr @r3
    mov.l @r14, r4
    mov.b @r15, r1
    mov.l   .L_060124E0, r3
    extu.b r1, r1
    jsr @r3
    mov #0x2, r0
    mov r0, r4
    mov r0, r3
    mov.w   .L_060124D2, r2
    shll8 r4
    shll8 r3
    shll2 r4
    shll2 r3
    shll2 r4
    shll2 r3
    shll2 r4
    shll2 r3
    shll r3
    add r3, r4
    mov.l   .L_060124E4, r3
    jsr @r3
    add r2, r4
    mov.l   .L_060124E8, r5
    mov.l   .L_060124EC, r4
    mov.l   .L_060124F0, r3
    mov.l   .L_060124F4, r2
    mov.l @r5, r5
    mov.l @r4, r4
    add #-0x1, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_060124F8, r6
    mov.l   .L_060124FC, r5
    mov.l   .L_060124EC, r4
    mov.l   .L_06012500, r3
    mov.l   .L_06012504, r2
    mov.l @r6, r6
    mov.w @r5, r5
    mov.l @r4, r4
    add #-0x1, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_06012508, r3
    jmp @r3
    mov.l @r15+, r14
.L_060124D2:
    .2byte  0x1000                         /* 0x1000 fixed-point angle bias */
.L_060124D4:
    .4byte  sym_06026DBC                   /* pre-transform setup */
.L_060124D8:
    .4byte  sym_06026E0C                   /* matrix entry init */
.L_060124DC:
    .4byte  sym_06026E2E                   /* position transform dispatch */
.L_060124E0:
    .4byte  sym_06035C2C                   /* memory store helper (writes to 0xFF00 area) */
.L_060124E4:
    .4byte  mat_rot_x               /* transform matrix application */
.L_060124E8:
    .4byte  sym_06063570                   /* chain A source param (dword: 0x4) */
.L_060124EC:
    .4byte  sym_0607EAD8                   /* object/car counter (dword) */
.L_060124F0:
    .4byte  sym_06063564                   /* chain A lookup table (object transforms) */
.L_060124F4:
    .4byte  sym_06031D8C                   /* transform chain dispatch A */
.L_060124F8:
    .4byte  sym_0606356C                   /* chain B source param (dword: 0x1) */
.L_060124FC:
    .4byte  sym_06089EA0                   /* display mode selector (16-bit) */
.L_06012500:
    .4byte  sym_0606355C                   /* chain B lookup table (display transforms) */
.L_06012504:
    .4byte  sym_06031A28                   /* transform chain dispatch B */
.L_06012508:
    .4byte  sym_06026DF8                   /* post-render cleanup (pop matrix frame) */
