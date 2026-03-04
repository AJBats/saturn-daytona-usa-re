/* FUN_0600FDFE  0x0600FDFE */


void FUN_0600fdfe(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_0600fe28;
  iVar2 = *(int *)PTR_DAT_0600fe28;
  *(int *)PTR_DAT_0600fe28 = iVar2 + -1;
  if (iVar2 + -1 < 0) {
    (*(code *)PTR_FUN_0600fe30)(0,DAT_0600fe2c);
    *(int *)puVar1 = (int)DAT_0600fe26;
    *PTR_DAT_0600fe34 = 0xf;
  }
  return;
}

