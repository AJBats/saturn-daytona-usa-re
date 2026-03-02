extern int DAT_0600d26a;

extern int DAT_0600d26c;

extern int DAT_0600d26e;

extern int DAT_0600d270;

extern int DAT_0600d272;

extern int PTR_DAT_0600d274;

extern int PTR_DAT_0600d274;

int FUN_0600d210()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar1 = (int)DAT_0600d26a;

  iVar3 = *(int *)0x0607E940;

  iVar2 = *(int *)(*(int *)0x0607E944 + iVar1);

  iVar4 = iVar2 - *(int *)(iVar3 + iVar1);

  if ((DAT_0600d26c <= iVar4) && (iVar4 <= DAT_0600d26e)) {

    if (iVar2 < *(int *)(iVar3 + DAT_0600d26a)) {

      iVar2 = iVar2 + -0x10;

    }

    else {

      iVar2 = iVar2 + 0x10;

    }

    if (iVar2 < 0) {

      *(int *)(iVar3 + DAT_0600d270) = 0;

    }

    else if (DAT_0600d272 < iVar2) {

      *(int *)(iVar3 + DAT_0600d270) = 0x800;

    }

    else {

      *(int *)(iVar3 + DAT_0600d270) = iVar2;

    }

    iVar1 = (int)PTR_DAT_0600d274;

    *(int *)(iVar3 + iVar1) = 0x40;

  }

  return iVar1;

}
