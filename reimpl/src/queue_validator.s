
    .section .text.FUN_06041128


    .global queue_validator
    .type queue_validator, @function
queue_validator:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   DAT_06041174, r3
    cmp/eq r3, r4
    bt      .L_check_sequence
    mov.l   .L_pool_0604117C, r0
    mov.l @r0, r0
    add #0x18, r0
    mov.b @(r0, r4), r0
    cmp/eq #0x1, r0
    bt      .L_check_sequence
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x7, r0
.L_check_sequence:
    mov.l   .L_pool_0604117C, r6
    mov.l @r6, r2
    mov.l @(56, r2), r3
    cmp/eq r5, r3
    bt      .L_validate_commit
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x9, r0
.L_validate_commit:
    mov.l @r6, r3
    mov #0x1, r2
    mov.w   .L_w_validated_flag_off, r0
    mov.l r2, @(r0, r3)
    mov.l @r6, r3
    add #0x4, r0
    mov.l r4, @(r0, r3)
    .byte   0xB4, 0x9B    /* bsr 0x06041AA0 (external) */  ! call track_boundary_check
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop

    .global DAT_06041174
DAT_06041174:
    .2byte  0x00FF
.L_w_validated_flag_off:
    .2byte  0x0304                     /* [HIGH] state struct offset: validated flag (+0x304) */
    .4byte  ai_checkpoint_validate     /* (adjacent TU pool entry) */
.L_pool_0604117C:
    .4byte  sym_060A5400               /* [HIGH] game state base pointer (indirect) */
