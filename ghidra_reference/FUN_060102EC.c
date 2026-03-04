/* FUN_060102EC  0x060102EC */


void FUN_060102ec(ushort param_1)

{
  undefined *puVar1;
  undefined1 *puVar2;
  uint in_r2;
  
  puVar1 = PTR_DAT_06010320;
  *(int *)PTR_DAT_06010320 = *(int *)PTR_DAT_06010320 + -1;
  if ((in_r2 & (int)PTR_DAT_0601030c._0_2_) == 0) {
    if ((*(int *)puVar1 < 1) || ((param_1 & DAT_0601038c) != 0)) {
      (*(code *)PTR_FUN_06010398)
                (0,*(undefined4 *)(PTR_DAT_06010394 + *(int *)PTR_DAT_06010390 * 4));
      *(undefined4 *)puVar1 = 0;
      *PTR_DAT_0601039c = 2;
      *PTR_DAT_060103a4 = (char)*(undefined4 *)PTR_DAT_060103a0;
      puVar2 = DAT_060103a8;
      *DAT_060103a8 = 0;
      if ((*PTR_DAT_060103ac == '\0') &&
         ((*(int *)PTR_DAT_060103b0 == 0 && ((*(ushort *)PTR_DAT_060103b4 & DAT_0601038e) != 0)))) {
        *puVar2 = 1;
      }
    }
  }
  else {
    *(undefined4 *)PTR_DAT_06010324 = 6;
  }
  return;
}

