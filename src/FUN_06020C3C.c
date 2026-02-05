extern int FUN_06020946();

unsigned int FUN_06020c3c()
{
  register int func asm("r3") = 0x06035228;
  char auStack_24[16];
  char auStack_14[20];
  unsigned int uVar3;

  (*(int(*)())func)();
  (*(int(*)())func)();

  uVar3 = *(unsigned short *)0x0608780C;

  if (uVar3 == 1) {
    *(short *)0x060A3DBA = (short)0xC060;
    *(short *)0x060A3DA8 = 0xf;
    *(short *)0x060635AC = 1;
    uVar3 = (*(int(*)())0x06038044)(auStack_14);
  } else if (uVar3 == 2) {
    *(short *)0x060A3DBA = (short)0xC044;
    *(short *)0x060A3DA8 = 0xf;
    *(short *)0x060635AC = 1;
    uVar3 = (*(int(*)())0x06038044)(auStack_24);
  } else if (uVar3 == 3) {
    uVar3 = FUN_06020946();
  } else if (uVar3 == 4) {
    uVar3 = (*(int(*)())0x0602853E)(4);
  }

  *(short *)0x0608780C = 0;
  return uVar3;
}
