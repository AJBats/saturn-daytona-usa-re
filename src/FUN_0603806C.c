extern int DAT_06038106;

extern int DAT_06038108;

void FUN_0603806c(param_1)
    char *param_1;
{

  char *puVar1;

  int uVar2;

  char *puVar3;

  int extraout_r3;

  int uVar4;

  unsigned int uVar5;

  int iVar6;

  int iVar7;

  char *puVar8;

  int *piVar9;

  int local_30 [8];

  char local_10 [4];

  puVar1 = 0x00010000;

  puVar8 = local_10;

  iVar7 = 0x200;

  uVar4 = 0;

  param_1[2] = 0;

  param_1[1] = 0;

  *param_1 = 0;

  param_1[3] = 0;

  *(int *)(param_1 + 8) = 0;

  *(int *)(param_1 + 0xc) = 0;

  param_1[4] = 0;

  uVar5 = 0;

  do {

    if ((uVar5 & 0xffff) < 0x40) {

      *(int *)(param_1 + (uVar5 & 0xffff) << 2 + (int)DAT_06038108) = uVar4;

    }

    iVar6 = (int)(short)((short)uVar5 * 0xc);

    *(int *)(param_1 + iVar6 + 0x10) = uVar4;

    *(char **)(puVar8 + -0x14) = puVar8 + -0x14;

    (*(int(*)())0x06035BC8)();

    *(int *)(puVar8 + -0x18) = 0;

    *(int *)(puVar8 + -0x1c) = 0x40F00000;

    puVar3 = puVar8 + -0xc;

    piVar9 = (int *)(puVar8 + -0x20);

    puVar8 = puVar8 + -0x20;

    *piVar9 = (int)puVar3;

    (*(int(*)())0x060359E4)();

    uVar2 = (*(int(*)())0x060357B8)();

    uVar5 = uVar5 + 1;

    *(int *)(extraout_r3 + 4) = uVar2;

    *(char **)(param_1 + iVar6 + 0x18) = puVar1;

  } while ((int)(uVar5 & 0xffff) < iVar7);

  return;

}
