extern int DAT_0604211e;

extern int DAT_06042120;

extern int DAT_06042122;

int FUN_06042088(param_1)
    int *param_1;
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  char local_14 [16];

  puVar2 = 0x060A5400;

  if (*(int *)((int)DAT_0604211e + *(int *)0x060A5400) == 1) {

    iVar3 = (*(void(*)())0x06036A1C)(*(int *)(*(int *)0x060A5400 + DAT_06042120 + 4),

                       *(int *)(*(int *)0x060A5400 + (int)DAT_06042120));

    if (iVar3 != 0) {

      return 1;

    }

    (*(void(*)())0x060349B6)(local_14);

    *(char *)(*(int *)puVar2 + 0x40) = local_14[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + (int)DAT_0604211e) = 2;

  }

  uVar1 = DAT_06042122;

  if ((*(int *)((int)DAT_0604211e + *(int *)puVar2) == 2) &&

     (uVar4 = (*(void(*)())0x06035C4E)(), (uVar4 & uVar1) != 0)) {

    *(int *)(*(int *)puVar2 + (int)DAT_0604211e) = 0;

  }

  return *(int *)((int)DAT_0604211e + *(int *)puVar2);

}
