/* FUN_0602E4F4  0x0602E4F4 */


int FUN_0602e4f4(void)

{
  longlong lVar1;
  code *in_r0;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  int unaff_r10;
  int in_stack_00000000;
  
  sVar2 = (*in_r0)();
  sVar2 = -sVar2;
  sVar6 = (short)*(undefined4 *)(PTR_DAT_0602e524._0_2_ + in_stack_00000000);
  sVar7 = sVar2 - sVar6;
  puVar3 = PTR_Onchip_DVSR_0602e534;
  if (((int)sVar7 <= (int)PTR_Onchip_DVSR_0602e534) ||
     (puVar3 = DAT_0602e5ac, (int)DAT_0602e5ac < (int)sVar7)) {
    sVar7 = (short)puVar3;
  }
  iVar4 = (int)(short)(sVar7 + sVar6);
  *(int *)(DAT_0602e5b0 + in_stack_00000000) = iVar4;
  *(int *)(DAT_0602e5b4 + in_stack_00000000) = iVar4;
  lVar1 = (longlong)*(int *)(DAT_0602e5b8 + unaff_r10) * (longlong)DAT_0602e5bc;
  uVar5 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  *(uint *)(DAT_0602e5a2 + in_stack_00000000) = uVar5;
  if (((int)uVar5 < *(int *)(DAT_0602e5a4 + in_stack_00000000)) && (*(int *)PTR_DAT_0602e5c0 == 0))
  {
    *(int *)PTR_DAT_0602e5c0 = (int)DAT_0602e5a6;
    in_stack_00000000 = (*(code *)PTR_FUN_0602e5c4)();
  }
  iVar4 = (int)(short)((sVar2 - (short)*(undefined4 *)(PTR_DAT_0602e5a8._0_2_ + in_stack_00000000))
                      + (short)PTR_DAT_0602e5c8);
  if ((DAT_0602e5cc <= iVar4) && (iVar4 <= (int)PTR_DAT_0602e5d0)) {
    return in_stack_00000000;
  }
  *(int *)(DAT_0602e5e0 + in_stack_00000000) = *(int *)(DAT_0602e5e0 + in_stack_00000000) + 1;
  return in_stack_00000000;
}

