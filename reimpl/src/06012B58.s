	.text
    .global cd_status_reader
cd_status_reader:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06012BC0, r10
    mov #0x1, r12
    mov #0x5, r14
    mov #-0x1, r4
    mov.l   .L_pool_06012BC4, r3
    mov.l r12, @r3
    mov r3, r2
    mov.l   .L_pool_06012BC8, r3
    mov.l r3, @(8, r2)
    mov #0x50, r3
    mov.l r3, @(4, r2)
    mov.l   .L_pool_06012BCC, r11
    bra     .L_06012B8A
    mov #0x0, r13
.L_06012B80:
    mov.l   .L_pool_06012BC4, r6
    mov r11, r5
    jsr @r10
    mov #0x5, r4
    mov r0, r4
.L_06012B8A:
    add #0x1, r13
    cmp/ge r14, r13
    bf      .L_06012B80
    mov #0x2, r3
    mov.l   .L_pool_06012BD0, r13
    cmp/gt r3, r4
    bt      .L_06012B9C
    bra     .L_06012BB0
    mov.b r12, @r13
.L_06012B9C:
    mov.l   .L_pool_06012BD4, r4
    mov.l   .L_pool_06012BD8, r3
    jsr @r3
    nop
    cmp/pz r0
    bt      .L_06012BAC
    bra     .L_06012BB0
    mov.b r12, @r13
.L_06012BAC:
    mov #0x0, r2
    mov.b r2, @r13
.L_06012BB0:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .short  0xFFFF
.L_pool_06012BC0:
    .long  cmd_validate_exec
.L_pool_06012BC4:
    .long  sym_06084360
.L_pool_06012BC8:
    .long  sym_0608436C
.L_pool_06012BCC:
    .long  sym_06083274
.L_pool_06012BD0:
    .long  sym_06084AEC
.L_pool_06012BD4:
    .long  sym_060448C8
.L_pool_06012BD8:
    .long  cmd_status_check
