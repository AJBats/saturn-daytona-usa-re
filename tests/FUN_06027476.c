int FUN_06027476(param_1)
    unsigned int param_1;
{

  char *puVar1;

  char *puVar2;

  

  puVar1 = (char *)0x0;

  puVar2 = 0x00008000;

  if (0 < (int)param_1) {

    do {

      puVar1 = puVar1 + (int)puVar2;

      if ((int)puVar1 * (int)puVar1 == param_1) break;

      if (param_1 < (unsigned int)((int)puVar1 * (int)puVar1)) {

        puVar1 = puVar1 + -(int)puVar2;

      }

      puVar2 = (char *)((unsigned int)puVar2 >> 1);

    } while (puVar2 != (char *)0x0);

  }

  return (int)puVar1 << 8;

}
