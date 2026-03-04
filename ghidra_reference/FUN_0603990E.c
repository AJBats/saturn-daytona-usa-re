/* FUN_0603990E  0x0603990E */


uint FUN_0603990e(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  byte bVar12;
  uint in_sr;
  uint uVar13;
  uint uVar14;
  
  puVar11 = PTR_DAT_06039a5c;
  puVar7 = PTR_DAT_06039970;
  puVar6 = PTR_DAT_0603996c;
  puVar5 = PTR_DAT_06039968;
  puVar4 = PTR_SMPC_SR_06039964;
  uVar3 = DAT_0603994a;
  uVar8 = in_sr >> 4 & 0xf;
  cVar1 = *PTR_DAT_06039974;
  uVar13 = in_sr & (int)DAT_0603994c & 0xfff0ffe | 0xf0;
  if ((cVar1 == '\0') != 0) {
    *PTR_DAT_06039a5c = *PTR_DAT_06039a60;
    puVar11[1] = *PTR_DAT_06039a64;
    puVar4 = PTR_DAT_06039a5c;
    *(ushort *)(PTR_DAT_06039a5c + 2) = CONCAT11(*PTR_DAT_06039a68,*PTR_DAT_06039a6c);
    *(uint *)(puVar4 + 4) =
         (uint)(byte)*PTR_DAT_06039a70 << 0x18 | (uint)(byte)*PTR_DAT_06039a74 << 0x10 |
         (uint)(byte)*PTR_DAT_06039a78 << 8 | (uint)(byte)*PTR_DAT_06039a7c;
    puVar4[8] = *PTR_DAT_06039a80;
    *PTR_DAT_06039a84 = 1;
    return uVar8 << 4 | (uVar13 | cVar1 == '\0') & (int)DAT_06039a58;
  }
  if (cVar1 == '\x01') {
LAB_06039a14:
    *PTR_DAT_06039968 = 0;
    *(undefined **)puVar7 = PTR_DAT_06039a80;
    while( true ) {
      uVar14 = uVar13 & 0xfffffffe;
      uVar13 = uVar14 | 1 < *(int *)PTR_DAT_06039fc4;
      if (((byte)uVar13 & 1) == 1) break;
      bVar12 = (byte)uVar3;
      if (*(int *)PTR_DAT_06039a90 < 1) {
        bVar2 = **(byte **)puVar7;
        *(uint *)PTR_DAT_06039a90 = bVar2 & 0xf;
        if ((bVar2 & 0xf) == 0) {
          if ((**(byte **)puVar7 & uVar3) == uVar3) {
            (*(code *)PTR_FUN_06039a94)((int)DAT_06039a5a);
            FUN_0603a7b0();
          }
          else {
            (*(code *)PTR_FUN_06039b64)(bVar12);
          }
          iVar9 = *(int *)PTR_DAT_06039b68;
          *(int *)PTR_DAT_06039b68 = iVar9 + 1;
          uVar13 = uVar14 & 0xfffffffe;
          if ((int)(uint)*(ushort *)PTR_DAT_06039b6c <= iVar9 + 1) {
            *puVar5 = 1;
          }
          if (*puVar5 == '\x01') break;
          FUN_06039fe8();
          uVar14 = uVar13 & 0xfffffffe;
          uVar13 = uVar14;
          if (*puVar5 == '\x02') break;
        }
        else {
          *PTR_DAT_06039b70 = 1;
        }
        *(int *)puVar7 = *(int *)puVar7 + 2;
      }
      do {
        do {
          if (*(int *)PTR_DAT_06039fb4 < 1) goto LAB_06039efe;
          uVar13 = uVar14 | *PTR_DAT_06039b70 == '\x01';
          if (((byte)uVar13 & 1) == 1) {
            *PTR_DAT_06039b70 = 0;
            *PTR_DAT_06039b74 = (char)DAT_06039b60;
            if ((**(byte **)puVar7 & uVar3) == uVar3) {
              if ((**(byte **)puVar7 & 0xf) == 0xf) {
                (*(code *)PTR_FUN_06039b64)((int)DAT_06039b60);
              }
              else {
                (*(code *)PTR_FUN_06039b64)(bVar12);
              }
              FUN_0603a7b0();
              iVar9 = *(int *)PTR_DAT_06039b68;
              *(int *)PTR_DAT_06039b68 = iVar9 + 1;
              uVar14 = uVar14 & 0xfffffffe;
              if ((int)(uint)*(ushort *)PTR_DAT_06039b6c <= iVar9 + 1) {
                *puVar5 = 1;
              }
              if (*puVar5 == '\x01') goto LAB_06039efe;
              *PTR_DAT_06039b70 = 1;
              *(int *)PTR_DAT_06039b78 = *(int *)PTR_DAT_06039b78 + -1;
            }
            else {
              if ((**(byte **)puVar7 & uVar3) == DAT_06039c32) {
                if (**(byte **)puVar7 == PTR_DAT_06039c34._0_2_) {
                  FUN_0603ab46(0x20);
                  *PTR_DAT_06039c38 = 0x20;
                }
                else {
                  FUN_0603ab46((int)**(char **)puVar7);
                }
              }
              else {
                FUN_0603ab46(**(byte **)puVar7 & bVar12);
                *PTR_DAT_06039c38 = **(byte **)puVar7 & bVar12;
              }
              uVar14 = uVar14 & 0xfffffffe;
              if ((**(byte **)puVar7 & 0xf) == 0) {
                *PTR_DAT_06039c3c = 1;
              }
              else {
                *(uint *)puVar6 = **(byte **)puVar7 & 0xf;
              }
              if (*PTR_DAT_06039c38 == ' ') {
                *PTR_DAT_06039c44 = *PTR_DAT_06039c40;
                uVar14 = uVar14 | 4 < (byte)*PTR_DAT_06039c40;
                if (((byte)uVar14 & 1) == 1) {
                  *PTR_DAT_06039c40 = *PTR_DAT_06039c40 + -2;
                }
                else {
                  *PTR_DAT_06039c40 = 3;
                }
              }
              *PTR_DAT_06039c48 = 1;
            }
            *(int *)puVar7 = *(int *)puVar7 + 2;
            FUN_06039fe8();
            uVar14 = uVar14 & 0xfffffffe;
            uVar13 = uVar14;
            if (*puVar5 == '\x02') goto LAB_06039efe;
          }
          uVar14 = uVar13 & 0xfffffffe;
          if (*PTR_DAT_06039e30 == '\x01') {
            *PTR_DAT_06039e30 = 0;
            *(uint *)puVar6 = (uint)**(byte **)puVar7;
            *(int *)puVar7 = *(int *)puVar7 + 2;
            FUN_06039fe8();
            uVar14 = uVar14 & 0xfffffffe;
            if (*puVar5 == '\x02') goto LAB_06039efe;
          }
          uVar13 = uVar14 | *PTR_DAT_06039e34 == '\x01';
          if (((byte)uVar13 & 1) == 1) {
            *PTR_DAT_06039e34 = 0;
            if (*(int *)puVar6 < (int)(uint)(byte)*PTR_DAT_06039e38) {
              if (puVar4 < (undefined *)(*(int *)puVar6 * 2 + *(int *)puVar7)) {
                *PTR_DAT_06039e40 = 1;
                *(int *)puVar6 =
                     *(int *)puVar6 -
                     ((int)(((int)puVar4 - *(int *)puVar7) +
                           (uint)((int)puVar4 - *(int *)puVar7 < 0)) >> 1);
                FUN_0603a01c(puVar4);
LAB_06039d78:
                *puVar5 = 2;
                goto LAB_06039efe;
              }
              *PTR_DAT_06039e48 = 1;
              FUN_0603a01c(*(int *)puVar6 * 2 + *(int *)puVar7);
              *(undefined4 *)puVar6 = 0;
              uVar13 = uVar14;
            }
            else if (puVar4 < (undefined *)(*(int *)puVar6 * 2 + *(int *)puVar7)) {
              *PTR_DAT_06039e3c = 1;
              if (puVar4 < (undefined *)((uint)(byte)*PTR_DAT_06039e38 * 2 + *(int *)puVar7)) {
                *PTR_DAT_06039e40 = 1;
                bVar12 = *PTR_DAT_06039e38;
                *(uint *)PTR_DAT_06039e44 = *(int *)puVar6 - (uint)bVar12;
                *(uint *)puVar6 =
                     (uint)bVar12 -
                     ((int)(((int)puVar4 - *(int *)puVar7) +
                           (uint)((int)puVar4 - *(int *)puVar7 < 0)) >> 1);
                FUN_0603a01c(puVar4);
                goto LAB_06039d78;
              }
              *PTR_DAT_06039e48 = 1;
              *(int *)PTR_DAT_06039e44 =
                   *(int *)puVar6 -
                   ((int)(((int)puVar4 - *(int *)puVar7) + (uint)((int)puVar4 - *(int *)puVar7 < 0))
                   >> 1);
              FUN_0603a01c((uint)(byte)*PTR_DAT_06039e38 * 2 + *(int *)puVar7);
              *(undefined **)puVar7 = puVar4;
              uVar13 = uVar14;
            }
            else {
              if (*PTR_DAT_06039e4c == ' ') {
                FUN_0603a01c((uint)(byte)*PTR_DAT_06039e38 * 2 + *(int *)puVar7);
                *(undefined4 *)puVar6 = 0;
              }
              else {
                *PTR_DAT_06039e50 = 2;
                *(undefined4 *)PTR_DAT_06039e54 = *(undefined4 *)puVar7;
                *(int *)puVar7 = *(int *)puVar7 + *(int *)puVar6 * 2;
              }
              *PTR_DAT_06039e48 = 1;
              uVar13 = uVar14;
            }
          }
          uVar14 = uVar13 & 0xfffffffe;
          if (*PTR_DAT_06039e40 == '\x01') {
            *PTR_DAT_06039e40 = 0;
            if (*(int *)puVar6 < 0x20) {
              *PTR_DAT_06039e48 = 1;
              puVar11 = PTR_DAT_06039e58 + *(int *)puVar6 * 2;
              *(undefined4 *)puVar6 = 0;
            }
            else {
              *PTR_DAT_06039e40 = 1;
              *(int *)puVar6 = *(int *)puVar6 + -0x20;
              puVar11 = puVar4;
            }
            while (*(undefined **)puVar7 < puVar11) {
              **(undefined1 **)PTR_DAT_06039e5c = **(undefined1 **)puVar7;
              *(int *)PTR_DAT_06039e5c = *(int *)PTR_DAT_06039e5c + 1;
              *(int *)puVar7 = *(int *)puVar7 + 2;
            }
            FUN_06039fe8();
            uVar14 = uVar14 & 0xfffffffe;
            if (*puVar5 == '\x02') goto LAB_06039efe;
          }
          if (*PTR_DAT_06039e48 == '\x01') {
            *PTR_DAT_06039e48 = 0;
            FUN_0603a0b0();
            iVar9 = *(int *)PTR_DAT_06039e60;
            *(int *)PTR_DAT_06039e60 = iVar9 + 1;
            uVar14 = uVar14 & 0xfffffffe;
            if ((int)(uint)*(ushort *)PTR_DAT_06039e64 <= iVar9 + 1) {
              *puVar5 = 1;
            }
            if (*puVar5 == '\x01') goto LAB_06039efe;
            if (*PTR_DAT_06039fb0 == '\0') {
              *(int *)PTR_DAT_06039fb4 = *(int *)PTR_DAT_06039fb4 + -1;
              *PTR_DAT_06039fb8 = 1;
            }
            FUN_06039fe8();
            uVar14 = uVar14 & 0xfffffffe;
            if (*puVar5 == '\x02') goto LAB_06039efe;
          }
        } while (*PTR_DAT_06039fb0 != '\x01');
        *PTR_DAT_06039fb0 = 0;
        if (*(int *)PTR_DAT_06039fbc < 0x21) {
          *(int *)puVar7 = *(int *)puVar7 + *(int *)PTR_DAT_06039fbc * 2;
          *PTR_DAT_06039fb8 = 1;
          *(int *)PTR_DAT_06039fb4 = *(int *)PTR_DAT_06039fb4 + -1;
          *(undefined4 *)PTR_DAT_06039fbc = 0;
        }
        else {
          *PTR_DAT_06039fc0 = 1;
          *(undefined **)puVar7 = puVar4;
          *(int *)PTR_DAT_06039fbc = *(int *)PTR_DAT_06039fbc + -0x20;
        }
        FUN_06039fe8();
        uVar14 = uVar14 & 0xfffffffe;
      } while (*puVar5 != '\x02');
LAB_06039efe:
      uVar13 = uVar14 & 0xfffffffe | (uint)(*puVar5 == '\0');
      if (((byte)uVar13 & 1) != 1) break;
      *(int *)PTR_DAT_06039fc4 = *(int *)PTR_DAT_06039fc4 + 1;
    }
  }
  else if (cVar1 == '\x02') {
    if (*PTR_DAT_06039a88 != '\0') goto LAB_06039a14;
    uVar14 = 0;
    do {
      iVar9 = 7 - uVar14;
      puVar10 = (undefined1 *)(*(int *)PTR_DAT_06039a8c + uVar14);
      uVar14 = uVar14 + 1;
      *puVar10 = PTR_DAT_06039a80[iVar9 * 2];
    } while (uVar14 < 7);
    *PTR_DAT_06039a88 = 1;
    *puVar5 = 2;
  }
  puVar4 = PTR_DAT_06039fc8;
  cVar1 = *puVar5;
  uVar13 = uVar13 & 0xfffffffe;
  uVar14 = uVar13 | cVar1 == '\0';
  if (((byte)uVar14 & 1) == 1) {
    FUN_0603a766();
  }
  else {
    uVar14 = uVar13 | cVar1 == '\x01';
    if (((byte)uVar14 & 1) != 1) {
      uVar14 = uVar13 | cVar1 == '\x02';
      if (((byte)uVar14 & 1) == 1) {
        *PTR_DAT_06039fc8 = ~*PTR_DAT_06039fc8;
        *PTR_DAT_06039fcc = *puVar4 & 0x80;
      }
      goto LAB_06039f88;
    }
  }
  *PTR_DAT_06039fcc = *PTR_DAT_06039fc8 & 0x80 | 0x40;
LAB_06039f88:
  return uVar8 << 4 | uVar14 & (int)DAT_06039fae;
}

