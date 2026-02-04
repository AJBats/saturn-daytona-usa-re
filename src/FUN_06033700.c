extern int FUN_06033504();
extern int FUN_06033520();

int FUN_06033700(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int *param_3;
{

  short sVar1;

  short extraout_var;

  short extraout_var_00;

  int in_r0;

  short *psVar2;

  int iVar3;

  int iVar4;

  int uVar5;

  int uVar6;

  int iVar7;

  int in_pr;

  uVar6 = *param_3;

  sVar1 = *(short *)((int)param_3 + 0xe);

  iVar3 = *(int *)0x0607EAD8 * 0x10;

  uVar5 = *(int *)(0x06033894 + iVar3 + 8);

  (*(void(*)())0x0602755C)(param_3[1],*(int *)(0x06033894 + iVar3 + 0xc),param_3 + 4);

  (*(void(*)())0x0602755C)(uVar6,uVar5);

  iVar7 = (int)extraout_var_00;

  if ('\0' < (char)*0x06078663) {

    iVar7 = -iVar7;

  }

  psVar2 = (short *)(0x06033894 + iVar3);

  iVar7 = *psVar2 - iVar7;

  iVar3 = (int)psVar2[1] - (int)extraout_var;

  if ('\0' < (char)*0x06078663) {

    iVar7 = iVar7 + psVar2[2];

    iVar3 = iVar3 + psVar2[3];

  }

  iVar4 = -(int)sVar1;

  FUN_06033520(iVar4,iVar7 + iVar4,iVar3 + iVar4,iVar7 + sVar1,in_pr,param_3);

  (*(void(*)())0x060280F8)(0x06062970,*(int *)0x060785FC);

  FUN_06033504();

  return in_r0;

}
