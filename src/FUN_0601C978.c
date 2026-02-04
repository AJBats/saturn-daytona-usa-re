extern int DAT_0601ca3a;

extern int DAT_0601ca3c;

extern int DAT_0601ca3e;

extern int PTR_DAT_0601ca40;

extern int PTR_DAT_0601ca40;

void FUN_0601c978()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  short *puVar4;

  short *puVar5;

  puVar1 = 0x06086028;

  *(int *)0x0608602C = 0;

  *0x06086030 = 0;

  puVar2 = 0x060149E0;

  *(short *)puVar1 = DAT_0601ca3a;

  (*puVar2)();

  (*0x060148FC)();

  (*0x06026CE0)();

  *(int *)0x06059F44 = 0;

  (*0x0600A026)();

  *(int *)0x0608601C = (int)DAT_0601ca3c;

  *(int *)0x06086020 = 0;

  *(int *)0x06086024 = 0;

  iVar3 = 0x20;

  puVar5 = (short *)0x25F00200;

  do {

    iVar3 = iVar3 + -2;

    *puVar5 = *(short *)puVar1;

    puVar4 = puVar5 + 1;

    puVar5 = puVar5 + 2;

    *puVar4 = *(short *)puVar1;

  } while (iVar3 != 0);

  iVar3 = 0x20;

  puVar5 = (short *)0x25F00400;

  do {

    iVar3 = iVar3 + -2;

    *puVar5 = *(short *)puVar1;

    puVar4 = puVar5 + 1;

    puVar5 = puVar5 + 2;

    *puVar4 = *(short *)puVar1;

  } while (iVar3 != 0);

  (*0x0602766C)(0x25F00000,0x0604880C,0x40);

  (*0x0600511E)(0x25E70E40,0x00014000,0,9);

  (*0x0600511E)(0x25E7B168,0x00016BC0,0,9);

  (*0x06028400)

            (4,*(int *)0x06063958,(int)DAT_0601ca3e,

             *(int *)(0x06063958 + 4),0x06063958);

  (*0x06028400)

            (0,*(int *)0x06063960,(int)DAT_0601ca3e,

             *(int *)(0x06063960 + 4),0x06063960);

  puVar1 = 0x06038BD4;

  (*0x06038BD4)((int)PTR_DAT_0601ca40,0);

  (*puVar1)(4,1);

  (*puVar1)(8,2);

  (*puVar1)(0x10,0);

  (*puVar1)(0x20,0);

  (*0x06036E90)(0x25F00FFE,1,0x06086028);

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x40000000;

  (*0x06026CE0)();

  *(int *)0x06059F44 = 0;

  return;

}
