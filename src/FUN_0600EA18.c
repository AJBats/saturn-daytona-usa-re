extern int DAT_0600ea76;

extern int DAT_0600eafa;

extern int PTR_DAT_0600ea78;

extern int PTR_DAT_0600ea78;

extern int PTR_DAT_0600eafc;

extern int PTR_DAT_0600eafc;

void FUN_0600ea18(param_1)
    int param_1;
{

  short sVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int uVar5;

  unsigned int *puVar6;

  int *piVar7;

  unsigned int uVar8;

  int iVar9;

  int iVar10;

  puVar2 = 0x0605A228;

  puVar6 = (unsigned int *)(DAT_0600ea76 + param_1);

  uVar8 = puVar6[1] | puVar6[2] | puVar6[3] | *puVar6;

  if ((uVar8 != 0) && ((puVar6[3] & *puVar6 & puVar6[2] & puVar6[1] & 0x80) == 0)) {

    if ((uVar8 & 0x33) == 0) {

      iVar3 = *(int *)0x0605A228;

      *(int *)0x0605A228 = iVar3 + 1;

      if ((int)PTR_DAT_0600ea78 <= iVar3 + 1) {

        *(int *)puVar2 = 0;

        goto LAB_0600ea80;

      }

    }

    else {

      *(int *)0x0605A228 = 0;

    }

    return;

  }

  *(int *)0x0605A228 = 0;

LAB_0600ea80:

  iVar3 = *(int *)(param_1 + 0x10);

  piVar7 = (int *)((*(int *)(param_1 + DAT_0600eafa) * 8 + 3) * 0x10 + *(int *)0x0607EB88);

  iVar9 = *piVar7;

  iVar10 = piVar7[1];

  iVar4 = *(int *)(param_1 + 0x18);

  sVar1 = *(short *)((int)piVar7 + 10);

  uVar5 = *(int *)(param_1 + 0x30);

  *(int *)0x060786BC = 0x10;

  *(int *)0x060786C0 = iVar9 - iVar3 >> 4;

  *(int *)0x060786C4 = iVar10 - iVar4 >> 4;

  *(short *)0x060786C8 = (short)(sVar1 * 4 - (short)uVar5) >> 4;

  *(int *)(param_1 + 0xc) = 0;

  *(int *)(param_1 + 8) = 0;

  iVar3 = (int)PTR_DAT_0600eafc;

  *(int *)(param_1 + iVar3) = 0;

  *(int *)(param_1 + iVar3 + 4) = 0;

  *(int *)(param_1 + iVar3 + 0x40) = 1;

  *(int *)(param_1 + iVar3 + 0x44) = 1;

  *(int *)(param_1 + iVar3 + 0x48) = 1;

  *(int *)(param_1 + iVar3 + 0x4c) = 1;

  return;

}
