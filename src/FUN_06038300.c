void FUN_06038300()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  (*0x06038F34)();

  puVar1 = 0x060A4C60;

  *(int *)0x060A4C60 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar1 = 0x060A4C68;

  *(int *)0x060A4C68 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar1 = 0x060A4C78;

  *(int *)0x060A4C78 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar1 = 0x060A4C40;

  *(short *)0x060A4C40 = 0;

  *(short *)(puVar1 + 2) = 0;

  puVar1 = 0x060A4C54;

  *(short *)0x060A4C54 = 0;

  *(short *)(puVar1 + 2) = 0;

  puVar1 = 0x060A4C44;

  *(int *)0x060A4C44 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar1 = 0x060A4C4C;

  *(int *)0x060A4C4C = 0;

  puVar2 = 0x0603C104;

  *(int *)(puVar1 + 4) = 0;

  (*puVar2)();

  puVar3 = 0x060A3DB0;

  puVar2 = 0x060A3D88;

  puVar1 = 0x0000FFFF;

  *(char **)0x060A3D84 = 0x25F80000;

  puVar4 = 0x00008000;

  *(short *)puVar2 = (short)0x00008000;

  *(short *)(puVar2 + 2) = 0;

  *(short *)(puVar2 + 6) = 0;

  *(short *)(puVar2 + 0xc) = 0;

  *(short *)(puVar2 + 0xe) = (short)((unsigned int)puVar4 >> 2);

  uVar7 = 0;

  do {

    uVar5 = (unsigned int)uVar7;

    uVar7 = uVar7 + 1;

    *(short *)(puVar2 + uVar5 * 2 + 0x10) = (short)puVar1;

  } while (uVar7 < 8);

  *(short *)(puVar2 + 0x20) = 0;

  *(short *)(puVar2 + 0x22) = 0;

  *(short *)(puVar2 + 0x24) = 0;

  *(short *)(puVar2 + 0x26) = 0;

  *(short *)puVar3 = 0;

  *(short *)(puVar3 + 2) = 0;

  *(short *)(puVar3 + 4) = 0;

  *(short *)(puVar3 + 6) = 0;

  *(short *)(puVar3 + 8) = 0;

  *(short *)(puVar3 + 10) = 0;

  *(short *)(puVar3 + 0xc) = 0;

  *(short *)(puVar3 + 0xe) = 0;

  *(short *)(puVar3 + 0x10) = 0;

  *(short *)(puVar3 + 0x12) = 0;

  uVar6 = 0;

  *(short *)(puVar3 + 0x14) = 0;

  *(short *)(puVar3 + 0x16) = 0;

  uVar7 = uVar6;

  do {

    uVar5 = (unsigned int)uVar7;

    uVar7 = uVar7 + 1;

    *(short *)(puVar3 + uVar5 * 2 + 0x18) = 0;

  } while (uVar7 < 8);

  do {

    uVar5 = (unsigned int)uVar6;

    uVar6 = uVar6 + 1;

    *(short *)(puVar3 + uVar5 * 2 + 0x28) = 0;

    puVar1 = 0x060A3DF8;

  } while (uVar6 < 0x10);

  *(int *)0x060A3DF8 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar2 = 0x00010000;

  *(char **)(puVar1 + 8) = 0x00010000;

  *(char **)(puVar1 + 0xc) = puVar2;

  *(int *)(puVar1 + 0x10) = 0;

  *(int *)(puVar1 + 0x14) = 0;

  *(char **)(puVar1 + 0x18) = puVar2;

  *(char **)(puVar1 + 0x1c) = puVar2;

  *(short *)(puVar1 + 0x20) = 0;

  *(short *)(puVar1 + 0x22) = 0;

  *(short *)(puVar1 + 0x24) = 0;

  *(short *)(puVar1 + 0x26) = 0;

  *(short *)(puVar1 + 0x28) = 0;

  *(short *)(puVar1 + 0x2a) = 0;

  *(int *)(puVar1 + 0x2c) = 0;

  *(int *)(puVar1 + 0x30) = 0;

  *(int *)(puVar1 + 0x34) = 0;

  *(int *)(puVar1 + 0x38) = 0;

  *(int *)(puVar1 + 0x3c) = 0;

  puVar1 = 0x060A3E38;

  *(short *)0x060A3E38 = 0;

  *(short *)(puVar1 + 2) = 0;

  *(short *)(puVar1 + 4) = 0;

  *(short *)(puVar1 + 6) = 0;

  *(short *)(puVar1 + 8) = 0;

  *(short *)(puVar1 + 10) = 0;

  *(int *)(puVar1 + 0xc) = 0;

  puVar1 = 0x060A3E48;

  *(short *)0x060A3E48 = 0;

  *(short *)(puVar1 + 2) = 0;

  *(short *)(puVar1 + 4) = 0;

  *(short *)(puVar1 + 6) = 0;

  *(short *)(puVar1 + 8) = 0;

  *(short *)(puVar1 + 10) = 0;

  *(short *)(puVar1 + 0xc) = 0;

  *(short *)(puVar1 + 0xe) = 0;

  *(short *)(puVar1 + 0x10) = 0;

  *(short *)(puVar1 + 0x12) = 0;

  *(short *)(puVar1 + 0x14) = 0;

  *(short *)(puVar1 + 0x16) = 0;

  *(int *)(puVar1 + 0x18) = 0;

  *(int *)(puVar1 + 0x1c) = 0;

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return;

}
