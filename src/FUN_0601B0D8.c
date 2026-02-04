void FUN_0601b0d8()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned short uVar5;

  unsigned int uVar6;

  puVar3 = 0x060284AE;

  puVar2 = 0x0604A4B8;

  puVar1 = 0x0604A490;

  uVar5 = 0;

  uVar6 = 0;

  do {

    iVar4 = ((uVar6 & 0xffff) + 6) * 0x40;

    (*puVar3)(8,(iVar4 + 2) * 2,0x60,puVar1);

    (*puVar3)(8,(((uVar6 & 0xffff) + 7) * 0x40 + 0x21) * 2,0x60,puVar2);

    (*puVar3)(0xc,(iVar4 + 0x25) * 2,0x60,puVar2);

    uVar5 = uVar5 + 1;

    uVar6 = uVar6 + 3;

  } while (uVar5 < 5);

  return;

}
