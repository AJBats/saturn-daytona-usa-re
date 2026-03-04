/* FUN_0600F914  0x0600F914 */


void FUN_0600f914(void)

{
  undefined *puVar1;
  
  (*(code *)PTR_FUN_0600f968)();
  (*(code *)PTR_FUN_0600f96c)();
  *(undefined2 *)PTR_DAT_0600f970 = 0;
  *(undefined2 *)PTR_PTR_0600f974 = 2;
  puVar1 = PTR_DAT_0600f97c;
  *(undefined4 *)PTR_DAT_0600f97c = DAT_0600f978;
  (*(code *)PTR_FUN_0600f980)(0x10,*(undefined4 *)puVar1,0);
  (*(code *)PTR_FUN_0600f984)();
  *PTR_DAT_0600f964 = 7;
  *(undefined2 *)PTR_DAT_0600f970 = 0;
  (*(code *)PTR_FUN_0600f988)(0);
  return;
}

