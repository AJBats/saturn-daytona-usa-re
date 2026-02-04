extern int DAT_0603cd4c;

void FUN_0603cc88(param_1, param_2, param_3, param_4)
    int param_1;
    short param_2;
    short param_3;
    short param_4;
{

  unsigned short uVar1;

  char *puVar2;

  puVar2 = 0x060A4D46;

  uVar1 = DAT_0603cd4c;

  if (param_1 == 0) {

    (*0x06034F78)();

    *(unsigned short *)(puVar2 + 4) = (*(unsigned short *)(puVar2 + 4) & uVar1) + param_2;

    (*0x06034F78)();

    *(unsigned short *)(puVar2 + 6) = (*(unsigned short *)(puVar2 + 6) & uVar1) + param_3;

    (*0x06034F78)();

    *(unsigned short *)(puVar2 + 8) = (*(unsigned short *)(puVar2 + 8) & uVar1) + param_4;

  }

  else {

    (*0x06034F78)();

    *(unsigned short *)(puVar2 + 10) = (*(unsigned short *)(puVar2 + 10) & uVar1) + param_2;

    (*0x06034F78)();

    *(unsigned short *)(puVar2 + 0xc) = (*(unsigned short *)(puVar2 + 0xc) & uVar1) + param_3;

    (*0x06034F78)();

    *(unsigned short *)(puVar2 + 0xe) = (*(unsigned short *)(puVar2 + 0xe) & uVar1) + param_4;

  }

  return;

}
