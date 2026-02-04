extern int DAT_0602f11e;

extern int DAT_0602f120;

extern int DAT_0602f122;

extern int DAT_0602f124;

extern int DAT_0602f126;

extern int DAT_0602f128;

extern int DAT_0602f12a;

extern int DAT_0602f15a;

extern int DAT_0602f15c;

extern int DAT_0602f15e;

extern int DAT_0602f160;

extern int DAT_0602f162;

int FUN_0602f0e8()
{

  int iVar1;

  int iVar2;

  int iVar3;

  iVar1 = *0x0607E944;

  *(int *)(DAT_0602f120 + iVar1) =

       *(int *)(DAT_0602f11e + iVar1) * 0x100 + *(int *)(DAT_0602f120 + iVar1) >> 1;

  if ((*(int *)(DAT_0602f122 + iVar1) == 0) && (*(int *)(DAT_0602f124 + iVar1) == 0)) {

    *(int *)(0x00000084 + iVar1) = *(int *)(DAT_0602f126 + iVar1);

    *(int *)(DAT_0602f12a + iVar1) = *(int *)(DAT_0602f128 + iVar1);

    return iVar1;

  }

  *(short *)(DAT_0602f15a + iVar1) = 0;

  iVar3 = (int)DAT_0602f15c;

  *(int *)(DAT_0602f15e + iVar1) = iVar3;

  *(int *)(DAT_0602f160 + iVar1) = iVar3;

  iVar2 = (int)DAT_0602f162;

  iVar3 = 0x0000071C;

  if (-1 < *(int *)(iVar2 + iVar1)) {

    iVar3 = -0x0000071C;

  }

  iVar3 = *(int *)(iVar2 + iVar1) + iVar3;

  if (-1 < iVar3) {

    *(int *)(iVar2 + iVar1) = 0;

    return iVar1;

  }

  *(int *)(iVar2 + iVar1) = iVar3;

  return iVar1;

}
