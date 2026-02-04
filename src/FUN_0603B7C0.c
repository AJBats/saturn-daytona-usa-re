extern int DAT_0603b838;

int FUN_0603b7c0(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  puVar2 = 0x0603F202;

  puVar1 = 0x0603F216;

  uVar4 = (unsigned int)DAT_0603b838;

  for (iVar5 = 0; iVar5 < param_1[1]; iVar5 = iVar5 + 1) {

    if (*param_1 == 0) {

      uVar3 = (*(void(*)())puVar2)(iVar5,param_1[2]);

    }

    else {

      uVar3 = (*(void(*)())puVar1)(iVar5,param_1[2]);

    }

    if ((uVar3 & uVar4) != 0) break;

  }

  if (param_1[1] < iVar5) {

    iVar5 = 0;

  }

  else {

    iVar5 = iVar5 + 1;

  }

  return iVar5;

}
