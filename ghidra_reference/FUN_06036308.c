/* FUN_06036308  0x06036308 */


undefined4 FUN_06036308(undefined1 param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 auStack_14 [4];
  undefined1 uStack_10;
  
  (*(code *)PTR_FUN_06036374)(auStack_14);
  auStack_14[0] = 0x43;
  uStack_10 = param_1;
  uVar1 = (*(code *)PTR_FUN_0603637c)(0,auStack_14,&uStack_1c);
  param_2[1] = uStack_1b;
  param_2[2] = uStack_1a;
  param_2[4] = uStack_19;
  *param_2 = uStack_17;
  param_2[3] = uStack_16;
  param_2[5] = uStack_15;
  return uVar1;
}

