/* FUN_060368DC  0x060368DC */


void FUN_060368dc(undefined1 param_1,undefined2 param_2)

{
  undefined1 auStack_14 [4];
  undefined1 uStack_10;
  undefined2 uStack_e;
  
  (*(code *)PTR_FUN_06036974)(auStack_14);
  auStack_14[0] = 100;
  uStack_10 = param_1;
  uStack_e = param_2;
  (*(code *)PTR_FUN_06036978)((int)DAT_06036970,auStack_14);
  return;
}

