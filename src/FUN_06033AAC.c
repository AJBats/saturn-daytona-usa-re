long long FUN_06033aac()
{

  int iVar1;

  short *psVar2;

  int *puVar3;

  int *puVar4;

  char *puVar5;

  unsigned int uVar6;

  int iVar7;

  int iVar8;

  uVar6 = 0;

  do {

    puVar5 = 0x06082A7C;

    iVar8 = (0x0000002C & 0xffff) * (uVar6 & 0xffff);

    0x06082A7C[0x00000000 + iVar8] = (char)uVar6;

    puVar5[0x00000010 + iVar8] = 0;

    puVar5[0x00000011 + iVar8] = 0;

    puVar5[0x00000026 + iVar8] = 0;

    puVar5[0x00000028 + iVar8] = 0;

    psVar2 = (short *)(0x060631BC + (0x0000000E & 0xffff) * (uVar6 & 0xffff));

    *(int *)(puVar5 + 0x00000014 + iVar8) = (int)*psVar2 << 0x10;

    *(int *)(puVar5 + 0x00000018 + iVar8) = (int)psVar2[1] << 0x10;

    *(int *)(puVar5 + 0x0000001C + iVar8) = (int)psVar2[2] << 0x10;

    *(int *)(puVar5 + 0x00000020 + iVar8) = (int)psVar2[3] << 0x10;

    *(short *)(puVar5 + 0x00000002 + iVar8) = psVar2[4];

    *(short *)(puVar5 + 0x00000012 + iVar8) = psVar2[5];

    *(short *)(puVar5 + 0x00000024 + iVar8) = (short)*(char *)(psVar2 + 6) << 8;

    puVar5[0x00000001 + iVar8] = *(char *)((int)psVar2 + 0xd);

    uVar6 = uVar6 + 1;

  } while ((int)uVar6 < 0x0000002D);

  *0x06083254 = 0;

  *(int *)0x06083250 = 0;

  iVar8 = 0x00000014;

  iVar7 = 0;

  puVar4 = (int *)0x060631AC;

  puVar5 = 0x0607EB94;

  do {

    puVar3 = (int *)*puVar4;

    puVar4 = puVar4 + 1;

    *puVar3 = puVar5;

    iVar1 = 0x00000006;

    puVar5[0x00000006] = (char)iVar7;

    puVar5 = puVar5 + iVar8;

    iVar7 = iVar7 + 1;

  } while (iVar7 < 2);

  return CONCAT44(psVar2 + 7,iVar1);

}
