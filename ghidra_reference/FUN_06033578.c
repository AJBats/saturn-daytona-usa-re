/* FUN_06033578  0x06033578 */


undefined4 FUN_06033578(void)

{
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
  
  iVar1 = FUN_060335f4();
  iVar1 = (*(code *)PTR_FUN_060335f0)(*(undefined4 *)(DAT_060335e8 + iVar1));
  iVar2 = (*(code *)PTR_FUN_060335f0)(extraout_r3,in_r7);
  iVar3 = (*(code *)PTR_FUN_060335f0)(extraout_r2);
  uVar5 = (*(code *)PTR_FUN_060335f0)(extraout_r2_00,in_r7);
  iVar4 = (int)((ulonglong)uVar5 >> 0x20);
  *(int *)(iVar4 + -4) = iVar1 - (int)uVar5;
  *(int *)(iVar4 + -8) = iVar2 + iVar3;
  return in_stack_00000000;
}

