extern int PTR_DAT_0601a4a8;

extern int PTR_DAT_0601a4a8;

void FUN_0601a3f4(param_1, param_2)
    unsigned short param_1;
    unsigned int param_2;
{

  unsigned char bVar1;

  char *puVar2;

  char *puVar3;

  unsigned char *pbVar4;

  char *puVar5;

  int iVar6;

  unsigned char bVar7;

  puVar3 = 0x06049E54;

  puVar2 = 0x060283E0;

  puVar5 = 0x06049B36;

  if ((param_2 & 0xffff) == 0xa8) {

    bVar1 = ((int *)0x06049CD4)[param_1];

    if ((param_1 == 1) || (param_1 == 4)) {

      iVar6 = 2;

    }

    else {

      iVar6 = 3;

    }

    pbVar4 = 0x06049CCC + param_1;

    for (bVar7 = 0; bVar7 < *pbVar4; bVar7 = bVar7 + 1) {

      (*(int(*)())puVar2)(iVar6 << 2,

                        ((unsigned int)(unsigned char)((char *)(0x06049C28 + ((unsigned int)bVar1 + (unsigned int)bVar7) << 1))[1] * 0x40

                        + (unsigned int)(unsigned char)((int *)0x06049C28)[((unsigned int)bVar1 + (unsigned int)bVar7) << 1]) << 1,0,

                        puVar3);

    }

    pbVar4 = 0x06059084 + (unsigned int)(param_1 << 1);

    puVar5 = 0x06049E58;

  }

  else {

    bVar1 = ((int *)0x06049C1E)[param_1];

    if ((param_1 == 5) || (param_1 == 8)) {

      iVar6 = 2;

    }

    else {

      iVar6 = 3;

    }

    pbVar4 = 0x06049C14 + param_1;

    for (bVar7 = 0; bVar7 < *pbVar4; bVar7 = bVar7 + 1) {

      (*(int(*)())puVar2)(iVar6 << 2,

                        ((unsigned int)(unsigned char)(puVar5 + ((unsigned int)bVar1 + (unsigned int)bVar7) << 1)[1] * 0x40 +

                        (unsigned int)(unsigned char)puVar5[((unsigned int)bVar1 + (unsigned int)bVar7) << 1]) << 1,0,puVar3);

    }

    pbVar4 = 0x06059060 + (unsigned int)(param_1 << 1);

    puVar5 = 0x06049E58;

  }

  (*(int(*)())0x060284AE)(iVar6 << 2,((unsigned int)pbVar4[1] * 0x40 + (unsigned int)*pbVar4) << 1,0x60,puVar5);

  return;

}
