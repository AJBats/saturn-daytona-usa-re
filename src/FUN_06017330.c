int FUN_06017330(param_1)
    unsigned short param_1;
{

  char *puVar1;

  unsigned int uVar2;

  unsigned char bVar3;

  puVar1 = 0x06085490;

  param_1 = param_1 & 0xff;

  ((int *)0x06085490)[(short)(param_1 * 0x18) + 4] = 0;

  *(short *)(puVar1 + (short)(param_1 * 0x18) + 6) = 0;

  puVar1[(short)(param_1 * 0x18) + 5] = 0;

  bVar3 = 0;

  do {

    uVar2 = (unsigned int)bVar3;

    bVar3 = bVar3 + 1;

    *(short *)(puVar1 + uVar2 * 2 + (short)(param_1 * 0x18) + 8) = 0;

  } while (bVar3 < 8);

  return 0;

}
