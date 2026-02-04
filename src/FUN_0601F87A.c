void FUN_0601f87a(param_1)
    char param_1;
{

  char *puVar1;

  *0x060877D8 = param_1;

  puVar1 = 0x06087080;

  if (param_1 == '\0') {

    *(char **)0x0605E098 = 0x060A0FA8;

    *puVar1 = 0;

  }

  else {

    *(char **)0x0605E098 = 0x0607ED90;

    *puVar1 = 1;

  }

  return;

}
