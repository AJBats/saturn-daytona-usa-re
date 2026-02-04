int FUN_060405b8(param_1, param_2)
    int *param_1;
    short *param_2;
{

  short uVar1;

  unsigned char local_10 [8];

  int uStack_8;

  uVar1 = (*(int(*)())0x06041330)(local_10);

  if (param_2 != (short *)0x0) {

    *param_2 = uVar1;

  }

  if (param_1 != (int *)0x0) {

    *param_1 = uStack_8;

  }

  switch(local_10[0] & 0xf) {

  case 0:

    return 2;

  case 1:

  case 2:

    return 0;

  case 3:

  case 8:

    return 1;

  case 4:

    return 2;

  case 5:

    return 1;

  case 6:

    return 3;

  case 7:

    return 4;

  default:

    return 5;

  }

}
