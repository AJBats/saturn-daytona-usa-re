extern int FUN_06020946();

unsigned int FUN_06020c3c()
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  char auStack_24 [16];

  char auStack_14 [20];

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06035228)();

  puVar2 = 0x060A3D88;

  puVar1 = 0x060635AC;

  uVar3 = (unsigned int)*(unsigned short *)0x0608780C;

  if (uVar3 == 1) {

    *(short *)(0x060A3DB0 + 10) = (short)0x0000C060;

    *(short *)(puVar2 + 0x20) = 0xf;

    *(short *)puVar1 = 1;

    uVar3 = (*(int(*)())0x06038044)(auStack_14);

  }

  else if (uVar3 == 2) {

    *(short *)(0x060A3DB0 + 10) = (short)0x0000C044;

    *(short *)(puVar2 + 0x20) = 0xf;

    *(short *)puVar1 = 1;

    uVar3 = (*(int(*)())0x06038044)(auStack_24);

  }

  else if (uVar3 == 3) {

    uVar3 = FUN_06020946();

  }

  else if (uVar3 == 4) {

    uVar3 = (*(int(*)())0x0602853E)(4);

  }

  *(short *)0x0608780C = 0;

  return uVar3;

}
