void FUN_060122f4()
{

  char *puVar1;



  puVar1 = 0x060788B4;

  *(int *)(0x060788B4 + 4) = *(int *)(0x060788B4 + 4) - 0x2999;

  *(int *)(puVar1 + 8) = *(int *)(puVar1 + 8) - 0x4000;

  if (*(int *)(puVar1 + 4) < (int)0x00020000) {

    *(char **)(puVar1 + 4) = 0x00020000;

  }

  if (*(int *)(puVar1 + 8) < (int)0x0004CCCC) {

    *(char **)(puVar1 + 8) = 0x0004CCCC;

  }

  *(short *)0x060788B2 = *(short *)0x060788B2 + 0x1800;

  return;

}
