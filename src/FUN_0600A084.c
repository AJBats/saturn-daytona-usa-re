extern int DAT_0600a10c;

void FUN_0600a084()
{

  int iVar1;

  if (*(int *)(*(int *)0x0607E944 + (int)DAT_0600a10c) < 2) {

    (*(int(*)())0x06014884)(0x10,0);

    return;

  }

  iVar1 = *(int *)(*(int *)0x0607E944 + (int)DAT_0600a10c) << 15;

  if ((*(unsigned int *)0x0607EBC8 & 1) != 0) {

    iVar1 = *(int *)(*(int *)0x0607E944 + (int)DAT_0600a10c) * -0x8000;

  }

  (*(int(*)())0x06014884)(0x10,iVar1,0);

  return;

}
