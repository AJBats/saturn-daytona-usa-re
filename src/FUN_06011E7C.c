extern int DAT_06011efe;

extern int DAT_06011f00;

extern int DAT_06011f02;

void FUN_06011e7c()
{

  (*(void(*)())0x06028400)(0xc,*(int *)0x060638B0,(int)DAT_06011f00,

             *(int *)(0x060638B0 + 4) + (int)DAT_06011efe);

  (*(void(*)())0x06028400)(0xc,*(int *)0x060638A0,(int)DAT_06011f02,

             *(int *)(0x060638A0 + 4) + (int)DAT_06011efe);

  return;

}
