extern int DAT_060303b6;

extern int DAT_06030402;

extern int DAT_0603045e;

extern int DAT_060304ac;

extern int DAT_060304ae;

extern int DAT_060304f0;

extern int DAT_060304f2;

extern int PTR_DAT_06030318;

extern int PTR_DAT_06030318;

extern int PTR_DAT_060303b8;

extern int PTR_DAT_060303b8;

extern int PTR_DAT_06030404;

extern int PTR_DAT_06030404;

extern int PTR_DAT_060304b0;

extern int PTR_DAT_060304b0;

void FUN_060302c6()
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  unsigned int uVar4;

  short sVar6;

  int iVar5;

  int uVar7;

  int iVar8;

  int iVar9;

  unsigned char bVar10;

  puVar2 = 0x0607ED88;

  iVar3 = *(int *)0x0607E944;

  if (*(short *)0x0607ED8C != 0) {

    iVar8 = *(int *)0x0607ED88;

    bVar10 = ((int *)0x0607ED90)[iVar8];

    *(unsigned short *)(DAT_060304ac + iVar3) = bVar10 & 3;

    *(int *)puVar2 = iVar8 + 2;

    uVar7 = 1;

    if ((bVar10 & 0x80) == 0) {

      uVar7 = 0x38;

      iVar8 = *(int *)(DAT_060304f0 + iVar3) + -2;

      if (iVar8 < 0x38) {

        iVar8 = 0x38;

      }

      *(int *)(DAT_060304f0 + iVar3) = iVar8;

      *(int *)(0x0000006C + iVar3) = 0;

    }

    else {

      iVar8 = (int)DAT_060304ae;

      *(int *)(iVar8 + iVar3) = 1;

      iVar8 = iVar8 + 8;

      iVar5 = *(int *)(iVar8 + iVar3);

      if (iVar5 <= PTR_DAT_060304b0) {

        iVar5 = iVar5 + 4;

      }

      *(int *)(iVar8 + iVar3) = iVar5;

    }

    if ((bVar10 & 0x40) == 0) {

      iVar8 = *(int *)(0x00000090 + iVar3);

      *(int *)(0x0000008C + iVar3) = iVar8;

      iVar8 = iVar8 + -5;

      if (iVar8 < 0x38) {

        iVar8 = 0x38;

      }

      *(int *)(0x00000090 + iVar3) = iVar8;

      *(int *)(0x00000088 + iVar3) = 0;

    }

    else {

      *(int *)(0x00000088 + iVar3) = uVar7;

      iVar8 = 0x00000090;

      iVar5 = *(int *)(0x00000090 + iVar3);

      iVar9 = (int)DAT_060304f2;

      *(int *)(0x0000008C + iVar3) = iVar5;

      if (iVar5 <= iVar9) {

        iVar5 = iVar5 + 5;

      }

      *(int *)(iVar8 + iVar3) = iVar5;

    }

    return;

  }

  uVar4 = (unsigned int)*(unsigned short *)0x06063D9A;

  iVar8 = (int)PTR_DAT_06030318;

  if (*(short *)0x0608188A < 1) {

    if ((uVar4 & (int)*(short *)0x06081896) == 0) {

      if ((uVar4 & (int)*(short *)0x06081894) == 0) {

        if ((uVar4 & (int)*(short *)0x06081892) == 0) {

          if ((uVar4 & (int)*(short *)0x06081890) != 0) {

            *(short *)(iVar8 + iVar3) = 0;

          }

        }

        else {

          *(short *)(iVar8 + iVar3) = 1;

        }

      }

      else {

        *(short *)(iVar8 + iVar3) = 2;

      }

    }

    else {

      *(short *)(iVar8 + iVar3) = 3;

    }

  }

  else if ((uVar4 & (int)*(short *)0x0608188A) == 0) {

    if ((uVar4 & (int)*(short *)0x06081888) != 0) {

      sVar6 = *(short *)(iVar8 + iVar3);

      if (sVar6 != 3) {

        sVar6 = sVar6 + 1;

      }

      *(short *)(iVar8 + iVar3) = sVar6;

    }

  }

  else {

    sVar6 = *(short *)(iVar8 + iVar3);

    if (sVar6 != 0) {

      sVar6 = sVar6 + -1;

    }

    *(short *)(iVar8 + iVar3) = sVar6;

  }

  bVar10 = (unsigned char)*(short *)(iVar8 + iVar3);

  uVar1 = *(unsigned short *)0x06063D98;

  uVar7 = 1;

  if ((uVar1 & *(unsigned short *)0x0608188C) == 0) {

    uVar7 = 0x38;

    iVar8 = *(int *)(DAT_06030402 + iVar3) + -2;

    if (iVar8 < 0x39) {

      iVar8 = 0x38;

    }

    *(int *)(DAT_06030402 + iVar3) = iVar8;

    *(int *)(0x0000006C + iVar3) = 0;

  }

  else {

    bVar10 = bVar10 | 0x80;

    iVar8 = (int)DAT_060303b6;

    *(int *)(iVar8 + iVar3) = 1;

    iVar8 = iVar8 + 8;

    iVar5 = *(int *)(iVar8 + iVar3);

    if (iVar5 <= PTR_DAT_060303b8) {

      iVar5 = iVar5 + 4;

    }

    *(int *)(iVar8 + iVar3) = iVar5;

  }

  if ((uVar1 & *(unsigned short *)0x0608188E) == 0) {

    iVar8 = *(int *)(0x00000090 + iVar3);

    *(int *)(0x0000008C + iVar3) = iVar8;

    iVar8 = iVar8 + -5;

    if (iVar8 < 0x38) {

      iVar8 = 0x38;

    }

    *(int *)(0x00000090 + iVar3) = iVar8;

    *(int *)(0x00000088 + iVar3) = 0;

  }

  else {

    bVar10 = bVar10 | 0x40;

    *(int *)(0x00000088 + iVar3) = uVar7;

    iVar8 = 0x00000090;

    iVar5 = *(int *)(0x00000090 + iVar3);

    iVar9 = (int)PTR_DAT_06030404;

    *(int *)(0x0000008C + iVar3) = iVar5;

    if (iVar5 <= iVar9) {

      iVar5 = iVar5 + 5;

    }

    *(int *)(iVar8 + iVar3) = iVar5;

  }

  puVar2 = 0x0607ED88;

  iVar8 = *(int *)0x0607ED88;

  ((int *)0x0607ED90)[iVar8] = bVar10;

  iVar3 = iVar8 + 2;

  if ((int)DAT_0603045e <= iVar8 + 2) {

    iVar3 = iVar8;

  }

  *(int *)puVar2 = iVar3;

  return;

}
