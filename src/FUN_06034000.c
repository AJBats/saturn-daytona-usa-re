int FUN_06034000()
{

  long long lVar1;

  int iVar2;

  int uVar3;

  int uVar4;

  int iVar5;

  unsigned int uVar6;

  int in_r7;

  int iVar7;

  int unaff_r14;

  int in_pr;

  if (*(char *)(unaff_r14 + 0x00000001) == '\x03') {

    iVar2 = 0x0000001C;

    *(int *)(unaff_r14 + 0x0000001C) =

         *(int *)(unaff_r14 + 0x0000001C) + (int)*(short *)(unaff_r14 + 0x00000012);

    return iVar2;

  }

  iVar5 = (int)*(short *)(unaff_r14 + 0x00000002) + (int)*(short *)(unaff_r14 + 0x00000012);

  *(short *)(unaff_r14 + 0x00000002) = (short)iVar5;

  iVar2 = (*0x06027344)(iVar5);

  iVar7 = *(int *)(unaff_r14 + 0x00000020);

  *(unsigned int *)(unaff_r14 + 0x00000004) =

       ((int)((unsigned long long)((long long)iVar7 * (long long)iVar2) >> 0x20) << 0x10 |

       (unsigned int)((long long)iVar7 * (long long)iVar2) >> 0x10) + *(int *)(unaff_r14 + 0x00000014);

  iVar5 = (*0x06027348)(iVar5);

  *(unsigned int *)(unaff_r14 + 0x0000000C) =

       ((int)((unsigned long long)((long long)iVar7 * (long long)iVar5) >> 0x20) << 0x10 |

       (unsigned int)((long long)iVar7 * (long long)iVar5) >> 0x10) + *(int *)(unaff_r14 + 0x0000001C);

  if (*(char *)(unaff_r14 + 0x00000001) == '\x02') {

    *(int *)0x06083238 = *(int *)(unaff_r14 + 0x00000004);

    *(int *)0x06083240 = *(int *)(unaff_r14 + 0x0000000C);

    uVar3 = (*0x06006838)();

    (*0x06027EDE)(uVar3,0x06083238,0x06083244,in_r7,in_pr);

    iVar2 = 0x00000008;

    *(int *)(unaff_r14 + 0x00000008) = *(int *)0x0608323C;

  }

  else {

    if (*(short *)(unaff_r14 + 0x00000024) == 0) {

      uVar6 = 0;

    }

    else {

      lVar1 = (long long)(int)*(short *)(unaff_r14 + 0x00000024) * (long long)iVar2;

      uVar6 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

      uVar3 = (*0x06027348)(uVar6);

      uVar4 = (*0x06027344)(uVar6);

      iVar2 = (*0x0602755C)(uVar3,uVar4);

      uVar6 = (int)((unsigned long long)((long long)iVar7 * (long long)iVar2) >> 0x20) << 0x10 |

              (unsigned int)((long long)iVar7 * (long long)iVar2) >> 0x10;

    }

    iVar2 = 0x00000008;

    *(unsigned int *)(unaff_r14 + 0x00000008) = uVar6 + *(int *)(unaff_r14 + 0x00000018);

  }

  return iVar2;

}
