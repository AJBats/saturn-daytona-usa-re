int FUN_06040220(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int *param_3;
    unsigned int *param_4;
    unsigned int *param_5;
    int *param_6;
    unsigned int *param_7;
    unsigned int *param_8;
{

  int uVar1;

  if (param_2 != (unsigned int *)0x0) {

    if ((*param_1 & 0x40000000) == 0) {

      *param_2 = *param_1;

    }

    else {

      *param_2 = *param_1 & 0x3FFFFFFF;

    }

  }

  if (param_3 != (unsigned int *)0x0) {

    *param_3 = param_1[1];

  }

  if (param_7 != (unsigned int *)0x0) {

    *param_7 = (unsigned int)*(unsigned char *)(param_1 + 7);

  }

  if (param_4 != (unsigned int *)0x0) {

    *param_4 = param_1[3];

  }

  if (param_5 != (unsigned int *)0x0) {

    *param_5 = param_1[4];

  }

  uVar1 = 0;

  if (param_8 != (unsigned int *)0x0) {

    uVar1 = 0x1d;

    *param_8 = (unsigned int)*(unsigned char *)((int)param_1 + 0x1d);

  }

  if (param_6 != (int *)0x0) {

    if (((*(unsigned char *)((int)param_1 + 0x1d) & 8) == 0) ||

       (uVar1 = 0x1d, (*(unsigned char *)((int)param_1 + 0x1d) & 4) == 0)) {

      uVar1 = 0x1d;

      *param_6 = param_1[3] - param_1[5];

    }

    else {

      *param_6 = 0;

    }

  }

  return uVar1;

}
