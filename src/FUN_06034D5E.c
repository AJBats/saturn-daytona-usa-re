int FUN_06034d5e(param_1, param_2)
    int *param_1;
    unsigned char *param_2;
{

  unsigned char bVar1;

  int iVar2;

  iVar2 = *param_1;

  if (iVar2 == 0) {

LAB_06034dac:

    iVar2 = (*0x06035228)();

  }

  else {

    if (iVar2 == 1) {

      *param_2 = *(unsigned char *)((int)param_1 + 5) | 0x80;

      param_2[1] = *(unsigned char *)((int)param_1 + 6);

      bVar1 = *(unsigned char *)((int)param_1 + 7);

    }

    else {

      if (iVar2 != 2) {

        if (iVar2 == 3) {

          iVar2 = (*0x06035228)();

          return iVar2;

        }

        goto LAB_06034dac;

      }

      *param_2 = 0;

      param_2[1] = *(unsigned char *)(param_1 + 1);

      bVar1 = *(unsigned char *)((int)param_1 + 5);

    }

    iVar2 = (int)(char)bVar1;

    param_2[2] = bVar1;

  }

  return iVar2;

}
