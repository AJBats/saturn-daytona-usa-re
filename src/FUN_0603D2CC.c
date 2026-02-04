void FUN_0603d2cc()
{

  unsigned short uVar1;

  unsigned short *puVar2;

  char *puVar3;

  unsigned short uVar4;

  puVar2 = (unsigned short *)0x060A4D28;

  puVar3 = 0x0000FFF0;

  (*(void(*)())0x06034F78)(0x060A4D28,0x060A4D58,1);

  uVar4 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar4;

  puVar3 = 0x0000F0FF;

  (*(void(*)())0x06034F78)();

  uVar1 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar1;

  (*(void(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar4;

  (*(void(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar1;

  (*(void(*)())0x06034F78)();

  puVar2[2] = puVar2[2] & uVar4;

  (*(void(*)())0x06034F78)();

  puVar2[2] = puVar2[2] & uVar1;

  (*(void(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar4;

  (*(void(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar1;

  (*(void(*)())0x06034F78)();

  return;

}
