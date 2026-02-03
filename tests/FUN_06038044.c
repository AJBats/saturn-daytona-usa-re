char * FUN_06038044(param_1)
    int param_1;
{

  char *puVar1;

  unsigned short uVar2;

  unsigned int uVar3;

  

  puVar1 = 0x060A3D88;

  uVar2 = 0;

  do {

    uVar3 = (unsigned int)uVar2;

    uVar2 = uVar2 + 1;

    *(short *)(puVar1 + (uVar3 << 1) + 0x10) = *(short *)((uVar3 << 1) + param_1);

  } while (uVar2 < 8);

  return puVar1;

}
