void FUN_0601772e(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  unsigned char bVar4;

  puVar2 = 0x06085640;

  puVar1 = 0x06028400;

  uVar3 = 0x2cU - param_1 & 0xff;

  bVar4 = 0;

  if (uVar3 != 0) {

    do {

      (*puVar1)(0xc,puVar2 + (short)((unsigned short)bVar4 * 0x36),(param_1 + 0x40) * 2,0);

      bVar4 = bVar4 + 1;

      param_1 = param_1 + 1;

    } while (bVar4 < uVar3);

  }

  return;

}
