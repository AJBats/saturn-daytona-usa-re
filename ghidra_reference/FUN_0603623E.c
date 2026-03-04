/* FUN_0603623E  0x0603623E */


undefined4 FUN_0603623e(undefined1 param_1,uint *param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uStack_20;
  uint uStack_1c;
  undefined1 auStack_18 [4];
  undefined1 uStack_14;
  
  (*(code *)PTR_FUN_06036298)(auStack_18);
  auStack_18[0] = 0x41;
  uStack_14 = param_1;
  uVar1 = (*(code *)PTR_FUN_060362a0)(0,auStack_18,&uStack_20);
  *param_2 = uStack_20 & DAT_060362a4;
  *param_3 = uStack_1c & DAT_060362a4;
  return uVar1;
}

