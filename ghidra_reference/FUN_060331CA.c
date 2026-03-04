/* FUN_060331CA  0x060331CA */


undefined8 FUN_060331ca(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *in_r0;
  undefined8 uVar1;
  undefined4 in_stack_0000000c;
  
  uVar1 = (*in_r0)();
  (*(code *)PTR_FUN_06033208)((int)((ulonglong)uVar1 >> 0x20));
  return CONCAT44((int)uVar1 - param_3,in_stack_0000000c);
}

