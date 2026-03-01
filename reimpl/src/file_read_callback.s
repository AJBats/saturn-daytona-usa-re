
    .section .text.FUN_060120CC


    .global file_read_callback
    .type file_read_callback, @function
file_read_callback:
    sts.l pr, @-r15
    mov #0x0, r14
    mov.l   .L_pool_06012150, r2
    mov r14, r6
    mov r14, r5
    mov.b r3, @r2
    mov.l   .L_pool_06012154, r3
    mov.l r14, @r3
    mov.l   .L_pool_06012158, r3
    jsr @r3
    mov #0x20, r4
    mov.l   .L_pool_0601215C, r4
    mov.l r14, @r4
    mov.l   .L_06012160, r2
    mov.l r2, @(4, r4)
    shlr2 r2
    mov.l   .L_pool_06012164, r3
    mov.l r3, @(8, r4)
    mov.l   .L_pool_06012168, r4
    mov.l r14, @r4
    mov.l r2, @(4, r4)
    mov r4, r2
    mov.l   .L_pool_0601216C, r3
    mov.l r3, @(8, r4)
    mov.l   .L_pool_06012170, r1
    mov.l   .L_pool_06012174, r3
    jsr @r3
    mov #0xC, r0
    mov.l   .L_pool_06012178, r1
    mov.l   .L_pool_06012174, r3
    jsr @r3
    mov #0xC, r0
    mov.l   .L_pool_0601217C, r1
    mov.l   .L_pool_06012174, r3
    jsr @r3
    mov #0xC, r0
    mov.w   DAT_0601214e, r2
    extu.b r14, r1
    mov.l   .L_pool_06012180, r3
    mov.w r2, @r3
    exts.w r14, r2
    mov.l   .L_pool_06012184, r3
    mov.w r2, @r3
    mov.l   .L_pool_06012188, r3
    mov.b r1, @r3
    mov.l   .L_pool_0601218C, r5
    mov.l   .L_pool_06012190, r4
    mov.l   .L_pool_06012194, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601213A
    mov #0x3C, r3
    mov.l r3, @r4
    bra     .L_06012148
    mov.l r14, @r5
.L_0601213A:
    mov #0x1, r2
    mov.l r2, @r4
    mov #0x14, r3
    mov.l r3, @r5
    lds.l @r15+, pr
    .byte   0xA0, 0xA1    /* bra 0x0601228A (external) */
    mov.l @r15+, r14
.L_06012148:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0601214e
DAT_0601214e:
    .2byte  0x1000                          /* initial animation counter value */
.L_pool_06012150:
    .4byte  sym_06078636                    /* replay mode flag (byte) */
.L_pool_06012154:
    .4byte  sym_060788F8                    /* menu scroll position (dword) */
.L_pool_06012158:
    .4byte  display_channel_b               /* display channel enable function */
.L_pool_0601215C:
    .4byte  sym_060788B4                    /* position vector A: primary HUD element XYZ */
.L_06012160:
    .4byte  0x00080000                      /* 8.0 (16.16 fixed-point) */
.L_pool_06012164:
    .4byte  0x000F3333                      /* ~15.2 (16.16 fixed-point) */
.L_pool_06012168:
    .4byte  sym_060788C0                    /* position vector B: secondary HUD element XYZ */
.L_pool_0601216C:
    .4byte  0x00053333                      /* ~5.2 (16.16 fixed-point) */
.L_pool_06012170:
    .4byte  sym_060788CC                    /* position vector C (initialized as copy of B) */
.L_pool_06012174:
    .4byte  sym_06035168                    /* memcpy_long(r0=nbytes, r1=dst, r2=src) */
.L_pool_06012178:
    .4byte  sym_060788D8                    /* position vector D (initialized as copy of B) */
.L_pool_0601217C:
    .4byte  sym_060788E4                    /* position vector E (initialized as copy of B) */
.L_pool_06012180:
    .4byte  sym_060788B0                    /* animation counter (16-bit) */
.L_pool_06012184:
    .4byte  sym_060788B2                    /* Z rotation angle state (16-bit) */
.L_pool_06012188:
    .4byte  sym_060788F0                    /* file read initialized flag (byte) */
.L_pool_0601218C:
    .4byte  sym_060788F4                    /* menu state counter (dword) */
.L_pool_06012190:
    .4byte  sym_060788AC                    /* frame timer / state counter (dword) */
.L_pool_06012194:
    .4byte  sym_0607EAD8                    /* race end state (0=racing, nonzero=ended) */

    .global sym_06012198
sym_06012198:
    .byte   0xD0, 0x21    /* mov.l .L_pool_06012220, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_060121A4
    .byte   0xA0, 0x73    /* bra 0x0601228A (external) */
    nop
.L_060121A4:
    .byte   0xA3, 0x1C    /* bra 0x060127E0 (external) */
    nop
