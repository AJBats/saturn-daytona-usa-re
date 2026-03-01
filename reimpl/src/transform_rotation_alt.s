
    .section .text.FUN_0602648E


    .global transform_rotation_alt
    .type transform_rotation_alt, @function
transform_rotation_alt:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    .byte   0xDC, 0x0C    /* mov.l .L_pool_slot_data_table_b, r12 */
    mov #0x8, r13
    .byte   0xDE, 0x0C    /* mov.l .L_pool_rotation_state_a, r14 */
    .byte   0xD7, 0x0D    /* mov.l .L_pool_rotation_state_b, r7 */
    .byte   0xD5, 0x0D    /* mov.l .L_pool_fp_half, r5 */
    mov #0x0, r4
    extu.w r4, r6
.L_loop_body:
    extu.w r6, r0
    shll2 r0
    shll r0
    add r12, r0
    mov.w @(6, r0), r0
    bra     .L_dispatch_setup
    extu.w r0, r0
    .4byte  0xA001624D                      /* embedded dispatch path bytes */
    .4byte  0x625DA027                      /* embedded dispatch path bytes */
    .4byte  0x2E21A001                      /* embedded dispatch path bytes */
    .4byte  0x624D625D                      /* embedded dispatch path bytes */
    .4byte  0xA0222721                      /* embedded dispatch path bytes */
.L_dispatch_out_of_range:
    bra     .L_next_slot
    nop
.L_pool_slot_data_table_b:
    .4byte  sym_0606107C                    /* [MEDIUM] slot data table B (8-byte stride, 8 slots) */
.L_pool_rotation_state_a:
    .4byte  sym_06060D2A                    /* [MEDIUM] &rotation_state_a (word) */
.L_pool_rotation_state_b:
    .4byte  sym_06060D34                    /* [MEDIUM] &rotation_state_b (word) */
.L_pool_fp_half:
    .4byte  0x00008000                  /* [HIGH] 0.5 (16.16 fixed-point) */
.L_dispatch_setup:
    mov.w   .L_wpool_dispatch_base, r1
    sub r1, r0
    mov #0xC, r1
    cmp/hs r1, r0
    bt      .L_dispatch_out_of_range
    shll r0
    mov r0, r1
    .word 0xC702
    mov.w @(r0, r1), r0
    braf r0
    nop
.L_wpool_dispatch_base:
    .2byte  0x008A                          /* [HIGH] dispatch base: lowest valid render_type */
    .4byte  0xFFC2FFC2                      /* dispatch offsets for render_type 0x008A and 0x008B */
    .4byte  0xFFCCFFCC                      /* dispatch offsets for render_type 0x008C and 0x008D */
    .4byte  0xFFC6FFC6                      /* dispatch offsets for render_type 0x008E and 0x008F */
    .4byte  0xFFC6FFC6                      /* dispatch offsets for render_type 0x0090 and 0x0091 */
    .4byte  0xFFD0FFD0                      /* dispatch offsets for render_type 0x0092 and 0x0093 */
    .4byte  0xFFD0FFD0                      /* dispatch offsets for render_type 0x0094 and 0x0095 */
.L_next_slot:
    add #0x1, r6
    extu.w r6, r2
    cmp/ge r13, r2
    bf      .L_loop_body
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
