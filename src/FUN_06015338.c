extern int DAT_0601541a;

void FUN_06015338()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x06038BD4;

  iVar2 = (int)DAT_0601541a;

  (*(void(*)())0x06018E70)();

  (*(void(*)())puVar1)(iVar2,0);

  *(int *)0x06085F8A = 0;

  *(int *)0x0605AD10 = 0x1e;

  (*(void(*)())0x0601ABC6)();

  if (*(int *)0x06085FF8 != '\0' || *(int *)0x06085FF9 != '\0') {

    if (*(short *)0x06085F92 == 0) {

      (*(void(*)())0x0601AC7C)();

    }

    *(int *)0x0605AD10 = 0x1a;

  }

  (*(void(*)())0x060172BC)();

  (*(void(*)())puVar1)(iVar2,0);

  (*(void(*)())puVar1)(4,1);

  (*(void(*)())puVar1)(0x10,6);

  (*(void(*)())0x060149E0)();

  *(int *)0x0605A00C = 0;

  (*(void(*)())0x06026CE0)();

  *(short *)0x0605A016 = 3;

  (*(void(*)())0x06020CF4)();

  (*(void(*)())0x060078DC)();

  (*(void(*)())0x06020CF4)();

  (*(void(*)())0x060078DC)();

  (*(void(*)())0x0602853E)(4);

  (*(void(*)())0x0602853E)(0xc);

  (*(void(*)())0x06028560)();

  (*(void(*)())0x060032D4)();

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 4;

  *(int *)0x0605A00C = 0;

  (*(void(*)())0x06026CE0)();

  (*(void(*)())puVar1)(iVar2,4);

  (*(void(*)())puVar1)(4,0);

  (**(void **)(0x0605B724 + *(int *)0x0607EAD8 * 4))();

  return;

}
