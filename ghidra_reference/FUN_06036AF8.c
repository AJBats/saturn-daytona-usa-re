/* FUN_06036AF8  0x06036AF8 */


int FUN_06036af8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint local_14 [2];
  undefined1 local_c [4];
  
  (*(code *)PTR_FUN_06036b38)(local_c);
  local_c[0] = 0x73;
  iVar1 = (*(code *)PTR_FUN_06036b3c)(0,local_c,local_14);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_FUN_06036bd4)(local_14[0] & DAT_06036bd0,param_2);
  }
  return iVar1;
}

