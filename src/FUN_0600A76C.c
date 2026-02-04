extern int DAT_0600a854;

extern int DAT_0600a856;

void FUN_0600a76c()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  char *pcVar4;

  puVar2 = 0x00008000;

  puVar1 = 0x0608A52C;

  pcVar4 = *(char **)0x0607EB8C;

  if (pcVar4[1] != '\0') {

    (*(int(*)())0x06027080)();

    (*(int(*)())0x060270F2)(*(int *)0x06044640 + (int)DAT_0600a856,

               *(int *)(0x06044640 + 4) + -13107,

               *(int *)(0x06044640 + 8) + 0xFFFF0F5D);

    (*(int(*)())0x06027124)(puVar2,puVar2,puVar2);

    iVar3 = (*pcVar4 + 0xe) << 2;

    (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar3),*(int *)(0x060621D8 + iVar3));

    iVar3 = (*pcVar4 + 0xe) << 2;

    (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar3),*(short *)0x06089E9C,

               *(int *)(0x06062180 + iVar3));

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

  }

  if (pcVar4[4] != '\0') {

    (*(int(*)())0x06027080)();

    (*(int(*)())0x060270F2)(*(int *)0x06044670,*(int *)(0x06044670 + 4) + -13107,

               0xFFFDB334 - *(int *)(0x06044670 + 8));

    (*(int(*)())0x06027124)(puVar2,puVar2,puVar2);

    iVar3 = (pcVar4[3] + 0xe) << 2;

    (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar3),*(int *)(0x060621D8 + iVar3));

    iVar3 = (pcVar4[3] + 0xe) << 2;

    (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar3),*(short *)0x06089E9C,

               *(int *)(0x06062180 + iVar3));

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

  }

  return;

}
