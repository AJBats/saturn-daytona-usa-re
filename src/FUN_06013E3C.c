extern int DAT_06013f46;

extern int DAT_06013f48;

extern int DAT_06013f4a;

extern int DAT_06013f4c;

int FUN_06013e3c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int uVar7;

  int uVar8;

  int iVar9;

  int *piVar10;

  int iVar11;

  int *piVar12;

  puVar4 = 0x00010000;

  puVar3 = 0x06084AF6;

  puVar2 = 0x06027552;

  puVar1 = 0x06026F2A;

  (*(void(*)())0x06026E0C)();

  puVar5 = 0x06089E4A;

  iVar11 = 0;

  piVar10 = (int *)(0x0605AD5C + DAT_06013f46);

  piVar12 = (int *)0x0605AD5C;

  do {

    (*(void(*)())0x06026DBC)();

    iVar6 = (*(void(*)())puVar2)((unsigned int)*(unsigned short *)puVar3 * (int)puVar4,(int)DAT_06013f48,puVar4);

    (*(void(*)())0x06026E2E)(0,DAT_06013f4a + iVar6,puVar4);

    (*(void(*)())puVar1)((int)*(short *)(piVar12 + 6));

    uVar7 = (*(void(*)())puVar2)(piVar12[1],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar6 = (*(void(*)())puVar2)(piVar12[2],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar9 = *piVar12;

    uVar8 = (*(void(*)())puVar2)(piVar12[3],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    (*(void(*)())0x06026E2E)(uVar7,iVar9 - iVar6,uVar8);

    (*(void(*)())puVar1)(-(int)*(short *)(piVar12 + 6));

    (*(void(*)())0x06026E94)((int)*(short *)((int)piVar12 + 0x1a) * (unsigned int)*(unsigned short *)puVar3);

    (*(void(*)())0x06026EDE)((int)*(short *)(piVar12 + 7) * (unsigned int)*(unsigned short *)puVar3);

    (*(void(*)())puVar1)((int)*(short *)((int)piVar12 + 0x1e) * (unsigned int)*(unsigned short *)puVar3);

    iVar6 = (*(void(*)())puVar2)(piVar12[4],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar6 = DAT_06013f4c + iVar6;

    (*(void(*)())0x06026E60)(iVar6,iVar6,iVar6);

    (*(void(*)())0x06031D8C)(*(int *)(0x06062338 + iVar11),4);

    uVar7 = (*(void(*)())0x06031A28)(*(int *)(0x060622C0 + iVar11),(int)*(short *)puVar5,1);

    piVar12 = piVar12 + 8;

    *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;

    iVar11 = iVar11 + 4;

  } while (piVar12 < piVar10);

  return uVar7;

}
