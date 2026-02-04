void FUN_06012710()
{

  char *puVar1;

  char *puVar2;

  int uVar3;

  int iVar4;

  int uVar5;

  uVar3 = 0xAE1115FF;

  puVar2 = 0x0601D5F4;

  puVar1 = 0x0607EBCC;

  iVar4 = *(int *)0x0607EBCC;

  if (iVar4 == 0x28) {

    (*(void(*)())0x0601D5F4)(0,0xAE1125FF);

    (*(void(*)())puVar2)(0,0xAE1116FF);

    *(short *)0x06086056 = 0x3c;

    *(int *)0x0608605A = 1;

  }

  else {

    uVar5 = 0xAE1124FF;

    if ((iVar4 != 0x3c) && (uVar5 = 0xAE1123FF, iVar4 != 0x50)) {

      if (iVar4 != 100) goto LAB_0601277a;

      *(int *)0x06078654 = 1;

      *(int *)0x06063EF0 = *(int *)(*(int *)0x0607E944 + 0x30);

      uVar5 = 0xAE1122FF;

    }

    (*(void(*)())puVar2)(0,uVar5);

    (*(void(*)())puVar2)(0,uVar3);

  }

LAB_0601277a:

  iVar4 = (*(void(*)())0x06035C2C)();

  if (0x6e < *(int *)puVar1 && iVar4 == 0) {

    (*(void(*)())puVar2)(0,0xAE110CFF);

  }

  return;

}
