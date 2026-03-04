/* FUN_0604140E  0x0604140E */


undefined4 FUN_0604140e(int param_1)

{
  int iVar1;
  undefined1 local_10 [16];
  
  if ((param_1 < 0) || (0x17 < param_1)) {
    return 0xfffffffa;
  }
  if (*(char *)(param_1 + *(int *)PTR_DAT_0604144c) == '\0') {
    return 0xfffffff9;
  }
  iVar1 = (*(code *)PTR_FUN_06041450)();
  if (iVar1 != 0) {
    return 0xfffffff6;
  }
  (*(code *)PTR_FUN_060414c8)(local_10);
  *(undefined1 *)(*(int *)PTR_DAT_060414cc + 0x40) = local_10[0];
  return 0;
}

