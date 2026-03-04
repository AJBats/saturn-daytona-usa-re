/* FUN_06034A9C  0x06034A9C */


undefined4 FUN_06034a9c(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_18 [2];
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 auStack_10 [12];
  
  (*(code *)PTR_FUN_06034b44)(auStack_10);
  auStack_10[0] = 1;
  uVar1 = (*(code *)PTR_FUN_06034b48)(0,auStack_10,auStack_18);
  *param_1 = uStack_16;
  param_1[1] = uStack_15;
  param_1[2] = uStack_13;
  param_1[3] = uStack_12;
  param_1[4] = uStack_11;
  return uVar1;
}

