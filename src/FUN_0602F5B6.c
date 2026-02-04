extern int DAT_0602f5e8;

extern int DAT_0602f5ea;

extern int DAT_0602f6e0;

extern int DAT_0602f6e2;

extern int DAT_0602f6e4;

extern int DAT_0602f6e6;

extern int DAT_0602f6e8;

extern int DAT_0602f6ea;

extern int DAT_0602f6ec;

extern int DAT_0602f6ee;

extern int DAT_0602f6f0;

extern int DAT_0602f6f2;

extern int DAT_0602f6f4;

extern int DAT_0602f6f6;

extern void FUN_0602f71c();

void FUN_0602f5b6()
{

  long long lVar1;

  long long lVar2;

  int in_r0;

  int iVar3;

  unsigned int uVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  puVar5 = *(char **)(DAT_0602f5ea + in_r0);

  puVar6 = 0x00000000;

  if (((int)0x00000000 < (int)puVar5) && (puVar6 = puVar5, (int)0x00002134 <= (int)puVar5))

  {

    puVar6 = 0x00002134;

  }

  lVar1 = (long long)*(int *)(*(int *)(DAT_0602f6e2 + in_r0) + ((unsigned int)puVar6 >> 7) * 4) *

          (long long)*(int *)(0x060477BC + *(short *)(DAT_0602f6e0 + in_r0) * 4);

  lVar1 = (long long)

          (int)(((int)((unsigned long long)

                       ((long long)*(int *)(0x06045AEC + *(int *)(DAT_0602f5e8 + in_r0) * 4) *

                       (long long)(int)0x00016666) >> 0x20) << 0x10 |

                (unsigned int)((long long)*(int *)(0x06045AEC + *(int *)(DAT_0602f5e8 + in_r0) * 4) *

                      (long long)(int)0x00016666) >> 0x10) - (int)0x00006666) *

          (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  iVar3 = (*0x0602755C)(*(int *)(DAT_0602f6e4 + in_r0) << 0x10,0x00019999);

  *(unsigned int *)(DAT_0602f6e6 + in_r0) =

       ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) - iVar3;

  lVar1 = (long long)*(int *)(0x06045AEC + *(int *)(DAT_0602f6e8 + in_r0) * 4) *

          (long long)*(int *)(0x06045AEC + *(int *)(DAT_0602f6e8 + in_r0) * 4);

  uVar4 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  lVar1 = (long long)0x0B400000 * (long long)(int)uVar4;

  lVar2 = (long long)(int)0x07800000 * (long long)(int)uVar4;

  *(unsigned int *)(DAT_0602f6ea + in_r0) = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  *(unsigned int *)(DAT_0602f6ec + in_r0) = (int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10;

  iVar3 = *(int *)(DAT_0602f6ee + in_r0);

  if (0 < iVar3) {

    iVar3 = iVar3 >> 1;

  }

  puVar6 = 0x06400000;

  iVar3 = (*0x06027348)(iVar3);

  iVar7 = (int)((unsigned long long)((long long)(int)puVar6 * (long long)iVar3) >> 0x20);

  *(int *)(DAT_0602f6f0 + in_r0) =

       (int)(iVar7 << 0x10 | (unsigned int)((long long)(int)puVar6 * (long long)iVar3) >> 0x10) >> 1;

  uVar4 = *(unsigned int *)(0x060454CC + *(int *)(in_r0 + 8) * 4);

  if (0 < *(short *)(DAT_0602f6f2 + in_r0)) {

    iVar7 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)(int)DAT_0602f6f4) >> 0x20);

    uVar4 = iVar7 << 0x10 | (unsigned int)((long long)(int)uVar4 * (long long)(int)DAT_0602f6f4) >> 0x10;

  }

  iVar3 = FUN_0602f71c();

  *(int *)(DAT_0602f6f6 + iVar3) = (int)(uVar4 + iVar7) >> 1;

  return;

}
