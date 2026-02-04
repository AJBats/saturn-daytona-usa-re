int FUN_0603458c()
{

  long long lVar1;

  int iVar2;

  int uVar3;

  int in_r7;

  int iVar4;

  char *puVar5;

  int unaff_r14;

  int in_pr;

  puVar5 = 0x00004000 + *(short *)(unaff_r14 + 0x00000002);

  iVar4 = *(int *)(unaff_r14 + 0x00000028);

  iVar2 = (*0x06027344)(puVar5);

  lVar1 = (long long)iVar4 * (long long)iVar2;

  *(unsigned int *)(unaff_r14 + 0x00000004) =

       *(int *)(unaff_r14 + 0x00000004) +

       ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  iVar2 = (*0x06027348)(puVar5);

  lVar1 = (long long)iVar4 * (long long)iVar2;

  *(unsigned int *)(unaff_r14 + 0x0000000C) =

       *(int *)(unaff_r14 + 0x0000000C) +

       ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  *(int *)0x06083238 = *(int *)(unaff_r14 + 0x00000004);

  *(int *)0x06083240 = *(int *)(unaff_r14 + 0x0000000C);

  uVar3 = (*0x06006838)();

  (*0x06027EDE)(uVar3,0x06083238,0x06083244,in_r7,in_pr);

  iVar2 = 0x00000008;

  *(int *)(unaff_r14 + 0x00000008) = *(int *)0x0608323C;

  return iVar2;

}
