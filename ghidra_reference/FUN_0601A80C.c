extern int DAT_0601a872;

extern int DAT_0601a926;

extern int DAT_0601a928;

extern int DAT_0601a92a;

void FUN_0601a80c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int in_r7;

  puVar3 = 0x0605D243;

  puVar2 = 0x0605D248;

  puVar1 = 0x06063D98;

  if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) == 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601a872) == 0) {

      if (((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) == 0) {

        if (((*(unsigned short *)0x06063D98 & DAT_0601a872) != 0) && (*(int *)0x0605D243 == '\x14')) {

          *(int *)0x0605D248 = *(int *)0x0605D248 + -1;

          *puVar3 = 0;

        }

      }

      else if (*(int *)0x0605D243 == '\x14') {

        *(int *)0x0605D248 = *(int *)0x0605D248 + 1;

        *puVar3 = 0;

      }

    }

    else {

      *(int *)0x0605D248 = *(int *)0x0605D248 + -1;

      *puVar3 = 0;

    }

  }

  else {

    *(int *)0x0605D248 = *(int *)0x0605D248 + 1;

    *puVar3 = 0;

  }

  if ((*(unsigned short *)(puVar1 + 2) & 0xf8) != 0) {

    *(int *)puVar2 = 0;

  }

  if (0x14 < *(int *)puVar2) {

    *(int *)puVar2 = 0;

  }

  if (*(int *)puVar2 < 0) {

    *(int *)puVar2 = 0x14;

  }

  if ((*(unsigned short *)(puVar1 + 2) & DAT_0601a926) != 0) {

    iVar4 = *(int *)puVar2 + 2;

    (*(int(*)())0x06018DDC)(iVar4,iVar4,0,in_r7,iVar4);

  }

  puVar1 = 0x060283E0;

  (*(int(*)())0x060283E0)(0xc,(int)DAT_0601a928,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a92a,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a928,0x0000E000,

                    *(int *)(0x0605D2B4 + *(int *)((int)(int)puVar2 << 3)));

  (*(int(*)())puVar1)(0xc,(int)DAT_0601a92a,0x0000E000,

                    *(int *)(0x0605D2B4 + (*(int *)((int)(int)puVar2 << 1) + 1) << 2));

  return;

}
