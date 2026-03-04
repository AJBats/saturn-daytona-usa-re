/* FUN_06042458  0x06042458 */


int FUN_06042458(int param_1)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  bVar1 = true;
  if (param_1 < (int)PTR_DAT_06042490) {
    if ((int)PTR_DAT_06042494 < param_1) {
      param_1 = (int)PTR_DAT_06042490 - param_1;
    }
    else {
      bVar1 = false;
    }
  }
  else {
    param_1 = 0;
  }
  iVar2 = (*(code *)PTR_FUN_06042498)(param_1);
  if (bVar1) {
    iVar2 = -iVar2;
  }
  return iVar2;
}

