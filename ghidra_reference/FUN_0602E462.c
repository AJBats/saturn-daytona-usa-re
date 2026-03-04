/* FUN_0602E462  0x0602E462 */


void FUN_0602e462(int param_1)

{
  longlong lVar1;
  int in_r0;
  int iVar2;
  int iVar3;
  int iVar4;
  int extraout_r3;
  uint uVar5;
  int iVar6;
  int iVar7;
  int unaff_r14;
  
  param_1 = -param_1;
  iVar4 = *(int *)(in_r0 + 0xc);
  iVar6 = *(int *)(in_r0 + 0x10);
  iVar7 = *(int *)(in_r0 + 0x18);
  *(int *)(in_r0 + 0x38) = iVar6;
  *(int *)(in_r0 + 0x3c) = iVar7;
  iVar2 = (*(code *)PTR_FUN_0602e4ac)();
  iVar3 = (*DAT_0602e4b0)(param_1);
  uVar5 = (int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar3) >> 0x20) << 0x10 |
          (uint)((longlong)extraout_r3 * (longlong)iVar3) >> 0x10;
  *(uint *)(DAT_0602e4b4 + unaff_r14) = uVar5;
  *(uint *)(unaff_r14 + 0x10) = iVar6 + uVar5;
  lVar1 = (longlong)iVar4 * (longlong)iVar2;
  uVar5 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  *(uint *)(DAT_0602e4b8 + unaff_r14) = uVar5;
  *(uint *)(unaff_r14 + 0x18) = iVar7 + uVar5;
  return;
}

