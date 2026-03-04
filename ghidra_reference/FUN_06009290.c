/* FUN_06009290  0x06009290 */


undefined4 FUN_06009290(void)

{
  undefined4 uVar1;
  
  *(undefined4 *)PTR_DAT_060092bc = 0x11;
  if (*(int *)PTR_DAT_060092c0 == 0) {
    uVar1 = (*(code *)PTR_FUN_060092c8)();
  }
  else {
    uVar1 = (*(code *)PTR_FUN_060092c4)();
  }
  *(undefined2 *)PTR_DAT_060092cc = 4;
  return uVar1;
}

