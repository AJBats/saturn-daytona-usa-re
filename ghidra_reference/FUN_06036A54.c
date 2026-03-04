/* FUN_06036A54  0x06036A54 */


void FUN_06036a54(undefined1 param_1,undefined3 param_2)

{
  undefined1 auStack_14 [4];
  undefined1 uStack_10;
  undefined3 uStack_f;
  
  (*(code *)PTR_FUN_06036a90)(auStack_14);
  auStack_14[0] = 0x71;
  _uStack_10 = CONCAT13(param_1,param_2);
  (*(code *)PTR_FUN_06036a94)((int)PTR_DAT_06036a8c._0_2_,auStack_14);
  return;
}

