/* FUN_0603358E  0x0603358E */


undefined4 FUN_0603358e(void)

{
  code *in_r0;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 in_r7;
  undefined8 uVar5;
  undefined4 in_stack_00000000;
  
  iVar1 = (*in_r0)();
  iVar2 = (*(code *)PTR_FUN_060335f0)(extraout_r3,in_r7);
  iVar3 = (*(code *)PTR_FUN_060335f0)(extraout_r2);
  uVar5 = (*(code *)PTR_FUN_060335f0)(extraout_r2_00,in_r7);
  iVar4 = (int)((ulonglong)uVar5 >> 0x20);
  *(int *)(iVar4 + -4) = iVar1 - (int)uVar5;
  *(int *)(iVar4 + -8) = iVar2 + iVar3;
  return in_stack_00000000;
}

