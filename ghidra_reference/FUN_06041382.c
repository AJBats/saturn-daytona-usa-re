/* FUN_06041382  0x06041382 */


undefined4 FUN_06041382(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined1 auStack_10 [4];
  int iStack_c;
  
  puVar1 = PTR_DAT_060413f4;
  iStack_c = *(int *)PTR_DAT_060413f4 + 0x18;
  if ((*(char *)(iStack_c + param_1) != '\0') && (*(char *)(iStack_c + param_2) != '\0')) {
    if (*(int *)(*(int *)PTR_DAT_060413f4 + (int)DAT_060413ee) != 0) {
      return 0xffffffff;
    }
    iVar2 = (int)DAT_060413ee;
    *(undefined4 *)(*(int *)PTR_DAT_060413f4 + iVar2) = 1;
    *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;
    *(int *)(*(int *)puVar1 + iVar2 + 8) = param_2;
    *(undefined4 *)(*(int *)puVar1 + iVar2 + 0xc) = param_3;
    *(undefined4 *)(*(int *)puVar1 + iVar2 + 0x10) = param_4;
    FUN_06041ee8(auStack_10);
    return 0;
  }
  return 0xfffffff9;
}

