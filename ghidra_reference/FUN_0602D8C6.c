/* FUN_0602D8C6  0x0602D8C6 */


void FUN_0602d8c6(void)

{
  longlong lVar1;
  int in_r0;
  int iVar2;
  int iVar3;
  int extraout_r3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_r14;
  
  *(undefined4 *)(in_r0 + 0x20) = *(undefined4 *)(in_r0 + 0x30);
  iVar5 = -*(int *)(in_r0 + 0x28);
  iVar3 = *(int *)(in_r0 + 0xc);
  iVar6 = *(int *)(in_r0 + 0x10);
  iVar7 = *(int *)(in_r0 + 0x18);
  *(int *)(in_r0 + 0x38) = iVar6;
  *(int *)(in_r0 + 0x3c) = iVar7;
  iVar2 = (*(code *)PTR_FUN_0602d91c)();
  iVar5 = (*DAT_0602d920)(iVar5);
  uVar4 = (int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar5) >> 0x20) << 0x10 |
          (uint)((longlong)extraout_r3 * (longlong)iVar5) >> 0x10;
  *(uint *)(DAT_0602d918 + unaff_r14) = uVar4;
  *(uint *)(unaff_r14 + 0x10) = iVar6 + uVar4;
  lVar1 = (longlong)iVar3 * (longlong)iVar2;
  uVar4 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  *(uint *)(DAT_0602d91a + unaff_r14) = uVar4;
  *(uint *)(unaff_r14 + 0x18) = iVar7 + uVar4;
  return;
}

