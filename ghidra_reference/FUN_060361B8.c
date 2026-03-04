/* FUN_060361B8  0x060361B8 */


undefined4 FUN_060361b8(uint *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_18 [4];
  byte bStack_14;
  undefined1 auStack_10 [12];
  
  (*(code *)PTR_FUN_060361f4)(auStack_10);
  auStack_10[0] = 0x32;
  uVar1 = (*(code *)PTR_FUN_060361f8)(0,auStack_10,auStack_18);
  *param_1 = (uint)bStack_14;
  return uVar1;
}

