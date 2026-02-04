extern int DAT_060024d6;

int FUN_06002486(param_1, param_2, param_3, param_4)
    short *param_1;
    short param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  short *local_18;

  int iStack_14;

  int iStack_10;

  short local_6;

  short *psStack_4;

  iStack_10 = param_4;

  local_6 = param_2;

  psStack_4 = param_1;

  do {

    local_18 = psStack_4;

    iStack_14 = param_3;

    do {

      *local_18 = local_6;

      iVar1 = (int)local_6;

      local_6 = (short)(iVar1 + 1);

      local_18 = local_18 + 1;

      iStack_14 = iStack_14 + -1;

    } while (iStack_14 != 0);

    psStack_4 = (short *)((int)psStack_4 + (int)DAT_060024d6);

    iStack_10 = iStack_10 + -1;

  } while (iStack_10 != 0);

  return iVar1 + 1;

}
