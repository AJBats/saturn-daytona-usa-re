extern int DAT_0601e162;

extern int DAT_0601e164;

extern int DAT_0601e166;

extern int DAT_0601e238;

extern int DAT_0601e23a;

extern int DAT_0601e23c;

extern int DAT_0601e23e;

extern int DAT_0601e240;

extern int DAT_0601e242;

extern int DAT_0601e244;

extern int DAT_0601e246;

extern int DAT_0601e248;

extern int DAT_0601e24a;

extern int DAT_0601e24c;

extern int DAT_0601e24e;

extern int PTR_DAT_0601e168;

extern int PTR_DAT_0601e168;

extern int FUN_0601e26c();

void FUN_0601e100()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  puVar4 = 0x00008000;

  puVar2 = 0x06028400;

  puVar3 = 0x06063750;

  if (*(int *)0x0607EAE0 == 0) {

    (*(void(*)())0x0602761E)(0x25F00100,0x0604892C,0x20);

    (*(void(*)())puVar2)(8,*(int *)(puVar3 + 0x10),(int)DAT_0601e162,

                      puVar4 + *(int *)(puVar3 + 0x14));

    puVar4 = puVar4 + *(int *)((int)(puVar3 + DAT_0601e164) + 4);

    puVar3 = *(char **)(puVar3 + DAT_0601e164);

    sVar1 = DAT_0601e166;

  }

  else {

    (*(void(*)())0x0602761E)(0x25F00100,0x0605DFCC,0x20);

    sVar1 = DAT_0601e238;

    if (*(int *)0x06078644 == 1) {

      sVar1 = PTR_DAT_0601e168;

    }

    (*(void(*)())puVar2)(8,*(int *)(puVar3 + sVar1),(int)DAT_0601e23a,

                      puVar4 + *(int *)((int)(puVar3 + sVar1) + 4));

    puVar4 = 0x00009000;

    (*(void(*)())puVar2)(8,*(int *)(puVar3 + DAT_0601e23c),(int)DAT_0601e23e,

                      0x00009000 + *(int *)((int)(puVar3 + DAT_0601e23c) + 4));

    (*(void(*)())puVar2)(8,*(int *)(puVar3 + DAT_0601e240),(int)DAT_0601e242,

                      puVar4 + *(int *)((int)(puVar3 + DAT_0601e240) + 4));

    (*(void(*)())puVar2)(8,*(int *)(puVar3 + DAT_0601e244),(int)DAT_0601e246,

                      puVar4 + *(int *)((int)(puVar3 + DAT_0601e244) + 4));

    (*(void(*)())0x0601AB8C)();

    FUN_0601e26c(*(int *)0x06086008);

    sVar1 = DAT_0601e248;

    (*(void(*)())puVar2)(8,0x0605DFF4,(int)DAT_0601e24a,

                      puVar4 + *(int *)(puVar3 + DAT_0601e248 + 4));

    FUN_0601e26c(*(int *)0x06086004);

    (*(void(*)())puVar2)(8,0x0605DFF4,(int)DAT_0601e24c,puVar4 + *(int *)(puVar3 + sVar1 + 4));

    FUN_0601e26c(0);

    puVar4 = puVar4 + *(int *)(puVar3 + sVar1 + 4);

    puVar3 = 0x0605DFF4;

    sVar1 = DAT_0601e24e;

  }

  (*(void(*)())puVar2)(8,puVar3,(int)sVar1,puVar4);

  *(int *)0x06087068 = 0;

  *(int *)0x0605DFF0 = 0;

  return;

}
