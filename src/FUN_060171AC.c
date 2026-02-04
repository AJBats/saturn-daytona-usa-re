extern int DAT_0601729e;

extern int PTR_DAT_060172a0;

extern int PTR_DAT_060172a0;

void FUN_060171ac()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  puVar4 = 0x060785FC;

  puVar3 = 0x0605A008;

  puVar2 = 0x060280F8;

  puVar1 = 0x06085490;

  if ((*(int *)0x0605AD10 == 0x19 || *(int *)0x0605AD10 == 0x15) &&

     (0x06084FC8[1] == '\0' && *0x06084FC8 != '\0')) {

    if (*(int *)0x0605AD10 == 0x19) {

      (*0x060280F8)(0x06085490 + DAT_0601729e,*(int *)0x060785FC);

      *(int *)puVar3 = *(int *)puVar3 + 1;

      iVar5 = *(int *)puVar4;

      *(int *)puVar4 = iVar5 + 0x20;

      (*puVar2)(puVar1 + PTR_DAT_060172a0,iVar5 + 0x20);

      *(int *)puVar3 = *(int *)puVar3 + 1;

      iVar5 = *(int *)puVar4;

      *(int *)puVar4 = iVar5 + 0x20;

      (*puVar2)(puVar1 + 0x78,iVar5 + 0x20);

      *(int *)puVar3 = *(int *)puVar3 + 1;

      iVar5 = *(int *)puVar4;

      *(int *)puVar4 = iVar5 + 0x20;

      (*puVar2)(puVar1 + 0x60,iVar5 + 0x20);

      *(int *)puVar3 = *(int *)puVar3 + 1;

      *(int *)puVar4 = *(int *)puVar4 + 0x20;

    }

    (*puVar2)(puVar1 + 0x48,*(int *)puVar4);

    *(int *)puVar3 = *(int *)puVar3 + 1;

    iVar5 = *(int *)puVar4;

    *(int *)puVar4 = iVar5 + 0x20;

    (*puVar2)(puVar1 + 0x30,iVar5 + 0x20);

    *(int *)puVar3 = *(int *)puVar3 + 1;

    iVar5 = *(int *)puVar4;

    *(int *)puVar4 = iVar5 + 0x20;

    (*puVar2)(puVar1 + 0x18,iVar5 + 0x20);

    *(int *)puVar3 = *(int *)puVar3 + 1;

    iVar5 = *(int *)puVar4;

    *(int *)puVar4 = iVar5 + 0x20;

    (*puVar2)(puVar1,iVar5 + 0x20);

    *(int *)puVar3 = *(int *)puVar3 + 1;

    *(int *)puVar4 = *(int *)puVar4 + 0x20;

  }

  return;

}
