/* FUN_06009F10  0x06009F10 */


void FUN_06009f10(void)

{
  undefined *puVar1;
  int iVar2;
  
  FUN_0600a294();
  iVar2 = *(int *)PTR_DAT_06009fb0;
  *(int *)PTR_DAT_06009fb0 = iVar2 + -1;
  puVar1 = PTR_DAT_06009fb4;
  if (iVar2 + -1 < 0) {
    iVar2 = (int)PTR_DAT_06009fac._0_2_;
    *(int *)(*(int *)PTR_DAT_06009fb4 + iVar2) = (int)(char)*PTR_DAT_06009fb8;
    *(undefined4 *)(*(int *)puVar1 + iVar2 + 0x1c) = *(undefined4 *)PTR_DAT_06009fbc;
    *(undefined4 *)PTR_DAT_06009fc4 = *(undefined4 *)PTR_DAT_06009fc0;
    *(undefined4 *)PTR_DAT_06009fc8 = 0x18;
    *(undefined2 *)PTR_DAT_06009fcc = 3;
    return;
  }
  if (*(int *)PTR_DAT_06009fd0 == 2) {
    (*(code *)PTR_FUN_06009fd4)();
  }
  (*(code *)PTR_FUN_06009fd8)();
  if (*(short *)PTR_DAT_06009fcc != 3) {
    PTR_DAT_06009fdc[1] = PTR_DAT_06009fdc[1] & 0x7f | 0x80;
    (*(code *)PTR_FUN_06009fe0)();
    (*(code *)PTR_FUN_06009fe4)();
    (*(code *)PTR_FUN_06009fe8)();
    (*(code *)PTR_FUN_06009fec)();
    (*(code *)PTR_FUN_06009ff0)();
    return;
  }
  *(undefined4 *)PTR_DAT_06009ff4 = 0;
  (*(code *)PTR_FUN_06009ff8)();
  return;
}

