/* FUN_06008D74  0x06008D74 */


void FUN_06008d74(void)

{
  undefined *puVar1;
  int iVar2;
  
  if (*(short *)PTR_DAT_06008dd8 == 0x70) {
    *(undefined4 *)PTR_DAT_06008ddc = 2;
  }
  iVar2 = *(int *)PTR_DAT_06008de0;
  *(int *)PTR_DAT_06008de0 = iVar2 + -1;
  if (iVar2 + -1 < 0) {
    *(undefined4 *)PTR_DAT_06008de4 = 0;
    (*(code *)PTR_FUN_06008de8)();
  }
  if ((*(ushort *)PTR_DAT_06008dec & DAT_06008dd6) != 0) {
    *(undefined4 *)PTR_DAT_06008de4 = 0;
    (*(code *)PTR_FUN_06008de8)();
  }
  (*(code *)PTR_FUN_06008df0)();
  puVar1 = PTR_FUN_06008df8;
  *(uint *)PTR_DAT_06008df4 = *(uint *)PTR_DAT_06008df4 | 4;
  (*(code *)puVar1)();
  *(undefined4 *)PTR_DAT_06008dfc = 0;
  return;
}

