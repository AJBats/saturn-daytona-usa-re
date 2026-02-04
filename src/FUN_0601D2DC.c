extern int DAT_0601d36a;

extern int DAT_0601d36c;

void FUN_0601d2dc()
{

  char *puVar1;

  char *puVar2;

  (*(int(*)())0x060149E0)();

  puVar1 = 0x06038BD4;

  (*(int(*)())0x06038BD4)(0x100,0);

  (*(int(*)())puVar1)(4,0);

  (*(int(*)())puVar1)(8,0);

  (*(int(*)())puVar1)(0x10,6);

  (*(int(*)())puVar1)(0x20,7);

  (*(int(*)())0x0600A026)();

  (*(int(*)())0x0600511E)(0x25E6F9C4,0x00017700,0,8);

  puVar2 = 0x0604842C;

  puVar1 = 0x0602766C;

  (*(int(*)())0x0602766C)(0x25F00600,0x0604842C,0x40);

  (*(int(*)())puVar1)(0x25F00660,0x0604888C,0x60);

  (*(int(*)())puVar1)(0x25F00000,puVar2,0x60);

  (*(int(*)())0x06028654)(0x25E759EC,0x06094FA8);

  puVar1 = 0x06095F48;

  (*(int(*)())0x06028654)(0x25E75DDC,0x06095F48);

  (*(int(*)())0x06028400)(8,puVar1,0,(int)DAT_0601d36c);

  *(int *)0x0607887F = 0;

  (*(int(*)())0x060149CC)();

  return;

}
