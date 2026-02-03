int FUN_06030ee0()
{

  short sVar1;

  int iVar2;



  iVar2 = 0x0150;

  sVar1 = *(short *)(*(int *)0x0607E940 + iVar2);

  if (0 < sVar1) {

    *(short *)(*(int *)0x0607E940 + iVar2) = sVar1 + -1;

  }

  return iVar2;

}
