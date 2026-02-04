extern int DAT_0603d5be;

void FUN_0603d514()
{

  unsigned short uVar1;

  unsigned short *puVar2;

  char *puVar3;

  unsigned short uVar4;

  puVar2 = (unsigned short *)0x060A4D3E;

  puVar3 = 0x0000FF00;

  (*(void(*)())0x06034F78)(0x060A4D3E,0x060A4D58,1);

  uVar4 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar4;

  uVar1 = DAT_0603d5be;

  (*(void(*)())0x06034F78)();

  *puVar2 = *puVar2 & uVar1;

  (*(void(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar4;

  (*(void(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar1;

  (*(void(*)())0x06034F78)();

  puVar2[2] = 0;

  (*(void(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar4;

  (*(void(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar1;

  (*(void(*)())0x06034F78)();

  return;

}
