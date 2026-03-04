/* FUN_060335AE  0x060335AE */


undefined4 FUN_060335ae(void)

{
  code *in_r0;
  int iVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 in_r7;
  int unaff_r13;
  int unaff_r14;
  undefined8 uVar3;
  undefined4 in_stack_00000000;
  
  iVar1 = (*in_r0)();
  uVar3 = (*(code *)PTR_FUN_060335f0)(extraout_r2,in_r7);
  iVar2 = (int)((ulonglong)uVar3 >> 0x20);
  *(int *)(iVar2 + -4) = unaff_r14 - (int)uVar3;
  *(int *)(iVar2 + -8) = unaff_r13 + iVar1;
  return in_stack_00000000;
}

