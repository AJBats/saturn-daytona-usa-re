
    .section .text.FUN_06020284


    .global obj_pool_dealloc
    .type obj_pool_dealloc, @function
obj_pool_dealloc:
    sts.l pr, @-r15
    add #-0x8, r15
    mov r15, r7
    mov r15, r1
    mov.l   .L_pool_06020320, r2
    mov.l   .L_pool_06020314, r6
    mov.l   .L_pool_06020318, r5
    mov.l   .L_pool_0602031C, r4
    mov.l   .L_pool_06020324, r3
    add #0x4, r7
    add #0x4, r1
    jsr @r3
    mov #0x4, r0
    mov.w @(2, r6), r0
    mov.l   .L_fp_half, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      _no_increment
    mov.b @r4, r3
    add #0x1, r3
    mov.b r3, @r4
    mov.b @r4, r2
    mov #0x19, r3
    cmp/ge r3, r2
    bf      _no_increment
    mov #0x19, r3
    mov.b r3, @r4
_no_increment:
    mov.w @(2, r6), r0
    mov.w   .L_wpool_06020310, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      _no_decrement
    mov.b @r4, r3
    add #-0x1, r3
    mov.b r3, @r4
    mov.b @r4, r2
    cmp/pl r2
    bt      _no_decrement
    mov #0x0, r2
    mov.b r2, @r4
_no_decrement:
    mov.w @(2, r6), r0
    mov.w   .L_wpool_06020312, r2
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      _no_confirm
    mov.b @r4, r3
    mov.b @r5, r0
    mov.b @(r0, r7), r2
    extu.b r2, r2
    cmp/eq r2, r3
    bf      _no_confirm
    mov.b @r5, r2
    add #0x1, r2
    mov.b r2, @r5
_no_confirm:
    mov.b @r5, r0
    cmp/eq #0x4, r0
    bf      _not_complete
    mov #0x1, r2
    mov.l   .L_pool_0602032C, r3
    mov.b r2, @r3
_not_complete:
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
.L_wpool_06020310:
    .2byte  0x4000                       /* bit 14: decrement button flag */
.L_wpool_06020312:
    .2byte  0x0200                       /* bit 9: confirm/select button flag */
.L_pool_06020314:
    .4byte  g_pad_state                 /* &input_state struct (+2 = button flags) */
.L_pool_06020318:
    .4byte  sym_06087826                 /* &anim_state_A byte (pool slot index) */
.L_pool_0602031C:
    .4byte  sym_06087825                 /* &lap_init_counter byte (0..25) */
.L_pool_06020320:
    .4byte  sym_0605F526                 /* &pool_data_table (4 bytes, src for copy) */
.L_pool_06020324:
    .4byte  sym_06035228                 /* memcpy_byte(r0=count, r1=dst, r2=src) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_0602032C:
    .4byte  sym_06087824                 /* &anim_state_B byte (completion flag) */
