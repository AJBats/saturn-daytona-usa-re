extern int DAT_0602f842;

extern int DAT_0602f844;

extern int DAT_0602f890;

extern int DAT_0602f8f0;

extern int DAT_0602f8f2;

extern int DAT_0602f97e;

extern int DAT_0602f980;

extern int DAT_0602f982;

extern void FUN_0602eccc();

void FUN_0602f7ea()
{

  char cVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  short *psVar5;

  int iVar6;

  int uVar7;

  unsigned int uVar8;

  unsigned int *puVar9;

  puVar3 = 0x0601D5F4;

  puVar9 = *(unsigned int **)0x0607E944;

  iVar6 = (int)*(short *)(0x0602FD3C + *(int *)0x0607EAD8 * 4);

  if (iVar6 != 0) {

    psVar5 = (short *)(0x0602FD48 +

                      *(short *)((int)(0x0602FD3C + *(int *)0x0607EAD8 * 4) + 2));

    do {

      if (((int)*psVar5 <= *(int *)((int)DAT_0602f842 + (int)puVar9)) &&

         (*(int *)((int)DAT_0602f842 + (int)puVar9) <= (int)psVar5[1])) {

        if (0x100000 < (int)puVar9[5]) {

          if (((int)DAT_0602f844 & *puVar9) == 0) {

            *puVar9 = *puVar9 | (int)DAT_0602f844;

            (*puVar3)(4,0xAE0601FF);

          }

        }

        goto LAB_0602f87c;

      }

      iVar6 = iVar6 + -1;

      psVar5 = psVar5 + 2;

    } while (iVar6 != 0);

    if (((int)DAT_0602f890 & *puVar9) != 0) {

      *puVar9 = *puVar9 & ~(int)DAT_0602f890;

      (*puVar3)(4,0xAE0600FF);

    }

  }

LAB_0602f87c:

  iVar6 = FUN_0602eccc();

  if (iVar6 < 2) {

    iVar6 = 1;

  }

  else if (0x7e < iVar6) {

    iVar6 = 0x7f;

  }

  (*puVar3)(1,iVar6);

  if ((*(int *)((int)DAT_0602f8f0 + (int)puVar9) == 0) &&

     (sVar2 = *(short *)((int)DAT_0602f8f2 + (int)puVar9), sVar2 != 0)) {

    if (sVar2 == 10) {

      uVar7 = 0xAE111EFF;

      if (*0x0605D241 != '\0') {

        uVar7 = 0xAE1142FF;

      }

    }

    else {

      if (sVar2 != 3) goto LAB_0602f910;

      uVar7 = 0xAE111CFF;

      if (*0x0605D241 != '\0') {

        uVar7 = 0xAE1140FF;

      }

    }

    (*puVar3)(0,uVar7);

  }

LAB_0602f910:

  if (*(int *)((int)DAT_0602f97e + (int)puVar9) == 0x2c) {

    uVar7 = 0xAE111BFF;

    if (*0x0605D241 != '\0') {

      uVar7 = 0xAE113FFF;

    }

    (*puVar3)(0,uVar7);

  }

  puVar4 = 0x0602FD9F;

  cVar1 = *0x0602FD9F;

  if (cVar1 == '\0') {

LAB_0602f93e:

    if ((puVar9[3] == 0) || (*(int *)((int)puVar9 + (int)DAT_0602f980) < 0xc9)) goto LAB_0602f95a;

    *puVar4 = 10;

    uVar7 = 1;

  }

  else {

    uVar7 = 0;

    *0x0602FD9F = cVar1 + -1;

    if (cVar1 != '\x01') goto LAB_0602f93e;

  }

  (*puVar3)(3,uVar7);

LAB_0602f95a:

  uVar8 = *(unsigned int *)((int)puVar9 + (int)DAT_0602f982);

  if ((int)uVar8 < 0) {

    uVar8 = -uVar8;

  }

  uVar8 = uVar8 >> 10;

  if (7 < uVar8) {

    uVar8 = 7;

  }

  (*puVar3)(2,uVar8);

  return;

}
