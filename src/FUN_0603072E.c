extern int DAT_06030742;

void FUN_0603072e(param_1, param_2)
    int param_1;
    int param_2;
{

  int unaff_r14;

  if (param_2 == *(int *)(DAT_06030742 + unaff_r14)) {

    return;

  }

  *(int *)(DAT_06030742 + unaff_r14) = param_2;

  (**(void **)(0x06030F1C + param_1 * 4))();

  return;

}
