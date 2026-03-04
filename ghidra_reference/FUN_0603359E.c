/* FUN_0603359E  0x0603359E */


undefined4 FUN_0603359e(void)

{
  code *in_r0;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 in_r7;
  int unaff_r14;
  undefined8 uVar4;
  undefined4 in_stack_00000000;
  
  iVar1 = (*in_r0)();
  iVar2 = (*(code *)PTR_FUN_060335f0)(extraout_r2);
  uVar4 = (*(code *)PTR_FUN_060335f0)(extraout_r2_00,in_r7);
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  *(int *)(iVar3 + -4) = unaff_r14 - (int)uVar4;
  *(int *)(iVar3 + -8) = iVar1 + iVar2;
  return in_stack_00000000;
}

