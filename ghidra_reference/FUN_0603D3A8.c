extern int DAT_0603d426;

int FUN_0603d3a8()
{

  int uVar1;

  unsigned short *puVar2;

  unsigned short uVar3;

  char *puVar4;

  unsigned short uVar5;

  uVar3 = 1;

  puVar2 = (unsigned short *)0x060A4D30;

  puVar4 = 0x0000FF00;

  (*(int(*)())0x06034F78)(0x060A4D30,1,0x060A4D58);

  uVar5 = (unsigned short)puVar4;

  *puVar2 = *puVar2 & uVar5 | 3;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & 0xff | DAT_0603d426;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar5 | uVar3;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & 0xff;

  (*(int(*)())0x06034F78)();

  puVar2[2] = 4;

  uVar1 = (*(int(*)())0x06034F78)();

  return uVar1;

}
