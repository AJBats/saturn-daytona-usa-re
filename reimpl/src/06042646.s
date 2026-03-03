	.text
    .global math_trig_lib
math_trig_lib:

    sts.l pr, @-r15
    .byte   0xDB, 0x2D    /* mov.l .L_pool_06042707, r11 */

    cmp/pz r10
    bt.s    .L_06042652
    mov r4, r12
    neg r10, r5
.L_06042652:
    cmp/pz r12
    bt      .L_06042658
    neg r12, r4
.L_06042658:

    mov #0x41, r2
    cmp/ge r2, r5
    bt      .L_06042664
    .byte   0xDD, 0x29    /* mov.l .L_pool_0604270B, r13 */
    bra     .L_06042674
    nop

.L_06042664:
    .byte   0xD0, 0x25    /* mov.l .L_pool_06042703, r0 */
    swap.w r4, r2
    mov.l r5, @r0
    exts.w r2, r2
    mov.l r2, @(16, r0)
    shll16 r4
    mov.l r4, @(20, r0)
    mov.l @(20, r0), r13

.L_06042674:
    mov #0x0, r4
    mov #0x5A, r5

.L_06042678:
    mov r4, r14
    add r5, r14
    shar r14
    mov r14, r0
    shll2 r0
    shll r0
    mov.l @(r0, r11), r2
    cmp/gt r13, r2
    bt      .L_0604269E

    mov r14, r4
    add #0x1, r4
    mov r4, r0
    shll2 r0
    shll r0
    mov.l @(r0, r11), r3
    cmp/ge r3, r13
    bt      .L_060426A0
    bra     .L_060426A4
    nop

.L_0604269E:
    mov r14, r5

.L_060426A0:
    cmp/ge r5, r4
    bf      .L_06042678

.L_060426A4:
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
    bf      .L_060426C4
    .byte   0xD4, 0x11    /* mov.l .L_pool_0604270F, r4 */

.L_060426C4:
    mov r14, r0
    shll16 r0
    cmp/pz r12
    bt.s    .L_060426D0
    add r0, r4
    neg r4, r4

.L_060426D0:
    cmp/pz r10
    bt      .L_060426E4

    cmp/pz r12
    bf      .L_060426DE

    .byte   0xD2, 0x0C    /* mov.l .L_pool_06042713, r2 */
    bra     .L_060426E0
    nop

.L_060426DE:
    .byte   0xD2, 0x0C    /* mov.l .L_pool_06042717, r2 */

.L_060426E0:
    sub r4, r2
    mov r2, r4

.L_060426E4:
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

    .short  0x0009                          /* padding (nop encoding) */

.L_pool_06042703:
    .long  0xFFFFFF00
.L_pool_06042707:
    .long  sym_06042714
.L_pool_0604270B:
    .long  0x7FFF0000
.L_pool_0604270F:
    .long  0x00010000
.L_pool_06042713:
    .long  0x00B40000
.L_pool_06042717:
    .long  0xFF4C0000

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
    bf.s    .L_0604280C
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
    .short  0x4E44
    .long  0x00341CF7
    .long  0x0000532D
    .long  0x0033867E
    .long  0x00005825
    .long  0x0032E8E2
    .long  0x00005D2D
    .long  0x00324454
    .long  0x00006244
    .long  0x00319908
    .long  0x0000676E
    .long  0x0030E733
    .long  0x00006CAA
    .long  0x00302F0C
    .long  0x000071FA
    .long  0x002F70CD
.L_wpool_060427E3:
    .short  0x0000
    .short  0x775F
    .long  0x002EACB2
    .long  0x00007CDC
    .long  0x002DE2F7
    .long  0x00008270
    .long  0x002D13DB
    .long  0x0000881E
    .long  0x002C3F9F
    .long  0x00008DE7
    .long  0x002B6686
    .long  0x000093CD
    .long  0x002A88D2
.L_0604280C:
    .word 0x0000
    mov.w   .L_wpool_060429BD, r9
    .word 0x0029
    .byte   0xA6, 0xC9    /* bra 0x060435A8 (external) */
    .word 0x0000
    .short  0x9FF7
    .long  0x0028C0B2
    .long  0x0000A63F
    .long  0x0027D6D3
    .long  0x0000ACAC
    .long  0x0026E978
    .long  0x0000B340
    .long  0x0025F8E8
    .long  0x0000B9FE
    .long  0x0025056F
    .long  0x0000C0E8
    .long  0x00240F5A
    .long  0x0000C802
    .long  0x002316F5
    .long  0x0000CF4E
    .long  0x00221C8D
    .long  0x0000D6CF
    .long  0x00212071
    .long  0x0000DE89
    .long  0x002022EE
    .long  0x0000E680
    .long  0x001F2455
    .long  0x0000EEB9
    .long  0x001E24F5
    .long  0x0000F737
    .long  0x001D251D
    .long  0x00010000
    .long  0x001C251D
    .long  0x00010918
    .long  0x001B2545
    .long  0x00011286
    .long  0x001A25E5
    .long  0x00011C51
    .long  0x0019274C
    .long  0x0001267E
    .long  0x001829C9
    .long  0x00013116
    .long  0x00172DAD
    .long  0x00013C22
    .long  0x00163345
    .long  0x000147AA
    .long  0x00153AE0
    .long  0x000153B9
    .long  0x001444CB
    .long  0x0001605A
    .long  0x00135152
    .long  0x00016D9B
    .long  0x001260C2
    .long  0x00017B89
    .long  0x00117366
    .long  0x00018A34
    .long  0x00108988
    .long  0x000199AF
    .long  0x000FA371
    .long  0x0001AA0E
    .long  0x000EC168
    .long  0x0001BB67
    .long  0x000DE3B4
    .long  0x0001CDD6
    .long  0x000D0A9B
    .long  0x0001E177
    .long  0x000C365F
    .long  0x0001F66D
    .long  0x000B6743
    .long  0x00020CE0
    .long  0x000A9D88
    .long  0x000224FE
    .long  0x0009D96D
    .long  0x00023EFC
    .long  0x00091B2E
    .long  0x00025B19
    .long  0x00086307
    .long  0x0002799F
    .long  0x0007B132
    .long  0x00029AE7
    .long  0x000705E6
    .long  0x0002BF5A
    .long  0x00066158
    .long  0x0002E77A
    .long  0x0005C3BC
    .long  0x000313E3
    .long  0x00052D43
    .long  0x00034556
    .long  0x00049E1C
    .long  0x00037CC7
    .long  0x00041673
    .long  0x0003BB67
    .long  0x00039673
    .long  0x000402C2
    .long  0x00031E44
    .long  0x000454DB
    .long  0x0002AE0B
    .long  0x0004B462
    .long  0x000245EB
    .long  0x00052501
    .long  0x0001E605
    .long  0x0005ABD9
    .long  0x00018E76
    .long  0x00065052
    .long  0x00013F5A
    .long  0x00071D88
    .long  0x0000F8CA
    .long  0x000824F3
    .long  0x0000BADB
    .short  0x0009
.L_wpool_060429BD:
    .short  0x83AD
    .long  0x000085A2
    .long  0x000B6E17
    .long  0x0000592D
    .long  0x000E4CF8
    .long  0x0000358D
    .long  0x001314C5
    .long  0x00001ACA
    .long  0x001CA2E1
    .long  0x000008EF
    .long  0x00394A3A
    .long  0x00000105
    .long  0x7FFFFFFF
    .long  0x00000000
