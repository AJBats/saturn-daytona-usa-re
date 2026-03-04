/* FUN_0600F98C  0x0600F98C */


void FUN_0600f98c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_0600fa08;
  puVar2 = PTR_DAT_0600fa0c + *(int *)PTR_DAT_0600fa08;
  *(undefined **)PTR_DAT_0600fa08 = puVar2;
  (*(code *)PTR_FUN_0600fa10)(0x10,puVar2,0);
  *(short *)PTR_DAT_0600fa14 = *(short *)PTR_DAT_0600fa14 + 2;
  (*(code *)PTR_FUN_0600fa18)();
  if (*(int *)puVar1 == 0) {
    *PTR_DAT_0600fa1c = 8;
  }
  return;
}

