

    .section .text.FUN_06018EAC
    .global cdb_read_status
    .type cdb_read_status, @function

cdb_read_status:
    sts.l   pr, @-r15
    add     #-12, r15
    mov.l   .L_cd_block_read_safe, r3
    jsr     @r3
    mov     r15, r4
    mov     r15, r0
    mov     #31, r4
    mov.b   @r0, r0
    add     #12, r15
    extu.b  r0, r0
    lds.l   @r15+, pr
    and     r0, r4
    rts
    mov     r4, r0

    .global scsp_set_master_volume
    .type scsp_set_master_volume, @function

scsp_set_master_volume:
    mov.w   .L_volume, r4
    mov.l   .L_slot16, r2
    extu.b  r4, r3
    mov.b   r3, @r2
    mov.l   .L_slot17, r3
    rts
    mov.b   r4, @r3

    .align 1
.L_volume:
    .word   0x00E0

    .align 2
.L_cd_block_read_safe:
    .4byte  cd_block_read_safe
.L_slot16:
    .4byte  0x25B00217
.L_slot17:
    .4byte  0x25B00237
