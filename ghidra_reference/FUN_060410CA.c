/* FUN_060410CA  0x060410CA */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_060410ca(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_10 [16];
  
  iVar1 = (*(code *)PTR_FUN_06041100)(param_1);
  if (iVar1 != 0) {
    return 0xfffffff6;
  }
  iVar1 = (*(code *)PTR_FUN_06041104)(param_1,param_3);
  if (iVar1 != 0) {
    return 0xfffffff6;
  }
  (*ram0x06041178)(local_10);
  *(undefined1 *)(*(int *)PTR_DAT_0604117c + 0x40) = local_10[0];
  return 0;
}

