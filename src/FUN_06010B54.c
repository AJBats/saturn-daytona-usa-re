int FUN_06010b54()
{

  int uVar1;

  if (*(int *)0x0607EAE0 == 0) {

    uVar1 = (*(void(*)())0x0601D5F4)(0,*(int *)(0x0604483C + *(int *)0x0607EAB8 * 4));

  }

  else {

    uVar1 = 0xAB110BFF;

    if (*(int *)0x06078644 == 1) {

      uVar1 = 0xAB110AFF;

    }

    uVar1 = (*(void(*)())0x0601D5F4)(0,uVar1);

  }

  return uVar1;

}
