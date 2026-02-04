extern int FUN_06019324();
extern int FUN_0601938c();

void FUN_060193f4()
{

  char *puVar1;

  char *puVar2;

  *(int *)0x06085FF0 = 0;

  *(int *)0x0605D245 = 0;

  *(int *)0x06085FF1 = 1;

  *(int *)0x06085FF2 = 0;

  *(int *)0x06085FF3 = 0;

  *(int *)0x06085FF5 = 0;

  (*(int(*)())0x0601D5F4)(0xf,0xAE0003FF);

  puVar2 = 0x06026CE0;

  puVar1 = 0x0605B6D8;

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x80000000;

  (*(int(*)())puVar2)();

  (*(int(*)())0x06026CE0)();

  FUN_0601938c();

  (*(int(*)())0x0601A73E)();

  (*(int(*)())0x0600511E)(0x25E76174,0x00014000,0,9);

  (*(int(*)())0x0600511E)(0x25E761FC,0x00017700,0,8);

  puVar2 = 0x06014884;

  (*(int(*)())0x06014884)(8,0);

  (*(int(*)())puVar2)(0x10,0);

  (*(int(*)())puVar2)(0x20,0);

  (*(int(*)())0x0602853E)(4);

  (*(int(*)())0x0602853E)(0xc);

  puVar2 = 0x06028560;

  *(unsigned int *)puVar1 = *(unsigned int *)puVar1 | 4;

  (*(int(*)())puVar2)();

  (*(int(*)())0x06028400)(4,*(int *)0x06063AF8,0,0x0000A000 + *(int *)(0x06063AF8 + 4),

             0x06063AF8);

  FUN_06019324();

  return;

}
