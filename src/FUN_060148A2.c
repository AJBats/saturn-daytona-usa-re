extern int DAT_060148e2;

void FUN_060148a2()
{

  char *puVar1;

  char *puVar2;

  puVar2 = 0x06038BD4;

  puVar1 = 0x0605B71C;

  (*0x06038BD4)((int)DAT_060148e2,(int)(char)*0x0605B71C);

  (*puVar2)(4,(int)(char)puVar1[1]);

  (*puVar2)(8,(int)(char)puVar1[2]);

  (*puVar2)(0x10,(int)(char)puVar1[3]);

  (*puVar2)(0x20,(int)(char)puVar1[4]);

  (*puVar2)(1,(int)(char)puVar1[5]);

  return;

}
