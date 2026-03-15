
    .section .text.FUN_0600A0C0


    .global FUN_0600A0C0
    .type FUN_0600A0C0, @function
FUN_0600A0C0:
    mov.l r14, @-r15
    sts.l pr, @-r15

    mov.w   .L_0600A10E, r4
    mov.l   .L_0600A120, r3
    jsr @r3
    mov #0x0, r5

    mov.l   .L_0600A124, r3
    jsr @r3
    nop

    mov #0x0, r14
    mov.l   .L_0600A128, r3
    mov.l r14, @r3

    mov.l   .L_0600A12C, r4
    mov.l   .L_0600A130, r3
    jsr @r3
    nop

    mov.w   DAT_0600a110, r2
    mov r14, r6
    mov r14, r5
    mov.l r2, @-r15
    mov.w   DAT_0600a112, r7
    mov.l   .L_0600A134, r3
    jsr @r3
    mov r14, r4

    mov.l   .L_0600A138, r3
    mov.l r14, @r3

    mov.l   .L_0600A12C, r2
    mov.l   .L_0600A13C, r3
    mov.l @r2, r2
    mov.w r3, @r2

    mov.l   .L_0600A124, r3
    jsr @r3
    add #0x4, r15

    mov.l   .L_0600A128, r3
    mov.l r14, @r3

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600a10c
DAT_0600a10c:
    mov.b @(r0, r11), r0
.L_0600A10E:
    .2byte  0x0100

    .global DAT_0600a110
DAT_0600a110:
    .2byte  0x00DF

    .global DAT_0600a112
DAT_0600a112:
    .2byte  0x015F
    .4byte  sym_0607E944
    .4byte  FUN_06014884
    .4byte  sym_0607EBC8
.L_0600A120:
    .4byte  FUN_06038BD4
.L_0600A124:
    .4byte  sym_06026CE0
.L_0600A128:
    .4byte  sym_06059F44
.L_0600A12C:
    .4byte  sym_06063F5C               /* [HIGH] VDP1 command buffer base pointer */
.L_0600A130:
    .4byte  FUN_06039250
.L_0600A134:
    .4byte  sym_060393FC
.L_0600A138:
    .4byte  sym_0605A008
.L_0600A13C:
    .4byte  0x00008000
