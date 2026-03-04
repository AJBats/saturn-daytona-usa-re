/* FUN_0600F990  0x0600F990 */


void FUN_0600f990(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_0600fa08;
  puVar2 = PTR_DAT_0600fa0c + *(int *)PTR_DAT_0600fa08;
  *(undefined **)PTR_DAT_0600fa08 = puVar2;
  (*(code *)PTR_FUN_0600fa10)(0x10,puVar2);
  *(short *)PTR_DAT_0600fa14 = *(short *)PTR_DAT_0600fa14 + 2;
  (*(code *)PTR_FUN_0600fa18)();
  if (*(int *)puVar1 == 0) {
    *PTR_DAT_0600fa1c = 8;
  }
  return;
}

