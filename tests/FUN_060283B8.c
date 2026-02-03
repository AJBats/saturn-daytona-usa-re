int FUN_060283b8(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    unsigned int param_4;
{

  int bVar1;

  unsigned short uVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = 0xe;

  iVar3 = **(int **)(0x06028614 + param_1);

  do {

    uVar2 = (unsigned short)param_4;

    param_4 = param_4 >> 4;

    *(unsigned short *)(iVar3 + param_2 + iVar4) = (uVar2 & 0xf) + param_3;

    bVar1 = iVar4 != 0;

    iVar4 = iVar4 + -2;

  } while (bVar1);

  return 0;

}
