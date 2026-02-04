extern int DAT_06041d58;

extern int DAT_06041d5a;

int FUN_06041cc8(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  char local_14 [16];

  puVar1 = 0x060A5400;

  if (*(int *)((int)DAT_06041d58 + *(int *)0x060A5400) == 1) {

    iVar2 = (int)DAT_06041d5a;

    iVar2 = (*0x060367E8)

                      (*(int *)(*(int *)0x060A5400 + iVar2 + -8),

                       *(int *)(*(int *)0x060A5400 + iVar2 + -4),

                       *(int *)(*(int *)0x060A5400 + iVar2));

    if (iVar2 != 0) {

      return 1;

    }

    (*0x060349B6)(local_14);

    *(char *)(*(int *)puVar1 + 0x40) = local_14[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar1 + (int)DAT_06041d58) = 2;

  }

  if ((*(int *)((int)DAT_06041d58 + *(int *)puVar1) == 2) &&

     (iVar2 = (*0x06034C68)(0), iVar2 == 0)) {

    *(int *)(*(int *)puVar1 + (int)DAT_06041d58) = 0;

    return 0;

  }

  return 1;

}
