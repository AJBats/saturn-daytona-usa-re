void FUN_06020d46()
{

  char *puVar1;

  unsigned int uVar2;

  int auStack_38 [10];

  puVar1 = 0x0608782C;

  (*0x06035168)();

  uVar2 = 0;

  do {

    if (puVar1[(short)(((unsigned short)uVar2 & 0xff) * 0x44)] != '\0') {

      (*auStack_38[(unsigned char)puVar1[(short)(((unsigned short)uVar2 & 0xff) * 0x44)] - 1])(uVar2);

    }

    uVar2 = uVar2 + 1;

  } while ((uVar2 & 0xff) < 0x10);

  return;

}
