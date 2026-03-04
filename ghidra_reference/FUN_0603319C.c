/* FUN_0603319C  0x0603319C */


undefined8 FUN_0603319c(void)

{
  code *in_r0;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int iVar1;
  undefined8 uVar2;
  undefined4 in_stack_0000000c;
  
  (*in_r0)();
  (*(code *)PTR_FUN_06033208)(extraout_r2);
  uVar2 = (*(code *)PTR_FUN_06033208)(extraout_r2_00);
  iVar1 = (int)uVar2;
  uVar2 = (*(code *)PTR_FUN_06033208)((int)((ulonglong)uVar2 >> 0x20));
  (*(code *)PTR_FUN_06033208)((int)((ulonglong)uVar2 >> 0x20));
  return CONCAT44((int)uVar2 - iVar1,in_stack_0000000c);
}

