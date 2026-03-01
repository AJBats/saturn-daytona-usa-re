
    .section .text.FUN_0602D89A


    .global vtx_clip_flag_set
    .type vtx_clip_flag_set, @function
vtx_clip_flag_set:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xD0, 0x06    /* mov.l .L_pool_car_state_ptr, r0 */
    mov.l @r0, r0
    bsr     sym_0602D8BC
    nop
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_pool_car_state_ptr:
    .4byte  sym_0607E944                  /* [MEDIUM] current car state pointer (per scene_camera.s) */

    .global sym_0602D8BC
sym_0602D8BC:
    mov #0x0, r4
    .byte   0x91, 0x2A    /* mov.w .L_wpool_0602D916, r1 */
    mov.w @(r0, r1), r2
    cmp/eq r4, r2
    .byte   0x8B, 0x2E    /* bf 0x0602D924 (external) */
