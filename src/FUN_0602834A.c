extern void FUN_060282c0();

int FUN_0602834a(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    int param_4;
{

  char cVar1;

  int bVar2;

  int iVar3;

  char *pcVar4;

  param_2 = param_2 + **(int **)(0x06028614 + param_1);

  iVar3 = FUN_060282c0(param_4);

  pcVar4 = (char *)(iVar3 + 8);

  iVar3 = 0;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

    *(short *)(param_2 + iVar3) = cVar1 + param_3;

    bVar2 = iVar3 != 6;

    iVar3 = iVar3 + 2;

  } while (bVar2);

  return 8;

}
