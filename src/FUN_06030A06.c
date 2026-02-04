extern int DAT_06030a3e;

extern int DAT_06030a40;

extern int DAT_06030a42;

extern int DAT_06030a44;

extern int DAT_06030a46;

int FUN_06030a06()
{

  int iVar1;

  int iVar2;

  int iVar3;

  iVar2 = *0x0607E940;

  iVar1 = (int)DAT_06030a3e;

  if ((*(short *)(iVar2 + iVar1) != 0) &&

     (iVar3 = *(short *)(iVar2 + iVar1) + -1, *(short *)(iVar2 + iVar1) = (short)iVar3, iVar3 == 0))

  {

    iVar1 = (int)DAT_06030a42;

    *(int *)(DAT_06030a40 + iVar2) = 0xFFFF0000;

    if (((unsigned int)0x00200000 & *(unsigned int *)(iVar2 + iVar1)) != 0) {

      iVar1 = (int)DAT_06030a44;

      *(int *)(iVar2 + iVar1) = *(int *)(DAT_06030a46 + iVar2);

      *(int *)(iVar2 + 0x28) = *(int *)(iVar2 + 0x30);

    }

  }

  return iVar1;

}
