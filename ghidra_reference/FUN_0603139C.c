/* FUN_0603139C  0x0603139C */


/* WARNING: Type propagation algorithm not settling */

int FUN_0603139c(void)

{
  char cVar1;
  bool bVar2;
  longlong lVar3;
  bool bVar4;
  code *in_r0;
  short sVar6;
  int iVar5;
  uint uVar7;
  int extraout_r1;
  int iVar8;
  int extraout_r2;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  int unaff_r10;
  undefined *puVar13;
  undefined *unaff_r12;
  uint *unaff_r13;
  uint *unaff_r14;
  undefined8 uVar14;
  undefined *puStack00000000;
  
  sVar6 = (*in_r0)();
  uVar9 = (uint)DAT_0603143a;
  uVar7 = (int)(short)unaff_r13[0xc] - ((uint)(ushort)-sVar6 | uVar9 << 1);
  if ((int)uVar7 < 1) {
    uVar7 = -uVar7;
  }
  uVar7 = (uint)((uVar7 & 0xffff) < uVar9);
  FUN_06031340();
  iVar8 = extraout_r1;
  if (extraout_r1 >= (int)uVar9) {
    iVar8 = extraout_r1 - uVar9;
  }
  uVar12 = (uint)(extraout_r1 < (int)uVar9);
  bVar2 = uVar12 != uVar7;
  uVar14 = (*DAT_06031440)(iVar8);
  iVar8 = (int)uVar14;
  uVar7 = extraout_r2 - unaff_r10 & 0xffff;
  if ((int)uVar9 <= (int)uVar7) {
    uVar7 = uVar7 - uVar9;
  }
  uVar9 = (uint)((ulonglong)uVar14 >> 0x29);
  iVar11 = 0;
  if ((10 < uVar9) && (uVar9 < 0x37)) {
    iVar11 = 1;
  }
  if (((bVar2) && (uVar12 = (uint)(uVar12 == 0), iVar11 != 0)) ||
     (unaff_r12 = (undefined *)
                  ((*(int *)(PTR_PTR_06031464 + uVar9 * 4) - (int)unaff_r12) +
                  *(int *)(PTR_PTR_06031464 + (uVar7 >> 9) * 4)), 0 < (int)unaff_r12)) {
    uVar7 = unaff_r14[10] - unaff_r13[10] & 0xffff;
    if (((int)DAT_06031496 < (int)uVar7) && ((int)uVar7 < DAT_06031496 * 3)) {
      bVar4 = true;
      if ((int)PTR_DAT_06031498 < (int)(unaff_r14[3] + unaff_r13[3])) {
        *unaff_r13 = *unaff_r13 | DAT_060314a8;
      }
    }
    else {
      bVar4 = false;
      if ((int)PTR_DAT_060314c8 < (int)(unaff_r13[3] - unaff_r14[3])) {
        *unaff_r13 = *unaff_r13 | DAT_060314cc;
      }
      else if ((iVar11 == 0) &&
              ((int)((uint)PTR_DAT_060314f4 >> 1) <= (int)(unaff_r13[3] - unaff_r14[3]))) {
        puVar13 = PTR_DAT_060314f8;
        if (uVar12 != 0) {
          puVar13 = (undefined *)((uint)PTR_DAT_060314f8 >> 1);
        }
        *unaff_r13 = *unaff_r13 | (uint)puVar13;
      }
      else {
        uVar7 = unaff_r13[10] - unaff_r10 & 0xffff;
        if (((int)uVar7 <= (int)DAT_06031516) || (DAT_06031516 * 3 <= (int)uVar7)) {
          if (iVar11 != 0) {
            unaff_r14[0xc] = unaff_r13[8];
            *(undefined4 *)((int)DAT_0603156a + (int)unaff_r13) = 8;
          }
          iVar5 = (*(code *)PTR_FUN_06031570)(uVar7);
          lVar3 = (longlong)(int)(unaff_r13[3] - unaff_r14[3]) * (longlong)iVar5;
          iVar5 = (int)((int)((ulonglong)lVar3 >> 0x20) << 0x10 | (uint)lVar3 >> 0x10) >> 1;
          unaff_r14[3] = unaff_r14[3] + iVar5;
          *(uint *)((int)PTR_DAT_0603156c._0_2_ + (int)unaff_r13) = unaff_r13[3] - iVar5;
        }
      }
    }
    if (iVar11 == 0) {
      if (*PTR_DAT_06031574 == '\0') {
        *PTR_DAT_06031574 = 3;
      }
    }
    else {
      sVar6 = *(short *)PTR_DAT_06031594;
      pcVar10 = PTR_DAT_06031590;
      if (bVar4) {
        if (uVar12 == 0) {
          uVar7 = 0x80;
          pcVar10 = PTR_DAT_06031590 + 1;
          if (sVar6 != 0) {
            uVar7 = (uint)DAT_060315b0;
          }
        }
        else {
          uVar7 = 0x40;
          if (sVar6 != 0) {
            uVar7 = (uint)DAT_060315be;
          }
        }
      }
      else if (uVar12 == 0) {
        uVar7 = (uint)DAT_0603162a;
        if (sVar6 != 0) {
          uVar7 = 0x40;
        }
      }
      else {
        uVar7 = (uint)DAT_060315ce;
        pcVar10 = PTR_DAT_06031590 + 1;
        if (sVar6 != 0) {
          uVar7 = 0x80;
        }
      }
      cVar1 = *pcVar10;
      *unaff_r14 = *unaff_r14 | uVar7;
      if (cVar1 == '\0') {
        *pcVar10 = '\x03';
      }
      iVar11 = (int)DAT_0603162c;
      if (uVar12 == 0) {
        iVar11 = iVar11 * 3;
      }
      unaff_r10 = (unaff_r13[0xc] & 0xffff) + iVar11;
      unaff_r12 = (undefined *)
                  ((int)((ulonglong)((longlong)(int)unaff_r12 * (longlong)iVar8) >> 0x20) << 0x10 |
                  (uint)((longlong)(int)unaff_r12 * (longlong)iVar8) >> 0x10);
      if (bVar2) {
        unaff_r12 = unaff_r12 + (int)PTR_DAT_06031630;
      }
    }
    if (*(short *)((int)DAT_0603162e + (int)unaff_r14) < 8) {
      if (*(short *)((int)DAT_0603162e + (int)unaff_r14) < 6) {
        puStack00000000 = (undefined *)((uint)unaff_r12 >> 2) + ((uint)unaff_r12 >> 1);
        puVar13 = (undefined *)((uint)unaff_r12 >> 2);
      }
      else {
        puVar13 = (undefined *)0x0;
        puStack00000000 = unaff_r12;
      }
    }
    else {
      puStack00000000 = (undefined *)0x0;
      puVar13 = unaff_r12;
    }
    uVar7 = unaff_r14[4];
    uVar9 = unaff_r14[6];
    unaff_r14[0xe] = uVar7;
    unaff_r14[0xf] = uVar9;
    iVar8 = (*(code *)PTR_FUN_060316b8)(-unaff_r10);
    iVar11 = (*DAT_060316bc)(-unaff_r10);
    unaff_r14[4] = uVar7 + ((int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar11) >> 0x20) <<
                            0x10 | (uint)((longlong)extraout_r3 * (longlong)iVar11) >> 0x10);
    unaff_r14[6] = uVar9 + ((int)((ulonglong)((longlong)(int)puVar13 * (longlong)iVar8) >> 0x20) <<
                            0x10 | (uint)((longlong)(int)puVar13 * (longlong)iVar8) >> 0x10);
    puVar13 = PTR_DAT_060316c0 + unaff_r10;
    uVar7 = unaff_r13[4];
    uVar9 = unaff_r13[6];
    unaff_r13[0xe] = uVar7;
    unaff_r13[0xf] = uVar9;
    iVar11 = (*(code *)PTR_FUN_060316b8)(-(int)puVar13);
    iVar8 = (*DAT_060316bc)(-(int)puVar13);
    unaff_r13[4] = uVar7 + ((int)((ulonglong)((longlong)extraout_r3_00 * (longlong)iVar8) >> 0x20)
                            << 0x10 | (uint)((longlong)extraout_r3_00 * (longlong)iVar8) >> 0x10);
    unaff_r13[6] = uVar9 + ((int)((ulonglong)
                                  ((longlong)(int)(puStack00000000 + ((uint)puStack00000000 >> 1)) *
                                  (longlong)iVar11) >> 0x20) << 0x10 |
                           (uint)((longlong)(int)(puStack00000000 + ((uint)puStack00000000 >> 1)) *
                                 (longlong)iVar11) >> 0x10);
  }
  return iVar8;
}

