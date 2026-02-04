extern int DAT_0602d48a;

extern int DAT_0602d48c;

extern int DAT_0602d48e;

extern int DAT_0602d490;

extern int DAT_0602d492;

extern int DAT_0602d494;

extern int DAT_0602d496;

extern int DAT_0602d542;

extern int DAT_0602d544;

extern int DAT_0602d546;

extern int DAT_0602d548;

extern int DAT_0602d54a;

extern int DAT_0602d5f0;

extern int DAT_0602d5f2;

extern int DAT_0602d5f4;

extern int DAT_0602d5f6;

extern int DAT_0602d62c;

extern int DAT_0602d62e;

extern int DAT_0602d67c;

extern int DAT_0602d67e;

extern int DAT_0602d680;

extern int DAT_0602d682;

extern int DAT_0602d6be;

extern int DAT_0602d6c2;

extern int DAT_0602d730;

extern int DAT_0602d732;

extern int DAT_0602d790;

extern int DAT_0602d792;

extern int PTR_DAT_0602d54c;

extern int PTR_DAT_0602d54c;

extern int PTR_DAT_0602d5f8;

extern int PTR_DAT_0602d5f8;

extern int PTR_DAT_0602d794;

extern int PTR_DAT_0602d794;

extern int PTR_DAT_0602d7dc;

extern int PTR_DAT_0602d7dc;

extern int FUN_0602d7e4();

void FUN_0602d43c()
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

  iVar11 = *(int *)((int)DAT_0602d48a + (int)unaff_r14);

  iVar12 = (int)DAT_0602d48c;

  if (*(short *)((int)DAT_0602d48e + (int)unaff_r14) < 1) {

    iVar5 = (int)DAT_0602d490;

    if ((((int)DAT_0602d492 <= (int)unaff_r14[2]) &&

        (*(int *)((int)DAT_0602d494 + (int)unaff_r14) != 0)) &&

       (*(int *)((int)DAT_0602d496 + (int)unaff_r14) <= (int)0x00006800)) {

      iVar10 = iVar11;

      if (iVar11 <= iVar5) {

        if (-iVar5 <= iVar11) goto LAB_0602d4a4;

        iVar10 = -iVar11;

      }

      iVar10 = iVar10 - iVar5;

      if (iVar10 < 5) {

        iVar10 = 4;

      }

      else if (9 < iVar10) {

        iVar10 = 10;

      }

      *(short *)(iVar12 + (int)unaff_r14) = (short)iVar10;

    }

  }

LAB_0602d4a4:

  iVar5 = (int)*(short *)(iVar12 + (int)unaff_r14);

  puVar2 = unaff_r14;

  if (0 < iVar5) {

    if (*(int *)((int)DAT_0602d542 + (int)unaff_r14) == 0) {

      iVar5 = iVar5 + -2;

    }

    *(short *)(iVar12 + (int)unaff_r14) = (short)(iVar5 + -1);

    uVar7 = 0;

    if (-1 < (int)(0x000A0000 + (iVar5 + -1) * -0x10000)) {

      lVar1 = (long long)*(int *)((int)DAT_0602d544 + (int)unaff_r14) *

              (long long)(int)(0x000A0000 + (iVar5 + -1) * -0x10000);

      puVar3 = (int *)(int)DAT_0602d546;

      *puVar3 = 0x000A0000;

      puVar3[4] = (int)(short)((unsigned long long)lVar1 >> 0x20);

      puVar3[5] = (unsigned int)lVar1 & 0xffff0000;

      uVar7 = puVar3[7];

    }

    *(int *)((int)DAT_0602d544 + (int)unaff_r14) = uVar7;

    puVar2 = (unsigned int *)FUN_0602d7e4();

  }

  iVar12 = (*(void(*)())0x06027344)(*(int *)((int)DAT_0602d548 + (int)puVar2));

  lVar1 = (long long)*(int *)((int)DAT_0602d544 + (int)unaff_r14) *

          (long long)*(int *)((int)DAT_0602d54a + (int)unaff_r14);

  lVar1 = (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) *

          (long long)(int)*(short *)((int)PTR_DAT_0602d54c + (int)unaff_r14);

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

    puVar2 = (unsigned int *)(int)DAT_0602d5f0;

    *puVar2 = local_8;

    puVar2[4] = (int)(short)((unsigned long long)lVar1 >> 0x28);

    puVar2[5] = uVar6 << 0x10;

    puVar8 = (char *)(*(void(*)())0x06027378)(puVar2[7]);

    if (puVar8 == (char *)0x0) {

      puVar8 = (char *)(int)*(char *)((int)DAT_0602d5f2 + (int)unaff_r14);

    }

  }

  sVar9 = (short)puVar8;

  if (((0 < *(short *)((int)DAT_0602d5f4 + (int)unaff_r14)) && ((int)unaff_r14[2] < 0x46)) &&

     ((int)(*(unsigned int *)((int)PTR_DAT_0602d5f8 + (int)unaff_r14) ^

           *(unsigned int *)((int)DAT_0602d5f6 + (int)unaff_r14)) < 0)) {

    iVar10 = (int)puVar8 << 0x10;

    iVar5 = (*(void(*)())0x06027344)((short)((int)*(unsigned int *)((int)DAT_0602d5f6 + (int)unaff_r14) >> 1) * 9);

    sVar9 = (short)((unsigned long long)((long long)iVar10 * (long long)iVar5) >> 0x20);

    if (sVar9 < 0) {

      sVar9 = 0;

    }

  }

  iVar5 = sVar9 * 3;

  iVar10 = -*(int *)((int)PTR_DAT_0602d5f8 + (int)unaff_r14);

  if (iVar10 < 0) {

    iVar5 = sVar9 * -3;

    if (iVar10 <= iVar5) goto LAB_0602d610;

  }

  else if (iVar5 <= iVar10) goto LAB_0602d610;

  iVar5 = iVar10;

LAB_0602d610:

  iVar5 = iVar5 - (short)((unsigned long long)((long long)(iVar11 << 0x10) * (long long)iVar12) >> 0x20);

  iVar12 = (int)DAT_0602d62e;

  iVar11 = -iVar12;

  if ((iVar11 < iVar5) && (iVar11 = iVar5, iVar12 <= iVar5)) {

    iVar11 = iVar12;

  }

  *(int *)((int)DAT_0602d62c + (int)unaff_r14) = iVar11;

  iVar12 = *(int *)((int)DAT_0602d67c + (int)unaff_r14);

  iVar11 = iVar11 + iVar12;

  *(int *)((int)DAT_0602d67c + (int)unaff_r14) = iVar11 - (-(iVar12 - iVar11) >> 3);

  lVar1 = (long long)*(int *)((int)DAT_0602d680 + (int)unaff_r14) *

          (long long)*(int *)((int)DAT_0602d67e + (int)unaff_r14);

  lVar1 = (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) *

          (long long)(int)*(short *)((int)DAT_0602d682 + (int)unaff_r14);

  if (local_8 != 0) {

    puVar2 = (unsigned int *)(int)DAT_0602d6be;

    *puVar2 = local_8;

    puVar2[4] = (int)(short)((unsigned long long)lVar1 >> 0x28);

    puVar2[5] = ((unsigned int)lVar1 >> 0x18 | (int)((unsigned long long)lVar1 >> 0x20) << 8) << 0x10;

    (*(void(*)())0x06027378)(puVar2[7]);

  }

  (*(void(*)())0x0602ECCC)(DAT_0602d6c2 + -0x32);

  uVar4 = *(unsigned int *)((int)DAT_0602d730 + (int)unaff_r14);

  uVar6 = uVar4 - *(int *)((int)DAT_0602d732 + (int)unaff_r14);

  if ((int)(uVar6 ^ uVar4) < 0) {

    iVar11 = 0x00000FE0;

    if ((int)uVar4 < 0) {

      iVar11 = -0x00000FE0;

    }

    (*(void(*)())0x0602ECCC)(iVar11);

  }

  iVar11 = (*(void(*)())0x0602ECCC)();

  *(unsigned int *)((int)DAT_0602d790 + (int)unaff_r14) =

       (iVar11 - uVar6) -

       ((int)-(*(int *)((int)DAT_0602d790 + (int)unaff_r14) - (iVar11 - uVar6)) >> 3);

  iVar11 = (int)PTR_DAT_0602d794;

  if ((int)DAT_0602d792 < (int)unaff_r14[2]) {

    if (0xFFFFCD80 < *(int *)(iVar11 + (int)unaff_r14)) {

      if (-0xFFFFCD80 <= *(int *)(iVar11 + (int)unaff_r14)) {

        *unaff_r14 = *unaff_r14 | (unsigned int)0x20000000 | 0x40000000;

      }

    }

    else {

      *unaff_r14 = *unaff_r14 | 0x10000000 | 0x40000000;

    }

  }

  iVar5 = *(int *)(iVar11 + (int)unaff_r14);

  iVar12 = 0xFFFFCC00;

  if ((iVar5 <= 0xFFFFCC00) || (iVar12 = -0xFFFFCC00, iVar12 < iVar5)) {

    *(short *)((int)PTR_DAT_0602d7dc + (int)unaff_r14) = 1;

    iVar5 = iVar12;

  }

  *(int *)(iVar11 + (int)unaff_r14) = iVar5;

  return;

}
