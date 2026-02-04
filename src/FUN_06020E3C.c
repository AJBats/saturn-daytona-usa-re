unsigned char FUN_06020e3c(param_1)
    char param_1;
{

  unsigned char bVar1;

  bVar1 = 0;

  do {

    if (param_1 == ((int *)0x0608782C)[(short)((unsigned short)bVar1 * 0x44)]) {

      return bVar1;

    }

    bVar1 = bVar1 + 1;

  } while (bVar1 < 0x10);

  return bVar1;

}
