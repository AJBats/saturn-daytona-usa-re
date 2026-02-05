void FUN_0601712c()
{

  char *puVar1;

  unsigned int uVar2;

  int auStack_6c [23];

  puVar1 = 0x06084FC8;

  (*(int(*)())0x06035168)();

  uVar2 = 0;

  do {

    if (puVar1[(short)(((unsigned short)uVar2 & 0xff) * 0x44)] != '\0') {

      (*(int(*)())auStack_6c[(unsigned char)puVar1[(short)(((unsigned short)uVar2 & 0xff) * 0x44)] - 1])(uVar2);

    }

    uVar2 = uVar2 + 1;

  } while ((uVar2 & 0xff) < 0x12);

  return;

}
