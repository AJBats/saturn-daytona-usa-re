extern int DAT_060113b2;

extern int DAT_060113b4;

extern int DAT_060113b6;

extern int DAT_06011462;

extern int DAT_06011464;

extern int DAT_06011466;

void FUN_06011310()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int local_20;

  puVar2 = 0x06063828;

  puVar1 = 0x06028400;

  if (*0x0607887F == '\v') {

    if ((*(unsigned int *)0x0607EBC8 & 1) == 0) {

      iVar5 = 4;

    }

    else {

      iVar5 = 3;

    }

  }

  else if ((*(unsigned int *)0x0607EBC8 & 3) < 2) {

    iVar5 = 3;

  }

  else {

    iVar5 = 4;

  }

  local_20 = iVar5;

  if (*(int *)0x0607EADC != 0) {

    local_20 = 3;

  }

  local_20 = local_20 * 0x1000;

  (*0x06028400)

            (4,0x0605A7FC,(int)DAT_060113b2,*(int *)(0x06063828 + 4) + local_20);

  puVar3 = 0x06078644;

  puVar4 = 0x0605A9B8;

  if (*(int *)0x06078644 != 0) {

    puVar4 = 0x0605A9B0;

  }

  (*puVar1)(4,puVar4,(int)DAT_060113b4,*(int *)(puVar2 + 4) + local_20);

  puVar4 = 0x0605A978;

  if (*(int *)puVar3 != 0) {

    puVar4 = 0x0605A998;

  }

  (*puVar1)(4,puVar4,(int)DAT_060113b6,*(int *)(puVar2 + 4) + local_20);

  local_20 = iVar5;

  if (*(int *)0x0607EADC != 1) {

    local_20 = 3;

  }

  iVar5 = (local_20 + 2) * 0x1000;

  (*puVar1)(4,0x0605A8B6,(int)DAT_06011462,*(int *)(puVar2 + 4) + iVar5);

  puVar4 = 0x0605A9B8;

  if (*(int *)puVar3 != 0) {

    puVar4 = 0x0605A9B0;

  }

  (*puVar1)(4,puVar4,(int)DAT_06011464,*(int *)(puVar2 + 4) + iVar5);

  puVar4 = 0x0605A980;

  if (*(int *)puVar3 != 0) {

    puVar4 = 0x0605A9A0;

  }

  (*puVar1)(4,puVar4,(int)DAT_06011466,*(int *)(puVar2 + 4) + iVar5);

  return;

}
