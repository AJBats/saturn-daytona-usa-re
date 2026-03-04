/* FUN_0601D778  0x0601D778 */


void FUN_0601d778(int param_1)

{
  if (*(int *)PTR_DAT_0601d7c0 != param_1) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d7c0 = param_1;
    *(int *)PTR_DAT_0601d7c4 = param_1;
    *(int *)PTR_DAT_0601d7c8 = param_1;
  }
  return;
}

