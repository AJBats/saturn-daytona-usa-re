extern int DAT_0601541a;

void FUN_06015338()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x06038BD4;

  iVar2 = (int)DAT_0601541a;

  (*0x06018E70)();

  (*puVar1)(iVar2,0);

  *0x06085F8A = 0;

  *(int *)0x0605AD10 = 0x1e;

  (*0x0601ABC6)();

  if (*0x06085FF8 != '\0' || *0x06085FF9 != '\0') {

    if (*(short *)0x06085F92 == 0) {

      (*0x0601AC7C)();

    }

    *(int *)0x0605AD10 = 0x1a;

  }

  (*0x060172BC)();

  (*puVar1)(iVar2,0);

  (*puVar1)(4,1);

  (*puVar1)(0x10,6);

  (*0x060149E0)();

  *(int *)0x0605A00C = 0;

  (*0x06026CE0)();

  *(short *)0x0605A016 = 3;

  (*0x06020CF4)();

  (*0x060078DC)();

  (*0x06020CF4)();

  (*0x060078DC)();

  (*0x0602853E)(4);

  (*0x0602853E)(0xc);

  (*0x06028560)();

  (*0x060032D4)();

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 4;

  *(int *)0x0605A00C = 0;

  (*0x06026CE0)();

  (*puVar1)(iVar2,4);

  (*puVar1)(4,0);

  (**(void **)(0x0605B724 + *(int *)0x0607EAD8 * 4))();

  return;

}
