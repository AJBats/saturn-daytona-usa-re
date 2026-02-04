extern int DAT_06018660;

extern int DAT_06018662;

extern int PTR_DAT_06018664;

extern int PTR_DAT_06018664;

void FUN_060185d8()
{

  char *puVar1;

  if (*(int *)0x06083254 == '\x03') {

    (*(void(*)())0x06026DBC)();

    (*(void(*)())0x06026E2E)(*(int *)0x06048140,*(int *)(0x06048140 + 4),

               *(int *)(0x06048140 + 8));

    (*(void(*)())0x06026EDE)((int)DAT_06018660);

    puVar1 = 0x00200000;

    (*(void(*)())0x06031D8C)(0x00200000 + (int)0x000BABE0,(int)DAT_06018662);

    (*(void(*)())0x06031A28)(puVar1 + (int)0x000BBD80,(int)*(short *)0x06089E98,

               (int)PTR_DAT_06018664);

    (*(void(*)())0x06026DF8)();

    return;

  }

  return;

}
