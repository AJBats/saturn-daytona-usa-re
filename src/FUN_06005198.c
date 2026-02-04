void FUN_06005198()
{

  unsigned short uVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  char *puVar6;

  unsigned short *local_14 [2];

  puVar6 = 0x06063D98;

  (*0x06039808)(local_14);

  uVar2 = local_14[0][4];

  uVar3 = local_14[0][1];

  uVar1 = local_14[0][9];

  uVar4 = local_14[0][0xd];

  uVar5 = local_14[0][10];

  if (*(int *)0x06059F44 == 1) {

    *(unsigned short *)puVar6 = ~*local_14[0];

    *(unsigned short *)(puVar6 + 2) = ~uVar2;

    *(unsigned short *)(puVar6 + 4) = ~uVar3;

    *(unsigned short *)(puVar6 + 6) = (unsigned short)*(unsigned char *)(local_14[0] + 8);

    *(unsigned short *)(puVar6 + 8) = ~uVar1;

    *(unsigned short *)(puVar6 + 10) = ~uVar4;

    *(unsigned short *)(puVar6 + 0xc) = ~uVar5;

    *(unsigned short *)(puVar6 + 0xe) = (unsigned short)*(unsigned char *)(local_14[0] + 0x11);

  }

  else {

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 | ~*local_14[0];

    *(unsigned short *)(puVar6 + 2) = *(unsigned short *)(puVar6 + 2) | ~uVar2;

    *(unsigned short *)(puVar6 + 4) = ~uVar3;

    *(unsigned short *)(puVar6 + 8) = *(unsigned short *)(puVar6 + 8) | ~uVar1;

    *(unsigned short *)(puVar6 + 10) = *(unsigned short *)(puVar6 + 10) | ~uVar4;

    *(unsigned short *)(puVar6 + 0xc) = ~uVar5;

  }

  if (*(short *)(puVar6 + 6) == 0x20) {

    *(short *)puVar6 = 0;

    *(short *)(puVar6 + 2) = 0;

    *(short *)(puVar6 + 4) = 0;

    *(short *)(puVar6 + 8) = 0;

    *(short *)(puVar6 + 10) = 0;

    *(short *)(puVar6 + 0xc) = 0;

  }

  return;

}
