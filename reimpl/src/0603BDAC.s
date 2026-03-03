	.text
    .global save_integrity_check
save_integrity_check:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov r15, r5
    mov.l   .L_pool_0603BE14, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov.l   .L_pool_0603BE18, r12
    cmp/eq #0x5, r0
    bt.s    .L_0603BDD2
    mov r0, r13
    mov.l   .L_pool_0603BE1C, r3
    jsr @r3
    mov.l @(4, r14), r4
    tst r0, r0
    bf      .L_0603BDF0
.L_0603BDD2:
    mov #-0x1, r5
    mov.l   .L_pool_0603BE20, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov.l @r12, r2
    mov.w   .L_wpool_0603BE10, r0
    mov.l @(r0, r2), r3
    cmp/eq r14, r3
    bf      .L_0603BDEC
    mov.l @r12, r2
    mov #0x0, r3
    mov.w   .L_wpool_0603BE10, r0
    mov.l r3, @(r0, r2)
.L_0603BDEC:
    bra     .L_0603BE00
    mov #0x5, r13
.L_0603BDF0:
    tst r13, r13
    bt      .L_0603BE00
    mov.l @r12, r3
    mov.w   .L_wpool_0603BE10, r0
    mov.l r14, @(r0, r3)
    mov #0x1, r3
    mov #0x12, r0
    mov.b r3, @(r0, r14)
.L_0603BE00:
    mov r13, r0
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .short  0x00A8
.L_wpool_0603BE10:
    .short  0x00B4
    .short  0xFFFF
.L_pool_0603BE14:
    .long  scene_buffer_update
.L_pool_0603BE18:
    .long  sym_060A4D14
.L_pool_0603BE1C:
    .long  sym_0603EFD4
.L_pool_0603BE20:
    .long  race_timer_sync
    .long  0x2F864F22
    .long  0x4F127FF0
    .long  0x2F5265F3
    .long  0xBC3A7504
    .long  0x64F37404
    .long  0x84486403
    .long  0x644C2448
    .long  0x8B0560F3
    .long  0x70046002
    .long  0x63F2A012
    .long  0x303C60F3
    .long  0x61F2D310
    .long  0x70046802
    .long  0x430B6043
    .long  0x63F37304
    .long  0xE209323C
    .long  0x6220622C
    .long  0x6343332C
    .long  0x0037001A
    .long  0x308C7F10
    .long  0x4F164F26
    .long  0x000B68F6
    .long  0xE01D004C
    .long  0x600CC860
    .long  0x8B02D304
    .long  0x432B0009
    .long  0x1458E200
    .long  0x000B1429
    .long  sym_06034FFC
    .long  evt_error_code_return
