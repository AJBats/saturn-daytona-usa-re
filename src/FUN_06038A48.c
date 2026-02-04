void FUN_06038a48(param_1, param_2, param_3)
    short *param_1;
    short *param_2;
    unsigned int param_3;
{

  unsigned int uVar1;

  

  uVar1 = 0;

  if (param_3 >> 1 != 0) {

    do {

      uVar1 = uVar1 + 1;

      *param_1 = *param_2;

      param_1 = param_1 + 1;

      param_2 = param_2 + 1;

    } while (uVar1 < param_3 >> 1);

  }

  return;

}
