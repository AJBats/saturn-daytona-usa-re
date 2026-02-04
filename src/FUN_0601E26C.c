void FUN_0601e26c()
{

  char *puVar1;

  char *puVar2;

  int uVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  unsigned char bVar6;

  puVar2 = 0x06087064;

  puVar1 = 0x0605DFF4;

  uVar3 = (*0x06005DD4)();

  *(int *)puVar2 = uVar3;

  bVar6 = 0;

  do {

    uVar5 = (unsigned int)bVar6;

    uVar4 = (unsigned int)bVar6;

    bVar6 = bVar6 + 1;

    *(unsigned short *)(puVar1 + uVar5 * 2 + 4) = (unsigned short)*(unsigned char *)(*(int *)puVar2 + uVar4);

  } while (bVar6 < 8);

  return;

}
