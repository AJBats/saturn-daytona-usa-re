/* FUN_06036704  0x06036704 */


void FUN_06036704(undefined1 param_1,undefined2 param_2,undefined3 param_3)

{
  undefined1 auStack_18 [2];
  undefined2 uStack_16;
  undefined1 uStack_14;
  undefined3 uStack_13;
  
  (*(code *)PTR_FUN_060367a0)(auStack_18);
  auStack_18[0] = 0x55;
  _uStack_14 = CONCAT13(param_1,param_3);
  uStack_16 = param_2;
  (*(code *)PTR_FUN_060367a4)(0x40,auStack_18);
  return;
}

