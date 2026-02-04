int FUN_06037618(param_1)
    char *param_1;
{

  unsigned int uVar1;

  unsigned char bVar2;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  bVar2 = 0;

  param_1[6] = 0;

  param_1[8] = 0;

  param_1[7] = 0;

  *(short *)(param_1 + 10) = 0;

  do {

    uVar1 = (unsigned int)bVar2;

    bVar2 = bVar2 + 1;

    *(int *)(param_1 + (uVar1 << 2) + 0xc) = 0;

  } while (bVar2 < 0x10);

  return 0;

}
