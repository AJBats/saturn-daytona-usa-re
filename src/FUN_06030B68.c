extern int DAT_06030bc2;

extern int DAT_06030be0;

extern int DAT_06030be2;

extern int DAT_06030c00;

extern int DAT_06030c02;

extern int DAT_06030c20;

extern int DAT_06030c22;

extern int DAT_06030c40;

extern int DAT_06030c42;

extern int DAT_06030cca;

extern int DAT_06030d22;

extern int DAT_06030da2;

extern void FUN_0603072e();
extern void FUN_06030dfe();

void FUN_06030b68(param_1, param_2, param_3, param_4)
    int param_1;
    short param_2;
    int param_3;
    int param_4;
{

  int bVar1;

  long long lVar2;

  int bVar3;

  unsigned int *puVar4;

  short sVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  unsigned int uVar9;

  int iVar10;

  unsigned int uVar11;

  unsigned int uVar12;

  unsigned int *unaff_r14;

  iVar8 = (int)(short)(param_2 - (short)unaff_r14[10]);

  if (((int)0x00001000 < iVar8) && (iVar8 < (int)0x00006FFF)) {

    FUN_0603072e();

    return;

  }

  if ((iVar8 < -(int)0x00001000) && (-(int)0x00006FFF < iVar8)) {

    FUN_0603072e();

    return;

  }

  *0x06089595 = 1;

  *(short *)((int)DAT_06030bc2 + (int)unaff_r14) = 4;

  if (param_1 == 0) {

    *unaff_r14 = *unaff_r14 | (int)DAT_06030be0;

    *(int *)((int)unaff_r14 + (int)DAT_06030be2) = 0;

    sVar5 = *(short *)(0x06063E9C + 0xe);

    iVar8 = *(int *)(0x06063E9C + 0x10);

LAB_06030c48:

    if (*0x0602FD9B == '\0') {

      *0x0602FD9B = 5;

    }

    iVar7 = unaff_r14[10] - iVar8;

    if (iVar7 < 0) {

      iVar7 = -iVar7;

    }

    iVar10 = (int)DAT_06030cca;

    iVar6 = iVar8;

    if ((iVar10 <= iVar7) && (iVar7 <= iVar10 * 3)) {

      iVar6 = iVar8 + iVar10 * 2;

    }

    unaff_r14[0xc] = (int)(short)iVar6;

    unaff_r14[10] = (int)(short)iVar6;

    puVar4 = (unsigned int *)(0x060A6000 + sVar5 * 0x34);

    uVar11 = puVar4[4];

    uVar12 = puVar4[5];

  }

  else {

    if (param_1 == 1) {

      *unaff_r14 = *unaff_r14 | (int)DAT_06030c20;

      *(int *)((int)unaff_r14 + (int)DAT_06030c22) = 2;

      sVar5 = *(short *)(0x06063EB0 + 0xe);

      iVar8 = *(int *)(0x06063EB0 + 0x10);

    }

    else {

      if (param_1 == 2) {

        *unaff_r14 = *unaff_r14 | (int)DAT_06030c00;

        *(int *)((int)unaff_r14 + (int)DAT_06030c02) = 1;

        sVar5 = *(short *)(0x06063EC4 + 0xe);

        iVar8 = *(int *)(0x06063EC4 + 0x10);

        goto LAB_06030c48;

      }

      *unaff_r14 = *unaff_r14 | (int)DAT_06030c40;

      *(int *)((int)unaff_r14 + (int)DAT_06030c42) = 3;

      sVar5 = *(short *)(0x06063ED8 + 0xe);

      iVar8 = *(int *)(0x06063ED8 + 0x10);

    }

    if (*0x0602FD9C == '\0') {

      *0x0602FD9C = 5;

    }

    iVar7 = unaff_r14[10] - iVar8;

    if (iVar7 < 0) {

      iVar7 = -iVar7;

    }

    iVar10 = (int)DAT_06030d22;

    iVar6 = iVar8;

    if ((iVar10 <= iVar7) && (iVar7 <= iVar10 * 3)) {

      iVar6 = iVar8 + iVar10 * 2;

    }

    unaff_r14[0xc] = (int)(short)iVar6;

    unaff_r14[10] = (int)(short)iVar6;

    puVar4 = (unsigned int *)(0x060A6000 + sVar5 * 0x34);

    uVar11 = puVar4[4];

    uVar12 = puVar4[5];

  }

  bVar3 = (*puVar4 & 0x1000000) == 0;

  iVar7 = ((int)((unsigned long long)((long long)(int)unaff_r14[4] * (long long)(int)uVar11) >> 0x20) << 0x10 |

          (unsigned int)((long long)(int)unaff_r14[4] * (long long)(int)uVar11) >> 0x10) + uVar12;

  if (bVar3) {

    iVar7 = iVar7 + unaff_r14[6];

  }

  uVar9 = (unsigned int)(iVar7 < 1);

  bVar1 = uVar9 != (*puVar4 >> 8 & 1);

  if (uVar11 == 0) {

    iVar8 = unaff_r14[6] + uVar12;

    if (iVar8 < 1) {

      iVar8 = -iVar8;

    }

    FUN_06030dfe(bVar1,iVar8);

    return;

  }

  if (!bVar3) {

    (*0x0602755C)(-uVar12,uVar11);

    FUN_06030dfe();

    return;

  }

  lVar2 = (long long)(int)-uVar11 * (long long)(int)(unaff_r14[6] + uVar12);

  iVar7 = (int)((unsigned long long)lVar2 >> 0x20);

  uVar12 = (unsigned int)lVar2;

  if ((iVar7 < DAT_06030da2) && (-(int)DAT_06030da2 < iVar7)) {

    lVar2 = (long long)(int)-uVar11 * (long long)(int)-uVar11;

    (*0x0602755C)

              (unaff_r14[4] + (iVar7 << 0x10 | uVar12 >> 0x10),

               ((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) + 0x10000,uVar9,

               param_4,bVar1,0,iVar8);

  }

  else {

    lVar2 = (long long)(int)-uVar11 * (long long)(int)-uVar11;

    (*0x0602755C)

              (((int)unaff_r14[4] >> 8) + (uVar12 >> 0x18 | iVar7 << 8),

               ((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) + 0x10000);

  }

  FUN_06030dfe();

  return;

}
