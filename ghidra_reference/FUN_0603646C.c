/* FUN_0603646C  0x0603646C */


undefined4 FUN_0603646c(undefined1 param_1,uint *param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_20 [2];
  byte bStack_1e;
  byte bStack_1d;
  undefined1 auStack_18 [4];
  undefined1 uStack_14;
  
  (*(code *)PTR_FUN_060364c8)(auStack_18);
  auStack_18[0] = 0x47;
  uStack_14 = param_1;
  uVar1 = (*(code *)PTR_FUN_060364d0)(0,auStack_18,auStack_20);
  *param_2 = (uint)bStack_1e;
  *param_3 = (uint)bStack_1d;
  return uVar1;
}

