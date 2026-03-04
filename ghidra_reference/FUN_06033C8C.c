/* FUN_06033C8C  0x06033C8C */


int FUN_06033c8c(void)

{
  bool bVar1;
  int iVar2;
  
  FUN_06033f54();
  FUN_06033f54(9);
  FUN_06033f54(10);
  FUN_06033f54(0xb);
  FUN_06033f54(0xc);
  FUN_06033f54(0xd);
  FUN_06033f54(0xe);
  FUN_06033f54(0xf);
  FUN_06033f54(0x10);
  FUN_06033f54(0x11);
  FUN_06033f54(0x12);
  FUN_06033f54(0x13);
  FUN_06033f54(0x14);
  FUN_06033f54(0x15);
  FUN_06033f54(0x16);
  FUN_06033f54(0x17);
  FUN_06033f54(0x18);
  if ((*(int *)(DAT_06033d50 + *(int *)PTR_DAT_06033d4c) < DAT_06033d54) ||
     (DAT_06033d58 < *(int *)(DAT_06033d50 + *(int *)PTR_DAT_06033d4c))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    iVar2 = FUN_06033e8c();
    return iVar2;
  }
  if (*(int *)PTR_DAT_06033d70 == 0) {
    iVar2 = 0;
  }
  else {
    FUN_06033f54(DAT_06033e64);
    iVar2 = *(int *)PTR_DAT_06033e68;
    if (DAT_06033e6c <= iVar2) {
      FUN_06033f54(DAT_06033e70);
      FUN_06033f54(DAT_06033e74);
      FUN_06033f54(DAT_06033e78);
      FUN_06033f54(DAT_06033e7c);
      if (DAT_06033e80 <= iVar2) {
        FUN_06033f54(0x1e);
        FUN_06033f54(0x1f);
        FUN_06033f54(0x20);
        FUN_06033f54(0x21);
        FUN_06033f54(0x22);
        if (DAT_06033e84 <= iVar2) {
          FUN_06033f54(0x23);
          FUN_06033f54(0x24);
          FUN_06033f54(0x25);
          FUN_06033f54(0x26);
          FUN_06033f54(0x27);
          FUN_06033f54(0x28);
          FUN_06033f54(0x29);
          FUN_06033f54(0x2a);
          FUN_06033f54(0x2b);
          FUN_06033f54(0x2c);
        }
      }
    }
    iVar2 = *(int *)PTR_DAT_06033e68 + 1;
    if (DAT_06033e88 <= *(int *)PTR_DAT_06033e68 + 1) {
      iVar2 = DAT_06033e88;
    }
    *(int *)PTR_DAT_06033e68 = iVar2;
  }
  return iVar2;
}

