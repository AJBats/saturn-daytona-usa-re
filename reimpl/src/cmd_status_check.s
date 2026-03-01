
    .section .text.FUN_0603AE08


    .global cmd_status_check
    .type cmd_status_check, @function
cmd_status_check:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_pool_state_ptr, r14
    mov.w   .L_woff_active_count, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_not_ready
    mov.l @r14, r0
    mov.w   .L_woff_mode_flag, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bt      .L_do_lookup
.L_not_ready:
    mov #-0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xA5, 0x86    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-8)
    mov.l @r15+, r14
.L_do_lookup:
    mov.l @r14, r6
    mov.w   .L_woff_max_entries, r0
    mov.l @r15, r5
    mov.l @r14, r4
    mov.l   .L_pool_dir_lookup_fn, r3
    mov.l @(r0, r6), r6
    mov.w   .L_woff_active_count, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r14
    cmp/pz r14
    bt      .L_lookup_ok
    mov #-0x9, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xA5, 0x75    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-9)
    mov.l @r15+, r14
.L_lookup_ok:
    .byte   0xB5, 0x73    /* bsr 0x0603B93C (external) */  ! call save_checksum_calc(r4=0) — report success
    mov #0x0, r4
    mov r14, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_woff_active_count:
    .2byte  0x00A0                          /* [HIGH] struct offset: active entry count (+0xA0) */
.L_woff_mode_flag:
    .2byte  0x0098                          /* [HIGH] struct offset: mode flag (+0x98) */
.L_woff_max_entries:
    .2byte  0x009C                          /* [HIGH] struct offset: max entries for lookup (+0x9C) */
    .2byte  0xFFFF                          /* alignment padding */
    .4byte  sym_06035168                    /* [HIGH] memcpy_long — unreferenced dead pool entry */
.L_pool_state_ptr:
    .4byte  sym_060A4D14                    /* [HIGH] global command state struct pointer */
.L_pool_dir_lookup_fn:
    .4byte  slave_sh2_setup                 /* [HIGH] directory entry lookup function */
