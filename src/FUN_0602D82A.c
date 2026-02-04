extern int DAT_0602d864;

extern int DAT_0602d866;

extern int DAT_0602d88c;

void FUN_0602d82a()
{

  long long lVar1;

  unsigned long long uVar2;

  int in_r0;

  char *puVar3;

  char *puVar4;

  int iVar5;

  lVar1 = (long long)*(int *)(0x060477BC + *(short *)(DAT_0602d864 + in_r0) << 2) *

          (long long)*(int *)(in_r0 + 0xc);

  uVar2 = (long long)(int)0x0221AC91 *

          (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  puVar3 = (char *)((unsigned int)(uVar2 >> 0x20) & 0xffff);

  if ((uVar2 & 0xffff00000000) == 0) {

    puVar4 = (char *)0x0;

  }

  else {

    puVar4 = puVar3;

    if ((int)0x00002134 <= (int)puVar3) {

      puVar4 = 0x00002134;

    }

  }

  *(char **)(DAT_0602d866 + in_r0) = puVar4;

  iVar5 = (int)puVar3 - (int)puVar4;

  if (iVar5 < 0) {

    iVar5 = 0;

  }

  *(int *)(DAT_0602d88c + in_r0) = iVar5;

  return;

}
