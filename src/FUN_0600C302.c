extern int DAT_0600c36a;

extern int DAT_0600c36c;

extern int DAT_0600c36e;

extern int DAT_0600c370;

extern int DAT_0600c372;

extern int DAT_0600c416;

extern int DAT_0600c418;

extern int DAT_0600c41a;

extern int PTR_DAT_0600c374;

extern int PTR_DAT_0600c374;

int FUN_0600c302()
{

  int iVar1;

  int iVar2;

  iVar2 = *(int *)0x0607E944;

  iVar1 = *(int *)(iVar2 + 0x68) << 5;

  *(int *)(iVar2 + 0xe4) = iVar1;

  *(int *)(iVar2 + 0xe0) = iVar1;

  if (0 < *(short *)(iVar2 + DAT_0600c36a)) {

    *(short *)(iVar2 + DAT_0600c36a) = *(short *)(iVar2 + DAT_0600c36a) + -1;

  }

  if (0 < *(short *)(iVar2 + DAT_0600c36c)) {

    *(short *)(iVar2 + DAT_0600c36c) = *(short *)(iVar2 + DAT_0600c36c) + -1;

  }

  if (*(short *)(iVar2 + DAT_0600c36e) != 0) {

    return (int)*(short *)(iVar2 + DAT_0600c36e);

  }

  if ((int)DAT_0600c370 <= *(int *)(iVar2 + 0x68)) {

    iVar1 = 0x172;

    *(short *)(iVar2 + iVar1) = 0x12;

    iVar1 = iVar1 + 2;

    *(short *)(iVar2 + iVar1) = 0;

    return iVar1;

  }

  if (*(int *)(iVar2 + DAT_0600c372) < (int)PTR_DAT_0600c374) {

    return (int)DAT_0600c372;

  }

  iVar1 = 0x68;

  if ((0x9b < *(int *)(iVar2 + 0x68)) && (*(int *)(iVar2 + 0x68) < (int)DAT_0600c418))

  {

    iVar1 = 0x172;

    *(short *)(iVar2 + iVar1) = 0;

    iVar1 = iVar1 + 2;

    *(short *)(iVar2 + iVar1) = 0x12;

  }

  return iVar1;

}
