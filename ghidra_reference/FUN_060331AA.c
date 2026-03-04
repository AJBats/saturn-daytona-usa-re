/* FUN_060331AA  0x060331AA */


undefined8 FUN_060331aa(void)

{
  code *in_r0;
  undefined4 extraout_r2;
  int iVar1;
  undefined8 uVar2;
  undefined4 in_stack_0000000c;
  
  (*in_r0)();
  uVar2 = (*(code *)PTR_FUN_06033208)(extraout_r2);
  iVar1 = (int)uVar2;
  uVar2 = (*(code *)PTR_FUN_06033208)((int)((ulonglong)uVar2 >> 0x20));
  (*(code *)PTR_FUN_06033208)((int)((ulonglong)uVar2 >> 0x20));
  return CONCAT44((int)uVar2 - iVar1,in_stack_0000000c);
}

