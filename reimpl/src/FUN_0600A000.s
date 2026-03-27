
    .section .text.FUN_0600A000


    .global FUN_0600A000
    .type FUN_0600A000, @function
FUN_0600A000:
    sts.l pr, @-r15
    mov.l   .L_pool_0600A06C, r14
    jsr @r14
    mov #0x1, r4
    mov #0x0, r5
    jsr @r14
    mov #0x3, r4
    mov #0x0, r5
    jsr @r14
    mov #0x2, r4
    mov.l   .L_pool_0600A070, r5
    jsr @r14
    mov #0x0, r4
    mov.l   .L_pool_0600A074, r5
    jsr @r14
    mov #0x0, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_0600A026
    .type FUN_0600A026, @function
FUN_0600A026:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600A078, r14
    jsr @r14
    mov #0x0, r4
    jsr @r14
    mov #0x4, r4
    jsr @r14
    mov #0x8, r4
    jsr @r14
    mov #0xC, r4
    mov.l   .L_0600A07C, r3
    jsr @r3
    nop
    mov #0x0, r6
    mov.l   .L_0600A080, r14
    mov r6, r5
    jsr @r14
    mov #0x4, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x20, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_0600A06C:
    .4byte  FUN_0601D5F4
.L_pool_0600A070:
    .4byte  0xAE0001FF
.L_pool_0600A074:
    .4byte  0xAE0600FF
.L_0600A078:
    .4byte  sym_0602853E
.L_0600A07C:
    .4byte  sym_06028560
.L_0600A080:
    .4byte  FUN_06014884
    .global FUN_0600A084
FUN_0600A084:
    .4byte  0xD523E401
    .4byte  0x90406352
    .4byte  0x023E3247
    .4byte  0x8904E600
    .4byte  0x6563D320
    .4byte  0x432BE410
    .4byte  0x62529035
    .4byte  0xD31E052E
    .4byte  0x63324518
    .4byte  0x24394508
    .4byte  0x45084508
    .4byte  0x45002448
    .4byte  0x8900655B
    .4byte  0xE600D317
    .4byte  0x432BE410
