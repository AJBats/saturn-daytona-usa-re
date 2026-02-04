extern int DAT_060052f6;

extern int DAT_0600537a;

void FUN_06005294(param_1, param_2, param_3)
    int *param_1;
    int *param_2;
    int *param_3;
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  iVar3 = param_2[1];

  iVar6 = *param_2 - *param_1;

  iVar4 = param_1[1];

  iVar5 = param_2[2] - param_1[2];

  iVar1 = (*0x0602744C)(iVar6,iVar5);

  if (iVar6 < 0) {

    iVar6 = -iVar6;

  }

  if (iVar5 < 0) {

    iVar5 = -iVar5;

  }

  if (iVar5 < iVar6) {

    iVar2 = (*0x06027552)(0x0000EC83,iVar6);

    iVar6 = (*0x06027552)((int)DAT_060052f6,iVar5);

  }

  else {

    iVar2 = (*0x06027552)(0x0000EC83,iVar5);

    iVar6 = (*0x06027552)((int)DAT_0600537a,iVar6);

  }

  iVar3 = (*0x0602744C)(iVar3 - iVar4,iVar2 + iVar6);

  if (*0x06078663 != '\0') {

    (*0x06026E60)(0xFFFF0000,0x00010000);

  }

  (*0x06026E94)(-iVar3);

  (*0x06026EDE)(iVar1);

  (*0x06026E2E)(-*param_1,-param_1[1],-param_1[2]);

  (*0x06035168)();

  *param_3 = iVar3;

  param_3[1] = -iVar1;

  param_3[2] = 0;

  return;

}
