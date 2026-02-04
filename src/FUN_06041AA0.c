extern int DAT_06041b0a;

extern int DAT_06041bc6;

extern int PTR_DAT_06041b0c;

extern int PTR_DAT_06041b0c;

int FUN_06041aa0(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  unsigned short uVar3;

  char local_14 [16];

  puVar1 = 0x060A5400;

  if (*(int *)((int)DAT_06041b0a + *(int *)0x060A5400) == 1) {

    iVar2 = (*0x06036144)

                      (*(int *)(*(int *)0x060A5400 + (int)PTR_DAT_06041b0c));

    *param_1 = *param_1 + 1;

    if (iVar2 == 0) {

      *(int *)(*(int *)puVar1 + (int)DAT_06041b0a) = 2;

    }

    (*0x060349B6)(local_14);

    *(char *)(*(int *)puVar1 + 0x40) = local_14[0];

  }

  if ((*(int *)((int)DAT_06041b0a + *(int *)puVar1) == 2) &&

     (uVar3 = (*0x06035C4E)(), (uVar3 & 0x40) != 0)) {

    *(int *)(*(int *)puVar1 + (int)DAT_06041bc6) = 0;

  }

  return *(int *)((int)DAT_06041bc6 + *(int *)puVar1);

}
