extern int DAT_0601a6de;

extern int DAT_0601a6e0;

extern int DAT_0601a6e2;

extern int DAT_0601a756;

extern int DAT_0601a758;

extern int DAT_0601a75a;

extern int PTR_DAT_0601a75c;

extern int PTR_DAT_0601a75c;

void FUN_0601a65e()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int *local_18;

  if (*(int *)0x06085FF0 == '\x03') {

    iVar3 = 3;

    if ((unsigned char)*(int *)0x0605D242 < 8) {

      iVar4 = 6;

    }

    else {

      iVar4 = 7;

      if (0x10 < (unsigned char)*(int *)0x0605D242) {

        *(int *)0x0605D242 = 0;

      }

    }

  }

  else {

    iVar4 = 6;

    iVar3 = 5;

  }

  puVar2 = 0x06028400;

  puVar1 = 0x06063750;

  if (*(int *)0x0605D241 == '\0') {

    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_0601a6de),(int)DAT_0601a6e0,

               (iVar4 << 12) + *(int *)((int)(0x06063750 + DAT_0601a6de) + 4));

    local_18 = (int *)(puVar1 + DAT_0601a6e2);

    iVar3 = (iVar3 << 12) + local_18[1];

  }

  else {

    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_0601a756),(int)DAT_0601a758,

               (iVar3 << 12) + *(int *)((int)(0x06063750 + DAT_0601a756) + 4));

    local_18 = (int *)(puVar1 + DAT_0601a75a);

    iVar3 = (iVar4 << 12) + local_18[1];

  }

  (*(int(*)())puVar2)(0xc,*local_18,(int)PTR_DAT_0601a75c,iVar3);

  return;

}
