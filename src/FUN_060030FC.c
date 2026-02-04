extern int DAT_060031e2;

extern int DAT_060031e4;

extern void FUN_06003218();
extern void FUN_06003274();

void FUN_060030fc()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int *puVar4;

  puVar3 = 0x20100063;

  puVar2 = 0x06059C50;

  puVar1 = 0x06059C58;

  (**(void **)0x06000320)(1);

  do {

  } while ((*puVar3 & 1) == 1);

  *puVar3 = 1;

  *0x2010001F = 0x19;

  do {

  } while ((*puVar3 & 1) != 0);

  for (puVar4 = *(int **)0x06059C4C; puVar4 < *(int **)puVar2;

      puVar4 = puVar4 + 1) {

    *puVar4 = 0;

  }

  for (puVar4 = *(int **)0x06059C54; puVar4 < *(int **)puVar1;

      puVar4 = puVar4 + 1) {

    *puVar4 = 0;

  }

  (*0x0603BF7C)(0);

  (*0x06034E58)();

  (**(void **)0x06000344)(0xffffffff,(int)DAT_060031e2);

  (*0x06012CF4)();

  FUN_06003274();

  (*0x06004A98)();

  (*0x06012E6A)();

  FUN_06003218();

  (*0x06018EE4)();

  (**(void **)0x06000344)((int)DAT_060031e4,0);

  (*0x06005174)();

  (*0x0601F936)();

  (*0x0601492C)();

  (*0x060149E0)();

  *(int *)0x0605AD10 = 2;

  return;

}
