/* FUN_0600FD54  0x0600FD54 */


int FUN_0600fd54(void)

{
  int iVar1;
  
  (*(code *)PTR_FUN_0600fdd8)(0,DAT_0600fdd4);
  *(undefined2 *)PTR_DAT_0600fddc = 0x78;
  *PTR_DAT_0600fde0 = 0xb;
  FUN_06010bc4();
  (*(code *)PTR_FUN_0600fde4)();
  if ((char)*PTR_DAT_0600fde8 == 0) {
    iVar1 = (*(code *)PTR_FUN_0600fdec)(1);
    return iVar1;
  }
  return (int)(char)*PTR_DAT_0600fde8;
}

