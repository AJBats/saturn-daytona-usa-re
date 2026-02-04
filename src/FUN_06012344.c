extern int DAT_060123de;

extern int DAT_060123e0;

extern int DAT_060123e2;

void FUN_06012344()
{

  int iVar1;

  int iVar2;

  char *puVar3;

  int iVar4;

  puVar3 = 0x06027552;

  iVar4 = ((int)(*(int *)0x060788AC + (unsigned int)(*(int *)0x060788AC < 0)) >> 1) << 0x10;

  iVar1 = (*(void(*)())0x06027552)(iVar4,(int)DAT_060123de);

  iVar2 = (*(void(*)())puVar3)(iVar4,(int)DAT_060123e0);

  iVar4 = (*(void(*)())puVar3)(iVar4,(int)DAT_060123e2);

  puVar3 = 0x060788C0;

  *(int *)0x060788C0 = *(int *)0x060788C0 + iVar1 * -2;

  *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) + iVar2;

  *(int *)(puVar3 + 8) = *(int *)(puVar3 + 8) + iVar4;

  puVar3 = 0x060788CC;

  *(int *)0x060788CC = *(int *)0x060788CC - iVar2;

  *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) - iVar1;

  *(int *)(puVar3 + 8) = *(int *)(puVar3 + 8) - iVar1;

  puVar3 = 0x060788D8;

  *(int *)0x060788D8 = *(int *)0x060788D8 + iVar1 * 2;

  iVar1 = (*(void(*)())0x06034FE0)();

  *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) - iVar1;

  *(int *)(puVar3 + 8) = *(int *)(puVar3 + 8) - iVar4;

  puVar3 = 0x060788E4;

  *(int *)0x060788E4 = *(int *)0x060788E4 + iVar2;

  *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) + iVar2;

  *(int *)(puVar3 + 8) = *(int *)(puVar3 + 8) + iVar4;

  return;

}
