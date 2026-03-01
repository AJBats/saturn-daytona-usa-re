
    .section .text.FUN_0603B424


    .global cmd_dispatch_main
    .type cmd_dispatch_main, @function
cmd_dispatch_main:
    mov.l r14, @-r15
    mov #0x12, r0
    mov.l r13, @-r15
    mov r4, r14
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.b @(r0, r14), r3
    extu.b r3, r3
    tst r3, r3
    bf      .check_deserialize
    bra     .ret_read_state
    nop
.check_deserialize:
    .byte   0xB4, 0x6E    /* bsr 0x0603BD1C (external) */  ! call save_deserialize(r4=block_ptr)
    mov r14, r4
    bra     .dispatch_code
    mov r0, r13
.err_state_6:
    mov.w   DAT_0603b4c6, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x1, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .byte   0xA2, 0x73    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-1)
    mov.l @r15+, r14
.err_state_3:
    mov.w   DAT_0603b4c8, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x17, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .byte   0xA2, 0x6A    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-0x17)
    mov.l @r15+, r14
.err_state_4:
    mov.w   DAT_0603b4ca, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x2, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .byte   0xA2, 0x61    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-2)
    mov.l @r15+, r14
.err_state_5:
    mov.w   DAT_0603b4cc, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    mov #-0x14, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .byte   0xA2, 0x58    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-0x14)
    mov.l @r15+, r14
.code_1_check_ready:
    .byte   0xB5, 0x65    /* bsr 0x0603BF5A (external) */  ! call cmd_block_check(r4=block_ptr)
    mov r14, r4
    cmp/eq #0x1, r0
    bf      .integrity_check
    mov.w   DAT_0603b4ce, r3
    mov #0x12, r0
    mov.b r3, @(r0, r14)
    mov #-0x18, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .byte   0xA2, 0x4B    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc(r4=-0x18)
    mov.l @r15+, r14
.code_0_exec:
    mov #0x11, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .integrity_check
    mov #0x0, r2
    mov #0x12, r0
    mov.b r2, @(r0, r14)
    .byte   0xB2, 0x8E    /* bsr 0x0603B9D6 (external) */  ! call save_field_read(r4=block_ptr)
    mov r14, r4
    .byte   0xB2, 0x3F    /* bsr 0x0603B93C (external) */  ! call save_checksum_calc(r4=0)
    mov #0x0, r4
    mov #0x12, r0
    mov.b @(r0, r14), r0
    bra     .epilogue
    extu.b r0, r0

    .global DAT_0603b4c6
DAT_0603b4c6:
    .2byte  0x00FF

    .global DAT_0603b4c8
DAT_0603b4c8:
    .2byte  0x00E9

    .global DAT_0603b4ca
DAT_0603b4ca:
    .2byte  0x00FE

    .global DAT_0603b4cc
DAT_0603b4cc:
    .2byte  0x00EC

    .global DAT_0603b4ce
DAT_0603b4ce:
    .2byte  0x00E8
.dispatch_code:
    cmp/eq #0x0, r0
    bt      .code_0_exec
    cmp/eq #0x1, r0
    bt      .code_1_check_ready
    cmp/eq #0x3, r0
    bt      .err_state_3
    cmp/eq #0x4, r0
    bt      .err_state_4
    cmp/eq #0x5, r0
    bt      .err_state_5
    cmp/eq #0x6, r0
    bt      .err_state_6
.integrity_check:
    .byte   0xB4, 0x60    /* bsr 0x0603BDAC (external) */  ! call save_integrity_check(r4=block_ptr)
    mov r14, r4
    mov r0, r4
    mov r13, r0
    cmp/eq #0x2, r0
    bf      .ret_read_state
    mov r4, r0
    cmp/eq #0x5, r0
    bf      .ret_read_state
    .byte   0xD3, 0x18    /* mov.l .L_pool_0603B55C, r3 */  ! r3 = &sym_0603F9F2 (time-field A getter)
    jsr @r3
    mov.l @(8, r14), r4
    mov r0, r8
    .byte   0xD3, 0x17    /* mov.l .L_pool_0603B560, r3 */  ! r3 = &sym_0603F9F6 (time-field B getter)
    jsr @r3
    mov.l @(8, r14), r4
    mov r8, r5
    mov r14, r4
    sub r0, r5
    .byte   0xBD, 0x5F    /* bsr 0x0603AFD0 (external) */  ! call cmd_error_return(r4=block, r5=delta, r6=1)
    mov #0x1, r6
    mov #0x0, r2
    mov #0x12, r0
    mov r14, r13
    mov.b r2, @(r0, r14)
    .byte   0xB1, 0xCB    /* bsr 0x0603B8B4 (external) */  ! call sys_dma_channel_init(r4=block_ptr)
    mov r14, r4
    .byte   0xB1, 0xE9    /* bsr 0x0603B8F4 (external) */  ! call inner_dma_flush(r4=block_ptr)
    mov r13, r4
    .byte   0xB2, 0x58    /* bsr 0x0603B9D6 (external) */  ! call save_field_read(r4=block_ptr)
    mov r13, r4
.ret_read_state:
    .byte   0xB2, 0x09    /* bsr 0x0603B93C (external) */  ! call save_checksum_calc(r4=0)
    mov #0x0, r4
    mov #0x12, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
.epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xE060
