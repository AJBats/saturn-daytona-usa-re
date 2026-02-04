extern int DAT_06003366;

extern int DAT_06003368;

extern int DAT_0600336a;

extern int DAT_0600336c;

extern int DAT_0600336e;

extern int DAT_06003370;

extern int DAT_06003372;

extern int DAT_06003374;

extern int DAT_06003376;

void FUN_0600330a()
{

  char *puVar1;

  char *puVar2;

  int *puVar3;

  puVar2 = 0x06028400;

  puVar1 = 0x06063750;

  (*0x06028400)

            (0xc,*(int *)(0x06063750 + DAT_06003366),(int)DAT_0600336a,

             *(int *)((int)(0x06063750 + DAT_06003366) + 4) + (int)DAT_06003368);

  puVar3 = (int *)(puVar1 + DAT_0600336c);

  (*puVar2)(0xc,*puVar3,(int)DAT_06003370,puVar3[1] + (int)DAT_0600336e);

  puVar3 = (int *)(puVar1 + DAT_06003372);

  (*puVar2)(0xc,*puVar3,(int)DAT_06003376,puVar3[1] + (int)DAT_06003374);

  return;

}
