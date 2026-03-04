/* FUN_060120A0  0x060120A0 */


void FUN_060120a0(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_060120c4;
  (*(code *)PTR_FUN_060120c4)(0x20);
  (*(code *)puVar1)(8,6);
  (*(code *)puVar1)((int)DAT_060120c2,5);
  (*(code *)puVar1)(0x10,4);
  return;
}

