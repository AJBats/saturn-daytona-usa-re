extern int DAT_0603881a;

extern int PTR_DAT_060388b4;

extern int PTR_DAT_060388b4;

void FUN_06038794(param_1, param_2)
    char *param_1;
    char *param_2;
{

  char *puVar1;

  char *puVar2;

  short sVar3;

  int iVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  puVar2 = 0x00010000;

  puVar1 = 0x0603C0A0;

  puVar5 = (char *)(int)DAT_0603881a;

  iVar4 = *(int *)0x060635A8;

  puVar6 = param_2;

  puVar7 = param_1;

  if ((iVar4 != 1) && (iVar4 != 2)) {

    if ((iVar4 != 4) && (iVar4 != 8)) goto LAB_06038802;

    puVar7 = 0x00FF0000;

    if ((((int)param_1 <= (int)0x00FF0000) && (puVar7 = puVar5, (int)puVar5 <= (int)param_1))

       && (puVar7 = param_1, param_1 == (char *)0x0)) {

      puVar7 = 0x00010000;

    }

    puVar6 = 0x00FF0000;

    if ((((int)param_2 <= (int)0x00FF0000) && (puVar6 = puVar5, (int)puVar5 <= (int)param_2))

       && (puVar6 = param_2, param_2 == (char *)0x0)) {

      puVar6 = 0x00010000;

    }

  }

  param_1 = (char *)(*(int(*)())0x0603C0A0)(0x00010000,puVar7);

  param_2 = (char *)(*(int(*)())puVar1)(puVar2,puVar6);

LAB_06038802:

  sVar3 = PTR_DAT_060388b4;

  puVar6 = 0x060A3DF8;

  puVar2 = 0x060A3E68;

  puVar1 = 0x060A3E38;

  iVar4 = *(int *)0x060635A8;

  if (iVar4 == 1) {

    *(char **)(0x060A3E68 + 0x4c) = param_1;

    *(char **)(puVar2 + 0x50) = param_2;

    if ((*(unsigned short *)(puVar1 + 4) & 0xff) != 0) {

      (*(int(*)())0x0603DDFC)(0,0);

      return;

    }

  }

  else if (iVar4 == 2) {

    *(char **)(0x060A3E68 + PTR_DAT_060388b4 + 0x4c) = param_1;

    *(char **)(puVar2 + sVar3 + 0x50) = param_2;

    if (((unsigned int)*(unsigned short *)(puVar1 + 4) & (unsigned int)0x0000FF00) != 0) {

      (*(int(*)())0x0603DDFC)(0,0);

      return;

    }

  }

  else if (iVar4 == 4) {

    *(char **)(0x060A3DF8 + 8) = param_1;

    *(char **)(puVar6 + 0xc) = param_2;

  }

  else if (iVar4 == 8) {

    *(char **)(0x060A3DF8 + 0x18) = param_1;

    *(char **)(puVar6 + 0x1c) = param_2;

  }

  return;

}
