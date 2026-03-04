/* FUN_0601D478  0x0601D478 */


void FUN_0601d478(void)

{
  undefined *puVar1;
  
  *(undefined2 *)PTR_PTR_0601d4f0 = 2;
  puVar1 = PTR_DAT_0601d4f8;
  *(undefined **)PTR_DAT_0601d4f8 = PTR_DAT_0601d4f4;
  (*(code *)PTR_FUN_0601d4fc)(0x20,*(undefined4 *)puVar1,0);
  *(undefined2 *)PTR_DAT_0601d500 = 0x2a;
  FUN_0601d57c(0x2a);
  *PTR_DAT_0601d504 = *PTR_DAT_0601d504 + '\x01';
  return;
}

