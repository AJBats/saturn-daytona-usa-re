/* FUN_060335BE  0x060335BE */


undefined4 FUN_060335be(void)

{
  code *in_r0;
  int iVar1;
  int unaff_r12;
  int unaff_r13;
  int unaff_r14;
  undefined8 uVar2;
  undefined4 in_stack_00000000;
  
  uVar2 = (*in_r0)();
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  *(int *)(iVar1 + -4) = unaff_r14 - (int)uVar2;
  *(int *)(iVar1 + -8) = unaff_r13 + unaff_r12;
  return in_stack_00000000;
}

