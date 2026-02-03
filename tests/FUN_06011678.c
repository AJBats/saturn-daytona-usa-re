extern void FUN_0601164a();


void FUN_06011678()
{

  char *puVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  int iVar4;



  puVar1 = 0x25E5F800;

  iVar4 = 0x0100;

  FUN_0601164a();

  uVar3 = 0;

  do {

    uVar2 = uVar3 & 0xffff;

    uVar3 = uVar3 + 1;

    *(int *)(puVar1 + (uVar2 << 2)) = 0;

  } while ((int)(uVar3 & 0xffff) < iVar4);

  return;

}
