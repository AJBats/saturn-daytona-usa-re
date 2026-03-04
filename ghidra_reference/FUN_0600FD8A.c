/* FUN_0600FD8A  0x0600FD8A */


int FUN_0600fd8a(void)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)PTR_DAT_0600fddc;
  *(short *)PTR_DAT_0600fddc = sVar1 + -1;
  if ((short)(sVar1 + -1) < 0) {
    *PTR_DAT_0600fde0 = 0xc;
    (*(code *)PTR_FUN_0600fdf0)(0xc);
    iVar2 = (*(code *)PTR_FUN_0600fdf0)(4);
    *(undefined4 *)PTR_DAT_0600fdf4 = 0x14;
  }
  else {
    FUN_06010bc4();
    (*(code *)PTR_FUN_0600fde4)();
    iVar2 = (int)(char)*PTR_DAT_0600fde8;
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_FUN_0600fdec)(1);
      return iVar2;
    }
  }
  return iVar2;
}

