/* FUN_0600FE38  0x0600FE38 */


void FUN_0600fe38(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = *(int *)PTR_DAT_0600fe98;
  *(int *)PTR_DAT_0600fe98 = iVar2 + -1;
  puVar1 = PTR_DAT_0600fe9c;
  if (iVar2 + -1 == (int)DAT_0600fe92) {
    (*(code *)PTR_FUN_0600fea4)(PTR_DAT_0600fea0,PTR_DAT_0600fe9c);
    (*(code *)PTR_FUN_0600feb0)(4,puVar1,0,PTR_DAT_0600feac + *(int *)(PTR_DAT_0600fea8 + 4));
    *(undefined4 *)PTR_DAT_0600feb4 = 0;
    *PTR_DAT_0600feb8 = 0x10;
  }
  (*(code *)PTR_FUN_0600fec0)(0xc,(int)DAT_0600fe96,(int)DAT_0600fe94,PTR_DAT_0600febc);
  (*(code *)PTR_FUN_0600fec8)(PTR_DAT_0600fec4);
  (*(code *)PTR_FUN_0600fec8)(PTR_DAT_0600fecc);
  return;
}

