extern int DAT_0603d500;

void FUN_0603d438()
{

  unsigned short uVar1;

  unsigned short *puVar2;

  char *puVar3;

  unsigned short uVar4;

  puVar2 = (unsigned short *)0x060A4D36;

  puVar3 = 0x0000FF00;

  (*0x06034F78)(0x060A4D36,0x060A4D58,1);

  uVar4 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar4;

  uVar1 = DAT_0603d500;

  (*0x06034F78)();

  *puVar2 = *puVar2 & uVar1;

  (*0x06034F78)();

  puVar2[1] = puVar2[1] & uVar4;

  (*0x06034F78)();

  puVar2[1] = puVar2[1] & uVar1;

  (*0x06034F78)();

  puVar2[2] = puVar2[2] & uVar4;

  (*0x06034F78)();

  puVar2[2] = puVar2[2] & uVar1;

  (*0x06034F78)();

  puVar2[3] = puVar2[3] & uVar4;

  (*0x06034F78)();

  puVar2[2] = puVar2[2] & uVar1;

  (*0x06034F78)();

  return;

}
