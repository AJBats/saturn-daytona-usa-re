
    .section .text.FUN_06042646


    .global math_trig_lib
    .type math_trig_lib, @function
math_trig_lib:

    sts.l pr, @-r15
    .byte   0xDB, 0x2D    /* mov.l .L_pool_06042707, r11 */

    cmp/pz r10
    bt/s    .L_x_nonneg
    mov r4, r12
    neg r10, r5
.L_x_nonneg:
    cmp/pz r12
    bt      .L_y_nonneg
    neg r12, r4
.L_y_nonneg:

    mov #0x41, r2
    cmp/ge r2, r5
    bt      .L_do_hw_divide
    .byte   0xDD, 0x29    /* mov.l .L_pool_0604270B, r13 */
    bra     .L_have_tangent_ratio
    nop

.L_do_hw_divide:
    .byte   0xD0, 0x25    /* mov.l .L_pool_06042703, r0 */
    swap.w r4, r2
    mov.l r5, @r0
    exts.w r2, r2
    mov.l r2, @(16, r0)
    shll16 r4
    mov.l r4, @(20, r0)
    mov.l @(20, r0), r13

.L_have_tangent_ratio:
    mov #0x0, r4
    mov #0x5A, r5

.L_bsearch_loop:
    mov r4, r14
    add r5, r14
    shar r14
    mov r14, r0
    shll2 r0
    shll r0
    mov.l @(r0, r11), r2
    cmp/gt r13, r2
    bt      .L_bsearch_go_low

    mov r14, r4
    add #0x1, r4
    mov r4, r0
    shll2 r0
    shll r0
    mov.l @(r0, r11), r3
    cmp/ge r3, r13
    bt      .L_bsearch_check_done
    bra     .L_bsearch_found
    nop

.L_bsearch_go_low:
    mov r14, r5

.L_bsearch_check_done:
    cmp/ge r5, r4
    bf      .L_bsearch_loop

.L_bsearch_found:
    mov r14, r0
    mov r13, r4
    shll2 r0
    shll r0
    mov.l @(r0, r11), r3
    sub r3, r4
    add #0x4, r0
    mov.l @(r0, r11), r5
    dmuls.l r4, r5
    sts mach, r3
    sts macl, r4
    xtrct r3, r4

    .byte   0xD2, 0x12    /* mov.l .L_pool_0604270F, r2 */
    cmp/gt r2, r4
    bf      .L_frac_ok
    .byte   0xD4, 0x11    /* mov.l .L_pool_0604270F, r4 */

.L_frac_ok:
    mov r14, r0
    shll16 r0
    cmp/pz r12
    bt/s    .L_y_was_positive
    add r0, r4
    neg r4, r4

.L_y_was_positive:
    cmp/pz r10
    bt      .L_result_ready

    cmp/pz r12
    bf      .L_x_neg_y_neg

    .byte   0xD2, 0x0C    /* mov.l .L_pool_06042713, r2 */
    bra     .L_apply_quadrant_offset
    nop

.L_x_neg_y_neg:
    .byte   0xD2, 0x0C    /* mov.l .L_pool_06042717, r2 */

.L_apply_quadrant_offset:
    sub r4, r2
    mov r2, r4

.L_result_ready:
    mov r4, r0
    lds.l @r15+, pr
    lds.l @r15+, macl
    lds.l @r15+, mach
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .2byte  0x0009                          /* padding (nop encoding) */

.L_pool_06042703:
    .4byte  0xFFFFFF00                  /* SH-2 division unit base (DVSR register) */
.L_pool_06042707:
    .4byte  sym_06042714                /* pointer to 91-entry tangent lookup table */
.L_pool_0604270B:
    .4byte  0x7FFF0000                  /* tangent clamp: max value when denominator too small (~32767.0) */
.L_pool_0604270F:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) — interpolation clamp */
.L_pool_06042713:
    .4byte  0x00B40000                  /* 180.0 degrees (16.16 FP: 0xB4 = 180 decimal) */
.L_pool_06042717:
    .4byte  0xFF4C0000                  /* -180.0 degrees (16.16 FP: 0xFF4C = -180 as signed 16-bit) */

    .global sym_06042714
sym_06042714:
    .word 0x0000
    .word 0x0000
    .word 0x0039
    .word 0x4A3A
    .word 0x0000
    mul.l r7, r4
    .word 0x0039
    .word 0x414B
    .word 0x0000
    .word 0x08F0
    .word 0x0039
    mov.b r7, @r15
    .word 0x0000
    .word 0x0D6A
    .word 0x0039
    mov.l r10, @(52, r4)
    .word 0x0000
    mov.l r14, @(24, r1)
    .word 0x0038
    .word 0xF10C
    .word 0x0000
    mov.l r6, @(20, r6)
    .word 0x0038
    mov.b @(152, gbr), r0
    .word 0x0000
    mov.l r14, @(32, r10)
    .word 0x0038
    bf/s    .L_tan_entry_deg31
    .word 0x0000
    mov.l r6, @(56, r15)
    .word 0x0038
    mov.l @(0, r7), r1
    .word 0x0000
    xor r15, r3
    .word 0x0038
    .word 0x0AE0
    .word 0x0000
    or r8, r8
    mul.l r3, r0
    .byte   0xBB, 0xC4    /* bsr 0x06041EEE (external) */
    .word 0x0000
    .word 0x2D23
    mul.l r3, r0
    mov.w @r3+, r4
    .word 0x0000
    cmp/hs r12, r1
    mul.l r3, r0
    mac.l @r4+, @r4+
    .word 0x0000
    subc r6, r6
    mov.l r3, @(r0, r0)
    mov.w   .L_wpool_060427E3, r12
    .word 0x0000
    subc r1, r11
    mov.l r3, @(r0, r0)
    mov.l r15, @-r11
    .word 0x0000
    cmp/ge r13, r15
    mov.w r3, @(r0, r0)
    .byte   0xB3, 0xC7    /* bsr 0x06042F1C (external) */
    .word 0x0000
    .word 0x4498
    mov.w r3, @(r0, r0)
    cmp/gt r12, r3
    .word 0x0000
    .word 0x4968
    mov.b r3, @(r0, r0)
    .byte   0xAC, 0x1E    /* bra 0x06041FDA (external) */
    .word 0x0000
    .2byte  0x4E44
    .4byte  0x00341CF7
    .4byte  0x0000532D
    .4byte  0x0033867E
    .4byte  0x00005825
    .4byte  0x0032E8E2
    .4byte  0x00005D2D
    .4byte  0x00324454
    .4byte  0x00006244
    .4byte  0x00319908
    .4byte  0x0000676E
    .4byte  0x0030E733
    .4byte  0x00006CAA
    .4byte  0x00302F0C
    .4byte  0x000071FA
    .4byte  0x002F70CD
.L_wpool_060427E3:
    .2byte  0x0000                      /* 0 */
    .2byte  0x775F
    .4byte  0x002EACB2
    .4byte  0x00007CDC
    .4byte  0x002DE2F7
    .4byte  0x00008270
    .4byte  0x002D13DB
    .4byte  0x0000881E
    .4byte  0x002C3F9F
    .4byte  0x00008DE7
    .4byte  0x002B6686
    .4byte  0x000093CD
    .4byte  0x002A88D2
.L_tan_entry_deg31:
    .word 0x0000
    mov.w   .L_wpool_060429BD, r9
    .word 0x0029
    .byte   0xA6, 0xC9    /* bra 0x060435A8 (external) */
    .word 0x0000
    .2byte  0x9FF7
    .4byte  0x0028C0B2
    .4byte  0x0000A63F
    .4byte  0x0027D6D3
    .4byte  0x0000ACAC
    .4byte  0x0026E978
    .4byte  0x0000B340
    .4byte  0x0025F8E8
    .4byte  0x0000B9FE
    .4byte  0x0025056F
    .4byte  0x0000C0E8
    .4byte  0x00240F5A
    .4byte  0x0000C802
    .4byte  0x002316F5
    .4byte  0x0000CF4E
    .4byte  0x00221C8D
    .4byte  0x0000D6CF
    .4byte  0x00212071
    .4byte  0x0000DE89
    .4byte  0x002022EE
    .4byte  0x0000E680
    .4byte  0x001F2455
    .4byte  0x0000EEB9
    .4byte  0x001E24F5
    .4byte  0x0000F737
    .4byte  0x001D251D
    .4byte  0x00010000
    .4byte  0x001C251D
    .4byte  0x00010918
    .4byte  0x001B2545
    .4byte  0x00011286
    .4byte  0x001A25E5
    .4byte  0x00011C51
    .4byte  0x0019274C
    .4byte  0x0001267E
    .4byte  0x001829C9
    .4byte  0x00013116
    .4byte  0x00172DAD
    .4byte  0x00013C22
    .4byte  0x00163345
    .4byte  0x000147AA
    .4byte  0x00153AE0
    .4byte  0x000153B9
    .4byte  0x001444CB
    .4byte  0x0001605A
    .4byte  0x00135152
    .4byte  0x00016D9B
    .4byte  0x001260C2
    .4byte  0x00017B89
    .4byte  0x00117366
    .4byte  0x00018A34
    .4byte  0x00108988
    .4byte  0x000199AF
    .4byte  0x000FA371
    .4byte  0x0001AA0E
    .4byte  0x000EC168
    .4byte  0x0001BB67
    .4byte  0x000DE3B4
    .4byte  0x0001CDD6
    .4byte  0x000D0A9B
    .4byte  0x0001E177
    .4byte  0x000C365F
    .4byte  0x0001F66D
    .4byte  0x000B6743
    .4byte  0x00020CE0
    .4byte  0x000A9D88
    .4byte  0x000224FE
    .4byte  0x0009D96D
    .4byte  0x00023EFC
    .4byte  0x00091B2E
    .4byte  0x00025B19
    .4byte  0x00086307
    .4byte  0x0002799F
    .4byte  0x0007B132
    .4byte  0x00029AE7
    .4byte  0x000705E6
    .4byte  0x0002BF5A
    .4byte  0x00066158
    .4byte  0x0002E77A
    .4byte  0x0005C3BC
    .4byte  0x000313E3
    .4byte  0x00052D43
    .4byte  0x00034556
    .4byte  0x00049E1C
    .4byte  0x00037CC7
    .4byte  0x00041673
    .4byte  0x0003BB67
    .4byte  0x00039673
    .4byte  0x000402C2
    .4byte  0x00031E44
    .4byte  0x000454DB
    .4byte  0x0002AE0B
    .4byte  0x0004B462
    .4byte  0x000245EB
    .4byte  0x00052501
    .4byte  0x0001E605
    .4byte  0x0005ABD9
    .4byte  0x00018E76
    .4byte  0x00065052
    .4byte  0x00013F5A
    .4byte  0x00071D88
    .4byte  0x0000F8CA
    .4byte  0x000824F3
    .4byte  0x0000BADB
    .2byte  0x0009
.L_wpool_060429BD:
    .2byte  0x83AD
    .4byte  0x000085A2
    .4byte  0x000B6E17
    .4byte  0x0000592D
    .4byte  0x000E4CF8
    .4byte  0x0000358D
    .4byte  0x001314C5
    .4byte  0x00001ACA
    .4byte  0x001CA2E1
    .4byte  0x000008EF
    .4byte  0x00394A3A
    .4byte  0x00000105
    .4byte  0x7FFFFFFF
    .4byte  0x00000000
