/* FUN_06015482  0x06015482 */


void FUN_06015482(undefined1 param_1)

{
  *PTR_DAT_060154ec = 0;
  *(undefined2 *)PTR_DAT_060154f0 = 0;
  *(uint *)PTR_DAT_060154f4 = *(uint *)PTR_DAT_060154f4 | 1;
  if (((*(int *)PTR_DAT_060154f8 == 0) &&
      (*(int *)(*(int *)PTR_DAT_060154fc + (int)DAT_060154e4) < 3)) ||
     ((*(ushort *)PTR_DAT_06015500 & DAT_060154e6) != 0)) {
    *(undefined4 *)PTR_DAT_06015504 = 0x16;
  }
  else {
    *(undefined4 *)PTR_DAT_06015504 = 0x18;
  }
  (*(code *)PTR_FUN_06015508)();
  (*(code *)PTR_FUN_060154e8)(param_1);
  return;
}

