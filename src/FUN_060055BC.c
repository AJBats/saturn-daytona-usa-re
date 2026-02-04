extern void FUN_06005294();
extern void FUN_0600553c();

void FUN_060055bc(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  short *psVar6;

  short *psVar7;

  char *puVar8;

  int iStack_50;

  int iStack_4c;

  int iStack_48;

  int iStack_44;

  int iStack_40;

  int iStack_3c;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  puVar8 = 0x06063E08;

  puVar1 = 0x06063EEC;

  psVar6 = *(short **)0x06063E04;

  psVar7 = psVar6 + 0x10;

  if ((int)*psVar7 <= (int)(unsigned int)*(unsigned short *)0x06063E08) {

    if (*psVar7 == -1) {

      psVar7 = *(short **)(psVar6 + 0x12);

    }

    psVar6 = psVar7;

    *(short **)0x06063E04 = psVar6;

    psVar7 = psVar6 + 0x10;

    if (*psVar6 == 0) {

      *(short *)puVar8 = 0;

    }

  }

  iVar5 = (int)*psVar6;

  uVar4 = (*0x0602755C)

                    (((unsigned int)*(unsigned short *)puVar8 - iVar5) * 0x10000,(*psVar7 - iVar5) * 0x10000,param_3

                     ,param_4,iVar5);

  FUN_0600553c(psVar6 + 1,0);

  puVar2 = 0x06026FFC;

  (*0x06026FFC)(psVar6 + 4,&iStack_2c);

  FUN_0600553c(psVar7 + 1,psVar6 + 1);

  (*puVar2)(psVar7 + 4,&iStack_38);

  puVar3 = 0x06027552;

  iVar5 = iStack_2c;

  iStack_44 = (*0x06027552)(iStack_38 - iStack_2c,uVar4);

  iStack_44 = iStack_44 + iVar5;

  iVar5 = iStack_28;

  iStack_40 = (*puVar3)(iStack_34 - iStack_28,uVar4);

  iStack_40 = iStack_40 + iVar5;

  iVar5 = iStack_24;

  iStack_3c = (*puVar3)(iStack_30 - iStack_24,uVar4);

  iStack_3c = iStack_3c + iVar5;

  FUN_0600553c((int)psVar6 + 3,psVar7 + 1);

  (*puVar2)(psVar6 + 10,&iStack_2c);

  FUN_0600553c((int)psVar7 + 3,(int)psVar6 + 3);

  (*puVar2)(psVar7 + 10,&iStack_38);

  iStack_50 = (*puVar3)(iStack_38 - iStack_2c,uVar4);

  iStack_50 = iStack_50 + iStack_2c;

  iStack_4c = (*puVar3)(iStack_34 - iStack_28,uVar4);

  iStack_4c = iStack_4c + iStack_28;

  iStack_48 = (*puVar3)(iStack_30 - iStack_24,uVar4);

  iStack_48 = iStack_48 + iStack_24;

  *(short *)puVar8 = *(short *)puVar8 + 1;

  (*0x06026E0C)();

  FUN_06005294(&iStack_44,&iStack_50,0x06063EEC);

  if (*0x06078663 == '\0') {

    puVar8 = (char *)(*(int *)(puVar1 + 4) * -0x400 + 0xFFA00000);

  }

  else {

    puVar8 = 0x01A00000 + *(int *)(puVar1 + 4) * 0x400;

  }

  (*0x0603850C)(4);

  (*0x0603853C)(puVar8,0x003A0000 + *(int *)puVar1 * -0x200,0);

  (*0x06038520)();

  return;

}
