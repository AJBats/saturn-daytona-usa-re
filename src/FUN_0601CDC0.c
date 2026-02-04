extern int FUN_0601d0bc();

void FUN_0601cdc0()
{

  short sVar1;

  short uVar2;

  char *puVar3;

  int iVar4;

  short local_74 [2];

  short asStack_70 [2];

  short asStack_6c [2];

  short *puStack_68;

  short *psStack_64;

  short local_60 [16];

  char auStack_40 [40];

  puVar3 = 0x06086020;

  if (*(int *)0x06086020 < 0x12) {

    sVar1 = *(short *)(0x0605DF58 + *(int *)(0x06086020 << 1));

    puStack_68 = (short *)0x25F00000;

    psStack_64 = local_60;

    for (iVar4 = 0; iVar4 < 0x20; iVar4 = iVar4 + 1) {

      uVar2 = *puStack_68;

      puStack_68 = puStack_68 + 1;

      FUN_0601d0bc(uVar2,local_74,asStack_70,asStack_6c);

      local_74[0] = (*(int(*)())0x06034FE0)(sVar1 * 0x1d);

      asStack_70[0] = (*(int(*)())0x06034FE0)();

      asStack_6c[0] = (*(int(*)())0x06034FE0)();

      *psStack_64 = asStack_6c[0] * 0x400 + asStack_70[0] * 0x20 + local_74[0];

      psStack_64 = psStack_64 + 1;

    }

    (*(int(*)())0x0602766C)(0x25F00200,local_60,0x20);

    (*(int(*)())0x0602766C)(0x25F00400,auStack_40,0x20);

  }

  *(int *)puVar3 = *(int *)puVar3 + 1;

  return;

}
