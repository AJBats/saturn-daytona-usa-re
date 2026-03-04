/* FUN_060204D0  0x060204D0 */


void FUN_060204d0(undefined1 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_0602051c;
  puVar2 = PTR_DAT_06020520 + *(int *)PTR_DAT_0602051c;
  *(undefined **)PTR_DAT_0602051c = puVar2;
  (*(code *)PTR_FUN_06020524)(0x20,param_2,puVar2);
  if ((int)PTR_DAT_06020528 < *(int *)puVar1) {
    FUN_06020dee(param_1);
    (*(code *)PTR_FUN_06020524)(0x20,0,PTR_DAT_06020528);
    return;
  }
  return;
}

