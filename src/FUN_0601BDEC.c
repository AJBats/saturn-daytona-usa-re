extern int PTR_DAT_0601be4c;

extern int PTR_DAT_0601be4c;

void FUN_0601bdec()
{

  int iVar1;

  unsigned int *puVar2;

  int iVar3;

  unsigned int *puVar4;

  int *piVar5;

  iVar3 = *(int *)0x0607E944;

  puVar2 = (unsigned int *)0x06059F38;

  puVar4 = (unsigned int *)0x06059F3C;

  piVar5 = (int *)0x06086018;

  iVar1 = (*(void(*)())0x06034FE0)();

  *puVar4 = *puVar4 + iVar1 + 1;

  if (*piVar5 - *(int *)(iVar3 + 0x20) < 1) {

    if (*piVar5 - *(int *)(iVar3 + 0x20) < 0) {

      *puVar2 = *puVar2 - 2;

    }

  }

  else {

    *puVar2 = *puVar2 + 2;

  }

  if (0x50 < *puVar4) {

    *puVar4 = *puVar4 - 0x50;

  }

  if ((unsigned int)(int)PTR_DAT_0601be4c < *puVar2) {

    *puVar2 = 0;

  }

  *piVar5 = *(int *)(iVar3 + 0x20);

  return;

}
