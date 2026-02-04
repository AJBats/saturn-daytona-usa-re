extern int DAT_06030b24;

extern int DAT_06030b26;

extern int DAT_06030b28;

extern int DAT_06030b2a;

extern int DAT_06030da2;

extern int PTR_DAT_06030b2c;

extern int PTR_DAT_06030b2c;

extern void FUN_06030dfe();

void FUN_06030a9c(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    int param_4;
{

  long long lVar1;

  int iVar2;

  unsigned int *puVar3;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  unsigned int *unaff_r14;

  uVar5 = unaff_r14[10];

  iVar4 = (int)(short)((short)uVar5 - param_3);

  if (iVar4 < 1) {

    iVar4 = iVar4 + (unsigned int)DAT_06030b24;

  }

  if ((int)(unsigned int)(DAT_06030b24 >> 1) < iVar4) {

    iVar4 = iVar4 + (unsigned int)(DAT_06030b24 >> 1) * -2;

  }

  iVar4 = iVar4 + (iVar4 >> 2);

  iVar2 = (int)DAT_06030b26;

  *(int *)((int)unaff_r14 + iVar2) = iVar4;

  *(unsigned int *)((int)unaff_r14 + iVar2 + -4) = uVar5 - iVar4;

  *(short *)((int)unaff_r14 + iVar2 + 4) = DAT_06030b28;

  *0x0607866D = 0xf;

  *0x06089595 = 1;

  *(unsigned int *)((int)unaff_r14 + (int)DAT_06030b2a) =

       *(unsigned int *)((int)unaff_r14 + (int)DAT_06030b2a) | (int)PTR_DAT_06030b2c;

  puVar3 = (unsigned int *)(0x060A6000 + *(short *)(param_4 + 0xe) * 0x34);

  uVar6 = puVar3[4];

  uVar7 = puVar3[5];

  uVar5 = (unsigned int)0x01000000 & *puVar3;

  if (*(short *)0x06030FBE == 0) {

    (*0x06008460)();

  }

  else {

    *unaff_r14 = *unaff_r14 | 0x08000000;

  }

  *(short *)0x06030FBC = 0xf;

  if (uVar6 == 0) {

    FUN_06030dfe();

    return;

  }

  if (uVar5 != 0) {

    (*0x0602755C)(-uVar7,uVar6);

    FUN_06030dfe();

    return;

  }

  lVar1 = (long long)(int)-uVar6 * (long long)(int)(unaff_r14[6] + uVar7);

  iVar4 = (int)((unsigned long long)lVar1 >> 0x20);

  uVar5 = (unsigned int)lVar1;

  if ((iVar4 < DAT_06030da2) && (-(int)DAT_06030da2 < iVar4)) {

    lVar1 = (long long)(int)-uVar6 * (long long)(int)-uVar6;

    (*0x0602755C)

              (unaff_r14[4] + (iVar4 << 0x10 | uVar5 >> 0x10),

               ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) + 0x10000);

  }

  else {

    lVar1 = (long long)(int)-uVar6 * (long long)(int)-uVar6;

    (*0x0602755C)

              (((int)unaff_r14[4] >> 8) + (uVar5 >> 0x18 | iVar4 << 8),

               ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) + 0x10000);

  }

  FUN_06030dfe();

  return;

}
