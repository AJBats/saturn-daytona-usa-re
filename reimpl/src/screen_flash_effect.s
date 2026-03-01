
    .section .text.FUN_06028384


    .global screen_flash_effect
    .type screen_flash_effect, @function
screen_flash_effect:
    sts.l pr, @-r15
    mov.l   .L_pool_060283AC, r0
    mov.l @(r0, r4), r2
    mov.l @r2, r2
    add r2, r5
    .byte   0xBF, 0x97    /* bsr 0x060282C0 (external) */
    mov r7, r4
    mov r0, r1
    mov #0x16, r7
    mov #0x0, r0
.copy_loop:
    mov.b @r1+, r3
    add r6, r3
    mov.w r3, @(r0, r5)
    cmp/eq r7, r0
    bf/s    .copy_loop
    add #0x2, r0
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x0000                        /* alignment padding */
.L_pool_060283AC:
    .4byte  sym_06028614
    .4byte  0xA003E302
    .4byte  0xA001E306
    .4byte  0xE30ED008
    .4byte  0x024E6222
    .4byte  0x325CE50F
    .4byte  0x61736033
    .4byte  0x21594709
    .4byte  0x316C4709
    .4byte  0x02152338
    .4byte  0x8FF673FE
    .4byte  0x000B0009
    .4byte  sym_06028614

    .global sym_060283E0
sym_060283E0:
    mov.l   .L_pool_060283F8, r0
    mov.l @(r0, r4), r2
    mov.l @r2, r2
    add r5, r2
.nullterm_loop:
    mov.b @r7+, r3
    tst r3, r3
    bt      .nullterm_done
    add r6, r3
    mov.w r3, @r2
    bra     .nullterm_loop
    add #0x2, r2
    .2byte  0x0000                        /* alignment padding */
.L_pool_060283F8:
    .4byte  sym_06028614
.nullterm_done:
    rts
    nop

    .global sym_06028400
sym_06028400:
    mov.l   .L_pool_0602842C, r0
    mov.l @(r0, r4), r4
    mov.l @r4, r4
    add r4, r6
    mov #-0x80, r4
    mov.w @r5+, r3
    mov.w @r5+, r2
    add r3, r4
    add r3, r4
    neg r4, r4
.row_loop:
    mov r3, r1
.col_loop:
    mov.w @r5+, r0
    add r7, r0
    mov.w r0, @r6
    dt r1
    bf/s    .col_loop
    add #0x2, r6
    dt r2
    bf/s    .row_loop
    add r4, r6
    rts
    nop
.L_pool_0602842C:
    .4byte  sym_06028614

    .global sym_06028430
sym_06028430:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
