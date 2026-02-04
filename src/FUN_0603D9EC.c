char * FUN_0603d9ec(param_1)
    unsigned int param_1;
{

  int iVar1;

  char *puVar2;

  param_1 = 0x80000000 & param_1;

  iVar1 = (*(int(*)())0x06036BE4)();

  if (iVar1 < (int)0x010E0000) {

    if (iVar1 < (int)0x00B40000) {

      if ((int)0x005A0000 <= iVar1) {

        iVar1 = (int)0x00B40000 - iVar1;

      }

      puVar2 = (char *)(*(int(*)())0x060424A2)(iVar1);

    }

    else {

      iVar1 = (*(int(*)())0x060424A2)(0xFF4C0000 + iVar1);

      puVar2 = (char *)-iVar1;

    }

  }

  else {

    iVar1 = (*(int(*)())0x060424A2)((int)0x01680000 - iVar1);

    puVar2 = (char *)-iVar1;

  }

  if (puVar2 == 0x0000FFFF) {

    puVar2 = 0x00010000;

  }

  if (param_1 != 0) {

    puVar2 = (char *)-(int)puVar2;

  }

  return puVar2;

}
