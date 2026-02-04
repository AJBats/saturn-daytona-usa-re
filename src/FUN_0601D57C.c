void FUN_0601d57c(param_1)
    unsigned short param_1;
{

  char *puVar1;

  char *puVar2;

  unsigned short uVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  puVar2 = 0x0605AAA6;

  puVar1 = 0x06094FAC;

  uVar3 = 0;

  do {

    uVar4 = (unsigned int)uVar3;

    uVar5 = (unsigned int)uVar3;

    uVar3 = uVar3 + 1;

    *(short *)(puVar2 + uVar4 * 4) = *(short *)(puVar1 + uVar5 * 0x58 + (unsigned int)param_1 * 2)

    ;

    *(short *)((int)(puVar2 + uVar4 * 4) + 2) =

         *(short *)((int)(puVar1 + uVar5 * 0x58 + (unsigned int)param_1 * 2) + 2);

  } while (uVar3 < 0x1c);

  (*0x06028400)(0xc,0x0605AAA2,(param_1 & 0x3f) << 1,0);

  return;

}
