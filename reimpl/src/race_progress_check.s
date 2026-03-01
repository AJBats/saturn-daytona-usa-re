
    .section .text.FUN_06012710


    .global race_progress_check
    .type race_progress_check, @function
race_progress_check:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_060127A4, r13
    mov.l   .L_pool_060127A8, r14
    mov.l   .L_pool_060127AC, r12
    bra     .L_0601276A
    mov.l @r13, r0
.L_06012722:
    mov #0x1, r2
    mov.l   .L_pool_060127B0, r3
    mov.b r2, @r3
    mov.l   .L_pool_060127B4, r2
    mov.l @r2, r2
    mov.l @(48, r2), r3
    mov.l   .L_pool_060127B8, r1
    mov.l r3, @r1
    mov.l   .L_pool_060127BC, r5
    bra     .L_06012740
    nop
.L_06012738:
    mov.l   .L_pool_060127C0, r5
    bra     .L_06012740
    nop
.L_0601273E:
    mov.l   .L_pool_060127C4, r5
.L_06012740:
    jsr @r14
    mov #0x0, r4
    mov r12, r5
    jsr @r14
    mov #0x0, r4
    bra     .L_0601277A
    nop
.L_0601274E:
    mov.l   .L_pool_060127C8, r5
    jsr @r14
    mov #0x0, r4
    mov.l   .L_pool_060127CC, r5
    jsr @r14
    mov #0x0, r4
    mov #0x3C, r2
    mov.l   .L_pool_060127D0, r3
    mov.w r2, @r3
    mov #0x1, r2
    mov.l   .L_pool_060127D4, r3
    mov.b r2, @r3
    bra     .L_0601277A
    nop
.L_0601276A:
    cmp/eq #0x28, r0
    bt      .L_0601274E
    cmp/eq #0x3C, r0
    bt      .L_0601273E
    cmp/eq #0x50, r0
    bt      .L_06012738
    cmp/eq #0x64, r0
    bt      .L_06012722
.L_0601277A:
    mov.l @r13, r1
    mov.l   .L_pool_060127D8, r2
    jsr @r2
    mov #0x4, r0
    tst r0, r0
    .word 0x0029
    mov.l @r13, r3
    mov #0x6E, r2
    cmp/gt r2, r3
    .word 0x0129
    and r1, r0
    tst r0, r0
    bt      .L_0601279A
    mov.l   .L_pool_060127DC, r5
    jsr @r14
    mov #0x0, r4
.L_0601279A:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_060127A4:
    .4byte  sym_0607EBCC                    /* &state_countdown (race progress counter) */
.L_pool_060127A8:
    .4byte  sound_cmd_dispatch              /* sound command dispatcher function */
.L_pool_060127AC:
    .4byte  0xAE1115FF                      /* sound cmd: persistent progress tone */
.L_pool_060127B0:
    .4byte  sym_06078654                    /* &finish_flag / lap count (byte) */
.L_pool_060127B4:
    .4byte  sym_0607E944                    /* &car_array_base pointer (deref to get array) */
.L_pool_060127B8:
    .4byte  sym_06063EF0                    /* &camera_yaw angle storage */
.L_pool_060127BC:
    .4byte  0xAE1122FF                      /* sound cmd: menu select / race-complete confirm */
.L_pool_060127C0:
    .4byte  0xAE1123FF                      /* sound cmd: lap progress milestone */
.L_pool_060127C4:
    .4byte  0xAE1124FF                      /* sound cmd: mid-race milestone */
.L_pool_060127C8:
    .4byte  0xAE1125FF                      /* sound cmd: early-race start */
.L_pool_060127CC:
    .4byte  0xAE1116FF                      /* sound cmd: race init / setup */
.L_pool_060127D0:
    .4byte  sym_06086056                    /* &countdown_timer (16-bit word) */
.L_pool_060127D4:
    .4byte  sym_0608605A                    /* &race_ready_flag (byte) */
.L_pool_060127D8:
    .4byte  sym_06035C2C                    /* mem_store_helper function */
.L_pool_060127DC:
    .4byte  0xAE110CFF                      /* sound cmd: race finish fanfare */
