
    .section .text.FUN_060145BC


    .global adv_collision_resp
    .type adv_collision_resp, @function
adv_collision_resp:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06014688, r12
    mov.l   .L_pool_0601468C, r14
    mov.l   .L_pool_06014690, r4
    mov.w   DAT_06014682, r2
    mov.w @(2, r4), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_exit
    mov.l   .L_pool_06014694, r11
    mov.l   .L_pool_06014698, r13
    mov.w @(2, r4), r0
    mov.w   .L_wpool_06014684, r2
    mov r0, r3
    extu.w r3, r3
    mov.l @r13, r0
    and r2, r3
    cmp/eq #0x7D, r0
    .word 0x0029
    or r0, r3
    tst r3, r3
    bt      .L_check_add
    mov.l @r14, r0
    tst r0, r0
    bf/s    .L_remove_car
    mov #0x0, r13
    mov r11, r4
    mov.b r13, @r4
    add #0x1, r4
    mov.b r13, @r4
    add #0x1, r4
    extu.b r13, r2
    mov.b r2, @r4
    add #0x1, r4
    extu.b r13, r13
    bra     .L_exit
    mov.b r13, @r4
.L_remove_car:
    mov.l   .L_pool_0601469C, r5
    jsr @r12
    mov #0x0, r4
    mov.l @r14, r2
    add #-0x1, r2
    mov.l r2, @r14
    mov r2, r3
    add r3, r11
    extu.b r13, r13
    bra     .L_exit
    mov.b r13, @r11
.L_check_add:
    mov.l @r13, r0
    cmp/eq #0x7B, r0
    bf      .L_add_variant
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0x4C    /* bra 0x060146D2 (external) */
    mov.l @r15+, r14
.L_add_variant:
    mov.l @r14, r0
    add #0x1, r0
    mov.l r0, @r14
    add #-0x1, r0
    mov.l @r13, r3
    mov.b r3, @(r0, r11)
    mov.l @r13, r2
    add #-0x41, r2
    cmp/pz r2
    bt      .L_lookup_sound
    mov.l   .L_pool_060146A0, r5
    bra     .L_play_sound
    nop
.L_lookup_sound:
    mov.l @r13, r5
    add #-0x41, r5
    shll2 r5
    mov.l   .L_pool_060146A4, r3
    add r3, r5
    mov.l @r5, r5
.L_play_sound:
    jsr @r12
    mov #0x0, r4
    mov.l @r14, r0
    cmp/eq #0x3, r0
    bf      .L_exit
    mov #0x1C, r3
    mov.l   .L_pool_060146A8, r2
    mov.l r3, @r2
    mov.l   .L_pool_060146AC, r5
    jsr @r12
    mov #0x0, r4
.L_exit:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06014682
DAT_06014682:
    .2byte  0x0700                      /* button mask: bits 8-10 (car management inputs) */
.L_wpool_06014684:
    .2byte  0x0100                      /* bit 8 mask (removal/backspace button) */
    .2byte  0xFFFF                      /* padding / alignment */
.L_pool_06014688:
    .4byte  sound_cmd_dispatch          /* sound command dispatch function */
.L_pool_0601468C:
    .4byte  sym_06084B18                /* &active_car_count (32-bit int) */
.L_pool_06014690:
    .4byte  g_pad_state                /* &input_state struct (+2 = button flags) */
.L_pool_06014694:
    .4byte  sym_06084B14                /* &variant_char_buffer (3 bytes) */
.L_pool_06014698:
    .4byte  sym_06084B20                /* &current_variant_code (32-bit) */
.L_pool_0601469C:
    .4byte  0xAB1101FF                  /* sound: car variant removed */
.L_pool_060146A0:
    .4byte  0xAB1102FF                  /* sound: default char (code < 0x41) */
.L_pool_060146A4:
    .4byte  sym_0605B0FC                /* per-character sound lookup table */
.L_pool_060146A8:
    .4byte  sym_06084B08                /* &car_slot_index (32-bit) */
.L_pool_060146AC:
    .4byte  0xAB111EFF                  /* sound: all 3 slots filled / completion */
    .4byte  0xD30FE204                  /* trailing data (next TU preamble) */
    .4byte  0x63323322
    .4byte  0x8907D20E
    .4byte  0xD30D6221
    .4byte  0x72FF2321
    .4byte  0x622F4215
    .4byte  0x8901A002
    .4byte  0x0009000B
    .2byte  0x0009
