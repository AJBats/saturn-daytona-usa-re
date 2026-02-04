extern int DAT_060148e2;

void FUN_060148a2()
{

  char *puVar1;

  char *puVar2;

  puVar2 = 0x06038BD4;

  puVar1 = 0x0605B71C;

  (*(int(*)())0x06038BD4)(0x100,(int)(char)*(int *)0x0605B71C);

  (*(int(*)())puVar2)(4,(int)(char)puVar1[1]);

  (*(int(*)())puVar2)(8,(int)(char)puVar1[2]);

  (*(int(*)())puVar2)(0x10,(int)(char)puVar1[3]);

  (*(int(*)())puVar2)(0x20,(int)(char)puVar1[4]);

  (*(int(*)())puVar2)(1,(int)(char)puVar1[5]);

  return;

}
