extern int DAT_0600ebd8;

extern int DAT_0600ebda;

void FUN_0600eb14()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int *puVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  uVar6 = (unsigned int)DAT_0600ebd8;

  uVar5 = 0;

  puVar4 = (int *)0x06078900;

  do {

    *puVar4 = 0;

    uVar5 = uVar5 + 1;

    puVar4 = puVar4 + 1;

  } while (uVar5 < uVar6);

  (*0x06026E02)();

  (*0x060270C6)();

  (*0x0600629C)();

  puVar1 = 0x06078900;

  iVar3 = (int)DAT_0600ebda;

  *(int *)(0x06078900 + iVar3) = 1;

  *(int *)(puVar1 + iVar3 + 4) = 1;

  *(int *)(puVar1 + iVar3 + 8) = 1;

  *(int *)(puVar1 + iVar3 + 0xc) = 1;

  *(short *)0x06063F46 = 0;

  *(int *)0x0607EAE4 = 0;

  *(int *)0x0607EAE8 = 0;

  *(int *)0x0607EAEC = 0;

  *(int *)0x0607EBD0 = 0;

  *(int *)0x0607EBF4 = 0;

  *0x06078654 = 5;

  *(int *)0x0605A1C4 = 0;

  *(int *)0x06082A30 = 0;

  *(int *)0x0607EABC = 0;

  *(int *)0x0607EAC0 = 0;

  *0x06083260 = 0;

  *0x06082A26 = 0;

  *(int *)0x060788FC = 0;

  *(int *)0x06082A38 = 0;

  *0x06083261 = 0;

  *(int *)0x0608325C = 0;

  *(int *)0x06083258 = 0;

  *(int *)0x0605A21C = 0;

  *(short *)0x06086058 = 0;

  *0x0608605A = 0;

  *0x0605DE3C = 0;

  *(int *)0x060786A8 = 0;

  *(int *)0x060786BC = 0;

  *0x06085FCC = 0;

  *0x06087060 = 0;

  puVar1 = 0x0602FD98;

  *(short *)0x0602FD98 = 0;

  *(short *)(puVar1 + 2) = 0;

  *(short *)(puVar1 + 4) = 0;

  *(short *)(puVar1 + 6) = 0;

  puVar2 = 0x06021450;

  *(short *)(puVar1 + 8) = 0;

  (*puVar2)();

  (*0x06018634)();

  return;

}
