extern int DAT_06006116;

extern int PTR_DAT_06006118;

extern int PTR_DAT_06006118;

void FUN_06005ecc()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  char *puVar9;

  int iVar10;

  char auStack_38 [4];

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  puVar4 = 0x06063E60;

  puVar3 = 0x06063E74;

  puVar2 = 0x06063E4C;

  puVar1 = 0x06063E88;

  iVar10 = *(int *)0x0607E944;

  iVar8 = *(int *)(iVar10 + 0x10);

  iVar6 = *(int *)(iVar10 + 0x14);

  iVar7 = *(int *)(iVar10 + 0x18);

  (*(void(*)())0x06026DBC)();

  (*(void(*)())0x06026E0C)();

  (*(void(*)())0x06026EDE)(*(int *)(iVar10 + 0x20) + *(int *)0x06063F10);

  (*(void(*)())0x06026FFC)(0x0604464C,puVar2);

  (*(void(*)())0x06026FFC)(0x06044640,puVar4);

  (*(void(*)())0x06026FFC)(0x06044658,puVar1);

  (*(void(*)())0x06026FFC)(0x06044664,puVar3);

  (*(void(*)())0x06026FFC)(0x06044688,0x06063E9C);

  (*(void(*)())0x06026FFC)(0x0604467C,0x06063EB0);

  (*(void(*)())0x06026FFC)(0x06044694,0x06063ED8);

  (*(void(*)())0x06026FFC)(0x060446A0,0x06063EC4);

  *(int *)puVar2 = *(int *)puVar2 + iVar8;

  *(int *)(puVar2 + 4) = *(int *)(puVar2 + 4) + iVar6;

  *(int *)(puVar2 + 8) = *(int *)(puVar2 + 8) + iVar7;

  *(int *)puVar4 = *(int *)puVar4 + iVar8;

  *(int *)(puVar4 + 4) = *(int *)(puVar4 + 4) + iVar6;

  *(int *)(puVar4 + 8) = *(int *)(puVar4 + 8) + iVar7;

  *(int *)puVar1 = *(int *)puVar1 + iVar8;

  *(int *)(puVar1 + 4) = *(int *)(puVar1 + 4) + iVar6;

  *(int *)(puVar1 + 8) = *(int *)(puVar1 + 8) + iVar7;

  *(int *)puVar3 = *(int *)puVar3 + iVar8;

  *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) + iVar6;

  *(int *)(puVar3 + 8) = *(int *)(puVar3 + 8) + iVar7;

  puVar9 = 0x06063E9C;

  *(int *)0x06063E9C = *(int *)0x06063E9C + iVar8;

  *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + iVar7;

  puVar9 = 0x06063EB0;

  *(int *)0x06063EB0 = *(int *)0x06063EB0 + iVar8;

  *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + iVar7;

  puVar9 = 0x06063ED8;

  *(int *)0x06063ED8 = *(int *)0x06063ED8 + iVar8;

  *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + iVar7;

  puVar9 = 0x06063EC4;

  *(int *)0x06063EC4 = *(int *)0x06063EC4 + iVar8;

  *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + iVar7;

  uVar5 = (*(void(*)())0x06006838)(*(int *)puVar2,*(int *)(puVar2 + 8));

  (*(void(*)())0x06027EDE)(uVar5,puVar2,puVar2 + 0xe);

  uVar5 = (*(void(*)())0x06006838)(*(int *)puVar4,*(int *)(puVar4 + 8));

  (*(void(*)())0x06027EDE)(uVar5,puVar4,puVar4 + 0xe);

  uVar5 = (*(void(*)())0x06006838)(*(int *)puVar1,*(int *)(puVar1 + 8));

  (*(void(*)())0x06027EDE)(uVar5,puVar1,puVar1 + 0xe);

  uVar5 = (*(void(*)())0x06006838)(*(int *)puVar3,*(int *)(puVar3 + 8));

  (*(void(*)())0x06027EDE)(uVar5,puVar3,puVar3 + 0xe);

  iVar6 = *(int *)(puVar4 + 4) + *(int *)(puVar2 + 4) + *(int *)(puVar1 + 4) + *(int *)(puVar3 + 4)

          >> 2;

  *(int *)(iVar10 + 0x14) = iVar6;

  (*(void(*)())0x06026FFC)(0x060446AC,&iStack_2c);

  iStack_2c = iStack_2c + iVar8;

  iStack_28 = iStack_28 + iVar6;

  iStack_24 = iStack_24 + iVar7;

  uVar5 = (*(void(*)())0x06006838)(iStack_2c,iStack_24);

  (*(void(*)())0x06027EDE)(uVar5,&iStack_2c,auStack_38);

  if ((iVar6 == iStack_28) ||

     ((iVar6 = iStack_28, puVar9 = 0x000D6666, *(int *)0x0607EAD8 == 1 &&

      ((int)PTR_DAT_06006118 <= *(int *)(iVar10 + DAT_06006116))))) {

    iVar6 = (*(void(*)())0x06027552)(0x00008000,*(int *)(puVar2 + 4) + *(int *)(puVar4 + 4));

    puVar9 = 0x0002CCCC;

  }

  iStack_34 = (*(void(*)())0x06027552)(0x00008000,*(int *)(puVar3 + 4) + *(int *)(puVar1 + 4));

  iVar7 = (*(void(*)())0x06027552)(0x00008000,*(int *)(puVar3 + 4) + *(int *)(puVar2 + 4));

  iStack_30 = (*(void(*)())0x06027552)(0x00008000,*(int *)(puVar1 + 4) + *(int *)(puVar4 + 4));

  uVar5 = (*(void(*)())0x0602744C)(iVar6 - iStack_34,puVar9);

  *(int *)(iVar10 + 0x1c) = uVar5;

  uVar5 = (*(void(*)())0x0602744C)(iVar7 - iStack_30,0x00011998);

  *(int *)(iVar10 + 0x24) = uVar5;

  *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;

  return;

}
