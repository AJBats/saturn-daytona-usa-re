/* FUN_0603101E  0x0603101E */


/* WARNING: Type propagation algorithm not settling */

int FUN_0603101e(void)

{
  bool bVar1;
  longlong lVar2;
  code *in_r0;
  short sVar4;
  int iVar3;
  uint uVar5;
  int extraout_r1;
  int iVar6;
  int extraout_r2;
  undefined *extraout_r2_00;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  int unaff_r10;
  undefined *puVar11;
  undefined *unaff_r12;
  uint *unaff_r13;
  uint *unaff_r14;
  undefined8 uVar12;
  undefined *puStack00000000;
  
  sVar4 = (*in_r0)();
  uVar7 = (uint)DAT_060310b8;
  uVar5 = unaff_r14[0xc] - ((uint)(ushort)-sVar4 | uVar7 << 1);
  if ((int)uVar5 < 1) {
    uVar5 = -uVar5;
  }
  uVar5 = (uint)((uVar5 & 0xffff) < uVar7);
  FUN_06031340();
  iVar6 = extraout_r1;
  if (extraout_r1 >= (int)uVar7) {
    iVar6 = extraout_r1 - uVar7;
  }
  uVar10 = (uint)(extraout_r1 < (int)uVar7);
  bVar1 = uVar10 != uVar5;
  uVar12 = (*DAT_060310c0)(iVar6);
  iVar6 = (int)uVar12;
  uVar5 = extraout_r2 - unaff_r10 & 0xffff;
  if ((int)uVar7 <= (int)uVar5) {
    uVar5 = uVar5 - uVar7;
  }
  uVar7 = (uint)((ulonglong)uVar12 >> 0x29);
  iVar9 = 0;
  if ((10 < uVar7) && (uVar7 < 0x37)) {
    iVar9 = 1;
  }
  if (((bVar1) && (uVar10 = (uint)(uVar10 == 0), iVar9 != 0)) ||
     (unaff_r12 = (undefined *)
                  ((*(int *)(PTR_PTR_060310e4 + uVar7 * 4) - (int)unaff_r12) +
                  *(int *)(PTR_PTR_060310e4 + (uVar5 >> 9) * 4)), 0 < (int)unaff_r12)) {
    uVar5 = unaff_r14[10] - unaff_r13[10] & 0xffff;
    if (((int)DAT_0603112e < (int)uVar5) && ((int)uVar5 < DAT_0603112e * 3)) {
      if ((int)PTR_DAT_06031134 < (int)(unaff_r14[3] + unaff_r13[3])) {
        *unaff_r13 = *unaff_r13 | DAT_06031138;
        (*(code *)PTR_FUN_0603113c)();
        *(int *)((int)unaff_r14 + (int)DAT_06031130) = (int)DAT_06031132;
      }
    }
    else {
      puVar11 = PTR_DAT_0603118c;
      if ((int)PTR_DAT_0603118c < (int)(unaff_r14[3] - unaff_r13[3])) {
        *unaff_r13 = *unaff_r13 | DAT_06031190;
        (*(code *)PTR_FUN_06031194)();
        *(int *)((int)unaff_r14 + (int)DAT_06031188) = (int)DAT_0603118a;
        puVar11 = extraout_r2_00;
      }
      if ((iVar9 == 0) && ((int)((uint)puVar11 >> 1) <= (int)(unaff_r14[3] - unaff_r13[3]))) {
        puVar11 = PTR_DAT_06031198;
        if (uVar10 != 0) {
          puVar11 = (undefined *)((uint)PTR_DAT_06031198 >> 1);
        }
        *unaff_r14 = *unaff_r14 | (uint)puVar11;
      }
      else {
        uVar5 = unaff_r14[10] - unaff_r10 & 0xffff;
        if (((int)uVar5 <= (int)DAT_060311b6) || (DAT_060311b6 * 3 <= (int)uVar5)) {
          if (iVar9 != 0) {
            unaff_r13[0xc] = unaff_r14[0xc];
            *(undefined4 *)((int)DAT_06031208 + (int)unaff_r13) = 8;
          }
          iVar3 = (*(code *)PTR_FUN_0603120c)(uVar5);
          lVar2 = (longlong)(int)(unaff_r14[3] - unaff_r13[3] >> 2) * (longlong)iVar3;
          iVar3 = (int)((int)((ulonglong)lVar2 >> 0x20) << 0x10 | (uint)lVar2 >> 0x10) >> 1;
          *(uint *)((int)DAT_0603120a + (int)unaff_r13) = unaff_r13[3] + iVar3;
          unaff_r14[3] = unaff_r14[3] - iVar3;
        }
      }
    }
    if (iVar9 == 0) {
      if (*PTR_DAT_06031210 == '\0') {
        *PTR_DAT_06031210 = 3;
      }
    }
    else {
      if (uVar10 == 0) {
        uVar5 = 0x80;
        pcVar8 = PTR_DAT_06031238 + 1;
        if (*(short *)PTR_DAT_0603123c != 0) {
          uVar5 = (uint)PTR_DAT_06031234._0_2_;
        }
      }
      else {
        uVar5 = 0x40;
        pcVar8 = PTR_DAT_06031238;
        if (*(short *)PTR_DAT_0603123c != 0) {
          uVar5 = (uint)DAT_0603129c;
        }
      }
      *unaff_r14 = *unaff_r14 | uVar5;
      if (*pcVar8 == '\0') {
        *pcVar8 = '\x03';
      }
      iVar9 = (int)DAT_0603129e;
      if (uVar10 == 0) {
        iVar9 = iVar9 * 3;
      }
      unaff_r10 = (unaff_r14[0xc] & 0xffff) + iVar9;
      unaff_r12 = (undefined *)
                  ((int)((ulonglong)((longlong)(int)unaff_r12 * (longlong)iVar6) >> 0x20) << 0x10 |
                  (uint)((longlong)(int)unaff_r12 * (longlong)iVar6) >> 0x10);
      if (bVar1) {
        unaff_r12 = unaff_r12 + (int)PTR_DAT_060312a4;
      }
    }
    if (*(short *)((int)PTR_DAT_060312a0._0_2_ + (int)unaff_r14) < 8) {
      if (*(short *)((int)PTR_DAT_060312a0._0_2_ + (int)unaff_r14) < 6) {
        puStack00000000 = (undefined *)((uint)unaff_r12 >> 2);
        puVar11 = puStack00000000 + ((uint)unaff_r12 >> 1);
      }
      else {
        puStack00000000 = (undefined *)0x0;
        puVar11 = unaff_r12;
      }
    }
    else {
      puVar11 = (undefined *)0x0;
      puStack00000000 = unaff_r12;
    }
    uVar5 = unaff_r13[4];
    uVar7 = unaff_r13[6];
    unaff_r13[0xe] = uVar5;
    unaff_r13[0xf] = uVar7;
    iVar6 = (*(code *)PTR_FUN_06031334)(-unaff_r10);
    iVar9 = (*DAT_06031338)(-unaff_r10);
    unaff_r13[4] = uVar5 + ((int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar9) >> 0x20) <<
                            0x10 | (uint)((longlong)extraout_r3 * (longlong)iVar9) >> 0x10);
    unaff_r13[6] = uVar7 + ((int)((ulonglong)((longlong)(int)puVar11 * (longlong)iVar6) >> 0x20) <<
                            0x10 | (uint)((longlong)(int)puVar11 * (longlong)iVar6) >> 0x10);
    puVar11 = PTR_DAT_0603133c + unaff_r10;
    uVar5 = unaff_r14[4];
    uVar7 = unaff_r14[6];
    unaff_r14[0xe] = uVar5;
    unaff_r14[0xf] = uVar7;
    iVar9 = (*(code *)PTR_FUN_06031334)(-(int)puVar11);
    iVar6 = (*DAT_06031338)(-(int)puVar11);
    unaff_r14[4] = uVar5 + ((int)((ulonglong)((longlong)extraout_r3_00 * (longlong)iVar6) >> 0x20)
                            << 0x10 | (uint)((longlong)extraout_r3_00 * (longlong)iVar6) >> 0x10);
    unaff_r14[6] = uVar7 + ((int)((ulonglong)((longlong)(int)puStack00000000 * (longlong)iVar9) >>
                                 0x20) << 0x10 |
                           (uint)((longlong)(int)puStack00000000 * (longlong)iVar9) >> 0x10);
  }
  return iVar6;
}

