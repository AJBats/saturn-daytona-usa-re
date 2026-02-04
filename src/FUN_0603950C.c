extern int DAT_060395b6;

extern int DAT_060397f4;

extern int DAT_060397f6;

extern int DAT_060397f8;

extern void FUN_0603a6c0();
extern void FUN_0603a72c();

void FUN_0603950c(char param_1,short param_2,char param_3,char param_4,
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  unsigned short uVar9;

  int iVar10;

  puVar8 = 0x20100079;

  puVar7 = 0x060A4CB0;

  puVar6 = 0x060A4CAC;

  puVar5 = 0x060A4CC0;

  puVar4 = 0x06063602;

  puVar3 = 0x060A4CBC;

  puVar2 = 0x060A4CAE;

  *0x20100079 = 0;

  puVar8[2] = 0;

  puVar8[6] = 0;

  puVar8[4] = 0;

  (**(void **)0x06000300)(0x47,0x0603990E);

  (**(void **)0x06000344)((int)DAT_060395b6,0);

  puVar8 = 0x060A4CAA;

  *0x060A4CAA = param_1;

  cVar1 = *puVar8;

  if (cVar1 == '\0') {

    *puVar4 = 1;

    puVar4[1] = 0;

    *0x060A4CA8 = 0;

    (*0x0603A72C)();

    return;

  }

  if (cVar1 == '\x01') {

    *puVar4 = 0;

    puVar4[1] = 8;

  }

  else if (cVar1 == '\x02') {

    *puVar4 = 1;

    puVar4[1] = 8;

    *0x060A4CD8 = 0;

  }

  *puVar2 = param_4;

  *(short *)puVar6 = param_2;

  *0x060A4CAB = param_6;

  *0x060A4CAF = param_3;

  *(int *)puVar7 = param_5;

  *(int *)0x060A4CB8 = 0;

  if (0xf < (unsigned char)*puVar2) {

    puVar4[1] = puVar4[1] | 0x50;

  }

  puVar4 = 0x060A4CD9;

  *(char **)0x060A4CE8 = 0x060A4CD9;

  *(char **)0x060A4C98 = puVar4 + 7;

  *(int *)puVar3 = *(int *)puVar7;

  puVar4 = 0x060A4CC8;

  uVar9 = (unsigned short)(unsigned char)*0x060A4CAF;

  if (uVar9 == 0) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 6 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0xc + *(int *)puVar7;

  }

  else if (uVar9 == 0x10) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 0x12 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0x24 + *(int *)puVar7;

  }

  else if (uVar9 == 0x20) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 0x12 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0x24 + *(int *)puVar7;

  }

  else if (uVar9 == 0x30) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 10 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0x14 + *(int *)puVar7;

  }

  else if (uVar9 == DAT_060397f4) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 3 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 6 + *(int *)puVar7;

  }

  else if (uVar9 == DAT_060397f6) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 6 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0xc + *(int *)puVar7;

  }

  else if (uVar9 == DAT_060397f8) {

    iVar10 = ((unsigned char)*puVar2 + 1) * (unsigned int)*(unsigned short *)puVar6;

    *(int *)puVar5 = *(int *)puVar7 + iVar10;

    *(int *)puVar4 = iVar10 * 2 + *(int *)puVar7;

  }

  *(int *)0x060A4CB4 = 0;

  (*0x0603A766)();

  puVar2 = 0x060A4CC4;

  *(int *)0x060A4CC4 = *(int *)puVar5;

  *(int *)puVar5 = *(int *)puVar3;

  *(int *)puVar3 = *(int *)puVar2;

  *(int *)0x060A4CB4 = 0;

  (*0x0603A766)();

  FUN_0603a6c0();

  FUN_0603a72c();

  return;

}
