/* FUN_0603667E  0x0603667E */


undefined4 FUN_0603667e(undefined1 param_1,undefined2 param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 auStack_18 [2];
  undefined2 uStack_16;
  undefined1 uStack_14;
  
  (*(code *)PTR_FUN_060366fc)(auStack_18);
  auStack_18[0] = 0x54;
  uStack_16 = param_2;
  uStack_14 = param_1;
  uVar1 = (*(code *)PTR_FUN_060366f8)(0,auStack_18,&uStack_20);
  *param_3 = uStack_20 & DAT_06036700;
  *(undefined1 *)(param_3 + 1) = uStack_1c;
  *(undefined1 *)((int)param_3 + 5) = uStack_1b;
  *(undefined1 *)((int)param_3 + 6) = uStack_1a;
  *(undefined1 *)((int)param_3 + 7) = uStack_19;
  return uVar1;
}

