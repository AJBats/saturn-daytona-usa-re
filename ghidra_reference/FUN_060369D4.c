/* FUN_060369D4  0x060369D4 */


undefined4 FUN_060369d4(uint *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_18;
  byte bStack_17;
  undefined1 auStack_10 [12];
  
  (*(code *)PTR_FUN_06036a10)(auStack_10);
  auStack_10[0] = 0x67;
  uVar1 = (*(code *)PTR_FUN_06036a18)(0,auStack_10,&uStack_18);
  *param_1 = (uint)bStack_17;
  return uVar1;
}

