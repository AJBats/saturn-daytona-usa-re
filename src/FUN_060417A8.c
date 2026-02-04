extern int DAT_060417d8;

extern int DAT_060417da;

extern int DAT_060417dc;

extern int DAT_060417de;

extern int DAT_060417e0;

extern int DAT_060417e2;

extern int DAT_0604185e;

int FUN_060417a8(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  if (param_1 == 0) {

    iVar2 = *(int *)0x060A5400;

    iVar1 = 0x58;

  }

  else if (param_1 == 1) {

    iVar1 = (int)DAT_060417d8;

    iVar2 = *(int *)0x060A5400;

  }

  else if (param_1 == 2) {

    iVar1 = (int)DAT_060417da;

    iVar2 = *(int *)0x060A5400;

  }

  else if (param_1 == 3) {

    iVar1 = 0x328;

    iVar2 = *(int *)0x060A5400;

  }

  else if (param_1 == 4) {

    iVar1 = 0x338;

    iVar2 = *(int *)0x060A5400;

  }

  else if (param_1 == 5) {

    iVar1 = 0x348;

    iVar2 = *(int *)0x060A5400;

  }

  else if (param_1 == 6) {

    iVar1 = 0x1e0;

    iVar2 = *(int *)0x060A5400;

  }

  else {

    if (param_1 != 7) goto LAB_06041818;

    iVar2 = *(int *)0x060A5400;

    iVar1 = 0x360;

  }

  param_1 = *(int *)(iVar2 + iVar1);

LAB_06041818:

  return param_1 == 0;

}
