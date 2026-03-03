	.text
    .global dma_vram_init
dma_vram_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_06003960, r14
    mov.l   .L_06003964, r5
    mov.l   .L_06003968, r4
    jsr @r14
    mov #0x60, r6
    mov #0x40, r6
    mov.l   .L_0600396C, r3
    mov.l r3, @(8, r15)
    mov.l   .L_06003970, r4
    jsr @r14
    mov r3, r5
    mov.l   .L_06003974, r5
    mov.l   .L_06003978, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0600397C, r5
    mov.l   .L_06003980, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_06003984, r5
    mov.l   .L_06003988, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0600398C, r5
    mov.l   .L_06003990, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_06003994, r5
    mov.l   .L_06003998, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0600399C, r5
    mov.l   .L_060039A0, r4
    jsr @r14
    mov #0x20, r6
    mov #0x20, r6
    mov.l   .L_060039A4, r3
    mov.l r3, @r15
    mov.l   .L_060039A8, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_060039AC, r3
    mov.l r3, @(4, r15)
    mov.l   .L_060039B0, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_060039B4, r4
    jsr @r14
    mov.l @(8, r15), r5
    mov.l   .L_060039B8, r5
    mov.l   .L_060039BC, r4
    jsr @r14
    mov #0x60, r6
    mov #0x20, r6
    mov.l   .L_060039C0, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x40, r6
    mov.l   .L_060039C4, r4
    jsr @r14
    mov.l @(4, r15), r5
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06003960:
    .long  dma_transfer
.L_06003964:
    .long  sym_0604814C
.L_06003968:
    .long  0x25F00000
.L_0600396C:
    .long  sym_0604848C
.L_06003970:
    .long  0x25F00060
.L_06003974:
    .long  sym_060484CC
.L_06003978:
    .long  0x25F000A0
.L_0600397C:
    .long  sym_060485AC
.L_06003980:
    .long  0x25F000E0
.L_06003984:
    .long  sym_0604892C
.L_06003988:
    .long  0x25F00100
.L_0600398C:
    .long  sym_060488EC
.L_06003990:
    .long  0x25F00120
.L_06003994:
    .long  sym_0604890C
.L_06003998:
    .long  0x25F00140
.L_0600399C:
    .long  sym_0605CDBC
.L_060039A0:
    .long  0x25F00160
.L_060039A4:
    .long  sym_060487EC
.L_060039A8:
    .long  0x25F001A0
.L_060039AC:
    .long  sym_060483EC
.L_060039B0:
    .long  0x25F001C0
.L_060039B4:
    .long  0x25F00600
.L_060039B8:
    .long  sym_0604888C
.L_060039BC:
    .long  0x25F00660
.L_060039C0:
    .long  0x25F007A0
.L_060039C4:
    .long  0x25F007C0
