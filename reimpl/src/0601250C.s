
    .section .text.FUN_0601250C


    .global hud_lap_gfx_update
    .type hud_lap_gfx_update, @function
hud_lap_gfx_update:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_06012588, r3
    jsr @r3
    nop
    mov.l   .L_0601258C, r3
    jsr @r3
    nop
    mov.l   .L_06012590, r14
    mov.l   .L_06012594, r3
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_06012598, r4
    mov.l   .L_0601259C, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_060125A0, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_060125A4, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_060125A8, r2
    mov #0x64, r3
    mov.l @r2, r2
    cmp/ge r3, r2
    bf      .L_0601254E
    mov.w   DAT_06012586, r4
    mov.l   .L_060125A4, r3
    jsr @r3
    nop
.L_0601254E:
    mov.l   .L_060125AC, r5
    mov.l   .L_060125B0, r4
    mov.l   .L_060125B4, r3
    mov.l   .L_060125B8, r2
    mov.l @r5, r5
    mov.l @r4, r4
    add #-0x1, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_060125BC, r6
    mov.l   .L_060125C0, r5
    mov.l   .L_060125B0, r4
    mov.l   .L_060125C4, r3
    mov.l   .L_060125C8, r2
    mov.l @r6, r6
    mov.w @r5, r5
    mov.l @r4, r4
    add #-0x1, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l   .L_060125CC, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_06012586
DAT_06012586:
    .2byte  0x1000
.L_06012588:
    .4byte  sym_06026DBC
.L_0601258C:
    .4byte  sym_06026E0C
.L_06012590:
    .4byte  sym_060788B4
.L_06012594:
    .4byte  sym_06026E2E
.L_06012598:
    .4byte  sym_060788B2
.L_0601259C:
    .4byte  mat_rot_z
.L_060125A0:
    .4byte  mat_rot_y
.L_060125A4:
    .4byte  mat_rot_x
.L_060125A8:
    .4byte  sym_0607EBCC
.L_060125AC:
    .4byte  sym_06063558
.L_060125B0:
    .4byte  sym_0607EAD8
.L_060125B4:
    .4byte  sym_0606354C
.L_060125B8:
    .4byte  sym_06031D8C
.L_060125BC:
    .4byte  sym_06063554
.L_060125C0:
    .4byte  sym_06089EA0
.L_060125C4:
    .4byte  sym_06063544
.L_060125C8:
    .4byte  sym_06031A28
.L_060125CC:
    .4byte  sym_06026DF8
