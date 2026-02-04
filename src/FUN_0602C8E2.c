extern int DAT_0602c9cc;

extern int DAT_0602c9ce;

extern int DAT_0602c9d0;

extern int DAT_0602c9d2;

extern int DAT_0602c9d4;

extern int DAT_0602c9d6;

extern int DAT_0602c9d8;

extern int DAT_0602c9da;

extern int DAT_0602c9dc;

extern int DAT_0602c9de;

extern int DAT_0602c9e0;

extern int DAT_0602c9e2;

extern int DAT_0602c9e4;

extern int DAT_0602c9e6;

extern int DAT_0602ca72;

extern int DAT_0602ca74;

extern int DAT_0602ca76;

extern int PTR_DAT_0602c9e8;

extern int PTR_DAT_0602c9e8;

extern int PTR_DAT_0602ca78;

extern int PTR_DAT_0602ca78;

void FUN_0602c8e2()
{

  short sVar1;

  long long lVar2;

  int bVar3;

  int in_r0;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  int iVar7;

  int unaff_r14;

  bVar3 = 0;

  uVar5 = *(unsigned int *)(DAT_0602c9cc + in_r0);

  uVar6 = 0;

  if ((-1 < (int)(*(unsigned int *)(DAT_0602c9ce + in_r0) ^ uVar5)) && (uVar6 = uVar5, (int)uVar5 < 0)) {

    uVar6 = -uVar5;

  }

  iVar4 = *(int *)(in_r0 + 8);

  if ((0x46 < iVar4) &&

     ((int)(*(unsigned int *)(DAT_0602c9d2 + in_r0) ^ *(unsigned int *)(DAT_0602c9d0 + in_r0)) < 0)) {

    if (((int)DAT_0602c9d6 <= *(int *)(DAT_0602c9d4 + in_r0)) ||

       (-(int)DAT_0602c9d6 < *(int *)(DAT_0602c9d4 + in_r0))) {

      *(short *)(DAT_0602c9d8 + in_r0) = 10;

    }

  }

  if ((99 < iVar4) && (0xe00 <= (int)uVar6)) {

    bVar3 = 1;

  }

  if (*(short *)(DAT_0602c9dc + in_r0) != 0) {

    *(short *)(DAT_0602c9de + in_r0) = 0x10;

  }

  if ((0x500 < *(int *)(in_r0 + 0x1c)) &&

     ((((*(unsigned int *)(DAT_0602c9e2 + in_r0) & 4) != 0 && (*(int *)(DAT_0602c9cc + in_r0) < 0)) ||

      (((*(unsigned int *)(DAT_0602c9e2 + 4 + in_r0) & 4) != 0 && (-1 < *(int *)(DAT_0602c9cc + in_r0)))))))

  {

    *(short *)(DAT_0602c9d8 + in_r0) = 0x14;

  }

  iVar7 = 0x16a;

  iVar4 = (int)*(short *)(iVar7 + in_r0);

  if (bVar3) {

    iVar4 = iVar4 + 1;

  }

  if (-1 < iVar4) {

    *(short *)(iVar7 + in_r0) = (short)iVar4 + -1;

    iVar4 = (*(int(*)())0x0602ECCC)(*(int *)(PTR_DAT_0602c9e8 + in_r0),

                       *(int *)(DAT_0602c9d2 + in_r0),

                       (int)((unsigned long long)

                             ((long long)*(int *)(DAT_0602c9e6 + in_r0) *

                             (long long)*(int *)(DAT_0602c9e6 + in_r0)) >> 0x20));

    uVar6 = *(unsigned int *)(PTR_DAT_0602c9e8 + unaff_r14);

    lVar2 = (long long)(int)uVar6 * (long long)(iVar4 << 0x10);

    uVar5 = (int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10;

    if ((int)uVar5 < 0) {

      uVar5 = 0;

    }

    if ((int)uVar6 < 1) {

      uVar6 = 0;

    }

    else if ((int)uVar5 < (int)uVar6) {

      uVar6 = uVar5;

    }

    *(unsigned int *)(PTR_DAT_0602c9e8 + unaff_r14) = uVar6;

    in_r0 = unaff_r14;

  }

  sVar1 = *(short *)(iVar7 + 2 + in_r0);

  if (-1 < sVar1) {

    *(short *)(iVar7 + 2 + in_r0) = sVar1 + -1;

    *(short *)(DAT_0602ca72 + in_r0) = 0;

  }

  sVar1 = *(short *)(iVar7 + 4 + in_r0);

  if (0 < sVar1) {

    *(short *)(iVar7 + 4 + in_r0) = sVar1 + -1;

    *(short *)(DAT_0602ca74 + in_r0) =

         (short)((unsigned int)((int)0x00011999 * *(int *)(DAT_0602ca74 + in_r0)) >> 0x10);

  }

  sVar1 = *(short *)(iVar7 + 6 + in_r0);

  if (0 < sVar1) {

    *(short *)(iVar7 + 6 + in_r0) = sVar1 + -1;

    *(int *)(DAT_0602ca74 + in_r0) = 0x09D80000;

  }

  sVar1 = *(short *)(iVar7 + 8 + in_r0);

  if (0 < sVar1) {

    *(short *)(iVar7 + 8 + in_r0) = sVar1 + -1;

    *(int *)(DAT_0602ca74 + in_r0) = *(int *)(DAT_0602ca74 + in_r0) >> 1;

    *(int *)(DAT_0602ca76 + in_r0) = 0;

  }

  sVar1 = *(short *)(iVar7 + 10 + in_r0);

  if (0 < sVar1) {

    *(short *)(iVar7 + 10 + in_r0) = sVar1 + -1;

    if (-1 < *(int *)(PTR_DAT_0602ca78 + in_r0)) {

      *(int *)(DAT_0602ca76 + in_r0) = -*(int *)(PTR_DAT_0602ca78 + in_r0);

    }

  }

  return;

}
