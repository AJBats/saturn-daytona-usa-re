int FUN_0600245c(param_1, param_2, param_3)
    short *param_1;
    int param_2;
    short param_3;
{

  int iStack_8;

  short *psStack_4;

  

  iStack_8 = param_2;

  psStack_4 = param_1;

  do {

    *psStack_4 = param_3;

    iStack_8 = iStack_8 + -1;

    psStack_4 = psStack_4 + 1;

  } while (iStack_8 != 0);

  return (int)param_3;

}
