extern int DAT_0602d0d4;

extern int DAT_0602d0d6;

extern int DAT_0602d0d8;

extern int DAT_0602d0da;

extern int DAT_0602d0dc;

extern int DAT_0602d0de;

extern int DAT_0602d186;

extern int DAT_0602d188;

extern int DAT_0602d18a;

extern int DAT_0602d18c;

extern int DAT_0602d18e;

extern int DAT_0602d234;

extern int DAT_0602d236;

extern int DAT_0602d238;

extern int DAT_0602d23a;

extern int DAT_0602d2c4;

extern int DAT_0602d2c6;

extern int DAT_0602d2c8;

extern int DAT_0602d2ca;

extern int DAT_0602d306;

extern int DAT_0602d30a;

extern int DAT_0602d388;

extern int DAT_0602d38a;

extern int DAT_0602d3e8;

extern int DAT_0602d3ea;

extern int DAT_0602d432;

extern int PTR_DAT_0602d190;

extern int PTR_DAT_0602d190;

extern int PTR_DAT_0602d23c;

extern int PTR_DAT_0602d23c;

extern int PTR_DAT_0602d270;

extern int PTR_DAT_0602d270;

extern int PTR_DAT_0602d434;

extern int PTR_DAT_0602d434;

extern int FUN_0602d7e4();

void FUN_0602d08a()
{

  long long lVar1;

  unsigned int *puVar2;

  int *puVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  int uVar7;

  char *puVar8;

  short sVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  unsigned int *unaff_r14;

  unsigned int local_8;

  iVar11 = *(int *)((int)DAT_0602d0d4 + (int)unaff_r14);

  iVar12 = 0x168;

  if (*(short *)((int)DAT_0602d0d8 + (int)unaff_r14) < 1) {

    iVar5 = 0x2e0;

    if ((((int)DAT_0602d0dc <= (int)unaff_r14[2]) &&

        (*(int *)((int)DAT_0602d0de + (int)unaff_r14) <= 0x00000300)) &&

       (-0x00000300 <= *(int *)((int)DAT_0602d0de + (int)unaff_r14))) {

      iVar10 = iVar11;

      if (iVar11 <= iVar5) {

        if (-iVar5 <= iVar11) goto LAB_0602d0ec;

        iVar10 = -iVar11;

      }

      iVar10 = iVar10 - iVar5;

      if (iVar10 < 5) {

        iVar10 = 4;

      }

      else if (0xe < iVar10) {

        iVar10 = 0xf;

      }

      *(short *)(iVar12 + (int)unaff_r14) = (short)iVar10;

    }

  }

LAB_0602d0ec:

  iVar5 = (int)*(short *)(iVar12 + (int)unaff_r14);

  puVar2 = unaff_r14;

  if (0 < iVar5) {

    if (*(int *)((int)DAT_0602d186 + (int)unaff_r14) < 0) {

      iVar5 = iVar5 + -2;

    }

    *(short *)(iVar12 + (int)unaff_r14) = (short)(iVar5 + -1);

    uVar7 = 0;

    if (-1 < (int)(0x000F0000 + (iVar5 + -1) * -0x10000)) {

      lVar1 = (long long)*(int *)((int)DAT_0602d188 + (int)unaff_r14) *

              (long long)(int)(0x000F0000 + (iVar5 + -1) * -0x10000);

      puVar3 = (int *)-256;

      *puVar3 = 0x000F0000;

      puVar3[4] = (int)(short)((unsigned long long)lVar1 >> 0x20);

      puVar3[5] = (unsigned int)lVar1 & 0xffff0000;

      uVar7 = puVar3[7];

    }

    *(int *)((int)DAT_0602d188 + (int)unaff_r14) = uVar7;

    puVar2 = (unsigned int *)FUN_0602d7e4();

  }

  iVar12 = (*(int(*)())0x06027344)(*(int *)((int)DAT_0602d18c + (int)puVar2));

  lVar1 = (long long)*(int *)((int)DAT_0602d188 + (int)unaff_r14) *

          (long long)*(int *)((int)DAT_0602d18e + (int)unaff_r14);

  lVar1 = (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) *

          (long long)(int)*(short *)((int)PTR_DAT_0602d190 + (int)unaff_r14);

  uVar6 = (unsigned int)lVar1 >> 0x18 | (int)((unsigned long long)lVar1 >> 0x20) << 8;

  uVar4 = unaff_r14[3];

  if ((int)uVar4 < 0x00000100) {

    puVar8 = 0x00004000;

    if ((int)uVar6 < 0) {

      puVar8 = (char *)-(int)0x00004000;

    }

    local_8 = 0;

  }

  else {

    local_8 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)(int)uVar4) >> 0x20) << 0x10 |

              (unsigned int)((long long)(int)uVar4 * (long long)(int)uVar4) >> 0x10;

    puVar2 = (unsigned int *)-256;

    *puVar2 = local_8;

    puVar2[4] = (int)(short)((unsigned long long)lVar1 >> 0x28);

    puVar2[5] = uVar6 << 0x10;

    puVar8 = (char *)(*(int(*)())0x06027378)(puVar2[7]);

    if (puVar8 == (char *)0x0) {

      puVar8 = (char *)(int)*(char *)((int)DAT_0602d236 + (int)unaff_r14);

    }

  }

  sVar9 = (short)puVar8;

  if (((0 < *(short *)((int)DAT_0602d238 + (int)unaff_r14)) && ((int)unaff_r14[2] < 0x46)) &&

     ((int)(*(unsigned int *)((int)PTR_DAT_0602d23c + (int)unaff_r14) ^

           *(unsigned int *)(0x40 + (int)unaff_r14)) < 0)) {

    iVar10 = (int)(int)puVar8 << 0x10;

    iVar5 = (*(int(*)())0x06027344)((short)((int)*(unsigned int *)(0x40 + (int)unaff_r14) >> 1) * 9);

    sVar9 = (short)((unsigned long long)((long long)iVar10 * (long long)iVar5) >> 0x20);

    if (sVar9 < 0) {

      sVar9 = 0;

    }

  }

  iVar5 = sVar9 * 3;

  iVar10 = -*(int *)((int)PTR_DAT_0602d23c + (int)unaff_r14);

  if (iVar10 < 0) {

    iVar5 = sVar9 * -3;

    if (iVar10 <= iVar5) goto LAB_0602d254;

  }

  else if (iVar5 <= iVar10) goto LAB_0602d254;

  iVar5 = iVar10;

LAB_0602d254:

  iVar5 = iVar5 - (short)((unsigned long long)((long long)(iVar11 << 0x10) * (long long)iVar12) >> 0x20);

  iVar11 = -0x00000300;

  if ((iVar11 < iVar5) && (iVar11 = iVar5, 0x00000300 <= iVar5)) {

    iVar11 = 0x00000300;

  }

  *(int *)(0x178 + (int)unaff_r14) = iVar11;

  iVar12 = *(int *)((int)DAT_0602d2c4 + (int)unaff_r14);

  iVar11 = iVar11 + iVar12;

  *(int *)((int)DAT_0602d2c4 + (int)unaff_r14) = iVar11 - (-(iVar12 - iVar11) >> 3);

  lVar1 = (long long)*(int *)(0x108 + (int)unaff_r14) *

          (long long)*(int *)(0x140 + (int)unaff_r14);

  lVar1 = (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) *

          (long long)(int)*(short *)((int)DAT_0602d2ca + (int)unaff_r14);

  if (local_8 != 0) {

    puVar2 = (unsigned int *)-256;

    *puVar2 = local_8;

    puVar2[4] = (int)(short)((unsigned long long)lVar1 >> 0x28);

    puVar2[5] = ((unsigned int)lVar1 >> 0x18 | (int)((unsigned long long)lVar1 >> 0x20) << 8) << 0x10;

    (*(int(*)())0x06027378)(puVar2[7]);

  }

  (*(int(*)())0x0602ECCC)(DAT_0602d30a + -0x32);

  uVar4 = *(unsigned int *)(0x40 + (int)unaff_r14);

  uVar6 = uVar4 - *(int *)((int)DAT_0602d38a + (int)unaff_r14);

  if ((int)(uVar6 ^ uVar4) < 0) {

    iVar11 = 0x00000FE0;

    if ((int)uVar4 < 0) {

      iVar11 = -0x00000FE0;

    }

    (*(int(*)())0x0602ECCC)(iVar11);

  }

  iVar11 = (*(int(*)())0x0602ECCC)();

  *(unsigned int *)((int)DAT_0602d3e8 + (int)unaff_r14) =

       (iVar11 - uVar6) -

       ((int)-(*(int *)((int)DAT_0602d3e8 + (int)unaff_r14) - (iVar11 - uVar6)) >> 3);

  if (0x41 < (int)unaff_r14[2]) {

    if (0xFFFFCD80 < *(int *)((int)DAT_0602d3ea + (int)unaff_r14)) {

      if (-0xFFFFCD80 <= *(int *)((int)DAT_0602d3ea + (int)unaff_r14)) {

        *unaff_r14 = *unaff_r14 | (unsigned int)0x20000000 | 0x40000000;

      }

    }

    else {

      *unaff_r14 = *unaff_r14 | 0x10000000 | 0x40000000;

    }

  }

  iVar5 = (int)DAT_0602d432;

  iVar12 = *(int *)(iVar5 + (int)unaff_r14);

  iVar11 = 0xFFFFCC00;

  if ((iVar12 <= 0xFFFFCC00) || (iVar11 = -0xFFFFCC00, iVar11 < iVar12)) {

    *(short *)((int)PTR_DAT_0602d434 + (int)unaff_r14) = 1;

    iVar12 = iVar11;

  }

  *(int *)(iVar5 + (int)unaff_r14) = iVar12;

  return;

}
