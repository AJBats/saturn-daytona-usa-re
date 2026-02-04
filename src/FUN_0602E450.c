extern int DAT_0602e460;

extern void FUN_0602d924();

void FUN_0602e450(param_1)
    int param_1;
{

  long long lVar1;

  int in_r0;

  int iVar2;

  int iVar3;

  int iVar4;

  int extraout_r3;

  unsigned int uVar5;

  int iVar6;

  int iVar7;

  if (*(short *)(DAT_0602e460 + in_r0) != 0) {

    FUN_0602d924();

    return;

  }

  param_1 = -param_1;

  iVar4 = *(int *)(in_r0 + 0xc);

  iVar6 = *(int *)(in_r0 + 0x10);

  iVar7 = *(int *)(in_r0 + 0x18);

  *(int *)(in_r0 + 0x38) = iVar6;

  *(int *)(in_r0 + 0x3c) = iVar7;

  iVar2 = (*0x06027344)();

  iVar3 = (*0x06027348)(param_1);

  uVar5 = (int)((unsigned long long)((long long)extraout_r3 * (long long)iVar3) >> 0x20) << 0x10 |

          (unsigned int)((long long)extraout_r3 * (long long)iVar3) >> 0x10;

  *(unsigned int *)(0x0000018C + in_r0) = uVar5;

  *(unsigned int *)(in_r0 + 0x10) = iVar6 + uVar5;

  lVar1 = (long long)iVar4 * (long long)iVar2;

  uVar5 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  *(unsigned int *)(0x00000190 + in_r0) = uVar5;

  *(unsigned int *)(in_r0 + 0x18) = iVar7 + uVar5;

  return;

}
