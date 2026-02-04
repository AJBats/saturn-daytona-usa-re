extern int DAT_0601112c;

extern int DAT_0601112e;

extern int DAT_06011206;

extern int DAT_06011208;

extern int DAT_0601120a;

extern int PTR_DAT_06011130;

extern int PTR_DAT_06011130;

extern int PTR_DAT_0601120c;

extern int PTR_DAT_0601120c;

void FUN_06011094()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int local_30;

  int iStack_2c;

  int iStack_28;

  puVar3 = 0x0605AC70;

  puVar2 = 0x06028400;

  puVar1 = 0x0607EADC;

  if (*0x0607887F == '\x03') {

    if ((*(unsigned int *)0x0607EBC8 & 1) == 0) {

      iStack_28 = 4;

    }

    else {

      iStack_28 = 3;

    }

  }

  else if ((*(unsigned int *)0x0607EBC8 & 3) < 2) {

    iStack_28 = 3;

  }

  else {

    iStack_28 = 4;

  }

  iVar8 = *(int *)(0x06063750 + DAT_0601112c);

  iVar7 = *(int *)(0x06063750 + DAT_0601112c + 0x10);

  local_30 = iStack_28;

  if (*(int *)0x0607EADC != 0) {

    local_30 = 3;

  }

  (*0x06028400)

            (4,*(int *)(0x0605AC70 + *(int *)0x06078644 * 4),(int)DAT_0601112e,

             local_30 * 0x1000 + iVar8);

  puVar5 = 0x0605AB98;

  puVar4 = 0x0605AD00;

  (*puVar2)(8,*(int *)(0x0605AB98 + *(int *)0x0605AD00 * 4),

                    (int)PTR_DAT_06011130,local_30 * 0x1000 + iVar7);

  iStack_2c = iStack_28;

  if (*(int *)puVar1 != 1) {

    iStack_2c = 3;

  }

  iVar6 = (iStack_2c + 2) * 0x1000;

  (*puVar2)(4,*(int *)(puVar3 + *(int *)0x06078644 * 4 + 0xc),(int)DAT_06011206

                    ,iVar6 + iVar8);

  (*puVar2)(8,*(int *)(puVar5 + *(int *)puVar4 * 4 + 0xc),(int)DAT_06011208,

                    iVar6 + iVar7);

  if (*(int *)puVar1 != 2) {

    iStack_28 = 3;

  }

  iVar6 = (iStack_28 + 4) * 0x1000;

  (*puVar2)(4,*(int *)(puVar3 + *(int *)0x06078644 * 4 + 0x18),

                    (int)DAT_0601120a,iVar6 + iVar8);

  (*puVar2)(8,*(int *)(puVar5 + *(int *)puVar4 * 4 + 0x18),

                    (int)PTR_DAT_0601120c,iVar6 + iVar7);

  return;

}
