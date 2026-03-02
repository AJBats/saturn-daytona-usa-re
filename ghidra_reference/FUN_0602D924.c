extern int DAT_0602d9d0;

extern int DAT_0602d9d2;

void FUN_0602d924()
{

  long long lVar1;

  unsigned int *in_r0;

  int iVar2;

  int extraout_r1;

  unsigned int uVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  long long uVar7;

  uVar3 = in_r0[0xc];

  (*(int(*)())0x0602ECCC)();

  iVar2 = extraout_r1;

  if ((*in_r0 & 0x00000300) == 0) {

    iVar2 = -extraout_r1;

  }

  in_r0[0xc] = uVar3 + iVar2;

  in_r0[8] = uVar3 + iVar2;

  uVar3 = *(unsigned int *)(0x248 + (int)in_r0);

  in_r0[10] = uVar3;

  puVar4 = (char *)

           ((int)((unsigned long long)

                  ((long long)

                   *(int *)(0x0602E8B8 + *(short *)(0x250 + (int)in_r0) << 2) *

                  (long long)(int)in_r0[3]) >> 0x20) << 0x10 |

           (unsigned int)((long long)

                  *(int *)(0x0602E8B8 + *(short *)(0x250 + (int)in_r0) << 2) *

                 (long long)(int)in_r0[3]) >> 0x10);

  in_r0[3] = (unsigned int)puVar4;

  if ((int)in_r0[2] < 0x29) {

    puVar4 = 0x00006AAA;

  }

  uVar5 = in_r0[4];

  uVar6 = in_r0[6];

  in_r0[0xe] = uVar5;

  in_r0[0xf] = uVar6;

  iVar2 = (*(int(*)())0x06027344)();

  uVar7 = (*(int(*)())0x06027348)(-uVar3);

  lVar1 = (long long)(int)puVar4 * (long long)(int)uVar7;

  uVar3 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  *(unsigned int *)(0x0000018C + (int)in_r0) = uVar3;

  in_r0[4] = uVar5 + uVar3;

  lVar1 = (long long)(int)((unsigned long long)uVar7 >> 0x20) * (long long)iVar2;

  uVar3 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  *(unsigned int *)(0x00000190 + (int)in_r0) = uVar3;

  in_r0[6] = uVar6 + uVar3;

  return;

}
