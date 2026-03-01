
    .section .text.FUN_06012CF4


    .global cd_progress_notify
    .type cd_progress_notify, @function
cd_progress_notify:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_cmd_validate_exec, r9
    mov.l   .L_pool_bios_service_ptr, r13
    mov #0x2, r14
    mov #-0x1, r3
    mov.l r3, @r15
    mov #0x0, r4
    mov r4, r10
    exts.b r4, r4
    mov.l   .L_pool_cd_status_flag, r3
    mov.b r4, @r3
    mov.l   .L_pool_cd_cmd_struct, r2
    mov #0x1, r3
    mov.l r3, @r2
    mov.l   .L_pool_cd_data_dest, r3
    mov.l r3, @(8, r2)
    mov #0x50, r3
    mov.l r3, @(4, r2)
    mov.l   .L_pool_cd_sector_buf, r11
.L_poll_loop:
    mov.l   .L_pool_cd_cmd_struct, r6
    mov r11, r5
    jsr @r9
    mov #0x5, r4
    add #0x1, r10
    mov #0x5, r2
    cmp/ge r2, r10
    bf/s    .L_check_result
    mov r0, r12
    mov.l @r13, r2
    jsr @r2
    nop
.L_check_result:
    cmp/gt r14, r12
    bf      .L_poll_loop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x000B
    .4byte  0x0009FFFF
.L_pool_cmd_validate_exec:
    .4byte  cmd_validate_exec
.L_pool_bios_service_ptr:
    .4byte  sym_0600026C
.L_pool_cd_status_flag:
    .4byte  sym_06084AEC
.L_pool_cd_cmd_struct:
    .4byte  sym_06084360
.L_pool_cd_data_dest:
    .4byte  sym_0608436C
.L_pool_cd_sector_buf:
    .4byte  sym_06083274
    .4byte  0x000B0009
    .4byte  0x000B0009
