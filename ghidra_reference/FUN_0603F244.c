/* FUN_0603F244  0x0603F244 */


int FUN_0603f244(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int local_10;
  undefined1 auStack_c [4];
  undefined1 auStack_8 [8];
  
  puVar2 = PTR_FUN_0603f2c8;
  puVar1 = PTR_FUN_0603f2c4;
  iVar3 = (*(code *)PTR_FUN_0603f2c8)
                    (param_1,*(undefined4 *)(*(int *)PTR_DAT_0603f2cc + (int)DAT_0603f2c2));
  if (iVar3 == -5) {
    local_10 = -1;
  }
  else {
    (*(code *)PTR_FUN_0603f2d4)(PTR_DAT_0603f2d0);
    while (iVar3 != 0) {
      iVar3 = (*(code *)puVar1)();
      if (iVar3 == -0xc) {
        return -1;
      }
      iVar3 = (*(code *)puVar2)();
    }
    iVar3 = (*(code *)PTR_FUN_0603f2d8)();
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_FUN_0603f2dc)(auStack_c,&local_10,auStack_8);
      if (iVar3 == 0) {
        local_10 = local_10 + 2;
      }
      else {
        local_10 = -1;
      }
    }
    else {
      local_10 = -1;
    }
  }
  return local_10;
}

