	.text
    .global evt_checkpoint_validate
evt_checkpoint_validate:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD7, 0x15    /* mov.l .L_pool_0604130D, r7 */
    mov.w   .L_06041306, r0
    mov.l @r7, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_060412CA
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x1, r0
.L_060412CA:
    mov.l @r7, r0
    mov.l @(52, r0), r0
    cmp/eq #0x1, r0
    bf      .L_060412DA
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x5, r0
.L_060412DA:
    mov #0x1, r3
    mov.l @r7, r2
    mov.l r3, @(52, r2)
    mov.l @r7, r2
    mov.w   .L_06041306, r0
    mov.l r3, @(r0, r2)
    add #0x4, r0
    mov.l @r7, r3
    mov.l r4, @(r0, r3)
    mov.l @r7, r3
    add #0x4, r0
    mov.l r5, @(r0, r3)
    add #0x4, r0
    mov.l @r7, r3
    mov.l r6, @(r0, r3)
    .byte   0xB5, 0x38    /* bsr 0x06041D6C (external) */
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
.L_06041306:
    .short  0x0338
    .long  ai_checkpoint_validate
.L_pool_0604130D:
    .long  sym_060A5400
    .long  0xD5149025
    .long  0x6352003E
    .long  0x20088906
    .long  0x63529020
    .long  0x023E3240
    .long  0x8B01000B
    .long  0xE000E001
    .long  0x000B0009
