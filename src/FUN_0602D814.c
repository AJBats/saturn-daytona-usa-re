extern int DAT_0602d862;

extern int DAT_0602d864;

extern int DAT_0602d866;

extern int DAT_0602d88c;

void FUN_0602d814()
{

  long long lVar1;

  unsigned long long uVar2;

  int iVar3;

  int iVar4;

  char *puVar5;

  char *puVar6;

  int unaff_r14;

  iVar3 = (int)DAT_0602d862;

  iVar4 = *(int *)(unaff_r14 + 0xc) + *(int *)(iVar3 + unaff_r14);

  *(int *)(unaff_r14 + 0xc) = iVar4;

  if (iVar4 < 0) {

    *(int *)(unaff_r14 + 0xc) = 0;

    *(int *)(iVar3 + unaff_r14) = 0;

  }

  lVar1 = (long long)*(int *)(0x060477BC + *(short *)(DAT_0602d864 + unaff_r14) * 4) *

          (long long)*(int *)(unaff_r14 + 0xc);

  uVar2 = (long long)(int)0x0221AC91 *

          (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  puVar5 = (char *)((unsigned int)(uVar2 >> 0x20) & 0xffff);

  if ((uVar2 & 0xffff00000000) == 0) {

    puVar6 = (char *)0x0;

  }

  else {

    puVar6 = puVar5;

    if ((int)0x00002134 <= (int)puVar5) {

      puVar6 = 0x00002134;

    }

  }

  *(char **)(DAT_0602d866 + unaff_r14) = puVar6;

  iVar3 = (int)puVar5 - (int)puVar6;

  if (iVar3 < 0) {

    iVar3 = 0;

  }

  *(int *)(DAT_0602d88c + unaff_r14) = iVar3;

  return;

}
