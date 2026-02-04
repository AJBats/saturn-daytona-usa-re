extern int DAT_06038cc8;

extern int DAT_06038cca;

extern int DAT_06038cce;

extern int DAT_06038cd0;

extern int DAT_06038cd2;

extern int DAT_06038cd4;

extern int DAT_06038cd6;

extern int DAT_06038e1a;

extern int PTR_DAT_06038e20;

extern int PTR_DAT_06038e20;

void FUN_06038bd4(param_1, param_2)
    unsigned int param_1;
    unsigned int param_2;
{

  unsigned short uVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  short uVar7;

  unsigned short *puVar8;

  unsigned int uVar9;

  puVar6 = 0x060A4D30;

  puVar5 = 0x0000F0FF;

  puVar4 = 0x0000FF00;

  uVar3 = DAT_06038cc8;

  uVar9 = 1;

  param_2 = param_2 & 0xff;

  uVar1 = (unsigned short)0x0000FFF0;

  puVar8 = (unsigned short *)0x060A4D28;

  if (((int)DAT_06038cca & param_1) != 0) {

    (*0x06034F78)();

    *puVar8 = *puVar8 & uVar1 | (unsigned short)param_2;

  }

  uVar2 = (unsigned short)puVar5;

  if (((int)DAT_06038cce & param_1) != 0) {

    (*0x06034F78)();

    *puVar8 = *puVar8 & uVar2 | (unsigned short)((param_2 & 0xffff) << 8);

  }

  if (((int)DAT_06038cd0 & param_1) != 0) {

    (*0x06034F78)();

    puVar8[1] = puVar8[1] & uVar1 | (unsigned short)param_2;

  }

  if (((int)DAT_06038cd2 & param_1) != 0) {

    (*0x06034F78)();

    puVar8[1] = puVar8[1] & uVar2 | (unsigned short)((param_2 & 0xff) << 8);

  }

  if (((int)DAT_06038cd4 & param_1) != 0) {

    (*0x06034F78)();

    puVar8[2] = puVar8[2] & uVar1 | (unsigned short)param_2;

  }

  if (((int)DAT_06038cd6 & param_1) != 0) {

    (*0x06034F78)();

    puVar8[2] = puVar8[2] & uVar2 | (unsigned short)((param_2 & 0xff) << 8);

  }

  if (((int)DAT_06038e1a & param_1) != 0) {

    (*0x06034F78)();

    puVar8[3] = puVar8[3] & uVar1 | (unsigned short)param_2;

  }

  if (((unsigned int)0x00008000 & param_1) != 0) {

    (*0x06034F78)();

    puVar8[3] = puVar8[3] & uVar2 | (unsigned short)((param_2 & 0xff) << 8);

  }

  uVar1 = (unsigned short)puVar4;

  if ((param_1 & 4) != 0) {

    (*0x06034F78)();

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 & uVar1 | (unsigned short)param_2;

  }

  if ((param_1 & 2) != 0) {

    (*0x06034F78)();

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 & uVar1 | (unsigned short)param_2;

  }

  if ((param_1 & 8) != 0) {

    (*0x06034F78)();

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 & uVar3 | (unsigned short)((param_2 & 0xffff) << 8);

  }

  if (((int)PTR_DAT_06038e20 & param_1) != 0) {

    (*0x06034F78)();

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 & uVar3 | (unsigned short)((param_2 & 0xffff) << 8);

  }

  if ((param_1 & 0x10) != 0) {

    (*0x06034F78)();

    *(unsigned short *)(puVar6 + 2) = *(unsigned short *)(puVar6 + 2) & uVar1 | (unsigned short)param_2;

  }

  uVar7 = (short)param_2;

  if ((param_1 & 0x20) != 0) {

    (*0x06034F78)();

    uVar7 = (short)param_2;

    *(unsigned short *)(puVar6 + 2) = *(unsigned short *)(puVar6 + 2) & uVar3 | (unsigned short)((param_2 & 0xff) << 8);

  }

  if ((param_1 & uVar9) != 0) {

    (*0x06034F78)();

    *(short *)(puVar6 + 4) = uVar7;

  }

  return;

}
