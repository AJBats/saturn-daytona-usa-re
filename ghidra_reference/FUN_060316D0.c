/* FUN_060316D0  0x060316D0 */


int FUN_060316d0(int param_1,uint *param_2,int param_3)

{
  longlong lVar1;
  int in_r0;
  int iVar2;
  short sVar5;
  int iVar3;
  int iVar4;
  uint uVar6;
  uint uVar7;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar8;
  undefined *puVar9;
  
  if ((int)param_2[3] < *(int *)(param_1 + 0xc)) {
    sVar5 = (*(code *)PTR_FUN_06031754)
                      (param_2[4] - *(int *)(param_1 + 0x10),param_2[6] - *(int *)(param_1 + 0x18));
    iVar2 = (int)-sVar5;
    uVar6 = *(int *)(param_1 + 0x20) - iVar2 & 0xffff;
    if (DAT_06031750 <= uVar6) {
      uVar6 = uVar6 - DAT_06031750;
    }
    uVar7 = param_2[8] - iVar2 & 0xffff;
    if (DAT_06031750 <= uVar7) {
      uVar7 = uVar7 - DAT_06031750;
    }
    uVar6 = (*(int *)(PTR_PTR_06031758 + (uVar6 >> 9) * 4) - param_3) +
            *(int *)(PTR_PTR_06031758 + (uVar7 >> 9) * 4);
    if (0 < (int)uVar6) {
      uVar7 = *(int *)(param_1 + 0x28) - param_2[10] & 0xffff;
      if (((int)DAT_0603178c < (int)uVar7) && ((int)uVar7 < DAT_0603178c * 3)) {
        if ((int)PTR_DAT_06031790 < (int)(*(int *)(param_1 + 0xc) + param_2[3])) {
          *param_2 = *param_2 | DAT_06031794;
        }
      }
      else {
        if ((int)PTR_DAT_060317c8 < (int)(*(int *)(param_1 + 0xc) - param_2[3])) {
          *param_2 = *param_2 | DAT_060317cc;
        }
        uVar7 = *(int *)(param_1 + 0x28) - iVar2 & 0xffff;
        if (((int)uVar7 <= (int)DAT_060317c6) || (DAT_060317c6 * 3 <= (int)uVar7)) {
          param_2[8] = *(uint *)(param_1 + 0x20);
          iVar3 = (*(code *)PTR_FUN_06031880)(uVar7);
          lVar1 = (longlong)(int)(*(int *)(param_1 + 0xc) - param_2[3]) * (longlong)iVar3;
          uVar7 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
          param_2[3] = param_2[3] + uVar7;
          *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) - uVar7;
        }
      }
      uVar6 = uVar6 >> 1;
      uVar7 = param_2[4];
      uVar8 = param_2[6];
      param_2[0xe] = uVar7;
      param_2[0xf] = uVar8;
      iVar3 = (*(code *)PTR_FUN_06031880)(-iVar2);
      iVar4 = (*DAT_06031884)(-iVar2);
      param_2[4] = uVar7 + ((int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar4) >> 0x20) <<
                            0x10 | (uint)((longlong)extraout_r3 * (longlong)iVar4) >> 0x10);
      lVar1 = (longlong)(int)uVar6 * (longlong)iVar3;
      param_2[6] = uVar8 + ((int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10);
      puVar9 = PTR_DAT_06031888 + iVar2;
      iVar3 = *(int *)(param_1 + 0x10);
      iVar4 = *(int *)(param_1 + 0x18);
      *(int *)(param_1 + 0x38) = iVar3;
      *(int *)(param_1 + 0x3c) = iVar4;
      iVar2 = (*(code *)PTR_FUN_06031880)(-(int)puVar9);
      in_r0 = (*DAT_06031884)(-(int)puVar9);
      *(uint *)(param_1 + 0x10) =
           iVar3 + ((int)((ulonglong)((longlong)extraout_r3_00 * (longlong)in_r0) >> 0x20) << 0x10 |
                   (uint)((longlong)extraout_r3_00 * (longlong)in_r0) >> 0x10);
      lVar1 = (longlong)(int)uVar6 * (longlong)iVar2;
      *(uint *)(param_1 + 0x18) =
           iVar4 + ((int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10);
    }
    return in_r0;
  }
  iVar2 = FUN_0603188c(param_1,param_2,param_2[4],param_2[6]);
  return iVar2;
}

