extern int DAT_0602f51a;

extern int DAT_0602f51c;

extern int DAT_0602f51e;

extern int DAT_0602f5b4;

int FUN_0602f4b4()
{

  int in_r0;

  short sVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  unsigned int uVar9;

  int in_pr;

  if (*(int *)0x0607EAE0 != 0) {

    return in_r0;

  }

  iVar2 = (int)DAT_0602f51a;

  if (0 < *(short *)(iVar2 + in_r0)) {

    *(short *)(iVar2 + in_r0) = *(short *)(iVar2 + in_r0) + -1;

  }

  iVar5 = *(int *)0x0607EA98;

  iVar6 = *(int *)0x0607E948;

  iVar7 = *(int *)(DAT_0602f51c + in_r0);

  iVar8 = *(int *)(DAT_0602f51e + in_r0);

  do {

    iVar3 = iVar7 - *(int *)(DAT_0602f51c + iVar6);

    if (iVar3 < 1) {

      iVar3 = -iVar3;

    }

    iVar4 = iVar8 - *(int *)(DAT_0602f51e + iVar6);

    if (iVar4 < 1) {

      iVar4 = -iVar4;

    }

    if (iVar3 < iVar4) {

      iVar4 = iVar4 + (iVar3 >> 1);

    }

    else {

      iVar4 = (iVar4 >> 1) + iVar3;

    }

    if (iVar4 < (int)0x001E0000) {

      sVar1 = (*(void(*)())0x0602744C)(*(int *)(DAT_0602f51c + iVar6) - iVar7,

                         *(int *)(DAT_0602f51e + iVar6) - iVar8,iVar6,iVar7,in_pr);

      uVar9 = (int)-sVar1 - *(int *)(in_r0 + 0x28);

      if (((unsigned int)0x00008000 & uVar9) == 0) {

        uVar9 = uVar9 & (unsigned int)0x0000FFFF;

      }

      else {

        uVar9 = uVar9 | 0xFFFF0000;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      if ((int)uVar9 < 0x0000071C) {

        *(short *)(iVar2 + in_r0) = 0x14;

        return in_r0;

      }

    }

    iVar6 = iVar6 + DAT_0602f5b4;

    iVar5 = iVar5 + -1;

    if (iVar5 == 0) {

      return in_r0;

    }

  } while( 1 );

}
