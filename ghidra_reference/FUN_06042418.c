/* FUN_06042418  0x06042418 */


int FUN_06042418(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = param_1 < 0;
  if (bVar1) {
    param_1 = -param_1;
  }
  if (param_1 < (int)PTR_DAT_0604244c) {
    if ((int)PTR_DAT_06042450 < param_1) {
      param_1 = (int)PTR_DAT_0604244c - param_1;
    }
  }
  else {
    param_1 = 0;
  }
  iVar2 = (*(code *)PTR_FUN_06042454)(param_1);
  if (bVar1) {
    iVar2 = -iVar2;
  }
  return iVar2;
}

