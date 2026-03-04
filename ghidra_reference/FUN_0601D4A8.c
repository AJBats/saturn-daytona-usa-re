/* FUN_0601D4A8  0x0601D4A8 */


void FUN_0601d4a8(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar3 = PTR_DAT_0601d508;
  puVar2 = PTR_DAT_0601d500;
  puVar1 = PTR_DAT_0601d4f8;
  if (*(short *)PTR_DAT_0601d500 != 0) {
    iVar4 = *(int *)PTR_DAT_0601d4f8 - (int)PTR_DAT_0601d508;
    *(int *)PTR_DAT_0601d4f8 = iVar4;
    (*(code *)PTR_FUN_0601d4fc)(0x20,iVar4,0);
    *(short *)puVar2 = *(short *)puVar2 + -2;
    FUN_0601d57c();
    return;
  }
  *PTR_DAT_0601d504 = *PTR_DAT_0601d504 + '\x01';
  *(int *)puVar1 = *(int *)puVar1 - (int)puVar3;
  return;
}

