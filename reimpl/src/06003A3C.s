	.text
    .global master_init_dispatch
master_init_dispatch:
    sts.l pr, @-r15
    mov #0x0, r3
    mov.l   .L_06003AE8, r2
    mov.l r3, @r2
    mov.l   .L_06003AEC, r3
    mov.l   .L_06003AF0, r2
    mov.l r3, @r2
    mov #0x0, r3
    mov.l   .L_06003AF4, r2
    mov.l r3, @r2
    mov.w   .L_06003ADC, r3
    mov.l   .L_06003AF8, r2
    mov.l r3, @r2
    mov #0x1, r3
    mov.l   .L_06003AFC, r2
    mov.l r3, @r2
    mov.w   DAT_06003ade, r7
    mov.l   .L_06003B00, r6
    mov.l   .L_06003B04, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0x8, r5
    mov.w   .L_06003AE0, r7
    mov.l   .L_06003B0C, r6
    mov.l   .L_06003B04, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0x8, r5
    mov #0x3F, r7
    mov.l   .L_06003B10, r6
    mov.l   .L_06003B14, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0x4, r5
    mov #0x61, r7
    mov.l   .L_06003B18, r6
    mov.l   .L_06003B04, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0x8, r5
    mov #0x45, r7
    mov.l   .L_06003B1C, r6
    mov.l   .L_06003B20, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0xC, r5
    mov #0xB, r7
    mov.l   .L_06003B24, r6
    mov.l   .L_06003B28, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0x4, r5
    mov #0x0, r7
    mov.l   .L_06003B2C, r4
    mov.l   .L_06003B08, r3
    mov r7, r6
    jsr @r3
    mov #0x4, r5
    mov #0x34, r7
    mov.l   .L_06003B30, r6
    mov.l   .L_06003B34, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0xC, r5
    mov.w   .L_06003AE2, r7
    mov.l   .L_06003B38, r6
    mov.l   .L_06003B3C, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0x9, r5
    mov.w   .L_06003AE4, r7
    mov.l   .L_06003B40, r6
    mov.l   .L_06003B44, r4
    mov.l   .L_06003B08, r3
    jsr @r3
    mov #0x9, r5
    mov #0x0, r7
    mov r7, r6
    bra     .L_06003B48
    mov #0x8, r5
.L_06003ADC:
    .short  0x0080

    .global DAT_06003ade
DAT_06003ade:
    .short  0x0096
.L_06003AE0:
    .short  0x00A2
.L_06003AE2:
    .short  0x00C9
.L_06003AE4:
    .short  0x02EA
    .short  0xFFFF
.L_06003AE8:
    .long  sym_06063D94
.L_06003AEC:
    .long  sym_060F0000
.L_06003AF0:
    .long  sym_06063D90
.L_06003AF4:
    .long  sym_06059F10
.L_06003AF8:
    .long  sym_06059F18
.L_06003AFC:
    .long  sym_06059F1C
.L_06003B00:
    .long  0x002D0868
.L_06003B04:
    .long  sym_06059EC8
.L_06003B08:
    .long  obj_transform_cache
.L_06003B0C:
    .long  0x002D0108
.L_06003B10:
    .long  sym_060430CE
.L_06003B14:
    .long  0x002BE5F0
.L_06003B18:
    .long  0x002D11A4
.L_06003B1C:
    .long  0x002A0000
.L_06003B20:
    .long  0x002A86F8
.L_06003B24:
    .long  0x002A7D64
.L_06003B28:
    .long  0x002AC382
.L_06003B2C:
    .long  0x002AC390
.L_06003B30:
    .long  0x002A3784
.L_06003B34:
    .long  0x002AA0B0
.L_06003B38:
    .long  0x002A6BCC
.L_06003B3C:
    .long  sym_060EF650
.L_06003B40:
    .long  0x002A3910
.L_06003B44:
    .long  sym_060EE300
.L_06003B48:
    mov.l   .L_06003C1C, r4
    mov.l   .L_06003C20, r3
    jsr @r3
    nop
    mov #0x0, r7
    mov.l   .L_06003C24, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0x8, r5
    mov #0x0, r7
    mov.l   .L_06003C28, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0x8, r5
    mov.w   .L_06003C16, r7
    mov.l   .L_06003C2C, r6
    mov.l   .L_06003C30, r4
    mov.l   .L_06003C20, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C34, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C38, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C3C, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C40, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C44, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C48, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C4C, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C50, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C54, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003C58, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x14, r7
    mov.l   .L_06003C5C, r6
    mov.l   .L_06003C60, r4
    mov.l   .L_06003C20, r3
    jsr @r3
    mov #0x4, r5
    mov #0x0, r7
    mov.l   .L_06003C64, r4
    mov.l   .L_06003C20, r3
    mov r7, r6
    jsr @r3
    mov #0x4, r5
    mov.w   .L_06003C18, r7
    mov.l   .L_06003C68, r6
    mov.l   .L_06003C6C, r4
    mov.l   .L_06003C20, r3
    jsr @r3
    mov #0x9, r5
    mov.w   DAT_06003c1a, r7
    bra     .L_06003C70
    nop
.L_06003C16:
    .short  0x01BB
.L_06003C18:
    .short  0x00DB

    .global DAT_06003c1a
DAT_06003c1a:
    .short  0x013C
.L_06003C1C:
    .long  sym_060EE7D4
.L_06003C20:
    .long  obj_transform_cache
.L_06003C24:
    .long  sym_060EECA8
.L_06003C28:
    .long  sym_060EF17C
.L_06003C2C:
    .long  0x002ADA4C
.L_06003C30:
    .long  0x002B4D1C
.L_06003C34:
    .long  0x002B4D50
.L_06003C38:
    .long  0x002B4D84
.L_06003C3C:
    .long  0x002B4DE4
.L_06003C40:
    .long  0x002B510A
.L_06003C44:
    .long  0x002B517A
.L_06003C48:
    .long  0x002B4DB8
.L_06003C4C:
    .long  0x002B4EAC
.L_06003C50:
    .long  0x002B4FF8
.L_06003C54:
    .long  0x002B5054
.L_06003C58:
    .long  0x002B50B2
.L_06003C5C:
    .long  0x002B43EC
.L_06003C60:
    .long  0x002B7082
.L_06003C64:
    .long  0x002B709A
.L_06003C68:
    .long  0x002B0910
.L_06003C6C:
    .long  sym_06059EC8
.L_06003C70:
    mov.l   .L_06003D3C, r6
    mov.l   .L_06003D40, r4
    mov.l   .L_06003D44, r3
    jsr @r3
    mov #0x9, r5
    mov #0x19, r7
    mov.l   .L_06003D48, r6
    mov.l   .L_06003D40, r4
    mov.l   .L_06003D44, r3
    jsr @r3
    mov #0x8, r5
    mov.w   DAT_06003d36, r7
    mov.l   .L_06003D4C, r6
    mov.l   .L_06003D40, r4
    mov.l   .L_06003D44, r3
    jsr @r3
    mov #0x9, r5
    mov.w   .L_06003D38, r7
    mov.l   .L_06003D50, r6
    mov.l   .L_06003D54, r4
    mov.l   .L_06003D44, r3
    jsr @r3
    mov #0xC, r5
    mov #0x57, r7
    mov.l   .L_06003D58, r6
    mov.l   .L_06003D5C, r4
    mov.l   .L_06003D44, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D60, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D64, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov.w   DAT_06003d3a, r7
    mov.l   .L_06003D68, r6
    mov.l   .L_06003D6C, r4
    mov.l   .L_06003D44, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D70, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D74, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D78, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D7C, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D80, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D84, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003D88, r4
    mov.l   .L_06003D44, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x52, r7
    mov.l   .L_06003D8C, r6
    mov.l   .L_06003D90, r4
    mov.l   .L_06003D44, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov r7, r6
    bra     .L_06003D94
    mov #0xC, r5

    .global DAT_06003d36
DAT_06003d36:
    .short  0x0106
.L_06003D38:
    .short  0x016A

    .global DAT_06003d3a
DAT_06003d3a:
    .short  0x0116
.L_06003D3C:
    .long  0x002B121C
.L_06003D40:
    .long  sym_06059EC8
.L_06003D44:
    .long  obj_transform_cache
.L_06003D48:
    .long  0x002B3550
.L_06003D4C:
    .long  0x002BECFC
.L_06003D50:
    .long  0x002B2300
.L_06003D54:
    .long  0x002B625E
.L_06003D58:
    .long  0x002B04B4
.L_06003D5C:
    .long  0x002B616E
.L_06003D60:
    .long  0x002B61C2
.L_06003D64:
    .long  0x002B6216
.L_06003D68:
    .long  0x002B36B4
.L_06003D6C:
    .long  0x002B6C02
.L_06003D70:
    .long  0x002B6C92
.L_06003D74:
    .long  0x002B6D22
.L_06003D78:
    .long  0x002B6DB2
.L_06003D7C:
    .long  0x002B6E42
.L_06003D80:
    .long  0x002B6ED2
.L_06003D84:
    .long  0x002B6F62
.L_06003D88:
    .long  0x002B6FF2
.L_06003D8C:
    .long  0x002B8EA8
.L_06003D90:
    .long  0x002BE684
.L_06003D94:
    mov.l   .L_06003E68, r4
    mov.l   .L_06003E6C, r3
    jsr @r3
    nop
    mov #0x0, r7
    mov.l   .L_06003E70, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E74, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E78, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov.w   .L_06003E66, r7
    mov.l   .L_06003E7C, r6
    mov.l   .L_06003E80, r4
    mov.l   .L_06003E6C, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E84, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E88, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E8C, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E90, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E94, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E98, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003E9C, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003EA0, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003EA4, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003EA8, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003EAC, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003EB0, r4
    mov.l   .L_06003E6C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov r7, r6
    mov.l   .L_06003EB4, r4
    bra     .L_06003EB8
    mov #0xC, r5
.L_06003E66:
    .short  0x0220
.L_06003E68:
    .long  0x002BE6E8
.L_06003E6C:
    .long  obj_transform_cache
.L_06003E70:
    .long  0x002BE71C
.L_06003E74:
    .long  0x002BE780
.L_06003E78:
    .long  0x002BE7B4
.L_06003E7C:
    .long  0x002ACB58
.L_06003E80:
    .long  0x002B49CC
.L_06003E84:
    .long  0x002B4A80
.L_06003E88:
    .long  0x002B4AB4
.L_06003E8C:
    .long  0x002B4AE8
.L_06003E90:
    .long  0x002B4B1C
.L_06003E94:
    .long  0x002B4B50
.L_06003E98:
    .long  0x002B4B84
.L_06003E9C:
    .long  0x002B4BB8
.L_06003EA0:
    .long  0x002B4BEC
.L_06003EA4:
    .long  0x002B4C20
.L_06003EA8:
    .long  0x002B4C54
.L_06003EAC:
    .long  0x002B4C64
.L_06003EB0:
    .long  0x002B4C70
.L_06003EB4:
    .long  0x002B4CAC
.L_06003EB8:
    mov.l   .L_06003F8C, r3
    jsr @r3
    nop
    mov #0x0, r7
    mov.l   .L_06003F90, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003F94, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003F98, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003F9C, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0x8, r5
    mov.w   .L_06003F88, r5
    mov.l   .L_06003FA0, r4
    mov.l   .L_06003FA4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_06003F88, r5
    mov.l   .L_06003FA8, r4
    mov.l   .L_06003FA4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_06003F88, r5
    mov.l   .L_06003FAC, r4
    mov.l   .L_06003FA4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_06003F88, r5
    mov.l   .L_06003FB0, r4
    mov.l   .L_06003FA4, r3
    jsr @r3
    mov #0x4, r6
    mov #0x49, r7
    mov.l   .L_06003FB4, r6
    mov.l   .L_06003FB8, r4
    mov.l   .L_06003F8C, r3
    jsr @r3
    mov #0xD, r5
    mov #0x14, r7
    mov.l   .L_06003FBC, r6
    mov.l   .L_06003FC0, r4
    mov.l   .L_06003F8C, r3
    jsr @r3
    mov #0x5, r5
    mov #0x0, r7
    mov.l   .L_06003FC4, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0x4, r5
    mov #0x10, r7
    mov.l   .L_06003FC8, r6
    mov.l   .L_06003FCC, r4
    mov.l   .L_06003F8C, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003FD0, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003FD4, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003FD8, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003FD8, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_06003F9C, r4
    mov.l   .L_06003F8C, r3
    mov r7, r6
    jsr @r3
    mov r7, r5
    mov #0x7, r7
    bra     .L_06003FDC
    nop
.L_06003F88:
    .short  0x0A00
    .short  0xFFFF
.L_06003F8C:
    .long  obj_transform_cache
.L_06003F90:
    .long  0x002B4CC8
.L_06003F94:
    .long  0x002B4CE4
.L_06003F98:
    .long  0x002B4D00
.L_06003F9C:
    .long  sym_06059EC8
.L_06003FA0:
    .long  0x002A8964
.L_06003FA4:
    .long  sym_0600508A
.L_06003FA8:
    .long  0x002A8AB8
.L_06003FAC:
    .long  0x002A8C74
.L_06003FB0:
    .long  0x002A8DC8
.L_06003FB4:
    .long  0x002AC63C
.L_06003FB8:
    .long  0x002B4918
.L_06003FBC:
    .long  0x002B43EC
.L_06003FC0:
    .long  0x002B7082
.L_06003FC4:
    .long  0x002B709A
.L_06003FC8:
    .long  0x002B9194
.L_06003FCC:
    .long  0x002BE7DC
.L_06003FD0:
    .long  0x002BE7EC
.L_06003FD4:
    .long  0x002BE7FC
.L_06003FD8:
    .long  0x002BE80C
.L_06003FDC:
    mov.l   .L_060040A4, r6
    mov.l   .L_060040A8, r4
    mov.l   .L_060040AC, r3
    jsr @r3
    mov #0x4, r5
    mov #0x26, r7
    mov.l   .L_060040B0, r6
    mov.l   .L_060040B4, r4
    mov.l   .L_060040AC, r3
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_060040B8, r4
    mov.l   .L_060040AC, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_060040BC, r4
    mov.l   .L_060040AC, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_060040C0, r4
    mov.l   .L_060040AC, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_060040C4, r4
    mov.l   .L_060040AC, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x0, r7
    mov.l   .L_060040C8, r4
    mov.l   .L_060040AC, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r5
    mov #0x1B, r7
    mov.l   .L_060040CC, r6
    mov.l   .L_060040D0, r4
    mov.l   .L_060040AC, r3
    jsr @r3
    mov #0x4, r5
    mov #0x0, r7
    mov.l   .L_060040D4, r4
    mov.l   .L_060040AC, r3
    mov r7, r6
    jsr @r3
    mov #0x4, r5
    mov #0x17, r7
    mov.l   .L_060040D8, r6
    mov.l   .L_060040DC, r4
    mov.l   .L_060040AC, r3
    jsr @r3
    mov #0xC, r5
    mov.w   .L_0600409E, r5
    mov.l   .L_060040E0, r4
    mov.l   .L_060040E4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_0600409E, r5
    mov.l   .L_060040E8, r4
    mov.l   .L_060040E4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_0600409E, r5
    mov.l   .L_060040EC, r4
    mov.l   .L_060040E4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_0600409E, r5
    mov.l   .L_060040F0, r4
    mov.l   .L_060040E4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_0600409E, r5
    mov.l   .L_060040F4, r4
    mov.l   .L_060040E4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   .L_0600409E, r5
    mov.l   .L_060040F8, r4
    mov.l   .L_060040E4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   DAT_060040a0, r5
    mov.l   .L_060040FC, r4
    mov.l   .L_060040E4, r3
    jsr @r3
    mov #0x4, r6
    mov.w   DAT_060040a2, r5
    bra     .L_06004100
    mov #0x4, r6
.L_0600409E:
    .short  0x0BB8

    .global DAT_060040a0
DAT_060040a0:
    .short  0x0C4F

    .global DAT_060040a2
DAT_060040a2:
    .short  0x0D7D
.L_060040A4:
    .long  0x002B8DC8
.L_060040A8:
    .long  0x002BE672
.L_060040AC:
    .long  obj_transform_cache
.L_060040B0:
    .long  0x002B9244
.L_060040B4:
    .long  0x002BE81C
.L_060040B8:
    .long  0x002BE834
.L_060040BC:
    .long  0x002BE84C
.L_060040C0:
    .long  0x002BE864
.L_060040C4:
    .long  0x002BE87C
.L_060040C8:
    .long  0x002BE888
.L_060040CC:
    .long  0x002B943C
.L_060040D0:
    .long  0x002BE894
.L_060040D4:
    .long  0x002BE8B4
.L_060040D8:
    .long  0x002B979C
.L_060040DC:
    .long  0x002BE8D2
.L_060040E0:
    .long  0x002B51EA
.L_060040E4:
    .long  sym_0600508A
.L_060040E8:
    .long  0x002B5B8E
.L_060040EC:
    .long  0x002B5F02
.L_060040F0:
    .long  0x002BDB00
.L_060040F4:
    .long  0x002BDBC4
.L_060040F8:
    .long  0x002BDC04
.L_060040FC:
    .long  0x002BDC50
.L_06004100:
    mov.l   .L_060041C8, r4
    mov.l   .L_060041CC, r3
    jsr @r3
    nop
    mov.w   DAT_060041c2, r5
    mov.l   .L_060041D0, r4
    .long  0xD32F430B
    .long  0xE6049556
    .long  0xD42FD32D
    .long  0x430BE604
    .long  0x9551D42E
    .long  0xD32A430B
    .long  0xE604954C
    .long  0xD42CD328
    .long  0x430BE604
    .long  0x9547D42B
    .long  0xD325430B
    .long  0xE6049542
    .long  0xD429D323
    .long  0x430BE604
    .long  0x953DD428
    .long  0xD320430B
    .long  0xE6049538
    .long  0xD426D31E
    .long  0x430BE604
    .long  0x9533D425
    .long  0xD31B430B
    .long  0xE604952F
    .long  0xD423D319
    .long  0x430BE604
    .long  0x952AD422
    .long  0xD316430B
    .long  0xE6049525
    .long  0xD420D314
    .long  0x430BE604
    .long  0x9520D41F
    .long  0xD311430B
    .long  0xE604E777
    .long  0xD61DD41E
    .long  0xD31E430B
    .long  0xE50CE700
    .long  0xD41DD31C
    .long  0x6673430B
    .long  0xE50CE700
    .long  0xD41BD319
    .long  0x6673430B
    .long  0xE50CE700
    .long  0xD419D316
    .long  0x6673430B
    .long  0xE50CE73C
    .long  0xD617A02F
    .short  0xE50C

    .global DAT_060041c2
DAT_060041c2:
    .short  0x0D7D

    .global DAT_060041c4
DAT_060041c4:
    .long  0x0E4CFFFF
.L_060041C8:
    .long  0x002BE098
.L_060041CC:
    .long  sym_0600508A
.L_060041D0:
    .long  0x002BE10C
    .long  0x002BE180
    .long  0x002BE1F4
    .long  0x002BE268
    .long  0x002BE2DC
    .long  0x002BE350
    .long  0x002BE3C4
    .long  0x002BE438
    .long  0x002BE4AC
    .long  0x002BE520
    .long  0x002BE54C
    .long  0x002BE588
    .long  0x002BE5C4
    .long  0x002A7643
    .long  0x002AC278
    .long  obj_transform_cache
    .long  0x002AC2EA
    .long  0x002AC2A6
    .long  0x002AC326
    .long  0x002B98F0
    .long  0xD432D333
    .long  0x430B0009
    .long  0xE700D432
    .long  0xD3306673
    .long  0x430BE50C
    .long  0xE700D430
    .long  0xD32D6673
    .long  0x430BE50C
    .long  0xE700D42E
    .long  0xD32A6673
    .long  0x430BE50C
    .long  0x954BD42C
    .long  0xD32C430B
    .long  0xE6049547
    .long  0xD42BD32A
    .long  0x430BE604
    .long  0x9542D42A
    .long  0xD327430B
    .long  0xE604953D
    .long  0xD428D325
    .long  0x430BE604
    .long  0x9538D427
    .long  0xD322430B
    .long  0xE6049533
    .long  0xD425D320
    .long  0x430BE604
    .long  0x952ED424
    .long  0xD31D430B
    .long  0xE6049529
    .long  0xD422D31B
    .long  0x430BE604
    .long  0x9524D421
    .long  0xD318430B
    .long  0xE604951F
    .long  0xD41FD316
    .long  0x430BE604
    .long  0x951AD41E
    .long  0xD313430B
    .long  0xE6049515
    .long  0xD41CD311
    .long  0x430BE604
    .long  0x9510D41B
    .long  0xD30E430B
    .long  0xE604950B
    .long  0xD419D30C
    .long  0x430BE604
    .long  0x9506D418
    .long  0xD309430B
    .long  0xE604A02D
    .long  0xE6040A00
    .long  0x0BB8FFFF
    .long  0x002BE90E
    .long  obj_transform_cache
    .long  0x002BE944
    .long  0x002BE97A
    .long  0x002BE9B0
    .long  0x002ED748
    .long  sym_0600508A
    .long  0x002EE0EC
    .long  0x002EE1B0
    .long  0x002EE2B4
    .long  0x002EE3B8
    .long  0x002EE454
    .long  0x002EE4F0
    .long  0x002EE510
    .long  0x002EE53C
    .long  0x002EE56C
    .long  0x002EE594
    .long  0x002EE5A8
    .long  0x002EE5C4
    .long  0x002EE5D8
    .long  0x002EE600
    .long  0x9560D431
    .long  0xD331430B
    .long  0x0009955B
    .long  0xD430D32F
    .long  0x430BE604
    .long  0x9556D42F
    .long  0xD32C430B
    .long  0xE6049551
    .long  0xD42DD32A
    .long  0x430BE604
    .long  0x954CD42C
    .long  0xD327430B
    .long  0xE6049547
    .long  0xD42AD325
    .long  0x430BE604
    .long  0x9542D429
    .long  0xD322430B
    .long  0xE604953D
    .long  0xD427D320
    .long  0x430BE604
    .long  0x9538D426
    .long  0xD31D430B
    .long  0xE6049533
    .long  0xD424D31B
    .long  0x430BE604
    .long  0x952ED423
    .long  0xD318430B
    .long  0xE6049529
    .long  0xD421D316
    .long  0x430BE604
    .long  0x9524D420
    .long  0xD313430B
    .long  0xE604951F
    .long  0xD41ED311
    .long  0x430BE604
    .long  0x951AD41D
    .long  0xD30E430B
    .long  0xE6049515
    .long  0xD41BD30C
    .long  0x430BE604
    .long  0x9510D41A
    .long  0xD309430B
    .long  0xE604950B
    .long  0xD418D307
    .long  0x430BE604
    .long  0x9506D417
    .long  0xD304430B
    .long  0xE6049501
    .long  0xA02AE604
    .long  0x0BB8FFFF
    .long  0x002EE620
    .long  sym_0600508A
    .long  0x002EE648
    .long  0x002EE72C
    .long  0x002EE738
    .long  0x002EE744
    .long  0x002EE770
    .long  0x002EE79C
    .long  0x002EE7C8
    .long  0x002EE7F4
    .long  0x002EE820
    .long  0x002EE84C
    .long  0x002EE878
    .long  0x002EE8A4
    .long  0x002EE8D0
    .long  0x002EE8FC
    .long  0x002EE928
    .long  0x002EE954
    .long  0x002EE980
    .long  0x002EE9AC
    .long  0xD430D331
    .long  0x430B0009
    .long  0x955BD430
    .long  0xD32E430B
    .long  0xE6049556
    .long  0xD42ED32C
    .long  0x430BE604
    .long  0x9551D42D
    .long  0xD329430B
    .long  0xE604954C
    .long  0xD42BD327
    .long  0x430BE604
    .long  0x9547D42A
    .long  0xD324430B
    .long  0xE6049542
    .long  0xD428D322
    .long  0x430BE604
    .long  0x953DD427
    .long  0xD31F430B
    .long  0xE6049538
    .long  0xD425D31D
    .long  0x430BE604
    .long  0x9533D424
    .long  0xD31A430B
    .long  0xE604952E
    .long  0xD422D318
    .long  0x430BE604
    .long  0x9529D421
    .long  0xD315430B
    .long  0xE6049524
    .long  0xD41FD313
    .long  0x430BE604
    .long  0x951FD41E
    .long  0xD310430B
    .long  0xE604951A
    .long  0xD41CD30E
    .long  0x430BE604
    .long  0x9515D41B
    .long  0xD30B430B
    .long  0xE6049510
    .long  0xD419D309
    .long  0x430BE604
    .long  0x950BD418
    .long  0xD306430B
    .long  0xE6049506
    .long  0xD416D304
    .long  0x430BE604
    .long  0x9501A029
    .long  0xE6040BB8
    .long  0x002EE9C8
    .long  sym_0600508A
    .long  0x002EE9DE
    .long  0x002EE9F4
    .long  0x002EEA10
    .long  0x002EEA2C
    .long  0x002EEA3C
    .long  0x002EEA48
    .long  0x002EEA6A
    .long  0x002EEA86
    .long  0x002EEAB2
    .long  0x002EEAC2
    .long  0x002EEAD6
    .long  0x002EEAFE
    .long  0x002EEB0E
    .long  0x002EEB22
    .long  0x002EEB4A
    .long  0x002EEB60
    .long  0x002EEB76
    .long  0x002EF51A
    .long  0xD429D32A
    .long  0x430B0009
    .long  0x974AD629
    .long  0xD429D32A
    .long  0x430BE509
    .long  0x9745D629
    .long  0xD429D327
    .long  0x430BE509
    .long  0x9540D428
    .long  0xD321430B
    .long  0xE604953B
    .long  0xD426D31F
    .long  0x430BE604
    .long  0x9536D425
    .long  0xD31C430B
    .long  0xE604E71F
    .long  0xD623D424
    .long  0xD31C430B
    .long  0xE50CE70A
    .long  0xD622D423
    .long  0xD319430B
    .long  0xE505E703
    .long  0xD621D422
    .long  0xD316430B
    .long  0xE500E700
    .long  0xD420D314
    .long  0x6673430B
    .long  0x6573E712
    .long  0xD61ED41F
    .long  0xD310430B
    .long  0xE5049514
    .long  0xD41DD30B
    .long  0x430BE604
    .long  0x950FD41C
    .long  0xD308430B
    .long  0xE604E706
    .long  0xD61AD41B
    .long  0xD308430B
    .long  0xE5004F26
    .long  0x000B0009
    .long  0x00A201C8

    .global DAT_06004610
DAT_06004610:
    .short  0x0E95

    .global DAT_06004612
DAT_06004612:
    .short  0x0B5E
    .long  0x002BE9E6
    .long  sym_0600508A
    .long  0x002BCF4C
    .long  sym_060438CE
    .long  obj_transform_cache
    .long  0x002BA314
    .long  sym_06044272
    .long  0x002BEB8E
    .long  0x002BEC32
    .long  0x002BECEA
    .long  0x002B47AC
    .long  0x002B70CA
    .long  0x002B466C
    .long  0x002B70B2
    .long  sym_0605E0E8
    .long  sym_0605E148
    .long  sym_0605E150
    .long  0x002ED508
    .long  0x002EFEBE
    .long  0x002AC3A0
    .long  0x002AC4BC
    .long  sym_06059E08
    .long  sym_06059DF8
