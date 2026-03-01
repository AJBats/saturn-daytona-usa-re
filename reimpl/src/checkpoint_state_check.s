
    .section .text.FUN_06041470


    .global checkpoint_state_check
    .type checkpoint_state_check, @function
checkpoint_state_check:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_ai_state_base, r6
    mov.l @r6, r0
    add #0x18, r0
    mov.b @(r0, r5), r0
    cmp/eq #0x1, r0
    bf      .L_invalid_state
    mov.l @r6, r0
    mov.b @(r0, r5), r0
    cmp/eq #0x1, r0
    bt      .L_check_trigger
.L_invalid_state:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x5, r0
.L_check_trigger:
    mov.l @r6, r2
    mov.w   .L_off_trigger_flag, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bt      .L_set_trigger
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x1, r0
.L_set_trigger:
    mov #0x1, r2
    mov.w   .L_off_trigger_flag, r0
    mov.l @r6, r3
    mov.l r2, @(r0, r3)
    add #0x4, r0
    mov.l @r6, r3
    mov.l r4, @(r0, r3)
    mov.l @r6, r3
    add #0x4, r0
    mov.l r5, @(r0, r3)
    .byte   0xB5, 0xE7    /* bsr 0x06042088 (external) */
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
.L_off_trigger_flag:
    .2byte  0x0360                      /* AI state offset: checkpoint trigger flag */
    .2byte  0xFFFF                     /* alignment padding */
    .4byte  ai_checkpoint_validate     /* (adjacent reference for BSR target) */
.L_ai_state_base:
    .4byte  sym_060A5400               /* pointer to AI state base structure */
