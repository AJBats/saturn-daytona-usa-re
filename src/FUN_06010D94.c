void FUN_06010d94(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  short *psVar8;

  puVar2 = 0x06026E0C;

  puVar1 = 0x06089EDC;

  if (*(unsigned int *)0x060788A0 < 10) {

    *(int *)0x06089EDC = *(int *)0x06089EDC + 0x30;

    (*(void(*)())puVar2)();

    puVar2 = 0x06026E2E;

    (*(void(*)())0x06026E2E)(param_2,param_3,param_4);

    (*(void(*)())0x06026EDE)((int)*(short *)0x06078878);

    puVar3 = 0x0606212C;

    (*(void(*)())0x06031D8C)(*(int *)0x0606212C,*(int *)0x060621D8);

    puVar6 = 0x06062180;

    puVar5 = 0x06031A28;

    puVar4 = 0x060620D8;

    psVar8 = (short *)(0x06089E44 + param_1 * 2);

    (*(void(*)())0x06031A28)(*(int *)0x060620D8,(int)*psVar8,*(int *)0x06062180);

    (*(void(*)())0x06026DBC)();

    (*(void(*)())puVar2)(*(int *)0x06044640,*(int *)0x06044644,

                      -*(int *)0x06044648);

    (*(void(*)())0x06031D8C)(*(int *)(puVar3 + 4),*(int *)0x060621DC);

    (*(void(*)())puVar5)(*(int *)(puVar4 + 4),(int)*psVar8,*(int *)(puVar6 + 4));

    puVar7 = 0x06026DBC;

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

    (*(void(*)())puVar7)();

    (*(void(*)())puVar2)(*(int *)0x0604464C,*(int *)0x06044650,

                      -*(int *)0x06044654);

    (*(void(*)())0x06031D8C)(*(int *)(puVar3 + 8),*(int *)0x060621E0);

    (*(void(*)())puVar5)(*(int *)(puVar4 + 8),(int)*psVar8,*(int *)(puVar6 + 8));

    puVar7 = 0x06026DBC;

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

    (*(void(*)())puVar7)();

    (*(void(*)())puVar2)(*(int *)0x06044670,*(int *)0x06044674,

                      -*(int *)0x06044678);

    (*(void(*)())0x06031D8C)(*(int *)(puVar3 + 0xc),*(int *)0x060621E4);

    (*(void(*)())puVar5)(*(int *)(puVar4 + 0xc),(int)*psVar8,*(int *)(puVar6 + 0xc));

    *(int *)puVar1 = *(int *)puVar1 + -0x60;

  }

  return;

}
