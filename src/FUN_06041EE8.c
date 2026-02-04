extern int DAT_06041f92;

extern int DAT_06041f94;

extern int DAT_06041f96;

extern int DAT_0604207a;

extern int DAT_0604207c;

extern int DAT_0604207e;

int FUN_06041ee8(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  char local_1c [16];

  puVar2 = 0x060A5400;

  puVar1 = 0x060349B6;

  if (*(int *)((int)DAT_06041f92 + *(int *)0x060A5400) == 1) {

    (*(void(*)())0x060363BC)(*(int *)(*(int *)0x060A5400 + (int)DAT_06041f96),

               *(int *)0x060A5400 + (int)DAT_06041f94);

    *param_1 = *param_1 + 1;

    (*(void(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    iVar3 = (*(void(*)())0x06036380)(*(int *)(*(int *)puVar2 + (int)DAT_06041f96),0);

    if (iVar3 != 0) {

      return 1;

    }

    (*(void(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + (int)DAT_06041f92) = 2;

  }

  if (*(int *)((int)DAT_06041f92 + *(int *)puVar2) == 2) {

    iVar3 = (int)DAT_06041f96;

    iVar3 = (*(void(*)())0x0603697C)(*(int *)(*(int *)puVar2 + iVar3 + 4),

                       *(int *)(*(int *)puVar2 + iVar3 + 8),

                       *(int *)(*(int *)puVar2 + iVar3 + 0xc),

                       *(int *)(*(int *)puVar2 + iVar3));

    if (iVar3 != 0) {

      return 1;

    }

    (*(void(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + (int)DAT_0604207a) = 3;

  }

  uVar5 = DAT_0604207c;

  if ((*(int *)((int)DAT_0604207a + *(int *)puVar2) == 3) &&

     (uVar4 = (*(void(*)())0x06035C4E)(), (uVar4 & uVar5) != 0)) {

    *(int *)(*(int *)puVar2 + (int)DAT_0604207a) = 4;

  }

  if (*(int *)((int)DAT_0604207a + *(int *)puVar2) == 4) {

    iVar3 = (*(void(*)())0x06036380)(*(int *)(*(int *)puVar2 + DAT_0604207e + -0x10),

                       *(int *)(*(int *)puVar2 + (int)DAT_0604207e));

    if (iVar3 != 0) {

      return 1;

    }

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + (int)DAT_0604207a) = 5;

  }

  if ((*(int *)((int)DAT_0604207a + *(int *)puVar2) == 5) &&

     (uVar5 = (*(void(*)())0x06035C4E)(), (uVar5 & 0x40) != 0)) {

    *(int *)(*(int *)puVar2 + (int)DAT_0604207a) = 0;

  }

  return *(int *)((int)DAT_0604207a + *(int *)puVar2);

}
