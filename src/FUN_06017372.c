unsigned char FUN_06017372(param_1)
    char param_1;
{

  unsigned char bVar1;

  

  bVar1 = 0;

  do {

    if (param_1 == *(char *)((short)((unsigned short)bVar1 * 0x44) + 0x06084FC8)) {

      return bVar1;

    }

    bVar1 = bVar1 + 1;

  } while (bVar1 < 0x12);

  return bVar1;

}
