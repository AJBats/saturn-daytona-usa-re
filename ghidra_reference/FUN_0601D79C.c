/* FUN_0601D79C  0x0601D79C */


void FUN_0601d79c(int param_1)

{
  if (*(int *)PTR_DAT_0601d7cc != param_1) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d7cc = param_1;
    *(int *)PTR_DAT_0601d7c4 = param_1;
    *(int *)PTR_DAT_0601d7c8 = param_1;
  }
  return;
}

