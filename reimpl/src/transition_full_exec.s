
    .section .text.FUN_0601924C


    .global transition_full_exec
    .type transition_full_exec, @function
transition_full_exec:
    sts.l pr, @-r15
    mov.l   .L_fn_sound_cmd_dispatch, r14
    mov.l   .L_snd_busy_flag, r2
    mov.l r3, @r2
    mov.l   .L_snd_cmd_init, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_snd_cmd_stop, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB0, 0x42    /* bsr 0x060192E8 (external) */  ! call wait_sound_ready
    nop
    mov.l   .L_snd_busy_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_skip_sound_restore
    mov.l   .L_copy_size, r6
    mov.l   .L_wram_src_addr, r5
    mov.l   .L_snd_ram_dst, r4
    mov.l   .L_fn_memcpy_byte_idx, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_snd_ready_mailbox, r3
    mov.w r2, @r3
.L_skip_sound_restore:
    mov.l   .L_snd_cmd_init, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0x000B
    .4byte  0x0009FFFF
.L_fn_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch
.L_snd_busy_flag:
    .4byte  sym_06086050
.L_snd_cmd_init:
    .4byte  0xAE0001FF
.L_snd_cmd_stop:
    .4byte  0xAE0005FF
.L_copy_size:
    .4byte  0x0006D000
.L_wram_src_addr:
    .4byte  0x0026D000
.L_snd_ram_dst:
    .4byte  0x25A03000                  /* Sound RAM +0x03000 */
.L_fn_memcpy_byte_idx:
    .4byte  memcpy_byte_idx
.L_snd_ready_mailbox:
    .4byte  0x25A02DBE                  /* Sound RAM +0x02DBE */
    .4byte  0xE500D611
    .4byte  0xD4116363
    .4byte  0x625E7601
    .4byte  0x44108FFA
    .4byte  0x2320000B
    .2byte  0x0009

    .global sym_060192CA
sym_060192CA:
    mov #0x0, r5
