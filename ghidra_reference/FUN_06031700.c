/* FUN_06031700  0x06031700 */


int FUN_06031700(void)

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
  int unaff_r14;
  int in_stack_00000000;
  
  sVar4 = (*in_r0)();
  iVar8 = (int)-sVar4;
  uVar5 = *(int *)(unaff_r14 + 0x20) - iVar8 & 0xffff;
  if (DAT_06031750 <= uVar5) {
    uVar5 = uVar5 - DAT_06031750;
  }
  uVar6 = unaff_r13[8] - iVar8 & 0xffff;
  if (DAT_06031750 <= uVar6) {
    uVar6 = uVar6 - DAT_06031750;
  }
  uVar5 = (*(int *)(PTR_PTR_06031758 + (uVar5 >> 9) * 4) - unaff_r12) +
          *(int *)(PTR_PTR_06031758 + (uVar6 >> 9) * 4);
  if (0 < (int)uVar5) {
    uVar6 = *(int *)(unaff_r14 + 0x28) - unaff_r13[10] & 0xffff;
    if (((int)DAT_0603178c < (int)uVar6) && ((int)uVar6 < DAT_0603178c * 3)) {
      if ((int)PTR_DAT_06031790 < (int)(*(int *)(unaff_r14 + 0xc) + unaff_r13[3])) {
        *unaff_r13 = *unaff_r13 | DAT_06031794;
      }
    }
    else {
      if ((int)PTR_DAT_060317c8 < (int)(*(int *)(unaff_r14 + 0xc) - unaff_r13[3])) {
        *unaff_r13 = *unaff_r13 | DAT_060317cc;
      }
      uVar6 = *(int *)(unaff_r14 + 0x28) - iVar8 & 0xffff;
      if (((int)uVar6 <= (int)DAT_060317c6) || (DAT_060317c6 * 3 <= (int)uVar6)) {
        unaff_r13[8] = *(uint *)(unaff_r14 + 0x20);
        iVar2 = (*(code *)PTR_FUN_06031880)(uVar6);
        lVar1 = (longlong)(int)(*(int *)(unaff_r14 + 0xc) - unaff_r13[3]) * (longlong)iVar2;
        uVar6 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
        unaff_r13[3] = unaff_r13[3] + uVar6;
        *(uint *)(unaff_r14 + 0xc) = *(int *)(unaff_r14 + 0xc) - uVar6;
      }
    }
    uVar5 = uVar5 >> 1;
    uVar6 = unaff_r13[4];
    uVar7 = unaff_r13[6];
    unaff_r13[0xe] = uVar6;
    unaff_r13[0xf] = uVar7;
    iVar2 = (*(code *)PTR_FUN_06031880)(-iVar8);
    iVar3 = (*DAT_06031884)(-iVar8);
    unaff_r13[4] = uVar6 + ((int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar3) >> 0x20) <<
                            0x10 | (uint)((longlong)extraout_r3 * (longlong)iVar3) >> 0x10);
    lVar1 = (longlong)(int)uVar5 * (longlong)iVar2;
    unaff_r13[6] = uVar7 + ((int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10);
    puVar9 = PTR_DAT_06031888 + iVar8;
    iVar2 = *(int *)(unaff_r14 + 0x10);
    iVar3 = *(int *)(unaff_r14 + 0x18);
    *(int *)(unaff_r14 + 0x38) = iVar2;
    *(int *)(unaff_r14 + 0x3c) = iVar3;
    iVar8 = (*(code *)PTR_FUN_06031880)(-(int)puVar9);
    in_stack_00000000 = (*DAT_06031884)(-(int)puVar9);
    *(uint *)(unaff_r14 + 0x10) =
         iVar2 + ((int)((ulonglong)((longlong)extraout_r3_00 * (longlong)in_stack_00000000) >> 0x20)
                  << 0x10 | (uint)((longlong)extraout_r3_00 * (longlong)in_stack_00000000) >> 0x10);
    lVar1 = (longlong)(int)uVar5 * (longlong)iVar8;
    *(uint *)(unaff_r14 + 0x18) =
         iVar3 + ((int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10);
  }
  return in_stack_00000000;
}

