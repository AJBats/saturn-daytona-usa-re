extern int DAT_0603fb22;

extern int DAT_0603fb24;

extern int DAT_0603fcb6;

extern int FUN_0603fc60();
extern int FUN_0603fce4();
extern int FUN_0603ff9c();

unsigned short FUN_0603face(param_1, param_2)
    int *param_1;
    int *param_2;
{

  unsigned char bVar1;

  unsigned short uVar3;

  int iVar2;

  int uVar4;

  int uVar5;

  int uVar6;

  uVar6 = 0;

  uVar5 = *param_1;

  uVar4 = param_1[2];

  if ((int)param_1[5] < 1) {

    *param_2 = 0;

    return 5;

  }

  if ((*(unsigned char *)(param_1 + 0xd) & DAT_0603fb22) != DAT_0603fb22) {

    *param_2 = 0;

    return *(unsigned char *)(param_1 + 0xd) & DAT_0603fb24;

  }

  uVar3 = *(unsigned char *)(param_1 + 0xd) & DAT_0603fb24;

  bVar1 = (unsigned char)DAT_0603fb22;

  if (uVar3 == 0) {

    FUN_0603fc60(param_1,uVar5,uVar4);

    if (param_1[1] == 0) goto LAB_0603fc40;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 1;

LAB_0603fb50:

    FUN_0603fce4(param_1,uVar5,uVar4);

    if (param_1[3] == 0) goto LAB_0603fc40;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 2;

LAB_0603fb74:

    iVar2 = (*param_1[9])(param_1[8]);

    if (iVar2 == 0) goto LAB_0603fc40;

    FUN_0603ff9c(param_1);

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 3;

LAB_0603fba0:

    iVar2 = (*param_1[0xb])(param_1[8]);

    if (0 < iVar2) goto LAB_0603fc40;

    uVar6 = 1;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 4;

  }

  else {

    if (uVar3 == 1) goto LAB_0603fb50;

    if (uVar3 == 2) goto LAB_0603fb74;

    if (uVar3 == 3) goto LAB_0603fba0;

    if (uVar3 != 4) goto LAB_0603fc40;

  }

  if (param_1[7] == *(int *)(param_1[1] + 8)) {

    (*(void(*)())0x0603F91C)(uVar5,param_1[1],0xffffffff);

    param_1[6] = param_1[6] + *(int *)(param_1[1] + 0xc);

    param_1[1] = 0;

  }

  (*(void(*)())0x0603F91C)(uVar4,param_1[3],0xffffffff);

  param_1[3] = 0;

  if ((int)param_1[6] < (int)param_1[5]) {

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1;

  }

  else {

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 5;

  }

LAB_0603fc40:

  *param_2 = uVar6;

  return *(unsigned char *)(param_1 + 0xd) & DAT_0603fcb6;

}
