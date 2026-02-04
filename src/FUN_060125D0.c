extern int DAT_060126a2;

extern int DAT_060126a4;

void FUN_060125d0()
{

  char *puVar1;

  int iVar2;

  int iVar3;

  int *puVar4;

  unsigned short auStack_14 [6];

  puVar1 = 0x060788B0;

  (*(void(*)())0x06035228)();

  (*(void(*)())0x06026DBC)();

  (*(void(*)())0x06026E0C)();

  (*(void(*)())0x06026E2E)(*(int *)0x060788B4,*(int *)(0x060788B4 + 4),

             *(int *)(0x060788B4 + 8));

  (*(void(*)())0x06026F2A)((int)*(short *)0x060788B2);

  iVar2 = (*(void(*)())0x06034FE0)();

  iVar3 = iVar2 * 2;

  puVar4 = (int *)(0x06063750 + (unsigned int)auStack_14[iVar2] * 8);

  (*(void(*)())0x06028400)(8,*puVar4,(int)DAT_060126a2,0x0000B000 + puVar4[1],puVar4,iVar3,iVar2);

  if (*(short *)puVar1 != *(short *)(0x0605AC94 + iVar3)) {

    *(short *)puVar1 = *(short *)puVar1 - DAT_060126a4;

  }

  (*(void(*)())0x06026EDE)(0);

  (*(void(*)())0x06026E94)((int)*(short *)puVar1);

  (*(void(*)())0x06031D8C)(*(int *)(0x0606354C + (*(int *)0x0607EAD8 + -1) * 4),

             *(int *)0x06063558);

  (*(void(*)())0x06031A28)(*(int *)(0x06063544 + (*(int *)0x0607EAD8 + -1) * 4),

             (int)*(short *)0x06089EA0,*(int *)0x06063554);

  (*(void(*)())0x06026DF8)();

  return;

}
