extern void FUN_06012c3c();

void FUN_06012db4(param_1)
    int param_1;
{

  char *puVar1;

  puVar1 = 0x00240000;

  if (param_1 == 1) {

    FUN_06012c3c(0x0604490C,0x00200000);

    FUN_06012c3c(0x0604491C,puVar1);

    return;

  }

  if (param_1 == 2) {

    FUN_06012c3c(0x06044928,0x00200000);

    FUN_06012c3c(0x06044938,puVar1);

    return;

  }

  FUN_06012c3c(0x06044944,0x00200000);

  FUN_06012c3c(0x06044954,puVar1);

  return;

}
