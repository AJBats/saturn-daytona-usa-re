extern int DAT_0600635e;

extern int DAT_06006360;

extern int DAT_06006362;

extern int PTR_DAT_0600644c;

extern int PTR_DAT_0600644c;

extern int PTR_DAT_0600654c;

extern int PTR_DAT_0600654c;

extern int FUN_060067c8();

void FUN_0600629c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  puVar4 = 0x0607E940;

  puVar3 = 0x0607E944;

  puVar2 = 0x0600E1D4;

  puVar1 = 0x06078900;

  iVar7 = 0x268;

  *(short *)0x0605DF4E = 0;

  *(short *)0x0605DF50 = 0;

  *(short *)0x0605DF52 = 0;

  *(short *)0x0605DF54 = 0;

  if (*(int *)0x06078635 == '\0') {

    for (iVar6 = 0; iVar6 < *(int *)0x0607EA98; iVar6 = iVar6 + 1) {

      *(char **)puVar4 = puVar1 + iVar6 * iVar7;

      *(int *)(puVar1 + iVar6 * iVar7 + 4) = iVar6;

      (*(int(*)())puVar2)();

    }

  }

  else {

    *(char **)puVar4 = puVar1 + iVar7;

    *(char **)puVar3 = puVar1 + iVar7;

    *(int *)(*(int *)puVar4 + 4) = 0;

    (*(int(*)())puVar2)();

    *(int *)(*(int *)puVar3 + 0x74) = 0x38;

    *(int *)(*(int *)puVar3 + 0x90) = 0x38;

    puVar5 = 0x0607ED90;

    *(unsigned short *)(*(int *)puVar3 + 0x9e) = (unsigned short)(unsigned char)*(int *)0x0607ED90;

    *(unsigned short *)(*(int *)puVar3 + 0x7c) = (unsigned short)(unsigned char)puVar5[1];

    *(unsigned short *)(*(int *)puVar3 + (int)DAT_06006360) = (unsigned short)(unsigned char)puVar5[2];

    if (*(int *)0x0607EAD8 == 0) {

      iVar7 = (int)DAT_06006362;

      *(short *)(*(int *)puVar4 + iVar7) = 3;

      *(short *)(*(int *)puVar4 + iVar7 + 2) = 3;

    }

    else {

      iVar7 = (int)DAT_06006362;

      *(short *)(*(int *)puVar4 + iVar7) = 0;

      *(short *)(*(int *)puVar4 + iVar7 + 2) = 0;

    }

    *(char **)puVar4 = puVar1;

    *(char **)puVar3 = puVar1;

    *(int *)(*(int *)puVar4 + 4) = 0;

    (*(int(*)())puVar2)();

  }

  *(int *)(*(int *)puVar3 + 0x74) = 0x38;

  *(int *)(*(int *)puVar3 + 0x90) = 0x38;

  *(short *)(*(int *)puVar3 + 0x9c) = (short)*(int *)0x0607EAB8;

  *(short *)(*(int *)puVar3 + 0x9e) = *(short *)0x06063F42;

  *(short *)(*(int *)puVar3 + 0x7c) = (short)*(int *)0x06078868;

  (*(int(*)())0x0600D280)();

  (*(int(*)())0x0602E5E4)();

  if ((*(int *)0x0607EBC0 == 0xe) && (*(int *)0x0607EAD8 == 0)) {

    *(int *)0x0607EAD0 = 1;

  }

  else {

    *(int *)0x0607EAD0 = 0;

  }

  puVar1 = 0x06063EF0;

  iVar7 = *(int *)puVar3;

  *(int *)0x06063EF0 = *(int *)(iVar7 + 0x20);

  *(int *)(puVar1 + 4) = 0;

  *(int *)0x06063F10 = 0;

  puVar1 = 0x06063E78;

  *(int *)0x06063E78 = 0;

  puVar2 = 0x06063E8C;

  *(int *)0x06063E8C = *(int *)puVar1;

  puVar1 = 0x06063E64;

  *(int *)0x06063E64 = *(int *)puVar2;

  *(int *)0x06063E50 = *(int *)puVar1;

  *(int *)0x06063F14 = 0xFEA00000;

  if (*(int *)0x0607EAD8 == 0) {

    iVar6 = (int)PTR_DAT_0600654c;

    *(short *)(iVar7 + iVar6) = 3;

    *(short *)(iVar7 + iVar6 + 2) = 3;

  }

  else {

    iVar6 = (int)PTR_DAT_0600644c;

    *(short *)(iVar7 + iVar6) = 0;

    *(short *)(iVar7 + iVar6 + 2) = 0;

  }

  *(int *)0x060620D0 = 0;

  *(int *)0x06063E1C = 2;

  *(int *)0x06059F30 = 1;

  (*(int(*)())0x06038BD4)(8,0);

  *(char **)0x06063E24 = 0x00058000;

  puVar1 = 0x0000F300;

  *(char **)0x06063E34 = 0x0000F300;

  *(char **)0x06063E28 = 0x006E0000;

  *(char **)0x06063E2C = 0x00100000;

  *(int *)0x06063E30 = 0;

  *(char **)0x06063EEC = puVar1;

  *(int *)0x06063E20 = 2;

  FUN_060067c8();

  return;

}
