extern int DAT_0602ce44;

extern int DAT_0602ce46;

extern int DAT_0602ce48;

extern int DAT_0602ce4a;

extern int DAT_0602cfda;

extern int DAT_0602cfdc;

extern int DAT_0602cfde;

extern int DAT_0602cfe0;

extern int DAT_0602d020;

extern int DAT_0602d022;

extern int DAT_0602d04e;

extern int DAT_0602d050;

extern int DAT_0602d074;

extern int DAT_0602d076;

extern int DAT_0602d078;

extern int PTR_DAT_0602cf34;

extern int PTR_DAT_0602cf34;

extern int PTR_DAT_0602d024;

extern int PTR_DAT_0602d024;

void FUN_0602cdf6()
{

  int bVar1;

  long long lVar2;

  char *puVar3;

  int in_r0;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int extraout_r2;

  int extraout_r3;

  unsigned int uVar8;

  int iVar9;

  int iVar10;

  unsigned int uVar11;

  unsigned int uVar12;

  int iVar13;

  char *puVar14;

  int unaff_r14;

  puVar3 = 0x06027348;

  iVar13 = (int)DAT_0602ce44;

  iVar10 = *(int *)(DAT_0602ce4a + in_r0);

  bVar1 = *(int *)(DAT_0602ce48 + in_r0) + *(int *)(DAT_0602ce46 + in_r0) <= iVar10;

  if (bVar1) {

    iVar13 = -iVar13;

  }

  iVar9 = *(int *)(DAT_0602ce48 + in_r0) + *(int *)(DAT_0602ce46 + in_r0) + iVar13;

  iVar10 = iVar10 + iVar13;

  iVar4 = (*(int(*)())0x06027348)(iVar9 - iVar10);

  iVar5 = (*(int(*)())puVar3)(iVar10);

  if (iVar4 != 0) {

    puVar14 = 0x0002C000;

    iVar4 = (*(int(*)())0x0602755C)((int)((unsigned long long)((long long)iVar5 * (long long)(int)0x0002C000) >> 0x20)

                       << 0x10 | (unsigned int)((long long)iVar5 * (long long)(int)0x0002C000) >> 0x10);

    if (iVar4 < 0) {

      iVar4 = -iVar4;

    }

    iVar6 = (*(int(*)())puVar3)(iVar9);

    iVar5 = (*(int(*)())0x06027344)(iVar9);

    iVar5 = (*(int(*)())0x0602744C)(extraout_r3,

                       ((int)((unsigned long long)((long long)iVar5 * (long long)iVar4) >> 0x20) << 0x10 |

                       (unsigned int)((long long)iVar5 * (long long)iVar4) >> 0x10) + ((unsigned int)puVar14 >> 1));

    iVar7 = (*(int(*)())puVar3)(iVar5);

    if (iVar7 != 0) {

      iVar4 = (*(int(*)())0x0602755C)((int)((unsigned long long)((long long)iVar6 * (long long)iVar4) >> 0x20) << 0x10 |

                         (unsigned int)((long long)iVar6 * (long long)iVar4) >> 0x10);

      if (iVar4 < 0) {

        iVar4 = -iVar4;

      }

      if (bVar1) {

        iVar4 = -iVar4;

      }

      if (iVar4 != 0) {

        iVar4 = (*(int(*)())0x0602755C)(*(int *)(unaff_r14 + 0xc));

        bVar1 = iVar4 < 0;

        if (bVar1) {

          iVar4 = -iVar4;

        }

        uVar11 = (unsigned int)((unsigned long long)((long long)0x28BE60DB * (long long)iVar4) >> 0x20) & 0xffff;

        if (bVar1) {

          uVar11 = -uVar11;

        }

        goto LAB_0602cf08;

      }

    }

  }

  uVar11 = 0;

  iVar5 = iVar9;

LAB_0602cf08:

  iVar4 = 0x00000154;

  *(int *)(unaff_r14 + 0x30) =

       (int)(short)((short)*(int *)(unaff_r14 + 0x30) + (short)uVar11);

  *(unsigned int *)(iVar4 + unaff_r14) = uVar11;

  if (iVar10 == iVar9) {

    iVar5 = iVar9;

  }

  iVar5 = iVar5 - iVar13;

  if (*(short *)(PTR_DAT_0602cf34 + unaff_r14) == 1) {

    iVar5 = *(int *)(0x0000002C + unaff_r14);

  }

  else {

    *(int *)(0x0000002C + unaff_r14) = iVar5;

  }

  iVar10 = (int)(short)((short)*(int *)(unaff_r14 + 0x30) + (short)iVar5);

  iVar13 = *(int *)(unaff_r14 + 0x28);

  *(int *)(unaff_r14 + 0x28) = iVar10;

  iVar10 = (*(int(*)())0x06027348)(iVar10 - iVar13);

  lVar2 = (long long)

          (int)((int)((unsigned long long)((long long)iVar10 * (long long)extraout_r2) >> 0x20) << 0x10 |

               (unsigned int)((long long)iVar10 * (long long)extraout_r2) >> 0x10) *

          (long long)(int)0x0028D0FA;

  lVar2 = (long long)(int)((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) *

          (long long)(int)0x03200000;

  uVar11 = (int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10;

  iVar10 = (int)DAT_0602cfdc;

  iVar13 = *(int *)(DAT_0602cfda + unaff_r14);

  iVar4 = *(int *)(iVar10 + unaff_r14);

  *(int *)(DAT_0602cfda + unaff_r14) = ((int)(uVar11 - iVar13) >> 2) + iVar13;

  *(int *)(iVar10 + unaff_r14) = ((int)(uVar11 - iVar4) >> 2) + iVar4;

  uVar8 = ((int)(short)((short)*(int *)(unaff_r14 + 0x30) - (short)*(int *)(unaff_r14 + 0x28)

                       ) >> 2) + *(int *)(unaff_r14 + 0x28) +

          (*(int *)(DAT_0602cfde + unaff_r14) >> 5);

  uVar12 = *(unsigned int *)(0x06063EEC + 4);

  uVar11 = uVar12;

  if ((int)uVar12 < 0) {

    uVar11 = -uVar12;

  }

  if (((int)DAT_0602cfe0 <= (int)uVar11) && ((int)(uVar12 ^ uVar8) < 0)) {

    if ((int)uVar12 < 0) {

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar12 = uVar12 | 0xFFFF0000;

    }

  }

  *(int *)(0x06063EEC + 4) = (int)(uVar8 + uVar12) >> 1;

  iVar13 = *(int *)(DAT_0602d020 + unaff_r14);

  iVar10 = *(int *)(unaff_r14 + 0x30) - iVar13;

  iVar4 = 0x258;

  if ((PTR_DAT_0602d024 < iVar10) || (iVar10 <= -(int)PTR_DAT_0602d024)) {

    iVar10 = (int)DAT_0602d04e;

    if (iVar13 < 0) {

      iVar10 = -iVar10;

    }

    iVar13 = iVar13 + iVar10;

    iVar10 = *(int *)(unaff_r14 + 0x30) - iVar13;

    if ((DAT_0602d050 < iVar10) || (iVar10 <= -(int)DAT_0602d050)) {

      *(int *)(iVar4 + unaff_r14) = 0;

      return;

    }

    iVar10 = *(int *)(iVar4 + unaff_r14) + 1;

    *(int *)(iVar4 + unaff_r14) = iVar10;

  }

  else {

    iVar10 = *(int *)(iVar4 + unaff_r14) + 1;

    *(int *)(iVar4 + unaff_r14) = iVar10;

  }

  if (DAT_0602d074 <= iVar10) {

    iVar13 = iVar13 - *(int *)(DAT_0602d076 + unaff_r14);

    iVar4 = (int)DAT_0602d078;

    iVar10 = -iVar4;

    if ((iVar10 < iVar13) && (iVar10 = iVar13, iVar4 < iVar13)) {

      iVar10 = iVar4;

    }

    *(int *)(unaff_r14 + 0x30) = *(int *)(unaff_r14 + 0x30) + iVar10;

  }

  return;

}
