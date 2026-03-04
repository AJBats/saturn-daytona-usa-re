/* FUN_0601D72C  0x0601D72C */


void FUN_0601d72c(int param_1)

{
  if (*(int *)PTR_DAT_0601d76c != param_1) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d76c = param_1;
    *(int *)PTR_DAT_0601d770 = param_1;
    *(int *)PTR_DAT_0601d774 = param_1;
  }
  return;
}

