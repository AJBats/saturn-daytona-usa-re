
    .section .text.FUN_06018EE4


    .global race_sound_handler
    .type race_sound_handler, @function
race_sound_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_sound_ram_0x02DBC, r11
    mov.w   DAT_06018f74, r12
    mov.l   .L_smpc_sf, r13
    mov #0x1, r14

_poll_sf_idle_sndoff:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      _poll_sf_idle_sndoff
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x7, r3
    mov.l   .L_smpc_comreg_ct, r2
    mov.b r3, @r2

_poll_sf_done_sndoff:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      _poll_sf_done_sndoff

    .byte   0xB1, 0xCE    /* bsr 0x060192B4 (external) */  ! BSR FUN_060192B4 — zero 512KB sound RAM
    nop
    mov.w   DAT_06018f76, r2
    mov.l   .L_scsp_reg_0x000, r3
    mov.w r2, @r3

    mov.l   .L_pool_load_sounds_bin, r3
    jsr @r3
    nop
    mov.l   .L_pool_load_gamed_sndram, r3
    jsr @r3
    nop

_poll_sf_idle_sndon:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      _poll_sf_idle_sndon
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x6, r3
    mov.l   .L_smpc_comreg_ct, r2
    mov.b r3, @r2

_poll_sf_done_sndon:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      _poll_sf_done_sndon

_poll_68k_boot_ok:
    mov.w @r11, r3
    extu.w r3, r3
    cmp/eq r12, r3
    bf      _poll_68k_boot_ok

    mov.l   .L_pool_bgm_start_cmd, r5
    mov.l   .L_pool_sound_cmd_dispatch, r3
    jsr @r3
    mov #0xF, r4
    mov.l   .L_pool_sys_init_cmd, r5
    mov.l   .L_pool_sound_cmd_dispatch, r3
    jsr @r3
    mov #0xF, r4

    mov #0x0, r2
    mov.l   .L_pool_snd_init_flag, r3
    mov.l r2, @r3
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_pool_set_master_vol, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_06018f74
DAT_06018f74:
    .2byte  0x4F4B                      /* "OK" — 68K boot handshake word (ASCII 'O','K') */

    .global DAT_06018f76
DAT_06018f76:
    .2byte  0x0200                      /* SCSP master control reset value */

.L_sound_ram_0x02DBC:
    .4byte  0x25A02DBC                  /* Sound RAM +0x02DBC */
.L_smpc_sf:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_smpc_comreg_ct:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_scsp_reg_0x000:
    .4byte  0x25B00400                  /* SCSP common register +0x000 */
.L_pool_load_sounds_bin:
    .4byte  sym_06012E84                /* -> load_sounds_bin (load SOUNDS.BIN to Sound RAM) */
.L_pool_load_gamed_sndram:
    .4byte  sym_06012EBC                /* -> load_gamed_sndram (load GAMED.BIN to Sound RAM +0x3000) */
.L_pool_bgm_start_cmd:
    .4byte  0xAE0600FF                  /* sound cmd: group 06, ID 00 — start BGM */
.L_pool_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch          /* -> sound_cmd_dispatch (sound command API) */
.L_pool_sys_init_cmd:
    .4byte  0xAE0007FF                  /* sound cmd: group 00, ID 07 — system init sound */
.L_pool_snd_init_flag:
    .4byte  sym_06086038                /* -> sound-init pending flag (cleared when done) */
.L_pool_set_master_vol:
    .4byte  scsp_set_master_volume      /* -> scsp_set_master_volume (set SCSP output levels) */
