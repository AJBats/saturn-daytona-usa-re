extern int DAT_06034d02;

extern int FUN_06034cc8();

int FUN_06034c68(param_1)
    int param_1;
{

  int iVar1;

  unsigned short local_14 [2];

  char auStack_10 [8];

  if (param_1 == 0) {

    iVar1 = 2;

  }

  else {

    iVar1 = (int)DAT_06034d02;

  }

  iVar1 = (*(void(*)())0x06035E00)(iVar1,local_14);

  if (((param_1 == 1) && (iVar1 == 0)) && ((local_14[0] & 0x80) != 0)) {

    iVar1 = -4;

  }

  if (iVar1 != 0) {

    FUN_06034cc8(auStack_10);

  }

  (*(void(*)())0x06035C6E)(0x0000FFFD);

  return iVar1;

}
