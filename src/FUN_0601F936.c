extern int DAT_0601f962;

extern int FUN_0601f87a();
extern int FUN_0601f9cc();
extern int FUN_0601fd20();

int FUN_0601f936()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  puVar2 = 0x0605B6D8;

  uVar1 = DAT_0601f962;

  *(int *)0x0605E05C = 0;

  FUN_0601f87a(0);

  uVar4 = (*(int(*)())0x0601E958)();

  puVar3 = 0x06026CE0;

  if (*(int *)0x0605E05C != '\0') {

    *(unsigned int *)puVar2 = *(unsigned int *)puVar2 | 0x80000000;

    (*(int(*)())puVar3)();

    (*(int(*)())0x06026CE0)();

    FUN_0601f9cc();

    *(unsigned int *)puVar2 = *(unsigned int *)puVar2 | 0x40000000;

    puVar3 = 0x06063D9A;

    do {

      FUN_0601fd20();

    } while ((*(unsigned short *)puVar3 & uVar1) == 0);

    uVar4 = FUN_0601fd20();

    *(unsigned int *)puVar2 = *(unsigned int *)puVar2 | 0x80000000;

  }

  return uVar4;

}
