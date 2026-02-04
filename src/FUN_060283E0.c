char * FUN_060283e0(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    char *param_4;
{

  char cVar1;

  char *puVar2;

  short *psVar3;

  puVar2 = 0x06028614;

  psVar3 = (short *)(**(int **)(0x06028614 + param_1) + param_2);

  while( true ) {

    cVar1 = *param_4;

    param_4 = param_4 + 1;

    if (cVar1 == '\0') break;

    *psVar3 = cVar1 + param_3;

    psVar3 = psVar3 + 1;

  }

  return puVar2;

}
