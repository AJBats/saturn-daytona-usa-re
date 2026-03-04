/* FUN_060422F0  0x060422F0 */


bool FUN_060422f0(uint param_1)

{
  short sVar1;
  
  sVar1 = (*(code *)PTR_FUN_06042310)();
  return ((int)sVar1 & param_1) != 0;
}

