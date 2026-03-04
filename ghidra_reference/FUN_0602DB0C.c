/* FUN_0602DB0C  0x0602DB0C */


void FUN_0602db0c(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  (*(code *)PTR_FUN_0602dbcc)(DAT_0602dbc4,DAT_0602dbc8);
  (*(code *)PTR_FUN_0602dbcc)(DAT_0602dbd0,DAT_0602dbc8);
  uVar2 = DAT_0602dbc8;
  *(undefined4 *)PTR_DAT_0602dbd4 = DAT_0602dbc8;
  *PTR_DAT_0602dbd8 = (char)uVar2;
  *(undefined4 *)PTR_DAT_0602dbdc = uVar2;
  *(undefined4 *)PTR_DAT_0602dbe0 = uVar2;
  iVar1 = *(int *)PTR_DAT_0602dbe4;
  *(undefined4 *)PTR_DAT_0602dbec = DAT_0602dbe8;
  uVar2 = DAT_0602dbc8;
  *(undefined4 *)(DAT_0602dbac + iVar1) = DAT_0602dbc8;
  *(undefined4 *)(DAT_0602dbae + iVar1) = uVar2;
  *(undefined4 *)(DAT_0602dbb0 + iVar1) = uVar2;
  *(undefined4 *)(DAT_0602dbb2 + iVar1) = uVar2;
  *(undefined4 *)PTR_DAT_0602dbf0 = uVar2;
  *(undefined4 *)(DAT_0602dbb4 + iVar1) = uVar2;
  *(undefined4 *)(DAT_0602dbb6 + iVar1) = uVar2;
  uVar2 = *(undefined4 *)(DAT_0602dbb8 + iVar1);
  *(undefined4 *)(DAT_0602dbba + iVar1) = uVar2;
  *(undefined4 *)(DAT_0602dbbc + iVar1) = uVar2;
  *(undefined4 *)(DAT_0602dbbe + iVar1) = DAT_0602dbc8;
  uVar3 = (int)((ulonglong)((longlong)DAT_0602dbf8 * (longlong)(int)PTR_DAT_0602dbf4) >> 0x20) <<
          0x10 | (uint)((longlong)DAT_0602dbf8 * (longlong)(int)PTR_DAT_0602dbf4) >> 0x10;
  if (DAT_0602dbfc <= *(int *)(DAT_0602dbc0 + iVar1)) {
    *(uint *)(DAT_0602dc00 + iVar1) = uVar3;
  }
  *(uint *)(DAT_0602dc04 + iVar1) = uVar3;
  *(int *)PTR_DAT_0602dc08 = (int)DAT_0602dbc2;
  *(undefined4 *)PTR_DAT_0602dc10 = *(undefined4 *)PTR_DAT_0602dc0c;
  *(int *)PTR_DAT_0602dc14 = (int)DAT_0602dbc2;
  (**(code **)(PTR_LAB_0602dc40 + *(int *)PTR_DAT_0602dc3c * 4))();
  FUN_0602e16c();
  return;
}

