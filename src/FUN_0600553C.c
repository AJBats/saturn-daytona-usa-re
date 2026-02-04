extern int PTR_DAT_060055a0;

extern int PTR_DAT_060055a0;

void FUN_0600553c(param_1, param_2)
    char *param_1;
    char *param_2;
{

  char cVar1;

  char *puVar2;

  int bVar3;

  int iVar4;

  cVar1 = *param_1;

  bVar3 = true;

  if ((param_2 != (char *)0x0) && (cVar1 == *param_2)) {

    bVar3 = false;

  }

  if ((bVar3) && ((*0x06026E0C)(), puVar2 = 0x06078900, cVar1 != -1)) {

    iVar4 = (int)cVar1 * (int)PTR_DAT_060055a0;

    (*0x06026E2E)

              (*(int *)(0x06078900 + iVar4 + 0x10),

               *(int *)(0x06078900 + iVar4 + 0x14),

               *(int *)(0x06078900 + iVar4 + 0x18));

    (*0x06026EDE)(*(int *)(puVar2 + iVar4 + 0x20));

    (*0x06026E94)(*(int *)(puVar2 + iVar4 + 0x1c));

    (*0x06026F2A)(*(int *)(puVar2 + iVar4 + 0x24));

    return;

  }

  return;

}
