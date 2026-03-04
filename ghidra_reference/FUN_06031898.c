/* FUN_06031898  0x06031898 */


int FUN_06031898(void)

{
  longlong lVar1;
  code *in_r0;
  short sVar4;
  int iVar2;
  int iVar3;
  uint uVar5;
  uint uVar6;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  int unaff_r12;
  uint *unaff_r13;
  uint *unaff_r14;
  int in_stack_00000000;
  
  sVar4 = (*in_r0)();
  iVar8 = (int)-sVar4;
  uVar7 = (uint)DAT_060318e4;
  uVar5 = unaff_r14[8] - iVar8 & 0xffff;
  if (uVar7 <= uVar5) {
    uVar5 = uVar5 - uVar7;
  }
  uVar6 = unaff_r13[8] - iVar8 & 0xffff;
  if (uVar7 <= uVar6) {
    uVar6 = uVar6 - uVar7;
  }
  uVar5 = (*(int *)(PTR_PTR_060318ec + (uVar5 >> 9) * 4) - unaff_r12) +
          *(int *)(PTR_PTR_060318ec + (uVar6 >> 9) * 4);
  if (0 < (int)uVar5) {
    uVar7 = unaff_r14[10] - unaff_r13[10] & 0xffff;
    if (((int)DAT_06031918 < (int)uVar7) && ((int)uVar7 < DAT_06031918 * 3)) {
      if ((int)PTR_DAT_0603191c < (int)(unaff_r14[3] + unaff_r13[3])) {
        uVar7 = *unaff_r14 | DAT_06031934;
        *unaff_r13 = *unaff_r13 | DAT_06031934;
        *unaff_r14 = uVar7;
      }
    }
    else {
      if ((int)PTR_DAT_06031970 < (int)(unaff_r13[3] - unaff_r14[3])) {
        uVar7 = *unaff_r14 | DAT_06031974;
        *unaff_r13 = *unaff_r13 | DAT_06031974;
        *unaff_r14 = uVar7;
      }
      uVar7 = unaff_r13[10] - iVar8 & 0xffff;
      if (((int)uVar7 <= (int)DAT_0603196c) || (DAT_0603196c * 3 <= (int)uVar7)) {
        uVar6 = unaff_r13[8];
        unaff_r14[8] = uVar6;
        unaff_r14[10] = uVar6;
        iVar2 = (*(code *)PTR_FUN_06031a18)(uVar7);
        lVar1 = (longlong)(int)(unaff_r13[3] - unaff_r14[3]) * (longlong)iVar2;
        uVar7 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
        unaff_r14[3] = unaff_r14[3] + uVar7;
        unaff_r13[3] = unaff_r13[3] - uVar7;
      }
    }
    uVar5 = uVar5 >> 1;
    uVar7 = unaff_r14[4];
    uVar6 = unaff_r14[6];
    unaff_r14[0xe] = uVar7;
    unaff_r14[0xf] = uVar6;
    iVar2 = (*(code *)PTR_FUN_06031a18)(-iVar8);
    iVar3 = (*DAT_06031a1c)(-iVar8);
    unaff_r14[4] = uVar7 + ((int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar3) >> 0x20) <<
                            0x10 | (uint)((longlong)extraout_r3 * (longlong)iVar3) >> 0x10);
    lVar1 = (longlong)(int)uVar5 * (longlong)iVar2;
    unaff_r14[6] = uVar6 + ((int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10);
    puVar9 = PTR_DAT_06031a20 + iVar8;
    uVar7 = unaff_r13[4];
    uVar6 = unaff_r13[6];
    unaff_r13[0xe] = uVar7;
    unaff_r13[0xf] = uVar6;
    iVar8 = (*(code *)PTR_FUN_06031a18)(-(int)puVar9);
    in_stack_00000000 = (*DAT_06031a1c)(-(int)puVar9);
    unaff_r13[4] = uVar7 + ((int)((ulonglong)
                                  ((longlong)extraout_r3_00 * (longlong)in_stack_00000000) >> 0x20)
                            << 0x10 |
                           (uint)((longlong)extraout_r3_00 * (longlong)in_stack_00000000) >> 0x10);
    lVar1 = (longlong)(int)uVar5 * (longlong)iVar8;
    unaff_r13[6] = uVar6 + ((int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10);
  }
  return in_stack_00000000;
}

