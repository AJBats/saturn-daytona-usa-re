
    .section .text.FUN_06012B58


    .global cd_status_reader
    .type cd_status_reader, @function
cd_status_reader:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_cmd_validate_exec, r10
    mov #0x1, r12
    mov #0x5, r14
    mov #-0x1, r4
    mov.l   .L_pool_cd_cmd_struct, r3
    mov.l r12, @r3
    mov r3, r2
    mov.l   .L_pool_cd_data_dest, r3
    mov.l r3, @(8, r2)
    mov #0x50, r3
    mov.l r3, @(4, r2)
    mov.l   .L_pool_cd_sector_buf, r11
    bra     .L_retry_check
    mov #0x0, r13
.L_retry_loop:
    mov.l   .L_pool_cd_cmd_struct, r6
    mov r11, r5
    jsr @r10
    mov #0x5, r4
    mov r0, r4
.L_retry_check:
    add #0x1, r13
    cmp/ge r14, r13
    bf      .L_retry_loop
    mov #0x2, r3
    mov.l   .L_pool_cd_status_flag, r13
    cmp/gt r3, r4
    bt      .L_read_ok
    bra     .L_return
    mov.b r12, @r13
.L_read_ok:
    mov.l   .L_pool_aprog_filename, r4
    mov.l   .L_pool_cmd_status_check, r3
    jsr @r3
    nop
    cmp/pz r0
    bt      .L_status_ok
    bra     .L_return
    mov.b r12, @r13
.L_status_ok:
    mov #0x0, r2
    mov.b r2, @r13
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_cmd_validate_exec:
    .4byte  cmd_validate_exec
.L_pool_cd_cmd_struct:
    .4byte  sym_06084360
.L_pool_cd_data_dest:
    .4byte  sym_0608436C
.L_pool_cd_sector_buf:
    .4byte  sym_06083274
.L_pool_cd_status_flag:
    .4byte  sym_06084AEC
.L_pool_aprog_filename:
    .4byte  sym_060448C8
.L_pool_cmd_status_check:
    .4byte  cmd_status_check
