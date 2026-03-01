
    .section .text.FUN_06027552


    .global fpmul
    .type fpmul, @function
fpmul:
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    rts
    xtrct r4, r0

    .global fpdiv_setup
fpdiv_setup:
    mov.w   .L_06027570, r2
    mov r4, r3
    mov.l r5, @(0, r2)
    shlr16 r3
    exts.w r3, r3
    mov.l r3, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    rts
    mov.l @(28, r2), r0
.L_06027570:
    .2byte  0xFF00
    .2byte  0x0000

    .global memmove_byte
memmove_byte:
    cmp/eq r4, r5
    bt      .mb_done
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .mb_done
    cmp/hi r4, r5
    bt      .mb_fwd
    add r6, r5
    add r6, r4
    add #-0x1, r5
.mb_bwd:
    mov.b @r5, r7
    dt r6
    mov.b r7, @-r4
    bf/s    .mb_bwd
    add #-0x1, r5
.mb_done:
    rts
    nop
.mb_fwd:
    mov.b @r5+, r7
    dt r6
    mov.b r7, @r4
    bf/s    .mb_fwd
    add #0x1, r4
    rts
    nop

    .global memmove_word
memmove_word:
    cmp/eq r4, r5
    bt      .mw_done
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .mw_done
    mov r6, r7
    cmp/hi r4, r5
    bt/s    .mw_fwd
    shlr r6
    add r7, r5
    add r7, r4
    add #-0x4, r5
.mw_bwd:
    mov.w @r5, r7
    dt r6
    mov.w r7, @-r4
    bf/s    .mw_bwd
    add #-0x2, r5
.mw_done:
    rts
    nop
.mw_fwd:
    mov.w @r5+, r7
    dt r6
    mov.w r7, @r4
    bf/s    .mw_fwd
    add #0x2, r4
    rts
    nop

    .global memmove_long
memmove_long:
    cmp/eq r4, r5
    bt      .ml_done
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .ml_done
    mov r6, r7
    cmp/hi r4, r5
    bt/s    .ml_fwd
    shlr2 r6
    add r7, r5
    add r7, r4
    add #-0x4, r5
.ml_bwd:
    mov.l @r5, r7
    dt r6
    mov.l r7, @-r4
    bf/s    .ml_bwd
    add #-0x4, r5
.ml_done:
    rts
    nop
.ml_fwd:
    mov.l @r5+, r7
    dt r6
    mov.l r7, @r4
    bf/s    .ml_fwd
    add #0x4, r4
    rts
    nop

    .global memcpy_byte_idx
memcpy_byte_idx:
    mov #0x0, r0
    add #-0x1, r6
.mbi_loop:
    mov.b @(r0, r5), r1
    cmp/gt r0, r6
    mov.b r1, @(r0, r4)
    bt/s    .mbi_loop
    add #0x1, r0
    rts
    add #0x1, r6

    .global memcpy_word_idx
memcpy_word_idx:
    mov #0x0, r0
    add #-0x2, r6
.mwi_loop:
    mov.w @(r0, r5), r1
    cmp/gt r0, r6
    mov.w r1, @(r0, r4)
    bt/s    .mwi_loop
    add #0x2, r0
    rts
    add #0x2, r6

    .global memcpy_long_idx
memcpy_long_idx:
    mov #0x0, r0
    add #-0x4, r6
.mli_loop:
    mov.l @(r0, r5), r1
    cmp/gt r0, r6
    mov.l r1, @(r0, r4)
    bt/s    .mli_loop
    add #0x4, r0
    rts
    add #0x4, r6

    .global memcpy_block32
memcpy_block32:
    mov.l @r5+, r0
    mov.l @r5+, r1
    mov.l @r5+, r2
    mov.l @r5+, r3
    mov.l r0, @(0, r4)
    mov.l r1, @(4, r4)
    mov.l r2, @(8, r4)
    mov.l r3, @(12, r4)
    mov.l @r5+, r0
    mov.l @r5+, r1
    mov.l @r5+, r2
    mov.l @r5+, r3
    mov.l r0, @(16, r4)
    mov.l r1, @(20, r4)
    mov.l r2, @(24, r4)
    mov.l r3, @(28, r4)
    dt r6
    bf/s    memcpy_block32
    add #0x20, r4
    rts
    nop

    .global dma_transfer
dma_transfer:
    .byte   0xD0, 0x07
    mov.l @r0, r0
    .byte   0xD1, 0x07
    tst r1, r0
    bf      dma_transfer
    .byte   0xD1, 0x07
    mov.w   .L_0602768A, r2
    mov.l r4, @(4, r1)
    mov.l r5, @(0, r1)
    mov.l r6, @(8, r1)
    mov.l r2, @(12, r1)
    mov #0x7, r0
    mov.l r0, @(20, r1)
    rts
    mov.l r2, @(16, r1)
.L_0602768A:
    .2byte  0x0101
.L_0602768C:
    .4byte  0x25FE007C
.L_06027690:
    .4byte  0x0000272E
.L_06027694:
    .4byte  0x25FE0000
    .4byte  0x00090000

    .global viewport_project
viewport_project:
    mov.w   .L_060276C0, r1
    mov.w   .L_060276CA, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r0
    mov.l @r4, r2
    neg r0, r0
    mov.l @(28, r1), r4
    dmuls.l r2, r4
    sts mach, r2
    dmuls.l r0, r4
    mov.w r2, @r5
    sts mach, r0
    rts
    mov.w r0, @(2, r5)
.L_060276C0:
    .2byte  0xFF00
    .2byte  0x0009
    .4byte  0x00010000
    .2byte  0xFF00
.L_060276CA:
    .2byte  0x00A0
