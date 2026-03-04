/* FUN_0603F238  0x0603F238 */


int FUN_0603f238(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iStack_24;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [8];
  
  puVar3 = PTR_DAT_0603f2cc;
  puVar2 = PTR_FUN_0603f2c8;
  puVar1 = PTR_FUN_0603f2c4;
  iVar4 = (*(code *)PTR_FUN_0603f2c8)
                    (param_1,*(undefined4 *)(*(int *)PTR_DAT_0603f2cc + (int)DAT_0603f2c2));
  if (iVar4 == -5) {
    iStack_24 = -1;
  }
  else {
    (*(code *)PTR_FUN_0603f2d4)(PTR_DAT_0603f2d0);
    while (iVar4 != 0) {
      iVar4 = (*(code *)puVar1)();
      if (iVar4 == -0xc) {
        return -1;
      }
      iVar4 = (*(code *)puVar2)(param_1,*(undefined4 *)(*(int *)puVar3 + (int)DAT_0603f2c2));
    }
    iVar4 = (*(code *)PTR_FUN_0603f2d8)();
    if (iVar4 == 0) {
      iVar4 = (*(code *)PTR_FUN_0603f2dc)(auStack_20,&iStack_24,auStack_1c);
      if (iVar4 == 0) {
        iStack_24 = iStack_24 + 2;
      }
      else {
        iStack_24 = -1;
      }
    }
    else {
      iStack_24 = -1;
    }
  }
  return iStack_24;
}

