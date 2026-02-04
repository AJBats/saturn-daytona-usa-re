void FUN_0600aa98(param_1, param_2)
    int param_1;
    int param_2;
{

  unsigned char bVar1;

  unsigned char bVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  short *psVar8;

  unsigned char *pbVar9;

  int iVar10;

  pbVar9 = 0x0605A1D5 + param_2 * 4;

  bVar2 = pbVar9[3];

  iVar6 = *(int *)(param_1 + 0x48);

  iVar7 = *(int *)(param_1 + 0x40) << 1;

  bVar1 = *pbVar9;

  (*0x06026DBC)();

  (*0x06026E2E)

            (*(int *)0x06044640,*(int *)(0x06044640 + 4),

             -*(int *)(0x06044640 + 8));

  (*0x06026EDE)(iVar7);

  (*0x06026E94)(-iVar6);

  puVar3 = 0x0606212C;

  iVar10 = (unsigned int)bVar1 * 4;

  (*0x06031D8C)

            (*(int *)(0x0606212C + iVar10),*(int *)(0x060621D8 + iVar10));

  puVar4 = 0x060620D8;

  psVar8 = (short *)(0x06089E44 + (unsigned int)bVar2 * 2);

  (*0x06031A28)

            (*(int *)(0x060620D8 + iVar10),(int)*psVar8,

             *(int *)(0x06062180 + iVar10));

  puVar5 = 0x06089EDC;

  *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;

  bVar1 = pbVar9[1];

  (*0x06026DBC)();

  (*0x06026E2E)

            (*(int *)0x0604464C,*(int *)(0x0604464C + 4),

             -*(int *)(0x0604464C + 8));

  (*0x06026EDE)(iVar7);

  (*0x06026E94)(-iVar6);

  iVar6 = (unsigned int)bVar1 * 4;

  (*0x06031D8C)

            (*(int *)(puVar3 + iVar6),*(int *)(0x060621D8 + iVar6));

  (*0x06031A28)

            (*(int *)(puVar4 + iVar6),(int)*psVar8,*(int *)(0x06062180 + iVar6))

  ;

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  iVar6 = *(int *)(param_1 + 0x50);

  bVar1 = pbVar9[2];

  (*0x06026DBC)();

  (*0x06026E2E)

            (*(int *)0x06044670,*(int *)(0x06044670 + 4),

             -*(int *)(0x06044670 + 8));

  (*0x06026E94)(-iVar6);

  iVar6 = (unsigned int)bVar1 * 4;

  (*0x06031D8C)

            (*(int *)(puVar3 + iVar6),*(int *)(0x060621D8 + iVar6));

  (*0x06031A28)

            (*(int *)(puVar4 + iVar6),(int)*psVar8,*(int *)(0x06062180 + iVar6))

  ;

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  return;

}
