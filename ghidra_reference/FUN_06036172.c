/* FUN_06036172  0x06036172 */


undefined4 FUN_06036172(uint *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_18 [4];
  byte bStack_14;
  undefined1 local_10 [12];
  
  (*(code *)PTR_FUN_060361ac)(local_10);
  local_10[0] = 0x31;
  uVar1 = (*(code *)PTR_FUN_060361b4)(0,local_10,auStack_18);
  *param_1 = (uint)bStack_14;
  return uVar1;
}

