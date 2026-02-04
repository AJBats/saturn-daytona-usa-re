int FUN_06035cbc(param_1, param_2)
    int param_1;
    short *param_2;
{

  char *puVar1;

  int iVar2;

  int local_14 [2];

  puVar1 = 0x25898000;

  iVar2 = (*(int(*)())0x06034C68)(0);

  if (iVar2 == 0) {

    iVar2 = 0;

    if (0 < param_1) {

      do {

        iVar2 = iVar2 + 1;

        *param_2 = *(short *)puVar1;

        param_2 = param_2 + 1;

      } while (iVar2 < param_1);

    }

    iVar2 = (*(int(*)())0x06034CC8)(local_14);

    if ((iVar2 == 0) && (param_1 != local_14[0])) {

      iVar2 = -7;

    }

  }

  return iVar2;

}
