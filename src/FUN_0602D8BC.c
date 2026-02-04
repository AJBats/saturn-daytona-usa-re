extern int DAT_0602d916;

extern int DAT_0602d918;

extern int DAT_0602d91a;

extern int DAT_0602d9d0;

extern int DAT_0602d9d2;

void FUN_0602d8bc()
{

  long long lVar1;

  unsigned int *in_r0;

  int iVar2;

  int extraout_r1;

  unsigned int uVar3;

  int extraout_r3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  unsigned int uVar8;

  int unaff_r14;

  long long uVar9;

  if (*(short *)((int)DAT_0602d916 + (int)in_r0) != 0) {

    uVar3 = in_r0[0xc];

    (*(void(*)())0x0602ECCC)();

    iVar2 = extraout_r1;

    if ((*in_r0 & 0x00000300) == 0) {

      iVar2 = -extraout_r1;

    }

    in_r0[0xc] = uVar3 + iVar2;

    in_r0[8] = uVar3 + iVar2;

    uVar3 = *(unsigned int *)((int)DAT_0602d9d0 + (int)in_r0);

    in_r0[10] = uVar3;

    puVar7 = (char *)

             ((int)((unsigned long long)

                    ((long long)

                     *(int *)(0x0602E8B8 + *(short *)((int)DAT_0602d9d2 + (int)in_r0) * 4) *

                    (long long)(int)in_r0[3]) >> 0x20) << 0x10 |

             (unsigned int)((long long)

                    *(int *)(0x0602E8B8 + *(short *)((int)DAT_0602d9d2 + (int)in_r0) * 4) *

                   (long long)(int)in_r0[3]) >> 0x10);

    in_r0[3] = (unsigned int)puVar7;

    if ((int)in_r0[2] < 0x29) {

      puVar7 = 0x00006AAA;

    }

    uVar4 = in_r0[4];

    uVar6 = in_r0[6];

    in_r0[0xe] = uVar4;

    in_r0[0xf] = uVar6;

    iVar2 = (*(void(*)())0x06027344)();

    uVar9 = (*(void(*)())0x06027348)(-uVar3);

    lVar1 = (long long)(int)puVar7 * (long long)(int)uVar9;

    uVar3 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

    *(unsigned int *)(0x0000018C + (int)in_r0) = uVar3;

    in_r0[4] = uVar4 + uVar3;

    lVar1 = (long long)(int)((unsigned long long)uVar9 >> 0x20) * (long long)iVar2;

    uVar3 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

    *(unsigned int *)(0x00000190 + (int)in_r0) = uVar3;

    in_r0[6] = uVar6 + uVar3;

    return;

  }

  in_r0[8] = in_r0[0xc];

  iVar5 = -in_r0[10];

  uVar3 = in_r0[3];

  uVar6 = in_r0[4];

  uVar8 = in_r0[6];

  in_r0[0xe] = uVar6;

  in_r0[0xf] = uVar8;

  iVar2 = (*(void(*)())0x06027344)();

  iVar5 = (*(void(*)())0x06027348)(iVar5);

  uVar4 = (int)((unsigned long long)((long long)extraout_r3 * (long long)iVar5) >> 0x20) << 0x10 |

          (unsigned int)((long long)extraout_r3 * (long long)iVar5) >> 0x10;

  *(unsigned int *)(DAT_0602d918 + unaff_r14) = uVar4;

  *(unsigned int *)(unaff_r14 + 0x10) = uVar6 + uVar4;

  uVar3 = (int)((unsigned long long)((long long)(int)uVar3 * (long long)iVar2) >> 0x20) << 0x10 |

          (unsigned int)((long long)(int)uVar3 * (long long)iVar2) >> 0x10;

  *(unsigned int *)(DAT_0602d91a + unaff_r14) = uVar3;

  *(unsigned int *)(unaff_r14 + 0x18) = uVar8 + uVar3;

  return;

}
