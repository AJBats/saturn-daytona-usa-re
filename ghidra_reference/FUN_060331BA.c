/* FUN_060331BA  0x060331BA */


undefined8 FUN_060331ba(void)

{
  code *in_r0;
  int iVar1;
  undefined8 uVar2;
  undefined4 in_stack_0000000c;
  
  uVar2 = (*in_r0)();
  iVar1 = (int)uVar2;
  uVar2 = (*(code *)PTR_FUN_06033208)((int)((ulonglong)uVar2 >> 0x20));
  (*(code *)PTR_FUN_06033208)((int)((ulonglong)uVar2 >> 0x20));
  return CONCAT44((int)uVar2 - iVar1,in_stack_0000000c);
}

