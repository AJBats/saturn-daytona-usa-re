extern int DAT_0601bb3a;

extern int DAT_0601bb3c;

extern int DAT_0601bb3e;

extern int DAT_0601bb40;

extern int DAT_0601bb42;

extern int DAT_0601bb44;

extern int DAT_0601bb46;

extern int DAT_0601bb48;

extern int DAT_0601bb4a;

extern int DAT_0601bbc0;

extern int DAT_0601bbc2;

extern void FUN_0601bbcc();

void FUN_0601ba50(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  char *pcVar6;

  char auStack_1c [8];

  puVar2 = 0x0605D4F7;

  puVar1 = 0x060284AE;

  (*0x06035228)();

  puVar4 = 0x06063750;

  puVar3 = 0x06028400;

  (*0x06028400)

            (0xc,*(int *)(0x06063750 + DAT_0601bb3a),(int)DAT_0601bb3c,

             0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601bb3a) + 4));

  (*puVar3)(0xc,*(int *)(puVar4 + DAT_0601bb3e),(int)DAT_0601bb40,

                    0x0000A000 + *(int *)((int)(puVar4 + DAT_0601bb3e) + 4));

  (*puVar3)(0xc,*(int *)(puVar4 + (param_1 + 0x30) * 8),(int)DAT_0601bb42,

                    0x00009000 + *(int *)((int)(puVar4 + (param_1 + 0x30) * 8) + 4));

  (*puVar3)(0xc,*(int *)(puVar4 + (param_2 + 0x33) * 8),(int)DAT_0601bb44,

                    0x00009000 + *(int *)((int)(puVar4 + (param_2 + 0x33) * 8) + 4));

  FUN_0601bbcc(*(int *)

                (0x0605DD6C + (param_1 * 6 + param_2 * 2 + (unsigned int)(unsigned char)*puVar2) * 4),

               (int)param_3,10);

  (*puVar3)(0xc,*(int *)(puVar4 + DAT_0601bb46),(int)DAT_0601bb4a,

                    *(int *)((int)(puVar4 + DAT_0601bb46) + 4) + (int)DAT_0601bb48);

  pcVar6 = *(char **)(0x0605DE24 + (param_1 * 2 + (unsigned int)(unsigned char)*puVar2) * 4);

  (*puVar1)(8,(int)DAT_0601bbc0,0x60,auStack_1c);

  if (*pcVar6 != '\0') {

    (*puVar1)(8,(int)DAT_0601bbc0,0x60,pcVar6);

  }

  uVar5 = (*0x06005DD4)

                    (*(int *)

                      (*(int *)(0x0605DE24 + (param_1 * 2 + (unsigned int)(unsigned char)*puVar2) * 4) + 4));

  (*puVar1)(8,(int)DAT_0601bbc2,0x78,uVar5);

  return;

}
