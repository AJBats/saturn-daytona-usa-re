extern int DAT_0603f42c;

extern int DAT_0603f4c2;

void FUN_0603f3f6(param_1, param_2, param_3)
    int *param_1;
    int param_2;
    unsigned int param_3;
{

  int iVar1;

  int iVar2;

  unsigned int uVar3;

  iVar2 = (int)DAT_0603f42c;

  if (*param_1 != 0) {

    if ((param_1[2] == -1) || ((int)DAT_0603f4c2 <= param_1[2])) {

      (*0x0603B21C)(*param_1,1,param_1[1],iVar2);

      param_1[2] = 0;

    }

    iVar1 = param_1[2];

    uVar3 = param_3;

    if ((unsigned int)(iVar2 - iVar1) <= param_3) {

      uVar3 = iVar2 - iVar1;

    }

    (*0x060360FC)(param_2,param_1[1] + iVar1,uVar3);

    param_1[2] = param_1[2] + uVar3;

    if (uVar3 < param_3) {

      (*0x0603B21C)(*param_1,1,param_1[1],iVar2);

      (*0x060360FC)(uVar3 + param_2,param_1[1],param_3 - uVar3);

      param_1[2] = param_3 - uVar3;

    }

    return;

  }

  (*0x06036D78)(param_2,0,param_3);

  return;

}
