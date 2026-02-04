extern int DAT_06034976;

int FUN_06034900(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int uVar1;

  unsigned int uVar2;

  int iVar3;

  int in_pr;

  iVar3 = *(int *)0x0607E944;

  if ((*(int *)(iVar3 + 0x000000B8) == 0x2c) || (*(int *)(iVar3 + 0x000001BC) == 0x28)) {

    (*0x0601D5F4)(0x00000000,0xAE1128FF);

  }

  uVar2 = *(unsigned int *)(iVar3 + DAT_06034976);

  if ((int)uVar2 < 0) {

    uVar2 = -uVar2;

  }

  uVar2 = uVar2 >> 10;

  if (7 < uVar2) {

    uVar2 = 7;

  }

  uVar1 = (*0x0601D5F4)(2,uVar2,param_3,param_4,in_pr);

  return uVar1;

}
