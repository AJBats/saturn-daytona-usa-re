extern void FUN_0601d0bc();

void FUN_0601cefc()
{

  short uVar1;

  char *puVar2;

  int iVar3;

  short local_74 [2];

  short asStack_70 [2];

  short asStack_6c [2];

  short *puStack_68;

  int iStack_64;

  short *psStack_60;

  short local_5c [16];

  char auStack_3c [40];

  puVar2 = 0x06086020;

  if (*(int *)0x06086020 < 0x12) {

    iStack_64 = 100 - *(short *)(0x0605DF58 + *(int *)0x06086020 * 2);

    puStack_68 = (short *)0x25F00000;

    psStack_60 = local_5c;

    for (iVar3 = 0; iVar3 < 0x20; iVar3 = iVar3 + 1) {

      uVar1 = *puStack_68;

      puStack_68 = puStack_68 + 1;

      FUN_0601d0bc(uVar1,local_74,asStack_70,asStack_6c);

      local_74[0] = (*0x06034FE0)(iStack_64 * 0x1d);

      asStack_70[0] = (*0x06034FE0)();

      asStack_6c[0] = (*0x06034FE0)();

      *psStack_60 = asStack_6c[0] * 0x400 + asStack_70[0] * 0x20 + local_74[0];

      psStack_60 = psStack_60 + 1;

    }

    (*0x0602766C)(0x25F00200,local_5c,0x20);

    (*0x0602766C)(0x25F00400,auStack_3c,0x20);

  }

  *(int *)puVar2 = *(int *)puVar2 + 1;

  return;

}
