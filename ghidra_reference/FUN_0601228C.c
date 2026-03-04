/* FUN_0601228C  0x0601228C */


void FUN_0601228c(void)

{
  int in_r2;
  
  if (in_r2 <= *(int *)PTR_DAT_060122d8) {
    FUN_060122f4();
    FUN_0601250c();
    FUN_06012710();
    return;
  }
  if (99 < *(int *)PTR_DAT_060122d8) {
    *(undefined2 *)PTR_DAT_060122dc = 0;
    FUN_0601250c();
    FUN_06012710();
    return;
  }
  if (0x27 < *(int *)PTR_DAT_060122d8) {
    *(undefined2 *)PTR_DAT_060122dc = 0;
    FUN_060125d0();
    FUN_06012710();
    return;
  }
  *(undefined4 *)PTR_DAT_060122d8 = 1;
  *(undefined4 *)PTR_DAT_0601232c = 0x10;
  *PTR_DAT_06012330 = 1;
  return;
}

