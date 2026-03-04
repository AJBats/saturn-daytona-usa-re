/* FUN_0601D6F8  0x0601D6F8 */


void FUN_0601d6f8(int param_1)

{
  if (*(int *)PTR_DAT_0601d728 != param_1) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d728 = param_1;
    *(int *)PTR_DAT_0601d720 = param_1;
    *(int *)PTR_DAT_0601d724 = param_1;
  }
  return;
}

