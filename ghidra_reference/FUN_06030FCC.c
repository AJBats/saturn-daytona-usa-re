/* FUN_06030FCC  0x06030FCC */


/* WARNING: Type propagation algorithm not settling */

int FUN_06030fcc(uint *param_1,uint *param_2,undefined *param_3)

{
  bool bVar1;
  longlong lVar2;
  undefined4 in_r0;
  int iVar3;
  short sVar5;
  int iVar4;
  uint uVar6;
  int extraout_r1;
  int iVar7;
  int extraout_r2;
  undefined *extraout_r2_00;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  undefined4 in_pr;
  undefined8 uVar13;
  
  if ((int)param_2[3] < (int)param_1[3]) {
    sVar5 = (*(code *)PTR_FUN_060310bc)(param_2[4] - param_1[4],param_2[6] - param_1[6]);
    iVar3 = (int)-sVar5;
    sVar5 = (*(code *)PTR_FUN_060310bc)
                      (param_2[0xe] - param_1[0xe],param_2[0xf] - param_1[0xf],param_1[0xe],
                       param_1[0xf],in_pr,in_r0);
    uVar8 = (uint)DAT_060310b8;
    uVar6 = param_1[0xc] - ((uint)(ushort)-sVar5 | uVar8 << 1);
    if ((int)uVar6 < 1) {
      uVar6 = -uVar6;
    }
    uVar6 = (uint)((uVar6 & 0xffff) < uVar8);
    FUN_06031340();
    iVar7 = extraout_r1;
    if (extraout_r1 >= (int)uVar8) {
      iVar7 = extraout_r1 - uVar8;
    }
    uVar11 = (uint)(extraout_r1 < (int)uVar8);
    bVar1 = uVar11 != uVar6;
    uVar13 = (*DAT_060310c0)(iVar7);
    iVar7 = (int)uVar13;
    uVar6 = extraout_r2 - iVar3 & 0xffff;
    if ((int)uVar8 <= (int)uVar6) {
      uVar6 = uVar6 - uVar8;
    }
    uVar8 = (uint)((ulonglong)uVar13 >> 0x29);
    iVar10 = 0;
    if ((10 < uVar8) && (uVar8 < 0x37)) {
      iVar10 = 1;
    }
    if (((bVar1) && (uVar11 = (uint)(uVar11 == 0), iVar10 != 0)) ||
       (param_3 = (undefined *)
                  ((*(int *)(PTR_PTR_060310e4 + uVar8 * 4) - (int)param_3) +
                  *(int *)(PTR_PTR_060310e4 + (uVar6 >> 9) * 4)), 0 < (int)param_3)) {
      uVar6 = param_1[10] - param_2[10] & 0xffff;
      if (((int)DAT_0603112e < (int)uVar6) && ((int)uVar6 < DAT_0603112e * 3)) {
        if ((int)PTR_DAT_06031134 < (int)(param_1[3] + param_2[3])) {
          *param_2 = *param_2 | DAT_06031138;
          (*(code *)PTR_FUN_0603113c)();
          *(int *)((int)param_1 + (int)DAT_06031130) = (int)DAT_06031132;
        }
      }
      else {
        puVar12 = PTR_DAT_0603118c;
        if ((int)PTR_DAT_0603118c < (int)(param_1[3] - param_2[3])) {
          *param_2 = *param_2 | DAT_06031190;
          (*(code *)PTR_FUN_06031194)();
          *(int *)((int)param_1 + (int)DAT_06031188) = (int)DAT_0603118a;
          puVar12 = extraout_r2_00;
        }
        if ((iVar10 == 0) && ((int)((uint)puVar12 >> 1) <= (int)(param_1[3] - param_2[3]))) {
          puVar12 = PTR_DAT_06031198;
          if (uVar11 != 0) {
            puVar12 = (undefined *)((uint)PTR_DAT_06031198 >> 1);
          }
          *param_1 = *param_1 | (uint)puVar12;
        }
        else {
          uVar6 = param_1[10] - iVar3 & 0xffff;
          if (((int)uVar6 <= (int)DAT_060311b6) || (DAT_060311b6 * 3 <= (int)uVar6)) {
            if (iVar10 != 0) {
              param_2[0xc] = param_1[0xc];
              *(undefined4 *)((int)DAT_06031208 + (int)param_2) = 8;
            }
            iVar4 = (*(code *)PTR_FUN_0603120c)(uVar6);
            lVar2 = (longlong)(int)(param_1[3] - param_2[3] >> 2) * (longlong)iVar4;
            iVar4 = (int)((int)((ulonglong)lVar2 >> 0x20) << 0x10 | (uint)lVar2 >> 0x10) >> 1;
            *(uint *)((int)DAT_0603120a + (int)param_2) = param_2[3] + iVar4;
            param_1[3] = param_1[3] - iVar4;
          }
        }
      }
      if (iVar10 == 0) {
        if (*PTR_DAT_06031210 == '\0') {
          *PTR_DAT_06031210 = 3;
        }
      }
      else {
        if (uVar11 == 0) {
          uVar6 = 0x80;
          pcVar9 = PTR_DAT_06031238 + 1;
          if (*(short *)PTR_DAT_0603123c != 0) {
            uVar6 = (uint)PTR_DAT_06031234._0_2_;
          }
        }
        else {
          uVar6 = 0x40;
          pcVar9 = PTR_DAT_06031238;
          if (*(short *)PTR_DAT_0603123c != 0) {
            uVar6 = (uint)DAT_0603129c;
          }
        }
        *param_1 = *param_1 | uVar6;
        if (*pcVar9 == '\0') {
          *pcVar9 = '\x03';
        }
        iVar3 = (int)DAT_0603129e;
        if (uVar11 == 0) {
          iVar3 = iVar3 * 3;
        }
        iVar3 = (param_1[0xc] & 0xffff) + iVar3;
        param_3 = (undefined *)
                  ((int)((ulonglong)((longlong)(int)param_3 * (longlong)iVar7) >> 0x20) << 0x10 |
                  (uint)((longlong)(int)param_3 * (longlong)iVar7) >> 0x10);
        if (bVar1) {
          param_3 = param_3 + (int)PTR_DAT_060312a4;
        }
      }
      if (*(short *)((int)PTR_DAT_060312a0._0_2_ + (int)param_1) < 8) {
        if (*(short *)((int)PTR_DAT_060312a0._0_2_ + (int)param_1) < 6) {
          puVar12 = (undefined *)((uint)param_3 >> 2) + ((uint)param_3 >> 1);
          param_3 = (undefined *)((uint)param_3 >> 2);
        }
        else {
          puVar12 = param_3;
          param_3 = (undefined *)0x0;
        }
      }
      else {
        puVar12 = (undefined *)0x0;
      }
      uVar6 = param_2[4];
      uVar8 = param_2[6];
      param_2[0xe] = uVar6;
      param_2[0xf] = uVar8;
      iVar7 = (*(code *)PTR_FUN_06031334)(-iVar3);
      iVar10 = (*DAT_06031338)(-iVar3);
      param_2[4] = uVar6 + ((int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar10) >> 0x20) <<
                            0x10 | (uint)((longlong)extraout_r3 * (longlong)iVar10) >> 0x10);
      param_2[6] = uVar8 + ((int)((ulonglong)((longlong)(int)puVar12 * (longlong)iVar7) >> 0x20) <<
                            0x10 | (uint)((longlong)(int)puVar12 * (longlong)iVar7) >> 0x10);
      puVar12 = PTR_DAT_0603133c + iVar3;
      uVar6 = param_1[4];
      uVar8 = param_1[6];
      param_1[0xe] = uVar6;
      param_1[0xf] = uVar8;
      iVar3 = (*(code *)PTR_FUN_06031334)(-(int)puVar12);
      iVar7 = (*DAT_06031338)(-(int)puVar12);
      param_1[4] = uVar6 + ((int)((ulonglong)((longlong)extraout_r3_00 * (longlong)iVar7) >> 0x20)
                            << 0x10 | (uint)((longlong)extraout_r3_00 * (longlong)iVar7) >> 0x10);
      param_1[6] = uVar8 + ((int)((ulonglong)((longlong)(int)param_3 * (longlong)iVar3) >> 0x20) <<
                            0x10 | (uint)((longlong)(int)param_3 * (longlong)iVar3) >> 0x10);
    }
    return iVar7;
  }
  iVar3 = FUN_0603136e(param_1,param_2,param_2[4],param_2[6]);
  return iVar3;
}

