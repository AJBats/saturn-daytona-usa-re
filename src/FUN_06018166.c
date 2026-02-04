extern int DAT_06018212;

extern int DAT_06018214;

extern int DAT_06018216;

extern int DAT_06018218;

extern int DAT_0601821a;

extern int DAT_060182f2;

extern void FUN_06018320();
extern void FUN_060185d8();

void FUN_06018166()
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  puVar4 = 0x060684EC;

  puVar3 = 0x06063F64;

  puVar2 = 0x0605BE2C;

  iVar8 = (int)DAT_06018212;

  iVar5 = *(int *)0x0607E944;

  *(short *)0x0605BE2C = *(short *)0x0605BE2C + 1;

  bVar1 = *(unsigned int *)(iVar5 + DAT_06018214) < *(int *)0x06063F28 - 1U;

  if (bVar1) {

    uVar6 = *(int *)0x06089E28;

  }

  else {

    uVar6 = *(int *)0x06089E2C;

  }

  iVar5 = (int)DAT_06018216;

  if (*(short *)puVar2 < 6) {

    iVar7 = (int)DAT_06018218;

    *(int *)(puVar3 + (unsigned int)*(unsigned short *)(puVar4 + iVar8) * 8) =

         *(int *)(puVar3 + (unsigned int)*(unsigned short *)(puVar4 + iVar8) * 8) + iVar7;

    *(int *)(puVar3 + (unsigned int)*(unsigned short *)(puVar4 + iVar5) * 8) =

         *(int *)(puVar3 + (unsigned int)*(unsigned short *)(puVar4 + iVar5) * 8) + iVar7;

  }

  else {

    *(int *)(puVar3 + (unsigned int)*(unsigned short *)(puVar4 + iVar8) * 8) = uVar6;

    *(int *)(puVar3 + (unsigned int)*(unsigned short *)(puVar4 + iVar5) * 8) =

         *(int *)0x06089E30;

    *(short *)puVar2 = 0;

  }

  if (bVar1) {

    *(short *)(puVar3 + (unsigned int)*(unsigned short *)(puVar4 + iVar8) * 8 + 6) = DAT_060182f2;

  }

  else {

    *(short *)(puVar3 + (unsigned int)*(unsigned short *)(puVar4 + iVar8) * 8 + 6) = DAT_0601821a;

  }

  if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00800000) != 0) {

    FUN_060185d8();

    return;

  }

  FUN_06018320();

  return;

}
