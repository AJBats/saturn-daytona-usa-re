extern int DAT_0604222c;

extern int DAT_0604222e;

extern int DAT_0604230a;

extern int DAT_0604230c;

extern int DAT_0604230e;

extern int PTR_DAT_06042230;

extern int PTR_DAT_06042230;

int FUN_06042134(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  unsigned short uVar3;

  int iVar4;

  unsigned char bVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  short sVar9;

  char local_2c [16];

  puVar2 = 0x060A5400;

  puVar1 = 0x060349B6;

  iVar7 = (int)DAT_0604222c;

  for (iVar8 = 0; iVar8 < *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230); iVar8 = iVar8 + 1)

  {

    sVar9 = (short)iVar8;

    bVar5 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 4) != -2;

    iVar4 = iVar7;

    if ((int)bVar5) {

      iVar4 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 4);

    }

    iVar6 = iVar7;

    if (*(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 8) != -2) {

      bVar5 = bVar5 | 2;

      iVar6 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 8);

    }

    iVar4 = (*0x06036414)

                      (*(int *)

                        (*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc)),bVar5,iVar4

                       ,iVar6);

    if (iVar4 != 0) break;

    (*puVar1)(local_2c);

    *(char *)(*(int *)puVar2 + 0x40) = local_2c[0];

    *param_1 = *param_1 + 1;

  }

  if (iVar8 < *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230)) {

    iVar7 = 0;

    for (; iVar8 < *(int *)(*(int *)puVar2 + (int)DAT_0604230c); iVar8 = iVar8 + 1) {

      iVar4 = (int)(short)((short)iVar7 * 0xc);

      iVar6 = (int)(short)((short)iVar8 * 0xc);

      *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar4) =

           *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar6);

      *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar4 + 4) =

           *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar6 + 4);

      *(int *)(iVar4 + *(int *)puVar2 + (int)DAT_0604230a + 8) =

           *(int *)(iVar6 + *(int *)puVar2 + (int)DAT_0604230a + 8);

      iVar7 = iVar7 + 1;

    }

    *(int *)(*(int *)puVar2 + (int)DAT_0604230c) = iVar7;

  }

  else {

    *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230) = 0;

  }

  uVar3 = (*0x06035C4E)();

  if (((uVar3 & 0x40) != 0) && (*(int *)(*(int *)puVar2 + (int)DAT_0604230c) == 0)) {

    *(int *)(*(int *)puVar2 + (int)DAT_0604230e) = 0;

  }

  return *(int *)((int)DAT_0604230c + *(int *)puVar2);

}
